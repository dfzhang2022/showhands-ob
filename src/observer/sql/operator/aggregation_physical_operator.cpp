#include "sql/operator/aggregation_physical_operator.h"

#include "common/log/log.h"
#include "storage/record/record.h"
#include "storage/table/table.h"

RC AggregationPhysicalOperator::open(Trx* trx) {
  if (children_.empty()) {
    return RC::SUCCESS;
  }
  PhysicalOperator* child = children_[0].get();
  RC rc = child->open(trx);
  if (rc != RC::SUCCESS) {
    LOG_WARN("failed to open child operator: %s", strrc(rc));
    return rc;
  }

  std::vector<TupleCellSpec*> speces;
  for (int i = 0; i < aggregation_fields_.size(); i++) {
    TupleCellSpec* tmp_cell;
    if (aggregation_fields_[i].table() == nullptr) {
      tmp_cell = new TupleCellSpec(nullptr, nullptr,
                                   aggregation_fields_[i].get_alias().c_str());
    } else {
      tmp_cell = new TupleCellSpec(aggregation_fields_[i].table_name(),
                                   aggregation_fields_[i].field_name(),
                                   aggregation_fields_[i].get_alias().c_str());
    }
    speces.push_back(tmp_cell);
  }
  this->tuple_.set_speces(speces);
  is_dirty_ = false;

  return RC::SUCCESS;
}

RC AggregationPhysicalOperator::next() {
  if (children_.empty()) {
    return RC::RECORD_EOF;
  }

  RC rc;
  while (1) {
    if (is_dirty_ &&
        children_[0].get()->type() != PhysicalOperatorType::GROUP_BY)
      return RC::RECORD_EOF;
    is_dirty_ = true;

    std::vector<Value> values;
    for (size_t i = 0; i < aggregation_fields_.size(); i++) {
      values.emplace_back(Value(0));
    }

    int row_index = 0;
    std::vector<int> is_modified(aggregation_fields_.size(),
                                 false);  // 用于记录每列的值是否已经修改过
    // 开始遍历每一行处理聚合函数
    while (RC::SUCCESS == (rc = children_[0]->next())) {
      Tuple* tuple = children_[0]->current_tuple();
      if (nullptr == tuple) {
        rc = RC::INTERNAL;
        LOG_WARN("failed to get tuple from operator");
        break;
      }
      Value tmp_value(0);
      for (size_t i = 0; i < aggregation_fields_.size(); i++) {
        switch (aggregation_fields_[i].get_aggr_func_type()) {
          case AggrFuncType::AVG: {
            tuple->cell_at(aggr_field_to_proj_field_map_[i], tmp_value);
            if (tmp_value.attr_type() != AttrType::NULL_ATTR) {
              if (is_modified[i] == 0) {
                values[i].set_value(tmp_value);
                is_modified[i]++;
              } else {
                rc = values[i].add_value(tmp_value);

                if (rc != RC::SUCCESS) {
                  LOG_ERROR("Error occurs when adding values in AVG func.");
                  return rc;
                }
                is_modified[i]++;
              }
            }

          } break;
          case AggrFuncType::SUM: {
            tuple->cell_at(aggr_field_to_proj_field_map_[i], tmp_value);
            if (tmp_value.attr_type() != AttrType::NULL_ATTR) {
              if (is_modified[i] == 0) {
                values[i].set_value(tmp_value);
                is_modified[i]++;
              } else {
                rc = values[i].add_value(tmp_value);
                if (rc != RC::SUCCESS) {
                  LOG_ERROR("Error occurs when adding values in AVG func.");
                  return rc;
                }
                is_modified[i]++;
              }
            }
          } break;
          case AggrFuncType::MAX: {
            tuple->cell_at(aggr_field_to_proj_field_map_[i], tmp_value);
            if (tmp_value.attr_type() != AttrType::NULL_ATTR) {
              if (is_modified[i] == 0) {
                values[i].set_value(tmp_value);
                is_modified[i]++;
              } else {
                if (values[i].compare(tmp_value) < 0) {
                  values[i].set_value(tmp_value);
                }
                is_modified[i]++;
              }
            }

          } break;
          case AggrFuncType::MIN: {
            tuple->cell_at(aggr_field_to_proj_field_map_[i], tmp_value);
            if (tmp_value.attr_type() != AttrType::NULL_ATTR) {
              if (is_modified[i] == 0) {
                values[i].set_value(tmp_value);
                is_modified[i]++;
              } else {
                if (values[i].compare(tmp_value) > 0) {
                  values[i].set_value(tmp_value);
                }
                is_modified[i]++;
              }
            }

          } break;
          case AggrFuncType::CNT: {
            tuple->cell_at(aggr_field_to_proj_field_map_[i], tmp_value);
            if (tmp_value.attr_type() != AttrType::NULL_ATTR) {
              values[i].add_value(Value(1));  // 直接把Value + 1
              is_modified[i]++;
            }
          } break;
          default: {
            tuple->cell_at(aggr_field_to_proj_field_map_[i], tmp_value);
            values[i].set_value(tmp_value);
          } break;
        }
      }
      row_index++;
    }
    if (rc == RC::SELECT_EXPR_INVALID_ARGUMENT) {
      return rc;
    }

    // 处理聚合函数最终结果
    for (size_t i = 0; i < aggregation_fields_.size(); i++) {
      switch (aggregation_fields_[i].get_aggr_func_type()) {
        case AggrFuncType::AVG: {
          if (is_modified[i] == 0) {
            values[i].set_null(nullptr, 4);
          } else {
            values[i].typecast_to(AttrType::FLOATS);
            float tmp = values[i].get_float();
            tmp /= is_modified[i];
            values[i].set_float(tmp);
          }

        } break;
        case AggrFuncType::SUM: {
          // 已经对对应列完成了求和
          if (!is_modified[i]) {
            values[i].set_null(nullptr, 4);
          }
        } break;
        case AggrFuncType::MAX: {
          // 已经是MAX
          if (!is_modified[i]) {
            values[i].set_null(nullptr, 4);
          }

        } break;
        case AggrFuncType::MIN: {
          // 已经是MIN
          if (!is_modified[i]) {
            values[i].set_null(nullptr, 4);
          }
        } break;
        case AggrFuncType::CNT: {
          // 已经对对应列完成了统计
          if (aggregation_fields_[i].get_alias().find_first_of("*") !=
              std::string::npos) {
            // 如果是COUNT(*), 需要返回所有的行数
            values[i].set_int(row_index);
          }
        } break;
        default:
          break;
      }
    }

    this->tuple_.set_cells(values);

    if (rc == RC::RECORD_END_GROUP) return RC::RECORD_EOF;

    // 对having子句做筛选
    bool having_passed = true;
    for (size_t i = 0; i < this->cmp_exprs_.size(); i++) {
      Value value;
      bool is_replaced =
          false;  // having子句中出现count(*)需要在当前的分组中进行替换
      ComparisonExpr* tmp_cmp_expr =
          static_cast<ComparisonExpr*>(cmp_exprs_[i].get());
      ComparisonExpr* new_cmp_expr = tmp_cmp_expr->clone();
      if (tmp_cmp_expr->left_type() == ExprType::FIELD) {
        Field* tmp_field = tmp_cmp_expr->left_field();
        if (tmp_field->get_aggr_func_type() == AggrFuncType::CNT) {
          std::unique_ptr<Expression> new_exp(
              static_cast<Expression*>(new ValueExpr(Value(row_index))));
          new_cmp_expr->set_left_expr(std::move(new_exp));
          is_replaced = true;
        }
      }
      if (tmp_cmp_expr->right_type() == ExprType::FIELD) {
        Field* tmp_field = tmp_cmp_expr->right_field();
        if (tmp_field->get_aggr_func_type() == AggrFuncType::CNT) {
          std::unique_ptr<Expression> new_exp(
              static_cast<Expression*>(new ValueExpr(Value(row_index))));
          new_cmp_expr->set_right_expr(std::move(new_exp));
          is_replaced = true;
        }
      }
      if (is_replaced) {
        rc = new_cmp_expr->get_value(tuple_, value);
      } else {
        rc = cmp_exprs_[i]->get_value(tuple_, value);
      }
      if (rc != RC::SUCCESS) {
        return rc;
      }
      having_passed = having_passed & value.get_boolean();
    }
    if (having_passed) return RC::SUCCESS;
  }

  return RC::SUCCESS;
}

RC AggregationPhysicalOperator::close() {
  if (!children_.empty()) {
    children_[0]->close();
  }
  std::vector<TupleCellSpec*> speces;
  this->tuple_.set_speces(speces);
  return RC::SUCCESS;
}

Tuple* AggregationPhysicalOperator::current_tuple() { return &tuple_; }
