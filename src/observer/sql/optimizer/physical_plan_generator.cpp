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
// Created by Wangyunlai on 2022/12/14.
//

#include "sql/optimizer/physical_plan_generator.h"

#include <utility>

#include "common/log/log.h"
#include "sql/expr/expression.h"
#include "sql/operator/aggregation_logical_operator.h"
#include "sql/operator/aggregation_physical_operator.h"
#include "sql/operator/calc_logical_operator.h"
#include "sql/operator/calc_physical_operator.h"
#include "sql/operator/delete_logical_operator.h"
#include "sql/operator/delete_physical_operator.h"
#include "sql/operator/explain_logical_operator.h"
#include "sql/operator/explain_physical_operator.h"
#include "sql/operator/group_by_logical_operator.h"
#include "sql/operator/group_by_physical_operator.h"
#include "sql/operator/index_scan_physical_operator.h"
#include "sql/operator/insert_logical_operator.h"
#include "sql/operator/insert_physical_operator.h"
#include "sql/operator/join_logical_operator.h"
#include "sql/operator/join_physical_operator.h"
#include "sql/operator/order_by_logical_operator.h"
#include "sql/operator/order_by_physical_operator.h"
#include "sql/operator/predicate_logical_operator.h"
#include "sql/operator/predicate_physical_operator.h"
#include "sql/operator/project_logical_operator.h"
#include "sql/operator/project_physical_operator.h"
#include "sql/operator/table_get_logical_operator.h"
#include "sql/operator/table_scan_physical_operator.h"
#include "sql/operator/update_logical_operator.h"
#include "sql/operator/update_physical_operator.h"

using namespace std;

RC PhysicalPlanGenerator::create(LogicalOperator &logical_operator,
                                 unique_ptr<PhysicalOperator> &oper) {
  RC rc = RC::SUCCESS;

  switch (logical_operator.type()) {
    case LogicalOperatorType::CALC: {
      return create_plan(static_cast<CalcLogicalOperator &>(logical_operator),
                         oper);
    } break;

    case LogicalOperatorType::TABLE_GET: {
      return create_plan(
          static_cast<TableGetLogicalOperator &>(logical_operator), oper);
    } break;

    case LogicalOperatorType::PREDICATE: {
      return create_plan(
          static_cast<PredicateLogicalOperator &>(logical_operator), oper);
    } break;
    case LogicalOperatorType::ORDER_BY: {
      return create_plan(
          static_cast<OrderByLogicalOperator &>(logical_operator), oper);
    } break;
    case LogicalOperatorType::GROUP_BY: {
      return create_plan(
          static_cast<GroupByLogicalOperator &>(logical_operator), oper);
    } break;
    case LogicalOperatorType::PROJECTION: {
      return create_plan(
          static_cast<ProjectLogicalOperator &>(logical_operator), oper);
    } break;
    case LogicalOperatorType::AGGREGATION: {
      return create_plan(
          static_cast<AggregationLogicalOperator &>(logical_operator), oper);
    } break;

    case LogicalOperatorType::INSERT: {
      return create_plan(static_cast<InsertLogicalOperator &>(logical_operator),
                         oper);
    } break;

    case LogicalOperatorType::DELETE: {
      return create_plan(static_cast<DeleteLogicalOperator &>(logical_operator),
                         oper);
    } break;
    case LogicalOperatorType::UPDATE: {
      return create_plan(static_cast<UpdateLogicalOperator &>(logical_operator),
                         oper);
    } break;
    case LogicalOperatorType::EXPLAIN: {
      return create_plan(
          static_cast<ExplainLogicalOperator &>(logical_operator), oper);
    } break;

    case LogicalOperatorType::JOIN: {
      return create_plan(static_cast<JoinLogicalOperator &>(logical_operator),
                         oper);
    } break;

    default: {
      return RC::INVALID_ARGUMENT;
    }
  }
  return rc;
}

RC PhysicalPlanGenerator::create_plan(TableGetLogicalOperator &table_get_oper,
                                      unique_ptr<PhysicalOperator> &oper) {
  vector<unique_ptr<Expression>> &predicates = table_get_oper.predicates();
  // 看看是否有可以用于索引查找的表达式
  Table *table = table_get_oper.table();

  Index *index = nullptr;
  ValueExpr *value_expr = nullptr;
  for (auto &expr : predicates) {
    if (expr->type() == ExprType::COMPARISON) {
      auto comparison_expr = static_cast<ComparisonExpr *>(expr.get());
      // 简单处理，就找等值查询
      // 先不使用索引
      if (comparison_expr->comp() != NO_OP) {
        continue;
      }

      unique_ptr<Expression> &left_expr = comparison_expr->left();
      unique_ptr<Expression> &right_expr = comparison_expr->right();
      // 左右比较的一边最少是一个值
      if (left_expr->type() != ExprType::VALUE &&
          right_expr->type() != ExprType::VALUE) {
        continue;
      }

      FieldExpr *field_expr = nullptr;
      if (left_expr->type() == ExprType::FIELD) {
        ASSERT(right_expr->type() == ExprType::VALUE,
               "right expr should be a value expr while left is field expr");
        field_expr = static_cast<FieldExpr *>(left_expr.get());
        value_expr = static_cast<ValueExpr *>(right_expr.get());
      } else if (right_expr->type() == ExprType::FIELD) {
        ASSERT(left_expr->type() == ExprType::VALUE,
               "left expr should be a value expr while right is a field expr");
        field_expr = static_cast<FieldExpr *>(right_expr.get());
        value_expr = static_cast<ValueExpr *>(left_expr.get());
      }

      if (field_expr == nullptr) {
        continue;
      }

      const Field &field = field_expr->field();
      index = table->find_index_by_field(field.field_name());
      if (nullptr != index) {
        break;
      }
    }
  }

  if (index != nullptr) {
    ASSERT(value_expr != nullptr, "got an index but value expr is null ?");

    const Value &value = value_expr->get_value();
    IndexScanPhysicalOperator *index_scan_oper = new IndexScanPhysicalOperator(
        table, index, table_get_oper.readonly(), &value,
        true /*left_inclusive*/, &value, true /*right_inclusive*/);

    index_scan_oper->set_predicates(std::move(predicates));
    oper = unique_ptr<PhysicalOperator>(index_scan_oper);
    logi_to_phys_map.insert({&table_get_oper, oper.get()});
    LOG_TRACE("use index scan");
  } else {
    auto table_scan_oper =
        new TableScanPhysicalOperator(table, table_get_oper.readonly());
    table_scan_oper->set_predicates(std::move(predicates));
    oper = unique_ptr<PhysicalOperator>(table_scan_oper);
    logi_to_phys_map.insert({&table_get_oper, oper.get()});
    LOG_TRACE("use table scan");
  }

  return RC::SUCCESS;
}

RC PhysicalPlanGenerator::create_plan(PredicateLogicalOperator &pred_oper,
                                      unique_ptr<PhysicalOperator> &oper) {
  vector<unique_ptr<LogicalOperator>> &children_opers = pred_oper.children();
  ASSERT(children_opers.size() == 1,
         "predicate logical operator's sub oper number should be 1");

  LogicalOperator &child_oper = *children_opers.front();

  unique_ptr<PhysicalOperator> child_phy_oper;
  RC rc = create(child_oper, child_phy_oper);
  if (rc != RC::SUCCESS) {
    LOG_WARN("failed to create child operator of predicate operator. rc=%s",
             strrc(rc));
    return rc;
  }

  vector<unique_ptr<Expression>> &expressions = pred_oper.expressions();
  ASSERT(expressions.size() == 1,
         "predicate logical operator's children should be 1");

  unique_ptr<Expression> expression = std::move(expressions.front());
  rc = expression->gen_physical();
  oper = unique_ptr<PhysicalOperator>(
      new PredicatePhysicalOperator(std::move(expression)));
  oper->add_child(std::move(child_phy_oper));
  return rc;
}

RC PhysicalPlanGenerator::create_plan(ProjectLogicalOperator &project_oper,
                                      unique_ptr<PhysicalOperator> &oper) {
  vector<unique_ptr<LogicalOperator>> &child_opers = project_oper.children();

  unique_ptr<PhysicalOperator> child_phy_oper;

  RC rc = RC::SUCCESS;
  if (!child_opers.empty()) {
    LogicalOperator *child_oper = child_opers.front().get();
    rc = create(*child_oper, child_phy_oper);
    if (rc != RC::SUCCESS) {
      LOG_WARN(
          "failed to create project logical operator's child physical "
          "operator. rc=%s",
          strrc(rc));
      return rc;
    }
  }

  ProjectPhysicalOperator *project_operator = new ProjectPhysicalOperator;
  const vector<Field> &project_fields = project_oper.fields();
  for (int i = 0; i < project_fields.size(); i++) {
    Field *field = const_cast<Field *>(&project_fields.at(i));
    TupleCellSpec *tmp_cell;
    tmp_cell = new TupleCellSpec(field);
    // if (field->has_alias()) {
    //   tmp_cell =
    //       new TupleCellSpec(field->table()->name(), field->meta()->name(),
    //                         field->get_alias().c_str());

    // } else {
    //   tmp_cell =
    //       new TupleCellSpec(field->table()->name(), field->meta()->name());
    // }
    // tmp_cell->set_func_type(field->get_func_type());
    project_operator->add_projection(*tmp_cell);
  }
  if (child_phy_oper) {
    project_operator->add_child(std::move(child_phy_oper));
  }

  oper = unique_ptr<PhysicalOperator>(project_operator);

  LOG_TRACE("create a project physical operator");
  return rc;
}
RC PhysicalPlanGenerator::create_plan(AggregationLogicalOperator &aggr_oper,
                                      std::unique_ptr<PhysicalOperator> &oper) {
  vector<unique_ptr<LogicalOperator>> &child_opers = aggr_oper.children();

  unique_ptr<PhysicalOperator> child_phy_oper;
  RC rc = RC::SUCCESS;
  if (!child_opers.empty()) {
    LogicalOperator *child_oper = child_opers.front().get();
    rc = create(*child_oper, child_phy_oper);
    if (rc != RC::SUCCESS) {
      LOG_WARN(
          "failed to create project logical operator's child physical "
          "operator. rc=%s",
          strrc(rc));
      return rc;
    }
  }
  const vector<Field> &aggr_fields = aggr_oper.aggregation_fields();
  const std::map<int, int> &aggr_field_to_proj_field_map =
      aggr_oper.aggr_field_to_proj_field_map();
  AggregationPhysicalOperator *aggr_operator = new AggregationPhysicalOperator(
      aggr_fields, aggr_field_to_proj_field_map);

  std::vector<std::unique_ptr<Expression>> &exprs = aggr_oper.expressions();
  for (size_t i = 0; i < exprs.size(); i++) {
    unique_ptr<Expression> expression = std::move(exprs.at(i));
    aggr_operator->add_expression(std::move(expression));
  }

  if (child_phy_oper) {
    aggr_operator->add_child(std::move(child_phy_oper));
  }
  oper = unique_ptr<PhysicalOperator>(aggr_operator);
  LOG_TRACE("create a aggregation physical operator");
  return rc;
}

RC PhysicalPlanGenerator::create_plan(InsertLogicalOperator &insert_oper,
                                      unique_ptr<PhysicalOperator> &oper) {
  Table *table = insert_oper.table();
  vector<Value> &values = insert_oper.values();
  vector<vector<Value>> insert_values = insert_oper.insert_values();
  InsertPhysicalOperator *insert_phy_oper =
      new InsertPhysicalOperator(table, std::move(insert_values));
  oper.reset(insert_phy_oper);
  return RC::SUCCESS;
}

RC PhysicalPlanGenerator::create_plan(DeleteLogicalOperator &delete_oper,
                                      unique_ptr<PhysicalOperator> &oper) {
  vector<unique_ptr<LogicalOperator>> &child_opers = delete_oper.children();

  unique_ptr<PhysicalOperator> child_physical_oper;

  RC rc = RC::SUCCESS;
  if (!child_opers.empty()) {
    LogicalOperator *child_oper = child_opers.front().get();
    rc = create(*child_oper, child_physical_oper);
    if (rc != RC::SUCCESS) {
      LOG_WARN("failed to create physical operator. rc=%s", strrc(rc));
      return rc;
    }
  }

  oper = unique_ptr<PhysicalOperator>(
      new DeletePhysicalOperator(delete_oper.table()));

  if (child_physical_oper) {
    oper->add_child(std::move(child_physical_oper));
  }
  return rc;
}
RC PhysicalPlanGenerator::create_plan(UpdateLogicalOperator &update_oper,
                                      unique_ptr<PhysicalOperator> &oper) {
  vector<unique_ptr<LogicalOperator>> &child_opers = update_oper.children();
  unique_ptr<PhysicalOperator> child_physical_oper;

  RC rc = RC::SUCCESS;
  if (!child_opers.empty()) {
    LogicalOperator *child_oper = child_opers.front().get();
    rc = create(*child_oper, child_physical_oper);
    if (rc != RC::SUCCESS) {
      LOG_WARN("failed to create physical operator. rc=%s", strrc(rc));
      return rc;
    }
  }

  oper = unique_ptr<UpdatePhysicalOperator>(new UpdatePhysicalOperator(
      update_oper.table(), update_oper.attribute_names(), update_oper.values(),
      update_oper.set_selects_attr_name()));

  if (!update_oper.set_selects_logical_opers().empty()) {
    size_t set_selects_num = update_oper.set_selects_logical_opers().size();
    for (size_t i = 0; i < set_selects_num; i++) {
      unique_ptr<PhysicalOperator> tmp_physical_oper;

      rc = this->create(*(update_oper.set_selects_logical_opers()[i]),
                        tmp_physical_oper);
      if (rc != RC::SUCCESS) {
        LOG_WARN("failed to create physical operator. rc=%s", strrc(rc));
        return rc;
      }

      UpdatePhysicalOperator *tmp_ptr =
          dynamic_cast<UpdatePhysicalOperator *>(oper.get());
      tmp_ptr->add_set_selects_physical_oper(std::move(tmp_physical_oper));
    }
  }

  if (child_physical_oper) {
    oper->add_child(std::move(child_physical_oper));
  }

  return rc;
}

RC PhysicalPlanGenerator::create_plan(ExplainLogicalOperator &explain_oper,
                                      unique_ptr<PhysicalOperator> &oper) {
  vector<unique_ptr<LogicalOperator>> &child_opers = explain_oper.children();

  RC rc = RC::SUCCESS;
  unique_ptr<PhysicalOperator> explain_physical_oper(
      new ExplainPhysicalOperator);
  for (unique_ptr<LogicalOperator> &child_oper : child_opers) {
    unique_ptr<PhysicalOperator> child_physical_oper;
    rc = create(*child_oper, child_physical_oper);
    if (rc != RC::SUCCESS) {
      LOG_WARN("failed to create child physical operator. rc=%s", strrc(rc));
      return rc;
    }

    explain_physical_oper->add_child(std::move(child_physical_oper));
  }

  oper = std::move(explain_physical_oper);
  return rc;
}

RC PhysicalPlanGenerator::create_plan(JoinLogicalOperator &join_oper,
                                      unique_ptr<PhysicalOperator> &oper) {
  RC rc = RC::SUCCESS;

  vector<unique_ptr<LogicalOperator>> &child_opers = join_oper.children();
  if (child_opers.size() != 2 &&
      !(join_oper.is_left_sub_link() || join_oper.is_right_sub_link())) {
    LOG_WARN(
        "join operator should have 2 children or have sub link node, but have "
        "%d",
        child_opers.size());
    return RC::INTERNAL;
  }

  vector<unique_ptr<Expression>> &predicates = join_oper.predicates();
  if (predicates.size() == 1) {
    if (predicates.front()->type() == ExprType::COMPARISON) {
      auto comp_expr = static_cast<ComparisonExpr *>(predicates.front().get());
      if (comp_expr->comp() == CompOp::EQUAL_TO) {
        unique_ptr<HashJoinPhysicalOperator> join_physical_oper(
            new HashJoinPhysicalOperator);
        for (auto &child_oper : child_opers) {
          unique_ptr<PhysicalOperator> child_physical_oper;
          rc = create(*child_oper, child_physical_oper);
          if (rc != RC::SUCCESS) {
            LOG_WARN("failed to create physical child oper. rc=%s", strrc(rc));
            return rc;
          }
          join_physical_oper->add_child(std::move(child_physical_oper));
        }
        join_physical_oper->set_predicates(std::move(predicates));
        oper = std::move(join_physical_oper);
        return rc;
      }
    }
  }
  unique_ptr<NestedLoopJoinPhysicalOperator> join_physical_oper(
      new NestedLoopJoinPhysicalOperator);
  if (join_oper.is_left_sub_link()) {
    join_physical_oper->set_is_left_sub_link(true);
    PhysicalOperator *tmp_phy_ptr = PhysicalPlanGenerator::logi_to_phys_map.at(
        const_cast<LogicalOperator *>(join_oper.left_link()));
    join_physical_oper->set_left_link(tmp_phy_ptr);
  }
  for (auto &child_oper : child_opers) {
    unique_ptr<PhysicalOperator> child_physical_oper;
    rc = create(*child_oper, child_physical_oper);
    if (rc != RC::SUCCESS) {
      LOG_WARN("failed to create physical child oper. rc=%s", strrc(rc));
      return rc;
    }
    join_physical_oper->add_child(std::move(child_physical_oper));
  }
  if (join_oper.is_right_sub_link()) {
    join_physical_oper->set_is_right_sub_link(true);
    PhysicalOperator *tmp_phy_ptr = PhysicalPlanGenerator::logi_to_phys_map.at(
        const_cast<LogicalOperator *>(join_oper.right_link()));
    join_physical_oper->set_right_link(tmp_phy_ptr);
  }
  join_physical_oper->set_predicates(std::move(predicates));
  oper = std::move(join_physical_oper);

  return rc;
}

RC PhysicalPlanGenerator::create_plan(CalcLogicalOperator &logical_oper,
                                      std::unique_ptr<PhysicalOperator> &oper) {
  RC rc = RC::SUCCESS;
  CalcPhysicalOperator *calc_oper =
      new CalcPhysicalOperator(std::move(logical_oper.expressions()));
  oper.reset(calc_oper);
  return rc;
}

RC PhysicalPlanGenerator::create_plan(OrderByLogicalOperator &order_by_oper,
                                      std::unique_ptr<PhysicalOperator> &oper) {
  vector<unique_ptr<LogicalOperator>> &child_opers = order_by_oper.children();

  unique_ptr<PhysicalOperator> child_phy_oper;
  RC rc = RC::SUCCESS;
  if (!child_opers.empty()) {
    LogicalOperator *child_oper = child_opers.front().get();
    rc = create(*child_oper, child_phy_oper);
    if (rc != RC::SUCCESS) {
      LOG_WARN(
          "failed to create project logical operator's child physical "
          "operator. rc=%s",
          strrc(rc));
      return rc;
    }
  }
  // const std::map<Field *, OrderByDirection> &field_direction_map =
  //     order_by_oper.field_direction_map();
  OrderByPhysicalOperator *order_by_operator = new OrderByPhysicalOperator(
      order_by_oper.fields(), order_by_oper.directions());

  if (child_phy_oper) {
    order_by_operator->add_child(std::move(child_phy_oper));
  }
  oper = unique_ptr<PhysicalOperator>(order_by_operator);
  LOG_TRACE("create an Order_by physical operator");
  return rc;
}

RC PhysicalPlanGenerator::create_plan(GroupByLogicalOperator &group_by_oper,
                                      std::unique_ptr<PhysicalOperator> &oper) {
  vector<unique_ptr<LogicalOperator>> &child_opers = group_by_oper.children();

  unique_ptr<PhysicalOperator> child_phy_oper;
  RC rc = RC::SUCCESS;
  if (!child_opers.empty()) {
    LogicalOperator *child_oper = child_opers.front().get();
    rc = create(*child_oper, child_phy_oper);
    if (rc != RC::SUCCESS) {
      LOG_WARN(
          "failed to create project logical operator's child physical "
          "operator. rc=%s",
          strrc(rc));
      return rc;
    }
  }

  GroupByPhysicalOperator *group_by_operator =
      new GroupByPhysicalOperator(group_by_oper.fields());
  if (child_phy_oper) {
    group_by_operator->add_child(std::move(child_phy_oper));
  }
  oper = unique_ptr<PhysicalOperator>(group_by_operator);
  LOG_TRACE("create an Group_by physical operator");
  return rc;
}