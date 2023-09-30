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

  return RC::SUCCESS;
}

RC AggregationPhysicalOperator::next() {
  if (is_dirty_) return RC::RECORD_EOF;
  if (children_.empty()) {
    return RC::RECORD_EOF;
  }
  RC rc;
  is_dirty_ = true;
  std::vector<Value> values;
  for (size_t i = 0; i < aggregation_fields_.size(); i++) {
    values.emplace_back(Value(0));
  }

  int row_index = 0;
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
          if (row_index == 0) {
            values[i].set_value(tmp_value);
          } else {
            rc = values[i].add_value(tmp_value);
            if (rc != RC::SUCCESS) {
              LOG_ERROR("Error occurs when adding values in AVG func.");
              return rc;
            }
          }
        } break;
        case AggrFuncType::SUM: {
          tuple->cell_at(aggr_field_to_proj_field_map_[i], tmp_value);
          if (row_index == 0) {
            values[i].set_value(tmp_value);
          } else {
            rc = values[i].add_value(tmp_value);
            if (rc != RC::SUCCESS) {
              LOG_ERROR("Error occurs when adding values in AVG func.");
              return rc;
            }
          }
        } break;
        case AggrFuncType::MAX: {
          tuple->cell_at(aggr_field_to_proj_field_map_[i], tmp_value);
          if (row_index == 0) {
            values[i].set_value(tmp_value);
          } else {
            if (values[i].compare(tmp_value) < 0) {
              values[i].set_value(tmp_value);
            }
          }
        } break;
        case AggrFuncType::MIN: {
          tuple->cell_at(aggr_field_to_proj_field_map_[i], tmp_value);

          if (row_index == 0) {
            values[i].set_value(tmp_value);
          } else {
            if (values[i].compare(tmp_value) > 0) {
              values[i].set_value(tmp_value);
            }
          }
        } break;
        case AggrFuncType::CNT: {
          values[i].add_value(Value(1));  // 直接把Value + 1
        } break;
        default:
          break;
      }
    }
    row_index++;
  }
  // 处理聚合函数最终结果
  for (size_t i = 0; i < aggregation_fields_.size(); i++) {
    switch (aggregation_fields_[i].get_aggr_func_type()) {
      case AggrFuncType::AVG: {
        values[i].typecast_to(AttrType::FLOATS);
        float tmp = values[i].get_float();
        tmp /= row_index;
        values[i].set_float(tmp);

      } break;
      case AggrFuncType::SUM: {
        // 已经对对应列完成了求和
      } break;
      case AggrFuncType::MAX: {
        // 已经是MAX

      } break;
      case AggrFuncType::MIN: {
        // 已经是MIN
      } break;
      case AggrFuncType::CNT: {
        // 已经对对应列完成了统计
        // values[i].set_int(count_set.size());
      } break;
      default:
        break;
    }
  }
  this->tuple_.set_cells(values);
  return RC::SUCCESS;
}

RC AggregationPhysicalOperator::close() {
  if (!children_.empty()) {
    children_[0]->close();
  }
  return RC::SUCCESS;
}

Tuple* AggregationPhysicalOperator::current_tuple() { return &tuple_; }
