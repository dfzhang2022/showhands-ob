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
// Created by Wangyunlai on 2023/6/14.
//

#pragma once

#include "common/log/log.h"
#include "common/rc.h"
#include "event/session_event.h"
#include "event/sql_event.h"
#include "session/session.h"
#include "sql/executor/sql_result.h"
#include "sql/stmt/clear_table_stmt.h"
#include "storage/db/db.h"

/**
 * @brief Clear Table语句执行器
 * @ingroup Executor
 */
class ClearTableExecutor {
 public:
  ClearTableExecutor() = default;
  virtual ~ClearTableExecutor() = default;

  RC execute(SQLStageEvent *sql_event) {
    Stmt *stmt = sql_event->stmt();
    Session *session = sql_event->session_event()->session();
    ASSERT(stmt->type() == StmtType::CLEAR_TABLE,
           "clear table executor can not run this command: %d",
           static_cast<int>(stmt->type()));
    std::vector<std::string> table_names;

    session->get_current_db()->all_tables(table_names);
    RC rc = RC::SUCCESS;
    for (std::string table_name : table_names) {
      rc = session->get_current_db()->drop_table(table_name.c_str());
      if (rc != RC::SUCCESS) {
        LOG_ERROR("Error occurs when dropping table %s.", table_name.c_str());
        return rc;
      }
    }
    return RC::SUCCESS;
  }
};