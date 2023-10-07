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
// Created by WangYunlai on 2022/12/30.
//

#include "sql/operator/join_physical_operator.h"

NestedLoopJoinPhysicalOperator::NestedLoopJoinPhysicalOperator() {}

RC NestedLoopJoinPhysicalOperator::open(Trx *trx) {
  if (children_.size() != 2) {
    LOG_WARN("nlj operator should have 2 children");
    return RC::INTERNAL;
  }

  RC rc = RC::SUCCESS;
  left_ = children_[0].get();
  right_ = children_[1].get();
  right_closed_ = true;
  round_done_ = true;

  rc = left_->open(trx);
  trx_ = trx;
  return rc;
}

RC NestedLoopJoinPhysicalOperator::next() {
  RC rc = RC::SUCCESS;
  while (1) {
    bool left_need_step = (left_tuple_ == nullptr);
    if (round_done_) {
      left_need_step = true;
    } else {
      rc = right_next();
      if (rc != RC::SUCCESS) {
        if (rc == RC::RECORD_EOF) {
          left_need_step = true;
        } else {
          return rc;
        }
      } else {
        bool filter_result = true;
        rc = filter(joined_tuple_, filter_result);
        if (rc != RC::SUCCESS) {
          return rc;
        }

        if (!filter_result) {
          continue;
        }
        return rc;  // got one tuple from right
      }
    }

    if (left_need_step) {
      rc = left_next();
      if (rc != RC::SUCCESS) {
        return rc;
      }
    }

    rc = right_next();
    if (rc != RC::SUCCESS) {
      return rc;
    }

    bool filter_result = true;
    rc = filter(joined_tuple_, filter_result);
    if (rc != RC::SUCCESS) {
      return rc;
    }

    if (filter_result) {
      return rc;
    }
  }
  
}

RC NestedLoopJoinPhysicalOperator::close() {
  RC rc = left_->close();
  if (rc != RC::SUCCESS) {
    LOG_WARN("failed to close left oper. rc=%s", strrc(rc));
  }

  if (!right_closed_) {
    rc = right_->close();
    if (rc != RC::SUCCESS) {
      LOG_WARN("failed to close right oper. rc=%s", strrc(rc));
    } else {
      right_closed_ = true;
    }
  }
  return rc;
}

Tuple *NestedLoopJoinPhysicalOperator::current_tuple() {
  return &joined_tuple_;
}

void NestedLoopJoinPhysicalOperator::set_predicates(std::vector<std::unique_ptr<Expression>> &&exprs)
{
  predicates_ = std::move(exprs);
}

std::vector<std::unique_ptr<Expression>> &NestedLoopJoinPhysicalOperator::predicates()
{
  return predicates_;
}

RC NestedLoopJoinPhysicalOperator::filter(JoinedTuple &tuple, bool &result)
{
  RC rc = RC::SUCCESS;
  Value value;
  for (std::unique_ptr<Expression> &expr : predicates_) {
    rc = expr->get_value(tuple, value);
    if (rc != RC::SUCCESS) {
      return rc;
    }

    bool tmp_result = value.get_boolean();
    if (!tmp_result) {
      result = false;
      return rc;
    }
  }

  result = true;
  return rc;
}

RC NestedLoopJoinPhysicalOperator::left_next() {
  RC rc = RC::SUCCESS;
  rc = left_->next();
  if (rc != RC::SUCCESS) {
    return rc;
  }

  left_tuple_ = left_->current_tuple();
  joined_tuple_.set_left(left_tuple_);
  return rc;
}

RC NestedLoopJoinPhysicalOperator::right_next() {
  RC rc = RC::SUCCESS;
  if (round_done_) {
    if (!right_closed_) {
      rc = right_->close();
      right_closed_ = true;
      if (rc != RC::SUCCESS) {
        return rc;
      }
    }

    rc = right_->open(trx_);
    if (rc != RC::SUCCESS) {
      return rc;
    }
    right_closed_ = false;

    round_done_ = false;
  }

  rc = right_->next();
  if (rc != RC::SUCCESS) {
    if (rc == RC::RECORD_EOF) {
      round_done_ = true;
    }
    return rc;
  }

  right_tuple_ = right_->current_tuple();
  joined_tuple_.set_right(right_tuple_);
  return rc;
}

HashJoinPhysicalOperator::HashJoinPhysicalOperator() {}

RC HashJoinPhysicalOperator::open(Trx *trx) {
  if (children_.size() != 2) {
    LOG_WARN("hj operator should have 2 children");
    return RC::INTERNAL;
  }

  RC rc = RC::SUCCESS;
  left_ = children_[0].get();
  right_ = children_[1].get();
  round_done_ = true;

  rc = left_->open(trx);
  if (rc != RC::SUCCESS) {
    return rc;
  }
  rc = right_->open(trx);
  if (rc != RC::SUCCESS) {
    return rc;
  }
  trx_ = trx;
  // predeal rigth table, add to hash table
  // suppose the number of predicate is one.
  if (predicates_.size() > 1) {
    return RC::EXPRESSION_NOT_VALID;
  }
  ComparisonExpr *comp_expr = static_cast<ComparisonExpr *>(predicates_.front().get());
  if (comp_expr->left()->type() != ExprType::FIELD || comp_expr->right()->type() != ExprType::FIELD) {
    return RC::EXPRESSION_NOT_VALID;
  }
  FieldExpr *right_filed_expr = static_cast<FieldExpr *>(comp_expr->right().get());
  TupleCellSpec *tuple_cell_spec = new TupleCellSpec(right_filed_expr->table_name(), right_filed_expr->field_name());
  Value value;
  size_t hash;
  std::vector<Tuple*> empty_bucket;
  while((rc = right_->next()) == RC::SUCCESS) {
    right_tuple_ = right_->current_tuple()->clone();
    right_tuple_->find_cell(*tuple_cell_spec, value);
    hash = hasher(value.to_string());
    hash_table_[hash].emplace_back(right_tuple_);
  }
  if (rc == RC::RECORD_EOF) {
    return RC::SUCCESS;
  }
  return rc;
}

RC HashJoinPhysicalOperator::next() {
  RC rc = RC::SUCCESS;

  bool left_need_step = (left_tuple_ == nullptr);
  if (round_done_) {
    left_need_step = true;
  } else {
    rc = right_next();
    if (rc != RC::SUCCESS) {
      if (rc == RC::RECORD_EOF) {
        left_need_step = true;
      } else {
        return rc;
      }
    } else {
      return rc;  // got one tuple from right
    }
  }

  if (left_need_step) {
    while((rc = left_next()) != RC::SUCCESS) {
      if (rc == RC::VALUE_NOT_EXISTS) {
        continue;
      }
      else {
        return rc;
      }
    }
  }

  rc = right_next();
  if (rc != RC::SUCCESS) {
    return rc;
  }

  return rc;
}

RC HashJoinPhysicalOperator::close() {
  RC rc = left_->close();
  if (rc != RC::SUCCESS) {
    LOG_WARN("failed to close left oper. rc=%s", strrc(rc));
  }

  rc = right_->close();
  if (rc != RC::SUCCESS) {
    LOG_WARN("failed to close right oper. rc=%s", strrc(rc));
  }
  return rc;
}

Tuple *HashJoinPhysicalOperator::current_tuple() { return &joined_tuple_; }

void HashJoinPhysicalOperator::set_predicates(std::vector<std::unique_ptr<Expression>> &&exprs)
{
  predicates_ = std::move(exprs);
}

std::vector<std::unique_ptr<Expression>> &HashJoinPhysicalOperator::predicates()
{
  return predicates_;
}

RC HashJoinPhysicalOperator::left_next() {
  RC rc = RC::SUCCESS;
  rc = left_->next();
  if (rc != RC::SUCCESS) {
    return rc;
  }

  ComparisonExpr *comp_expr = static_cast<ComparisonExpr *>(predicates_.front().get());
  FieldExpr *left_filed_expr = static_cast<FieldExpr *>(comp_expr->left().get());
  TupleCellSpec *tuple_cell_spec = new TupleCellSpec(left_filed_expr->table_name(), left_filed_expr->field_name());
  Value value;
  size_t hash;
  left_tuple_ = left_->current_tuple();
  left_tuple_->find_cell(*tuple_cell_spec, value);
  if (value.attr_type() == AttrType::NULL_ATTR) {
    return RC::VALUE_NOT_EXISTS;
  }
  hash = hasher(value.to_string());
  if (!hash_table_.count(hash)) {
    return RC::VALUE_NOT_EXISTS;
  }
  current_bin_ = hash_table_[hash];
  joined_tuple_.set_left(left_tuple_);
  return rc;
}

RC HashJoinPhysicalOperator::right_next() {
  RC rc = RC::SUCCESS;
  if (round_done_) {
    iter_ = current_bin_.begin();
    if (iter_ == current_bin_.end()) {
      return RC::RECORD_EOF;
    }

    round_done_ = false;
    right_tuple_ = *iter_;
    joined_tuple_.set_right(right_tuple_);
    return rc;
  }

  iter_++;
  if (iter_ == current_bin_.end()) {
    rc = RC::RECORD_EOF;
    round_done_ = true;
    return rc;
  }

  right_tuple_ = *iter_;
  joined_tuple_.set_right(right_tuple_);
  return rc;
}