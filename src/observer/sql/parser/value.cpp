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
// Created by WangYunlai on 2023/06/28.
//

#include "sql/parser/value.h"

#include <cmath>
#include <sstream>

#include "common/lang/comparator.h"
#include "common/lang/string.h"
#include "common/log/log.h"
#include "storage/field/field.h"

const char *AGGR_FUNC_NAME[] = {"NONE", "MAX", "MIN", "COUNT", "AVG", "SUM"};
const char *aggr_func_to_str(AggrFuncType type_in) {
  if (type_in >= AggrFuncType::NONE && type_in <= AggrFuncType::SUM) {
    return AGGR_FUNC_NAME[type_in];
  }
  return "";
}

const char *FUNC_NAME[] = {"NONE", "LENGTH", "ROUND", "DATE_FORMAT"};
const char *func_to_str(FunctionType type_in) {
  if (type_in >= FunctionType::NONE_FUNC &&
      type_in <= FunctionType::DATE_FORMAT_FUNC) {
    return FUNC_NAME[type_in];
  }
  return "";
}

const char *ATTR_TYPE_NAME[] = {"undefined", "chars",    "ints",
                                "floats",    "booleans", "dates",
                                "texts",     "like_str", "null"};

const char *attr_type_to_string(AttrType type) {
  if (type >= UNDEFINED && type <= NULL_ATTR) {
    return ATTR_TYPE_NAME[type];
  }
  return "unknown";
}
AttrType attr_type_from_string(const char *s) {
  for (unsigned int i = 0;
       i < sizeof(ATTR_TYPE_NAME) / sizeof(ATTR_TYPE_NAME[0]); i++) {
    if (0 == strcmp(ATTR_TYPE_NAME[i], s)) {
      return (AttrType)i;
    }
  }
  return UNDEFINED;
}
std::string find_number_in_str_using_regex(std::string str) {
  std::string digits = ".0123456789";
  std::string re = "(\\-|\\+)?\\d+(\\.\\d+)?";
  std::regex regex(re);
  std::smatch match;
  if (std::regex_search(str, match, regex)) {
    if (str.find(match[0], 0) != 0) {
      // 找到了数字 但是不是前缀字符串
      return "0";
    }
    return match[0];
  }

  return "0";
}
std::string find_number_in_str(std::string str) {
  std::string digits = ".0123456789";
  std::string result;
  int begin_pos = str.find_first_of(digits.c_str());
  if (begin_pos == std::string::npos) return "0";
  int end_pos = str.find_first_not_of(digits.c_str(), begin_pos);
  if (end_pos == std::string::npos) {
    result = str.substr(begin_pos, str.length() - begin_pos);
  } else {
    result = str.substr(begin_pos, end_pos - begin_pos);
  }
  return result;
}
bool check_like_str_pattern_using_regex(std::string str, std::string like_str) {
  std::string re;
  for (int i = 0; i < like_str.size(); i++) {
    if (like_str[i] == '_')
      re += ".";
    else if (like_str[i] == '%')
      re += ".*";
    else {
      re.push_back(like_str[i]);
    }
  }
  std::regex regex(re);
  return std::regex_match(str, regex);
}

bool check_like_str_pattern(std::string str, std::string like_str) {
  if (str.length() == 0 || like_str.length() == 0) return false;
  int str_len = str.length();
  int like_str_len = like_str.length();
  int idx_str = 0, idx_like_str = 0;
  while (idx_like_str < like_str_len) {
    if (idx_str >= str_len) break;
    if (like_str[idx_like_str] == '_') {
      idx_like_str++;
      idx_str++;
    } else if (like_str[idx_like_str] == '%') {
      if (idx_like_str == like_str_len - 1) {
        // 直到末尾都能匹配
        return true;
      }
      idx_like_str++;
      char tmp_char = like_str[idx_like_str];
      while (str[idx_str] != tmp_char && idx_str < str_len) {
        idx_str++;
      }
      if (idx_str == str_len) {
        // 没有匹配到%后面的一个字符,直接返回false
        return false;
      }
      idx_str++;
      idx_like_str++;
    } else {
      if (str[idx_str] != like_str[idx_like_str]) {
        return false;
      }

      idx_str++;
      idx_like_str++;
    }
  }
  if (idx_like_str < like_str_len) return false;
  if (idx_str == str_len)
    return true;
  else
    return false;
}

float roundToDecimalPlaces(float number, float decimalPlaces) {
  float multiplier = std::pow(10.0, decimalPlaces);
  return std::round(number * multiplier) / multiplier;
}
float customRound(float x, int y) {
  float multiplier = powf(10, y);
  float roundedValue = roundf(x * multiplier) / multiplier;
  return roundedValue;
}

bool check_date(int ymd) {
  int d = ymd % 100;
  int m = (ymd / 100) % 100;
  int y = (ymd / 10000) % 10000;

  static int mon[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  bool leap = (y % 400 == 0 || (y % 100 && y % 4 == 0));
  return y > 0 && (m > 0) && (m <= 12) && (d > 0) &&
         (d <= ((m == 2 && leap) ? 1 : 0) + mon[m]);
}
bool check_date(int y, int m, int d) {
  static int mon[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  bool leap = (y % 400 == 0 || (y % 100 && y % 4 == 0));
  return y > 0 && (m > 0) && (m <= 12) && (d > 0) &&
         (d <= ((m == 2 && leap) ? 1 : 0) + mon[m]);
}
std::string date_to_str(int date) {
  int d = date % 100;
  int m = (date / 100) % 100;
  int y = (date / 10000) % 10000;

  std::stringstream os;
  os << y << "-";
  if (m < 10) {
    os << '0' << m << '-';

  } else
    os << m << '-';
  if (d < 10) {
    os << '0' << d;

  } else
    os << d;
  return os.str();
}

void Value::date_value_init() {
  if (attr_type_ == AttrType::DATES) {
    char *str_p = (char *)str_value_.c_str();

    int y, m, d;
    sscanf(str_p, "%d-%d-%d", &y, &m, &d);
    bool b = check_date(y, m, d);
    if (!b) {
      LOG_ERROR("Date format error, date_str is %s.", str_p);
      this->set_date(-1);
      return;
    }

    int dv = y * 10000 + m * 100 + d;
    this->set_date(dv);
    return;
  } else {
    LOG_ERROR("Value is not DATE type, type is %d", (int)attr_type_);
    return;
  }
}

Value::Value(int val) { set_int(val); }

Value::Value(float val) { set_float(val); }

Value::Value(bool val) { set_boolean(val); }

Value::Value(int year, int month, int day) {
  bool b = check_date(year, month, day);
  if (!b) {
    LOG_ERROR("Date invalid, y = %d,m = %d,d = %d", year, month, day);
    this->set_date(-1);
  } else {
    int dv = year * 10000 + month * 100 + day;
    this->set_date(dv);
  }
}

Value::Value(const char *s, int len /*= 0*/) { set_string(s, len); }

void Value::set_data(char *data, int length) {
  switch (attr_type_) {
    case CHARS: {
      set_string(data, length);
    } break;
    case INTS: {
      num_value_.int_value_ = *(int *)data;
      length_ = length;
    } break;
    case FLOATS: {
      num_value_.float_value_ = *(float *)data;
      length_ = length;
    } break;
    case BOOLEANS: {
      num_value_.bool_value_ = *(int *)data != 0;
      length_ = length;
    } break;
    case DATES: {
      num_value_.date_value_ = *(int *)data;
      length_ = length;
    } break;
    case TEXTS: {
      set_text(data, length);
    } break;
    case NULL_ATTR: {
      length_ = length;
    }
    default: {
      LOG_WARN("unknown data type: %d", attr_type_);
    } break;
  }
}
void Value::set_int(int val) {
  attr_type_ = INTS;
  num_value_.int_value_ = val;
  length_ = sizeof(val);
}

void Value::set_float(float val) {
  attr_type_ = FLOATS;
  num_value_.float_value_ = val;
  length_ = sizeof(val);
}
void Value::set_boolean(bool val) {
  attr_type_ = BOOLEANS;
  num_value_.bool_value_ = val;
  length_ = sizeof(val);
}
void Value::set_date(int val) {
  attr_type_ = DATES;
  num_value_.date_value_ = val;
  length_ = sizeof(val);
}
void Value::set_null(const char *s, int len /*= 0*/) {
  attr_type_ = NULL_ATTR;
  num_value_.int_value_ = 0;
  str_value_ = "";
  length_ = 4;
}
void Value::set_string(const char *s, int len /*= 0*/) {
  attr_type_ = CHARS;
  if (len > 0) {
    len = strnlen(s, len);
    str_value_.assign(s, len);
  } else {
    str_value_.assign(s);
  }
  length_ = str_value_.length();
}
void Value::set_text(const char *s, int len /*= 0*/) {
  attr_type_ = TEXTS;
  len = MAX_TEXT_LENGTH;
  if (len > 0) {
    len = strnlen(s, len);
    str_value_.assign(s, len);
  } else {
    str_value_.assign(s);
  }
  length_ = str_value_.length();
}

void Value::set_like_string(const char *s, int len /*= 0*/) {
  attr_type_ = LIKE_STR;
  if (len > 0) {
    len = strnlen(s, len);
    like_str_value_.assign(s, len);
  } else {
    like_str_value_.assign(s);
  }
  length_ = like_str_value_.length();
}

void Value::set_value(const Value &value) {
  switch (value.attr_type_) {
    case INTS: {
      set_int(value.get_int());
    } break;
    case FLOATS: {
      set_float(value.get_float());
    } break;
    case CHARS: {
      set_string(value.get_string().c_str());
    } break;
    case BOOLEANS: {
      set_boolean(value.get_boolean());
    } break;
    case UNDEFINED: {
      ASSERT(false, "got an invalid value type");
    } break;
    case DATES: {
      set_date(value.get_date());
    } break;
    case TEXTS: {
      set_text(value.get_string().c_str());
    } break;
    case LIKE_STR: {
      set_string(value.get_string().c_str());
    } break;
    case NULL_ATTR: {
      set_null(nullptr);
    } break;
  }
}
RC Value::add_value(const Value &value) {
  RC rc = RC::SUCCESS;
  Value tmp_value(value);
  tmp_value.set_value(value);
  if (this->attr_type_ != value.attr_type()) {
    LOG_INFO("Typecasting in add Value.");
    rc = tmp_value.typecast_to(this->attr_type_);
    if (rc != RC::SUCCESS) {
      LOG_ERROR("Typecast Error from %s to %s.", value.attr_type(),
                this->attr_type_);
      return rc;
    }
  }
  switch (attr_type_) {
    case NULL_ATTR: {
      LOG_WARN("Try to add to or add with an null value.");
      return RC::INVALID_ARGUMENT;
    } break;
    case INTS: {
      set_int(this->get_int() + tmp_value.get_int());
    } break;
    case FLOATS: {
      set_float(this->get_float() + tmp_value.get_float());
    } break;
    case CHARS: {
      LOG_ERROR("Cannot add a string to another.");
      rc = RC::INVALID_ARGUMENT;
    } break;
    case TEXTS: {
      LOG_ERROR("Cannot add a text to another.");
      rc = RC::INVALID_ARGUMENT;
    } break;
    case BOOLEANS: {
      LOG_ERROR("Cannot add a bool to another.");
      rc = RC::INVALID_ARGUMENT;
    } break;
    case UNDEFINED: {
      ASSERT(false, "got an invalid value type");
    } break;
    case DATES: {
      LOG_ERROR("Cannot add a date to another.");
      rc = RC::INVALID_ARGUMENT;
    } break;
  }
  return rc;
}

const char *Value::data() const {
  switch (attr_type_) {
    case CHARS: {
      return str_value_.c_str();
    } break;
    case TEXTS: {
      return str_value_.c_str();
    } break;
    case NULL_ATTR: {
      return (const char *)&num_value_;
    } break;
    default: {
      return (const char *)&num_value_;
    } break;
  }
}

std::string Value::to_string() const {
  std::stringstream os;
  switch (attr_type_) {
    case INTS: {
      os << num_value_.int_value_;
    } break;
    case FLOATS: {
      os << common::double_to_str(num_value_.float_value_);
    } break;
    case BOOLEANS: {
      os << num_value_.bool_value_;
    } break;
    case CHARS: {
      os << str_value_;
    } break;
    case LIKE_STR: {
      os << like_str_value_;
    } break;
    case DATES: {
      os << date_to_str(num_value_.date_value_);
    } break;
    case TEXTS: {
      os << str_value_;
    } break;
    case NULL_ATTR: {
      os << "null";
    } break;
    default: {
      LOG_WARN("unsupported attr type: %d", attr_type_);
    } break;
  }
  return os.str();
}
RC Value::typecast_to(AttrType dest_type) {
  RC rc = RC::TYPECAST_FAILED;
  if (this->attr_type() == dest_type) {
    rc = RC::SUCCESS;
  } else if (this->attr_type() == AttrType::NULL_ATTR) {
    LOG_WARN("Null cannot typecast to other types.");
    return RC::TYPECAST_FAILED;
  } else if (this->attr_type_ == AttrType::INTS &&
             dest_type == AttrType::FLOATS) {
    float this_data = this->num_value_.int_value_;
    this->set_float(this_data);
    rc = RC::SUCCESS;
  } else if (this->attr_type_ == AttrType::FLOATS &&
             dest_type == AttrType::INTS) {
    float tmp_float = this->num_value_.float_value_;
    int this_data =
        ((int)tmp_float) + ((((int)(tmp_float * 10)) % 10) >= 5 ? 1 : 0);
    this->set_int(this_data);
    rc = RC::SUCCESS;
  } else if (this->attr_type_ == AttrType::CHARS &&
             dest_type == AttrType::FLOATS) {
    char *this_data =
        (char *)find_number_in_str_using_regex(this->str_value_).c_str();
    float this_float;
    try {
      this_float = atof(this_data);
    } catch (const std::invalid_argument &e) {
      rc = RC::INVALID_ARGUMENT;
      LOG_ERROR("Cannot typecast, src:%s, dest type:%d.",
                this->str_value_.c_str(), dest_type);
      return rc;
    }
    this->set_float(this_float);
    rc = RC::SUCCESS;
  } else if (this->attr_type_ == AttrType::FLOATS &&
             dest_type == AttrType::CHARS) {
    std::stringstream ss;
    ss << this->num_value_.float_value_;
    const char *this_data = ss.str().c_str();
    this->set_string(this_data, strlen(this_data));
    rc = RC::SUCCESS;
  } else if (this->attr_type_ == AttrType::CHARS &&
             dest_type == AttrType::INTS) {
    char *this_data =
        (char *)find_number_in_str_using_regex(this->str_value_).c_str();
    float tmp_float;
    int this_int;

    try {
      tmp_float = atof(this_data);
      this_int =
          ((int)tmp_float) + ((((int)(tmp_float * 10)) % 10) >= 5 ? 1 : 0);
    } catch (const std::invalid_argument &e) {
      rc = RC::INVALID_ARGUMENT;
      LOG_ERROR("Cannot typecast, src:%s, dest type:%d.",
                this->str_value_.c_str(), dest_type);
      return rc;
    }
    this->set_int(this_int);
    rc = RC::SUCCESS;
  } else if (this->attr_type_ == AttrType::INTS &&
             dest_type == AttrType::CHARS) {
    char *this_data =
        (char *)std::to_string(this->num_value_.int_value_).c_str();
    this->set_string(this_data, strlen(this_data));
    rc = RC::SUCCESS;
  } else if (this->attr_type_ == AttrType::CHARS &&
             dest_type == AttrType::TEXTS) {
    this->set_text(this->data());
    rc = RC::SUCCESS;
  } else if (this->attr_type_ == AttrType::TEXTS &&
             dest_type == AttrType::CHARS) {
    this->set_string(this->data());
    rc = RC::SUCCESS;
  } else if (dest_type == AttrType::NULL_ATTR) {
    // this->set_null(this_data, strlen(this_data));
    rc = RC::SUCCESS;
  }

  return rc;
}
RC Value::compare(const Value &other, int &cmp_result) const {
  RC rc = RC::SUCCESS;

  if (this->attr_type_ == other.attr_type_) {
    switch (this->attr_type_) {
      case INTS: {
        cmp_result = common::compare_int((void *)&this->num_value_.int_value_,
                                         (void *)&other.num_value_.int_value_);
      } break;
      case FLOATS: {
        cmp_result =
            common::compare_float((void *)&this->num_value_.float_value_,
                                  (void *)&other.num_value_.float_value_);
      } break;
      case CHARS: {
        cmp_result = common::compare_string(
            (void *)this->str_value_.c_str(), this->str_value_.length(),
            (void *)other.str_value_.c_str(), other.str_value_.length());
      } break;
      case BOOLEANS: {
        cmp_result = common::compare_int((void *)&this->num_value_.bool_value_,
                                         (void *)&other.num_value_.bool_value_);
      } break;
      case DATES: {
        cmp_result = common::compare_int((void *)&this->num_value_.date_value_,
                                         (void *)&other.num_value_.date_value_);
      } break;
      case TEXTS: {
        cmp_result = common::compare_string(
            (void *)this->str_value_.c_str(), this->str_value_.length(),
            (void *)other.str_value_.c_str(), other.str_value_.length());
      } break;
      case NULL_ATTR: {
        cmp_result = 0;
        rc = RC::NULL_COMPARE_ERROR;
      } break;
      default: {
        LOG_WARN("unsupported type: %d", this->attr_type_);
      }
    }
    return rc;
  } else if (other.attr_type_ == AttrType::NULL_ATTR ||
             this->attr_type_ == AttrType::NULL_ATTR) {
    cmp_result = 1;
    rc = RC::NULL_COMPARE_ERROR;
    return rc;
  } else if (other.attr_type_ == AttrType::LIKE_STR) {
    // Here to process like_str pattern;
    // TO DO
    Value *tmp_value = new Value(other);
    tmp_value->set_like_string(tmp_value->str_value_.c_str());
    char *like_str = (char *)tmp_value->like_str_value_.c_str();
    char *this_str = (char *)this->str_value_.c_str();
    // bool result = check_like_str_pattern(this_str, like_str);
    bool result = check_like_str_pattern_using_regex(this_str, like_str);
    cmp_result = result ? 0 : -1;
    return rc;
  } else if (other.attr_type_ == AttrType::FLOATS ||
             this->attr_type_ == AttrType::FLOATS) {
    if (this->attr_type_ == AttrType::FLOATS) {
      Value *tmp_value = new Value(other);
      RC rc = tmp_value->typecast_to(this->attr_type());
      if (rc != RC::SUCCESS) {
        LOG_WARN("Cannot tpecast from %d to %d.", tmp_value->attr_type(),
                 this->attr_type());
        cmp_result = -1;
      }
      cmp_result = this->compare(*tmp_value);

    } else {
      cmp_result = -other.compare(*this);
    }
    return rc;

  } else if (other.attr_type_ == AttrType::INTS ||
             this->attr_type_ == AttrType::INTS) {
    if (this->attr_type_ != AttrType::INTS) {
      Value *tmp_value = new Value(*this);
      RC rc = tmp_value->typecast_to(AttrType::FLOATS);
      if (rc != RC::SUCCESS) {
        LOG_WARN("Cannot tpecast from %d to %d.", tmp_value->attr_type(),
                 AttrType::FLOATS);
        cmp_result = -1;
      }
      Value *tmp_other_value = new Value(other);
      rc = tmp_other_value->typecast_to(AttrType::FLOATS);
      if (rc != RC::SUCCESS) {
        LOG_WARN("Cannot tpecast from %d to %d.", tmp_other_value->attr_type(),
                 AttrType::FLOATS);
        cmp_result = -1;
      }
      cmp_result = tmp_value->compare(*tmp_other_value);
    } else {
      cmp_result = -other.compare(*this);
    }
    return rc;

  } else {
    Value *tmp_value = new Value(*this);
    RC rc = tmp_value->typecast_to(other.attr_type());
    if (rc != RC::SUCCESS) {
      LOG_WARN("Cannot tpecast from %d to %d.", tmp_value->attr_type(),
               other.attr_type());
      cmp_result = -1;
    }
    cmp_result = tmp_value->compare(other);
    return rc;
  }

  LOG_WARN("not supported");
  cmp_result = -1;  // TODO cmp_result =  rc?
  return rc;
}
int Value::compare(const Value &other) const {
  if (this->attr_type_ == other.attr_type_) {
    switch (this->attr_type_) {
      case INTS: {
        return common::compare_int((void *)&this->num_value_.int_value_,
                                   (void *)&other.num_value_.int_value_);
      } break;
      case FLOATS: {
        return common::compare_float((void *)&this->num_value_.float_value_,
                                     (void *)&other.num_value_.float_value_);
      } break;
      case CHARS: {
        return common::compare_string(
            (void *)this->str_value_.c_str(), this->str_value_.length(),
            (void *)other.str_value_.c_str(), other.str_value_.length());
      } break;
      case BOOLEANS: {
        return common::compare_int((void *)&this->num_value_.bool_value_,
                                   (void *)&other.num_value_.bool_value_);
      }
      case DATES: {
        return common::compare_int((void *)&this->num_value_.date_value_,
                                   (void *)&other.num_value_.date_value_);
      }
      case TEXTS: {
        return common::compare_string(
            (void *)this->str_value_.c_str(), this->str_value_.length(),
            (void *)other.str_value_.c_str(), other.str_value_.length());
      } break;
      case NULL_ATTR: {
        return 0;
      }
      default: {
        LOG_WARN("unsupported type: %d", this->attr_type_);
      }
    }
  }
  // else if (this->attr_type_ == INTS && other.attr_type_ == FLOATS) {
  //   float this_data = this->num_value_.int_value_;
  //   return common::compare_float((void *)&this_data,
  //                                (void *)&other.num_value_.float_value_);
  // } else if (this->attr_type_ == FLOATS && other.attr_type_ == INTS) {
  //   float other_data = other.num_value_.int_value_;
  //   return common::compare_float((void *)&this->num_value_.float_value_,
  //                                (void *)&other_data);
  // } else if (this->attr_type_ == CHARS && other.attr_type_ == FLOATS) {
  //   char *this_data = (char *)this->str_value_.c_str();
  //   float this_float = strtof(this_data, nullptr);
  //   return common::compare_float((void *)&this_float,
  //                                (void *)&other.num_value_.float_value_);
  // }
  else if (other.attr_type_ == AttrType::NULL_ATTR ||
           this->attr_type_ == AttrType::NULL_ATTR) {
    return this->attr_type_ == AttrType::NULL_ATTR ? -1 : 1;
  } else if (other.attr_type_ == AttrType::LIKE_STR) {
    // Here to process like_str pattern;
    // TO DO
    Value *tmp_value = new Value(other);
    tmp_value->set_like_string(tmp_value->str_value_.c_str());
    char *like_str = (char *)tmp_value->like_str_value_.c_str();
    char *this_str = (char *)this->str_value_.c_str();
    // bool result = check_like_str_pattern(this_str, like_str);
    bool result = check_like_str_pattern_using_regex(this_str, like_str);
    return result ? 0 : -1;

  } else if (other.attr_type_ == AttrType::FLOATS ||
             this->attr_type_ == AttrType::FLOATS) {
    if (this->attr_type_ == AttrType::FLOATS) {
      Value *tmp_value = new Value(other);
      RC rc = tmp_value->typecast_to(this->attr_type());
      if (rc != RC::SUCCESS) {
        LOG_WARN("Cannot tpecast from %d to %d.", tmp_value->attr_type(),
                 this->attr_type());
        return -1;
      }
      return this->compare(*tmp_value);
    } else {
      return -other.compare(*this);
    }
  } else if (other.attr_type_ == AttrType::INTS ||
             this->attr_type_ == AttrType::INTS) {
    if (this->attr_type_ != AttrType::INTS) {
      Value *tmp_value = new Value(*this);
      RC rc = tmp_value->typecast_to(AttrType::FLOATS);
      if (rc != RC::SUCCESS) {
        LOG_WARN("Cannot tpecast from %d to %d.", tmp_value->attr_type(),
                 AttrType::FLOATS);
        return -1;
      }
      Value *tmp_other_value = new Value(other);
      rc = tmp_other_value->typecast_to(AttrType::FLOATS);
      if (rc != RC::SUCCESS) {
        LOG_WARN("Cannot tpecast from %d to %d.", tmp_other_value->attr_type(),
                 AttrType::FLOATS);
        return -1;
      }
      return tmp_value->compare(*tmp_other_value);
    } else {
      return -other.compare(*this);
    }
  } else {
    Value *tmp_value = new Value(*this);
    RC rc = tmp_value->typecast_to(other.attr_type());
    if (rc != RC::SUCCESS) {
      LOG_WARN("Cannot tpecast from %d to %d.", tmp_value->attr_type(),
               other.attr_type());
      return -1;
    }
    return tmp_value->compare(other);
  }

  LOG_WARN("not supported");
  return -1;  // TODO return rc?
}

int Value::get_int() const {
  switch (attr_type_) {
    case CHARS: {
      try {
        return (int)(std::stol(str_value_));
      } catch (std::exception const &ex) {
        LOG_TRACE("failed to convert string to number. s=%s, ex=%s",
                  str_value_.c_str(), ex.what());
        return 0;
      }
    }
    case TEXTS: {
      try {
        return (int)(std::stol(str_value_));
      } catch (std::exception const &ex) {
        LOG_TRACE("failed to convert string to number. s=%s, ex=%s",
                  str_value_.c_str(), ex.what());
        return 0;
      }
    }
    case INTS: {
      return num_value_.int_value_;
    }
    case FLOATS: {
      return (int)(num_value_.float_value_);
    }
    case BOOLEANS: {
      return (int)(num_value_.bool_value_);
    }
    case DATES: {
      return num_value_.date_value_;
    }
    default: {
      LOG_WARN("unknown data type. type=%d", attr_type_);
      return 0;
    }
  }
  return 0;
}

float Value::get_float() const {
  switch (attr_type_) {
    case CHARS: {
      try {
        return std::stof(str_value_);
      } catch (std::exception const &ex) {
        LOG_TRACE("failed to convert string to float. s=%s, ex=%s",
                  str_value_.c_str(), ex.what());
        return 0.0;
      }
    } break;
    case TEXTS: {
      try {
        return std::stof(str_value_);
      } catch (std::exception const &ex) {
        LOG_TRACE("failed to convert string to float. s=%s, ex=%s",
                  str_value_.c_str(), ex.what());
        return 0.0;
      }
    } break;
    case INTS: {
      return float(num_value_.int_value_);
    } break;
    case FLOATS: {
      return num_value_.float_value_;
    } break;
    case BOOLEANS: {
      return float(num_value_.bool_value_);
    } break;
    default: {
      LOG_WARN("unknown data type. type=%d", attr_type_);
      return 0;
    }
  }
  return 0;
}

std::string Value::get_string() const { return this->to_string(); }
std::string Value::get_like_string() const { return this->like_str_value_; }

bool Value::get_boolean() const {
  switch (attr_type_) {
    case CHARS: {
      try {
        float val = std::stof(str_value_);
        if (val >= EPSILON || val <= -EPSILON) {
          return true;
        }

        int int_val = std::stol(str_value_);
        if (int_val != 0) {
          return true;
        }

        return !str_value_.empty();
      } catch (std::exception const &ex) {
        LOG_TRACE("failed to convert string to float or integer. s=%s, ex=%s",
                  str_value_.c_str(), ex.what());
        return !str_value_.empty();
      }
    } break;
    case TEXTS: {
      try {
        float val = std::stof(str_value_);
        if (val >= EPSILON || val <= -EPSILON) {
          return true;
        }

        int int_val = std::stol(str_value_);
        if (int_val != 0) {
          return true;
        }

        return !str_value_.empty();
      } catch (std::exception const &ex) {
        LOG_TRACE("failed to convert string to float or integer. s=%s, ex=%s",
                  str_value_.c_str(), ex.what());
        return !str_value_.empty();
      }
    } break;
    case INTS: {
      return num_value_.int_value_ != 0;
    } break;
    case FLOATS: {
      float val = num_value_.float_value_;
      return val >= EPSILON || val <= -EPSILON;
    } break;
    case BOOLEANS: {
      return num_value_.bool_value_;
    } break;
    default: {
      LOG_WARN("unknown data type. type=%d", attr_type_);
      return false;
    }
  }
  return false;
}

int Value::get_date() const {
  switch (attr_type_) {
    case CHARS: {
      try {
        return (int)(std::stol(str_value_));
      } catch (std::exception const &ex) {
        LOG_TRACE("failed to convert string to number. s=%s, ex=%s",
                  str_value_.c_str(), ex.what());
        return 0;
      }
    }
    case TEXTS: {
      try {
        return (int)(std::stol(str_value_));
      } catch (std::exception const &ex) {
        LOG_TRACE("failed to convert string to number. s=%s, ex=%s",
                  str_value_.c_str(), ex.what());
        return 0;
      }
    }
    case INTS: {
      if (check_date(num_value_.int_value_)) return num_value_.int_value_;
      return -1;
    }
    case FLOATS: {
      return -1;
    }
    case BOOLEANS: {
      return -1;
    }
    case DATES: {
      return num_value_.date_value_;
    }
    default: {
      LOG_WARN("unknown data type. type=%d", attr_type_);
      return 0;
    }
  }
  return 0;
}
