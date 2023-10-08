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
// Created by Wangyunlai on 2022/12/30.
//

#include "sql/optimizer/predicate_pushdown_rewriter.h"

#include "sql/expr/expression.h"
#include "sql/operator/table_get_logical_operator.h"

RC PredicatePushdownRewriter::rewrite(std::unique_ptr<LogicalOperator> &oper,
                                      bool &change_made) {
  RC rc = RC::SUCCESS;
  if (oper->type() != LogicalOperatorType::PREDICATE) {
    return rc;
  }

  if (oper->children().size() != 1) {
    return rc;
  }

  std::unique_ptr<LogicalOperator> &child_oper = oper->children().front();

  if (child_oper->type() == LogicalOperatorType::TABLE_GET) {
    auto table_get_oper =
        static_cast<TableGetLogicalOperator *>(child_oper.get());

    std::vector<std::unique_ptr<Expression>> &predicate_oper_exprs =
        oper->expressions();
    if (predicate_oper_exprs.size() != 1) {
      return rc;
    }

    std::unique_ptr<Expression> &predicate_expr = predicate_oper_exprs.front();
    std::vector<std::unique_ptr<Expression>> pushdown_exprs;
    rc = get_exprs_can_pushdown(predicate_expr, pushdown_exprs);
    if (rc != RC::SUCCESS) {
      LOG_WARN("failed to get exprs can pushdown. rc=%s", strrc(rc));
      return rc;
    }

    if (!predicate_expr) {
      // 所有的表达式都下推到了下层算子
      // 这个predicate
      // operator其实就可以不要了。但是这里没办法删除，弄一个空的表达式吧
      LOG_TRACE(
          "all expressions of predicate operator were pushdown to table get "
          "operator, then make a fake one");

      Value value((bool)true);
      predicate_expr = std::unique_ptr<Expression>(new ValueExpr(value));
    }

    if (!pushdown_exprs.empty()) {
      change_made = true;
      table_get_oper->set_predicates(std::move(pushdown_exprs));
    }
    return rc;
  } else if (child_oper->type() == LogicalOperatorType::JOIN) {
    auto join_oper = static_cast<JoinLogicalOperator *>(child_oper.get());

    std::vector<std::unique_ptr<Expression>> &predicate_oper_exprs =
        oper->expressions();
    if (predicate_oper_exprs.size() != 1) {
      return rc;
    }

    std::unique_ptr<Expression> &predicate_expr = predicate_oper_exprs.front();
    /*{
      // 这段代码用于在condition数量小于3时 不进行下推
      ConjunctionExpr *conjunction_expr =
          static_cast<ConjunctionExpr *>(predicate_expr.get());
      std::vector<std::unique_ptr<Expression>> &child_exprs =
          conjunction_expr->children();
      if (child_exprs.size() <= 2) return rc;
    }*/

    bool pushdown_result = false;
    rc = join_exprs_can_pushdown(join_oper, predicate_expr, pushdown_result);
    if (rc != RC::SUCCESS) {
      LOG_WARN("failed to get exprs can pushdown. rc=%s", strrc(rc));
      return rc;
    }

    if (!predicate_expr) {
      // 所有的表达式都下推到了下层算子
      // 这个predicate
      // operator其实就可以不要了。但是这里没办法删除，弄一个空的表达式吧
      LOG_TRACE(
          "all expressions of predicate operator were pushdown to table get "
          "operator, then make a fake one");

      Value value((bool)true);
      predicate_expr = std::unique_ptr<Expression>(new ValueExpr(value));
    }

    if (pushdown_result) {
      change_made = true;
    }
    return rc;
  }

  return rc;
}

/**
 * 判断一个子树是否包含该表达式取值的表
 */
RC PredicatePushdownRewriter::contain_expr(LogicalOperator *oper,
                                           std::unique_ptr<Expression> &expr,
                                           bool &contain_result) {
  RC rc = RC::SUCCESS;
  if (expr->type() != ExprType::FIELD) {
    return rc;
  }
  if (oper->type() != LogicalOperatorType::TABLE_GET &&
      oper->type() != LogicalOperatorType::JOIN) {
    return rc;
  }
  if (oper->type() == LogicalOperatorType::TABLE_GET) {
    auto table_get_oper = static_cast<TableGetLogicalOperator *>(oper);
    Table *table = table_get_oper->table();
    auto filed_expr = static_cast<FieldExpr *>(expr.get());
    if (strcmp(table->name(), filed_expr->table_name()) == 0) {
      contain_result = true;
    }
    return rc;
  } else {
    auto join_oper = static_cast<JoinLogicalOperator *>(oper);
    std::vector<std::unique_ptr<LogicalOperator>> &children_opers =
        join_oper->children();
    for (auto iter = children_opers.begin(); iter != children_opers.end();
         iter++) {
      rc = contain_expr(iter->get(), expr, contain_result);
      if (rc != RC::SUCCESS) {
        return rc;
      }
      if (contain_result) {
        return rc;
      }
    }
    return rc;
  }
}

/**
 * 查看表达式是否可以直接下放到table get算子的filter
 * @param expr 是当前的表达式。如果可以下放给table get
 * 算子，执行完成后expr就失效了
 * @param pushdown_exprs 当前所有要下放给table get
 * 算子的filter。此函数执行多次， pushdown_exprs 只会增加，不要做清理操作
 */
RC PredicatePushdownRewriter::get_exprs_can_pushdown(
    std::unique_ptr<Expression> &expr,
    std::vector<std::unique_ptr<Expression>> &pushdown_exprs) {
  RC rc = RC::SUCCESS;
  if (expr->type() == ExprType::CONJUNCTION) {
    ConjunctionExpr *conjunction_expr =
        static_cast<ConjunctionExpr *>(expr.get());
    // 或 操作的比较，太复杂，现在不考虑
    if (conjunction_expr->conjunction_type() == ConjunctionExpr::Type::OR) {
      return rc;
    }

    std::vector<std::unique_ptr<Expression>> &child_exprs =
        conjunction_expr->children();
    for (auto iter = child_exprs.begin(); iter != child_exprs.end();) {
      // 对每个子表达式，判断是否可以下放到table get 算子
      // 如果可以的话，就从当前孩子节点中删除他
      rc = get_exprs_can_pushdown(*iter, pushdown_exprs);
      if (rc != RC::SUCCESS) {
        LOG_WARN("failed to get pushdown expressions. rc=%s", strrc(rc));
        return rc;
      }

      if (!*iter) {
        child_exprs.erase(iter);
      } else {
        ++iter;
      }
    }
  } else if (expr->type() == ExprType::COMPARISON) {
    // 如果是比较操作，并且比较的左边或右边是表某个列值，那么就下推下去
    auto comparison_expr = static_cast<ComparisonExpr *>(expr.get());
    CompOp comp = comparison_expr->comp();
    if (comp == NO_OP) {
      // 简单处理，仅取等值比较。当然还可以取一些范围比较，还有 like % 等操作
      // 其它的还有 is null 等
      // fixed: pushdown all comps
      return rc;
    }

    std::unique_ptr<Expression> &left_expr = comparison_expr->left();
    std::unique_ptr<Expression> &right_expr = comparison_expr->right();
    // 比较操作的左右两边只要有一个是取列字段值的并且另一边也是取字段值或常量，就pushdown
    if (left_expr->type() != ExprType::FIELD &&
        right_expr->type() != ExprType::FIELD) {
      return rc;
    }
    if (left_expr->type() != ExprType::FIELD &&
        left_expr->type() != ExprType::VALUE &&
        right_expr->type() != ExprType::FIELD &&
        right_expr->type() != ExprType::VALUE) {
      return rc;
    }

    pushdown_exprs.emplace_back(std::move(expr));
  }
  return rc;
}

RC PredicatePushdownRewriter::join_exprs_can_pushdown(
    JoinLogicalOperator *&join_oper, std::unique_ptr<Expression> &expr,
    bool &pushdown_result) {
  RC rc = RC::SUCCESS;
  if (expr->type() == ExprType::CONJUNCTION) {
    ConjunctionExpr *conjunction_expr =
        static_cast<ConjunctionExpr *>(expr.get());
    // 或 操作的比较，太复杂，现在不考虑
    if (conjunction_expr->conjunction_type() == ConjunctionExpr::Type::OR) {
      return rc;
    }

    std::vector<std::unique_ptr<Expression>> &child_exprs =
        conjunction_expr->children();
    for (auto iter = child_exprs.begin(); iter != child_exprs.end();) {
      // 对每个子表达式，判断是否可以下放到join 算子
      // 如果可以的话，就从当前孩子节点中删除他
      rc = join_exprs_can_pushdown(join_oper, *iter, pushdown_result);
      if (rc != RC::SUCCESS) {
        LOG_WARN("failed to get pushdown expressions. rc=%s", strrc(rc));
        return rc;
      }

      if (!*iter) {
        child_exprs.erase(iter);
      } else {
        ++iter;
      }
    }
  } else if (expr->type() == ExprType::COMPARISON) {
    // 如果是比较操作，并且比较的左边或右边是表某个列值，那么就下推下去
    auto comparison_expr = static_cast<ComparisonExpr *>(expr.get());
    CompOp comp = comparison_expr->comp();
    if (comp == NO_OP) {
      // 简单处理，仅取等值比较。当然还可以取一些范围比较，还有 like % 等操作
      // 其它的还有 is null 等
      // fixed: pushdown all comps
      return rc;
    }

    std::unique_ptr<Expression> &left_expr = comparison_expr->left();
    std::unique_ptr<Expression> &right_expr = comparison_expr->right();
    // 比较操作的左右两边只要有一个是取列字段值的并且另一边也是取字段值或常量，就pushdown
    if (left_expr->type() != ExprType::FIELD &&
        right_expr->type() != ExprType::FIELD) {
      return rc;
    }
    if (left_expr->type() != ExprType::FIELD &&
        left_expr->type() != ExprType::VALUE &&
        right_expr->type() != ExprType::FIELD &&
        right_expr->type() != ExprType::VALUE) {
      return rc;
    }

    // 预处理出左右子树是否包含该表达式
    bool left_oper_result = false;
    bool right_oper_result = false;
    bool need_swap = false;  // 是否需要交换左右表达式
    std::vector<std::unique_ptr<LogicalOperator>> &children_opers =
        join_oper->children();
    std::unique_ptr<LogicalOperator> &left_oper = children_opers.front();
    rc = contain_expr(left_oper.get(), left_expr, left_oper_result);
    if (rc != RC::SUCCESS) {
      return rc;
    }
    if (!left_oper_result) {
      rc = contain_expr(left_oper.get(), right_expr, left_oper_result);
      if (rc != RC::SUCCESS) {
        return rc;
      }
      if (left_oper_result) {
        need_swap = true;
      }
    }

    std::unique_ptr<LogicalOperator> &right_oper = children_opers.back();
    rc = contain_expr(right_oper.get(), left_expr, right_oper_result);
    if (rc != RC::SUCCESS) {
      return rc;
    }
    if (!right_oper_result) {
      rc = contain_expr(right_oper.get(), right_expr, right_oper_result);
      if (rc != RC::SUCCESS) {
        return rc;
      }
    }

    if (left_expr->type() == ExprType::FIELD &&
        right_expr->type() == ExprType::FIELD) {
      // 两边都是取字段值，如果字段分别在左右子树，就pushdown到当前operator节点；否则继续下推
      if (left_oper_result) {
        if (right_oper_result) {
          if (need_swap) {
            comparison_expr->swap_left_right();
          }
          join_oper->add_predicates(expr);
        } else {
          // pushdown to left child
          if (left_oper->type() == LogicalOperatorType::TABLE_GET) {
            std::vector<std::unique_ptr<Expression>> pushdown_exprs;
            rc = get_exprs_can_pushdown(expr, pushdown_exprs);
            if (rc != RC::SUCCESS) {
              LOG_WARN("failed to get exprs can pushdown. rc=%s", strrc(rc));
              return rc;
            }

            if (!pushdown_exprs.empty()) {
              auto table_get_oper =
                  static_cast<TableGetLogicalOperator *>(left_oper.get());
              table_get_oper->set_predicates(std::move(pushdown_exprs));
            } else {
              pushdown_result = false;
            }
          } else {
            auto child_join_oper =
                static_cast<JoinLogicalOperator *>(left_oper.get());
            rc =
                join_exprs_can_pushdown(child_join_oper, expr, pushdown_result);
            if (rc != RC::SUCCESS) {
              return rc;
            }
          }
        }
      } else {
        if (right_oper_result) {
          // pushdown to right child
          if (right_oper->type() == LogicalOperatorType::TABLE_GET) {
            std::vector<std::unique_ptr<Expression>> pushdown_exprs;
            rc = get_exprs_can_pushdown(expr, pushdown_exprs);
            if (rc != RC::SUCCESS) {
              LOG_WARN("failed to get exprs can pushdown. rc=%s", strrc(rc));
              return rc;
            }

            if (!pushdown_exprs.empty()) {
              auto table_get_oper =
                  static_cast<TableGetLogicalOperator *>(right_oper.get());
              table_get_oper->set_predicates(std::move(pushdown_exprs));
            } else {
              pushdown_result = false;
            }
          } else {
            auto child_join_oper =
                static_cast<JoinLogicalOperator *>(right_oper.get());
            rc =
                join_exprs_can_pushdown(child_join_oper, expr, pushdown_result);
            if (rc != RC::SUCCESS) {
              return rc;
            }
          }
        } else {
          return RC::SCHEMA_TABLE_NOT_EXIST;
        }
      }
    } else {
      // 某一边是字段值，必然会下推到一个子树
      if (left_oper_result) {
        // pushdown to left child
        if (left_oper->type() == LogicalOperatorType::TABLE_GET) {
          std::vector<std::unique_ptr<Expression>> pushdown_exprs;
          rc = get_exprs_can_pushdown(expr, pushdown_exprs);
          if (rc != RC::SUCCESS) {
            LOG_WARN("failed to get exprs can pushdown. rc=%s", strrc(rc));
            return rc;
          }

          if (!pushdown_exprs.empty()) {
            auto table_get_oper =
                static_cast<TableGetLogicalOperator *>(left_oper.get());
            table_get_oper->set_predicates(std::move(pushdown_exprs));
          } else {
            pushdown_result = false;
          }
        } else {
          auto child_join_oper =
              static_cast<JoinLogicalOperator *>(left_oper.get());
          rc = join_exprs_can_pushdown(child_join_oper, expr, pushdown_result);
          if (rc != RC::SUCCESS) {
            return rc;
          }
        }
      } else {
        // pushdown to right child
        if (right_oper->type() == LogicalOperatorType::TABLE_GET) {
          std::vector<std::unique_ptr<Expression>> pushdown_exprs;
          rc = get_exprs_can_pushdown(expr, pushdown_exprs);
          if (rc != RC::SUCCESS) {
            LOG_WARN("failed to get exprs can pushdown. rc=%s", strrc(rc));
            return rc;
          }

          if (!pushdown_exprs.empty()) {
            auto table_get_oper =
                static_cast<TableGetLogicalOperator *>(right_oper.get());
            table_get_oper->set_predicates(std::move(pushdown_exprs));
          } else {
            pushdown_result = false;
          }
        } else {
          auto child_join_oper =
              static_cast<JoinLogicalOperator *>(right_oper.get());
          rc = join_exprs_can_pushdown(child_join_oper, expr, pushdown_result);
          if (rc != RC::SUCCESS) {
            return rc;
          }
        }
      }
    }

    pushdown_result = true;
    return rc;
  }
  return rc;
}