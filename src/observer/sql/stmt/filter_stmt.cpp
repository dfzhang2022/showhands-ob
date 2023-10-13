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
// Created by Wangyunlai on 2022/5/22.
//

#include "sql/stmt/filter_stmt.h"

#include "common/lang/string.h"
#include "common/log/log.h"
#include "common/rc.h"
#include "storage/db/db.h"
#include "storage/table/table.h"

FilterStmt::~FilterStmt() {
  for (FilterUnit *unit : filter_units_) {
    delete unit;
  }
  filter_units_.clear();
}

RC FilterStmt::create(Db *db, Table *default_table,
                      std::unordered_map<std::string, Table *> *tables,
                      const ConditionSqlNode *conditions, int condition_num,
                      FilterStmt *&stmt) {
  RC rc = RC::SUCCESS;
  stmt = nullptr;

  FilterStmt *tmp_stmt = new FilterStmt();
  for (int i = 0; i < condition_num; i++) {
    FilterUnit *filter_unit = nullptr;
    rc = create_filter_unit(db, default_table, tables, conditions[i],
                            filter_unit);
    if (rc != RC::SUCCESS) {
      delete tmp_stmt;
      LOG_WARN("failed to create filter unit. condition index=%d", i);
      return rc;
    }
    tmp_stmt->filter_units_.push_back(filter_unit);
  }

  stmt = tmp_stmt;
  return rc;
}

RC get_table_and_field(Db *db, Table *default_table,
                       std::unordered_map<std::string, Table *> *tables,
                       const RelAttrSqlNode &attr, Table *&table,
                       const FieldMeta *&field) {
  if (common::is_blank(attr.relation_name.c_str())) {
    table = default_table;
  } else if (nullptr != tables) {
    auto iter = tables->find(attr.relation_name);
    if (iter != tables->end()) {
      table = iter->second;
    } else {
      iter = tables->find(attr.alias);
      if (iter != tables->end()) {
        table = iter->second;
      }
    }
  } else {
    table = db->find_table(attr.relation_name.c_str());
  }
  if (nullptr == table) {
    LOG_WARN("No such table: attr.relation_name: %s",
             attr.relation_name.c_str());
    return RC::SCHEMA_TABLE_NOT_EXIST;
  }

  field = table->table_meta().field(attr.attribute_name.c_str());
  if (nullptr == field) {
    LOG_WARN("no such field in table: table %s, field %s", table->name(),
             attr.attribute_name.c_str());
    table = nullptr;
    return RC::SCHEMA_FIELD_NOT_EXIST;
  }

  return RC::SUCCESS;
}

RC check_value_date(const Value &value) {
  RC rc = RC::SUCCESS;
  if (value.attr_type() == AttrType::DATES && value.get_date() == -1) {
    rc = RC::INVALID_DATE;
    LOG_WARN("Invalid date.");
    return rc;
  }
  return rc;
}

RC get_field(Db *db, Table *default_table,
    std::unordered_map<std::string, Table *> *tables,
    const RelAttrSqlNode &attr, Field &tmp_field) {
  RC rc = RC::SUCCESS;
  Table *table = nullptr;
  const FieldMeta *field = nullptr;
  if (attr.is_aggregation_func &&
      attr.aggr_func_type == AggrFuncType::CNT &&
      0 == strcmp("*", attr.attribute_name.c_str())) {
    // 对于COUNT(*)>value做单独的处理
    tmp_field.set_aggr_func_type(attr.aggr_func_type);
  } else {
    rc = get_table_and_field(db, default_table, tables, attr,
                            table, field);
    if (rc != RC::SUCCESS) {
      LOG_WARN("cannot find attr");
      return rc;
    }
    tmp_field = Field(table, field);
    if (attr.is_aggregation_func) {
      tmp_field.set_aggr_func_type(attr.aggr_func_type);
    }
  }
  return rc;
}

RC FilterStmt::create_filter_unit(
    Db *db, Table *default_table,
    std::unordered_map<std::string, Table *> *tables,
    const ConditionSqlNode &condition, FilterUnit *&filter_unit) {
  RC rc = RC::SUCCESS;


  ExprOp comp = condition.comp;
  if (comp < EQUAL_TO || comp >= NO_OP) {
    LOG_WARN("invalid compare operator : %d", comp);
    return RC::INVALID_ARGUMENT;
  }

  filter_unit = new FilterUnit;

  if (condition.left_type == ExpressType::ATTR_T) {
    FilterObj filter_obj;
    Field tmp_field;
    rc = get_field(db, default_table, tables, condition.left_attr, tmp_field);
    if (rc != RC::SUCCESS) {
      return rc;
    }
    filter_obj.init_attr(tmp_field);
    filter_unit->set_left(filter_obj);
  } else if (condition.left_type == ExpressType::VALUE_T) {
    rc = check_value_date(condition.left_value);
    if (rc != RC::SUCCESS) {
      return rc;
    }
    FilterObj filter_obj;
    filter_obj.init_value(condition.left_value);
    filter_unit->set_left(filter_obj);
  } else if (condition.left_type == ExpressType::EXPR_T) {
    FilterObj filter_obj;
    rc = filter_obj.init_expr(db, default_table, tables, condition.left_expr);
    if (rc != RC::SUCCESS) {
      return rc;
    }
    filter_unit->set_left(filter_obj);
  } else {
    FilterObj filter_obj;
    Stmt *tmp_ptr;
    rc = SelectStmt::create(db, *condition.left_selects, tmp_ptr, true);
    filter_obj.init_select(tmp_ptr);
    filter_unit->set_left(filter_obj);
  }

  if (condition.right_type == ExpressType::ATTR_T) {
    FilterObj filter_obj;
    Field tmp_field;
    rc = get_field(db, default_table, tables, condition.right_attr, tmp_field);
    if (rc != RC::SUCCESS) {
      return rc;
    }
    filter_obj.init_attr(tmp_field);
    filter_unit->set_right(filter_obj);
  } else if (condition.right_type == ExpressType::VALUE_T) {
    rc = check_value_date(condition.right_value);
    if (rc != RC::SUCCESS) {
      return rc;
    }
    FilterObj filter_obj;
    filter_obj.init_value(condition.right_value);
    if (comp == ExprOp::LIKE || comp == ExprOp::NOT_LIKE) {
      // 说明右值是like_str
      filter_obj.expr_obj_.right_value.set_type(AttrType::LIKE_STR);
    } else if (comp == ExprOp::IS_EQUAL) {
      // 比较语句是IS
      // filter_obj.value.set_type(AttrType::LIKE_STR);
    }

    filter_unit->set_right(filter_obj);
  } else if (condition.right_type == ExpressType::EXPR_T) {
    FilterObj filter_obj;
    rc = filter_obj.init_expr(db, default_table, tables, condition.right_expr);
    if (rc != RC::SUCCESS) {
      return rc;
    }
    filter_unit->set_right(filter_obj);
  } else {
    FilterObj filter_obj;
    Stmt *tmp_ptr;
    rc = SelectStmt::create(db, *condition.right_selects, tmp_ptr, true);
    filter_obj.init_select(tmp_ptr);
    filter_unit->set_right(filter_obj);
  }
  filter_unit->set_comp(comp);
  return rc;
}
