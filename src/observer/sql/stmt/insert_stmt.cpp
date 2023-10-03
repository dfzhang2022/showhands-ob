/* Copyright (c) 2021OceanBase and/or its affiliates. All rights reserved.
miniob is licensed under Mulan PSL v2.
You can use this software according to the terms and conditions of the Mulan PSL
v2. You may obtain a copy of Mulan PSL v2 at:
         http://license.coscl.org.cn/MulanPSL2
THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
See the Mulan PSL v2 for more details. */

//
// Created by Wangyunlai on 2022/5/22.
//

#include "sql/stmt/insert_stmt.h"

#include "common/log/log.h"
#include "storage/db/db.h"
#include "storage/table/table.h"

InsertStmt::InsertStmt(Table *table, const Value *values, int value_amount)
    : table_(table), values_(values), value_amount_(value_amount) {}
InsertStmt::InsertStmt(Table *table,
                       std::vector<std::vector<Value>> insert_values,
                       int value_amount, int record_amount)
    : table_(table),
      insert_values_(insert_values),
      value_amount_(value_amount),
      record_amount_(record_amount) {}

RC InsertStmt::create(Db *db, const InsertSqlNode &inserts, Stmt *&stmt) {
  const char *table_name = inserts.relation_name.c_str();
  if (nullptr == db || nullptr == table_name || inserts.insert_values.empty()) {
    LOG_WARN("invalid argument. db=%p, table_name=%p, value_num=%d", db,
             table_name, static_cast<int>(inserts.insert_values.size()));
    return RC::INVALID_ARGUMENT;
  }

  // check whether the table exists
  Table *table = db->find_table(table_name);
  if (nullptr == table) {
    LOG_WARN("no such table. db=%s, table_name=%s", db->name(), table_name);
    return RC::SCHEMA_TABLE_NOT_EXIST;
  }

  std::vector<std::vector<Value>> insert_values_vec;
  int record_amount = inserts.insert_values.size();

  // check the fields number
  const TableMeta &table_meta = table->table_meta();
  const int field_num = table_meta.field_num() - table_meta.sys_field_num();
  for (int cnt = 0; cnt < record_amount; cnt++) {
    const int value_num =
        static_cast<int>(inserts.insert_values.at(cnt).values.size());
    if (field_num != value_num) {
      LOG_WARN("schema mismatch. value num=%d, field num in schema=%d",
               value_num, field_num);
      return RC::SCHEMA_FIELD_MISSING;
    }
  }
  // check fields type
  const int sys_field_num = table_meta.sys_field_num();
  const int value_num =
      static_cast<int>(inserts.insert_values.at(0).values.size());
  for (int cnt = 0; cnt < record_amount; cnt++) {
    for (int i = 0; i < value_num; i++) {
      const FieldMeta *field_meta = table_meta.field(i + sys_field_num);
      const AttrType field_type = field_meta->type();
      const AttrType value_type =
          inserts.insert_values.at(cnt).values.at(i).attr_type();
      const bool is_nullable = field_meta->nullable();
      if (value_type == NULL_ATTR) {
        if (!is_nullable) {
          LOG_WARN("Insert null into not null column.");
          return RC::SCHEMA_FIELD_TYPE_MISMATCH;
        }
      } else if (field_type != value_type) {  // TODO try to convert the value
                                              // type to field type
        Value value = inserts.insert_values.at(cnt).values.at(i);
        if (value.typecast_to(field_type) != RC::SUCCESS) {
          LOG_WARN(
              "field type mismatch. table=%s, field=%s, field type=%d, "
              "value_type=%d",
              table_name, field_meta->name(), field_type, value_type);
          return RC::SCHEMA_FIELD_TYPE_MISMATCH;
        }
      }
      if (value_type == AttrType::DATES) {
        if (inserts.insert_values.at(cnt).values.at(i).get_date() == -1) {
          LOG_WARN(
              "Date Invalid. table=%s, field=%s, field type=%d, "
              "value_type=%d",
              table_name, field_meta->name(), field_type, value_type);
          return RC::INVALID_ARGUMENT;
        }
      }
    }
  }
  for (int cnt = 0; cnt < record_amount; cnt++) {
    insert_values_vec.push_back(inserts.insert_values.at(cnt).values);
  }
  for (int cnt = 0; cnt < record_amount; cnt++) {
    for (int i = 0; i < value_num; i++) {
      const FieldMeta *field_meta = table_meta.field(i + sys_field_num);
      const AttrType field_type = field_meta->type();
      const AttrType value_type = insert_values_vec.at(cnt).at(i).attr_type();
      const bool is_nullable = field_meta->nullable();
      if (value_type == NULL_ATTR) {
        // 如何把null值体现在记录里
        switch (field_type) {
          case AttrType::DATES: {
            insert_values_vec.at(cnt).at(i).set_date(
                10002000);  // "10002000" represents null date.
          } break;
          case AttrType::INTS: {
            insert_values_vec.at(cnt).at(i).set_int(
                104274);  // "104274" represents null int.
          } break;
          case AttrType::CHARS: {
            insert_values_vec.at(cnt).at(i).set_string(
                "ZDF", 3);  // "ZDF" represents null chars.
          } break;
          case AttrType::FLOATS: {
            insert_values_vec.at(cnt).at(i).set_float(
                114.514);  // "114.514" represents null float.
          } break;
          
          default:{
            LOG_WARN("Unimplement type null value.");
          }
            break;
        }
      } else if (field_type != value_type) {  // TODO try to convert the value
                                              // type to field type
        if (insert_values_vec.at(cnt).at(i).typecast_to(field_type) !=
            RC::SUCCESS) {
          LOG_WARN(
              "field type mismatch. table=%s, field=%s, field type=%d, "
              "value_type=%d",
              table_name, field_meta->name(), field_type, value_type);
          return RC::SCHEMA_FIELD_TYPE_MISMATCH;
        }
      }
    }
  }

  // check the fields number
  // const Value *values = inserts.values.data();
  // const int value_num = static_cast<int>(inserts.values.size());
  // const TableMeta &table_meta = table->table_meta();
  // const int field_num = table_meta.field_num() - table_meta.sys_field_num();
  // if (field_num != value_num) {
  //   LOG_WARN("schema mismatch. value num=%d, field num in schema=%d",
  //   value_num,
  //            field_num);
  //   return RC::SCHEMA_FIELD_MISSING;
  // }

  // check fields type
  // const int sys_field_num = table_meta.sys_field_num();
  // for (int i = 0; i < value_num; i++) {
  //   const FieldMeta *field_meta = table_meta.field(i + sys_field_num);
  //   const AttrType field_type = field_meta->type();
  //   const AttrType value_type = values[i].attr_type();
  //   if (field_type !=
  //       value_type) {  // TODO try to convert the value type to field type
  //     LOG_WARN(
  //         "field type mismatch. table=%s, field=%s, field type=%d, "
  //         "value_type=%d",
  //         table_name, field_meta->name(), field_type, value_type);
  //     return RC::SCHEMA_FIELD_TYPE_MISMATCH;
  //   }
  //   if (value_type == AttrType::DATES) {
  //     if (values[i].get_date() == -1) {
  //       LOG_WARN(
  //           "Date Invalid. table=%s, field=%s, field type=%d, "
  //           "value_type=%d",
  //           table_name, field_meta->name(), field_type, value_type);
  //       return RC::INVALID_ARGUMENT;
  //     }
  //   }
  // }

  // everything alright
  stmt = new InsertStmt(table, insert_values_vec, value_num, record_amount);
  return RC::SUCCESS;
}
