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
// Created by Wangyunlai 2023/6/27
//

#pragma once

#include <stdlib.h>

#include <iostream>
// #include <regex>
#include <sstream>
#include <string>

#include "common/rc.h"
// #include "deps/3rd/benchmark/src/re.h"
#include <regex>

// #include "./date.h"

enum AggrFuncType { NONE, MAX, MIN, CNT, AVG, SUM };
const char *aggr_func_to_str(AggrFuncType type_in);

enum OrderByDirection { ASC_ORDER, DESC_ORDER };

/**
 * @brief 属性的类型
 *
 */
enum AttrType {
  UNDEFINED,
  CHARS,     ///< 字符串类型
  INTS,      ///< 整数类型(4字节)
  FLOATS,    ///< 浮点数类型(4字节)
  BOOLEANS,  ///< boolean类型，当前不是由parser解析出来的，是程序内部使用的
  DATES,     ///< 新添加的DATE类型
  TEXTS,     ///< 未来肯能需要支持的文本类型数据
  LIKE_STR,  ///< 支持 LIKE 语法的匹配字符串
  NULL_ATTR,  ///< 支持null类型数据
};

const char *attr_type_to_string(AttrType type);
AttrType attr_type_from_string(const char *s);

/**
 * @brief 属性的值
 *
 */
class Value {
 public:
  Value() = default;

  Value(AttrType attr_type, char *data, int length = 4)
      : attr_type_(attr_type) {
    this->set_data(data, length);
  }

  explicit Value(int val);
  explicit Value(float val);
  explicit Value(bool val);
  explicit Value(const char *s, int len = 0);
  explicit Value(int year, int month, int day);

  Value(const Value &other) = default;
  Value &operator=(const Value &other) = default;

  void date_value_init();

  RC typecast_to(AttrType dest_type);

  void set_type(AttrType type) { this->attr_type_ = type; }
  void set_data(char *data, int length);
  void set_data(const char *data, int length) {
    this->set_data(const_cast<char *>(data), length);
  }
  void set_int(int val);
  void set_float(float val);
  void set_boolean(bool val);
  void set_string(const char *s, int len = 0);
  void set_like_string(const char *s, int len = 0);
  void set_null(const char *s, int len = 0);
  void set_date(int val);
  void set_value(const Value &value);
  RC add_value(const Value &value);

  std::string to_string() const;

  int compare(const Value &other) const;
  RC compare(const Value &other, int &cmp_result) const;

  const char *data() const;
  int length() const { return length_; }

  AttrType attr_type() const { return attr_type_; }

 public:
  /**
   * 获取对应的值
   * 如果当前的类型与期望获取的类型不符，就会执行转换操作
   */
  int get_int() const;
  float get_float() const;
  std::string get_string() const;
  std::string get_like_string() const;
  bool get_boolean() const;
  int get_date() const;
  std::string get_date_str() const;

 private:
  AttrType attr_type_ = UNDEFINED;
  int length_ = 0;

  union {
    int int_value_;
    float float_value_;
    bool bool_value_;
    int date_value_;
  } num_value_;
  std::string str_value_;
  std::string like_str_value_;
  // Date date_value_;
};
