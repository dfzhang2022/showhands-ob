#include "sql/operator/order_by_physical_operator.h"

#include "common/log/log.h"
#include "storage/record/record.h"
#include "storage/table/table.h"

RC OrderByPhysicalOperator::open(Trx *trx) {
  if (children_.empty()) {
    return RC::SUCCESS;
  }

  PhysicalOperator *child = children_[0].get();
  RC rc = child->open(trx);
  if (rc != RC::SUCCESS) {
    LOG_WARN("failed to open child operator: %s", strrc(rc));
    return rc;
  }

  return RC::SUCCESS;
}

RC OrderByPhysicalOperator::next() {
  if (children_.empty()) {
    return RC::RECORD_EOF;
  }
  RC rc = RC::SUCCESS;
  if (!is_dirty_) {
    while (RC::SUCCESS == (rc = children_[0]->next())) {
      Tuple *tuple = children_[0]->current_tuple();
      if (nullptr == tuple) {
        rc = RC::INTERNAL;
        LOG_WARN("failed to get tuple from operator");
        break;
      }
      Tuple *tmp_tuple = tuple->clone();
      this->tuples_.push_back(tmp_tuple);
    }
    LOG_INFO("tuples_ size is %d", this->tuples_.size());

    const std::vector<Field> tmp_fields = order_by_fields_;
    std::vector<OrderByDirection> tmp_directions = order_by_directions_;
    // 使用std::function定义一个函数对象，包含两个参数
    std::function<bool(const Tuple *, const Tuple *)> comparatorFunction =
        [tmp_fields, tmp_directions](const Tuple *a, const Tuple *b) {
          return Tuple::compareTuples(a, b, tmp_fields, tmp_directions);
        };

    std::sort(tuples_.begin(), tuples_.end(), comparatorFunction);

    current_index_ = 0;
    is_dirty_ = true;
  }

  if (current_index_ < tuples_.size()) {
    tuple_ = tuples_[current_index_];
    current_index_++;
    return RC::SUCCESS;
  } else {
    return RC::RECORD_EOF;
  }
}

RC OrderByPhysicalOperator::close() {
  if (!children_.empty()) {
    children_[0]->close();
  }
  return RC::SUCCESS;
}

Tuple *OrderByPhysicalOperator::current_tuple() { return tuple_; }
