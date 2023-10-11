/* Copyright (c) 2021 OceanBase and/or its affiliates. All rights reserved.
miniob is licensed under Mulan PSL v2.
You can use this software according to the terms and conditions of the Mulan PSL
v2. You may obtain a copy of Mulan PSL v2 at:
         http://license.coscl.org.cn/MulanPSL2
THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
See the Mulan PSL v2 for more details. */

//
// Created by Wangyunlai on 2021/5/14.
//

#pragma once

#include <cstring>
#include <memory>
#include <string>
#include <vector>

#include "common/log/log.h"
#include "sql/expr/expression.h"
#include "sql/expr/tuple_cell.h"
#include "sql/parser/parse.h"
#include "sql/parser/value.h"
#include "storage/record/record.h"

class Table;

/**
 * @defgroup Tuple
 * @brief Tuple 元组，表示一行数据，当前返回客户端时使用
 * @details
 * tuple是一种可以嵌套的数据结构。
 * 比如select t1.a+t2.b from t1, t2;
 * 需要使用下面的结构表示：
 * @code {.cpp}
 *  Project(t1.a+t2.b)
 *        |
 *      Joined
 *      /     \
 *   Row(t1) Row(t2)
 * @endcode
 *
 */

/**
 * @brief 元组的结构，包含哪些字段(这里成为Cell)，每个字段的说明
 * @ingroup Tuple
 */
class TupleSchema {
 public:
  void append_cell(const TupleCellSpec &cell) { cells_.push_back(cell); }
  void append_cell(const char *table, const char *field) {
    append_cell(TupleCellSpec(table, field));
  }
  void append_cell(const char *alias) { append_cell(TupleCellSpec(alias)); }
  int cell_num() const { return static_cast<int>(cells_.size()); }
  const TupleCellSpec &cell_at(int i) const { return cells_[i]; }

 private:
  std::vector<TupleCellSpec> cells_;
};

/**
 * @brief 元组的抽象描述
 * @ingroup Tuple
 */
class Tuple {
 public:
  Tuple() = default;
  virtual ~Tuple() = default;

  // Copy Constructor
  Tuple(const Tuple &other) = default;

  virtual Tuple *clone() = 0;

  /**
   * @brief 获取元组中的Cell的个数
   * @details 个数应该与tuple_schema一致
   */
  virtual int cell_num() const = 0;

  /**
   * @brief 获取指定位置的Cell
   *
   * @param index 位置
   * @param[out] cell  返回的Cell
   */
  virtual RC cell_at(int index, Value &cell) const = 0;

  /**
   * @brief 根据cell的描述，获取cell的值
   *
   * @param spec cell的描述
   * @param[out] cell 返回的cell
   */
  virtual RC find_cell(const TupleCellSpec &spec, Value &cell) const = 0;

  virtual std::string to_string() const {
    std::string str;
    const int cell_num = this->cell_num();
    for (int i = 0; i < cell_num - 1; i++) {
      Value cell;
      cell_at(i, cell);
      str += cell.to_string();
      str += ", ";
    }

    if (cell_num > 0) {
      Value cell;
      cell_at(cell_num - 1, cell);
      str += cell.to_string();
    }
    return str;
  }
  static bool compareTuples(const Tuple *a, const Tuple *b, const Field *field,
                            OrderByDirection direction) {
    // Function implementation here
    Value tmp_v1, tmp_v2;
    a->find_cell(TupleCellSpec(field->table_name(), field->field_name()),
                 tmp_v1);
    b->find_cell(TupleCellSpec(field->table_name(), field->field_name()),
                 tmp_v2);
    if (direction == OrderByDirection::ASC_ORDER) {
      return tmp_v1.compare(tmp_v2) < 0;
    } else {
      return tmp_v2.compare(tmp_v1) < 0;
    }
  }

  static bool compareTuples(const Tuple *a, const Tuple *b,
                            const std::vector<Field> fields,
                            std::vector<OrderByDirection> directions) {
    // Function implementation here
    Value tmp_v1, tmp_v2;
    int tmp_result = 0;
    for (size_t i = 0; i < fields.size(); i++) {
      a->find_cell(
          TupleCellSpec(fields[i].table_name(), fields[i].field_name()),
          tmp_v1);
      b->find_cell(
          TupleCellSpec(fields[i].table_name(), fields[i].field_name()),
          tmp_v2);
      tmp_result = tmp_v1.compare(tmp_v2);
      if (tmp_result == 0) {
        continue;
      } else {
        if (directions[i] == OrderByDirection::ASC_ORDER) {
          return tmp_result < 0;
        } else {
          return tmp_result > 0;
        }
      }
    }
    return false;
  }
};

/**
 * @brief 一行数据的元组
 * @ingroup Tuple
 * @details 直接就是获取表中的一条记录
 */
class RowTuple : public Tuple {
 public:
  RowTuple() = default;
  virtual ~RowTuple() {
    for (FieldExpr *spec : speces_) {
      delete spec;
    }
    speces_.clear();
  }
  // Copy Constructor
  RowTuple(const RowTuple &other) {
    // rowSpecificProperty = other.rowSpecificProperty;
    // Record *record_ = new Record(*other.record_);

    // this->set_record((Record *)&other.record());
    this->table_ = new Table(*other.table_);
    char *tmp_data = (char *)malloc(table_->table_meta().record_size());
    memcpy(tmp_data, other.record().data(), table_->table_meta().record_size());
    this->record_ = new Record();
    this->record_->set_data(tmp_data, table_->table_meta().record_size());
    for (auto iter : other.speces_) {
      this->speces_.push_back(new FieldExpr(*iter));
    }
  }
  RowTuple *clone() override { return new RowTuple(*this); }

  void set_record(Record *record) { this->record_ = record; }

  void set_schema(const Table *table, const std::vector<FieldMeta> *fields) {
    table_ = table;
    this->speces_.reserve(fields->size());
    for (const FieldMeta &field : *fields) {
      speces_.push_back(new FieldExpr(table, &field));
    }
  }

  int cell_num() const override { return speces_.size(); }

  RC cell_at(int index, Value &cell) const override {
    if (index < 0 || index >= static_cast<int>(speces_.size())) {
      LOG_WARN("invalid argument. index=%d", index);
      return RC::INVALID_ARGUMENT;
    }

    FieldExpr *field_expr = speces_[index];
    const FieldMeta *field_meta = field_expr->field().meta();
    cell.set_type(field_meta->type());
    cell.set_data(this->record_->data() + field_meta->offset(),
                  field_meta->len());

    // 判断是否为null值
    const FieldMeta *null_field_meta =
        table_->table_meta().field("null_bitmap");
    Value null_bitmap;
    null_bitmap.set_type(AttrType::INTS);
    null_bitmap.set_data(this->record_->data() + null_field_meta->offset(),
                         null_field_meta->len());
    if (index > 0) {
      if (null_bitmap.get_int() & (1 << (index - 1))) {
        cell.set_null(nullptr, 4);
      }
    }
    return RC::SUCCESS;
  }

  RC update_record_by_attr_name(std::string attribute_name, Value value,
                                Record *&new_record) {
    RC rc = RC::SCHEMA_FIELD_NOT_EXIST;
    // LOG_INFO("attribute_name is %s", attribute_name.c_str());
    // LOG_INFO("Value is :%d", value.get_int());
    for (int cnt = 0; cnt < speces_.size(); cnt++) {
      FieldExpr *field_expr = speces_[cnt];
      const FieldMeta *field_meta = field_expr->field().meta();
      // LOG_INFO("field_name is %s", field_meta->name());
      if (0 == std::strcmp(field_meta->name(), attribute_name.c_str())) {
        if (field_meta->type() != value.attr_type()) {
          break;
        }
        // char *new_rec_data =
        //     (char *)malloc(this->record_->len());  // 申请新的内存空间
        // std::memcpy(
        //     new_rec_data, this->record_->data(),
        //     this->record_->len());  // 将旧有的数据地址复制到新的record中
        // LOG_INFO("field_meta->offset() is %d", field_meta->offset());
        // LOG_INFO("field_meta->len() is %d", field_meta->len());
        std::memcpy(new_record->data() + field_meta->offset(), value.data(),
                    value.length());  // 将旧有的数据地址复制到新的record中
        // new_record->set_data_owner(new_rec_data, this->record_->len());
        rc = RC::SUCCESS;
      }
    }
    return rc;
  }

  RC update_record_by_attr_name(std::vector<std::string> attr_name_vec,
                                std::vector<Value> value_vec,
                                Record *&new_record) {
    RC rc = RC::SCHEMA_FIELD_NOT_EXIST;
    if (attr_name_vec.size() != value_vec.size()) {
      rc = RC::INVALID_ARGUMENT;
      LOG_ERROR("attr_num not equal to value_num.");
    }

    for (size_t i = 0; i < attr_name_vec.size(); i++) {
      for (int cnt = 0; cnt < speces_.size(); cnt++) {
        FieldExpr *field_expr = speces_[cnt];
        const FieldMeta *field_meta = field_expr->field().meta();
        // LOG_INFO("field_name is %s", field_meta->name());
        if (0 == std::strcmp(field_meta->name(), attr_name_vec.at(i).c_str())) {
          if (value_vec.at(i).attr_type() == NULL_ATTR) {
            if (field_meta->nullable()) {
              value_vec.at(i).set_null(nullptr, 4);
              // 判断是否为null值
              const FieldMeta *null_field_meta =
                  table_->table_meta().field("null_bitmap");
              Value null_bitmap;
              null_bitmap.set_type(AttrType::INTS);
              null_bitmap.set_data(
                  this->record_->data() + null_field_meta->offset(),
                  null_field_meta->len());
              int bitmap = null_bitmap.get_int();
              bitmap = bitmap | (1 << cnt);
              null_bitmap.set_int(bitmap);

            } else {
              return RC::NULL_VALUE_ERROR;
            }
          } else if (field_meta->type() != value_vec.at(i).attr_type()) {
            break;
          }
          std::memcpy(
              new_record->data() + field_meta->offset(), value_vec.at(i).data(),
              value_vec.at(i).length());  // 将旧有的数据地址复制到新的record中

          rc = RC::SUCCESS;
        }
      }
    }
    return rc;
  }

  RC find_cell(const TupleCellSpec &spec, Value &cell) const override {
    const char *table_name = spec.table_name();
    const char *field_name = spec.field_name();
    if (0 != strcmp(table_name, table_->name())) {
      return RC::NOTFOUND;
    }

    for (size_t i = 0; i < speces_.size(); ++i) {
      const FieldExpr *field_expr = speces_[i];
      const Field &field = field_expr->field();
      if (0 == strcmp(field_name, field.field_name())) {
        RC rc = cell_at(i, cell);
        if (spec.get_func_type() == FunctionType::LENGTH_FUNC &&
            cell.attr_type() == AttrType::CHARS) {
          std::string tmp_str = cell.get_string();
          cell.set_int(tmp_str.length());
        } else if (spec.get_func_type() == FunctionType::ROUND_FUNC &&
                   cell.attr_type() == AttrType::FLOATS) {
          int round_pos = spec.get_func_info().round_type;
          float tmp_float = customRound(cell.get_float(), round_pos);
          cell.set_float(tmp_float);
        }

        return rc;
      }
    }
    return RC::NOTFOUND;
  }

#if 0
  RC cell_spec_at(int index, const TupleCellSpec *&spec) const override
  {
    if (index < 0 || index >= static_cast<int>(speces_.size())) {
      LOG_WARN("invalid argument. index=%d", index);
      return RC::INVALID_ARGUMENT;
    }
    spec = speces_[index];
    return RC::SUCCESS;
  }
#endif

  Record &record() { return *record_; }

  const Record &record() const { return *record_; }

 private:
  Record *record_ = nullptr;
  const Table *table_ = nullptr;
  std::vector<FieldExpr *> speces_;
};

/**
 * @brief 从一行数据中，选择部分字段组成的元组，也就是投影操作
 * @ingroup Tuple
 * @details 一般在select语句中使用。
 * 投影也可以是很复杂的操作，比如某些字段需要做类型转换、重命名、表达式运算、函数计算等。
 * 当前的实现是比较简单的，只是选择部分字段，不做任何其他操作。
 */
class ProjectTuple : public Tuple {
 public:
  ProjectTuple() = default;
  virtual ~ProjectTuple() {
    for (TupleCellSpec *spec : speces_) {
      delete spec;
    }
    speces_.clear();
  }
  // Copy Constructor
  ProjectTuple(const ProjectTuple &other) : Tuple(other) {
    // rowSpecificProperty = other.rowSpecificProperty;
    this->tuple_ = new RowTuple(*(static_cast<RowTuple *>(other.tuple_)));

    for (auto iter : other.speces_) {
      this->speces_.push_back(new TupleCellSpec(*iter));
    }
  }
  ProjectTuple *clone() override {
    ProjectTuple *ret_tuple = new ProjectTuple();
    ret_tuple->tuple_ = this->tuple_->clone();  // TODO
    for (auto iter : this->speces_) {
      ret_tuple->speces_.push_back(new TupleCellSpec(*iter));
    }
    return ret_tuple;
  }

  void set_tuple(Tuple *tuple) { this->tuple_ = tuple; }

  void set_cell_alias_at(int index, std::string new_name) {
    speces_[index]->set_alias(new_name);
  }
  std::string cell_alias_at(int index) { return speces_[index]->alias(); }

  void add_cell_spec(TupleCellSpec *spec) { speces_.push_back(spec); }
  int cell_num() const override { return speces_.size(); }

  RC cell_at(int index, Value &cell) const override {
    if (index < 0 || index >= static_cast<int>(speces_.size())) {
      return RC::INTERNAL;
    }
    if (tuple_ == nullptr) {
      return RC::INTERNAL;
    }

    const TupleCellSpec *spec = speces_[index];
    if (spec->is_constant_value()) {
      cell.set_value(spec->get_constant_value());
      return RC::SUCCESS;
    } else {
      return tuple_->find_cell(*spec, cell);
    }
  }

  RC find_cell(const TupleCellSpec &spec, Value &cell) const override {
    if (spec.is_constant_value()) {
      cell.set_value(spec.get_constant_value());
      return RC::SUCCESS;
    } else {
      return tuple_->find_cell(spec, cell);
    }
  }

#if 0
  RC cell_spec_at(int index, const TupleCellSpec *&spec) const override
  {
    if (index < 0 || index >= static_cast<int>(speces_.size())) {
      return RC::NOTFOUND;
    }
    spec = speces_[index];
    return RC::SUCCESS;
  }
#endif
 private:
  std::vector<TupleCellSpec *> speces_;
  Tuple *tuple_ = nullptr;
};

class ExpressionTuple : public Tuple {
 public:
  ExpressionTuple(std::vector<std::unique_ptr<Expression>> &expressions)
      : expressions_(expressions) {}

  virtual ~ExpressionTuple() {}
  ExpressionTuple *clone() override {
    // TODO
    return nullptr;
  }

  int cell_num() const override { return expressions_.size(); }

  RC cell_at(int index, Value &cell) const override {
    if (index < 0 || index >= static_cast<int>(expressions_.size())) {
      return RC::INTERNAL;
    }

    const Expression *expr = expressions_[index].get();
    return expr->try_get_value(cell);
  }

  RC find_cell(const TupleCellSpec &spec, Value &cell) const override {
    for (const std::unique_ptr<Expression> &expr : expressions_) {
      if (0 == strcmp(spec.alias(), expr->name().c_str())) {
        return expr->try_get_value(cell);
      }
    }
    return RC::NOTFOUND;
  }

 private:
  const std::vector<std::unique_ptr<Expression>> &expressions_;
};

/**
 * @brief 一些常量值组成的Tuple
 * @ingroup Tuple
 */
class ValueListTuple : public Tuple {
 public:
  ValueListTuple() = default;
  virtual ~ValueListTuple() {
    for (TupleCellSpec *spec : speces_) {
      delete spec;
    }
    speces_.clear();
  }
  ValueListTuple *clone() override {
    // TODO
    return nullptr;
  }

  void set_cells(const std::vector<Value> &cells) { cells_ = cells; }
  void set_speces(const std::vector<TupleCellSpec *> &speces) {
    speces_ = speces;
  }

  virtual int cell_num() const override {
    return static_cast<int>(cells_.size());
  }

  virtual RC cell_at(int index, Value &cell) const override {
    if (index < 0 || index >= cell_num()) {
      return RC::NOTFOUND;
    }

    cell = cells_[index];
    return RC::SUCCESS;
  }

  virtual RC find_cell(const TupleCellSpec &spec, Value &cell) const override {
    for (size_t i = 0; i < speces_.size(); i++) {
      if (speces_.at(i)->compareTo(spec)) {
        return cell_at(i, cell);
      }
    }
    return RC::NOTFOUND;
  }

 private:
  std::vector<TupleCellSpec *> speces_;
  std::vector<Value> cells_;
};

/**
 * @brief 将两个tuple合并为一个tuple
 * @ingroup Tuple
 * @details 在join算子中使用
 */
class JoinedTuple : public Tuple {
 public:
  JoinedTuple() = default;
  virtual ~JoinedTuple() = default;
  JoinedTuple *clone() override {
    // TODO
    JoinedTuple *ret_tuple = new JoinedTuple();
    ret_tuple->set_left(this->left_->clone());
    ret_tuple->set_right(this->right_->clone());
    return ret_tuple;
  }

  void set_left(Tuple *left) { left_ = left; }
  void set_right(Tuple *right) { right_ = right; }

  int cell_num() const override {
    return left_->cell_num() + right_->cell_num();
  }

  RC cell_at(int index, Value &value) const override {
    const int left_cell_num = left_->cell_num();
    if (index > 0 && index < left_cell_num) {
      return left_->cell_at(index, value);
    }

    if (index >= left_cell_num && index < left_cell_num + right_->cell_num()) {
      return right_->cell_at(index - left_cell_num, value);
    }

    return RC::NOTFOUND;
  }

  RC find_cell(const TupleCellSpec &spec, Value &value) const override {
    RC rc = left_->find_cell(spec, value);
    if (rc == RC::SUCCESS || rc != RC::NOTFOUND) {
      return rc;
    }

    return right_->find_cell(spec, value);
  }

 private:
  Tuple *left_ = nullptr;
  Tuple *right_ = nullptr;
};
