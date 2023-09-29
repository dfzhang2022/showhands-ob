#include "sql/operator/aggregation_physical_operator.h"

#include "common/log/log.h"
#include "storage/record/record.h"
#include "storage/table/table.h"

RC AggregationPhysicalOperator::open(Trx* trx) {
  if (children_.empty()) {
    return RC::SUCCESS;
  }
  PhysicalOperator* child = children_[0].get();
  RC rc = child->open(trx);
  if (rc != RC::SUCCESS) {
    LOG_WARN("failed to open child operator: %s", strrc(rc));
    return rc;
  }

  return RC::SUCCESS;
}

RC AggregationPhysicalOperator::next() {
  if (children_.empty()) {
    return RC::RECORD_EOF;
  }
  return children_[0]->next();
}

RC AggregationPhysicalOperator::close() {
  if (!children_.empty()) {
    children_[0]->close();
  }
  return RC::SUCCESS;
}

Tuple* AggregationPhysicalOperator::current_tuple() { return &tuple_; }

