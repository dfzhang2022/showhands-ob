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
// Created by Wangyunlai on 2022/5/22.
//
#include "sql/stmt/update_stmt.h"

#include "common/log/log.h"
#include "sql/stmt/filter_stmt.h"
#include "sql/stmt/select_stmt.h"
#include "storage/db/db.h"
#include "storage/table/table.h"

UpdateStmt::UpdateStmt(Table *table, std::vector<std::string> attribute_names,
                       std::vector<Value> values, int value_amount,
                       FilterStmt *filter_stmt,
                       std::map<std::string, SelectStmt *> col_name_to_selects)
    : table_(table),
      attribute_names_(attribute_names),
      values_(values),
      value_amount_(value_amount),
      filter_stmt_(filter_stmt),
      col_name_to_selects_(col_name_to_selects) {}
UpdateStmt::~UpdateStmt() {
  if (nullptr != filter_stmt_) {
    delete filter_stmt_;
    filter_stmt_ = nullptr;
  }
}
RC UpdateStmt::create(Db *db, const UpdateSqlNode &update_sql, Stmt *&stmt) {
  // TODO
  const char *table_name = update_sql.relation_name.c_str();
  if (nullptr == db || nullptr == table_name) {
    LOG_WARN("invalid argument. db=%p, table_name=%p", db, table_name);
    return RC::INVALID_ARGUMENT;
  }

  // check whether the table exists
  Table *table = db->find_table(table_name);
  if (nullptr == table) {
    LOG_WARN("no such table. db=%s, table_name=%s", db->name(), table_name);
    return RC::SCHEMA_TABLE_NOT_EXIST;
  }

  std::unordered_map<std::string, Table *> table_map;
  table_map.insert(
      std::pair<std::string, Table *>(std::string(table_name), table));

  FilterStmt *filter_stmt = nullptr;
  RC rc = FilterStmt::create(
      db, table, &table_map, update_sql.conditions.data(),
      static_cast<int>(update_sql.conditions.size()), filter_stmt);
  if (rc != RC::SUCCESS) {
    LOG_WARN("failed to create filter statement. rc=%d:%s", rc, strrc(rc));
    return rc;
  }
  std::vector<std::string> str_vec;
  std::vector<Value> val_vec;
  int value_amount = update_sql.update_values.size();
  std::map<std::string, SelectStmt *> col_name_to_selects;
  for (int i = 0; i < value_amount; i++) {
    std::string attr_name = update_sql.update_values.at(i).name;
    str_vec.emplace_back(attr_name);
    if (update_sql.update_values.at(i).is_right_selects) {
      // right value is select statement
      Stmt *stmt = nullptr;
      rc = SelectStmt::create(db, update_sql.update_values[i].select_sql_node,
                              stmt);
      if (rc != RC::SUCCESS && rc != RC::UNIMPLENMENT) {
        LOG_WARN("failed to create select_stmt in update_stmt. rc=%d:%s", rc,
                 strrc(rc));
        return rc;
      }
      SelectStmt *select_stmt_ptr = static_cast<SelectStmt *>(stmt);

      col_name_to_selects.insert(
          std::pair<std::string, SelectStmt *>(attr_name, select_stmt_ptr));
      val_vec.emplace_back(Value(0));
    } else
      val_vec.emplace_back(update_sql.update_values.at(i).value);
  }

  // LOG_INFO("value is %d", update_sql.value.get_int());
  // stmt = new UpdateStmt(table, update_sql.attribute_name, &update_sql.value,
  //                       int(1), filter_stmt);
  stmt = new UpdateStmt(table, str_vec, val_vec, value_amount, filter_stmt,
                        col_name_to_selects);
  return rc;
}
