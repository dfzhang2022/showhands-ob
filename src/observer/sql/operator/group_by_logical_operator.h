#pragma once

#include <memory>
#include <vector>

#include "sql/expr/expression.h"
#include "sql/operator/logical_operator.h"
#include "storage/field/field.h"

/**
 * @brief group by 进行分组运算
 * @ingroup LogicalOperator
 * @details 从表中获取数据后，按照指定的列进行分组
 */

class GroupByLogicalOperator : public LogicalOperator {
 public:
  GroupByLogicalOperator(std::vector<Field> fields) {
    this->fields_.swap(fields);
  }
  virtual ~GroupByLogicalOperator() = default;

  LogicalOperatorType type() const override {
    return LogicalOperatorType::GROUP_BY;
  }

  const std::vector<Field>& fields() const { return fields_; }

 private:
  /* data */
  std::vector<Field> fields_;
};