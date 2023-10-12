/* Copyright (c) 2021 OceanBase and/or its affiliates. All rights reserved.
miniob is licensed under Mulan PSL v2.
You can use this software according to the terms and conditions of the Mulan PSL v2.
You may obtain a copy of Mulan PSL v2 at:
         http://license.coscl.org.cn/MulanPSL2
THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
See the Mulan PSL v2 for more details. */

//
// Created by Wangyunlai on 2022/5/22.
//

#pragma once

#include <vector>
#include <unordered_map>
#include "sql/parser/parse_defs.h"
#include "sql/stmt/select_stmt.h"
#include "sql/stmt/stmt.h"
#include "sql/expr/expression.h"

class Db;
class Table;
class FieldMeta;

RC get_table_and_field(Db *db, Table *default_table,
                       std::unordered_map<std::string, Table *> *tables,
                       const RelAttrSqlNode &attr, Table *&table,
                       const FieldMeta *&field);

struct ExprObj
{
  std::string name;
  ExpressType type;

  ExpressType left_type;
  Value left_value;
  Field left_field;
  SelectStmt* left_select;
  ExprObj* left_expr;
  ExprOp comp;
  ExpressType right_type;
  Value right_value;
  Field right_field;
  SelectStmt* right_select;
  ExprObj* right_expr;

  void init_value(const Value &value)
  {
    type = ExpressType::VALUE_T;
    left_value = value;
  }

  void init_attr(const Field &field)
  {
    type = ExpressType::ATTR_T;
    left_field = field;
  }

  void init_select(const SelectStmt* select_stmt)
  {
    type = ExpressType::SELECT_T;
    left_select = (SelectStmt*)select_stmt;
  }

  void init_left(ExprObj* left_obj)
  {
    left_type = left_obj->type;
    switch (left_type)
    {
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

  void init_right(ExprObj* right_obj)
  {
    right_type = right_obj->type;
    switch (right_type)
    {
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

  void init_expr(ExprObj* left_obj, ExprObj* right_obj, ExprOp exprop)
  {
    type = ExpressType::EXPR_T;
    init_left(left_obj);
    comp = exprop;
    init_right(right_obj);
  }

  RC init(Db *db, Table *default_table,
    std::unordered_map<std::string, Table *> *tables, ExprSqlNode* expr_sql_node)
  {
    RC rc = RC::SUCCESS;
    name = expr_sql_node->name;
    if (expr_sql_node->type == ExpressType::VALUE_T) {
      init_value(expr_sql_node->left_value);
      if (left_value.attr_type() == AttrType::DATES && left_value.get_date() == -1) {
        rc = RC::INVALID_DATE;
        LOG_WARN("Invalid date.");
        return rc;
      }
    }
    else if (expr_sql_node->type == ExpressType::ATTR_T) {
      Table *table = nullptr;
      const FieldMeta *field = nullptr;
      if (expr_sql_node->left_attr.is_aggregation_func &&
          expr_sql_node->left_attr.aggr_func_type == AggrFuncType::CNT &&
          0 == strcmp("*", expr_sql_node->left_attr.attribute_name.c_str())) {
        // 对于COUNT(*)>value做单独的处理
        Field tmp_field;
        tmp_field.set_aggr_func_type(expr_sql_node->left_attr.aggr_func_type);
        init_attr(tmp_field);
      } else {
        rc = get_table_and_field(db, default_table, tables, expr_sql_node->left_attr,
                                table, field);
        if (rc != RC::SUCCESS) {
          LOG_WARN("cannot find attr");
          return rc;
        }
        Field tmp_field(table, field);
        if (expr_sql_node->left_attr.is_aggregation_func) {
          tmp_field.set_aggr_func_type(expr_sql_node->left_attr.aggr_func_type);
        }
        init_attr(tmp_field);
      }
    }
    else if (expr_sql_node->type == ExpressType::EXPR_T) {
      ExprObj *left_obj = new ExprObj();
      ExprObj *right_obj = new ExprObj();
      left_type = expr_sql_node->left_type;
      if (left_type == VALUE_T) {
        left_obj->init_value(expr_sql_node->left_value);
        if (left_obj->left_value.attr_type() == AttrType::DATES && left_obj->left_value.get_date() == -1) {
          rc = RC::INVALID_DATE;
          LOG_WARN("Invalid date.");
          return rc;
        }
      }
      else if (left_type == ATTR_T) {
        Table *table = nullptr;
        const FieldMeta *field = nullptr;
        if (expr_sql_node->left_attr.is_aggregation_func &&
            expr_sql_node->left_attr.aggr_func_type == AggrFuncType::CNT &&
            0 == strcmp("*", expr_sql_node->left_attr.attribute_name.c_str())) {
          // 对于COUNT(*)>value做单独的处理
          Field tmp_field;
          tmp_field.set_aggr_func_type(expr_sql_node->left_attr.aggr_func_type);
          left_obj->init_attr(tmp_field);
        } else {
          rc = get_table_and_field(db, default_table, tables, expr_sql_node->left_attr,
                                  table, field);
          if (rc != RC::SUCCESS) {
            LOG_WARN("cannot find attr");
            return rc;
          }
          Field tmp_field(table, field);
          if (expr_sql_node->left_attr.is_aggregation_func) {
            tmp_field.set_aggr_func_type(expr_sql_node->left_attr.aggr_func_type);
          }
          left_obj->init_attr(tmp_field);
        }
      }
      else if (left_type == EXPR_T) {
        rc = left_obj->init(db, default_table, tables, expr_sql_node->left_expr);
        if (rc != RC::SUCCESS) {
          return rc;
        }
      }
      else {
        return RC::UNIMPLENMENT;
      }

      right_type = expr_sql_node->right_type;
      if (right_type == VALUE_T) {
        right_obj->init_value(expr_sql_node->right_value);
        if (right_obj->left_value.attr_type() == AttrType::DATES && right_obj->left_value.get_date() == -1) {
          rc = RC::INVALID_DATE;
          LOG_WARN("Invalid date.");
          return rc;
        }
      }
      else if (right_type == ATTR_T) {
        Table *table = nullptr;
        const FieldMeta *field = nullptr;
        if (expr_sql_node->right_attr.is_aggregation_func &&
            expr_sql_node->right_attr.aggr_func_type == AggrFuncType::CNT &&
            0 == strcmp("*", expr_sql_node->right_attr.attribute_name.c_str())) {
          // 对于COUNT(*)>value做单独的处理
          Field tmp_field;
          tmp_field.set_aggr_func_type(expr_sql_node->right_attr.aggr_func_type);
          right_obj->init_attr(tmp_field);
        } else {
          rc = get_table_and_field(db, default_table, tables, expr_sql_node->right_attr,
                                  table, field);
          if (rc != RC::SUCCESS) {
            LOG_WARN("cannot find attr");
            return rc;
          }
          Field tmp_field(table, field);
          if (expr_sql_node->right_attr.is_aggregation_func) {
            tmp_field.set_aggr_func_type(expr_sql_node->right_attr.aggr_func_type);
          }
          right_obj->init_attr(tmp_field);
        }
      }
      else if (right_type == EXPR_T) {
        rc = right_obj->init(db, default_table, tables, expr_sql_node->right_expr);
        if (rc != RC::SUCCESS) {
          return rc;
        }
      }
      else {
        return RC::UNIMPLENMENT;
      }
      init_expr(left_obj, right_obj, expr_sql_node->comp);
    }
    else {
      return RC::UNIMPLENMENT;
    }
    return rc;
  }

  std::unique_ptr<Expression> to_expression()
  {
    switch (type)
    {
    case ExpressType::VALUE_T:
      {
        std::unique_ptr<Expression> value_expr(
          static_cast<Expression*>(new ValueExpr(left_value)));
        return value_expr;
      }
    case ExpressType::ATTR_T:
      {
        std::unique_ptr<Expression> field_expr(
          static_cast<Expression*>(new FieldExpr(left_field)));
        return field_expr;
      }
    case ExpressType::EXPR_T:
      {
        if (comp < ExprOp::COMP_LIMIT) {
          std::unique_ptr<Expression> comp_expr(
            static_cast<Expression*>(new ComparisonExpr(comp,
                left_expr->to_expression(),
                right_expr->to_expression()))
          );
          return comp_expr;
        }
        else {
          ArithmeticExpr::Type type;
          if (comp == ExprOp::ADD) {
            type = ArithmeticExpr::Type::ADD;
          }
          else if (comp == ExprOp::SUB) {
            type = ArithmeticExpr::Type::SUB;
          }
          else if (comp == ExprOp::MUL) {
            type = ArithmeticExpr::Type::MUL;
          }
          else if (comp == ExprOp::DIV) {
            type = ArithmeticExpr::Type::DIV;
          }
          else if (comp == ExprOp::NEGATIVE) {
            type = ArithmeticExpr::Type::NEGATIVE;
          }
          // 暂时不考虑左右为子查询的情况
          std::unique_ptr<Expression> left(
            left_type == ExpressType::VALUE_T ? static_cast<Expression*>(new ValueExpr(left_value)) :
            (left_type == ExpressType::ATTR_T ? static_cast<Expression*>(new FieldExpr(left_field)) :
            left_expr->to_expression().release())
          );
          
          std::unique_ptr<Expression> right(
            right_type == ExpressType::VALUE_T ? static_cast<Expression*>(new ValueExpr(right_value)) :
            (right_type == ExpressType::ATTR_T ? static_cast<Expression*>(new FieldExpr(right_field)) :
            right_expr->to_expression().release())
          );
          std::unique_ptr<Expression> arith_expr(
            static_cast<Expression*>(new ArithmeticExpr(type, std::move(left), std::move(right))));
          return arith_expr;
        }
      }
    
    default:
      return nullptr;
    }
  }
};
