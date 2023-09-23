#include "sql/operator/update_physical_operator.h"

#include "sql/stmt/update_stmt.h"
#include "storage/table/table.h"
#include "storage/trx/trx.h"

using namespace std;

UpdatePhysicalOperator::UpdatePhysicalOperator(Table *table,
                                               std::string attribute_name,
                                               Value value)
    : table_(table), attribute_name_(attribute_name), value_(value) {}

RC UpdatePhysicalOperator::open(Trx *trx) {
  if (children_.empty()) {
    return RC::SUCCESS;
  }
  std::unique_ptr<PhysicalOperator> &child = children_[0];
  RC rc = child->open(trx);
  if (rc != RC::SUCCESS) {
    LOG_WARN("failed to open child operator: %s", strrc(rc));
    return rc;
  }

  trx_ = trx;

  return RC::SUCCESS;
}

RC UpdatePhysicalOperator::next() {
  RC rc = RC::SUCCESS;
  if (children_.empty()) {
    return RC::RECORD_EOF;
  }
  PhysicalOperator *child = children_[0].get();
  std::vector<Record *> update_record_vec;
  while (RC::SUCCESS == (rc = child->next())) {
    Tuple *tuple = child->current_tuple();
    if (nullptr == tuple) {
      LOG_WARN("failed to get current record in updating record: %s",
               strrc(rc));
      return rc;
    }

    RowTuple *row_tuple = static_cast<RowTuple *>(tuple);
    Record &old_record = row_tuple->record();
    Record *new_rec = new Record(old_record);
    rc =
        row_tuple->update_record_by_attr_name(attribute_name_, value_, new_rec);
    if (rc != RC::SUCCESS) {
      LOG_WARN("No such field:%s,table_name: %s,attr_name:%s", strrc(rc),
               table_->name(), attribute_name_.c_str());
      return rc;
    }
    update_record_vec.push_back(new_rec);

    rc = trx_->delete_record(table_, old_record);
    if (rc != RC::SUCCESS) {
      LOG_WARN("failed to delete record in updating record: %s", strrc(rc));
      return rc;
    }
  }

  for (Record *record_tmp : update_record_vec) {
    rc = trx_->insert_record(table_, *record_tmp);
    if (rc != RC::SUCCESS) {
      LOG_WARN("failed to insert record in updating record. rc=%s", strrc(rc));
    }
  }

  return RC::RECORD_EOF;
}

RC UpdatePhysicalOperator::close() {
  if (!children_.empty()) {
    children_[0]->close();
  }
  return RC::SUCCESS;
}