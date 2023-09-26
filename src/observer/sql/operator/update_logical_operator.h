#pragma once

#include <map>
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
  UpdateLogicalOperator(Table *table, std::vector<std::string> attribute_names,
                        std::vector<Value> values,
                        std::vector<std::string> set_selects_attr_name)
      : table_(table),
        attribute_names_(attribute_names),
        values_(values),
        set_selects_attr_name_(set_selects_attr_name) {
    // this->set_selects_attr_name_.swap(set_selects_attr_name);
    // this->set_selects_logical_opers_.swap(set_selects_logical_opers);
  }
  // UpdateLogicalOperator(const UpdateLogicalOperator &other) {
  //   // 复制 set_selects_logical_opers_ 中的元素到新对象
  //   for (const auto &ptr : other.set_selects_logical_opers_) {
  //     set_selects_logical_opers_.emplace_back(
  //         std::make_unique<LogicalOperator>(*ptr));
  //   }
  //   this->set_selects_attr_name_ = other.set_selects_attr_name_;
  //   this->attribute_name_ = other.attribute_name_;
  //   this->table_ = other.table_;
  //   this->value_ = other.value_;
  // }

  virtual ~UpdateLogicalOperator() = default;
  LogicalOperatorType type() const override {
    return LogicalOperatorType::UPDATE;
  }
  Table *table() const { return table_; }
  //   const Value &value() const { return value; }
  std::vector<Value> &values() { return values_; }

  //   const std::string attribute_name() const { return attribute_name_; }
  std::string attribute_name() { return attribute_name_; }
  std::vector<std::string> attribute_names() { return attribute_names_; }

  std::vector<std::string> &set_selects_attr_name() {
    return set_selects_attr_name_;
  };

  std::vector<std::unique_ptr<LogicalOperator>> &set_selects_logical_opers() {
    return set_selects_logical_opers_;
  }
  void add_set_selects_oper(std::unique_ptr<LogicalOperator> oper) {
    set_selects_logical_opers_.emplace_back(std::move(oper));
  }

 private:
  Table *table_ = nullptr;
  Value value_;
  std::string attribute_name_;

  std::vector<Value> values_;
  std::vector<std::string> attribute_names_;

  std::vector<std::string> set_selects_attr_name_;
  std::vector<std::unique_ptr<LogicalOperator>> set_selects_logical_opers_;
};
