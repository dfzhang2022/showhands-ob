#pragma once
#include <functional>
#include <set>

#include "sql/operator/physical_operator.h"

/**
 * @brief order by物理算子
 * @ingroup PhysicalOperator
 */

class OrderByPhysicalOperator : public PhysicalOperator {
 public:
  OrderByPhysicalOperator(
      const std::vector<Field> &order_by_fields,
      const std::vector<OrderByDirection> &order_by_directions)
      : order_by_fields_(order_by_fields),
        order_by_directions_(order_by_directions) {}

  OrderByPhysicalOperator(
      std::map<Field *, OrderByDirection> field_direction_map)
      : field_direction_map_(field_direction_map) {}
  virtual ~OrderByPhysicalOperator() = default;

  PhysicalOperatorType type() const override {
    return PhysicalOperatorType::ORDER_BY;
  }

  RC open(Trx *trx) override;
  RC next() override;
  RC close() override;

  Tuple *current_tuple() override;

 private:
  /* data */
  std::vector<Tuple *> tuples_;
  Tuple *tuple_;
  std::vector<Field> order_by_fields_;
  std::vector<OrderByDirection> order_by_directions_;
  std::map<Field *, OrderByDirection> field_direction_map_;
  bool is_dirty_ = false;
  size_t current_index_;
};
