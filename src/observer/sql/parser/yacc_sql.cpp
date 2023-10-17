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
  YYSYMBOL_INTO = 33,                      /* INTO  */
  YYSYMBOL_VALUES = 34,                    /* VALUES  */
  YYSYMBOL_FROM = 35,                      /* FROM  */
  YYSYMBOL_INNER = 36,                     /* INNER  */
  YYSYMBOL_JOIN = 37,                      /* JOIN  */
  YYSYMBOL_WHERE = 38,                     /* WHERE  */
  YYSYMBOL_AND = 39,                       /* AND  */
  YYSYMBOL_OR = 40,                        /* OR  */
  YYSYMBOL_EXISTS = 41,                    /* EXISTS  */
  YYSYMBOL_ORDER = 42,                     /* ORDER  */
  YYSYMBOL_GROUP = 43,                     /* GROUP  */
  YYSYMBOL_BY = 44,                        /* BY  */
  YYSYMBOL_HAVING = 45,                    /* HAVING  */
  YYSYMBOL_SET = 46,                       /* SET  */
  YYSYMBOL_ON = 47,                        /* ON  */
  YYSYMBOL_LIKE_MARK = 48,                 /* LIKE_MARK  */
  YYSYMBOL_NOT = 49,                       /* NOT  */
  YYSYMBOL_LOAD = 50,                      /* LOAD  */
  YYSYMBOL_DATA = 51,                      /* DATA  */
  YYSYMBOL_INFILE = 52,                    /* INFILE  */
  YYSYMBOL_EXPLAIN = 53,                   /* EXPLAIN  */
  YYSYMBOL_CLEAR = 54,                     /* CLEAR  */
  YYSYMBOL_IS = 55,                        /* IS  */
  YYSYMBOL_IN = 56,                        /* IN  */
  YYSYMBOL_AS = 57,                        /* AS  */
  YYSYMBOL_NULL_T = 58,                    /* NULL_T  */
  YYSYMBOL_NONE_T = 59,                    /* NONE_T  */
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
  YYSYMBOL_condition = 133,                /* condition  */
  YYSYMBOL_condition_tree = 134,           /* condition_tree  */
  YYSYMBOL_group_by = 135,                 /* group_by  */
  YYSYMBOL_order_by = 136,                 /* order_by  */
  YYSYMBOL_order = 137,                    /* order  */
  YYSYMBOL_order_list = 138,               /* order_list  */
  YYSYMBOL_null_or_nullable = 139,         /* null_or_nullable  */
  YYSYMBOL_comp_op = 140,                  /* comp_op  */
  YYSYMBOL_load_data_stmt = 141,           /* load_data_stmt  */
  YYSYMBOL_explain_stmt = 142,             /* explain_stmt  */
  YYSYMBOL_set_variable_stmt = 143,        /* set_variable_stmt  */
  YYSYMBOL_opt_semicolon = 144             /* opt_semicolon  */
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
#define YYLAST   502

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  85
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  60
/* YYNRULES -- Number of rules.  */
#define YYNRULES  177
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
       0,   240,   240,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   273,   279,   284,   290,   296,
     302,   308,   314,   319,   324,   332,   340,   352,   367,   377,
     396,   399,   412,   426,   440,   454,   468,   482,   498,   501,
     502,   503,   504,   505,   508,   526,   529,   541,   556,   559,
     577,   581,   585,   595,   600,   605,   612,   623,   642,   645,
     657,   689,   721,   732,   742,   747,   758,   761,   764,   767,
     770,   774,   777,   785,   793,   801,   809,   817,   821,   828,
     835,   847,   860,   879,   892,   907,   920,   926,   935,   943,
     950,   961,   971,   982,  1016,  1033,  1043,  1046,  1049,  1052,
    1055,  1061,  1073,  1091,  1099,  1109,  1117,  1123,  1131,  1141,
    1144,  1149,  1157,  1162,  1173,  1176,  1190,  1193,  1205,  1214,
    1217,  1234,  1261,  1276,  1287,  1293,  1301,  1304,  1311,  1314,
    1369,  1425,  1503,  1506,  1515,  1522,  1529,  1536,  1539,  1552,
    1555,  1560,  1565,  1570,  1578,  1581,  1586,  1674,  1678,  1685,
    1686,  1687,  1688,  1689,  1690,  1691,  1692,  1693,  1694,  1695,
    1696,  1697,  1698,  1702,  1715,  1723,  1733,  1734
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
  "FLOAT_T", "DATE_T", "TEXT_T", "HELP", "EXIT", "DOT", "INTO", "VALUES",
  "FROM", "INNER", "JOIN", "WHERE", "AND", "OR", "EXISTS", "ORDER",
  "GROUP", "BY", "HAVING", "SET", "ON", "LIKE_MARK", "NOT", "LOAD", "DATA",
  "INFILE", "EXPLAIN", "CLEAR", "IS", "IN", "AS", "NULL_T", "NONE_T",
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
  "condition", "condition_tree", "group_by", "order_by", "order",
  "order_list", "null_or_nullable", "comp_op", "load_data_stmt",
  "explain_stmt", "set_variable_stmt", "opt_semicolon", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-223)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     427,   125,    15,   147,   233,   -52,   108,  -223,     2,    10,
     -10,  -223,  -223,  -223,  -223,  -223,     1,    65,   427,    90,
     120,   119,  -223,  -223,  -223,  -223,  -223,  -223,  -223,  -223,
    -223,  -223,  -223,  -223,  -223,  -223,  -223,  -223,  -223,  -223,
    -223,  -223,  -223,  -223,    53,   126,    60,    84,   121,   147,
    -223,  -223,  -223,  -223,  -223,  -223,  -223,   147,  -223,  -223,
      98,  -223,    81,  -223,  -223,  -223,  -223,  -223,   178,   183,
     189,   -24,   347,   -34,  -223,   149,   174,   195,  -223,  -223,
     192,   156,   157,   172,   170,   188,  -223,  -223,  -223,  -223,
    -223,   205,   164,   197,  -223,   200,    70,  -223,   147,   147,
     147,   147,   147,   222,    45,   347,   347,   347,   -55,   171,
     221,  -223,  -223,   234,   347,   347,   347,   347,   347,  -223,
     179,   -13,   208,   248,   249,   209,   141,   210,   213,   266,
     239,   240,  -223,  -223,    72,    72,  -223,  -223,  -223,  -223,
     347,   155,   109,   224,   -34,   -34,   290,   247,  -223,   149,
      82,    82,  -223,  -223,   -23,  -223,   315,   249,  -223,   -17,
      62,   321,   322,  -223,   323,   320,  -223,   275,   324,  -223,
     314,   159,   327,   272,   331,  -223,   149,   283,  -223,   278,
    -223,  -223,   293,  -223,  -223,   330,  -223,   335,   179,   317,
     -34,   295,  -223,   -34,   -33,   264,   -33,   141,   339,   202,
    -223,  -223,    43,   325,  -223,  -223,  -223,  -223,  -223,  -223,
    -223,   419,  -223,   128,   347,   347,   209,   249,   367,  -223,
    -223,  -223,  -223,  -223,    37,   213,   357,   381,   326,   382,
     384,   396,  -223,   340,   335,  -223,  -223,   374,   377,  -223,
       0,  -223,   -16,   400,  -223,   -15,   152,   408,   400,   409,
     323,  -223,   282,    -1,  -223,  -223,  -223,  -223,   347,   320,
     320,   252,   252,   324,  -223,   356,   359,   378,  -223,   327,
    -223,   358,   420,  -223,  -223,  -223,   399,  -223,   -33,   403,
     407,   -34,  -223,   371,   -33,   433,  -223,   379,  -223,   -33,
     -33,   434,   347,   435,   339,  -223,   252,  -223,  -223,  -223,
    -223,  -223,   439,  -223,  -223,   441,  -223,   320,   181,   442,
    -223,   -33,   320,  -223,  -223,   -34,   400,  -223,    16,   400,
     400,  -223,   238,  -223,  -223,   -12,  -223,   128,  -223,  -223,
     -33,   400,   128,  -223,  -223,   444,   445,  -223,   404,  -223,
    -223,  -223,  -223,  -223,  -223
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,    27,     0,     0,
       0,    28,    29,    30,    26,    25,     0,     0,     0,     0,
       0,   176,    23,    22,    15,    16,    17,    18,     9,    24,
      10,    11,    12,    13,    14,     8,     5,     7,     6,     4,
       3,    19,    20,    21,     0,     0,     0,     0,     0,     0,
     157,    65,   158,    60,    61,    62,    63,     0,    82,    73,
      74,    64,     0,   108,   106,   107,   109,   110,     0,     0,
       0,   119,     0,   119,    89,   126,    72,     0,    35,    33,
       0,     0,     0,     0,     0,     0,   174,    32,     1,   177,
       2,     0,     0,     0,    31,     0,     0,    81,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     122,    90,    88,   126,     0,     0,     0,     0,     0,   105,
       0,     0,     0,     0,   136,     0,     0,     0,     0,     0,
       0,     0,    80,    75,    76,    77,    78,    79,    99,    87,
       0,     0,     0,     0,   119,   119,   120,     0,   104,   126,
      83,    84,    85,    86,   119,   133,   134,   136,    96,   119,
       0,     0,     0,    34,     0,   142,    66,     0,    68,   175,
       0,     0,    40,     0,     0,    38,   126,     0,   101,     0,
      91,    92,     0,   123,   127,     0,   132,   129,     0,   149,
     119,     0,   111,   119,     0,     0,     0,     0,    55,   142,
     171,   167,     0,   165,   169,   159,   160,   161,   162,   163,
     164,     0,   143,   137,     0,     0,     0,   136,     0,    49,
      50,    51,    52,    53,    43,     0,     0,     0,     0,     0,
       0,     0,   121,     0,   129,   131,   135,     0,   147,    93,
     119,    95,   119,   124,   116,   119,     0,     0,   124,    58,
       0,    54,     0,     0,   172,   168,   170,   166,     0,   142,
     142,   141,    70,    68,    67,     0,     0,     0,    45,    40,
      39,     0,     0,   100,   103,   102,     0,   130,   154,     0,
     138,   119,   112,     0,     0,     0,   113,     0,   115,     0,
       0,     0,     0,     0,    55,   146,   140,   144,   145,    69,
     173,    48,     0,    47,    41,     0,    36,   142,   151,   155,
     150,     0,   142,    71,    94,   119,   124,    98,   119,   124,
     124,    97,    58,    57,    56,    42,    37,   128,   152,   153,
     154,   124,   139,   125,   114,     0,     0,    59,     0,    44,
     156,   148,   118,   117,    46
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -223,  -223,   448,  -223,  -223,  -223,  -223,  -223,  -223,  -223,
    -223,  -223,  -223,  -223,  -223,  -223,  -223,   207,   253,  -223,
    -223,  -223,   185,   232,   161,     6,  -223,  -223,   223,   268,
     -61,  -223,   387,   370,    -4,  -223,  -115,  -107,   -69,  -222,
    -102,   333,   260,  -223,  -223,   307,  -145,  -223,  -223,  -189,
    -223,  -223,  -223,   166,  -223,  -193,  -223,  -223,  -223,  -223
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,   226,   172,   302,
     224,    36,   251,   198,   293,    74,    37,    38,   217,   168,
      39,    40,    59,    60,   211,    76,    77,   308,   192,   285,
     119,   234,   235,   155,   156,   157,   166,   313,   212,   213,
     280,   238,   309,   310,    61,   214,    41,    42,    43,    90
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      75,   103,   111,   190,   113,   286,   161,   158,   108,    58,
     253,   148,   189,   185,   162,   191,   283,   287,   258,   295,
     281,    47,   144,   109,    48,    78,   291,   145,    63,    64,
      65,    66,    67,   109,   109,    81,   334,   338,   259,   260,
     109,   109,   109,   110,   242,    82,   339,   184,    63,    64,
      65,    66,    67,   110,   110,    58,   266,   109,   104,   258,
     110,   110,   110,    58,   159,   139,   140,    83,   112,   160,
     297,   298,   264,   109,   229,   180,   181,   110,    84,   161,
     161,   161,   193,   194,   254,   186,   267,   243,   247,   248,
     132,   255,     4,   110,   333,   268,    87,   335,   336,   256,
      62,   141,   142,   143,    58,    58,    58,    58,    58,   341,
     149,   150,   151,   152,   153,    79,    85,    80,   327,    98,
      88,   239,    89,   332,   241,   115,   116,   117,   118,   178,
      91,    44,   169,    45,    46,    92,   176,    93,   103,    50,
      51,    52,    63,    64,    65,    66,    67,    68,    69,    70,
      99,   100,   101,   102,   101,   102,    53,    54,    71,    55,
      56,    94,    72,   161,   117,   118,    49,   259,   260,   161,
     114,   282,   288,   289,   161,   161,   177,   316,    99,   100,
     101,   102,   319,   320,   219,   220,   221,   222,   223,   115,
     116,   117,   118,   328,   329,   252,   161,   105,    95,    50,
      51,    52,   106,   249,   331,    50,    51,    52,   107,   120,
     261,   262,   314,     4,   121,   161,    53,    54,   125,    55,
      56,   199,    53,    54,   128,    55,    56,   122,    57,   115,
     116,   117,   118,   123,   124,   115,   116,   117,   118,   126,
     127,   129,   138,   200,   130,   179,   282,   131,   146,   282,
     201,   202,    62,   147,   296,   114,   154,   203,   204,   292,
      50,    51,    52,    63,    64,    65,    66,    67,    68,    69,
      70,   205,   206,   207,   208,   209,   210,    53,    54,    71,
      55,    56,   164,    72,   244,   163,   167,   165,   322,   170,
     171,    50,    51,    52,    63,    64,    65,    66,    67,    68,
      69,    70,   139,   140,   115,   116,   117,   118,    53,    54,
      71,    55,    56,   173,    72,    73,   174,   175,   115,   116,
     117,   118,   182,   200,   183,    63,    64,    65,    66,    67,
     201,   202,   115,   116,   117,   118,   188,   203,   204,   199,
     195,   245,   197,   196,   215,   216,   246,   218,   225,   227,
     228,   205,   206,   207,   208,   209,   210,   231,   230,   237,
     250,   200,   115,   116,   117,   118,    62,   233,   201,   202,
     232,   185,   240,   265,   257,   203,   204,   270,    50,    51,
      52,    63,    64,    65,    66,    67,    68,    69,    70,   205,
     206,   207,   208,   209,   210,    53,    54,    71,    55,    56,
     271,    72,   273,   272,   274,    50,    51,    52,    63,    64,
      65,    66,    67,    68,    69,    70,   275,   276,   278,    96,
     279,   284,    53,    54,    71,    55,    56,    97,    72,   290,
     292,     1,     2,   300,   301,   305,   303,     3,     4,     5,
     306,     6,     7,     8,     9,    10,   307,   311,   315,    11,
      12,    13,   312,   317,   321,   323,   318,    14,    15,   325,
     200,   326,   344,   330,   342,   343,    86,   201,   202,   134,
     135,   136,   137,    16,   203,   204,   304,    17,   269,   324,
      18,    19,   294,   337,   263,   133,   299,   187,   205,   206,
     207,   208,   209,   210,   277,   236,   340,     0,     0,   115,
     116,   117,   118
};

static const yytype_int16 yycheck[] =
{
       4,    62,    71,    20,    73,    20,   121,    20,    32,     3,
     199,   113,   157,    36,   121,    32,    32,    32,   211,    20,
      20,     6,    77,    57,     9,    77,   248,    82,    61,    62,
      63,    64,    65,    57,    57,    33,    20,    49,    39,    40,
      57,    57,    57,    77,    77,    35,    58,   149,    61,    62,
      63,    64,    65,    77,    77,    49,    19,    57,    62,   252,
      77,    77,    77,    57,    77,    20,    21,    77,    72,    82,
     259,   260,   217,    57,   176,   144,   145,    77,    77,   194,
     195,   196,    20,    21,    41,   154,    49,   194,   195,   196,
      20,    48,    11,    77,   316,    58,     6,   319,   320,    56,
      19,   105,   106,   107,    98,    99,   100,   101,   102,   331,
     114,   115,   116,   117,   118,     7,    51,     9,   307,    21,
       0,   190,     3,   312,   193,    80,    81,    82,    83,    20,
      77,     6,   126,     8,     9,     9,   140,    77,   199,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      80,    81,    82,    83,    82,    83,    75,    76,    77,    78,
      79,    77,    81,   278,    82,    83,    19,    39,    40,   284,
      21,   240,    20,    21,   289,   290,    21,   284,    80,    81,
      82,    83,   289,   290,    25,    26,    27,    28,    29,    80,
      81,    82,    83,    12,    13,   199,   311,    19,    77,    58,
      59,    60,    19,   197,   311,    58,    59,    60,    19,    35,
     214,   215,   281,    11,    19,   330,    75,    76,    46,    78,
      79,    19,    75,    76,    19,    78,    79,    35,    81,    80,
      81,    82,    83,    77,    77,    80,    81,    82,    83,    69,
      52,    77,    20,    41,    47,    21,   315,    47,    77,   318,
      48,    49,    19,    32,   258,    21,    77,    55,    56,    21,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    34,    81,    20,    77,    77,    38,   292,    79,
      77,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    20,    21,    80,    81,    82,    83,    75,    76,
      77,    78,    79,    47,    81,    82,    77,    77,    80,    81,
      82,    83,    32,    41,    77,    61,    62,    63,    64,    65,
      48,    49,    80,    81,    82,    83,    21,    55,    56,    19,
      19,    77,    19,    21,    69,    21,    82,    33,    21,    77,
      19,    69,    70,    71,    72,    73,    74,    79,    75,    42,
      21,    41,    80,    81,    82,    83,    19,    37,    48,    49,
      77,    36,    77,     6,    49,    55,    56,    20,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      19,    81,    20,    77,    20,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    20,    77,    44,    49,
      43,    21,    75,    76,    77,    78,    79,    57,    81,    21,
      21,     4,     5,    77,    75,    77,    58,    10,    11,    12,
      20,    14,    15,    16,    17,    18,    47,    44,    77,    22,
      23,    24,    45,    20,    20,    20,    77,    30,    31,    20,
      41,    20,    58,    21,    20,    20,    18,    48,    49,    99,
     100,   101,   102,    46,    55,    56,   269,    50,   225,   294,
      53,    54,   250,   322,   216,    98,   263,   154,    69,    70,
      71,    72,    73,    74,   234,   188,   330,    -1,    -1,    80,
      81,    82,    83
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     4,     5,    10,    11,    12,    14,    15,    16,    17,
      18,    22,    23,    24,    30,    31,    46,    50,    53,    54,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   106,   111,   112,   115,
     116,   141,   142,   143,     6,     8,     9,     6,     9,    19,
      58,    59,    60,    75,    76,    78,    79,    81,   110,   117,
     118,   139,    19,    61,    62,    63,    64,    65,    66,    67,
      68,    77,    81,    82,   110,   119,   120,   121,    77,     7,
       9,    33,    35,    77,    77,    51,    87,     6,     0,     3,
     144,    77,     9,    77,    77,    77,   118,   118,    21,    80,
      81,    82,    83,   115,   119,    19,    19,    19,    32,    57,
      77,   123,   119,   123,    21,    80,    81,    82,    83,   125,
      35,    19,    35,    77,    77,    46,    69,    52,    19,    77,
      47,    47,    20,   117,   118,   118,   118,   118,    20,    20,
      21,   119,   119,   119,    77,    82,    77,    32,   125,   119,
     119,   119,   119,   119,    77,   128,   129,   130,    20,    77,
      82,   121,   122,    77,    34,    38,   131,    77,   114,   110,
      79,    77,   103,    47,    77,    77,   119,    21,    20,    21,
     123,   123,    32,    77,   125,    36,   123,   126,    21,   131,
      20,    32,   123,    20,    21,    19,    21,    19,   108,    19,
      41,    48,    49,    55,    56,    69,    70,    71,    72,    73,
      74,   119,   133,   134,   140,    69,    21,   113,    33,    25,
      26,    27,    28,    29,   105,    21,   102,    77,    19,   125,
      75,    79,    77,    37,   126,   127,   130,    42,   136,   123,
      77,   123,    77,   122,    20,    77,    82,   122,   122,   110,
      21,   107,   119,   134,    41,    48,    56,    49,   140,    39,
      40,   119,   119,   114,   131,     6,    19,    49,    58,   103,
      20,    19,    77,    20,    20,    20,    77,   127,    44,    43,
     135,    20,   123,    32,    21,   124,    20,    32,    20,    21,
      21,   124,    21,   109,   108,    20,   119,   134,   134,   113,
      77,    75,   104,    58,   102,    77,    20,    47,   122,   137,
     138,    44,    45,   132,   123,    77,   122,    20,    77,   122,
     122,    20,   119,    20,   107,    20,    20,   134,    12,    13,
      21,   122,   134,   124,    20,   124,   124,   109,    49,    58,
     138,   124,    20,    20,    58
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
     110,   110,   110,   110,   110,   110,   111,   112,   113,   113,
     114,   115,   115,   116,   117,   117,   118,   118,   118,   118,
     118,   118,   118,   119,   119,   119,   119,   119,   119,   119,
     119,   119,   119,   119,   119,   119,   119,   119,   119,   119,
     119,   119,   119,   119,   120,   120,   121,   121,   121,   121,
     121,   122,   122,   122,   122,   122,   122,   122,   122,   123,
     123,   123,   123,   123,   124,   124,   125,   125,   126,   127,
     127,   128,   129,   129,   130,   130,   131,   131,   132,   132,
     133,   133,   134,   134,   134,   134,   134,   135,   135,   136,
     136,   137,   137,   137,   138,   138,   138,   139,   139,   140,
     140,   140,   140,   140,   140,   140,   140,   140,   140,   140,
     140,   140,   140,   141,   142,   143,   144,   144
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
       1,     1,     1,     1,     1,     1,     4,     6,     0,     3,
       3,     8,     2,     2,     1,     3,     3,     3,     3,     3,
       3,     2,     1,     3,     3,     3,     3,     3,     2,     1,
       2,     4,     4,     5,     7,     5,     3,     7,     7,     3,
       6,     4,     6,     6,     3,     2,     1,     1,     1,     1,
       1,     2,     4,     4,     6,     4,     3,     7,     7,     0,
       2,     4,     1,     3,     0,     3,     0,     3,     5,     0,
       2,     3,     2,     1,     1,     3,     0,     2,     0,     2,
       3,     2,     0,     1,     3,     3,     3,     0,     4,     0,
       3,     1,     2,     2,     0,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     1,     2,     1,
       2,     1,     2,     7,     2,     4,     0,     1
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
#line 241 "yacc_sql.y"
  {
    std::unique_ptr<ParsedSqlNode> sql_node = std::unique_ptr<ParsedSqlNode>((yyvsp[-1].sql_node));
    sql_result->add_sql_node(std::move(sql_node));
  }
#line 1930 "yacc_sql.cpp"
    break;

  case 25: /* exit_stmt: EXIT  */
#line 273 "yacc_sql.y"
         {
      (void)yynerrs;  // 这么写为了消除yynerrs未使用的告警。如果你有更好的方法欢迎提PR
      (yyval.sql_node) = new ParsedSqlNode(SCF_EXIT);
    }
#line 1939 "yacc_sql.cpp"
    break;

  case 26: /* help_stmt: HELP  */
#line 279 "yacc_sql.y"
         {
      (yyval.sql_node) = new ParsedSqlNode(SCF_HELP);
    }
#line 1947 "yacc_sql.cpp"
    break;

  case 27: /* sync_stmt: SYNC  */
#line 284 "yacc_sql.y"
         {
      (yyval.sql_node) = new ParsedSqlNode(SCF_SYNC);
    }
#line 1955 "yacc_sql.cpp"
    break;

  case 28: /* begin_stmt: TRX_BEGIN  */
#line 290 "yacc_sql.y"
               {
      (yyval.sql_node) = new ParsedSqlNode(SCF_BEGIN);
    }
#line 1963 "yacc_sql.cpp"
    break;

  case 29: /* commit_stmt: TRX_COMMIT  */
#line 296 "yacc_sql.y"
               {
      (yyval.sql_node) = new ParsedSqlNode(SCF_COMMIT);
    }
#line 1971 "yacc_sql.cpp"
    break;

  case 30: /* rollback_stmt: TRX_ROLLBACK  */
#line 302 "yacc_sql.y"
                  {
      (yyval.sql_node) = new ParsedSqlNode(SCF_ROLLBACK);
    }
#line 1979 "yacc_sql.cpp"
    break;

  case 31: /* drop_table_stmt: DROP TABLE ID  */
#line 308 "yacc_sql.y"
                  {
      (yyval.sql_node) = new ParsedSqlNode(SCF_DROP_TABLE);
      (yyval.sql_node)->drop_table.relation_name = (yyvsp[0].string);
      free((yyvsp[0].string));
    }
#line 1989 "yacc_sql.cpp"
    break;

  case 32: /* clear_table_stmt: CLEAR TABLE  */
#line 314 "yacc_sql.y"
               {
      (yyval.sql_node) = new ParsedSqlNode(SCF_CLEAR_TABLE);
    }
#line 1997 "yacc_sql.cpp"
    break;

  case 33: /* show_tables_stmt: SHOW TABLES  */
#line 319 "yacc_sql.y"
                {
      (yyval.sql_node) = new ParsedSqlNode(SCF_SHOW_TABLES);
    }
#line 2005 "yacc_sql.cpp"
    break;

  case 34: /* show_index_stmt: SHOW INDEX FROM ID  */
#line 324 "yacc_sql.y"
                      {
      (yyval.sql_node) = new ParsedSqlNode(SCF_SHOW_INDEX);
      (yyval.sql_node)->show_index.relation_name = (yyvsp[0].string);
      free((yyvsp[0].string));
    }
#line 2015 "yacc_sql.cpp"
    break;

  case 35: /* desc_table_stmt: DESC ID  */
#line 332 "yacc_sql.y"
             {
      (yyval.sql_node) = new ParsedSqlNode(SCF_DESC_TABLE);
      (yyval.sql_node)->desc_table.relation_name = (yyvsp[0].string);
      free((yyvsp[0].string));
    }
#line 2025 "yacc_sql.cpp"
    break;

  case 36: /* create_index_stmt: CREATE INDEX ID ON ID LBRACE ID RBRACE  */
#line 341 "yacc_sql.y"
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
#line 2041 "yacc_sql.cpp"
    break;

  case 37: /* create_index_stmt: CREATE UNIQUE INDEX ID ON ID LBRACE ID RBRACE  */
#line 353 "yacc_sql.y"
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
#line 2057 "yacc_sql.cpp"
    break;

  case 38: /* drop_index_stmt: DROP INDEX ID ON ID  */
#line 368 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_DROP_INDEX);
      (yyval.sql_node)->drop_index.index_name = (yyvsp[-2].string);
      (yyval.sql_node)->drop_index.relation_name = (yyvsp[0].string);
      free((yyvsp[-2].string));
      free((yyvsp[0].string));
    }
#line 2069 "yacc_sql.cpp"
    break;

  case 39: /* create_table_stmt: CREATE TABLE ID LBRACE attr_def attr_def_list RBRACE  */
#line 378 "yacc_sql.y"
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
#line 2089 "yacc_sql.cpp"
    break;

  case 40: /* attr_def_list: %empty  */
#line 396 "yacc_sql.y"
    {
      (yyval.attr_infos) = nullptr;
    }
#line 2097 "yacc_sql.cpp"
    break;

  case 41: /* attr_def_list: COMMA attr_def attr_def_list  */
#line 400 "yacc_sql.y"
    {
      if ((yyvsp[0].attr_infos) != nullptr) {
        (yyval.attr_infos) = (yyvsp[0].attr_infos);
      } else {
        (yyval.attr_infos) = new std::vector<AttrInfoSqlNode>;
      }
      (yyval.attr_infos)->emplace_back(*(yyvsp[-1].attr_info));
      delete (yyvsp[-1].attr_info);
    }
#line 2111 "yacc_sql.cpp"
    break;

  case 42: /* attr_def: ID type LBRACE number RBRACE  */
#line 413 "yacc_sql.y"
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
      (yyval.attr_info)->nullable = true;
      free((yyvsp[-4].string));
    }
#line 2129 "yacc_sql.cpp"
    break;

  case 43: /* attr_def: ID type  */
#line 427 "yacc_sql.y"
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
      (yyval.attr_info)->nullable = true;
      free((yyvsp[-1].string));
    }
#line 2147 "yacc_sql.cpp"
    break;

  case 44: /* attr_def: ID type LBRACE number RBRACE NULL_T  */
#line 441 "yacc_sql.y"
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
#line 2165 "yacc_sql.cpp"
    break;

  case 45: /* attr_def: ID type NULL_T  */
#line 455 "yacc_sql.y"
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
#line 2183 "yacc_sql.cpp"
    break;

  case 46: /* attr_def: ID type LBRACE number RBRACE NOT NULL_T  */
#line 469 "yacc_sql.y"
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
#line 2201 "yacc_sql.cpp"
    break;

  case 47: /* attr_def: ID type NOT NULL_T  */
#line 483 "yacc_sql.y"
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
#line 2219 "yacc_sql.cpp"
    break;

  case 48: /* number: NUMBER  */
#line 498 "yacc_sql.y"
           {(yyval.number) = (yyvsp[0].number);}
#line 2225 "yacc_sql.cpp"
    break;

  case 49: /* type: INT_T  */
#line 501 "yacc_sql.y"
               { (yyval.number)=INTS; }
#line 2231 "yacc_sql.cpp"
    break;

  case 50: /* type: STRING_T  */
#line 502 "yacc_sql.y"
               { (yyval.number)=CHARS; }
#line 2237 "yacc_sql.cpp"
    break;

  case 51: /* type: FLOAT_T  */
#line 503 "yacc_sql.y"
               { (yyval.number)=FLOATS; }
#line 2243 "yacc_sql.cpp"
    break;

  case 52: /* type: DATE_T  */
#line 504 "yacc_sql.y"
                { (yyval.number)=DATES;}
#line 2249 "yacc_sql.cpp"
    break;

  case 53: /* type: TEXT_T  */
#line 505 "yacc_sql.y"
                { (yyval.number)=TEXTS;}
#line 2255 "yacc_sql.cpp"
    break;

  case 54: /* insert_stmt: INSERT INTO ID VALUES insert_value insert_value_list  */
#line 509 "yacc_sql.y"
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
#line 2274 "yacc_sql.cpp"
    break;

  case 55: /* insert_value_list: %empty  */
#line 526 "yacc_sql.y"
    {
      (yyval.insert_value_list) = nullptr;
    }
#line 2282 "yacc_sql.cpp"
    break;

  case 56: /* insert_value_list: COMMA insert_value insert_value_list  */
#line 530 "yacc_sql.y"
    {
      if ((yyvsp[0].insert_value_list) != nullptr) {
        (yyval.insert_value_list) = (yyvsp[0].insert_value_list);
      } else {
        (yyval.insert_value_list) = new std::vector<InsertValueSqlNode>;
      }
      (yyval.insert_value_list)->emplace_back(*(yyvsp[-1].insert_value));
      delete (yyvsp[-1].insert_value);
    }
#line 2296 "yacc_sql.cpp"
    break;

  case 57: /* insert_value: LBRACE value value_list RBRACE  */
#line 542 "yacc_sql.y"
    {
        (yyval.insert_value) = new InsertValueSqlNode;
        if((yyvsp[-1].value_list) != nullptr){
          (yyval.insert_value)->values.swap(*(yyvsp[-1].value_list));
        }
        (yyval.insert_value)->values.emplace_back(*(yyvsp[-2].value));
        std::reverse((yyval.insert_value)->values.begin(),(yyval.insert_value)->values.end());
        delete (yyvsp[-2].value);
    }
#line 2310 "yacc_sql.cpp"
    break;

  case 58: /* value_list: %empty  */
#line 556 "yacc_sql.y"
    {
      (yyval.value_list) = nullptr;
    }
#line 2318 "yacc_sql.cpp"
    break;

  case 59: /* value_list: COMMA express value_list  */
#line 559 "yacc_sql.y"
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
#line 2339 "yacc_sql.cpp"
    break;

  case 60: /* value: NUMBER  */
#line 577 "yacc_sql.y"
           {
      (yyval.value) = new Value((int)(yyvsp[0].number));
      (yyloc) = (yylsp[0]);
    }
#line 2348 "yacc_sql.cpp"
    break;

  case 61: /* value: FLOAT  */
#line 581 "yacc_sql.y"
           {
      (yyval.value) = new Value((float)(yyvsp[0].floats));
      (yyloc) = (yylsp[0]);
    }
#line 2357 "yacc_sql.cpp"
    break;

  case 62: /* value: DATE_STR  */
#line 585 "yacc_sql.y"
               {
      char *tmp = common::substr((yyvsp[0].string),1,strlen((yyvsp[0].string))-2);
      int y, m, d;
      sscanf(tmp, "%d-%d-%d", &y, &m, &d);


      (yyval.value) = new Value(y,m,d);

      
    }
#line 2372 "yacc_sql.cpp"
    break;

  case 63: /* value: SSS  */
#line 595 "yacc_sql.y"
         {
      char *tmp = common::substr((yyvsp[0].string),1,strlen((yyvsp[0].string))-2);
      (yyval.value) = new Value(tmp);
      free(tmp);
    }
#line 2382 "yacc_sql.cpp"
    break;

  case 64: /* value: null_or_nullable  */
#line 600 "yacc_sql.y"
                     {
      (yyval.value) = new Value(0);
      
      (yyval.value)->set_null(nullptr,4);
    }
#line 2392 "yacc_sql.cpp"
    break;

  case 65: /* value: NONE_T  */
#line 605 "yacc_sql.y"
           {
      (yyval.value) = new Value(114514);
    }
#line 2400 "yacc_sql.cpp"
    break;

  case 66: /* delete_stmt: DELETE FROM ID where  */
#line 613 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_DELETE);
      (yyval.sql_node)->deletion.relation_name = (yyvsp[-1].string);
      if ((yyvsp[0].condition_tree) != nullptr) {
        (yyval.sql_node)->deletion.conditions.emplace_back((yyvsp[0].condition_tree));
      }
      free((yyvsp[-1].string));
    }
#line 2413 "yacc_sql.cpp"
    break;

  case 67: /* update_stmt: UPDATE ID SET set_value set_value_list where  */
#line 624 "yacc_sql.y"
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
      if ((yyvsp[0].condition_tree) != nullptr) {
        (yyval.sql_node)->update.conditions.emplace_back((yyvsp[0].condition_tree));
      }
    }
#line 2433 "yacc_sql.cpp"
    break;

  case 68: /* set_value_list: %empty  */
#line 642 "yacc_sql.y"
    {
      (yyval.update_value_list) = nullptr;
    }
#line 2441 "yacc_sql.cpp"
    break;

  case 69: /* set_value_list: COMMA set_value set_value_list  */
#line 645 "yacc_sql.y"
                                   {
      if ((yyvsp[0].update_value_list) != nullptr) {
        (yyval.update_value_list) = (yyvsp[0].update_value_list);
      } else {
        (yyval.update_value_list) = new std::vector<UpdateValueSqlNode>;
      }
      (yyval.update_value_list)->emplace_back(*(yyvsp[-1].update_value));
      delete (yyvsp[-1].update_value);

    }
#line 2456 "yacc_sql.cpp"
    break;

  case 70: /* set_value: ID EQ express  */
#line 658 "yacc_sql.y"
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
#line 2482 "yacc_sql.cpp"
    break;

  case 71: /* select_stmt: SELECT select_attr FROM rel_list where order_by group_by having_clause  */
#line 690 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_SELECT);
      if ((yyvsp[-6].express_list) != nullptr) {
        (yyval.sql_node)->selection.attributes.swap(*(yyvsp[-6].express_list));
        delete (yyvsp[-6].express_list);
      }
     
      (yyval.sql_node)->selection.relations.swap(*(yyvsp[-4].relation_list));
      delete (yyvsp[-4].relation_list);
      
      std::reverse((yyval.sql_node)->selection.relations.begin(), (yyval.sql_node)->selection.relations.end());

      if ((yyvsp[-3].condition_tree) != nullptr) {
        // printf("condition left type= %d\n", $5->node.left_type);
        (yyval.sql_node)->selection.conditions.emplace_back((yyvsp[-3].condition_tree));
      }
      if ((yyvsp[-2].order_list) != nullptr) {
        (yyval.sql_node)->selection.order_by_sql_nodes.swap(*(yyvsp[-2].order_list));
        delete (yyvsp[-2].order_list);
      }

      if((yyvsp[-1].rel_attr_list) != nullptr){
        (yyval.sql_node)->selection.group_by_attributes.swap (*(yyvsp[-1].rel_attr_list));
        delete (yyvsp[-1].rel_attr_list);
      }
      if ((yyvsp[0].condition_tree) != nullptr) {
        (yyval.sql_node)->selection.having_conditions.emplace_back((yyvsp[0].condition_tree));
        // delete $8;
      }

    }
#line 2518 "yacc_sql.cpp"
    break;

  case 72: /* select_stmt: SELECT select_attr  */
#line 722 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_SELECT);
      if((yyvsp[0].express_list) != nullptr){
        (yyval.sql_node)->selection.attributes.swap(*(yyvsp[0].express_list));
        delete (yyvsp[0].express_list);
      }

    }
#line 2531 "yacc_sql.cpp"
    break;

  case 73: /* calc_stmt: CALC expression_list  */
#line 733 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_CALC);
      std::reverse((yyvsp[0].expression_list)->begin(), (yyvsp[0].expression_list)->end());
      (yyval.sql_node)->calc.expressions.swap(*(yyvsp[0].expression_list));
      delete (yyvsp[0].expression_list);
    }
#line 2542 "yacc_sql.cpp"
    break;

  case 74: /* expression_list: expression  */
#line 743 "yacc_sql.y"
    {
      (yyval.expression_list) = new std::vector<Expression*>;
      (yyval.expression_list)->emplace_back((yyvsp[0].expression));
    }
#line 2551 "yacc_sql.cpp"
    break;

  case 75: /* expression_list: expression COMMA expression_list  */
#line 748 "yacc_sql.y"
    {
      if ((yyvsp[0].expression_list) != nullptr) {
        (yyval.expression_list) = (yyvsp[0].expression_list);
      } else {
        (yyval.expression_list) = new std::vector<Expression *>;
      }
      (yyval.expression_list)->emplace_back((yyvsp[-2].expression));
    }
#line 2564 "yacc_sql.cpp"
    break;

  case 76: /* expression: expression '+' expression  */
#line 758 "yacc_sql.y"
                              {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::ADD, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2572 "yacc_sql.cpp"
    break;

  case 77: /* expression: expression '-' expression  */
#line 761 "yacc_sql.y"
                                {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::SUB, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2580 "yacc_sql.cpp"
    break;

  case 78: /* expression: expression '*' expression  */
#line 764 "yacc_sql.y"
                                {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::MUL, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2588 "yacc_sql.cpp"
    break;

  case 79: /* expression: expression '/' expression  */
#line 767 "yacc_sql.y"
                                {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::DIV, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2596 "yacc_sql.cpp"
    break;

  case 80: /* expression: LBRACE expression RBRACE  */
#line 770 "yacc_sql.y"
                               {
      (yyval.expression) = (yyvsp[-1].expression);
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));
    }
#line 2605 "yacc_sql.cpp"
    break;

  case 81: /* expression: '-' expression  */
#line 774 "yacc_sql.y"
                                  {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::NEGATIVE, (yyvsp[0].expression), nullptr, sql_string, &(yyloc));
    }
#line 2613 "yacc_sql.cpp"
    break;

  case 82: /* expression: value  */
#line 777 "yacc_sql.y"
            {
      (yyval.expression) = new ValueExpr(*(yyvsp[0].value));
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));
      delete (yyvsp[0].value);
    }
#line 2623 "yacc_sql.cpp"
    break;

  case 83: /* express: express '+' express  */
#line 785 "yacc_sql.y"
                        {
      (yyval.express) = new ExprSqlNode;
      (yyval.express)->name = token_name(sql_string, &(yyloc));
      (yyval.express)->type = ExpressType::EXPR_T;
      (yyval.express)->add_left_child((yyvsp[-2].express));
      (yyval.express)->comp = ExprOp::ADD;
      (yyval.express)->add_right_child((yyvsp[0].express));
    }
#line 2636 "yacc_sql.cpp"
    break;

  case 84: /* express: express '-' express  */
#line 793 "yacc_sql.y"
                          {
      (yyval.express) = new ExprSqlNode;
      (yyval.express)->name = token_name(sql_string, &(yyloc));
      (yyval.express)->type = ExpressType::EXPR_T;
      (yyval.express)->add_left_child((yyvsp[-2].express));
      (yyval.express)->comp = ExprOp::SUB;
      (yyval.express)->add_right_child((yyvsp[0].express));
    }
#line 2649 "yacc_sql.cpp"
    break;

  case 85: /* express: express '*' express  */
#line 801 "yacc_sql.y"
                          {
      (yyval.express) = new ExprSqlNode;
      (yyval.express)->name = token_name(sql_string, &(yyloc));
      (yyval.express)->type = ExpressType::EXPR_T;
      (yyval.express)->add_left_child((yyvsp[-2].express));
      (yyval.express)->comp = ExprOp::MUL;
      (yyval.express)->add_right_child((yyvsp[0].express));
    }
#line 2662 "yacc_sql.cpp"
    break;

  case 86: /* express: express '/' express  */
#line 809 "yacc_sql.y"
                          {
      (yyval.express) = new ExprSqlNode;
      (yyval.express)->name = token_name(sql_string, &(yyloc));
      (yyval.express)->type = ExpressType::EXPR_T;
      (yyval.express)->add_left_child((yyvsp[-2].express));
      (yyval.express)->comp = ExprOp::DIV;
      (yyval.express)->add_right_child((yyvsp[0].express));
    }
#line 2675 "yacc_sql.cpp"
    break;

  case 87: /* express: LBRACE express RBRACE  */
#line 817 "yacc_sql.y"
                            {
      (yyval.express) = (yyvsp[-1].express);
      (yyval.express)->name = token_name(sql_string, &(yyloc));
    }
#line 2684 "yacc_sql.cpp"
    break;

  case 88: /* express: '-' express  */
#line 821 "yacc_sql.y"
                               {
      (yyval.express) = new ExprSqlNode;
      (yyval.express)->name = token_name(sql_string, &(yyloc));
      (yyval.express)->type = ExpressType::EXPR_T;
      (yyval.express)->add_left_child((yyvsp[0].express));
      (yyval.express)->comp = ExprOp::NEGATIVE;
    }
#line 2696 "yacc_sql.cpp"
    break;

  case 89: /* express: value  */
#line 828 "yacc_sql.y"
            {
      (yyval.express) = new ExprSqlNode;
      (yyval.express)->name = token_name(sql_string, &(yyloc));
      (yyval.express)->type = ExpressType::VALUE_T;
      (yyval.express)->left_value = *(yyvsp[0].value);
      delete (yyvsp[0].value);
    }
#line 2708 "yacc_sql.cpp"
    break;

  case 90: /* express: ID as_alias  */
#line 835 "yacc_sql.y"
                 {
      // printf("aaa\n");
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
#line 2725 "yacc_sql.cpp"
    break;

  case 91: /* express: ID DOT ID as_alias  */
#line 847 "yacc_sql.y"
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
#line 2743 "yacc_sql.cpp"
    break;

  case 92: /* express: ID DOT '*' as_alias  */
#line 860 "yacc_sql.y"
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
#line 2760 "yacc_sql.cpp"
    break;

  case 93: /* express: aggregation_func LBRACE ID RBRACE as_alias  */
#line 879 "yacc_sql.y"
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
#line 2778 "yacc_sql.cpp"
    break;

  case 94: /* express: aggregation_func LBRACE ID DOT ID RBRACE as_alias  */
#line 892 "yacc_sql.y"
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
#line 2798 "yacc_sql.cpp"
    break;

  case 95: /* express: aggregation_func LBRACE '*' RBRACE as_alias  */
#line 907 "yacc_sql.y"
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
#line 2816 "yacc_sql.cpp"
    break;

  case 96: /* express: aggregation_func LBRACE RBRACE  */
#line 920 "yacc_sql.y"
                                    {
      (yyval.express) = new ExprSqlNode;
      (yyval.express)->name = token_name(sql_string, &(yyloc));
      (yyval.express)->type = ExpressType::ATTR_T;
      (yyval.express)->left_attr.is_syntax_error = true;
    }
#line 2827 "yacc_sql.cpp"
    break;

  case 97: /* express: aggregation_func LBRACE rel_attr COMMA rel_attr attr_list RBRACE  */
#line 926 "yacc_sql.y"
                                                                      {
      (yyval.express) = new ExprSqlNode;
      (yyval.express)->name = token_name(sql_string, &(yyloc));
      (yyval.express)->type = ExpressType::ATTR_T;
      (yyval.express)->left_attr.is_syntax_error = true;
      delete (yyvsp[-4].rel_attr);
      delete (yyvsp[-2].rel_attr);
      delete (yyvsp[-1].rel_attr_list);
    }
#line 2841 "yacc_sql.cpp"
    break;

  case 98: /* express: aggregation_func LBRACE '*' COMMA rel_attr attr_list RBRACE  */
#line 935 "yacc_sql.y"
                                                                 {
      (yyval.express) = new ExprSqlNode;
      (yyval.express)->name = token_name(sql_string, &(yyloc));
      (yyval.express)->type = ExpressType::ATTR_T;
      (yyval.express)->left_attr.is_syntax_error = true;
      delete (yyvsp[-2].rel_attr);
      delete (yyvsp[-1].rel_attr_list);
    }
#line 2854 "yacc_sql.cpp"
    break;

  case 99: /* express: LBRACE select_stmt RBRACE  */
#line 944 "yacc_sql.y"
    {
      (yyval.express) = new ExprSqlNode;
      (yyval.express)->name = token_name(sql_string, &(yyloc));
      (yyval.express)->type = ExpressType::SELECT_T;
      (yyval.express)->left_selects = &((yyvsp[-1].sql_node)->selection);
    }
#line 2865 "yacc_sql.cpp"
    break;

  case 100: /* express: LBRACE express COMMA express express_list RBRACE  */
#line 951 "yacc_sql.y"
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
#line 2880 "yacc_sql.cpp"
    break;

  case 101: /* express: LENGTH LBRACE express RBRACE  */
#line 962 "yacc_sql.y"
    {
      (yyval.express) = new ExprSqlNode;
      (yyval.express)->name = token_name(sql_string, &(yyloc));
      (yyval.express)->type = ExpressType::FUNC_T;
      (yyval.express)->left_expr = (yyvsp[-1].express);
      (yyval.express)->func_info = new FunctionMetaInfo;
      (yyval.express)->func_info->function_type = FunctionType::LENGTH_FUNC;

    }
#line 2894 "yacc_sql.cpp"
    break;

  case 102: /* express: DATE_FORMAT LBRACE express COMMA SSS RBRACE  */
#line 972 "yacc_sql.y"
    {
      (yyval.express) = new ExprSqlNode;
      (yyval.express)->name = token_name(sql_string, &(yyloc));
      (yyval.express)->type = ExpressType::FUNC_T;
      (yyval.express)->left_expr = (yyvsp[-3].express);
      (yyval.express)->func_info = new FunctionMetaInfo;
      (yyval.express)->func_info->function_type = FunctionType::DATE_FORMAT_FUNC;
      (yyval.express)->func_info->date_format_str = (yyvsp[-1].string);

    }
#line 2909 "yacc_sql.cpp"
    break;

  case 103: /* express: ROUND LBRACE express COMMA NUMBER RBRACE  */
#line 983 "yacc_sql.y"
    {
      (yyval.express) = new ExprSqlNode;
      (yyval.express)->name = token_name(sql_string, &(yyloc));
      (yyval.express)->type = ExpressType::FUNC_T;
      (yyval.express)->left_expr = (yyvsp[-3].express);
      (yyval.express)->func_info = new FunctionMetaInfo;
      (yyval.express)->func_info->function_type = FunctionType::ROUND_FUNC;
      (yyval.express)->func_info->round_type = (yyvsp[-1].number);

    }
#line 2924 "yacc_sql.cpp"
    break;

  case 104: /* select_attr: '*' as_alias express_list  */
#line 1016 "yacc_sql.y"
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
      if((yyvsp[-1].string) != nullptr){
        expr_sql_node->left_attr.has_alias = true;
        expr_sql_node->left_attr.alias = (yyvsp[-1].string);
        expr_sql_node->left_attr.is_syntax_error = true;
      }
      (yyval.express_list)->emplace_back(expr_sql_node);
    }
#line 2946 "yacc_sql.cpp"
    break;

  case 105: /* select_attr: express express_list  */
#line 1033 "yacc_sql.y"
                           {
      if ((yyvsp[0].express_list) != nullptr) {
        (yyval.express_list) = (yyvsp[0].express_list);
      } else {
        (yyval.express_list) = new std::vector<ExprSqlNode *>;
      }
      (yyval.express_list)->emplace_back((yyvsp[-1].express));
    }
#line 2959 "yacc_sql.cpp"
    break;

  case 106: /* aggregation_func: MAX_FUNC  */
#line 1043 "yacc_sql.y"
            {
      (yyval.aggr_func) = AggrFuncType::MAX;
    }
#line 2967 "yacc_sql.cpp"
    break;

  case 107: /* aggregation_func: MIN_FUNC  */
#line 1046 "yacc_sql.y"
              {
      (yyval.aggr_func) = AggrFuncType::MIN;
    }
#line 2975 "yacc_sql.cpp"
    break;

  case 108: /* aggregation_func: CNT_FUNC  */
#line 1049 "yacc_sql.y"
              {
      (yyval.aggr_func) = AggrFuncType::CNT;
    }
#line 2983 "yacc_sql.cpp"
    break;

  case 109: /* aggregation_func: AVG_FUNC  */
#line 1052 "yacc_sql.y"
              {
      (yyval.aggr_func) = AggrFuncType::AVG;
    }
#line 2991 "yacc_sql.cpp"
    break;

  case 110: /* aggregation_func: SUM_FUNC  */
#line 1055 "yacc_sql.y"
              {
      (yyval.aggr_func) = AggrFuncType::SUM;
    }
#line 2999 "yacc_sql.cpp"
    break;

  case 111: /* rel_attr: ID as_alias  */
#line 1061 "yacc_sql.y"
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
#line 3016 "yacc_sql.cpp"
    break;

  case 112: /* rel_attr: ID DOT ID as_alias  */
#line 1073 "yacc_sql.y"
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
#line 3035 "yacc_sql.cpp"
    break;

  case 113: /* rel_attr: aggregation_func LBRACE ID RBRACE  */
#line 1091 "yacc_sql.y"
                                       {
      (yyval.rel_attr) = new RelAttrSqlNode;
      (yyval.rel_attr)->attribute_name = (yyvsp[-1].string);
      free((yyvsp[-1].string));
      (yyval.rel_attr)->is_aggregation_func = true;
      (yyval.rel_attr)->aggr_func_type = (yyvsp[-3].aggr_func);

    }
#line 3048 "yacc_sql.cpp"
    break;

  case 114: /* rel_attr: aggregation_func LBRACE ID DOT ID RBRACE  */
#line 1099 "yacc_sql.y"
                                              {
      (yyval.rel_attr) = new RelAttrSqlNode;
      (yyval.rel_attr)->relation_name  = (yyvsp[-3].string);
      (yyval.rel_attr)->attribute_name = (yyvsp[-1].string);
      free((yyvsp[-3].string));
      free((yyvsp[-1].string));
      (yyval.rel_attr)->is_aggregation_func = true;
      (yyval.rel_attr)->aggr_func_type = (yyvsp[-5].aggr_func);

    }
#line 3063 "yacc_sql.cpp"
    break;

  case 115: /* rel_attr: aggregation_func LBRACE '*' RBRACE  */
#line 1109 "yacc_sql.y"
                                        {
      (yyval.rel_attr) = new RelAttrSqlNode;
      (yyval.rel_attr)->relation_name = "";
      (yyval.rel_attr)->attribute_name = "*";
      (yyval.rel_attr)->is_aggregation_func = true;
      (yyval.rel_attr)->aggr_func_type = (yyvsp[-3].aggr_func);

    }
#line 3076 "yacc_sql.cpp"
    break;

  case 116: /* rel_attr: aggregation_func LBRACE RBRACE  */
#line 1117 "yacc_sql.y"
                                    {
      (yyval.rel_attr) = new RelAttrSqlNode;
      (yyval.rel_attr)->is_syntax_error = true;
      (yyval.rel_attr)->aggr_func_type = (yyvsp[-2].aggr_func);

    }
#line 3087 "yacc_sql.cpp"
    break;

  case 117: /* rel_attr: aggregation_func LBRACE rel_attr COMMA rel_attr attr_list RBRACE  */
#line 1123 "yacc_sql.y"
                                                                      {
      (yyval.rel_attr) = new RelAttrSqlNode;
      (yyval.rel_attr)->is_syntax_error = true;
      delete (yyvsp[-4].rel_attr);
      delete (yyvsp[-2].rel_attr);
      delete (yyvsp[-1].rel_attr_list);

    }
#line 3100 "yacc_sql.cpp"
    break;

  case 118: /* rel_attr: aggregation_func LBRACE '*' COMMA rel_attr attr_list RBRACE  */
#line 1131 "yacc_sql.y"
                                                                 {
      (yyval.rel_attr) = new RelAttrSqlNode;
      (yyval.rel_attr)->is_syntax_error = true;
      delete (yyvsp[-2].rel_attr);
      delete (yyvsp[-1].rel_attr_list);

    }
#line 3112 "yacc_sql.cpp"
    break;

  case 119: /* as_alias: %empty  */
#line 1141 "yacc_sql.y"
    {
      (yyval.string) = nullptr;
    }
#line 3120 "yacc_sql.cpp"
    break;

  case 120: /* as_alias: AS ID  */
#line 1144 "yacc_sql.y"
           {
      (yyval.string) = (char*)malloc(strlen((yyvsp[0].string))+1);
      strcpy((yyval.string),(yyvsp[0].string));
      free((yyvsp[0].string));
    }
#line 3130 "yacc_sql.cpp"
    break;

  case 121: /* as_alias: AS ID DOT ID  */
#line 1149 "yacc_sql.y"
                  {
      (yyval.string) = (char*)malloc(strlen((yyvsp[-2].string))+strlen((yyvsp[0].string))+2);
      strcpy((yyval.string),(yyvsp[-2].string));
      strcpy((yyval.string)+strlen((yyvsp[-2].string)),".");
      strcpy((yyval.string)+strlen((yyvsp[-2].string))+1,(yyvsp[0].string));
      free((yyvsp[-2].string));
      free((yyvsp[0].string));
    }
#line 3143 "yacc_sql.cpp"
    break;

  case 122: /* as_alias: ID  */
#line 1157 "yacc_sql.y"
        {
      (yyval.string) = (char*)malloc(strlen((yyvsp[0].string))+1);
      strcpy((yyval.string),(yyvsp[0].string));
      free((yyvsp[0].string));
    }
#line 3153 "yacc_sql.cpp"
    break;

  case 123: /* as_alias: ID DOT ID  */
#line 1162 "yacc_sql.y"
               {
      (yyval.string) = (char*)malloc(strlen((yyvsp[-2].string))+strlen((yyvsp[0].string))+2);
      strcpy((yyval.string),(yyvsp[-2].string));
      strcpy((yyval.string)+strlen((yyvsp[-2].string)),".");
      strcpy((yyval.string)+strlen((yyvsp[-2].string))+1,(yyvsp[0].string));
      free((yyvsp[-2].string));
      free((yyvsp[0].string));
    }
#line 3166 "yacc_sql.cpp"
    break;

  case 124: /* attr_list: %empty  */
#line 1173 "yacc_sql.y"
    {
      (yyval.rel_attr_list) = nullptr;
    }
#line 3174 "yacc_sql.cpp"
    break;

  case 125: /* attr_list: COMMA rel_attr attr_list  */
#line 1176 "yacc_sql.y"
                               {
      if ((yyvsp[0].rel_attr_list) != nullptr) {
        (yyval.rel_attr_list) = (yyvsp[0].rel_attr_list);
      } else {
        (yyval.rel_attr_list) = new std::vector<RelAttrSqlNode>;
      }

      (yyval.rel_attr_list)->emplace_back(*(yyvsp[-1].rel_attr));
      delete (yyvsp[-1].rel_attr);
    }
#line 3189 "yacc_sql.cpp"
    break;

  case 126: /* express_list: %empty  */
#line 1190 "yacc_sql.y"
    {
      (yyval.express_list) = nullptr;
    }
#line 3197 "yacc_sql.cpp"
    break;

  case 127: /* express_list: COMMA express express_list  */
#line 1193 "yacc_sql.y"
                                 {
      if ((yyvsp[0].express_list) != nullptr) {
        (yyval.express_list) = (yyvsp[0].express_list);
      } else {
        (yyval.express_list) = new std::vector<ExprSqlNode *>;
      }

      (yyval.express_list)->emplace_back((yyvsp[-1].express));
    }
#line 3211 "yacc_sql.cpp"
    break;

  case 128: /* inner_join: INNER JOIN ID ON condition_tree  */
#line 1206 "yacc_sql.y"
    {
        (yyval.join_rel) = new JoinedRelationSqlNode;
        (yyval.join_rel)->relations.push_back((yyvsp[-2].string));
        (yyval.join_rel)->join_on_conditions.emplace_back((yyvsp[0].condition_tree));
        // free($3);
    }
#line 3222 "yacc_sql.cpp"
    break;

  case 129: /* inner_join_list: %empty  */
#line 1214 "yacc_sql.y"
    {
      (yyval.join_rel) = nullptr;
    }
#line 3230 "yacc_sql.cpp"
    break;

  case 130: /* inner_join_list: inner_join inner_join_list  */
#line 1218 "yacc_sql.y"
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
#line 3249 "yacc_sql.cpp"
    break;

  case 131: /* join_relation: ID inner_join inner_join_list  */
#line 1235 "yacc_sql.y"
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
#line 3277 "yacc_sql.cpp"
    break;

  case 132: /* rel_element: ID as_alias  */
#line 1262 "yacc_sql.y"
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
#line 3296 "yacc_sql.cpp"
    break;

  case 133: /* rel_element: join_relation  */
#line 1277 "yacc_sql.y"
    {
      (yyval.relation) = new RelationSqlNode;
      (yyval.relation)->inner_join_sql_node = *(yyvsp[0].join_rel);
      (yyval.relation) -> has_inner_join = true;
      // delete $1;

    }
#line 3308 "yacc_sql.cpp"
    break;

  case 134: /* rel_list: rel_element  */
#line 1288 "yacc_sql.y"
    { 
      (yyval.relation_list) = new std::vector<RelationSqlNode>;
      (yyval.relation_list)->emplace_back(*(yyvsp[0].relation));
      // delete $1;
    }
#line 3318 "yacc_sql.cpp"
    break;

  case 135: /* rel_list: rel_element COMMA rel_list  */
#line 1293 "yacc_sql.y"
                                 {
      (yyval.relation_list) = (yyvsp[0].relation_list);
      (yyval.relation_list)->emplace_back(*(yyvsp[-2].relation));
      // delete $1;
    }
#line 3328 "yacc_sql.cpp"
    break;

  case 136: /* where: %empty  */
#line 1301 "yacc_sql.y"
    {
      (yyval.condition_tree) = nullptr;
    }
#line 3336 "yacc_sql.cpp"
    break;

  case 137: /* where: WHERE condition_tree  */
#line 1304 "yacc_sql.y"
                           {
      // printf("condition left type= %d\n", $2->node.left_type);
      (yyval.condition_tree) = (yyvsp[0].condition_tree);  
    }
#line 3345 "yacc_sql.cpp"
    break;

  case 138: /* having_clause: %empty  */
#line 1311 "yacc_sql.y"
    {
      (yyval.condition_tree) = nullptr;
    }
#line 3353 "yacc_sql.cpp"
    break;

  case 139: /* having_clause: HAVING condition_tree  */
#line 1314 "yacc_sql.y"
                            {
      (yyval.condition_tree) = (yyvsp[0].condition_tree);  
    }
#line 3361 "yacc_sql.cpp"
    break;

  case 140: /* condition: express comp_op express  */
#line 1370 "yacc_sql.y"
    {
      (yyval.condition) = new ConditionSqlNode;
      // printf("type= %d\n", $1->type);
      if ((yyvsp[-2].express)->type == ExpressType::VALUE_T) {
        (yyval.condition)->left_type = ExpressType::VALUE_T;
        (yyval.condition)->left_value = (yyvsp[-2].express)->left_value;
        delete (yyvsp[-2].express);
      }
      else if ((yyvsp[-2].express)->type == ExpressType::ATTR_T) {
        (yyval.condition)->left_type = ExpressType::ATTR_T;
        (yyval.condition)->left_attr = (yyvsp[-2].express)->left_attr;
        // delete $1;
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
      else {
        (yyval.condition)->left_type = ExpressType::INVALID_T;
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
      else {
        (yyval.condition)->right_type = ExpressType::INVALID_T;
      }
    }
#line 3421 "yacc_sql.cpp"
    break;

  case 141: /* condition: comp_op express  */
#line 1426 "yacc_sql.y"
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
#line 3440 "yacc_sql.cpp"
    break;

  case 142: /* condition_tree: %empty  */
#line 1503 "yacc_sql.y"
    {
      (yyval.condition_tree) = nullptr;
    }
#line 3448 "yacc_sql.cpp"
    break;

  case 143: /* condition_tree: condition  */
#line 1507 "yacc_sql.y"
    {
      (yyval.condition_tree) = new ConditionTreeSqlNode;
      // printf("conditiontree left type= %d\n", $1->left_type);
      (yyval.condition_tree)->type = ConjuctionType::ONE_T;
      (yyval.condition_tree)->node = *(yyvsp[0].condition);
      // printf("conditiontree left type= %d\n", $1->left_type);
      // printf("conditiontree node left type= %d\n", $$->node.left_type);
    }
#line 3461 "yacc_sql.cpp"
    break;

  case 144: /* condition_tree: condition_tree AND condition_tree  */
#line 1516 "yacc_sql.y"
    {
      (yyval.condition_tree) = new ConditionTreeSqlNode;
      (yyval.condition_tree)->type = ConjuctionType::AND_T;
      (yyval.condition_tree)->left_sub_tree = (yyvsp[-2].condition_tree);
      (yyval.condition_tree)->right_sub_tree = (yyvsp[0].condition_tree);
    }
#line 3472 "yacc_sql.cpp"
    break;

  case 145: /* condition_tree: condition_tree OR condition_tree  */
#line 1523 "yacc_sql.y"
    {
      (yyval.condition_tree) = new ConditionTreeSqlNode;
      (yyval.condition_tree)->type = ConjuctionType::OR_T;
      (yyval.condition_tree)->left_sub_tree = (yyvsp[-2].condition_tree);
      (yyval.condition_tree)->right_sub_tree = (yyvsp[0].condition_tree);
    }
#line 3483 "yacc_sql.cpp"
    break;

  case 146: /* condition_tree: LBRACE condition_tree RBRACE  */
#line 1530 "yacc_sql.y"
    {
      (yyval.condition_tree) = (yyvsp[-1].condition_tree);
    }
#line 3491 "yacc_sql.cpp"
    break;

  case 147: /* group_by: %empty  */
#line 1536 "yacc_sql.y"
    {
      (yyval.rel_attr_list) = nullptr;
    }
#line 3499 "yacc_sql.cpp"
    break;

  case 148: /* group_by: GROUP BY rel_attr attr_list  */
#line 1539 "yacc_sql.y"
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
#line 3514 "yacc_sql.cpp"
    break;

  case 149: /* order_by: %empty  */
#line 1552 "yacc_sql.y"
    {
      (yyval.order_list) = nullptr;
    }
#line 3522 "yacc_sql.cpp"
    break;

  case 150: /* order_by: ORDER BY order_list  */
#line 1555 "yacc_sql.y"
                          {
      (yyval.order_list) = (yyvsp[0].order_list);
    }
#line 3530 "yacc_sql.cpp"
    break;

  case 151: /* order: rel_attr  */
#line 1560 "yacc_sql.y"
             {
      (yyval.order) = new OrderBySqlNode;
      (yyval.order)->rel_attr = *(yyvsp[0].rel_attr);
      (yyval.order)->direction = OrderByDirection::ASC_ORDER;
    }
#line 3540 "yacc_sql.cpp"
    break;

  case 152: /* order: rel_attr DESC  */
#line 1565 "yacc_sql.y"
                   {
      (yyval.order) = new OrderBySqlNode;
      (yyval.order)->rel_attr = *(yyvsp[-1].rel_attr);
      (yyval.order)->direction = OrderByDirection::DESC_ORDER;
    }
#line 3550 "yacc_sql.cpp"
    break;

  case 153: /* order: rel_attr ASC  */
#line 1570 "yacc_sql.y"
                  {
      (yyval.order) = new OrderBySqlNode;
      (yyval.order)->rel_attr = *(yyvsp[-1].rel_attr);
      (yyval.order)->direction = OrderByDirection::ASC_ORDER;
    }
#line 3560 "yacc_sql.cpp"
    break;

  case 154: /* order_list: %empty  */
#line 1578 "yacc_sql.y"
    {
      (yyval.order_list) = nullptr;
    }
#line 3568 "yacc_sql.cpp"
    break;

  case 155: /* order_list: order  */
#line 1581 "yacc_sql.y"
           {
        (yyval.order_list) = new std::vector<OrderBySqlNode>;
        (yyval.order_list)->emplace_back(*(yyvsp[0].order));
        delete (yyvsp[0].order);
    }
#line 3578 "yacc_sql.cpp"
    break;

  case 156: /* order_list: order COMMA order_list  */
#line 1586 "yacc_sql.y"
                            {
      (yyval.order_list) = (yyvsp[0].order_list);
      (yyval.order_list)->emplace_back(*(yyvsp[-2].order));
      delete (yyvsp[-2].order);
    }
#line 3588 "yacc_sql.cpp"
    break;

  case 157: /* null_or_nullable: NULL_T  */
#line 1675 "yacc_sql.y"
    {
      (yyval.number) = 1;
    }
#line 3596 "yacc_sql.cpp"
    break;

  case 158: /* null_or_nullable: NULLABLE  */
#line 1679 "yacc_sql.y"
    {
      (yyval.number) = 1;
    }
#line 3604 "yacc_sql.cpp"
    break;

  case 159: /* comp_op: EQ  */
#line 1685 "yacc_sql.y"
         { (yyval.comp) = EQUAL_TO; }
#line 3610 "yacc_sql.cpp"
    break;

  case 160: /* comp_op: LT  */
#line 1686 "yacc_sql.y"
         { (yyval.comp) = LESS_THAN; }
#line 3616 "yacc_sql.cpp"
    break;

  case 161: /* comp_op: GT  */
#line 1687 "yacc_sql.y"
         { (yyval.comp) = GREAT_THAN; }
#line 3622 "yacc_sql.cpp"
    break;

  case 162: /* comp_op: LE  */
#line 1688 "yacc_sql.y"
         { (yyval.comp) = LESS_EQUAL; }
#line 3628 "yacc_sql.cpp"
    break;

  case 163: /* comp_op: GE  */
#line 1689 "yacc_sql.y"
         { (yyval.comp) = GREAT_EQUAL; }
#line 3634 "yacc_sql.cpp"
    break;

  case 164: /* comp_op: NE  */
#line 1690 "yacc_sql.y"
         { (yyval.comp) = NOT_EQUAL; }
#line 3640 "yacc_sql.cpp"
    break;

  case 165: /* comp_op: IS  */
#line 1691 "yacc_sql.y"
         { (yyval.comp) = IS_EQUAL;}
#line 3646 "yacc_sql.cpp"
    break;

  case 166: /* comp_op: IS NOT  */
#line 1692 "yacc_sql.y"
            {(yyval.comp) = IS_NOT_EQUAL;}
#line 3652 "yacc_sql.cpp"
    break;

  case 167: /* comp_op: LIKE_MARK  */
#line 1693 "yacc_sql.y"
                {(yyval.comp) = LIKE;}
#line 3658 "yacc_sql.cpp"
    break;

  case 168: /* comp_op: NOT LIKE_MARK  */
#line 1694 "yacc_sql.y"
                    {(yyval.comp) = NOT_LIKE;}
#line 3664 "yacc_sql.cpp"
    break;

  case 169: /* comp_op: IN  */
#line 1695 "yacc_sql.y"
         {(yyval.comp) = IN_COMP;}
#line 3670 "yacc_sql.cpp"
    break;

  case 170: /* comp_op: NOT IN  */
#line 1696 "yacc_sql.y"
             {(yyval.comp) = NOT_IN_COMP;}
#line 3676 "yacc_sql.cpp"
    break;

  case 171: /* comp_op: EXISTS  */
#line 1697 "yacc_sql.y"
             {(yyval.comp) = EXISTS_COMP;}
#line 3682 "yacc_sql.cpp"
    break;

  case 172: /* comp_op: NOT EXISTS  */
#line 1698 "yacc_sql.y"
                 {(yyval.comp) = NOT_EXISTS_COMP;}
#line 3688 "yacc_sql.cpp"
    break;

  case 173: /* load_data_stmt: LOAD DATA INFILE SSS INTO TABLE ID  */
#line 1703 "yacc_sql.y"
    {
      char *tmp_file_name = common::substr((yyvsp[-3].string), 1, strlen((yyvsp[-3].string)) - 2);
      
      (yyval.sql_node) = new ParsedSqlNode(SCF_LOAD_DATA);
      (yyval.sql_node)->load_data.relation_name = (yyvsp[0].string);
      (yyval.sql_node)->load_data.file_name = tmp_file_name;
      free((yyvsp[0].string));
      free(tmp_file_name);
    }
#line 3702 "yacc_sql.cpp"
    break;

  case 174: /* explain_stmt: EXPLAIN command_wrapper  */
#line 1716 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_EXPLAIN);
      (yyval.sql_node)->explain.sql_node = std::unique_ptr<ParsedSqlNode>((yyvsp[0].sql_node));
    }
#line 3711 "yacc_sql.cpp"
    break;

  case 175: /* set_variable_stmt: SET ID EQ value  */
#line 1724 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_SET_VARIABLE);
      (yyval.sql_node)->set_variable.name  = (yyvsp[-2].string);
      (yyval.sql_node)->set_variable.value = *(yyvsp[0].value);
      free((yyvsp[-2].string));
      delete (yyvsp[0].value);
    }
#line 3723 "yacc_sql.cpp"
    break;


#line 3727 "yacc_sql.cpp"

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

#line 1736 "yacc_sql.y"

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
