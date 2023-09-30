
#pragma once

#include <map>

#include "sql/operator/physical_operator.h"

/**
 * @brief 聚合函数物理算子
 * @ingroup PhysicalOperator
 */

class AggregationPhysicalOperator : public PhysicalOperator {
 public:
  AggregationPhysicalOperator(std::vector<Field> aggregation_fields,
                              std::map<int, int> aggr_field_to_proj_field_map) {
    this->aggregation_fields_.swap(aggregation_fields);
    this->aggr_field_to_proj_field_map_.swap(aggr_field_to_proj_field_map);
  }
  virtual ~AggregationPhysicalOperator() = default;

  void add_expressions(std::vector<std::unique_ptr<Expression>> &&expressions) {

  }

  PhysicalOperatorType type() const override {
    return PhysicalOperatorType::AGGREGATION;
  }

  void add_aggr_field(Field field) { aggregation_fields_.emplace_back(field); }
  void add_aggr_to_proj_map(int aggr_index, int proj_index) {
    aggr_field_to_proj_field_map_[aggr_index] = proj_index;
  }

  RC open(Trx *trx) override;
  RC next() override;
  RC close() override;

  int cell_num() const { return tuple_.cell_num(); }

  Tuple *current_tuple() override;

 private:
  ValueListTuple tuple_;
  std::vector<Field> aggregation_fields_;  // 聚合函数输出结构
  std::map<int, int>
      aggr_field_to_proj_field_map_;  // 用于记录聚合列指向投影之后的哪一列
  bool is_dirty_ = false;
};
