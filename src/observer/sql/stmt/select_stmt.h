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
// Created by Wangyunlai on 2022/6/5.
//

#pragma once

#include <map>
#include <memory>
#include <vector>

#include "common/rc.h"
#include "sql/stmt/stmt.h"
#include "storage/field/field.h"

class FieldMeta;
class FilterStmt;
class Db;
class Table;

/**
 * @brief 表示select语句
 * @ingroup Statement
 */
class SelectStmt : public Stmt {
 public:
  SelectStmt() = default;
  ~SelectStmt() override;

  StmtType type() const override { return StmtType::SELECT; }

 public:
  static RC create(Db *db, const SelectSqlNode &select_sql, Stmt *&stmt);

 public:
  const std::vector<Table *> &tables() const { return tables_; }
  const std::vector<Field> &query_fields() const { return query_fields_; }
  const std::vector<Field> &aggr_query_fields() const {
    return aggr_query_fields_;
  }
  const std::vector<Field> &order_by_fields() const { return order_by_fields_; }
  const std::vector<Field> &group_by_fields() const { return group_by_fields_; }
  const std::vector<OrderByDirection> &order_by_directions() const {
    return order_by_directions_;
  }
  FilterStmt *filter_stmt() const { return filter_stmt_; }
  // const std::unordered_map<Field *, AggrFuncType> &aggrfunc_queries() {
  //   return aggrfunc_queries_;
  // }

  void add_aggr_to_proj_map(int aggr_index, int proj_index) {
    aggr_field_to_query_field_map_[aggr_index] = proj_index;
  }
  const std::map<int, int> &aggr_field_to_query_field_map() const {
    return aggr_field_to_query_field_map_;
  }

 private:
  std::vector<Field> aggr_query_fields_;  // 当存在聚合函数时候会调用该vector
  std::map<int, int>
      aggr_field_to_query_field_map_;  // 用于记录聚合列指向投影之后的哪一列
  std::vector<Field> query_fields_;
  std::vector<Table *> tables_;
  FilterStmt *filter_stmt_ = nullptr;
  // std::unordered_map<Field *, AggrFuncType> aggrfunc_queries_;
  std::vector<Field> order_by_fields_;
  std::vector<OrderByDirection> order_by_directions_;

  std::vector<Field> group_by_fields_;  // 用于group by
};
