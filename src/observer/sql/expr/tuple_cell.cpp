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
// Created by WangYunlai on 2022/07/05.
//

#include "sql/expr/tuple_cell.h"

#include <sstream>

#include "common/lang/comparator.h"
#include "common/lang/string.h"
#include "common/log/log.h"
#include "storage/field/field.h"

TupleCellSpec::TupleCellSpec(const char *table_name, const char *field_name,
                             const char *alias) {
  if (table_name) {
    table_name_ = table_name;
  }
  if (field_name) {
    field_name_ = field_name;
  }
  if (alias) {
    alias_ = alias;
  } else {
    if (table_name_.empty()) {
      alias_ = field_name_;
    } else {
      alias_ = table_name_ + "." + field_name_;
    }
  }
}

TupleCellSpec::TupleCellSpec(const char *alias) {
  if (alias) {
    alias_ = alias;
  }
}
TupleCellSpec::TupleCellSpec(const Field *field) {
  const char *table_name = field->table()->name();
  const char *field_name = field->field_name();
  const char *alias;
  if (field->has_alias()) {
    alias = field->get_alias().c_str();
  } else {
    alias = nullptr;
  }
  if (table_name) {
    table_name_ = table_name;
  }
  if (field_name) {
    field_name_ = field_name;
  }
  if (alias) {
    alias_ = alias;
  } else {
    if (table_name_.empty()) {
      alias_ = field_name_;
    } else {
      alias_ = table_name_ + "." + field_name_;
    }
  }

  this->function_info_ = field->get_func_info();
  this->type_ = field->get_func_type();

  if (field->is_constant_value()) {
    this->set_is_constant_value(true);
    this->set_constant_value(field->get_constant_value());
  }
}

TupleCellSpec *TupleCellSpec::clone() {
  TupleCellSpec *ret_spec =
      new TupleCellSpec(this->table_name(), this->field_name(), this->alias());
  ret_spec->set_func_type(this->get_func_type());
  ret_spec->set_func_info(this->get_func_info());
  if (this->is_constant_value()) {
    ret_spec->set_is_constant_value(true);
    ret_spec->set_constant_value(this->get_constant_value());
  }
  return ret_spec;
}
