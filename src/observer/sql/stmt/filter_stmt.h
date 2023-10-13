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

#include <unordered_map>
#include <vector>

#include "sql/expr/expression.h"
#include "sql/parser/parse_defs.h"
#include "sql/stmt/express_obj.h"
#include "sql/stmt/select_stmt.h"
#include "sql/stmt/stmt.h"

class Db;
class Table;
class FieldMeta;

struct FilterObj 
{
  ExpressType type_;
  ExprObj expr_obj_;

  void init_value(const Value &value)
  {
    type_ = ExpressType::VALUE_T;
    expr_obj_.init_value(value);
  }

  void init_attr(const Field &field)
  {
    type_ = ExpressType::ATTR_T;
    expr_obj_.init_attr(field);
  }

  void init_select(const Stmt* stmt)
  {
    type_ = ExpressType::SELECT_T;
    expr_obj_.init_select(stmt);
  }

  void init_expr(const ExprObj &expr_obj)
  {
    type_ = ExpressType::EXPR_T;
    expr_obj_ = expr_obj;
  }

  RC init_expr(Db *db, Table *default_table,
    std::unordered_map<std::string, Table *> *tables, ExprSqlNode* expr_sql_node)
  {
    type_ = ExpressType::EXPR_T;
    return expr_obj_.init(db, default_table, tables, expr_sql_node);
  }

  std::unique_ptr<Expression> to_expression(std::map<std::string, LogicalOperator *> *map = nullptr)
  {
    return expr_obj_.to_expression(map);
  }
};

class FilterUnit {
 public:
  FilterUnit() = default;
  ~FilterUnit() {}

  void set_comp(ExprOp comp)
  {
    comp_ = comp;
  }

  ExprOp comp() const
  {
    return comp_;
  }

  void set_left(const FilterObj &obj)
  {
    left_ = obj;
  }
  void set_right(const FilterObj &obj)
  {
    right_ = obj;
  }

  const FilterObj &left() const
  {
    return left_;
  }
  const FilterObj &right() const
  {
    return right_;
  }

private:
  ExprOp comp_ = NO_OP;
  FilterObj left_;
  FilterObj right_;
};

/**
 * @brief Filter/谓词/过滤语句
 * @ingroup Statement
 */
class FilterStmt {
 public:
  FilterStmt() = default;
  virtual ~FilterStmt();

 public:
  const std::vector<FilterUnit *> &filter_units() const {
    return filter_units_;
  }

 public:
  static RC create(Db *db, Table *default_table,
                   std::unordered_map<std::string, Table *> *tables,
                   const ConditionSqlNode *conditions, int condition_num,
                   FilterStmt *&stmt);

  static RC create_filter_unit(Db *db, Table *default_table,
                               std::unordered_map<std::string, Table *> *tables,
                               const ConditionSqlNode &condition,
                               FilterUnit *&filter_unit);

 private:
  std::vector<FilterUnit *> filter_units_;  // 默认当前都是AND关系
};
