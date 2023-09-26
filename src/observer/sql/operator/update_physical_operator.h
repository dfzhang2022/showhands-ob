#pragma once

#include <string>

#include "sql/operator/physical_operator.h"
#include "sql/parser/parse.h"

class Trx;

class UpdateStmt;

/**
 * @brief 物理算子，更新
 * @ingroup PhysicalOperator
 */

class UpdatePhysicalOperator : public PhysicalOperator {
 public:
  UpdatePhysicalOperator(Table *table, std::vector<std::string> attribute_names,
                         std::vector<Value> values,
                         std::vector<std::string> set_selects_attr_name);
  virtual ~UpdatePhysicalOperator() = default;

  PhysicalOperatorType type() const override {
    return PhysicalOperatorType::UPDATE;
  }

  RC open(Trx *trx) override;
  RC next() override;
  RC close() override;

  Tuple *current_tuple() override { return nullptr; }

  std::vector<std::unique_ptr<PhysicalOperator>> &set_selects_physical_opers() {
    return set_selects_physical_opers_;
  }
  void add_set_selects_physical_oper(std::unique_ptr<PhysicalOperator> oper) {
    set_selects_physical_opers_.emplace_back(std::move(oper));
  }

 private:
  Table *table_ = nullptr;
  std::string attribute_name_;
  std::vector<std::string> attribute_names_;
  Value value_;
  std::vector<Value> values_;

  std::vector<std::string> set_selects_attr_name_;
  std::vector<std::unique_ptr<PhysicalOperator>> set_selects_physical_opers_;

  Trx *trx_ = nullptr;
};