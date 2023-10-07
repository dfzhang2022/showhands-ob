#pragma once
#include <functional>
#include <set>

#include "sql/operator/physical_operator.h"

/**
 * @brief group by物理算子
 * @ingroup PhysicalOperator
 */

class GroupByPhysicalOperator : public PhysicalOperator {
 public:
  GroupByPhysicalOperator(const std::vector<Field> &group_by_fields)
      : group_by_fields_(group_by_fields) {}

  virtual ~GroupByPhysicalOperator() = default;

  PhysicalOperatorType type() const override {
    return PhysicalOperatorType::GROUP_BY;
  }

  RC open(Trx *trx) override;
  RC next() override;
  RC close() override;

  Tuple *current_tuple() override;

 private:
  /* data */
  std::vector<Tuple *> tuples_;
  Tuple *tuple_;
  std::vector<Field> group_by_fields_;
  std::vector<size_t> group_index_;

  bool is_dirty_ = false;
  size_t current_index_;
  size_t current_group_;
};