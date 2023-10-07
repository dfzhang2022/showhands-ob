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
// Created by Wangyunlai on 2022/6/6.
//

#include "sql/stmt/select_stmt.h"

#include "common/lang/string.h"
#include "common/log/log.h"
#include "sql/stmt/filter_stmt.h"
#include "storage/db/db.h"
#include "storage/table/table.h"

SelectStmt::~SelectStmt() {
  if (nullptr != filter_stmt_) {
    delete filter_stmt_;
    filter_stmt_ = nullptr;
  }
}

static void wildcard_fields(Table *table, std::vector<Field> &field_metas) {
  const TableMeta &table_meta = table->table_meta();
  const int field_num = table_meta.field_num();
  for (int i = table_meta.sys_field_num(); i < field_num; i++) {
    Field tmp_field(table, table_meta.field(i));
    if (table->has_alias()) {
      tmp_field.set_alias(table->get_alias() + "." + tmp_field.field_name());
      tmp_field.set_has_alias(true);
    }
    field_metas.push_back(tmp_field);
  }
}

RC SelectStmt::create(Db *db, const SelectSqlNode &select_sql, Stmt *&stmt) {
  if (nullptr == db) {
    LOG_WARN("invalid argument. db is null");
    return RC::INVALID_ARGUMENT;
  }

  // collect tables in `from` statement
  std::vector<Table *> tables;
  std::unordered_map<std::string, Table *> table_map;
  std::vector<ConditionSqlNode> conditions = select_sql.conditions;
  for (size_t i = 0; i < select_sql.relations.size(); i++) {
    const char *table_name = select_sql.relations[i].relation.c_str();
    const char *table_alias = select_sql.relations[i].alias.c_str();
    RelationSqlNode relationsqlnode = select_sql.relations[i];
    if (!relationsqlnode.has_inner_join) {
      const char *table_name = relationsqlnode.relation.c_str();
      if (nullptr == table_name) {
        LOG_WARN("invalid argument. relation name is null. index=%d", i);
        return RC::INVALID_ARGUMENT;
      }

      Table *table = db->find_table(table_name);
      if (nullptr == table) {
        LOG_WARN("no such table. db=%s, table_name=%s", db->name(), table_name);
        return RC::SCHEMA_TABLE_NOT_EXIST;
      }
      if (select_sql.relations[i].has_alias) {
        table->set_has_alias(true);
        table->set_alias(select_sql.relations[i].alias);
        table_map.insert(std::pair<std::string, Table *>(table_alias, table));
      }

      tables.push_back(table);
      table_map.insert(std::pair<std::string, Table *>(table_name, table));
    } else {
      for (auto relation : relationsqlnode.inner_join_sql_node.relations) {
        const char *table_name = relation.c_str();
        if (nullptr == table_name) {
          LOG_WARN("invalid argument. relation name is null. index=%d", i);
          return RC::INVALID_ARGUMENT;
        }

        Table *table = db->find_table(table_name);
        if (nullptr == table) {
          LOG_WARN("no such table. db=%s, table_name=%s", db->name(),
                   table_name);
          return RC::SCHEMA_TABLE_NOT_EXIST;
        }
        if (select_sql.relations[i].has_alias) {
          table->set_has_alias(true);
          table->set_alias(select_sql.relations[i].alias);
          table_map.insert(std::pair<std::string, Table *>(table_alias, table));
        }

        tables.push_back(table);
        table_map.insert(std::pair<std::string, Table *>(table_name, table));
      }
      conditions.insert(
          conditions.end(),
          relationsqlnode.inner_join_sql_node.join_on_conditions.begin(),
          relationsqlnode.inner_join_sql_node.join_on_conditions.end());
    }
  }

  // collect query fields in `select` statement
  std::vector<Field> query_fields;       // 投影列
  std::vector<Field> aggr_query_fields;  // 聚合列
  // 聚合列和投影列本来是一一对应的 只有出现AGGR(*)时才会出现数量不一致
  // 其实只有COUNT(*)
  // COUNT(*.*)是语法错误
  std::map<int, int> aggr_field_to_query_field_map;
  int aggr_func_count = 0;  // 计算列中的聚合函数数量
  for (int i = static_cast<int>(select_sql.attributes.size()) - 1; i >= 0;
       i--) {
    if (select_sql.attributes[i].aggr_func_type != AggrFuncType::NONE)
      aggr_func_count++;
  }
  if (aggr_func_count != 0 && aggr_func_count != select_sql.attributes.size()) {
    // 若存在聚合函数但又不全是聚合函数
    LOG_WARN("All aggr_func or all not");
    return RC::AGGR_FUNC_NOT_VALID;
  }

  for (int i = static_cast<int>(select_sql.attributes.size()) - 1; i >= 0;
       i--) {
    const RelAttrSqlNode &relation_attr = select_sql.attributes[i];
    if (relation_attr.is_syntax_error)
      return RC::SQL_SYNTAX;  // 排除语法解析错误
    // 只剩下两种非法:1. non-aggr和aggr的混用 2.非COUNT(*)以外的AGGR(*)

    if (common::is_blank(relation_attr.relation_name.c_str()) &&
        0 == strcmp(relation_attr.attribute_name.c_str(), "*")) {
      // 代表投影列是 "*"
      for (Table *table : tables) {
        wildcard_fields(table, query_fields);
      }
      if (relation_attr.aggr_func_type != AggrFuncType::NONE) {
        // 存在聚集函数
        if (relation_attr.aggr_func_type == AggrFuncType::CNT) {
          Field *tmp_field = new Field();
          tmp_field->set_aggr_func_type(AggrFuncType::CNT);
          tmp_field->set_alias("COUNT(*)");
          if (select_sql.attributes[i].has_alias) {
            tmp_field->set_alias(select_sql.attributes[i].alias);
          }
          aggr_query_fields.emplace_back(*tmp_field);
          aggr_field_to_query_field_map[aggr_query_fields.size() - 1] =
              query_fields.size() - 1;

        } else {
          LOG_WARN("These aggr_func doesn't support \"*\".");
          return RC::AGGR_FUNC_NOT_VALID;
        }
      }

    } else if (!common::is_blank(relation_attr.relation_name.c_str())) {
      const char *table_name = relation_attr.relation_name.c_str();
      const char *field_name = relation_attr.attribute_name.c_str();

      if (0 == strcmp(table_name, "*")) {
        if (0 != strcmp(field_name, "*")) {
          // 对应 "*.attr"
          LOG_WARN("invalid field name while table is *. attr=%s", field_name);
          return RC::SCHEMA_FIELD_MISSING;
        }
        // 对应"*.*"
        for (Table *table : tables) {
          wildcard_fields(table, query_fields);
        }
        if (relation_attr.aggr_func_type != AggrFuncType::NONE) {
          // 对于聚合函数内部含有多列 应该返回错误
          LOG_WARN("Too many cols in aggr_func,cols is:%s.%s", table_name,
                   field_name);
          return RC::AGGR_FUNC_NOT_VALID;
        }

      } else {
        // 对应"rel.attr"或"rel.*"
        auto iter = table_map.find(table_name);
        if (iter == table_map.end()) {
          LOG_WARN("no such table in from list: %s", table_name);
          return RC::SCHEMA_FIELD_MISSING;
        }

        Table *table = iter->second;
        if (0 == strcmp(field_name, "*")) {
          wildcard_fields(table, query_fields);
          if (relation_attr.aggr_func_type != AggrFuncType::NONE) {
            // 对于聚合函数内部含有多列 应该返回错误
            LOG_WARN("Too many cols in aggr_func,cols is:%s.%s", table_name,
                     field_name);
            return RC::AGGR_FUNC_NOT_VALID;
          }

        } else {
          // 对应"rel.attr"
          const FieldMeta *field_meta = table->table_meta().field(field_name);
          if (nullptr == field_meta) {
            LOG_WARN("no such field. field=%s.%s.%s", db->name(), table->name(),
                     field_name);
            return RC::SCHEMA_FIELD_MISSING;
          }
          Field *tmp_field = new Field(table, field_meta);
          if (select_sql.attributes[i].has_alias) {
            tmp_field->set_alias(select_sql.attributes[i].alias);
            tmp_field->set_has_alias(true);

          } else if (table->has_alias()) {
            tmp_field->set_alias(table->get_alias() + "." + field_name);
            tmp_field->set_has_alias(true);
          }
          query_fields.emplace_back(*tmp_field);
          tmp_field->set_aggr_func_type(relation_attr.aggr_func_type);
          if (relation_attr.aggr_func_type != AggrFuncType::NONE) {
            tmp_field->set_alias(
                std::string(aggr_func_to_str(relation_attr.aggr_func_type)) +
                '(' + table_name + "." + field_name + ')');
            tmp_field->set_has_alias(true);

            if (select_sql.attributes[i].has_alias) {
              tmp_field->set_alias(select_sql.attributes[i].alias);
            } else if (table->has_alias()) {
              tmp_field->set_alias(
                  std::string(aggr_func_to_str(relation_attr.aggr_func_type)) +
                  '(' + table->get_alias() + "." + field_name + ')');
            }
            aggr_query_fields.emplace_back(*tmp_field);
            aggr_field_to_query_field_map[aggr_query_fields.size() - 1] =
                query_fields.size() - 1;
          }
        }
      }
    } else {
      // 对应 "attr" (没有表名)
      if (tables.size() != 1) {
        LOG_WARN("invalid. I do not know the attr's table. attr=%s",
                 relation_attr.attribute_name.c_str());
        return RC::SCHEMA_FIELD_MISSING;
      }

      Table *table = tables[0];
      const FieldMeta *field_meta =
          table->table_meta().field(relation_attr.attribute_name.c_str());
      if (nullptr == field_meta) {
        LOG_WARN("no such field. field=%s.%s.%s", db->name(), table->name(),
                 relation_attr.attribute_name.c_str());
        return RC::SCHEMA_FIELD_MISSING;
      }
      Field *tmp_field = new Field(table, field_meta);
      tmp_field->set_aggr_func_type(relation_attr.aggr_func_type);
      if (select_sql.attributes[i].has_alias) {
        tmp_field->set_alias(select_sql.attributes[i].alias);
        tmp_field->set_has_alias(true);
      }
      query_fields.emplace_back(*tmp_field);
      if (relation_attr.aggr_func_type != AggrFuncType::NONE) {
        tmp_field->set_alias(
            std::string(aggr_func_to_str(relation_attr.aggr_func_type)) + "(" +
            field_meta->name() + ")");
        tmp_field->set_has_alias(true);
        if (select_sql.attributes[i].has_alias) {
          tmp_field->set_alias(select_sql.attributes[i].alias);
        }
        aggr_query_fields.emplace_back(*tmp_field);
        aggr_field_to_query_field_map[aggr_query_fields.size() - 1] =
            query_fields.size() - 1;
      }
    }
  }

  LOG_INFO("got %d tables in from stmt and %d fields in query stmt",
           tables.size(), query_fields.size());

  // if (aggr_func_count != 0 && aggr_func_count !=
  // select_sql.attributes.size())
  //   return RC::AGGR_FUNC_NOT_VALID;

  Table *default_table = nullptr;
  if (tables.size() == 1) {
    default_table = tables[0];
  }

  // create filter statement in `where` statement
  FilterStmt *filter_stmt = nullptr;

  RC rc = FilterStmt::create(db, default_table, &table_map, conditions.data(),
                             static_cast<int>(conditions.size()), filter_stmt);
  if (rc != RC::SUCCESS) {
    LOG_WARN("cannot construct filter stmt");
    return rc;
  }

  // collect order by fields in 'order by' statement
  std::vector<Field> order_by_fields;
  std::vector<OrderByDirection> directions;

  for (int i = static_cast<int>(select_sql.order_by_sql_nodes.size()) - 1;
       i >= 0; i--) {
    const RelAttrSqlNode &relation_attr =
        select_sql.order_by_sql_nodes.at(i).rel_attr;
    OrderByDirection direction = select_sql.order_by_sql_nodes.at(i).direction;
    directions.emplace_back(direction);

    const char *table_name = relation_attr.relation_name.c_str();
    const char *field_name = relation_attr.attribute_name.c_str();

    if (common::is_blank(table_name) && 0 == strcmp(field_name, "*")) {
      LOG_WARN("Order by clause cannot process * columns.");
      return RC::INVALID_ARGUMENT;
    } else if (!common::is_blank(table_name)) {
      if (0 == strcmp(table_name, "*")) {
        LOG_WARN("Order by clause cannot process * columns.");
        return RC::INVALID_ARGUMENT;
      } else {
        // 对应"rel.attr"或"rel.*"
        auto iter = table_map.find(table_name);
        if (iter == table_map.end()) {
          LOG_WARN("no such table in from list: %s", table_name);
          return RC::SCHEMA_FIELD_MISSING;
        }
        Table *table = iter->second;

        if (0 == strcmp(field_name, "*")) {
          // 对应 rel.*
          LOG_WARN("Order by clause cannot process * columns.");
          return RC::INVALID_ARGUMENT;
        } else {
          // 对应"rel.attr"
          const FieldMeta *field_meta = table->table_meta().field(field_name);
          if (nullptr == field_meta) {
            LOG_WARN("no such field. field=%s.%s.%s", db->name(), table->name(),
                     field_name);
            return RC::SCHEMA_FIELD_MISSING;
          }
          Field *tmp_field = new Field(table, field_meta);
          order_by_fields.emplace_back(*tmp_field);
        }
      }
    } else {
      // 对应 "attr" (没有表名)
      if (tables.size() != 1) {
        LOG_WARN("invalid. I do not know the attr's table. attr=%s",
                 relation_attr.attribute_name.c_str());
        return RC::SCHEMA_FIELD_MISSING;
      }

      Table *table = tables[0];
      const FieldMeta *field_meta = table->table_meta().field(field_name);
      if (nullptr == field_meta) {
        LOG_WARN("no such field. field=%s.%s.%s", db->name(), table->name(),
                 relation_attr.attribute_name.c_str());
        return RC::SCHEMA_FIELD_MISSING;
      }
      Field *tmp_field = new Field(table, field_meta);
      order_by_fields.emplace_back(*tmp_field);
    }
  }
  // everything alright
  SelectStmt *select_stmt = new SelectStmt();
  // TODO add expression copy
  select_stmt->tables_.swap(tables);
  select_stmt->query_fields_.swap(query_fields);
  select_stmt->aggr_query_fields_.swap(aggr_query_fields);
  select_stmt->aggr_field_to_query_field_map_.swap(
      aggr_field_to_query_field_map);
  select_stmt->order_by_fields_.swap(order_by_fields);
  select_stmt->order_by_directions_.swap(directions);
  select_stmt->filter_stmt_ = filter_stmt;
  stmt = select_stmt;
  return RC::SUCCESS;
}
