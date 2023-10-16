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

struct FilterObj {
  ExpressType type_;
  ExprObj expr_obj_;

  void init_value(const Value &value) {
    type_ = ExpressType::VALUE_T;
    expr_obj_.init_value(value);
  }

  void init_attr(const Field &field) {
    type_ = ExpressType::ATTR_T;
    expr_obj_.init_attr(field);
  }

  void init_select(const Stmt *stmt) {
    type_ = ExpressType::SELECT_T;
    expr_obj_.init_select(stmt);
  }

  void init_expr(const ExprObj &expr_obj) {
    type_ = ExpressType::EXPR_T;
    expr_obj_ = expr_obj;
  }
  void init_null() { type_ = ExpressType::INVALID_T; }

  RC init_expr(Db *db, Table *default_table,
               std::unordered_map<std::string, Table *> *tables,
               ExprSqlNode *expr_sql_node) {
    type_ = ExpressType::EXPR_T;
    return expr_obj_.init(db, default_table, tables, expr_sql_node);
  }
  RC init_list(Db *db, Table *default_table,
               std::unordered_map<std::string, Table *> *tables,
               ExprSqlNode *expr_sql_node) {
    type_ = ExpressType::EXPR_LIST_T;
    return expr_obj_.init_list(db, default_table, tables, expr_sql_node);
  }

  std::unique_ptr<Expression> to_expression(
      std::map<std::string, LogicalOperator *> *map = nullptr) {
    if (this->type_ != ExpressType::INVALID_T) {
      return expr_obj_.to_expression(map);
    } else {
      return std::unique_ptr<Expression>(nullptr);
    }
  }
};

class FilterUnit {
 public:
  FilterUnit() = default;
  ~FilterUnit() {}

  void set_comp(ExprOp comp) { comp_ = comp; }

  ExprOp comp() const { return comp_; }

  void set_left_unit(const FilterUnit *left_unit) { left_unit_ = (FilterUnit *)left_unit; }
  void set_right_unit(const FilterUnit *right_unit) { right_unit_ = (FilterUnit *)right_unit; }

  FilterUnit *left_unit() const { return left_unit_; }
  FilterUnit *right_unit() const { return right_unit_; }

  // void set_obj(const FilterObj &obj) { obj_ = obj; }

  // const FilterObj &obj() const { return obj_; }

  void set_left(const FilterObj &left) { left_= left; }
  void set_right(const FilterObj &right) { right_ = right; }

  const FilterObj &left() const { return left_; }
  const FilterObj &right() const { return right_; }

  std::unique_ptr<Expression> to_expression(
      std::map<std::string, LogicalOperator *> *map = nullptr) {
    if (comp_ == ExprOp::CONJUNC_AND) {
      std::vector<std::unique_ptr<Expression>> cmp_exprs;
      std::unique_ptr<Expression> left = left_unit_->to_expression(map);
      std::unique_ptr<Expression> right = right_unit_->to_expression(map);
      cmp_exprs.emplace_back(std::move(left));
      cmp_exprs.emplace_back(std::move(right));
      std::unique_ptr<ConjunctionExpr> conjunction_expr(
        new ConjunctionExpr(ConjunctionExpr::Type::AND, cmp_exprs));
      return conjunction_expr;
    } else if (comp_ == ExprOp::CONJUNC_OR) {
      std::vector<std::unique_ptr<Expression>> cmp_exprs;
      std::unique_ptr<Expression> left = left_unit_->to_expression(map);
      std::unique_ptr<Expression> right = right_unit_->to_expression(map);
      cmp_exprs.emplace_back(std::move(left));
      cmp_exprs.emplace_back(std::move(right));
      std::unique_ptr<ConjunctionExpr> conjunction_expr(
        new ConjunctionExpr(ConjunctionExpr::Type::OR, cmp_exprs));
      return conjunction_expr;
    } else if (comp_ != ExprOp::NO_OP) {
      std::unique_ptr<Expression> left = left_.to_expression(map);
      std::unique_ptr<Expression> right = right_.to_expression(map);
      std::unique_ptr<ComparisonExpr> cmp_expr (
        new ComparisonExpr(comp_, std::move(left), std::move(right)));
      return cmp_expr;
    } else {
      return std::unique_ptr<Expression>(nullptr);
    }
  }

 private:
  ExprOp comp_ = NO_OP;
  FilterUnit *left_unit_;
  FilterUnit *right_unit_;
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
                   ConditionTreeSqlNode **condition_trees, int condition_num,
                   FilterStmt *&stmt);

  static RC create_filter_unit(Db *db, Table *default_table,
                               std::unordered_map<std::string, Table *> *tables,
                               ConditionTreeSqlNode *&condition_tree,
                               FilterUnit *&filter_unit);

  static RC create_filter_unit(Db *db, Table *default_table,
                               std::unordered_map<std::string, Table *> *tables,
                               const ConditionSqlNode &condition_tree,
                               FilterUnit *&filter_unit);

 private:
  std::vector<FilterUnit *> filter_units_;  // 默认当前都是AND关系
};
