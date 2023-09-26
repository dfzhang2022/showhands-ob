#pragma once

#include <string>
#include <vector>
#include <map>

#include "sql/operator/logical_operator.h"
#include "sql/parser/parse_defs.h"

/**
 * @brief 更新逻辑算子
 * @ingroup LogicalOperator
 */

class UpdateLogicalOperator : public LogicalOperator {
 public:
  UpdateLogicalOperator(Table *table, std::vector<std::string> attribute_names,
                        std::vector<Value> values,std::map<std::string,std::unique_ptr<LogicalOperator>>& col_name_to_select_oper)
      : table_(table), attribute_names_(attribute_names), values_(values) {
      this->col_name_to_select_oper_.swap(col_name_to_select_oper);
      }
        
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
  std::map<std::string,std::unique_ptr<LogicalOperator>> &col_name_to_select_oper(){return col_name_to_select_oper_;};

 private:
  Table *table_ = nullptr;
  Value value_;
  std::string attribute_name_;

  std::vector<Value> values_;
  std::vector<std::string> attribute_names_;
  std::map<std::string,std::unique_ptr<LogicalOperator>> col_name_to_select_oper_;
};
