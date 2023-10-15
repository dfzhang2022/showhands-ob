/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_YACC_SQL_HPP_INCLUDED
# define YY_YY_YACC_SQL_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    SEMICOLON = 258,               /* SEMICOLON  */
    CREATE = 259,                  /* CREATE  */
    DROP = 260,                    /* DROP  */
    TABLE = 261,                   /* TABLE  */
    TABLES = 262,                  /* TABLES  */
    UNIQUE = 263,                  /* UNIQUE  */
    INDEX = 264,                   /* INDEX  */
    CALC = 265,                    /* CALC  */
    SELECT = 266,                  /* SELECT  */
    DESC = 267,                    /* DESC  */
    ASC = 268,                     /* ASC  */
    SHOW = 269,                    /* SHOW  */
    SYNC = 270,                    /* SYNC  */
    INSERT = 271,                  /* INSERT  */
    DELETE = 272,                  /* DELETE  */
    UPDATE = 273,                  /* UPDATE  */
    LBRACE = 274,                  /* LBRACE  */
    RBRACE = 275,                  /* RBRACE  */
    COMMA = 276,                   /* COMMA  */
    TRX_BEGIN = 277,               /* TRX_BEGIN  */
    TRX_COMMIT = 278,              /* TRX_COMMIT  */
    TRX_ROLLBACK = 279,            /* TRX_ROLLBACK  */
    INT_T = 280,                   /* INT_T  */
    STRING_T = 281,                /* STRING_T  */
    FLOAT_T = 282,                 /* FLOAT_T  */
    DATE_T = 283,                  /* DATE_T  */
    TEXT_T = 284,                  /* TEXT_T  */
    HELP = 285,                    /* HELP  */
    EXIT = 286,                    /* EXIT  */
    DOT = 287,                     /* DOT  */
    QUOTE = 288,                   /* QUOTE  */
    INTO = 289,                    /* INTO  */
    VALUES = 290,                  /* VALUES  */
    FROM = 291,                    /* FROM  */
    INNER = 292,                   /* INNER  */
    JOIN = 293,                    /* JOIN  */
    WHERE = 294,                   /* WHERE  */
    AND = 295,                     /* AND  */
    OR = 296,                      /* OR  */
    EXISTS = 297,                  /* EXISTS  */
    ORDER = 298,                   /* ORDER  */
    GROUP = 299,                   /* GROUP  */
    BY = 300,                      /* BY  */
    HAVING = 301,                  /* HAVING  */
    SET = 302,                     /* SET  */
    ON = 303,                      /* ON  */
    LIKE_MARK = 304,               /* LIKE_MARK  */
    NOT = 305,                     /* NOT  */
    LOAD = 306,                    /* LOAD  */
    DATA = 307,                    /* DATA  */
    INFILE = 308,                  /* INFILE  */
    EXPLAIN = 309,                 /* EXPLAIN  */
    CLEAR = 310,                   /* CLEAR  */
    IS = 311,                      /* IS  */
    IN = 312,                      /* IN  */
    AS = 313,                      /* AS  */
    NULL_T = 314,                  /* NULL_T  */
    NULLABLE = 315,                /* NULLABLE  */
    CNT_FUNC = 316,                /* CNT_FUNC  */
    MAX_FUNC = 317,                /* MAX_FUNC  */
    MIN_FUNC = 318,                /* MIN_FUNC  */
    AVG_FUNC = 319,                /* AVG_FUNC  */
    SUM_FUNC = 320,                /* SUM_FUNC  */
    ROUND = 321,                   /* ROUND  */
    LENGTH = 322,                  /* LENGTH  */
    DATE_FORMAT = 323,             /* DATE_FORMAT  */
    EQ = 324,                      /* EQ  */
    LT = 325,                      /* LT  */
    GT = 326,                      /* GT  */
    LE = 327,                      /* LE  */
    GE = 328,                      /* GE  */
    NE = 329,                      /* NE  */
    NUMBER = 330,                  /* NUMBER  */
    FLOAT = 331,                   /* FLOAT  */
    ID = 332,                      /* ID  */
    DATE_STR = 333,                /* DATE_STR  */
    SSS = 334,                     /* SSS  */
    UMINUS = 335                   /* UMINUS  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 131 "yacc_sql.y"

  ParsedSqlNode *                   sql_node;
  ConditionSqlNode *                condition;
  Value *                           value;
  enum ExprOp                       comp;
  enum AggrFuncType                 aggr_func;
  enum ConjuctionType               conj_type;
  RelAttrSqlNode *                  rel_attr;
  std::vector<AttrInfoSqlNode> *    attr_infos;
  AttrInfoSqlNode *                 attr_info;
  UpdateValueSqlNode*               update_value;
  std::vector<UpdateValueSqlNode> * update_value_list;
  InsertValueSqlNode*               insert_value;
  std::vector<InsertValueSqlNode> * insert_value_list;
  Expression *                      expression;
  std::vector<Expression *> *       expression_list;
  ExprSqlNode *                     express;
  std::vector<ExprSqlNode *> *      express_list;
  OrderBySqlNode*                   order;
  std::vector<OrderBySqlNode> *     order_list;
  std::vector<Value> *              value_list;
  std::vector<ConditionSqlNode> *   condition_list;
  std::vector<RelAttrSqlNode> *     rel_attr_list;
  std::vector<RelationSqlNode> *    relation_list;
  RelationSqlNode*                  relation;
  JoinedRelationSqlNode*            join_rel;
  std::vector<JoinedRelationSqlNode>* join_rel_list;
  GroupBySqlNode*                   group_by;
  RelAttrSqlNode *                  function; 
  ConditionTreeSqlNode*             condition_tree;
  char *                            string;
  int                               number;
  float                             floats;
  bool		                          boolean;
            

#line 181 "yacc_sql.hpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif




int yyparse (const char * sql_string, ParsedSqlResult * sql_result, void * scanner);


#endif /* !YY_YY_YACC_SQL_HPP_INCLUDED  */
