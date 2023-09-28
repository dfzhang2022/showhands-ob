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
// Created by WangYunlai on 2022/07/01.
//

#include "sql/operator/project_physical_operator.h"

#include "common/log/log.h"
#include "storage/record/record.h"
#include "storage/table/table.h"

RC ProjectPhysicalOperator::open(Trx *trx) {
  if (children_.empty()) {
    return RC::SUCCESS;
  }

  PhysicalOperator *child = children_[0].get();
  RC rc = child->open(trx);
  if (rc != RC::SUCCESS) {
    LOG_WARN("failed to open child operator: %s", strrc(rc));
    return rc;
  }

  return RC::SUCCESS;
}

RC ProjectPhysicalOperator::next() {
  if (is_dirty_) return RC::RECORD_EOF;
  if (aggr_funcs_type_.empty()) {
    if (children_.empty()) {
      return RC::RECORD_EOF;
    }
    return children_[0]->next();
  } else {
    // 存在聚合函数
    RC rc;
    is_dirty_ = true;
    std::vector<Value> values;
    for (size_t i = 0; i < tuple_.cell_num(); i++) {
      values.emplace_back(Value(0));
      // switch (aggr_funcs_type_[i]) {
      //   case AggrFuncType::AVG: {
      //     std::string new_alias = tuple_.cell_alias_at(i);
      //     new_alias = "AVG(" + new_alias + ")";
      //     tuple_.set_cell_alias_at(i, new_alias);
      //   } break;
      //   case AggrFuncType::MAX: {
      //     std::string new_alias = tuple_.cell_alias_at(i);
      //     new_alias = "MAX(" + new_alias + ")";
      //     tuple_.set_cell_alias_at(i, new_alias);

      //   } break;
      //   case AggrFuncType::MIN: {
      //     std::string new_alias = tuple_.cell_alias_at(i);
      //     new_alias = "MIN(" + new_alias + ")";
      //     tuple_.set_cell_alias_at(i, new_alias);

      //   } break;
      //   case AggrFuncType::CNT: {
      //     std::string new_alias = tuple_.cell_alias_at(i);
      //     new_alias = "CNT(" + new_alias + ")";
      //     tuple_.set_cell_alias_at(i, new_alias);
      //   } break;
      //   default:
      //     break;
      // }
    }

    std::set<std::string> count_set;
    int row_index = 0;
    // 开始遍历每一行处理聚合函数
    while (RC::SUCCESS == (rc = children_[0]->next())) {
      Tuple *tuple = children_[0]->current_tuple();
      tuple_.set_tuple(tuple);
      if (nullptr == tuple) {
        rc = RC::INTERNAL;
        LOG_WARN("failed to get tuple from operator");
        break;
      }
      Value tmp_value(0);
      for (size_t i = 0; i < aggr_funcs_type_.size(); i++) {
        switch (aggr_funcs_type_[i]) {
          case AggrFuncType::AVG: {
            tuple_.cell_at(i, tmp_value);
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
            tuple_.cell_at(i, tmp_value);
            if (row_index == 0) {
              values[i].set_value(tmp_value);
            } else {
              if (values[i].compare(tmp_value) < 0) {
                values[i].set_value(tmp_value);
              }
            }
          } break;
          case AggrFuncType::MIN: {
            tuple_.cell_at(i, tmp_value);

            if (row_index == 0) {
              values[i].set_value(tmp_value);
            } else {
              if (values[i].compare(tmp_value) > 0) {
                values[i].set_value(tmp_value);
              }
            }
          } break;
          case AggrFuncType::CNT: {
            // tuple_.cell_at(i, tmp_value);
            // count_set.insert(tmp_value.to_string());
            values[i].add_value(Value(1));  // 直接把Value + 1
          } break;
          default:
            break;
        }
      }
      row_index++;
    }
    // 处理聚合函数最终结果
    for (size_t i = 0; i < aggr_funcs_type_.size(); i++) {
      switch (aggr_funcs_type_[i]) {
        case AggrFuncType::AVG: {
          values[i].typecast_to(AttrType::FLOATS);
          float tmp = values[i].get_float();
          tmp /= row_index;
          values[i].set_float(tmp);

        } break;
        case AggrFuncType::MAX: {
          // 已经是MAX

        } break;
        case AggrFuncType::MIN: {
          // 已经是MIN
        } break;
        case AggrFuncType::CNT: {
          // values[i].set_int(count_set.size());
        } break;
        default:
          break;
      }
    }
    this->aggr_result_.set_cells(values);

    return RC::SUCCESS;
  }
}

RC ProjectPhysicalOperator::close() {
  if (!children_.empty()) {
    children_[0]->close();
  }
  return RC::SUCCESS;
}
Tuple *ProjectPhysicalOperator::current_tuple() {
  if (aggr_funcs_type_.empty()) {
    tuple_.set_tuple(children_[0]->current_tuple());
    return &tuple_;
  } else {
    return &aggr_result_;
  }
}

void ProjectPhysicalOperator::add_projection(const Table *table,
                                             const FieldMeta *field_meta) {
  // 对单表来说，展示的(alias) 字段总是字段名称，
  // 对多表查询来说，展示的alias 需要带表名字
  TupleCellSpec *spec =
      new TupleCellSpec(table->name(), field_meta->name(), field_meta->name());
  tuple_.add_cell_spec(spec);
}
