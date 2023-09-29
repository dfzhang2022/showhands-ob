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
  AggregationLogicalOperator(const std::vector<Field> &fields);
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

 private:
  /* data */
  std::vector<Field> aggregation_fields_;  // 用作记录计算聚合函数之后的表头信息
};

AggregationLogicalOperator ::AggregationLogicalOperator(
    const std::vector<Field> &aggregation_fields)
    : aggregation_fields_(aggregation_fields) {}
