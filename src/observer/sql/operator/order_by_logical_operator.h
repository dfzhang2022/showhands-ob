#pragma once

#include <memory>
#include <vector>

#include "sql/expr/expression.h"
#include "sql/operator/logical_operator.h"
#include "storage/field/field.h"

/**
 * @brief order by 进行排序运算
 * @ingroup LogicalOperator
 * @details 从表中获取数据后，按照指定的列及方向进行排序
 */

class OrderByLogicalOperator : public LogicalOperator {
 public:
  OrderByLogicalOperator(std::vector<Field> fields,
                         std::vector<OrderByDirection> directions) {
    size_t cnt = 0;
    for (; cnt < fields.size(); cnt++) {
      field_direction_map_.insert({&fields[cnt], directions[cnt]});
    }
    this->fields_.swap(fields);
    this->directions_.swap(directions);
  }
  virtual ~OrderByLogicalOperator() = default;

  LogicalOperatorType type() const override {
    return LogicalOperatorType::ORDER_BY;
  }

  const std::map<Field*, OrderByDirection>& field_direction_map() const {
    return field_direction_map_;
  }
  void add_field_direction(Field* field, OrderByDirection direct) {
    this->field_direction_map_.insert({field, direct});
  }
  const std::vector<Field>& fields() const { return fields_; }
  const std::vector<OrderByDirection>& directions() const {
    return directions_;
  }

 private:
  /* data */
  std::map<Field*, OrderByDirection> field_direction_map_;
  std::vector<Field> fields_;
  std::vector<OrderByDirection> directions_;
};
