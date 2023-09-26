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

#pragma once

#include <string>
#include <map>

#include "common/rc.h"
#include "sql/stmt/stmt.h"

class Table;
class FilterStmt;
class SelectStmt;

/**
 * @brief 更新语句
 * @ingroup Statement
 */
class UpdateStmt : public Stmt {
 public:
  UpdateStmt() = default;
  UpdateStmt(Table *table, std::vector<std::string> attribute_names,
             const std::vector<Value> values, int value_amount,
             FilterStmt *filter_stmt,std::map<std::string,SelectStmt*>col_name_to_selects);
  ~UpdateStmt() override;

 public:
  static RC create(Db *db, const UpdateSqlNode &update_sql, Stmt *&stmt);

 public:
  Table *table() const { return table_; }
  // const Value *values() const { return values_; }
  std::vector<Value> values() { return values_; }
  FilterStmt *filter_stmt() const { return filter_stmt_; }
  int value_amount() const { return value_amount_; }
  std::string attribute_name() const { return attribute_name_; }
  std::vector<std::string> attribute_names() { return attribute_names_; }
  std::map<std::string,SelectStmt*>col_name_to_selects(){return col_name_to_selects_;}

  StmtType type() const override { return StmtType::UPDATE; }

 private:
  Table *table_ = nullptr;

  // const Value *values_ = nullptr;
  std::vector<Value> values_;
  int value_amount_ = 0;
  FilterStmt *filter_stmt_ = nullptr;
  std::string attribute_name_;
  std::vector<std::string> attribute_names_;
  std::map<std::string,SelectStmt*>col_name_to_selects_;
};
