
%{

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

#include "common/log/log.h"
#include "common/lang/string.h"
#include "sql/parser/parse_defs.h"
#include "sql/parser/yacc_sql.hpp"
#include "sql/parser/lex_sql.h"
#include "sql/expr/expression.h"

using namespace std;

string token_name(const char *sql_string, YYLTYPE *llocp)
{
  return string(sql_string + llocp->first_column, llocp->last_column - llocp->first_column + 1);
}

int yyerror(YYLTYPE *llocp, const char *sql_string, ParsedSqlResult *sql_result, yyscan_t scanner, const char *msg)
{
  std::unique_ptr<ParsedSqlNode> error_sql_node = std::make_unique<ParsedSqlNode>(SCF_ERROR);
  error_sql_node->error.error_msg = msg;
  error_sql_node->error.line = llocp->first_line;
  error_sql_node->error.column = llocp->first_column;
  sql_result->add_sql_node(std::move(error_sql_node));
  return 0;
}

ArithmeticExpr *create_arithmetic_expression(ArithmeticExpr::Type type,
                                             Expression *left,
                                             Expression *right,
                                             const char *sql_string,
                                             YYLTYPE *llocp)
{
  ArithmeticExpr *expr = new ArithmeticExpr(type, left, right);
  expr->set_name(token_name(sql_string, llocp));
  return expr;
}

%}

%define api.pure full
%define parse.error verbose
/** 启用位置标识 **/
%locations
%lex-param { yyscan_t scanner }
/** 这些定义了在yyparse函数中的参数 **/
%parse-param { const char * sql_string }
%parse-param { ParsedSqlResult * sql_result }
%parse-param { void * scanner }

//标识tokens
%token  SEMICOLON
        CREATE
        DROP
        TABLE
        TABLES
        UNIQUE
        INDEX
        CALC
        SELECT
        DESC
        ASC
        SHOW
        SYNC
        INSERT
        DELETE
        UPDATE
        LBRACE
        RBRACE
        COMMA
        TRX_BEGIN
        TRX_COMMIT
        TRX_ROLLBACK
        INT_T
        STRING_T
        FLOAT_T
        DATE_T
        HELP
        EXIT
        DOT 
        QUOTE
        INTO
        VALUES
        FROM
        INNER
        JOIN
        WHERE
        AND
        ORDER
        GROUP
        BY
        SET
        ON
        LIKE_MARK
        NOT
        LOAD
        DATA
        INFILE
        EXPLAIN
        CLEAR
        IS
        IN
        AS 
        NULL_T
        NULLABLE
        CNT_FUNC
        MAX_FUNC
        MIN_FUNC
        AVG_FUNC
        SUM_FUNC
        EQ
        LT
        GT
        LE
        GE
        NE

/** union 中定义各种数据类型，真实生成的代码也是union类型，所以不能有非POD类型的数据 **/
%union {
  ParsedSqlNode *                   sql_node;
  ConditionSqlNode *                condition;
  Value *                           value;
  enum CompOp                       comp;
  enum AggrFuncType                 aggr_func;
  RelAttrSqlNode *                  rel_attr;
  std::vector<AttrInfoSqlNode> *    attr_infos;
  AttrInfoSqlNode *                 attr_info;
  UpdateValueSqlNode*               update_value;
  std::vector<UpdateValueSqlNode> * update_value_list;
  InsertValueSqlNode*               insert_value;
  std::vector<InsertValueSqlNode> * insert_value_list;
  Expression *                      expression;
  std::vector<Expression *> *       expression_list;
  OrderBySqlNode*                   order;
  std::vector<OrderBySqlNode> *     order_list;
  std::vector<Value> *              value_list;
  std::vector<ConditionSqlNode> *   condition_list;
  std::vector<RelAttrSqlNode> *     rel_attr_list;
  std::vector<RelationSqlNode> *    relation_list;
  RelationSqlNode*                  relation;
  JoinedRelationSqlNode*            join_rel;
  std::vector<JoinedRelationSqlNode>* join_rel_list;
  char *                            string;
  int                               number;
  float                             floats;
}

%token <number> NUMBER
%token <floats> FLOAT
%token <string> ID
%token <string> DATE_STR
%token <string> SSS
//非终结符

/** type 定义了各种解析后的结果输出的是什么类型。类型对应了 union 中的定义的成员变量名称 **/
%type <number>              type
%type <condition>           condition
%type <value>               value
%type <number>              number
%type <comp>                comp_op
%type <number>              null_or_nullable
%type <string>              as_alias
%type <rel_attr>            rel_attr
%type <attr_infos>          attr_def_list
%type <attr_info>           attr_def
%type <value_list>          value_list
%type <condition_list>      where
%type <condition_list>      condition_list
%type <rel_attr_list>       select_attr
%type <relation_list>       rel_list
%type <relation>            rel_element
%type <join_rel>            join_relation
%type <join_rel>            inner_join
%type <join_rel>            inner_join_list
%type <rel_attr_list>       attr_list
%type <update_value>        set_value
%type <update_value_list>   set_value_list
%type <insert_value>        insert_value
%type <insert_value_list>   insert_value_list
%type <expression>          expression
%type <expression_list>     expression_list
%type <order_list>          order_by
%type <order>               order
%type <order_list>          order_list
%type <aggr_func>           aggregation_func
%type <sql_node>            calc_stmt
%type <sql_node>            select_stmt
%type <sql_node>            insert_stmt
%type <sql_node>            update_stmt
%type <sql_node>            delete_stmt
%type <sql_node>            create_table_stmt
%type <sql_node>            drop_table_stmt
%type <sql_node>            show_tables_stmt
%type <sql_node>            show_index_stmt
%type <sql_node>            desc_table_stmt
%type <sql_node>            create_index_stmt
%type <sql_node>            drop_index_stmt
%type <sql_node>            sync_stmt
%type <sql_node>            begin_stmt
%type <sql_node>            commit_stmt
%type <sql_node>            rollback_stmt
%type <sql_node>            load_data_stmt
%type <sql_node>            explain_stmt
%type <sql_node>            clear_table_stmt
%type <sql_node>            set_variable_stmt
%type <sql_node>            help_stmt
%type <sql_node>            exit_stmt
%type <sql_node>            command_wrapper
// commands should be a list but I use a single command instead
%type <sql_node>            commands

%left '+' '-'
%left '*' '/'
%nonassoc UMINUS
%%

commands: command_wrapper opt_semicolon  //commands or sqls. parser starts here.
  {
    std::unique_ptr<ParsedSqlNode> sql_node = std::unique_ptr<ParsedSqlNode>($1);
    sql_result->add_sql_node(std::move(sql_node));
  }
  ;

command_wrapper:
    calc_stmt
  | select_stmt
  | insert_stmt
  | update_stmt
  | delete_stmt
  | create_table_stmt
  | drop_table_stmt
  | show_tables_stmt
  | show_index_stmt
  | desc_table_stmt
  | create_index_stmt
  | drop_index_stmt
  | sync_stmt
  | begin_stmt
  | commit_stmt
  | rollback_stmt
  | load_data_stmt
  | explain_stmt
  | set_variable_stmt
  | help_stmt
  | exit_stmt
  | clear_table_stmt
    ;

exit_stmt:      
    EXIT {
      (void)yynerrs;  // 这么写为了消除yynerrs未使用的告警。如果你有更好的方法欢迎提PR
      $$ = new ParsedSqlNode(SCF_EXIT);
    };

help_stmt:
    HELP {
      $$ = new ParsedSqlNode(SCF_HELP);
    };

sync_stmt:
    SYNC {
      $$ = new ParsedSqlNode(SCF_SYNC);
    }
    ;

begin_stmt:
    TRX_BEGIN  {
      $$ = new ParsedSqlNode(SCF_BEGIN);
    }
    ;

commit_stmt:
    TRX_COMMIT {
      $$ = new ParsedSqlNode(SCF_COMMIT);
    }
    ;

rollback_stmt:
    TRX_ROLLBACK  {
      $$ = new ParsedSqlNode(SCF_ROLLBACK);
    }
    ;

drop_table_stmt:    /*drop table 语句的语法解析树*/
    DROP TABLE ID {
      $$ = new ParsedSqlNode(SCF_DROP_TABLE);
      $$->drop_table.relation_name = $3;
      free($3);
    };
clear_table_stmt:    /* clear table 语法解析树 */
    CLEAR TABLE{
      $$ = new ParsedSqlNode(SCF_CLEAR_TABLE);
    };

show_tables_stmt:
    SHOW TABLES {
      $$ = new ParsedSqlNode(SCF_SHOW_TABLES);
    }
    ;
show_index_stmt:
    SHOW INDEX FROM ID{
      $$ = new ParsedSqlNode(SCF_SHOW_INDEX);
      $$->show_index.relation_name = $4;
      free($4);
    }
    ;

desc_table_stmt:
    DESC ID  {
      $$ = new ParsedSqlNode(SCF_DESC_TABLE);
      $$->desc_table.relation_name = $2;
      free($2);
    }
    ;

create_index_stmt:    /*create index 语句的语法解析树*/
    CREATE INDEX ID ON ID LBRACE ID RBRACE
    {
      $$ = new ParsedSqlNode(SCF_CREATE_INDEX);
      CreateIndexSqlNode &create_index = $$->create_index;
      create_index.is_unique = false;
      create_index.index_name = $3;
      create_index.relation_name = $5;
      create_index.attribute_name = $7;
      free($3);
      free($5);
      free($7);
    }
    | CREATE UNIQUE INDEX ID ON ID LBRACE ID RBRACE
    {
      $$ = new ParsedSqlNode(SCF_CREATE_INDEX);
      CreateIndexSqlNode &create_index = $$->create_index;
      create_index.is_unique = true;
      create_index.index_name = $4;
      create_index.relation_name = $6;
      create_index.attribute_name = $8;
      free($4);
      free($6);
      free($8);
    }
    ;

drop_index_stmt:      /*drop index 语句的语法解析树*/
    DROP INDEX ID ON ID
    {
      $$ = new ParsedSqlNode(SCF_DROP_INDEX);
      $$->drop_index.index_name = $3;
      $$->drop_index.relation_name = $5;
      free($3);
      free($5);
    }
    ;
create_table_stmt:    /*create table 语句的语法解析树*/
    CREATE TABLE ID LBRACE attr_def attr_def_list RBRACE
    {
      $$ = new ParsedSqlNode(SCF_CREATE_TABLE);
      CreateTableSqlNode &create_table = $$->create_table;
      create_table.relation_name = $3;
      free($3);

      std::vector<AttrInfoSqlNode> *src_attrs = $6;

      if (src_attrs != nullptr) {
        create_table.attr_infos.swap(*src_attrs);
      }
      create_table.attr_infos.emplace_back(*$5);
      std::reverse(create_table.attr_infos.begin(), create_table.attr_infos.end());
      delete $5;
    }
    ;
attr_def_list:
    /* empty */
    {
      $$ = nullptr;
    }
    | COMMA attr_def attr_def_list
    {
      if ($3 != nullptr) {
        $$ = $3;
      } else {
        $$ = new std::vector<AttrInfoSqlNode>;
      }
      $$->emplace_back(*$2);
      delete $2;
    }
    ;
    
attr_def:
    ID type LBRACE number RBRACE 
    {
      $$ = new AttrInfoSqlNode;
      $$->type = (AttrType)$2;
      $$->name = $1;
      $$->length = $4;
      $$->nullable = false;
      free($1);
    }
    | ID type
    {
      $$ = new AttrInfoSqlNode;
      $$->type = (AttrType)$2;
      $$->name = $1;
      $$->length = 4;
      $$->nullable = false;
      free($1);
    }
    |ID type LBRACE number RBRACE NULLABLE
    {
      $$ = new AttrInfoSqlNode;
      $$->type = (AttrType)$2;
      $$->name = $1;
      $$->length = $4;
      $$->nullable = true;
      free($1);
    }
    | ID type NULLABLE
    {
      $$ = new AttrInfoSqlNode;
      $$->type = (AttrType)$2;
      $$->name = $1;
      $$->length = 4;
      $$->nullable = true;
      free($1);
    }
    |ID type LBRACE number RBRACE NOT NULL_T
    {
      $$ = new AttrInfoSqlNode;
      $$->type = (AttrType)$2;
      $$->name = $1;
      $$->length = $4;
      $$->nullable = false;
      free($1);
    }
    | ID type NOT NULL_T
    {
      $$ = new AttrInfoSqlNode;
      $$->type = (AttrType)$2;
      $$->name = $1;
      $$->length = 4;
      $$->nullable = false;
      free($1);
    }
    ;
number:
    NUMBER {$$ = $1;}
    ;
type:
    INT_T      { $$=INTS; }
    | STRING_T { $$=CHARS; }
    | FLOAT_T  { $$=FLOATS; }
    | DATE_T    { $$=DATES;}
    ;
insert_stmt:        /*insert   语句的语法解析树*/
    INSERT INTO ID VALUES insert_value insert_value_list
    {
      $$ = new ParsedSqlNode(SCF_INSERT);
      $$->insertion.relation_name = $3;
      free($3);

      std::vector<InsertValueSqlNode> *src_insertv = $6;
      if (src_insertv != nullptr) {
        $$->insertion.insert_values.swap(*src_insertv);
      }
      $$->insertion.insert_values.emplace_back(*$5);
      std::reverse($$->insertion.insert_values.begin(), $$->insertion.insert_values.end());
      delete $5;
      
    }
    ;
insert_value_list:
    /* empty */
    {
      $$ = nullptr;
    }
    |COMMA insert_value insert_value_list
    {
      if ($3 != nullptr) {
        $$ = $3;
      } else {
        $$ = new std::vector<InsertValueSqlNode>;
      }
      $$->emplace_back(*$2);
      delete $2;
    }
    ;
insert_value:
    LBRACE value value_list RBRACE
    {
        $$ = new InsertValueSqlNode;
        if($3 != nullptr){
          $$->values.swap(*$3);
        }
        $$->values.emplace_back(*$2);
        std::reverse($$->values.begin(),$$->values.end());
        delete $2;
    }
    ;


value_list:
    /* empty */
    {
      $$ = nullptr;
    }
    | COMMA value value_list  { 
      if ($3 != nullptr) {
        $$ = $3;
      } else {
        $$ = new std::vector<Value>;
      }
      $$->emplace_back(*$2);
      delete $2;
    }
    ;
value:
    NUMBER {
      $$ = new Value((int)$1);
      @$ = @1;
    }
    |FLOAT {
      $$ = new Value((float)$1);
      @$ = @1;
    }
    | DATE_STR {
      char *tmp = common::substr($1,1,strlen($1)-2);
      int y, m, d;
      sscanf(tmp, "%d-%d-%d", &y, &m, &d);


      $$ = new Value(y,m,d);

      
    }
    |SSS {
      char *tmp = common::substr($1,1,strlen($1)-2);
      $$ = new Value(tmp);
      free(tmp);
    }
    |null_or_nullable{
      $$ = new Value(0);
      
      $$->set_null(nullptr,4);
      
      
    }
    
    ;
    
delete_stmt:    /*  delete 语句的语法解析树*/
    DELETE FROM ID where 
    {
      $$ = new ParsedSqlNode(SCF_DELETE);
      $$->deletion.relation_name = $3;
      if ($4 != nullptr) {
        $$->deletion.conditions.swap(*$4);
        delete $4;
      }
      free($3);
    }
    ;
update_stmt:      /*  update 语句的语法解析树*/
    UPDATE ID SET set_value set_value_list where 
    {
      $$ = new ParsedSqlNode(SCF_UPDATE);
      $$->update.relation_name = $2;

      std::vector<UpdateValueSqlNode> *src_update_values = $5;
      if (src_update_values != nullptr) {
        $$->update.update_values.swap(*src_update_values);
      }
      $$->update.update_values.emplace_back(*$4);
      std::reverse($$->update.update_values.begin(),$$->update.update_values.end());
      delete $4;
      if ($6 != nullptr) {
        $$->update.conditions.swap(*$6);
        delete $6;
      }
    }
    ;
set_value_list:
    /* empty */
    {
      $$ = nullptr;
    }
    |COMMA set_value set_value_list{
      if ($3 != nullptr) {
        $$ = $3;
      } else {
        $$ = new std::vector<UpdateValueSqlNode>;
      }
      $$->emplace_back(*$2);
      delete $2;

    }
    ;
set_value:
    ID EQ value
    {
      $$ = new UpdateValueSqlNode;
      $$->name = $1;
      $$->value = *$3;

      delete $1;
      delete $3;
    }
    | ID EQ LBRACE select_stmt RBRACE
    {
      $$ = new UpdateValueSqlNode;
      $$->name = $1;
      $$->select_sql_node =  $4->selection;
      $$->is_right_selects = true;

      delete $1;
      delete $4;
    }
    ;
select_stmt:        /*  select 语句的语法解析树*/
    SELECT select_attr FROM rel_list where order_by
    {
      $$ = new ParsedSqlNode(SCF_SELECT);
      if ($2 != nullptr) {
        $$->selection.attributes.swap(*$2);
        delete $2;
      }
     
      $$->selection.relations.swap(*$4);
      // delete $4;
      
      std::reverse($$->selection.relations.begin(), $$->selection.relations.end());

      if ($5 != nullptr) {
        $$->selection.conditions.swap(*$5);
        delete $5;
      }
      if ($6 != nullptr) {
        $$->selection.order_by_sql_nodes.swap(*$6);
        delete $6;
      }
      // free($4);
    }
    ;
calc_stmt:
    CALC expression_list
    {
      $$ = new ParsedSqlNode(SCF_CALC);
      std::reverse($2->begin(), $2->end());
      $$->calc.expressions.swap(*$2);
      delete $2;
    }
    ;

expression_list:
    expression
    {
      $$ = new std::vector<Expression*>;
      $$->emplace_back($1);
    }
    | expression COMMA expression_list
    {
      if ($3 != nullptr) {
        $$ = $3;
      } else {
        $$ = new std::vector<Expression *>;
      }
      $$->emplace_back($1);
    }
    ;
expression:
    expression '+' expression {
      $$ = create_arithmetic_expression(ArithmeticExpr::Type::ADD, $1, $3, sql_string, &@$);
    }
    | expression '-' expression {
      $$ = create_arithmetic_expression(ArithmeticExpr::Type::SUB, $1, $3, sql_string, &@$);
    }
    | expression '*' expression {
      $$ = create_arithmetic_expression(ArithmeticExpr::Type::MUL, $1, $3, sql_string, &@$);
    }
    | expression '/' expression {
      $$ = create_arithmetic_expression(ArithmeticExpr::Type::DIV, $1, $3, sql_string, &@$);
    }
    | LBRACE expression RBRACE {
      $$ = $2;
      $$->set_name(token_name(sql_string, &@$));
    }
    | '-' expression %prec UMINUS {
      $$ = create_arithmetic_expression(ArithmeticExpr::Type::NEGATIVE, $2, nullptr, sql_string, &@$);
    }
    | value {
      $$ = new ValueExpr(*$1);
      $$->set_name(token_name(sql_string, &@$));
      delete $1;
    }
    ;

select_attr:
    '*' attr_list {
      if($2 != nullptr){
        $$ = $2;
      } else {
        $$ = new std::vector<RelAttrSqlNode>;
      }
      RelAttrSqlNode attr;
      attr.relation_name  = "";
      attr.attribute_name = "*";
      $$->emplace_back(attr);
    }
    | rel_attr attr_list {
      if ($2 != nullptr) {
        $$ = $2;
      } else {
        $$ = new std::vector<RelAttrSqlNode>;
      }
      $$->emplace_back(*$1);
      delete $1;
    }
    ; 
aggregation_func:
    MAX_FUNC{
      $$ = MAX;
    }
    | MIN_FUNC{
      $$ = MIN;
    }
    | CNT_FUNC{
      $$ = CNT;
    }
    | AVG_FUNC{
      $$ = AVG;
    }
    | SUM_FUNC{
      $$ = SUM;
    }
    ;

rel_attr:
    ID as_alias{
      $$ = new RelAttrSqlNode;
      $$->attribute_name = $1;
      free($1);

     
      if($2 !=nullptr){
        $$->has_alias = true;
        $$->alias = $2;
        free($2);
      }
    }
    | ID DOT ID as_alias{
      $$ = new RelAttrSqlNode;
      $$->relation_name  = $1;
      $$->attribute_name = $3;
      free($1);
      free($3);
      

      if($4 !=nullptr){
        $$->has_alias = true;
        $$->alias = $4;
        free($4);
      }
    }
    | aggregation_func LBRACE ID RBRACE{
      $$ = new RelAttrSqlNode;
      $$->attribute_name = $3;
      free($3);
      $$->is_aggregation_func = true;
      $$->aggr_func_type = $1;

    }
    | aggregation_func LBRACE ID DOT ID RBRACE{
      $$ = new RelAttrSqlNode;
      $$->relation_name  = $3;
      $$->attribute_name = $5;
      free($3);
      free($5);
      $$->is_aggregation_func = true;
      $$->aggr_func_type = $1;

    }
    | aggregation_func LBRACE '*' RBRACE{
      $$ = new RelAttrSqlNode;
      $$->relation_name = "";
      $$->attribute_name = "*";
      $$->is_aggregation_func = true;
      $$->aggr_func_type = $1;

    }
    | aggregation_func LBRACE RBRACE{
      $$ = new RelAttrSqlNode;
      $$->is_syntax_error = true;
      $$->aggr_func_type = $1;

    }
    | aggregation_func LBRACE rel_attr COMMA rel_attr attr_list RBRACE{
      $$ = new RelAttrSqlNode;
      $$->is_syntax_error = true;
      delete $3;
      delete $5;
      delete $6;

    }
    | aggregation_func LBRACE '*' COMMA rel_attr attr_list RBRACE{
      $$ = new RelAttrSqlNode;
      $$->is_syntax_error = true;
      delete $5;
      delete $6;

    }
    ;
as_alias:
    /* empty */
    {
      $$ = nullptr;
    }
    | AS ID{
      $$ = (char*)malloc(strlen($2)+1);
      strcpy($$,$2);
      free($2);
    }
    | AS ID DOT ID{
      $$ = (char*)malloc(strlen($2)+strlen($4)+2);
      strcpy($$,$2);
      strcpy($$+strlen($2),".");
      strcpy($$+strlen($2)+1,$4);
      free($2);
      free($4);
    }
    ;
attr_list:
    /* empty */
    {
      $$ = nullptr;
    }
    | COMMA rel_attr attr_list {
      if ($3 != nullptr) {
        $$ = $3;
      } else {
        $$ = new std::vector<RelAttrSqlNode>;
      }

      $$->emplace_back(*$2);
      delete $2;
    }
    ;

inner_join:
    INNER JOIN ID ON condition_list
    {
        $$ = new JoinedRelationSqlNode;
        $$->relations.push_back($3);
        for(auto iter:*$5){
          $$->join_on_conditions.emplace_back(iter);
        }
        // free($3);
    }
    ;
inner_join_list:
    {
      $$ = nullptr;
    }
    | inner_join inner_join_list
    {
      if($2!=nullptr){
        $$ = $2;
      }else {
        $$ = new JoinedRelationSqlNode;
      }
      for(auto iter : $1->relations){
        $$->relations.emplace_back(iter);
      }
      for(auto iter : $1->join_on_conditions){
        $$->join_on_conditions.emplace_back(iter);
      }
      // free($1);
    }
    ;
join_relation:
    ID inner_join inner_join_list
    {
      if($3!=nullptr){
        $$ = $3;
      }else{
        $$ = new JoinedRelationSqlNode;
      }
      for(auto iter : $2->relations){
        $$->relations.emplace_back(iter);
      }
      // $$->relations.insert($$->relations.end(), $2->relations.begin(), $2->relations.end());
      $$->join_on_conditions.insert($$->join_on_conditions.end(), $2->join_on_conditions.begin(), $2->join_on_conditions.end());
      // for(auto iter : $2->relations){
      //   $$->relations.emplace_back(iter);
      // }
      // for(auto iter : $2->join_on_conditions){
      //   $$->join_on_conditions.emplace_back(iter);
      // }
      $$->relations.push_back($1);
      std::reverse($$->relations.begin(), $$->relations.end());
      std::reverse($$->join_on_conditions.begin(), $$->join_on_conditions.end());
      // free($1);

    }
    ;

rel_element:
    ID as_alias
    {
      $$ = new RelationSqlNode;
      $$ -> relation = $1;
      $$ -> has_inner_join = false;
      free($1);

      
      if($2 !=nullptr){
        $$->alias = $2;
        $$->has_alias = true;
        free($2);
      }

    }
    |join_relation 
    {
      $$ = new RelationSqlNode;
      $$->inner_join_sql_node = *$1;
      $$ -> has_inner_join = true;
      // delete $1;

    }
    ;

rel_list:
    rel_element
    { 
      $$ = new std::vector<RelationSqlNode>;
      $$->emplace_back(*$1);
      // delete $1;
    }
    |rel_element COMMA  rel_list {
      $$ = $3;
      $$->emplace_back(*$1);
      // delete $1;
    }
    ;
where:
    /* empty */
    {
      $$ = nullptr;
    }
    | WHERE condition_list {
      $$ = $2;  
    }
    ;
condition_list:
    /* empty */
    {
      $$ = nullptr;
    }
    | condition {
      $$ = new std::vector<ConditionSqlNode>;
      $$->emplace_back(*$1);
      delete $1;
    }
    | condition AND condition_list {
      $$ = $3;
      $$->emplace_back(*$1);
      delete $1;
    }
    ;
condition:
    rel_attr comp_op value
    {
      $$ = new ConditionSqlNode;
      $$->left_is_attr = 1;
      $$->left_attr = *$1;
      $$->right_is_attr = 0;
      $$->right_value = *$3;
      $$->comp = $2;

      delete $1;
      delete $3;
    }
    | value comp_op value 
    {
      $$ = new ConditionSqlNode;
      $$->left_is_attr = 0;
      $$->left_value = *$1;
      $$->right_is_attr = 0;
      $$->right_value = *$3;
      $$->comp = $2;

      delete $1;
      delete $3;
    }
    | rel_attr comp_op rel_attr
    {
      $$ = new ConditionSqlNode;
      $$->left_is_attr = 1;
      $$->left_attr = *$1;
      $$->right_is_attr = 1;
      $$->right_attr = *$3;
      $$->comp = $2;

      delete $1;
      delete $3;
    }
    | value comp_op rel_attr
    {
      $$ = new ConditionSqlNode;
      $$->left_is_attr = 0;
      $$->left_value = *$1;
      $$->right_is_attr = 1;
      $$->right_attr = *$3;
      $$->comp = $2;

      delete $1;
      delete $3;
    }
    | value comp_op LBRACE select_stmt RBRACE
    {
      $$ = new ConditionSqlNode;
      $$->left_is_attr = 0;
      $$->left_value = *$1;
      $$->right_is_attr =2;
      // $$->right_selects = static_cast<SelectSqlNode*>($4);
      $$->comp = $2;

      delete $1;
      // delete $4;
    }
    | rel_attr comp_op LBRACE select_stmt RBRACE
    {
      $$ = new ConditionSqlNode;
      $$->left_is_attr = 1;
      $$->left_attr = *$1;
      $$->right_is_attr = 2;
      // $$->right_selects = static_cast<SelectSqlNode*>($4);
      $$->comp = $2;

      delete $1;
      // delete $4;
    }
    | LBRACE select_stmt RBRACE comp_op  value
    {
      $$ = new ConditionSqlNode;
      $$->left_is_attr = 2;
      // $$->left_selects = static_cast<SelectSqlNode*>($2);
      $$->right_is_attr =0;
      $$->right_value = *$5;
      $$->comp = $4;

      // delete $2;
      delete $5;
    }
    | LBRACE select_stmt RBRACE comp_op rel_attr
    {
      $$ = new ConditionSqlNode;
      $$->left_is_attr = 2;
      // $$->left_selects = static_cast<SelectSqlNode*>($2);
      $$->right_is_attr = 1;
      $$->right_attr = *$5;
      $$->comp = $4;

      // delete $2;
      delete $5;
    }
    ;
order_by:
    /* empty */
    {
      $$ = nullptr;
    }
    | ORDER BY order_list {
      $$ = $3;
    }
    ;
order:
    rel_attr {
      $$ = new OrderBySqlNode;
      $$->rel_attr = *$1;
      $$->direction = OrderByDirection::ASC_ORDER;
    }
    |rel_attr DESC {
      $$ = new OrderBySqlNode;
      $$->rel_attr = *$1;
      $$->direction = OrderByDirection::DESC_ORDER;
    }
    |rel_attr ASC {
      $$ = new OrderBySqlNode;
      $$->rel_attr = *$1;
      $$->direction = OrderByDirection::ASC_ORDER;
    }
    ;
order_list:
    /* empty */
    {
      $$ = nullptr;
    }
    | order{
        $$ = new std::vector<OrderBySqlNode>;
        $$->emplace_back(*$1);
        delete $1;
    }
    | order COMMA order_list{
      $$ = $3;
      $$->emplace_back(*$1);
      delete $1;
    }

null_or_nullable:
    NULL_T
    {
      $$ = 1;
    }
    |NULLABLE
    {
      $$ = 1;
    }
    ;

comp_op:
      EQ { $$ = EQUAL_TO; }
    | LT { $$ = LESS_THAN; }
    | GT { $$ = GREAT_THAN; }
    | LE { $$ = LESS_EQUAL; }
    | GE { $$ = GREAT_EQUAL; }
    | NE { $$ = NOT_EQUAL; }
    | IS { $$ = IS_EQUAL;}
    | IS NOT{$$ = IS_NOT_EQUAL;}
    | LIKE_MARK {$$ = LIKE;}
    | NOT LIKE_MARK {$$ = NOT_LIKE;}
    ;

load_data_stmt:
    LOAD DATA INFILE SSS INTO TABLE ID 
    {
      char *tmp_file_name = common::substr($4, 1, strlen($4) - 2);
      
      $$ = new ParsedSqlNode(SCF_LOAD_DATA);
      $$->load_data.relation_name = $7;
      $$->load_data.file_name = tmp_file_name;
      free($7);
      free(tmp_file_name);
    }
    ;

explain_stmt:
    EXPLAIN command_wrapper
    {
      $$ = new ParsedSqlNode(SCF_EXPLAIN);
      $$->explain.sql_node = std::unique_ptr<ParsedSqlNode>($2);
    }
    ;

set_variable_stmt:
    SET ID EQ value
    {
      $$ = new ParsedSqlNode(SCF_SET_VARIABLE);
      $$->set_variable.name  = $2;
      $$->set_variable.value = *$4;
      free($2);
      delete $4;
    }
    ;

opt_semicolon: /*empty*/
    | SEMICOLON
    ;
%%
//_____________________________________________________________________
extern void scan_string(const char *str, yyscan_t scanner);

int sql_parse(const char *s, ParsedSqlResult *sql_result) {
  yyscan_t scanner;
  yylex_init(&scanner);
  scan_string(s, scanner);
  int result = yyparse(s, sql_result, scanner);
  yylex_destroy(scanner);
  return result;
}
