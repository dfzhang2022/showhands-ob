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
    HELP = 284,                    /* HELP  */
    EXIT = 285,                    /* EXIT  */
    DOT = 286,                     /* DOT  */
    QUOTE = 287,                   /* QUOTE  */
    INTO = 288,                    /* INTO  */
    VALUES = 289,                  /* VALUES  */
    FROM = 290,                    /* FROM  */
    WHERE = 291,                   /* WHERE  */
    AND = 292,                     /* AND  */
    ORDER = 293,                   /* ORDER  */
    GROUP = 294,                   /* GROUP  */
    BY = 295,                      /* BY  */
    SET = 296,                     /* SET  */
    ON = 297,                      /* ON  */
    LIKE_MARK = 298,               /* LIKE_MARK  */
    NOT = 299,                     /* NOT  */
    LOAD = 300,                    /* LOAD  */
    DATA = 301,                    /* DATA  */
    INFILE = 302,                  /* INFILE  */
    EXPLAIN = 303,                 /* EXPLAIN  */
    CLEAR = 304,                   /* CLEAR  */
    IS = 305,                      /* IS  */
    NULL_T = 306,                  /* NULL_T  */
    NULLABLE = 307,                /* NULLABLE  */
    CNT_FUNC = 308,                /* CNT_FUNC  */
    MAX_FUNC = 309,                /* MAX_FUNC  */
    MIN_FUNC = 310,                /* MIN_FUNC  */
    AVG_FUNC = 311,                /* AVG_FUNC  */
    SUM_FUNC = 312,                /* SUM_FUNC  */
    EQ = 313,                      /* EQ  */
    LT = 314,                      /* LT  */
    GT = 315,                      /* GT  */
    LE = 316,                      /* LE  */
    GE = 317,                      /* GE  */
    NE = 318,                      /* NE  */
    NUMBER = 319,                  /* NUMBER  */
    FLOAT = 320,                   /* FLOAT  */
    ID = 321,                      /* ID  */
    DATE_STR = 322,                /* DATE_STR  */
    SSS = 323,                     /* SSS  */
    UMINUS = 324                   /* UMINUS  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 120 "yacc_sql.y"

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
  std::vector<std::string> *        relation_list;
  char *                            string;
  int                               number;
  float                             floats;

#line 159 "yacc_sql.hpp"

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
