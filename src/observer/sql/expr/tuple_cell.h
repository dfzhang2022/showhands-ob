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
// Created by WangYunlai on 2022/6/7.
//

#pragma once

#include <string.h>

#include <iostream>

#include "storage/field/field.h"
#include "storage/field/field_meta.h"
#include "storage/table/table.h"

class TupleCellSpec {
 public:
  TupleCellSpec(const char *table_name, const char *field_name,
                const char *alias = nullptr);
  TupleCellSpec(const char *alias);
  TupleCellSpec(const Field *field);

  TupleCellSpec *clone();

  const char *table_name() const { return table_name_.c_str(); }
  const char *field_name() const { return field_name_.c_str(); }
  const char *alias() const { return alias_.c_str(); }

  void set_alias(std::string new_alias) { this->alias_ = new_alias; }

  bool compareTo(const TupleCellSpec &other) {
    const char *other_alias = other.alias();
    if (0 == strcmp(other_alias, this->alias())) {
      return true;
    } else {
      const char *other_table_name = other.table_name();
      const char *other_field_name = other.field_name();

      if (0 == strcmp(other_table_name, this->table_name()) &&
          0 == strcmp(other_field_name, this->field_name())) {
        return true;
      }
    }
    return false;
  }

  const FunctionType get_func_type() const { return this->type_; }
  void set_func_type(FunctionType type_in) { this->type_ = type_in; }

  const FunctionMetaInfo get_func_info() const { return function_info_; }
  void set_func_info(FunctionMetaInfo info) { this->function_info_ = info; }

  const bool is_constant_value() const { return is_constant_value_; }
  void set_is_constant_value(bool flag) { this->is_constant_value_ = flag; }
  const Value get_constant_value() const { return this->constant_value_; }
  void set_constant_value(const Value &value) {
    this->constant_value_.set_value(value);
  }

 private:
  std::string table_name_;
  std::string field_name_;
  std::string alias_;

  bool is_constant_value_ = false;
  Value constant_value_;
  FunctionType type_;
  FunctionMetaInfo function_info_;
};
