
#pragma once

#include "sql/operator/physical_operator.h"

/**
 * @brief 聚合函数物理算子
 * @ingroup PhysicalOperator
 */

class AggregationPhysicalOperator : public PhysicalOperator {
 public:
  AggregationPhysicalOperator(/* args */) {}
  virtual ~AggregationPhysicalOperator() = default;

  PhysicalOperatorType type() const override {
    return PhysicalOperatorType::AGGREGATION;
  }

  RC open(Trx *trx) override;
  RC next() override;
  RC close() override;

  int cell_num() const { return tuple_.cell_num(); }

  Tuple *current_tuple() override;

 private:
  ValueListTuple tuple_;
};
