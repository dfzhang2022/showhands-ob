/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 2

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 2 "yacc_sql.y"


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


#line 115 "yacc_sql.cpp"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "yacc_sql.hpp"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_SEMICOLON = 3,                  /* SEMICOLON  */
  YYSYMBOL_CREATE = 4,                     /* CREATE  */
  YYSYMBOL_DROP = 5,                       /* DROP  */
  YYSYMBOL_TABLE = 6,                      /* TABLE  */
  YYSYMBOL_TABLES = 7,                     /* TABLES  */
  YYSYMBOL_UNIQUE = 8,                     /* UNIQUE  */
  YYSYMBOL_INDEX = 9,                      /* INDEX  */
  YYSYMBOL_CALC = 10,                      /* CALC  */
  YYSYMBOL_SELECT = 11,                    /* SELECT  */
  YYSYMBOL_DESC = 12,                      /* DESC  */
  YYSYMBOL_ASC = 13,                       /* ASC  */
  YYSYMBOL_SHOW = 14,                      /* SHOW  */
  YYSYMBOL_SYNC = 15,                      /* SYNC  */
  YYSYMBOL_INSERT = 16,                    /* INSERT  */
  YYSYMBOL_DELETE = 17,                    /* DELETE  */
  YYSYMBOL_UPDATE = 18,                    /* UPDATE  */
  YYSYMBOL_LBRACE = 19,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 20,                    /* RBRACE  */
  YYSYMBOL_COMMA = 21,                     /* COMMA  */
  YYSYMBOL_TRX_BEGIN = 22,                 /* TRX_BEGIN  */
  YYSYMBOL_TRX_COMMIT = 23,                /* TRX_COMMIT  */
  YYSYMBOL_TRX_ROLLBACK = 24,              /* TRX_ROLLBACK  */
  YYSYMBOL_INT_T = 25,                     /* INT_T  */
  YYSYMBOL_STRING_T = 26,                  /* STRING_T  */
  YYSYMBOL_FLOAT_T = 27,                   /* FLOAT_T  */
  YYSYMBOL_DATE_T = 28,                    /* DATE_T  */
  YYSYMBOL_TEXT_T = 29,                    /* TEXT_T  */
  YYSYMBOL_HELP = 30,                      /* HELP  */
  YYSYMBOL_EXIT = 31,                      /* EXIT  */
  YYSYMBOL_DOT = 32,                       /* DOT  */
  YYSYMBOL_QUOTE = 33,                     /* QUOTE  */
  YYSYMBOL_INTO = 34,                      /* INTO  */
  YYSYMBOL_VALUES = 35,                    /* VALUES  */
  YYSYMBOL_FROM = 36,                      /* FROM  */
  YYSYMBOL_INNER = 37,                     /* INNER  */
  YYSYMBOL_JOIN = 38,                      /* JOIN  */
  YYSYMBOL_WHERE = 39,                     /* WHERE  */
  YYSYMBOL_AND = 40,                       /* AND  */
  YYSYMBOL_OR = 41,                        /* OR  */
  YYSYMBOL_EXISTS = 42,                    /* EXISTS  */
  YYSYMBOL_ORDER = 43,                     /* ORDER  */
  YYSYMBOL_GROUP = 44,                     /* GROUP  */
  YYSYMBOL_BY = 45,                        /* BY  */
  YYSYMBOL_HAVING = 46,                    /* HAVING  */
  YYSYMBOL_SET = 47,                       /* SET  */
  YYSYMBOL_ON = 48,                        /* ON  */
  YYSYMBOL_LIKE_MARK = 49,                 /* LIKE_MARK  */
  YYSYMBOL_NOT = 50,                       /* NOT  */
  YYSYMBOL_LOAD = 51,                      /* LOAD  */
  YYSYMBOL_DATA = 52,                      /* DATA  */
  YYSYMBOL_INFILE = 53,                    /* INFILE  */
  YYSYMBOL_EXPLAIN = 54,                   /* EXPLAIN  */
  YYSYMBOL_CLEAR = 55,                     /* CLEAR  */
  YYSYMBOL_IS = 56,                        /* IS  */
  YYSYMBOL_IN = 57,                        /* IN  */
  YYSYMBOL_AS = 58,                        /* AS  */
  YYSYMBOL_NULL_T = 59,                    /* NULL_T  */
  YYSYMBOL_NULLABLE = 60,                  /* NULLABLE  */
  YYSYMBOL_CNT_FUNC = 61,                  /* CNT_FUNC  */
  YYSYMBOL_MAX_FUNC = 62,                  /* MAX_FUNC  */
  YYSYMBOL_MIN_FUNC = 63,                  /* MIN_FUNC  */
  YYSYMBOL_AVG_FUNC = 64,                  /* AVG_FUNC  */
  YYSYMBOL_SUM_FUNC = 65,                  /* SUM_FUNC  */
  YYSYMBOL_ROUND = 66,                     /* ROUND  */
  YYSYMBOL_LENGTH = 67,                    /* LENGTH  */
  YYSYMBOL_DATE_FORMAT = 68,               /* DATE_FORMAT  */
  YYSYMBOL_EQ = 69,                        /* EQ  */
  YYSYMBOL_LT = 70,                        /* LT  */
  YYSYMBOL_GT = 71,                        /* GT  */
  YYSYMBOL_LE = 72,                        /* LE  */
  YYSYMBOL_GE = 73,                        /* GE  */
  YYSYMBOL_NE = 74,                        /* NE  */
  YYSYMBOL_NUMBER = 75,                    /* NUMBER  */
  YYSYMBOL_FLOAT = 76,                     /* FLOAT  */
  YYSYMBOL_ID = 77,                        /* ID  */
  YYSYMBOL_DATE_STR = 78,                  /* DATE_STR  */
  YYSYMBOL_SSS = 79,                       /* SSS  */
  YYSYMBOL_80_ = 80,                       /* '+'  */
  YYSYMBOL_81_ = 81,                       /* '-'  */
  YYSYMBOL_82_ = 82,                       /* '*'  */
  YYSYMBOL_83_ = 83,                       /* '/'  */
  YYSYMBOL_UMINUS = 84,                    /* UMINUS  */
  YYSYMBOL_YYACCEPT = 85,                  /* $accept  */
  YYSYMBOL_commands = 86,                  /* commands  */
  YYSYMBOL_command_wrapper = 87,           /* command_wrapper  */
  YYSYMBOL_exit_stmt = 88,                 /* exit_stmt  */
  YYSYMBOL_help_stmt = 89,                 /* help_stmt  */
  YYSYMBOL_sync_stmt = 90,                 /* sync_stmt  */
  YYSYMBOL_begin_stmt = 91,                /* begin_stmt  */
  YYSYMBOL_commit_stmt = 92,               /* commit_stmt  */
  YYSYMBOL_rollback_stmt = 93,             /* rollback_stmt  */
  YYSYMBOL_drop_table_stmt = 94,           /* drop_table_stmt  */
  YYSYMBOL_clear_table_stmt = 95,          /* clear_table_stmt  */
  YYSYMBOL_show_tables_stmt = 96,          /* show_tables_stmt  */
  YYSYMBOL_show_index_stmt = 97,           /* show_index_stmt  */
  YYSYMBOL_desc_table_stmt = 98,           /* desc_table_stmt  */
  YYSYMBOL_create_index_stmt = 99,         /* create_index_stmt  */
  YYSYMBOL_drop_index_stmt = 100,          /* drop_index_stmt  */
  YYSYMBOL_create_table_stmt = 101,        /* create_table_stmt  */
  YYSYMBOL_attr_def_list = 102,            /* attr_def_list  */
  YYSYMBOL_attr_def = 103,                 /* attr_def  */
  YYSYMBOL_number = 104,                   /* number  */
  YYSYMBOL_type = 105,                     /* type  */
  YYSYMBOL_insert_stmt = 106,              /* insert_stmt  */
  YYSYMBOL_insert_value_list = 107,        /* insert_value_list  */
  YYSYMBOL_insert_value = 108,             /* insert_value  */
  YYSYMBOL_value_list = 109,               /* value_list  */
  YYSYMBOL_value = 110,                    /* value  */
  YYSYMBOL_delete_stmt = 111,              /* delete_stmt  */
  YYSYMBOL_update_stmt = 112,              /* update_stmt  */
  YYSYMBOL_set_value_list = 113,           /* set_value_list  */
  YYSYMBOL_set_value = 114,                /* set_value  */
  YYSYMBOL_select_stmt = 115,              /* select_stmt  */
  YYSYMBOL_calc_stmt = 116,                /* calc_stmt  */
  YYSYMBOL_expression_list = 117,          /* expression_list  */
  YYSYMBOL_expression = 118,               /* expression  */
  YYSYMBOL_express = 119,                  /* express  */
  YYSYMBOL_select_attr = 120,              /* select_attr  */
  YYSYMBOL_aggregation_func = 121,         /* aggregation_func  */
  YYSYMBOL_rel_attr = 122,                 /* rel_attr  */
  YYSYMBOL_as_alias = 123,                 /* as_alias  */
  YYSYMBOL_attr_list = 124,                /* attr_list  */
  YYSYMBOL_express_list = 125,             /* express_list  */
  YYSYMBOL_inner_join = 126,               /* inner_join  */
  YYSYMBOL_inner_join_list = 127,          /* inner_join_list  */
  YYSYMBOL_join_relation = 128,            /* join_relation  */
  YYSYMBOL_rel_element = 129,              /* rel_element  */
  YYSYMBOL_rel_list = 130,                 /* rel_list  */
  YYSYMBOL_where = 131,                    /* where  */
  YYSYMBOL_having_clause = 132,            /* having_clause  */
  YYSYMBOL_condition_list = 133,           /* condition_list  */
  YYSYMBOL_condition = 134,                /* condition  */
  YYSYMBOL_group_by = 135,                 /* group_by  */
  YYSYMBOL_order_by = 136,                 /* order_by  */
  YYSYMBOL_order = 137,                    /* order  */
  YYSYMBOL_order_list = 138,               /* order_list  */
  YYSYMBOL_function = 139,                 /* function  */
  YYSYMBOL_null_or_nullable = 140,         /* null_or_nullable  */
  YYSYMBOL_comp_op = 141,                  /* comp_op  */
  YYSYMBOL_load_data_stmt = 142,           /* load_data_stmt  */
  YYSYMBOL_explain_stmt = 143,             /* explain_stmt  */
  YYSYMBOL_set_variable_stmt = 144,        /* set_variable_stmt  */
  YYSYMBOL_opt_semicolon = 145             /* opt_semicolon  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if 1

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* 1 */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  88
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   478

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  85
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  61
/* YYNRULES -- Number of rules.  */
#define YYNRULES  178
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  345

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   335


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,    82,    80,     2,    81,     2,    83,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    84
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   243,   243,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   261,   262,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   276,   282,   287,   293,   299,
     305,   311,   317,   322,   327,   335,   343,   355,   370,   380,
     399,   402,   415,   429,   443,   457,   471,   485,   501,   504,
     505,   506,   507,   508,   511,   529,   532,   544,   559,   562,
     580,   584,   588,   598,   603,   614,   626,   646,   649,   661,
     693,   725,   736,   746,   751,   762,   765,   768,   771,   774,
     778,   781,   789,   797,   805,   813,   821,   825,   832,   839,
     850,   863,   875,   882,   895,   910,   923,   929,   938,   946,
     953,   987,   999,  1009,  1012,  1015,  1018,  1021,  1027,  1039,
    1053,  1057,  1065,  1075,  1083,  1089,  1097,  1107,  1110,  1115,
    1123,  1128,  1139,  1142,  1156,  1159,  1171,  1182,  1185,  1202,
    1229,  1244,  1255,  1261,  1269,  1272,  1278,  1281,  1288,  1291,
    1296,  1352,  1401,  1494,  1497,  1510,  1513,  1518,  1523,  1528,
    1536,  1539,  1544,  1552,  1566,  1581,  1599,  1612,  1632,  1636,
    1643,  1644,  1645,  1646,  1647,  1648,  1649,  1650,  1651,  1652,
    1653,  1654,  1655,  1656,  1660,  1673,  1681,  1691,  1692
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "SEMICOLON", "CREATE",
  "DROP", "TABLE", "TABLES", "UNIQUE", "INDEX", "CALC", "SELECT", "DESC",
  "ASC", "SHOW", "SYNC", "INSERT", "DELETE", "UPDATE", "LBRACE", "RBRACE",
  "COMMA", "TRX_BEGIN", "TRX_COMMIT", "TRX_ROLLBACK", "INT_T", "STRING_T",
  "FLOAT_T", "DATE_T", "TEXT_T", "HELP", "EXIT", "DOT", "QUOTE", "INTO",
  "VALUES", "FROM", "INNER", "JOIN", "WHERE", "AND", "OR", "EXISTS",
  "ORDER", "GROUP", "BY", "HAVING", "SET", "ON", "LIKE_MARK", "NOT",
  "LOAD", "DATA", "INFILE", "EXPLAIN", "CLEAR", "IS", "IN", "AS", "NULL_T",
  "NULLABLE", "CNT_FUNC", "MAX_FUNC", "MIN_FUNC", "AVG_FUNC", "SUM_FUNC",
  "ROUND", "LENGTH", "DATE_FORMAT", "EQ", "LT", "GT", "LE", "GE", "NE",
  "NUMBER", "FLOAT", "ID", "DATE_STR", "SSS", "'+'", "'-'", "'*'", "'/'",
  "UMINUS", "$accept", "commands", "command_wrapper", "exit_stmt",
  "help_stmt", "sync_stmt", "begin_stmt", "commit_stmt", "rollback_stmt",
  "drop_table_stmt", "clear_table_stmt", "show_tables_stmt",
  "show_index_stmt", "desc_table_stmt", "create_index_stmt",
  "drop_index_stmt", "create_table_stmt", "attr_def_list", "attr_def",
  "number", "type", "insert_stmt", "insert_value_list", "insert_value",
  "value_list", "value", "delete_stmt", "update_stmt", "set_value_list",
  "set_value", "select_stmt", "calc_stmt", "expression_list", "expression",
  "express", "select_attr", "aggregation_func", "rel_attr", "as_alias",
  "attr_list", "express_list", "inner_join", "inner_join_list",
  "join_relation", "rel_element", "rel_list", "where", "having_clause",
  "condition_list", "condition", "group_by", "order_by", "order",
  "order_list", "function", "null_or_nullable", "comp_op",
  "load_data_stmt", "explain_stmt", "set_variable_stmt", "opt_semicolon", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-251)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     365,    13,    43,   -13,   184,   -36,    26,  -251,    20,    60,
       2,  -251,  -251,  -251,  -251,  -251,    33,    70,   365,   127,
     134,   149,  -251,  -251,  -251,  -251,  -251,  -251,  -251,  -251,
    -251,  -251,  -251,  -251,  -251,  -251,  -251,  -251,  -251,  -251,
    -251,  -251,  -251,  -251,    58,   154,    88,    89,    92,   -13,
    -251,  -251,  -251,  -251,  -251,  -251,   -13,  -251,  -251,    35,
    -251,    83,  -251,  -251,  -251,  -251,  -251,   156,   157,   158,
     -27,   260,   160,  -251,    57,   150,   176,  -251,  -251,  -251,
     163,   119,   123,   162,   143,   165,  -251,  -251,  -251,  -251,
    -251,   182,   136,   171,  -251,   173,    10,  -251,   -13,   -13,
     -13,   -13,   -13,   203,    -7,   375,   288,   392,   -40,   147,
     200,  -251,  -251,   260,  -251,   260,   260,   260,   260,  -251,
     159,   206,   164,   198,   195,   177,   132,   161,   179,   194,
     180,   187,  -251,  -251,   -38,   -38,  -251,  -251,  -251,  -251,
     260,   232,     6,   256,   255,  -251,   257,   261,   259,   -41,
     -41,   250,   207,    57,   -12,   -12,  -251,  -251,   -19,  -251,
     266,   195,  -251,   121,    66,   268,  -251,   271,   236,  -251,
     225,   297,  -251,   299,   202,   313,   263,   323,  -251,    57,
     269,   270,  -251,   296,   273,  -251,  -251,   264,  -251,  -251,
     289,  -251,  -251,   307,  -251,   309,   159,   325,   -41,   294,
     -41,   392,   392,   132,   351,  -251,  -251,   -17,   324,  -251,
    -251,  -251,  -251,  -251,  -251,  -251,   352,  -251,   344,   260,
     260,   177,   195,   379,  -251,  -251,  -251,  -251,  -251,     1,
     179,   366,   371,   314,   372,   373,   -41,  -251,   148,    99,
     376,   378,   380,  -251,   322,   309,  -251,  -251,   358,   360,
    -251,    -5,  -251,   384,   384,   385,   271,  -251,  -251,  -251,
    -251,  -251,   260,   236,   249,   249,   297,  -251,   330,   335,
     354,  -251,   313,  -251,   334,   394,  -251,  -251,  -251,  -251,
     338,  -251,   392,   392,  -251,  -251,   369,  -251,   392,   382,
     383,   -41,   392,   398,   408,   260,   410,   351,   249,  -251,
    -251,  -251,  -251,   411,  -251,  -251,   424,  -251,   112,   384,
     384,   236,   114,   425,  -251,   392,   236,  -251,  -251,   384,
    -251,  -251,    74,  -251,  -251,   -26,  -251,  -251,   427,   428,
    -251,  -251,  -251,   392,   384,  -251,  -251,  -251,   386,  -251,
    -251,  -251,  -251,  -251,  -251
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,    27,     0,     0,
       0,    28,    29,    30,    26,    25,     0,     0,     0,     0,
       0,   177,    23,    22,    15,    16,    17,    18,     9,    24,
      10,    11,    12,    13,    14,     8,     5,     7,     6,     4,
       3,    19,    20,    21,     0,     0,     0,     0,     0,     0,
     158,   159,    60,    61,    62,    63,     0,    81,    72,    73,
      64,     0,   105,   103,   104,   106,   107,     0,     0,     0,
     117,     0,   124,    88,   124,    71,     0,    92,    35,    33,
       0,     0,     0,     0,     0,     0,   175,    32,     1,   178,
       2,     0,     0,     0,    31,     0,     0,    80,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     120,    89,    87,     0,   101,     0,     0,     0,     0,   102,
       0,     0,     0,     0,   134,     0,     0,     0,     0,     0,
       0,     0,    79,    74,    75,    76,    77,    78,    99,    86,
       0,     0,   117,     0,     0,   110,     0,     0,     0,   117,
     117,   118,     0,   124,    82,    83,    84,    85,   117,   131,
     132,   134,    96,   117,     0,     0,    34,     0,   138,    65,
       0,    67,   176,     0,     0,    40,     0,     0,    38,   124,
       0,     0,   108,     0,     0,   154,   153,     0,    90,    91,
       0,   121,   125,     0,   130,   127,     0,   145,   117,     0,
     117,     0,     0,     0,    55,   172,   168,     0,   166,   170,
     160,   161,   162,   163,   164,   165,     0,   135,   139,     0,
       0,     0,   134,     0,    49,    50,    51,    52,    53,    43,
       0,     0,     0,     0,     0,     0,   117,   114,   117,     0,
       0,     0,     0,   119,     0,   127,   129,   133,     0,   143,
      93,   117,    95,   122,   122,    58,     0,    54,   173,   169,
     171,   167,     0,   138,   142,    69,    67,    66,     0,     0,
       0,    45,    40,    39,     0,     0,   100,   156,   109,   111,
       0,   113,     0,     0,   155,   157,     0,   128,   150,     0,
     136,   117,     0,     0,     0,     0,     0,    55,   141,   140,
      68,   174,    48,     0,    47,    41,     0,    36,   117,   122,
     122,   138,   147,   151,   146,     0,   138,    70,    94,   122,
      98,    97,    58,    57,    56,    42,    37,   112,     0,     0,
     126,   148,   149,   150,   122,   137,   123,    59,     0,    44,
     116,   115,   152,   144,    46
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -251,  -251,   431,  -251,  -251,  -251,  -251,  -251,  -251,  -251,
    -251,  -251,  -251,  -251,  -251,  -251,  -251,   178,   231,  -251,
    -251,  -251,   166,   208,   140,    -1,  -251,  -251,   199,   245,
     406,  -251,   370,    72,    -4,  -251,   -98,   -78,   -69,  -250,
     -71,   312,   226,  -251,  -251,   276,  -145,  -251,  -133,  -251,
    -251,  -251,  -251,   141,   -95,  -251,   262,  -251,  -251,  -251,
    -251
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,   231,   175,   303,
     229,    36,   257,   204,   296,    73,    37,    38,   222,   171,
      39,    40,    58,    59,   216,    75,    76,   312,   182,   293,
     114,   245,   246,   159,   160,   161,   169,   317,   217,   218,
     290,   249,   313,   314,    77,    60,   219,    41,    42,    43,
      90
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      74,   111,    57,   119,   294,   108,    49,   143,   143,   143,
     145,   145,   145,   139,   140,   291,   197,   109,   193,    44,
     269,    45,    46,   143,   338,   258,   145,   144,   147,   148,
     132,   109,   259,    79,   339,    80,   110,   149,   181,   109,
     260,    78,   150,   165,   101,   102,    50,    51,    57,    47,
     110,   270,    48,   109,    81,    57,    98,   104,   110,   328,
     329,   271,    52,    53,   109,    54,    55,   112,    56,   336,
     117,   118,   110,   115,   116,   117,   118,   267,   113,    83,
     188,   189,   192,   110,   343,   143,   200,   201,   145,   194,
      99,   100,   101,   102,     4,   295,    82,    57,    57,    57,
      57,    57,    61,   143,   143,   240,   145,   145,   234,   153,
      84,   154,   155,   156,   157,    99,   100,   101,   102,   281,
     282,    96,    85,   253,   254,   172,   331,   332,    97,   250,
     299,   252,   327,    87,    88,    91,   179,   115,   116,   117,
     118,   198,    50,    51,    62,    63,    64,    65,    66,    67,
      68,    69,    89,   199,   115,   116,   117,   118,    52,    53,
      70,    54,    55,    92,    71,    93,    94,   278,   279,    95,
     109,   134,   135,   136,   137,   105,   106,   107,   330,   109,
     280,   113,   278,   335,   143,   143,   120,   145,   145,   110,
     143,    50,    51,   145,   143,   121,   123,   145,   110,   122,
     124,   128,   255,    61,   309,   310,   109,    52,    53,   125,
      54,    55,   126,   129,   319,   264,   265,   143,   127,   130,
     145,   131,   318,   138,   151,   110,   162,   224,   225,   226,
     227,   228,   152,   167,   168,   143,   158,   334,   145,   278,
     173,   166,   176,    50,    51,    62,    63,    64,    65,    66,
      67,    68,    69,   180,   170,    61,   174,   177,   298,    52,
      53,    70,    54,    55,   178,    71,    72,    62,    63,    64,
      65,    66,    67,    68,    69,   183,   184,   185,   205,    61,
     187,   186,   190,   163,   191,   206,   207,   196,   164,   202,
     203,   322,   208,   209,   220,    50,    51,    62,    63,    64,
      65,    66,    67,    68,    69,   210,   211,   212,   213,   214,
     215,    52,    53,    70,    54,    55,   237,    71,   221,    50,
      51,    62,    63,    64,    65,    66,    67,    68,    69,   115,
     116,   117,   118,   223,   230,    52,    53,    70,    54,    55,
     232,    71,   233,   242,   235,   244,   193,   236,   241,    62,
      63,    64,    65,    66,    67,    68,    69,    62,    63,    64,
      65,    66,    67,    68,    69,   142,   243,   146,   248,     1,
       2,   251,   256,   238,   261,     3,     4,     5,   239,     6,
       7,     8,     9,    10,   263,   268,   273,    11,    12,    13,
     274,   275,   276,   277,   205,    14,    15,   283,   284,   286,
     285,   206,   207,   288,   289,   292,   295,   301,   208,   209,
     302,   306,    16,   304,   307,   308,    17,   311,   320,    18,
      19,   210,   211,   212,   213,   214,   215,   315,   321,   316,
     323,   325,   115,   116,   117,   118,    62,    63,    64,    65,
      66,    67,    68,    69,   326,   344,   333,   340,   341,    86,
     305,   141,   142,    62,    63,    64,    65,    66,    67,    68,
      69,   272,   337,   324,   297,   300,   266,   103,   133,   142,
     195,   287,   247,     0,   342,     0,     0,     0,   262
};

static const yytype_int16 yycheck[] =
{
       4,    70,     3,    74,   254,    32,    19,   105,   106,   107,
     105,   106,   107,    20,    21,    20,   161,    58,    37,     6,
      19,     8,     9,   121,    50,    42,   121,   105,   106,   107,
      20,    58,    49,     7,    60,     9,    77,    77,    32,    58,
      57,    77,    82,   121,    82,    83,    59,    60,    49,     6,
      77,    50,     9,    58,    34,    56,    21,    61,    77,   309,
     310,    60,    75,    76,    58,    78,    79,    71,    81,   319,
      82,    83,    77,    80,    81,    82,    83,   222,    21,    77,
     149,   150,   153,    77,   334,   183,    20,    21,   183,   158,
      80,    81,    82,    83,    11,    21,    36,    98,    99,   100,
     101,   102,    19,   201,   202,   183,   201,   202,   179,   113,
      77,   115,   116,   117,   118,    80,    81,    82,    83,    20,
      21,    49,    52,   201,   202,   126,    12,    13,    56,   198,
     263,   200,    20,     6,     0,    77,   140,    80,    81,    82,
      83,    20,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,     3,    32,    80,    81,    82,    83,    75,    76,
      77,    78,    79,     9,    81,    77,    77,   236,    20,    77,
      58,    99,   100,   101,   102,    19,    19,    19,   311,    58,
      32,    21,   251,   316,   282,   283,    36,   282,   283,    77,
     288,    59,    60,   288,   292,    19,    77,   292,    77,    36,
      77,    19,   203,    19,   282,   283,    58,    75,    76,    47,
      78,    79,    69,    77,   292,   219,   220,   315,    53,    48,
     315,    48,   291,    20,    77,    77,    20,    25,    26,    27,
      28,    29,    32,    35,    39,   333,    77,   315,   333,   308,
      79,    77,    48,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    21,    77,    19,    77,    77,   262,    75,
      76,    77,    78,    79,    77,    81,    82,    61,    62,    63,
      64,    65,    66,    67,    68,    19,    21,    20,    42,    19,
      21,    20,    32,    77,    77,    49,    50,    21,    82,    21,
      19,   295,    56,    57,    69,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    20,    81,    21,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    80,
      81,    82,    83,    34,    21,    75,    76,    77,    78,    79,
      77,    81,    19,    79,    75,    38,    37,    77,    75,    61,
      62,    63,    64,    65,    66,    67,    68,    61,    62,    63,
      64,    65,    66,    67,    68,    77,    77,    79,    43,     4,
       5,    77,    21,    77,    50,    10,    11,    12,    82,    14,
      15,    16,    17,    18,    40,     6,    20,    22,    23,    24,
      19,    77,    20,    20,    42,    30,    31,    21,    20,    77,
      20,    49,    50,    45,    44,    21,    21,    77,    56,    57,
      75,    77,    47,    59,    20,    77,    51,    48,    20,    54,
      55,    69,    70,    71,    72,    73,    74,    45,    20,    46,
      20,    20,    80,    81,    82,    83,    61,    62,    63,    64,
      65,    66,    67,    68,    20,    59,    21,    20,    20,    18,
     272,    76,    77,    61,    62,    63,    64,    65,    66,    67,
      68,   230,   322,   297,   256,   266,   221,    61,    98,    77,
     158,   245,   196,    -1,   333,    -1,    -1,    -1,   216
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     4,     5,    10,    11,    12,    14,    15,    16,    17,
      18,    22,    23,    24,    30,    31,    47,    51,    54,    55,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   106,   111,   112,   115,
     116,   142,   143,   144,     6,     8,     9,     6,     9,    19,
      59,    60,    75,    76,    78,    79,    81,   110,   117,   118,
     140,    19,    61,    62,    63,    64,    65,    66,    67,    68,
      77,    81,    82,   110,   119,   120,   121,   139,    77,     7,
       9,    34,    36,    77,    77,    52,    87,     6,     0,     3,
     145,    77,     9,    77,    77,    77,   118,   118,    21,    80,
      81,    82,    83,   115,   119,    19,    19,    19,    32,    58,
      77,   123,   119,    21,   125,    80,    81,    82,    83,   125,
      36,    19,    36,    77,    77,    47,    69,    53,    19,    77,
      48,    48,    20,   117,   118,   118,   118,   118,    20,    20,
      21,    76,    77,   121,   122,   139,    79,   122,   122,    77,
      82,    77,    32,   119,   119,   119,   119,   119,    77,   128,
     129,   130,    20,    77,    82,   122,    77,    35,    39,   131,
      77,   114,   110,    79,    77,   103,    48,    77,    77,   119,
      21,    32,   123,    19,    21,    20,    20,    21,   123,   123,
      32,    77,   125,    37,   123,   126,    21,   131,    20,    32,
      20,    21,    21,    19,   108,    42,    49,    50,    56,    57,
      69,    70,    71,    72,    73,    74,   119,   133,   134,   141,
      69,    21,   113,    34,    25,    26,    27,    28,    29,   105,
      21,   102,    77,    19,   125,    75,    77,    20,    77,    82,
     122,    75,    79,    77,    38,   126,   127,   130,    43,   136,
     123,    77,   123,   122,   122,   110,    21,   107,    42,    49,
      57,    50,   141,    40,   119,   119,   114,   131,     6,    19,
      50,    60,   103,    20,    19,    77,    20,    20,   123,    20,
      32,    20,    21,    21,    20,    20,    77,   127,    45,    44,
     135,    20,    21,   124,   124,    21,   109,   108,   119,   133,
     113,    77,    75,   104,    59,   102,    77,    20,    77,   122,
     122,    48,   122,   137,   138,    45,    46,   132,   123,   122,
      20,    20,   119,    20,   107,    20,    20,    20,   124,   124,
     133,    12,    13,    21,   122,   133,   124,   109,    50,    60,
      20,    20,   138,   124,    59
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    85,    86,    87,    87,    87,    87,    87,    87,    87,
      87,    87,    87,    87,    87,    87,    87,    87,    87,    87,
      87,    87,    87,    87,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,    99,   100,   101,
     102,   102,   103,   103,   103,   103,   103,   103,   104,   105,
     105,   105,   105,   105,   106,   107,   107,   108,   109,   109,
     110,   110,   110,   110,   110,   111,   112,   113,   113,   114,
     115,   115,   116,   117,   117,   118,   118,   118,   118,   118,
     118,   118,   119,   119,   119,   119,   119,   119,   119,   119,
     119,   119,   119,   119,   119,   119,   119,   119,   119,   119,
     119,   120,   120,   121,   121,   121,   121,   121,   122,   122,
     122,   122,   122,   122,   122,   122,   122,   123,   123,   123,
     123,   123,   124,   124,   125,   125,   126,   127,   127,   128,
     129,   129,   130,   130,   131,   131,   132,   132,   133,   133,
     133,   134,   134,   135,   135,   136,   136,   137,   137,   137,
     138,   138,   138,   139,   139,   139,   139,   139,   140,   140,
     141,   141,   141,   141,   141,   141,   141,   141,   141,   141,
     141,   141,   141,   141,   142,   143,   144,   145,   145
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     2,     2,     4,     2,     8,     9,     5,     7,
       0,     3,     5,     2,     6,     3,     7,     4,     1,     1,
       1,     1,     1,     1,     6,     0,     3,     4,     0,     3,
       1,     1,     1,     1,     1,     4,     6,     0,     3,     3,
       8,     2,     2,     1,     3,     3,     3,     3,     3,     3,
       2,     1,     3,     3,     3,     3,     3,     2,     1,     2,
       4,     4,     1,     5,     7,     5,     3,     7,     7,     3,
       6,     2,     2,     1,     1,     1,     1,     1,     2,     4,
       1,     4,     6,     4,     3,     7,     7,     0,     2,     4,
       1,     3,     0,     3,     0,     3,     5,     0,     2,     3,
       2,     1,     1,     3,     0,     2,     0,     2,     0,     1,
       3,     3,     2,     0,     4,     0,     3,     1,     2,     2,
       0,     1,     3,     4,     4,     6,     6,     6,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     1,     2,
       1,     2,     1,     2,     7,     2,     4,     0,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (&yylloc, sql_string, sql_result, scanner, YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF

/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)


/* YYLOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

# ifndef YYLOCATION_PRINT

#  if defined YY_LOCATION_PRINT

   /* Temporary convenience wrapper in case some people defined the
      undocumented and private YY_LOCATION_PRINT macros.  */
#   define YYLOCATION_PRINT(File, Loc)  YY_LOCATION_PRINT(File, *(Loc))

#  elif defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
}

#   define YYLOCATION_PRINT  yy_location_print_

    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT(File, Loc)  YYLOCATION_PRINT(File, &(Loc))

#  else

#   define YYLOCATION_PRINT(File, Loc) ((void) 0)
    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT  YYLOCATION_PRINT

#  endif
# endif /* !defined YYLOCATION_PRINT */


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, Location, sql_string, sql_result, scanner); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, const char * sql_string, ParsedSqlResult * sql_result, void * scanner)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (yylocationp);
  YY_USE (sql_string);
  YY_USE (sql_result);
  YY_USE (scanner);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, const char * sql_string, ParsedSqlResult * sql_result, void * scanner)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  YYLOCATION_PRINT (yyo, yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yykind, yyvaluep, yylocationp, sql_string, sql_result, scanner);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp,
                 int yyrule, const char * sql_string, ParsedSqlResult * sql_result, void * scanner)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)],
                       &(yylsp[(yyi + 1) - (yynrhs)]), sql_string, sql_result, scanner);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule, sql_string, sql_result, scanner); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
  YYLTYPE *yylloc;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
  if (!yypact_value_is_default (yyn))
    {
      /* Start YYX at -YYN if negative to avoid negative indexes in
         YYCHECK.  In other words, skip the first -YYN actions for
         this state because they are default actions.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;
      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yyx;
      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;
      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, YYLTYPE *yylocationp, const char * sql_string, ParsedSqlResult * sql_result, void * scanner)
{
  YY_USE (yyvaluep);
  YY_USE (yylocationp);
  YY_USE (sql_string);
  YY_USE (sql_result);
  YY_USE (scanner);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}






/*----------.
| yyparse.  |
`----------*/

int
yyparse (const char * sql_string, ParsedSqlResult * sql_result, void * scanner)
{
/* Lookahead token kind.  */
int yychar;


/* The semantic value of the lookahead symbol.  */
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
YY_INITIAL_VALUE (static YYSTYPE yyval_default;)
YYSTYPE yylval YY_INITIAL_VALUE (= yyval_default);

/* Location data for the lookahead symbol.  */
static YYLTYPE yyloc_default
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
YYLTYPE yylloc = yyloc_default;

    /* Number of syntax errors so far.  */
    int yynerrs = 0;

    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

    /* The location stack: array, bottom, top.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls = yylsa;
    YYLTYPE *yylsp = yyls;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[3];

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  yylsp[0] = yylloc;
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex (&yylval, &yylloc, scanner);
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      yyerror_range[1] = yylloc;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* commands: command_wrapper opt_semicolon  */
#line 244 "yacc_sql.y"
  {
    std::unique_ptr<ParsedSqlNode> sql_node = std::unique_ptr<ParsedSqlNode>((yyvsp[-1].sql_node));
    sql_result->add_sql_node(std::move(sql_node));
  }
#line 1927 "yacc_sql.cpp"
    break;

  case 25: /* exit_stmt: EXIT  */
#line 276 "yacc_sql.y"
         {
      (void)yynerrs;  // 这么写为了消除yynerrs未使用的告警。如果你有更好的方法欢迎提PR
      (yyval.sql_node) = new ParsedSqlNode(SCF_EXIT);
    }
#line 1936 "yacc_sql.cpp"
    break;

  case 26: /* help_stmt: HELP  */
#line 282 "yacc_sql.y"
         {
      (yyval.sql_node) = new ParsedSqlNode(SCF_HELP);
    }
#line 1944 "yacc_sql.cpp"
    break;

  case 27: /* sync_stmt: SYNC  */
#line 287 "yacc_sql.y"
         {
      (yyval.sql_node) = new ParsedSqlNode(SCF_SYNC);
    }
#line 1952 "yacc_sql.cpp"
    break;

  case 28: /* begin_stmt: TRX_BEGIN  */
#line 293 "yacc_sql.y"
               {
      (yyval.sql_node) = new ParsedSqlNode(SCF_BEGIN);
    }
#line 1960 "yacc_sql.cpp"
    break;

  case 29: /* commit_stmt: TRX_COMMIT  */
#line 299 "yacc_sql.y"
               {
      (yyval.sql_node) = new ParsedSqlNode(SCF_COMMIT);
    }
#line 1968 "yacc_sql.cpp"
    break;

  case 30: /* rollback_stmt: TRX_ROLLBACK  */
#line 305 "yacc_sql.y"
                  {
      (yyval.sql_node) = new ParsedSqlNode(SCF_ROLLBACK);
    }
#line 1976 "yacc_sql.cpp"
    break;

  case 31: /* drop_table_stmt: DROP TABLE ID  */
#line 311 "yacc_sql.y"
                  {
      (yyval.sql_node) = new ParsedSqlNode(SCF_DROP_TABLE);
      (yyval.sql_node)->drop_table.relation_name = (yyvsp[0].string);
      free((yyvsp[0].string));
    }
#line 1986 "yacc_sql.cpp"
    break;

  case 32: /* clear_table_stmt: CLEAR TABLE  */
#line 317 "yacc_sql.y"
               {
      (yyval.sql_node) = new ParsedSqlNode(SCF_CLEAR_TABLE);
    }
#line 1994 "yacc_sql.cpp"
    break;

  case 33: /* show_tables_stmt: SHOW TABLES  */
#line 322 "yacc_sql.y"
                {
      (yyval.sql_node) = new ParsedSqlNode(SCF_SHOW_TABLES);
    }
#line 2002 "yacc_sql.cpp"
    break;

  case 34: /* show_index_stmt: SHOW INDEX FROM ID  */
#line 327 "yacc_sql.y"
                      {
      (yyval.sql_node) = new ParsedSqlNode(SCF_SHOW_INDEX);
      (yyval.sql_node)->show_index.relation_name = (yyvsp[0].string);
      free((yyvsp[0].string));
    }
#line 2012 "yacc_sql.cpp"
    break;

  case 35: /* desc_table_stmt: DESC ID  */
#line 335 "yacc_sql.y"
             {
      (yyval.sql_node) = new ParsedSqlNode(SCF_DESC_TABLE);
      (yyval.sql_node)->desc_table.relation_name = (yyvsp[0].string);
      free((yyvsp[0].string));
    }
#line 2022 "yacc_sql.cpp"
    break;

  case 36: /* create_index_stmt: CREATE INDEX ID ON ID LBRACE ID RBRACE  */
#line 344 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_CREATE_INDEX);
      CreateIndexSqlNode &create_index = (yyval.sql_node)->create_index;
      create_index.is_unique = false;
      create_index.index_name = (yyvsp[-5].string);
      create_index.relation_name = (yyvsp[-3].string);
      create_index.attribute_name = (yyvsp[-1].string);
      free((yyvsp[-5].string));
      free((yyvsp[-3].string));
      free((yyvsp[-1].string));
    }
#line 2038 "yacc_sql.cpp"
    break;

  case 37: /* create_index_stmt: CREATE UNIQUE INDEX ID ON ID LBRACE ID RBRACE  */
#line 356 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_CREATE_INDEX);
      CreateIndexSqlNode &create_index = (yyval.sql_node)->create_index;
      create_index.is_unique = true;
      create_index.index_name = (yyvsp[-5].string);
      create_index.relation_name = (yyvsp[-3].string);
      create_index.attribute_name = (yyvsp[-1].string);
      free((yyvsp[-5].string));
      free((yyvsp[-3].string));
      free((yyvsp[-1].string));
    }
#line 2054 "yacc_sql.cpp"
    break;

  case 38: /* drop_index_stmt: DROP INDEX ID ON ID  */
#line 371 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_DROP_INDEX);
      (yyval.sql_node)->drop_index.index_name = (yyvsp[-2].string);
      (yyval.sql_node)->drop_index.relation_name = (yyvsp[0].string);
      free((yyvsp[-2].string));
      free((yyvsp[0].string));
    }
#line 2066 "yacc_sql.cpp"
    break;

  case 39: /* create_table_stmt: CREATE TABLE ID LBRACE attr_def attr_def_list RBRACE  */
#line 381 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_CREATE_TABLE);
      CreateTableSqlNode &create_table = (yyval.sql_node)->create_table;
      create_table.relation_name = (yyvsp[-4].string);
      free((yyvsp[-4].string));

      std::vector<AttrInfoSqlNode> *src_attrs = (yyvsp[-1].attr_infos);

      if (src_attrs != nullptr) {
        create_table.attr_infos.swap(*src_attrs);
      }
      create_table.attr_infos.emplace_back(*(yyvsp[-2].attr_info));
      std::reverse(create_table.attr_infos.begin(), create_table.attr_infos.end());
      delete (yyvsp[-2].attr_info);
    }
#line 2086 "yacc_sql.cpp"
    break;

  case 40: /* attr_def_list: %empty  */
#line 399 "yacc_sql.y"
    {
      (yyval.attr_infos) = nullptr;
    }
#line 2094 "yacc_sql.cpp"
    break;

  case 41: /* attr_def_list: COMMA attr_def attr_def_list  */
#line 403 "yacc_sql.y"
    {
      if ((yyvsp[0].attr_infos) != nullptr) {
        (yyval.attr_infos) = (yyvsp[0].attr_infos);
      } else {
        (yyval.attr_infos) = new std::vector<AttrInfoSqlNode>;
      }
      (yyval.attr_infos)->emplace_back(*(yyvsp[-1].attr_info));
      delete (yyvsp[-1].attr_info);
    }
#line 2108 "yacc_sql.cpp"
    break;

  case 42: /* attr_def: ID type LBRACE number RBRACE  */
#line 416 "yacc_sql.y"
    {
      (yyval.attr_info) = new AttrInfoSqlNode;
      (yyval.attr_info)->type = (AttrType)(yyvsp[-3].number);
      (yyval.attr_info)->name = (yyvsp[-4].string);
      if ((yyval.attr_info)->type == AttrType::TEXTS) {
        (yyval.attr_info)->length = MAX_TEXT_LENGTH;
      }
      else {
        (yyval.attr_info)->length = (yyvsp[-1].number);
      }
      (yyval.attr_info)->nullable = false;
      free((yyvsp[-4].string));
    }
#line 2126 "yacc_sql.cpp"
    break;

  case 43: /* attr_def: ID type  */
#line 430 "yacc_sql.y"
    {
      (yyval.attr_info) = new AttrInfoSqlNode;
      (yyval.attr_info)->type = (AttrType)(yyvsp[0].number);
      (yyval.attr_info)->name = (yyvsp[-1].string);
      if ((yyval.attr_info)->type == AttrType::TEXTS) {
        (yyval.attr_info)->length = MAX_TEXT_LENGTH;
      }
      else {
        (yyval.attr_info)->length = 4;
      }
      (yyval.attr_info)->nullable = false;
      free((yyvsp[-1].string));
    }
#line 2144 "yacc_sql.cpp"
    break;

  case 44: /* attr_def: ID type LBRACE number RBRACE NULLABLE  */
#line 444 "yacc_sql.y"
    {
      (yyval.attr_info) = new AttrInfoSqlNode;
      (yyval.attr_info)->type = (AttrType)(yyvsp[-4].number);
      (yyval.attr_info)->name = (yyvsp[-5].string);
      if ((yyval.attr_info)->type == AttrType::TEXTS) {
        (yyval.attr_info)->length = MAX_TEXT_LENGTH;
      }
      else {
        (yyval.attr_info)->length = (yyvsp[-2].number);
      }
      (yyval.attr_info)->nullable = true;
      free((yyvsp[-5].string));
    }
#line 2162 "yacc_sql.cpp"
    break;

  case 45: /* attr_def: ID type NULLABLE  */
#line 458 "yacc_sql.y"
    {
      (yyval.attr_info) = new AttrInfoSqlNode;
      (yyval.attr_info)->type = (AttrType)(yyvsp[-1].number);
      (yyval.attr_info)->name = (yyvsp[-2].string);
      if ((yyval.attr_info)->type == AttrType::TEXTS) {
        (yyval.attr_info)->length = MAX_TEXT_LENGTH;
      }
      else {
        (yyval.attr_info)->length = 4;
      }
      (yyval.attr_info)->nullable = true;
      free((yyvsp[-2].string));
    }
#line 2180 "yacc_sql.cpp"
    break;

  case 46: /* attr_def: ID type LBRACE number RBRACE NOT NULL_T  */
#line 472 "yacc_sql.y"
    {
      (yyval.attr_info) = new AttrInfoSqlNode;
      (yyval.attr_info)->type = (AttrType)(yyvsp[-5].number);
      (yyval.attr_info)->name = (yyvsp[-6].string);
      if ((yyval.attr_info)->type == AttrType::TEXTS) {
        (yyval.attr_info)->length = MAX_TEXT_LENGTH;
      }
      else {
        (yyval.attr_info)->length = (yyvsp[-3].number);
      }
      (yyval.attr_info)->nullable = false;
      free((yyvsp[-6].string));
    }
#line 2198 "yacc_sql.cpp"
    break;

  case 47: /* attr_def: ID type NOT NULL_T  */
#line 486 "yacc_sql.y"
    {
      (yyval.attr_info) = new AttrInfoSqlNode;
      (yyval.attr_info)->type = (AttrType)(yyvsp[-2].number);
      (yyval.attr_info)->name = (yyvsp[-3].string);
      if ((yyval.attr_info)->type == AttrType::TEXTS) {
        (yyval.attr_info)->length = MAX_TEXT_LENGTH;
      }
      else {
        (yyval.attr_info)->length = 4;
      }
      (yyval.attr_info)->nullable = false;
      free((yyvsp[-3].string));
    }
#line 2216 "yacc_sql.cpp"
    break;

  case 48: /* number: NUMBER  */
#line 501 "yacc_sql.y"
           {(yyval.number) = (yyvsp[0].number);}
#line 2222 "yacc_sql.cpp"
    break;

  case 49: /* type: INT_T  */
#line 504 "yacc_sql.y"
               { (yyval.number)=INTS; }
#line 2228 "yacc_sql.cpp"
    break;

  case 50: /* type: STRING_T  */
#line 505 "yacc_sql.y"
               { (yyval.number)=CHARS; }
#line 2234 "yacc_sql.cpp"
    break;

  case 51: /* type: FLOAT_T  */
#line 506 "yacc_sql.y"
               { (yyval.number)=FLOATS; }
#line 2240 "yacc_sql.cpp"
    break;

  case 52: /* type: DATE_T  */
#line 507 "yacc_sql.y"
                { (yyval.number)=DATES;}
#line 2246 "yacc_sql.cpp"
    break;

  case 53: /* type: TEXT_T  */
#line 508 "yacc_sql.y"
                { (yyval.number)=TEXTS;}
#line 2252 "yacc_sql.cpp"
    break;

  case 54: /* insert_stmt: INSERT INTO ID VALUES insert_value insert_value_list  */
#line 512 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_INSERT);
      (yyval.sql_node)->insertion.relation_name = (yyvsp[-3].string);
      free((yyvsp[-3].string));

      std::vector<InsertValueSqlNode> *src_insertv = (yyvsp[0].insert_value_list);
      if (src_insertv != nullptr) {
        (yyval.sql_node)->insertion.insert_values.swap(*src_insertv);
      }
      (yyval.sql_node)->insertion.insert_values.emplace_back(*(yyvsp[-1].insert_value));
      std::reverse((yyval.sql_node)->insertion.insert_values.begin(), (yyval.sql_node)->insertion.insert_values.end());
      delete (yyvsp[-1].insert_value);
      
    }
#line 2271 "yacc_sql.cpp"
    break;

  case 55: /* insert_value_list: %empty  */
#line 529 "yacc_sql.y"
    {
      (yyval.insert_value_list) = nullptr;
    }
#line 2279 "yacc_sql.cpp"
    break;

  case 56: /* insert_value_list: COMMA insert_value insert_value_list  */
#line 533 "yacc_sql.y"
    {
      if ((yyvsp[0].insert_value_list) != nullptr) {
        (yyval.insert_value_list) = (yyvsp[0].insert_value_list);
      } else {
        (yyval.insert_value_list) = new std::vector<InsertValueSqlNode>;
      }
      (yyval.insert_value_list)->emplace_back(*(yyvsp[-1].insert_value));
      delete (yyvsp[-1].insert_value);
    }
#line 2293 "yacc_sql.cpp"
    break;

  case 57: /* insert_value: LBRACE value value_list RBRACE  */
#line 545 "yacc_sql.y"
    {
        (yyval.insert_value) = new InsertValueSqlNode;
        if((yyvsp[-1].value_list) != nullptr){
          (yyval.insert_value)->values.swap(*(yyvsp[-1].value_list));
        }
        (yyval.insert_value)->values.emplace_back(*(yyvsp[-2].value));
        std::reverse((yyval.insert_value)->values.begin(),(yyval.insert_value)->values.end());
        delete (yyvsp[-2].value);
    }
#line 2307 "yacc_sql.cpp"
    break;

  case 58: /* value_list: %empty  */
#line 559 "yacc_sql.y"
    {
      (yyval.value_list) = nullptr;
    }
#line 2315 "yacc_sql.cpp"
    break;

  case 59: /* value_list: COMMA express value_list  */
#line 562 "yacc_sql.y"
                                { 
      if ((yyvsp[0].value_list) != nullptr) {
        (yyval.value_list) = (yyvsp[0].value_list);
      } else {
        (yyval.value_list) = new std::vector<Value>;
      }
      if ((yyvsp[-1].express)->type == ExpressType::EXPR_T && (yyvsp[-1].express)->comp == ExprOp::NEGATIVE) {
        if ((yyvsp[-1].express)->left_value.attr_type() == AttrType::INTS) {
          (yyvsp[-1].express)->left_value.set_int(-(yyvsp[-1].express)->left_value.get_int());
        } else {
          (yyvsp[-1].express)->left_value.set_float(-(yyvsp[-1].express)->left_value.get_float());
        }
      }
      (yyval.value_list)->emplace_back((yyvsp[-1].express)->left_value);
      delete (yyvsp[-1].express);
    }
#line 2336 "yacc_sql.cpp"
    break;

  case 60: /* value: NUMBER  */
#line 580 "yacc_sql.y"
           {
      (yyval.value) = new Value((int)(yyvsp[0].number));
      (yyloc) = (yylsp[0]);
    }
#line 2345 "yacc_sql.cpp"
    break;

  case 61: /* value: FLOAT  */
#line 584 "yacc_sql.y"
           {
      (yyval.value) = new Value((float)(yyvsp[0].floats));
      (yyloc) = (yylsp[0]);
    }
#line 2354 "yacc_sql.cpp"
    break;

  case 62: /* value: DATE_STR  */
#line 588 "yacc_sql.y"
               {
      char *tmp = common::substr((yyvsp[0].string),1,strlen((yyvsp[0].string))-2);
      int y, m, d;
      sscanf(tmp, "%d-%d-%d", &y, &m, &d);


      (yyval.value) = new Value(y,m,d);

      
    }
#line 2369 "yacc_sql.cpp"
    break;

  case 63: /* value: SSS  */
#line 598 "yacc_sql.y"
         {
      char *tmp = common::substr((yyvsp[0].string),1,strlen((yyvsp[0].string))-2);
      (yyval.value) = new Value(tmp);
      free(tmp);
    }
#line 2379 "yacc_sql.cpp"
    break;

  case 64: /* value: null_or_nullable  */
#line 603 "yacc_sql.y"
                     {
      (yyval.value) = new Value(0);
      
      (yyval.value)->set_null(nullptr,4);
      
      
    }
#line 2391 "yacc_sql.cpp"
    break;

  case 65: /* delete_stmt: DELETE FROM ID where  */
#line 615 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_DELETE);
      (yyval.sql_node)->deletion.relation_name = (yyvsp[-1].string);
      if ((yyvsp[0].condition_list) != nullptr) {
        (yyval.sql_node)->deletion.conditions.swap(*(yyvsp[0].condition_list));
        delete (yyvsp[0].condition_list);
      }
      free((yyvsp[-1].string));
    }
#line 2405 "yacc_sql.cpp"
    break;

  case 66: /* update_stmt: UPDATE ID SET set_value set_value_list where  */
#line 627 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_UPDATE);
      (yyval.sql_node)->update.relation_name = (yyvsp[-4].string);

      std::vector<UpdateValueSqlNode> *src_update_values = (yyvsp[-1].update_value_list);
      if (src_update_values != nullptr) {
        (yyval.sql_node)->update.update_values.swap(*src_update_values);
      }
      (yyval.sql_node)->update.update_values.emplace_back(*(yyvsp[-2].update_value));
      std::reverse((yyval.sql_node)->update.update_values.begin(),(yyval.sql_node)->update.update_values.end());
      delete (yyvsp[-2].update_value);
      if ((yyvsp[0].condition_list) != nullptr) {
        (yyval.sql_node)->update.conditions.swap(*(yyvsp[0].condition_list));
        delete (yyvsp[0].condition_list);
      }
    }
#line 2426 "yacc_sql.cpp"
    break;

  case 67: /* set_value_list: %empty  */
#line 646 "yacc_sql.y"
    {
      (yyval.update_value_list) = nullptr;
    }
#line 2434 "yacc_sql.cpp"
    break;

  case 68: /* set_value_list: COMMA set_value set_value_list  */
#line 649 "yacc_sql.y"
                                   {
      if ((yyvsp[0].update_value_list) != nullptr) {
        (yyval.update_value_list) = (yyvsp[0].update_value_list);
      } else {
        (yyval.update_value_list) = new std::vector<UpdateValueSqlNode>;
      }
      (yyval.update_value_list)->emplace_back(*(yyvsp[-1].update_value));
      delete (yyvsp[-1].update_value);

    }
#line 2449 "yacc_sql.cpp"
    break;

  case 69: /* set_value: ID EQ express  */
#line 662 "yacc_sql.y"
    {
      (yyval.update_value) = new UpdateValueSqlNode;
      (yyval.update_value)->name = (yyvsp[-2].string);
      if ((yyvsp[0].express)->type == VALUE_T || (yyvsp[0].express)->type == ExpressType::EXPR_T) {
        if ((yyvsp[0].express)->type == ExpressType::EXPR_T && (yyvsp[0].express)->comp == ExprOp::NEGATIVE) {
          if ((yyvsp[0].express)->left_value.attr_type() == AttrType::INTS) {
            (yyvsp[0].express)->left_value.set_int(-(yyvsp[0].express)->left_value.get_int());
          } else {
            (yyvsp[0].express)->left_value.set_float(-(yyvsp[0].express)->left_value.get_float());
          }
        }
        (yyval.update_value)->value = (yyvsp[0].express)->left_value;
      }
      else {
        (yyval.update_value)->select_sql_node =  *((yyvsp[0].express)->left_selects);
        (yyval.update_value)->is_right_selects = true;
      }

      delete (yyvsp[-2].string);
      delete (yyvsp[0].express);
    }
#line 2475 "yacc_sql.cpp"
    break;

  case 70: /* select_stmt: SELECT select_attr FROM rel_list where order_by group_by having_clause  */
#line 694 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_SELECT);
      if ((yyvsp[-6].express_list) != nullptr) {
        (yyval.sql_node)->selection.attributes.swap(*(yyvsp[-6].express_list));
        delete (yyvsp[-6].express_list);
      }
     
      (yyval.sql_node)->selection.relations.swap(*(yyvsp[-4].relation_list));
      delete (yyvsp[-4].relation_list);
      
      std::reverse((yyval.sql_node)->selection.relations.begin(), (yyval.sql_node)->selection.relations.end());

      if ((yyvsp[-3].condition_list) != nullptr) {
        (yyval.sql_node)->selection.conditions.swap(*(yyvsp[-3].condition_list));
        delete (yyvsp[-3].condition_list);
      }
      if ((yyvsp[-2].order_list) != nullptr) {
        (yyval.sql_node)->selection.order_by_sql_nodes.swap(*(yyvsp[-2].order_list));
        delete (yyvsp[-2].order_list);
      }

      if((yyvsp[-1].rel_attr_list) != nullptr){
        (yyval.sql_node)->selection.group_by_attributes.swap (*(yyvsp[-1].rel_attr_list));
        delete (yyvsp[-1].rel_attr_list);
      }
      if ((yyvsp[0].condition_list) != nullptr) {
        (yyval.sql_node)->selection.having_conditions.swap(*(yyvsp[0].condition_list));
        delete (yyvsp[0].condition_list);
      }

    }
#line 2511 "yacc_sql.cpp"
    break;

  case 71: /* select_stmt: SELECT select_attr  */
#line 726 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_SELECT);
      if((yyvsp[0].express_list) != nullptr){
        (yyval.sql_node)->selection.attributes.swap(*(yyvsp[0].express_list));
        delete (yyvsp[0].express_list);
      }

    }
#line 2524 "yacc_sql.cpp"
    break;

  case 72: /* calc_stmt: CALC expression_list  */
#line 737 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_CALC);
      std::reverse((yyvsp[0].expression_list)->begin(), (yyvsp[0].expression_list)->end());
      (yyval.sql_node)->calc.expressions.swap(*(yyvsp[0].expression_list));
      delete (yyvsp[0].expression_list);
    }
#line 2535 "yacc_sql.cpp"
    break;

  case 73: /* expression_list: expression  */
#line 747 "yacc_sql.y"
    {
      (yyval.expression_list) = new std::vector<Expression*>;
      (yyval.expression_list)->emplace_back((yyvsp[0].expression));
    }
#line 2544 "yacc_sql.cpp"
    break;

  case 74: /* expression_list: expression COMMA expression_list  */
#line 752 "yacc_sql.y"
    {
      if ((yyvsp[0].expression_list) != nullptr) {
        (yyval.expression_list) = (yyvsp[0].expression_list);
      } else {
        (yyval.expression_list) = new std::vector<Expression *>;
      }
      (yyval.expression_list)->emplace_back((yyvsp[-2].expression));
    }
#line 2557 "yacc_sql.cpp"
    break;

  case 75: /* expression: expression '+' expression  */
#line 762 "yacc_sql.y"
                              {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::ADD, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2565 "yacc_sql.cpp"
    break;

  case 76: /* expression: expression '-' expression  */
#line 765 "yacc_sql.y"
                                {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::SUB, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2573 "yacc_sql.cpp"
    break;

  case 77: /* expression: expression '*' expression  */
#line 768 "yacc_sql.y"
                                {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::MUL, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2581 "yacc_sql.cpp"
    break;

  case 78: /* expression: expression '/' expression  */
#line 771 "yacc_sql.y"
                                {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::DIV, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2589 "yacc_sql.cpp"
    break;

  case 79: /* expression: LBRACE expression RBRACE  */
#line 774 "yacc_sql.y"
                               {
      (yyval.expression) = (yyvsp[-1].expression);
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));
    }
#line 2598 "yacc_sql.cpp"
    break;

  case 80: /* expression: '-' expression  */
#line 778 "yacc_sql.y"
                                  {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::NEGATIVE, (yyvsp[0].expression), nullptr, sql_string, &(yyloc));
    }
#line 2606 "yacc_sql.cpp"
    break;

  case 81: /* expression: value  */
#line 781 "yacc_sql.y"
            {
      (yyval.expression) = new ValueExpr(*(yyvsp[0].value));
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));
      delete (yyvsp[0].value);
    }
#line 2616 "yacc_sql.cpp"
    break;

  case 82: /* express: express '+' express  */
#line 789 "yacc_sql.y"
                        {
      (yyval.express) = new ExprSqlNode;
      (yyval.express)->name = token_name(sql_string, &(yyloc));
      (yyval.express)->type = ExpressType::EXPR_T;
      (yyval.express)->add_left_child((yyvsp[-2].express));
      (yyval.express)->comp = ExprOp::ADD;
      (yyval.express)->add_right_child((yyvsp[0].express));
    }
#line 2629 "yacc_sql.cpp"
    break;

  case 83: /* express: express '-' express  */
#line 797 "yacc_sql.y"
                          {
      (yyval.express) = new ExprSqlNode;
      (yyval.express)->name = token_name(sql_string, &(yyloc));
      (yyval.express)->type = ExpressType::EXPR_T;
      (yyval.express)->add_left_child((yyvsp[-2].express));
      (yyval.express)->comp = ExprOp::SUB;
      (yyval.express)->add_right_child((yyvsp[0].express));
    }
#line 2642 "yacc_sql.cpp"
    break;

  case 84: /* express: express '*' express  */
#line 805 "yacc_sql.y"
                          {
      (yyval.express) = new ExprSqlNode;
      (yyval.express)->name = token_name(sql_string, &(yyloc));
      (yyval.express)->type = ExpressType::EXPR_T;
      (yyval.express)->add_left_child((yyvsp[-2].express));
      (yyval.express)->comp = ExprOp::MUL;
      (yyval.express)->add_right_child((yyvsp[0].express));
    }
#line 2655 "yacc_sql.cpp"
    break;

  case 85: /* express: express '/' express  */
#line 813 "yacc_sql.y"
                          {
      (yyval.express) = new ExprSqlNode;
      (yyval.express)->name = token_name(sql_string, &(yyloc));
      (yyval.express)->type = ExpressType::EXPR_T;
      (yyval.express)->add_left_child((yyvsp[-2].express));
      (yyval.express)->comp = ExprOp::DIV;
      (yyval.express)->add_right_child((yyvsp[0].express));
    }
#line 2668 "yacc_sql.cpp"
    break;

  case 86: /* express: LBRACE express RBRACE  */
#line 821 "yacc_sql.y"
                            {
      (yyval.express) = (yyvsp[-1].express);
      (yyval.express)->name = token_name(sql_string, &(yyloc));
    }
#line 2677 "yacc_sql.cpp"
    break;

  case 87: /* express: '-' express  */
#line 825 "yacc_sql.y"
                               {
      (yyval.express) = new ExprSqlNode;
      (yyval.express)->name = token_name(sql_string, &(yyloc));
      (yyval.express)->type = ExpressType::EXPR_T;
      (yyval.express)->add_left_child((yyvsp[0].express));
      (yyval.express)->comp = ExprOp::NEGATIVE;
    }
#line 2689 "yacc_sql.cpp"
    break;

  case 88: /* express: value  */
#line 832 "yacc_sql.y"
            {
      (yyval.express) = new ExprSqlNode;
      (yyval.express)->name = token_name(sql_string, &(yyloc));
      (yyval.express)->type = ExpressType::VALUE_T;
      (yyval.express)->left_value = *(yyvsp[0].value);
      delete (yyvsp[0].value);
    }
#line 2701 "yacc_sql.cpp"
    break;

  case 89: /* express: ID as_alias  */
#line 839 "yacc_sql.y"
                 {
      (yyval.express) = new ExprSqlNode;
      (yyval.express)->name = token_name(sql_string, &(yyloc));
      (yyval.express)->type = ExpressType::ATTR_T;
      (yyval.express)->left_attr.attribute_name = (yyvsp[-1].string);
      if((yyvsp[0].string)!=nullptr){
        (yyval.express)->left_attr.has_alias = true;
        (yyval.express)->left_attr.alias = (yyvsp[0].string);
      }
      free((yyvsp[-1].string));
    }
#line 2717 "yacc_sql.cpp"
    break;

  case 90: /* express: ID DOT ID as_alias  */
#line 850 "yacc_sql.y"
                        {
      (yyval.express) = new ExprSqlNode;
      (yyval.express)->name = token_name(sql_string, &(yyloc));
      (yyval.express)->type = ExpressType::ATTR_T;
      (yyval.express)->left_attr.relation_name = (yyvsp[-3].string);
      (yyval.express)->left_attr.attribute_name = (yyvsp[-1].string);
      if((yyvsp[0].string) != nullptr){
        (yyval.express)->left_attr.has_alias = true;
        (yyval.express)->left_attr.alias = (yyvsp[0].string);
      }
      free((yyvsp[-3].string));
      free((yyvsp[-1].string));
    }
#line 2735 "yacc_sql.cpp"
    break;

  case 91: /* express: ID DOT '*' as_alias  */
#line 863 "yacc_sql.y"
                         {
      (yyval.express) = new ExprSqlNode;
      (yyval.express)->name = token_name(sql_string, &(yyloc));
      (yyval.express)->type = ExpressType::ATTR_T;
      (yyval.express)->left_attr.relation_name = (yyvsp[-3].string);
      (yyval.express)->left_attr.attribute_name = "*";
      if((yyvsp[0].string) != nullptr){
        (yyval.express)->left_attr.has_alias = true;
        (yyval.express)->left_attr.alias = (yyvsp[0].string);
      }
      free((yyvsp[-3].string));
    }
#line 2752 "yacc_sql.cpp"
    break;

  case 92: /* express: function  */
#line 875 "yacc_sql.y"
               {
      (yyval.express) = new ExprSqlNode;
      (yyval.express)->name = token_name(sql_string, &(yyloc));
      (yyval.express)->type = ExpressType::ATTR_T;
      (yyval.express)->left_attr = *(yyvsp[0].function);
      free((yyvsp[0].function));
    }
#line 2764 "yacc_sql.cpp"
    break;

  case 93: /* express: aggregation_func LBRACE ID RBRACE as_alias  */
#line 882 "yacc_sql.y"
                                                {    
      (yyval.express) = new ExprSqlNode;
      (yyval.express)->name = token_name(sql_string, &(yyloc));
      (yyval.express)->type = ExpressType::ATTR_T;
      (yyval.express)->left_attr.attribute_name = (yyvsp[-2].string);
      free((yyvsp[-2].string));
      (yyval.express)->left_attr.is_aggregation_func = true;
      (yyval.express)->left_attr.aggr_func_type = (yyvsp[-4].aggr_func);
      if((yyvsp[0].string) != nullptr){
        (yyval.express)->left_attr.has_alias = true;
        (yyval.express)->left_attr.alias = (yyvsp[0].string);
      }
    }
#line 2782 "yacc_sql.cpp"
    break;

  case 94: /* express: aggregation_func LBRACE ID DOT ID RBRACE as_alias  */
#line 895 "yacc_sql.y"
                                                       {
      (yyval.express) = new ExprSqlNode;
      (yyval.express)->name = token_name(sql_string, &(yyloc));
      (yyval.express)->type = ExpressType::ATTR_T;
      (yyval.express)->left_attr.relation_name  = (yyvsp[-4].string);
      (yyval.express)->left_attr.attribute_name = (yyvsp[-2].string);
      free((yyvsp[-4].string));
      free((yyvsp[-2].string));
      (yyval.express)->left_attr.is_aggregation_func = true;
      (yyval.express)->left_attr.aggr_func_type = (yyvsp[-6].aggr_func);
      if((yyvsp[0].string) != nullptr){
        (yyval.express)->left_attr.has_alias = true;
        (yyval.express)->left_attr.alias = (yyvsp[0].string);
      }
    }
#line 2802 "yacc_sql.cpp"
    break;

  case 95: /* express: aggregation_func LBRACE '*' RBRACE as_alias  */
#line 910 "yacc_sql.y"
                                                 {
      (yyval.express) = new ExprSqlNode;
      (yyval.express)->name = token_name(sql_string, &(yyloc));
      (yyval.express)->type = ExpressType::ATTR_T;
      (yyval.express)->left_attr.relation_name = "";
      (yyval.express)->left_attr.attribute_name = "*";
      (yyval.express)->left_attr.is_aggregation_func = true;
      (yyval.express)->left_attr.aggr_func_type = (yyvsp[-4].aggr_func);
      if((yyvsp[0].string) != nullptr){
        (yyval.express)->left_attr.has_alias = true;
        (yyval.express)->left_attr.alias = (yyvsp[0].string);
      }
    }
#line 2820 "yacc_sql.cpp"
    break;

  case 96: /* express: aggregation_func LBRACE RBRACE  */
#line 923 "yacc_sql.y"
                                    {
      (yyval.express) = new ExprSqlNode;
      (yyval.express)->name = token_name(sql_string, &(yyloc));
      (yyval.express)->type = ExpressType::ATTR_T;
      (yyval.express)->left_attr.is_syntax_error = true;
    }
#line 2831 "yacc_sql.cpp"
    break;

  case 97: /* express: aggregation_func LBRACE rel_attr COMMA rel_attr attr_list RBRACE  */
#line 929 "yacc_sql.y"
                                                                      {
      (yyval.express) = new ExprSqlNode;
      (yyval.express)->name = token_name(sql_string, &(yyloc));
      (yyval.express)->type = ExpressType::ATTR_T;
      (yyval.express)->left_attr.is_syntax_error = true;
      delete (yyvsp[-4].rel_attr);
      delete (yyvsp[-2].rel_attr);
      delete (yyvsp[-1].rel_attr_list);
    }
#line 2845 "yacc_sql.cpp"
    break;

  case 98: /* express: aggregation_func LBRACE '*' COMMA rel_attr attr_list RBRACE  */
#line 938 "yacc_sql.y"
                                                                 {
      (yyval.express) = new ExprSqlNode;
      (yyval.express)->name = token_name(sql_string, &(yyloc));
      (yyval.express)->type = ExpressType::ATTR_T;
      (yyval.express)->left_attr.is_syntax_error = true;
      delete (yyvsp[-2].rel_attr);
      delete (yyvsp[-1].rel_attr_list);
    }
#line 2858 "yacc_sql.cpp"
    break;

  case 99: /* express: LBRACE select_stmt RBRACE  */
#line 947 "yacc_sql.y"
    {
      (yyval.express) = new ExprSqlNode;
      (yyval.express)->name = token_name(sql_string, &(yyloc));
      (yyval.express)->type = ExpressType::SELECT_T;
      (yyval.express)->left_selects = &((yyvsp[-1].sql_node)->selection);
    }
#line 2869 "yacc_sql.cpp"
    break;

  case 100: /* express: LBRACE express COMMA express express_list RBRACE  */
#line 954 "yacc_sql.y"
    {
      (yyval.express) = new ExprSqlNode;
      (yyval.express)->name = token_name(sql_string, &(yyloc));
      (yyval.express)->type = ExpressType::EXPR_LIST_T;
      if ((yyvsp[-1].express_list) != nullptr) {
        (yyval.express)->expr_list.swap(*(yyvsp[-1].express_list));
      }
      (yyval.express)->expr_list.emplace_back((yyvsp[-2].express));
      (yyval.express)->expr_list.emplace_back((yyvsp[-4].express));
    }
#line 2884 "yacc_sql.cpp"
    break;

  case 101: /* select_attr: '*' express_list  */
#line 987 "yacc_sql.y"
                     {
      if((yyvsp[0].express_list) != nullptr){
        (yyval.express_list) = (yyvsp[0].express_list);
      } else {
        (yyval.express_list) = new std::vector<ExprSqlNode *>;
      }
      ExprSqlNode *expr_sql_node = new ExprSqlNode;
      expr_sql_node->type = ExpressType::ATTR_T;
      expr_sql_node->left_attr.relation_name  = "";
      expr_sql_node->left_attr.attribute_name = "*";
      (yyval.express_list)->emplace_back(expr_sql_node);
    }
#line 2901 "yacc_sql.cpp"
    break;

  case 102: /* select_attr: express express_list  */
#line 999 "yacc_sql.y"
                           {
      if ((yyvsp[0].express_list) != nullptr) {
        (yyval.express_list) = (yyvsp[0].express_list);
      } else {
        (yyval.express_list) = new std::vector<ExprSqlNode *>;
      }
      (yyval.express_list)->emplace_back((yyvsp[-1].express));
    }
#line 2914 "yacc_sql.cpp"
    break;

  case 103: /* aggregation_func: MAX_FUNC  */
#line 1009 "yacc_sql.y"
            {
      (yyval.aggr_func) = MAX;
    }
#line 2922 "yacc_sql.cpp"
    break;

  case 104: /* aggregation_func: MIN_FUNC  */
#line 1012 "yacc_sql.y"
              {
      (yyval.aggr_func) = MIN;
    }
#line 2930 "yacc_sql.cpp"
    break;

  case 105: /* aggregation_func: CNT_FUNC  */
#line 1015 "yacc_sql.y"
              {
      (yyval.aggr_func) = CNT;
    }
#line 2938 "yacc_sql.cpp"
    break;

  case 106: /* aggregation_func: AVG_FUNC  */
#line 1018 "yacc_sql.y"
              {
      (yyval.aggr_func) = AVG;
    }
#line 2946 "yacc_sql.cpp"
    break;

  case 107: /* aggregation_func: SUM_FUNC  */
#line 1021 "yacc_sql.y"
              {
      (yyval.aggr_func) = SUM;
    }
#line 2954 "yacc_sql.cpp"
    break;

  case 108: /* rel_attr: ID as_alias  */
#line 1027 "yacc_sql.y"
               {
      (yyval.rel_attr) = new RelAttrSqlNode;
      (yyval.rel_attr)->attribute_name = (yyvsp[-1].string);
      free((yyvsp[-1].string));

     
      if((yyvsp[0].string) !=nullptr){
        (yyval.rel_attr)->has_alias = true;
        (yyval.rel_attr)->alias = (yyvsp[0].string);
        free((yyvsp[0].string));
      }
    }
#line 2971 "yacc_sql.cpp"
    break;

  case 109: /* rel_attr: ID DOT ID as_alias  */
#line 1039 "yacc_sql.y"
                        {
      (yyval.rel_attr) = new RelAttrSqlNode;
      (yyval.rel_attr)->relation_name  = (yyvsp[-3].string);
      (yyval.rel_attr)->attribute_name = (yyvsp[-1].string);
      free((yyvsp[-3].string));
      free((yyvsp[-1].string));
      

      if((yyvsp[0].string) !=nullptr){
        (yyval.rel_attr)->has_alias = true;
        (yyval.rel_attr)->alias = (yyvsp[0].string);
        free((yyvsp[0].string));
      }
    }
#line 2990 "yacc_sql.cpp"
    break;

  case 110: /* rel_attr: function  */
#line 1054 "yacc_sql.y"
    {
      (yyval.rel_attr) = (yyvsp[0].function);
    }
#line 2998 "yacc_sql.cpp"
    break;

  case 111: /* rel_attr: aggregation_func LBRACE ID RBRACE  */
#line 1057 "yacc_sql.y"
                                       {
      (yyval.rel_attr) = new RelAttrSqlNode;
      (yyval.rel_attr)->attribute_name = (yyvsp[-1].string);
      free((yyvsp[-1].string));
      (yyval.rel_attr)->is_aggregation_func = true;
      (yyval.rel_attr)->aggr_func_type = (yyvsp[-3].aggr_func);

    }
#line 3011 "yacc_sql.cpp"
    break;

  case 112: /* rel_attr: aggregation_func LBRACE ID DOT ID RBRACE  */
#line 1065 "yacc_sql.y"
                                              {
      (yyval.rel_attr) = new RelAttrSqlNode;
      (yyval.rel_attr)->relation_name  = (yyvsp[-3].string);
      (yyval.rel_attr)->attribute_name = (yyvsp[-1].string);
      free((yyvsp[-3].string));
      free((yyvsp[-1].string));
      (yyval.rel_attr)->is_aggregation_func = true;
      (yyval.rel_attr)->aggr_func_type = (yyvsp[-5].aggr_func);

    }
#line 3026 "yacc_sql.cpp"
    break;

  case 113: /* rel_attr: aggregation_func LBRACE '*' RBRACE  */
#line 1075 "yacc_sql.y"
                                        {
      (yyval.rel_attr) = new RelAttrSqlNode;
      (yyval.rel_attr)->relation_name = "";
      (yyval.rel_attr)->attribute_name = "*";
      (yyval.rel_attr)->is_aggregation_func = true;
      (yyval.rel_attr)->aggr_func_type = (yyvsp[-3].aggr_func);

    }
#line 3039 "yacc_sql.cpp"
    break;

  case 114: /* rel_attr: aggregation_func LBRACE RBRACE  */
#line 1083 "yacc_sql.y"
                                    {
      (yyval.rel_attr) = new RelAttrSqlNode;
      (yyval.rel_attr)->is_syntax_error = true;
      (yyval.rel_attr)->aggr_func_type = (yyvsp[-2].aggr_func);

    }
#line 3050 "yacc_sql.cpp"
    break;

  case 115: /* rel_attr: aggregation_func LBRACE rel_attr COMMA rel_attr attr_list RBRACE  */
#line 1089 "yacc_sql.y"
                                                                      {
      (yyval.rel_attr) = new RelAttrSqlNode;
      (yyval.rel_attr)->is_syntax_error = true;
      delete (yyvsp[-4].rel_attr);
      delete (yyvsp[-2].rel_attr);
      delete (yyvsp[-1].rel_attr_list);

    }
#line 3063 "yacc_sql.cpp"
    break;

  case 116: /* rel_attr: aggregation_func LBRACE '*' COMMA rel_attr attr_list RBRACE  */
#line 1097 "yacc_sql.y"
                                                                 {
      (yyval.rel_attr) = new RelAttrSqlNode;
      (yyval.rel_attr)->is_syntax_error = true;
      delete (yyvsp[-2].rel_attr);
      delete (yyvsp[-1].rel_attr_list);

    }
#line 3075 "yacc_sql.cpp"
    break;

  case 117: /* as_alias: %empty  */
#line 1107 "yacc_sql.y"
    {
      (yyval.string) = nullptr;
    }
#line 3083 "yacc_sql.cpp"
    break;

  case 118: /* as_alias: AS ID  */
#line 1110 "yacc_sql.y"
           {
      (yyval.string) = (char*)malloc(strlen((yyvsp[0].string))+1);
      strcpy((yyval.string),(yyvsp[0].string));
      free((yyvsp[0].string));
    }
#line 3093 "yacc_sql.cpp"
    break;

  case 119: /* as_alias: AS ID DOT ID  */
#line 1115 "yacc_sql.y"
                  {
      (yyval.string) = (char*)malloc(strlen((yyvsp[-2].string))+strlen((yyvsp[0].string))+2);
      strcpy((yyval.string),(yyvsp[-2].string));
      strcpy((yyval.string)+strlen((yyvsp[-2].string)),".");
      strcpy((yyval.string)+strlen((yyvsp[-2].string))+1,(yyvsp[0].string));
      free((yyvsp[-2].string));
      free((yyvsp[0].string));
    }
#line 3106 "yacc_sql.cpp"
    break;

  case 120: /* as_alias: ID  */
#line 1123 "yacc_sql.y"
        {
      (yyval.string) = (char*)malloc(strlen((yyvsp[0].string))+1);
      strcpy((yyval.string),(yyvsp[0].string));
      free((yyvsp[0].string));
    }
#line 3116 "yacc_sql.cpp"
    break;

  case 121: /* as_alias: ID DOT ID  */
#line 1128 "yacc_sql.y"
               {
      (yyval.string) = (char*)malloc(strlen((yyvsp[-2].string))+strlen((yyvsp[0].string))+2);
      strcpy((yyval.string),(yyvsp[-2].string));
      strcpy((yyval.string)+strlen((yyvsp[-2].string)),".");
      strcpy((yyval.string)+strlen((yyvsp[-2].string))+1,(yyvsp[0].string));
      free((yyvsp[-2].string));
      free((yyvsp[0].string));
    }
#line 3129 "yacc_sql.cpp"
    break;

  case 122: /* attr_list: %empty  */
#line 1139 "yacc_sql.y"
    {
      (yyval.rel_attr_list) = nullptr;
    }
#line 3137 "yacc_sql.cpp"
    break;

  case 123: /* attr_list: COMMA rel_attr attr_list  */
#line 1142 "yacc_sql.y"
                               {
      if ((yyvsp[0].rel_attr_list) != nullptr) {
        (yyval.rel_attr_list) = (yyvsp[0].rel_attr_list);
      } else {
        (yyval.rel_attr_list) = new std::vector<RelAttrSqlNode>;
      }

      (yyval.rel_attr_list)->emplace_back(*(yyvsp[-1].rel_attr));
      delete (yyvsp[-1].rel_attr);
    }
#line 3152 "yacc_sql.cpp"
    break;

  case 124: /* express_list: %empty  */
#line 1156 "yacc_sql.y"
    {
      (yyval.express_list) = nullptr;
    }
#line 3160 "yacc_sql.cpp"
    break;

  case 125: /* express_list: COMMA express express_list  */
#line 1159 "yacc_sql.y"
                                 {
      if ((yyvsp[0].express_list) != nullptr) {
        (yyval.express_list) = (yyvsp[0].express_list);
      } else {
        (yyval.express_list) = new std::vector<ExprSqlNode *>;
      }

      (yyval.express_list)->emplace_back((yyvsp[-1].express));
    }
#line 3174 "yacc_sql.cpp"
    break;

  case 126: /* inner_join: INNER JOIN ID ON condition_list  */
#line 1172 "yacc_sql.y"
    {
        (yyval.join_rel) = new JoinedRelationSqlNode;
        (yyval.join_rel)->relations.push_back((yyvsp[-2].string));
        for(auto iter:*(yyvsp[0].condition_list)){
          (yyval.join_rel)->join_on_conditions.emplace_back(iter);
        }
        // free($3);
    }
#line 3187 "yacc_sql.cpp"
    break;

  case 127: /* inner_join_list: %empty  */
#line 1182 "yacc_sql.y"
    {
      (yyval.join_rel) = nullptr;
    }
#line 3195 "yacc_sql.cpp"
    break;

  case 128: /* inner_join_list: inner_join inner_join_list  */
#line 1186 "yacc_sql.y"
    {
      if((yyvsp[0].join_rel)!=nullptr){
        (yyval.join_rel) = (yyvsp[0].join_rel);
      }else {
        (yyval.join_rel) = new JoinedRelationSqlNode;
      }
      for(auto iter : (yyvsp[-1].join_rel)->relations){
        (yyval.join_rel)->relations.emplace_back(iter);
      }
      for(auto iter : (yyvsp[-1].join_rel)->join_on_conditions){
        (yyval.join_rel)->join_on_conditions.emplace_back(iter);
      }
      // free($1);
    }
#line 3214 "yacc_sql.cpp"
    break;

  case 129: /* join_relation: ID inner_join inner_join_list  */
#line 1203 "yacc_sql.y"
    {
      if((yyvsp[0].join_rel)!=nullptr){
        (yyval.join_rel) = (yyvsp[0].join_rel);
      }else{
        (yyval.join_rel) = new JoinedRelationSqlNode;
      }
      for(auto iter : (yyvsp[-1].join_rel)->relations){
        (yyval.join_rel)->relations.emplace_back(iter);
      }
      // $$->relations.insert($$->relations.end(), $2->relations.begin(), $2->relations.end());
      (yyval.join_rel)->join_on_conditions.insert((yyval.join_rel)->join_on_conditions.end(), (yyvsp[-1].join_rel)->join_on_conditions.begin(), (yyvsp[-1].join_rel)->join_on_conditions.end());
      // for(auto iter : $2->relations){
      //   $$->relations.emplace_back(iter);
      // }
      // for(auto iter : $2->join_on_conditions){
      //   $$->join_on_conditions.emplace_back(iter);
      // }
      (yyval.join_rel)->relations.push_back((yyvsp[-2].string));
      std::reverse((yyval.join_rel)->relations.begin(), (yyval.join_rel)->relations.end());
      std::reverse((yyval.join_rel)->join_on_conditions.begin(), (yyval.join_rel)->join_on_conditions.end());
      // free($1);

    }
#line 3242 "yacc_sql.cpp"
    break;

  case 130: /* rel_element: ID as_alias  */
#line 1230 "yacc_sql.y"
    {
      (yyval.relation) = new RelationSqlNode;
      (yyval.relation) -> relation = (yyvsp[-1].string);
      (yyval.relation) -> has_inner_join = false;
      free((yyvsp[-1].string));

      
      if((yyvsp[0].string) !=nullptr){
        (yyval.relation)->alias = (yyvsp[0].string);
        (yyval.relation)->has_alias = true;
        free((yyvsp[0].string));
      }

    }
#line 3261 "yacc_sql.cpp"
    break;

  case 131: /* rel_element: join_relation  */
#line 1245 "yacc_sql.y"
    {
      (yyval.relation) = new RelationSqlNode;
      (yyval.relation)->inner_join_sql_node = *(yyvsp[0].join_rel);
      (yyval.relation) -> has_inner_join = true;
      // delete $1;

    }
#line 3273 "yacc_sql.cpp"
    break;

  case 132: /* rel_list: rel_element  */
#line 1256 "yacc_sql.y"
    { 
      (yyval.relation_list) = new std::vector<RelationSqlNode>;
      (yyval.relation_list)->emplace_back(*(yyvsp[0].relation));
      // delete $1;
    }
#line 3283 "yacc_sql.cpp"
    break;

  case 133: /* rel_list: rel_element COMMA rel_list  */
#line 1261 "yacc_sql.y"
                                 {
      (yyval.relation_list) = (yyvsp[0].relation_list);
      (yyval.relation_list)->emplace_back(*(yyvsp[-2].relation));
      // delete $1;
    }
#line 3293 "yacc_sql.cpp"
    break;

  case 134: /* where: %empty  */
#line 1269 "yacc_sql.y"
    {
      (yyval.condition_list) = nullptr;
    }
#line 3301 "yacc_sql.cpp"
    break;

  case 135: /* where: WHERE condition_list  */
#line 1272 "yacc_sql.y"
                           {
      (yyval.condition_list) = (yyvsp[0].condition_list);  
    }
#line 3309 "yacc_sql.cpp"
    break;

  case 136: /* having_clause: %empty  */
#line 1278 "yacc_sql.y"
    {
      (yyval.condition_list) = nullptr;
    }
#line 3317 "yacc_sql.cpp"
    break;

  case 137: /* having_clause: HAVING condition_list  */
#line 1281 "yacc_sql.y"
                            {
      (yyval.condition_list) = (yyvsp[0].condition_list);  
    }
#line 3325 "yacc_sql.cpp"
    break;

  case 138: /* condition_list: %empty  */
#line 1288 "yacc_sql.y"
    {
      (yyval.condition_list) = nullptr;
    }
#line 3333 "yacc_sql.cpp"
    break;

  case 139: /* condition_list: condition  */
#line 1291 "yacc_sql.y"
                {
      (yyval.condition_list) = new std::vector<ConditionSqlNode>;
      (yyval.condition_list)->emplace_back(*(yyvsp[0].condition));
      delete (yyvsp[0].condition);
    }
#line 3343 "yacc_sql.cpp"
    break;

  case 140: /* condition_list: condition AND condition_list  */
#line 1296 "yacc_sql.y"
                                   {
      (yyval.condition_list) = (yyvsp[0].condition_list);
      (yyval.condition_list)->emplace_back(*(yyvsp[-2].condition));
      delete (yyvsp[-2].condition);
    }
#line 3353 "yacc_sql.cpp"
    break;

  case 141: /* condition: express comp_op express  */
#line 1353 "yacc_sql.y"
    {
      (yyval.condition) = new ConditionSqlNode;
      if ((yyvsp[-2].express)->type == ExpressType::VALUE_T) {
        (yyval.condition)->left_type = ExpressType::VALUE_T;
        (yyval.condition)->left_value = (yyvsp[-2].express)->left_value;
        delete (yyvsp[-2].express);
      }
      else if ((yyvsp[-2].express)->type == ExpressType::ATTR_T) {
        (yyval.condition)->left_type = ExpressType::ATTR_T;
        (yyval.condition)->left_attr = (yyvsp[-2].express)->left_attr;
        delete (yyvsp[-2].express);
      }
      else if ((yyvsp[-2].express)->type == ExpressType::SELECT_T) {
        (yyval.condition)->left_type = ExpressType::SELECT_T;
        (yyval.condition)->left_selects = (yyvsp[-2].express)->left_selects;
      }
      else if ((yyvsp[-2].express)->type == ExpressType::EXPR_T){
        (yyval.condition)->left_type = ExpressType::EXPR_T;
        (yyval.condition)->left_expr = (yyvsp[-2].express);
      }
      else if ((yyvsp[-2].express)->type == ExpressType::EXPR_LIST_T){
        (yyval.condition)->left_type = ExpressType::EXPR_LIST_T;
        (yyval.condition)->left_expr = (yyvsp[-2].express);
      }
      (yyval.condition)->comp = (yyvsp[-1].comp);
      if ((yyvsp[0].express)->type == ExpressType::VALUE_T) {
        (yyval.condition)->right_type = ExpressType::VALUE_T;
        (yyval.condition)->right_value = (yyvsp[0].express)->left_value;
        delete (yyvsp[0].express);
      }
      else if ((yyvsp[0].express)->type == ExpressType::ATTR_T) {
        (yyval.condition)->right_type = ExpressType::ATTR_T;
        (yyval.condition)->right_attr = (yyvsp[0].express)->left_attr;
        delete (yyvsp[0].express);
      }
      else if ((yyvsp[0].express)->type == ExpressType::SELECT_T) {
        (yyval.condition)->right_type = ExpressType::SELECT_T;
        (yyval.condition)->right_selects = (yyvsp[0].express)->left_selects;
      }
      else if ((yyvsp[0].express)->type == ExpressType::EXPR_T){
        (yyval.condition)->right_type = ExpressType::EXPR_T;
        (yyval.condition)->right_expr = (yyvsp[0].express);
      }
      else if ((yyvsp[0].express)->type == ExpressType::EXPR_LIST_T){
        (yyval.condition)->right_type = ExpressType::EXPR_LIST_T;
        (yyval.condition)->right_expr = (yyvsp[0].express);
      }
    }
#line 3406 "yacc_sql.cpp"
    break;

  case 142: /* condition: comp_op express  */
#line 1402 "yacc_sql.y"
    {
      if((yyvsp[0].express)->type != ExpressType::SELECT_T && ((yyvsp[-1].comp)!=EXISTS_COMP || (yyvsp[-1].comp)!=NOT_EXISTS_COMP)){
          (yyval.condition) = nullptr;
      }else
      {
        (yyval.condition) = new ConditionSqlNode;
        (yyval.condition)->left_type = ExpressType::INVALID_T;
        
        (yyval.condition)->comp = (yyvsp[-1].comp);
        
        (yyval.condition)->right_type = ExpressType::SELECT_T;
        (yyval.condition)->right_selects = (yyvsp[0].express)->left_selects;
      }
    }
#line 3425 "yacc_sql.cpp"
    break;

  case 143: /* group_by: %empty  */
#line 1494 "yacc_sql.y"
    {
      (yyval.rel_attr_list) = nullptr;
    }
#line 3433 "yacc_sql.cpp"
    break;

  case 144: /* group_by: GROUP BY rel_attr attr_list  */
#line 1497 "yacc_sql.y"
                                  {
      (yyval.rel_attr_list) = new std::vector<RelAttrSqlNode>;
      if ((yyvsp[0].rel_attr_list) != nullptr) {
        (yyval.rel_attr_list) = (yyvsp[0].rel_attr_list);
      } else {
        (yyval.rel_attr_list) = new std::vector<RelAttrSqlNode>;
      }
      (yyval.rel_attr_list)->emplace_back(*(yyvsp[-1].rel_attr));
      delete (yyvsp[-1].rel_attr);
    }
#line 3448 "yacc_sql.cpp"
    break;

  case 145: /* order_by: %empty  */
#line 1510 "yacc_sql.y"
    {
      (yyval.order_list) = nullptr;
    }
#line 3456 "yacc_sql.cpp"
    break;

  case 146: /* order_by: ORDER BY order_list  */
#line 1513 "yacc_sql.y"
                          {
      (yyval.order_list) = (yyvsp[0].order_list);
    }
#line 3464 "yacc_sql.cpp"
    break;

  case 147: /* order: rel_attr  */
#line 1518 "yacc_sql.y"
             {
      (yyval.order) = new OrderBySqlNode;
      (yyval.order)->rel_attr = *(yyvsp[0].rel_attr);
      (yyval.order)->direction = OrderByDirection::ASC_ORDER;
    }
#line 3474 "yacc_sql.cpp"
    break;

  case 148: /* order: rel_attr DESC  */
#line 1523 "yacc_sql.y"
                   {
      (yyval.order) = new OrderBySqlNode;
      (yyval.order)->rel_attr = *(yyvsp[-1].rel_attr);
      (yyval.order)->direction = OrderByDirection::DESC_ORDER;
    }
#line 3484 "yacc_sql.cpp"
    break;

  case 149: /* order: rel_attr ASC  */
#line 1528 "yacc_sql.y"
                  {
      (yyval.order) = new OrderBySqlNode;
      (yyval.order)->rel_attr = *(yyvsp[-1].rel_attr);
      (yyval.order)->direction = OrderByDirection::ASC_ORDER;
    }
#line 3494 "yacc_sql.cpp"
    break;

  case 150: /* order_list: %empty  */
#line 1536 "yacc_sql.y"
    {
      (yyval.order_list) = nullptr;
    }
#line 3502 "yacc_sql.cpp"
    break;

  case 151: /* order_list: order  */
#line 1539 "yacc_sql.y"
           {
        (yyval.order_list) = new std::vector<OrderBySqlNode>;
        (yyval.order_list)->emplace_back(*(yyvsp[0].order));
        delete (yyvsp[0].order);
    }
#line 3512 "yacc_sql.cpp"
    break;

  case 152: /* order_list: order COMMA order_list  */
#line 1544 "yacc_sql.y"
                            {
      (yyval.order_list) = (yyvsp[0].order_list);
      (yyval.order_list)->emplace_back(*(yyvsp[-2].order));
      delete (yyvsp[-2].order);
    }
#line 3522 "yacc_sql.cpp"
    break;

  case 153: /* function: LENGTH LBRACE rel_attr RBRACE  */
#line 1553 "yacc_sql.y"
    {
      
      if((yyvsp[-1].rel_attr) == nullptr){
        (yyval.function) = new RelAttrSqlNode;
        (yyval.function)->is_syntax_error = true;
      }
      else{
        (yyval.function) = (yyvsp[-1].rel_attr);
        (yyval.function)->is_function = true;
        (yyval.function)->function_type = FunctionType::LENGTH_FUNC;
      }

    }
#line 3540 "yacc_sql.cpp"
    break;

  case 154: /* function: LENGTH LBRACE SSS RBRACE  */
#line 1567 "yacc_sql.y"
    {
        (yyval.function) = new RelAttrSqlNode;
        (yyval.function)->is_function = true;
        (yyval.function)->function_type = FunctionType::LENGTH_FUNC;
        FunctionMetaInfo tmp_func_info;
        tmp_func_info.is_length_of_attr = true;
        char *tmp = common::substr((yyvsp[-1].string),1,strlen((yyvsp[-1].string))-2);
        tmp_func_info.length_str = tmp;
        (yyval.function)->function_meta_info = tmp_func_info;
        (yyval.function)->is_constant_value = true;
        (yyval.function)->constant_value.set_string(tmp,strlen(tmp));
        free(tmp);
        
    }
#line 3559 "yacc_sql.cpp"
    break;

  case 155: /* function: ROUND LBRACE rel_attr COMMA NUMBER RBRACE  */
#line 1582 "yacc_sql.y"
    {

      if((yyvsp[-3].rel_attr) == nullptr){
        (yyval.function) = new RelAttrSqlNode;
        (yyval.function)->is_syntax_error = true;
      }
      else{
        (yyval.function) = (yyvsp[-3].rel_attr);
        (yyval.function)->is_function = true;
        (yyval.function)->function_type = FunctionType::ROUND_FUNC;
        FunctionMetaInfo tmp_func_info;
        tmp_func_info.round_type = (int)(yyvsp[-1].number);
        (yyval.function)->function_meta_info = tmp_func_info;
        
      }
        
    }
#line 3581 "yacc_sql.cpp"
    break;

  case 156: /* function: ROUND LBRACE FLOAT COMMA NUMBER RBRACE  */
#line 1600 "yacc_sql.y"
    {

        (yyval.function) = new RelAttrSqlNode;
        (yyval.function)->is_function = true;
        (yyval.function)->function_type = FunctionType::ROUND_FUNC;
        FunctionMetaInfo tmp_func_info;
        tmp_func_info.round_type = (int)(yyvsp[-1].number);
        (yyval.function)->function_meta_info = tmp_func_info;
        (yyval.function)->is_constant_value = true;
        (yyval.function)->constant_value.set_value(Value((float)(yyvsp[-3].floats)));
        
    }
#line 3598 "yacc_sql.cpp"
    break;

  case 157: /* function: DATE_FORMAT LBRACE rel_attr COMMA SSS RBRACE  */
#line 1613 "yacc_sql.y"
    {
      if((yyvsp[-3].rel_attr) == nullptr){
        (yyval.function) = new RelAttrSqlNode;
        (yyval.function)->is_syntax_error = true;
      }
      else{
        (yyval.function) = (yyvsp[-3].rel_attr);
        (yyval.function)->is_function = true;
        (yyval.function)->function_type = FunctionType::DATE_FORMAT_FUNC;
        FunctionMetaInfo tmp_func_info;
        char *tmp = common::substr((yyvsp[-1].string),1,strlen((yyvsp[-1].string))-2);
        tmp_func_info.date_format_str = tmp;
        (yyval.function)->function_meta_info = tmp_func_info;
        
      } 
    }
#line 3619 "yacc_sql.cpp"
    break;

  case 158: /* null_or_nullable: NULL_T  */
#line 1633 "yacc_sql.y"
    {
      (yyval.number) = 1;
    }
#line 3627 "yacc_sql.cpp"
    break;

  case 159: /* null_or_nullable: NULLABLE  */
#line 1637 "yacc_sql.y"
    {
      (yyval.number) = 1;
    }
#line 3635 "yacc_sql.cpp"
    break;

  case 160: /* comp_op: EQ  */
#line 1643 "yacc_sql.y"
         { (yyval.comp) = EQUAL_TO; }
#line 3641 "yacc_sql.cpp"
    break;

  case 161: /* comp_op: LT  */
#line 1644 "yacc_sql.y"
         { (yyval.comp) = LESS_THAN; }
#line 3647 "yacc_sql.cpp"
    break;

  case 162: /* comp_op: GT  */
#line 1645 "yacc_sql.y"
         { (yyval.comp) = GREAT_THAN; }
#line 3653 "yacc_sql.cpp"
    break;

  case 163: /* comp_op: LE  */
#line 1646 "yacc_sql.y"
         { (yyval.comp) = LESS_EQUAL; }
#line 3659 "yacc_sql.cpp"
    break;

  case 164: /* comp_op: GE  */
#line 1647 "yacc_sql.y"
         { (yyval.comp) = GREAT_EQUAL; }
#line 3665 "yacc_sql.cpp"
    break;

  case 165: /* comp_op: NE  */
#line 1648 "yacc_sql.y"
         { (yyval.comp) = NOT_EQUAL; }
#line 3671 "yacc_sql.cpp"
    break;

  case 166: /* comp_op: IS  */
#line 1649 "yacc_sql.y"
         { (yyval.comp) = IS_EQUAL;}
#line 3677 "yacc_sql.cpp"
    break;

  case 167: /* comp_op: IS NOT  */
#line 1650 "yacc_sql.y"
            {(yyval.comp) = IS_NOT_EQUAL;}
#line 3683 "yacc_sql.cpp"
    break;

  case 168: /* comp_op: LIKE_MARK  */
#line 1651 "yacc_sql.y"
                {(yyval.comp) = LIKE;}
#line 3689 "yacc_sql.cpp"
    break;

  case 169: /* comp_op: NOT LIKE_MARK  */
#line 1652 "yacc_sql.y"
                    {(yyval.comp) = NOT_LIKE;}
#line 3695 "yacc_sql.cpp"
    break;

  case 170: /* comp_op: IN  */
#line 1653 "yacc_sql.y"
         {(yyval.comp) = IN_COMP;}
#line 3701 "yacc_sql.cpp"
    break;

  case 171: /* comp_op: NOT IN  */
#line 1654 "yacc_sql.y"
             {(yyval.comp) = NOT_IN_COMP;}
#line 3707 "yacc_sql.cpp"
    break;

  case 172: /* comp_op: EXISTS  */
#line 1655 "yacc_sql.y"
             {(yyval.comp) = EXISTS_COMP;}
#line 3713 "yacc_sql.cpp"
    break;

  case 173: /* comp_op: NOT EXISTS  */
#line 1656 "yacc_sql.y"
                 {(yyval.comp) = NOT_EXISTS_COMP;}
#line 3719 "yacc_sql.cpp"
    break;

  case 174: /* load_data_stmt: LOAD DATA INFILE SSS INTO TABLE ID  */
#line 1661 "yacc_sql.y"
    {
      char *tmp_file_name = common::substr((yyvsp[-3].string), 1, strlen((yyvsp[-3].string)) - 2);
      
      (yyval.sql_node) = new ParsedSqlNode(SCF_LOAD_DATA);
      (yyval.sql_node)->load_data.relation_name = (yyvsp[0].string);
      (yyval.sql_node)->load_data.file_name = tmp_file_name;
      free((yyvsp[0].string));
      free(tmp_file_name);
    }
#line 3733 "yacc_sql.cpp"
    break;

  case 175: /* explain_stmt: EXPLAIN command_wrapper  */
#line 1674 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_EXPLAIN);
      (yyval.sql_node)->explain.sql_node = std::unique_ptr<ParsedSqlNode>((yyvsp[0].sql_node));
    }
#line 3742 "yacc_sql.cpp"
    break;

  case 176: /* set_variable_stmt: SET ID EQ value  */
#line 1682 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_SET_VARIABLE);
      (yyval.sql_node)->set_variable.name  = (yyvsp[-2].string);
      (yyval.sql_node)->set_variable.value = *(yyvsp[0].value);
      free((yyvsp[-2].string));
      delete (yyvsp[0].value);
    }
#line 3754 "yacc_sql.cpp"
    break;


#line 3758 "yacc_sql.cpp"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      {
        yypcontext_t yyctx
          = {yyssp, yytoken, &yylloc};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (&yylloc, sql_string, sql_result, scanner, yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
    }

  yyerror_range[1] = yylloc;
  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval, &yylloc, sql_string, sql_result, scanner);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, yylsp, sql_string, sql_result, scanner);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  ++yylsp;
  YYLLOC_DEFAULT (*yylsp, yyerror_range, 2);

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (&yylloc, sql_string, sql_result, scanner, YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc, sql_string, sql_result, scanner);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, yylsp, sql_string, sql_result, scanner);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 1694 "yacc_sql.y"

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
