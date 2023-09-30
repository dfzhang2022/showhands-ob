#pragma once

#include <memory>
#include <vector>

#include "sql/expr/expression.h"
#include "sql/operator/logical_operator.h"
#include "storage/field/field.h"

/**
 * @brief aggregation 进行聚合函数的计算
 * @ingroup LogicalOperator
 * @details 从下层返回的投影结果中按照聚合要求进行计算
 */

class AggregationLogicalOperator : public LogicalOperator

{
 public:
  AggregationLogicalOperator(const std::vector<Field> &aggregation_fields,
                             std::map<int, int> aggr_field_to_proj_field_map)
      : aggregation_fields_(aggregation_fields),
        aggr_field_to_proj_field_map_(aggr_field_to_proj_field_map) {}
  virtual ~AggregationLogicalOperator() = default;
  LogicalOperatorType type() const override {
    return LogicalOperatorType::AGGREGATION;
  }

  std::vector<std::unique_ptr<Expression>> &expressions() {
    return expressions_;
  }
  const std::vector<std::unique_ptr<Expression>> &expressions() const {
    return expressions_;
  }
  const std::vector<Field> &aggregation_fields() const {
    return aggregation_fields_;
  }
  const std::map<int, int> &aggr_field_to_proj_field_map() const {
    return aggr_field_to_proj_field_map_;
  }

 private:
  /* data */
  std::vector<Field> aggregation_fields_;  // 用作记录计算聚合函数之后的表头信息
  std::map<int, int> aggr_field_to_proj_field_map_;
};
