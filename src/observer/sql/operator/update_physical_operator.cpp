#include "sql/operator/update_physical_operator.h"

#include "sql/stmt/update_stmt.h"
#include "storage/table/table.h"
#include "storage/trx/trx.h"

using namespace std;

UpdatePhysicalOperator::UpdatePhysicalOperator(
    Table *table, std::vector<std::string> attribute_names,
    std::vector<Value> values, std::vector<std::string> set_selects_attr_name)
    : table_(table),
      attribute_names_(attribute_names),
      values_(values),
      set_selects_attr_name_(std::move(set_selects_attr_name)) {}

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
  if (!set_selects_physical_opers_.empty()) {
    size_t set_select_amount = set_selects_physical_opers_.size();
    for (size_t i = 0; i < set_select_amount; i++) {
      rc = set_selects_physical_opers_[i].get()->open(trx);
      if (rc != RC::SUCCESS) {
        LOG_WARN("failed to open set_select operator: %s", strrc(rc));
        return rc;
      }
    }
  }

  trx_ = trx;

  return RC::SUCCESS;
}

RC UpdatePhysicalOperator::next() {
  RC rc = RC::SUCCESS;
  if (children_.empty()) {
    return RC::RECORD_EOF;
  }
  // 先处理set-select部分
  if (!set_selects_physical_opers_.empty()) {
    size_t set_select_amount = set_selects_physical_opers_.size();
    for (size_t i = 0; i < set_select_amount; i++) {
      std::string attr_name = set_selects_attr_name_[i];
      Value tmp_v;
      while (RC::SUCCESS ==
             (rc = set_selects_physical_opers_[i].get()->next())) {
        Tuple *tuple = set_selects_physical_opers_[i].get()->current_tuple();
        if (nullptr == tuple) {
          LOG_WARN("failed to get current record in processing set-select: %s",
                   strrc(rc));
          return rc;
        }
        RowTuple *row_tuple = static_cast<RowTuple *>(tuple);
        if (row_tuple->cell_num() != 1) {
          // SET name EQ value 只能单值
          rc = RC::INVALID_ARGUMENT;
          LOG_WARN("set-select returns multi-value: %s", strrc(rc));
          return rc;
        }

        rc = row_tuple->cell_at(0, tmp_v);
        if (rc != RC::SUCCESS) {
          LOG_WARN("Get value fault: %s", strrc(rc));
          return rc;
        }
      }

      // 更新set-select中的值
      for (size_t cnt = 0; cnt < attribute_names_.size(); cnt++) {
        if (attribute_names_[cnt] == attr_name) {
          values_[cnt].set_value(tmp_v);
          break;
        }
      }
    }
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
    rc = row_tuple->update_record_by_attr_name(attribute_names_, values_,
                                               new_rec);
    if (rc != RC::SUCCESS) {
      LOG_WARN("No such field:%s,table_name: %s,attr_name:%s", strrc(rc),
               table_->name(), attribute_name_.c_str());
      return rc;
    }
    // new version
    rc = trx_->update_record(table_, old_record, *new_rec);
    if (rc != RC::SUCCESS) {
      delete new_rec;
      LOG_WARN("failed to update record in new version: %s", strrc(rc));
      return rc;
    }

    delete new_rec;

    // new version end

    // update_record_vec.push_back(new_rec);

    // rc = trx_->delete_record(table_, old_record);
    // if (rc != RC::SUCCESS) {
    //   LOG_WARN("failed to delete record in updating record: %s", strrc(rc));
    //   return rc;
    // }
  }

  // for (Record *record_tmp : update_record_vec) {
  //   rc = trx_->insert_record(table_, *record_tmp);
  //   if (rc != RC::SUCCESS) {
  //     LOG_WARN("failed to insert record in updating record. rc=%s",
  //     strrc(rc));
  //   }
  // }

  return RC::RECORD_EOF;
}

RC UpdatePhysicalOperator::close() {
  if (!children_.empty()) {
    children_[0]->close();
  }
  return RC::SUCCESS;
}