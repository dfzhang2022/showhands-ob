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
// Created by Wangyunlai on 2022/07/05.
//

#pragma once

#include "sql/parser/parse_defs.h"
#include "storage/field/field_meta.h"
#include "storage/table/table.h"

/**
 * @brief 字段
 *
 */
class Field {
 public:
  Field() = default;
  Field(const Table *table, const FieldMeta *field)
      : table_(table), field_(field) {
    // if (table->has_alias()) {
    //   this->set_alias(table->get_alias() + "." + field->name());
    // }
  }
  Field(const Field &) = default;

  const Table *table() const { return table_; }
  const FieldMeta *meta() const { return field_; }

  AttrType attr_type() const { return field_->type(); }

  const char *table_name() const { return table_->name(); }
  const char *field_name() const { return field_->name(); }

  void set_table(const Table *table) { this->table_ = table; }
  void set_field(const FieldMeta *field) { this->field_ = field; }

  void set_int(Record &record, int value);
  int get_int(const Record &record);

  const AggrFuncType get_aggr_func_type() const { return aggr_func_type_; }
  void set_aggr_func_type(AggrFuncType type) { aggr_func_type_ = type; }

  const bool has_alias() const { return has_alias_; }
  void set_has_alias(bool flag) { this->has_alias_ = flag; }
  const std::string get_alias() const { return alias_; }
  void set_alias(std::string in_str) { this->alias_ = in_str; }

  // 若该列是常量值
  const FunctionType get_func_type() const { return func_type_; }
  void set_func_type(FunctionType type) { this->func_type_ = type; }
  const bool is_constant_value() const { return is_constant_value_; }
  void set_is_constant_value(bool flag) { this->is_constant_value_ = flag; }
  const Value get_constant_value() const { return this->constant_value_; }
  void set_constant_value(const Value &value) {
    this->constant_value_.set_value(value);
  }

  const FunctionMetaInfo get_func_info() const { return func_info_; }
  void set_func_info(const FunctionMetaInfo &func_info_in) {
    this->func_info_ = func_info_in;
    return;
  }

  const char *get_data(const Record &record);

 private:
  const Table *table_ = nullptr;
  const FieldMeta *field_ = nullptr;
  AggrFuncType aggr_func_type_ = AggrFuncType::NONE;
  FunctionType func_type_ = FunctionType::NONE_FUNC;
  FunctionMetaInfo func_info_;

  bool has_alias_ = false;
  std::string
      alias_;  // 记录临时需要的别名("目前的一个用法是用作聚合函数输出表头")

  bool is_constant_value_ = false;
  Value constant_value_;
};
