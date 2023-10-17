#include "sql/operator/group_by_physical_operator.h"

#include "common/log/log.h"
#include "storage/record/record.h"
#include "storage/table/table.h"

RC GroupByPhysicalOperator::open(Trx *trx) {
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

RC GroupByPhysicalOperator::next() {
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

    const std::vector<Field> tmp_fields = group_by_fields_;
    std::vector<OrderByDirection> tmp_directions;
    for (auto i : tmp_fields) {
      tmp_directions.push_back(OrderByDirection::ASC_ORDER);
    }
    if (this->tuples_.size() > 0) {
      // 使用std::function定义一个函数对象，包含两个参数
      std::function<bool(const Tuple *, const Tuple *)> comparatorFunction =
          [tmp_fields, tmp_directions](const Tuple *a, const Tuple *b) {
            return Tuple::compareTuples(a, b, tmp_fields, tmp_directions);
          };

      std::sort(tuples_.begin(), tuples_.end(), comparatorFunction);
      group_index_.push_back(0);
      for (int i = 0; i < tuples_.size() - 1; i++) {
        if (Tuple::compareTuples(tuples_.at(i), tuples_.at(i + 1), tmp_fields,
                                 tmp_directions)) {
          group_index_.push_back(i + 1);
        }
      }
    }

    group_index_.push_back(tuples_.size());
    current_group_ = 0;
    current_index_ = 0;
    is_dirty_ = true;
  }

  if (current_index_ < tuples_.size()) {
    if (current_index_ < group_index_[current_group_ + 1]) {
      tuple_ = tuples_[current_index_];
      current_index_++;
      return RC::SUCCESS;
    } else {
      current_group_++;
      return RC::RECORD_EOF;
    }

  } else if (current_index_ == tuples_.size()) {
    current_index_++;
    return RC::RECORD_EOF;
  } else {
    return RC::RECORD_END_GROUP;
  }
}

RC GroupByPhysicalOperator::close() {
  if (!children_.empty()) {
    children_[0]->close();
  }
  return RC::SUCCESS;
}

Tuple *GroupByPhysicalOperator::current_tuple() { return tuple_; }