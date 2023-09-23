#pragma once

#include <string>
#include <vector>

#include "sql/operator/logical_operator.h"
#include "sql/parser/parse_defs.h"

/**
 * @brief 更新逻辑算子
 * @ingroup LogicalOperator
 */

class UpdateLogicalOperator : public LogicalOperator {
 public:
  UpdateLogicalOperator(Table *table, std::string attribute_name, Value value)
      : table_(table), attribute_name_(attribute_name), value_(value) {}
  virtual ~UpdateLogicalOperator() = default;
  LogicalOperatorType type() const override {
    return LogicalOperatorType::UPDATE;
  }
  Table *table() const { return table_; }
  //   const Value &value() const { return value; }
  Value &value() { return value_; }

  //   const std::string attribute_name() const { return attribute_name_; }
  std::string attribute_name() { return attribute_name_; }

 private:
  Table *table_ = nullptr;
  Value value_;
  std::string attribute_name_;
};