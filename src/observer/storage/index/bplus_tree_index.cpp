/* Copyright (c) 2021 OceanBase and/or its affiliates. All rights reserved.
miniob is licensed under Mulan PSL v2.
You can use this software according to the terms and conditions of the Mulan PSL
v2. You may obtain a copy of Mulan PSL v2 at:
         http://license.coscl.org.cn/MulanPSL2
THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
See the Mulan PSL v2 for more details. */

//
// Created by wangyunlai.wyl on 2021/5/19.
//

#include "storage/index/bplus_tree_index.h"

#include "common/log/log.h"

BplusTreeIndex::~BplusTreeIndex() noexcept { close(); }

RC BplusTreeIndex::create(const char *file_name, const IndexMeta &index_meta,
                          const std::vector<const FieldMeta*> &fields_meta) {
  if (inited_) {
    LOG_WARN(
        "Failed to create index due to the index has been created before. "
        "file_name:%s, index:%s",
        file_name, index_meta.name());
    return RC::RECORD_OPENNED;
  }

  Index::init(index_meta, fields_meta);

  RC rc = index_handler_.create(file_name, fields_meta, index_meta.type());
  if (RC::SUCCESS != rc) {
    LOG_WARN(
        "Failed to create index_handler, file_name:%s, index:%s, "
        "rc:%s",
        file_name, index_meta.name(), strrc(rc));
    return rc;
  }

  inited_ = true;
  LOG_INFO("Successfully create index, file_name:%s, index:%s",
           file_name, index_meta.name());
  return RC::SUCCESS;
}

RC BplusTreeIndex::open(const char *file_name, const IndexMeta &index_meta,
                        const std::vector<const FieldMeta*> &fields_meta) {
  if (inited_) {
    LOG_WARN(
        "Failed to open index due to the index has been initedd before. "
        "file_name:%s, index:%s",
        file_name, index_meta.name());
    return RC::RECORD_OPENNED;
  }

  Index::init(index_meta, fields_meta);

  RC rc = index_handler_.open(file_name);
  if (RC::SUCCESS != rc) {
    LOG_WARN(
        "Failed to open index_handler, file_name:%s, index:%s, rc:%s",
        file_name, index_meta.name(), strrc(rc));
    return rc;
  }

  inited_ = true;
  LOG_INFO("Successfully open index, file_name:%s, index:%s",
           file_name, index_meta.name());
  return RC::SUCCESS;
}

RC BplusTreeIndex::close() {
  if (inited_) {
    LOG_INFO("Begin to close index, index:%s", index_meta_.name());
    index_handler_.close();
    inited_ = false;
  }
  LOG_INFO("Successfully close index.");
  return RC::SUCCESS;
}

char* BplusTreeIndex::construct_user_key(const char* record, int &key_len) {
  key_len = 0;
  for(FieldMeta field : fields_meta_) {
    key_len += field.len();
  }
  char* user_key = (char*) malloc(key_len);
  int cur_pos = 0;
  for(FieldMeta field : fields_meta_) {
    memcpy(user_key + cur_pos, record + field.offset(), field.len());
    cur_pos += field.len();
  }
  return user_key;
}

RC BplusTreeIndex::insert_entry(const char *record, const RID *rid) {
  RC rc = RC::SUCCESS;
  int key_len;
  char* user_key = construct_user_key(record, key_len);

  if (this->index_meta_.type() == IndexType::UNIQUE_INDEX) {
    std::list<RID> tmp_rids;
    rc = index_handler_.get_entry(user_key,
                                  key_len, tmp_rids);
    if (rc != RC::SUCCESS) return rc;  
    if (!tmp_rids.empty()) {
      bool has_null = false;
      common::Bitmap bitmap(user_key, fields_meta_[0].len());
      for (int i = 1 ; i <= fields_meta_.size() ; i++) {
        if (bitmap.get_bit(fields_meta_[i].index())) {
          has_null = true;
          break;
        }
      }
      
      if (has_null) {
        // 插入值为null
        return index_handler_.insert_entry(user_key, rid);
      } else {
        LOG_WARN("Try to insert exist key on an indexed column.");
        index_handler_.insert_entry(user_key, rid);
        return RC::RECORD_DUPLICATE_KEY;
      }
    }
  }

  rc = index_handler_.insert_entry(user_key, rid);
  free(user_key);
  return rc;
}

// 同上一样的问题
RC BplusTreeIndex::delete_entry(const char *record, const RID *rid) {
  int key_len;
  char* user_key = construct_user_key(record, key_len);
  
  RC rc = index_handler_.delete_entry(user_key, rid);
  free(user_key);
  return rc;
}

RC BplusTreeIndex::update_entry(const char *record, const RID *rid, const char *old_record) {

  RC rc = RC::SUCCESS;
  int new_key_len, old_key_len;
  char* new_user_key = construct_user_key(record, new_key_len);
  char* old_user_key = construct_user_key(old_record, old_key_len);

  assert(new_key_len == old_key_len);
  if (0 == std::memcmp(new_user_key, old_user_key, new_key_len)) { // 相等, 无需操作
    free(new_user_key);
    free(old_user_key);
    return rc;
  }

  if (this->index_meta_.type() == IndexType::UNIQUE_INDEX) {
    std::list<RID> tmp_rids;
    rc = index_handler_.get_entry(record,
                                  new_key_len, tmp_rids);
    if (rc != RC::SUCCESS) return rc;  
    if (!tmp_rids.empty()) {
      bool has_null = false;
      common::Bitmap bitmap(const_cast<char*>(record), fields_meta_[0].len());
      for (int i = 1 ; i <= fields_meta_.size() ; i++) {
        if (bitmap.get_bit(fields_meta_[i].index())) {
          has_null = true;
          break;
        }
      }
      
      if (has_null) {
        return index_handler_.update_entry(new_user_key, rid, old_user_key);
      } else {
        LOG_WARN("Try to insert exist key on an indexed column.");
        index_handler_.update_entry(new_user_key, rid, old_user_key);
        return RC::RECORD_DUPLICATE_KEY;
      }
    }
  }
  rc = index_handler_.update_entry(new_user_key, rid, old_user_key);
  free(new_user_key);
  free(old_user_key);
  return rc;
}

IndexScanner *BplusTreeIndex::create_scanner(const char *left_key, int left_len,
                                             bool left_inclusive,
                                             const char *right_key,
                                             int right_len,
                                             bool right_inclusive) {
  BplusTreeIndexScanner *index_scanner =
      new BplusTreeIndexScanner(index_handler_);
  RC rc = index_scanner->open(left_key, left_len, left_inclusive, right_key,
                              right_len, right_inclusive);
  if (rc != RC::SUCCESS) {
    LOG_WARN("failed to open index scanner. rc=%d:%s", rc, strrc(rc));
    delete index_scanner;
    return nullptr;
  }
  return index_scanner;
}

RC BplusTreeIndex::sync() { return index_handler_.sync(); }

////////////////////////////////////////////////////////////////////////////////
BplusTreeIndexScanner::BplusTreeIndexScanner(BplusTreeHandler &tree_handler)
    : tree_scanner_(tree_handler) {}

BplusTreeIndexScanner::~BplusTreeIndexScanner() noexcept {
  tree_scanner_.close();
}

RC BplusTreeIndexScanner::open(const char *left_key, int left_len,
                               bool left_inclusive, const char *right_key,
                               int right_len, bool right_inclusive) {
  return tree_scanner_.open(left_key, left_len, left_inclusive, right_key,
                            right_len, right_inclusive);
}

RC BplusTreeIndexScanner::next_entry(RID *rid) {
  return tree_scanner_.next_entry(*rid);
}

RC BplusTreeIndexScanner::destroy() {
  delete this;
  return RC::SUCCESS;
}
