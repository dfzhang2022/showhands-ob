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
#include "sql/stmt/select_stmt.h"
#include "sql/stmt/stmt.h"

class Db;
class Table;
class FieldMeta;

RC get_table_and_field(Db *db, Table *default_table,
                       std::unordered_map<std::string, Table *> *tables,
                       const RelAttrSqlNode &attr, Table *&table,
                       const FieldMeta *&field);

RC check_value_date(const Value &value);

RC get_field(Db *db, Table *default_table,
    std::unordered_map<std::string, Table *> *tables,
    const RelAttrSqlNode &attr, Field &tmp_field);

struct ExprObj {
  std::string name;
  ExpressType type;

  ExpressType left_type;
  Value left_value;
  Field left_field;
  Stmt *left_select;
  ExprObj *left_expr;
  ExprOp comp;
  ExpressType right_type;
  Value right_value;
  Field right_field;
  Stmt *right_select;
  ExprObj *right_expr;

  std::vector<ExprObj *> expr_obj_list;

  void init_value(const Value &value) {
    type = ExpressType::VALUE_T;
    left_value = value;
  }

  void init_attr(const Field &field) {
    type = ExpressType::ATTR_T;
    left_field = field;
  }

  void init_select(const Stmt *stmt) {
    type = ExpressType::SELECT_T;
    left_select = (Stmt *)stmt;
  }

  void init_left(ExprObj *left_obj) {
    left_type = left_obj->type;
    switch (left_type) {
      case ExpressType::VALUE_T:
        left_value = left_obj->left_value;
        break;
      case ExpressType::ATTR_T:
        left_field = left_obj->left_field;
        break;
      case ExpressType::SELECT_T:
        left_select = left_obj->left_select;
        break;
      case ExpressType::EXPR_T:
        left_expr = left_obj;
        break;

      default:
        break;
    }
  }

  void init_right(ExprObj *right_obj) {
    right_type = right_obj->type;
    switch (right_type) {
      case ExpressType::VALUE_T:
        right_value = right_obj->left_value;
        break;
      case ExpressType::ATTR_T:
        right_field = right_obj->left_field;
        break;
      case ExpressType::SELECT_T:
        right_select = right_obj->left_select;
        break;
      case ExpressType::EXPR_T:
        right_expr = right_obj;
        break;

      default:
        break;
    }
  }

  void init_expr(ExprObj *left_obj, ExprObj *right_obj, ExprOp exprop) {
    type = ExpressType::EXPR_T;
    init_left(left_obj);
    comp = exprop;
    init_right(right_obj);
  }

  RC init(Db *db, Table *default_table,
          std::unordered_map<std::string, Table *> *tables,
          ExprSqlNode *expr_sql_node) {
    RC rc = RC::SUCCESS;
    name = expr_sql_node->name;
    if (expr_sql_node->type == ExpressType::VALUE_T) {
      rc = check_value_date(expr_sql_node->left_value);
      if (rc != RC::SUCCESS) {
        return rc;
      }
      init_value(expr_sql_node->left_value);
    }
    else if (expr_sql_node->type == ExpressType::ATTR_T) {
      Field tmp_field;
      rc = get_field(db, default_table, tables, expr_sql_node->left_attr, tmp_field);
      if (rc != RC::SUCCESS) {
        return rc;
      }
      init_attr(tmp_field);
    }
    else if (expr_sql_node->type == ExpressType::EXPR_T) {
      ExprObj *left_obj = new ExprObj();
      ExprObj *right_obj = new ExprObj();
      left_type = expr_sql_node->left_type;
      if (left_type == VALUE_T) {
        rc = check_value_date(expr_sql_node->left_value);
        if (rc != RC::SUCCESS) {
          return rc;
        }
        left_obj->init_value(expr_sql_node->left_value);
      }
      else if (left_type == ATTR_T) {
        Field tmp_field;
        rc = get_field(db, default_table, tables, expr_sql_node->left_attr, tmp_field);
        if (rc != RC::SUCCESS) {
          return rc;
        }
        left_obj->init_attr(tmp_field);
      }
      else if (left_type == EXPR_T) {
        rc = left_obj->init(db, default_table, tables, expr_sql_node->left_expr);
        if (rc != RC::SUCCESS) {
          return rc;
        }
      } else {
        return RC::UNIMPLENMENT;
      }

      right_type = expr_sql_node->right_type;
      if (right_type == VALUE_T) {
        rc = check_value_date(expr_sql_node->right_value);
        if (rc != RC::SUCCESS) {
          return rc;
        }
        right_obj->init_value(expr_sql_node->right_value);
      }
      else if (right_type == ATTR_T) {
        Field tmp_field;
        rc = get_field(db, default_table, tables, expr_sql_node->right_attr, tmp_field);
        if (rc != RC::SUCCESS) {
          return rc;
        }
        right_obj->init_attr(tmp_field);
      }
      else if (right_type == EXPR_T) {
        rc = right_obj->init(db, default_table, tables, expr_sql_node->right_expr);
        if (rc != RC::SUCCESS) {
          return rc;
        }
      } else {
        return RC::UNIMPLENMENT;
      }
      init_expr(left_obj, right_obj, expr_sql_node->comp);
    } else if (expr_sql_node->type == ExpressType::EXPR_LIST_T) {
      for (auto iter : expr_sql_node->expr_list) {
        ExprObj *new_obj = new ExprObj();
        new_obj->init(db, default_table, tables, iter);
        this->expr_obj_list.push_back(new_obj);
      }
    } else {
      return RC::UNIMPLENMENT;
    }
    return rc;
  }
  RC init_list(Db *db, Table *default_table,
               std::unordered_map<std::string, Table *> *tables,
               ExprSqlNode *expr_sql_node) {
    RC rc = RC::SUCCESS;
    name = expr_sql_node->name;
    for (auto iter : expr_sql_node->expr_list) {
      ExprObj *new_tmp_expr_obj = new ExprObj();
      rc = new_tmp_expr_obj->init(db, default_table, tables, iter);
      if (rc != RC::SUCCESS) {
        return rc;
      }
      this->expr_obj_list.push_back(new_tmp_expr_obj);
    }
    this->type = ExpressType::EXPR_LIST_T;
    return rc;
  }

  std::unique_ptr<Expression> to_expression(
      std::map<std::string, LogicalOperator *> *map = nullptr) {
    switch (type) {
      case ExpressType::VALUE_T: {
        std::unique_ptr<Expression> value_expr(
            static_cast<Expression *>(new ValueExpr(left_value)));
        return value_expr;
      }
      case ExpressType::ATTR_T: {
        std::unique_ptr<Expression> field_expr(
            static_cast<Expression *>(new FieldExpr(left_field)));
        return field_expr;
      }
      case ExpressType::SELECT_T: {
        std::unique_ptr<Expression> select_expr(
            static_cast<Expression *>(new SelectExpr(left_select, map)));
        return select_expr;
      }
      case ExpressType::EXPR_T: {
        if (comp < ExprOp::COMP_LIMIT) {
          std::unique_ptr<Expression> comp_expr(static_cast<Expression *>(
              new ComparisonExpr(comp, left_expr->to_expression(map),
                                 right_expr->to_expression(map))));
          return comp_expr;
        } else {
          ArithmeticExpr::Type type;
          if (comp == ExprOp::ADD) {
            type = ArithmeticExpr::Type::ADD;
          } else if (comp == ExprOp::SUB) {
            type = ArithmeticExpr::Type::SUB;
          } else if (comp == ExprOp::MUL) {
            type = ArithmeticExpr::Type::MUL;
          } else if (comp == ExprOp::DIV) {
            type = ArithmeticExpr::Type::DIV;
          } else if (comp == ExprOp::NEGATIVE) {
            type = ArithmeticExpr::Type::NEGATIVE;
          }
          // 暂时不考虑左右为子查询的情况
          std::unique_ptr<Expression> left(
              left_type == ExpressType::VALUE_T
                  ? static_cast<Expression *>(new ValueExpr(left_value))
                  : (left_type == ExpressType::ATTR_T
                         ? static_cast<Expression *>(new FieldExpr(left_field))
                         : (left_type == ExpressType::SELECT_T
                                ? (static_cast<Expression *>(
                                      new SelectExpr(left_select, map)))
                                : left_expr->to_expression(map).release())));

          std::unique_ptr<Expression> right(
              right_type == ExpressType::VALUE_T
                  ? static_cast<Expression *>(new ValueExpr(right_value))
                  : (right_type == ExpressType::ATTR_T
                         ? static_cast<Expression *>(new FieldExpr(right_field))
                         : right_expr->to_expression(map).release()));
          std::unique_ptr<Expression> arith_expr(static_cast<Expression *>(
              new ArithmeticExpr(type, std::move(left), std::move(right))));
          return arith_expr;
        }
      }
      case ExpressType::EXPR_LIST_T: {
        std::unique_ptr<ListExpression> list_expression(new ListExpression());
        for (int i = 0; i < expr_obj_list.size(); i++) {
          list_expression->get_expr_list()->emplace_back(
              std::move(expr_obj_list[i]->to_expression(map)));
        }
        return list_expression;

      } break;

      default:
        return nullptr;
    }
  }
};
