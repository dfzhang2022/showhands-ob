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
                         std::vector<Value> values,std::map<std::string,std::unique_ptr<PhysicalOperator>>  col_name_to_select_physical_oper);
  virtual ~UpdatePhysicalOperator() = default;

  PhysicalOperatorType type() const override {
    return PhysicalOperatorType::UPDATE;
  }

  RC open(Trx *trx) override;
  RC next() override;
  RC close() override;

  Tuple *current_tuple() override { return nullptr; }

 private:
  Table *table_ = nullptr;
  std::string attribute_name_;
  std::vector<std::string> attribute_names_;
  Value value_;
  std::vector<Value> values_;
  std::map<std::string,std::unique_ptr<PhysicalOperator>>  col_name_to_select_physical_oper_;

  Trx *trx_ = nullptr;
};