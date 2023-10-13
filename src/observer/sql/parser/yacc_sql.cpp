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
  YYSYMBOL_ORDER = 41,                     /* ORDER  */
  YYSYMBOL_GROUP = 42,                     /* GROUP  */
  YYSYMBOL_BY = 43,                        /* BY  */
  YYSYMBOL_HAVING = 44,                    /* HAVING  */
  YYSYMBOL_SET = 45,                       /* SET  */
  YYSYMBOL_ON = 46,                        /* ON  */
  YYSYMBOL_LIKE_MARK = 47,                 /* LIKE_MARK  */
  YYSYMBOL_NOT = 48,                       /* NOT  */
  YYSYMBOL_LOAD = 49,                      /* LOAD  */
  YYSYMBOL_DATA = 50,                      /* DATA  */
  YYSYMBOL_INFILE = 51,                    /* INFILE  */
  YYSYMBOL_EXPLAIN = 52,                   /* EXPLAIN  */
  YYSYMBOL_CLEAR = 53,                     /* CLEAR  */
  YYSYMBOL_IS = 54,                        /* IS  */
  YYSYMBOL_IN = 55,                        /* IN  */
  YYSYMBOL_AS = 56,                        /* AS  */
  YYSYMBOL_NULL_T = 57,                    /* NULL_T  */
  YYSYMBOL_NULLABLE = 58,                  /* NULLABLE  */
  YYSYMBOL_CNT_FUNC = 59,                  /* CNT_FUNC  */
  YYSYMBOL_MAX_FUNC = 60,                  /* MAX_FUNC  */
  YYSYMBOL_MIN_FUNC = 61,                  /* MIN_FUNC  */
  YYSYMBOL_AVG_FUNC = 62,                  /* AVG_FUNC  */
  YYSYMBOL_SUM_FUNC = 63,                  /* SUM_FUNC  */
  YYSYMBOL_ROUND = 64,                     /* ROUND  */
  YYSYMBOL_LENGTH = 65,                    /* LENGTH  */
  YYSYMBOL_DATE_FORMAT = 66,               /* DATE_FORMAT  */
  YYSYMBOL_EQ = 67,                        /* EQ  */
  YYSYMBOL_LT = 68,                        /* LT  */
  YYSYMBOL_GT = 69,                        /* GT  */
  YYSYMBOL_LE = 70,                        /* LE  */
  YYSYMBOL_GE = 71,                        /* GE  */
  YYSYMBOL_NE = 72,                        /* NE  */
  YYSYMBOL_NUMBER = 73,                    /* NUMBER  */
  YYSYMBOL_FLOAT = 74,                     /* FLOAT  */
  YYSYMBOL_ID = 75,                        /* ID  */
  YYSYMBOL_DATE_STR = 76,                  /* DATE_STR  */
  YYSYMBOL_SSS = 77,                       /* SSS  */
  YYSYMBOL_78_ = 78,                       /* '+'  */
  YYSYMBOL_79_ = 79,                       /* '-'  */
  YYSYMBOL_80_ = 80,                       /* '*'  */
  YYSYMBOL_81_ = 81,                       /* '/'  */
  YYSYMBOL_UMINUS = 82,                    /* UMINUS  */
  YYSYMBOL_YYACCEPT = 83,                  /* $accept  */
  YYSYMBOL_commands = 84,                  /* commands  */
  YYSYMBOL_command_wrapper = 85,           /* command_wrapper  */
  YYSYMBOL_exit_stmt = 86,                 /* exit_stmt  */
  YYSYMBOL_help_stmt = 87,                 /* help_stmt  */
  YYSYMBOL_sync_stmt = 88,                 /* sync_stmt  */
  YYSYMBOL_begin_stmt = 89,                /* begin_stmt  */
  YYSYMBOL_commit_stmt = 90,               /* commit_stmt  */
  YYSYMBOL_rollback_stmt = 91,             /* rollback_stmt  */
  YYSYMBOL_drop_table_stmt = 92,           /* drop_table_stmt  */
  YYSYMBOL_clear_table_stmt = 93,          /* clear_table_stmt  */
  YYSYMBOL_show_tables_stmt = 94,          /* show_tables_stmt  */
  YYSYMBOL_show_index_stmt = 95,           /* show_index_stmt  */
  YYSYMBOL_desc_table_stmt = 96,           /* desc_table_stmt  */
  YYSYMBOL_create_index_stmt = 97,         /* create_index_stmt  */
  YYSYMBOL_drop_index_stmt = 98,           /* drop_index_stmt  */
  YYSYMBOL_create_table_stmt = 99,         /* create_table_stmt  */
  YYSYMBOL_attr_def_list = 100,            /* attr_def_list  */
  YYSYMBOL_attr_def = 101,                 /* attr_def  */
  YYSYMBOL_number = 102,                   /* number  */
  YYSYMBOL_type = 103,                     /* type  */
  YYSYMBOL_insert_stmt = 104,              /* insert_stmt  */
  YYSYMBOL_insert_value_list = 105,        /* insert_value_list  */
  YYSYMBOL_insert_value = 106,             /* insert_value  */
  YYSYMBOL_value_list = 107,               /* value_list  */
  YYSYMBOL_value = 108,                    /* value  */
  YYSYMBOL_delete_stmt = 109,              /* delete_stmt  */
  YYSYMBOL_update_stmt = 110,              /* update_stmt  */
  YYSYMBOL_set_value_list = 111,           /* set_value_list  */
  YYSYMBOL_set_value = 112,                /* set_value  */
  YYSYMBOL_select_stmt = 113,              /* select_stmt  */
  YYSYMBOL_calc_stmt = 114,                /* calc_stmt  */
  YYSYMBOL_expression_list = 115,          /* expression_list  */
  YYSYMBOL_expression = 116,               /* expression  */
  YYSYMBOL_express = 117,                  /* express  */
  YYSYMBOL_select_attr = 118,              /* select_attr  */
  YYSYMBOL_aggregation_func = 119,         /* aggregation_func  */
  YYSYMBOL_rel_attr = 120,                 /* rel_attr  */
  YYSYMBOL_as_alias = 121,                 /* as_alias  */
  YYSYMBOL_attr_list = 122,                /* attr_list  */
  YYSYMBOL_express_list = 123,             /* express_list  */
  YYSYMBOL_inner_join = 124,               /* inner_join  */
  YYSYMBOL_inner_join_list = 125,          /* inner_join_list  */
  YYSYMBOL_join_relation = 126,            /* join_relation  */
  YYSYMBOL_rel_element = 127,              /* rel_element  */
  YYSYMBOL_rel_list = 128,                 /* rel_list  */
  YYSYMBOL_where = 129,                    /* where  */
  YYSYMBOL_having_clause = 130,            /* having_clause  */
  YYSYMBOL_condition_list = 131,           /* condition_list  */
  YYSYMBOL_condition = 132,                /* condition  */
  YYSYMBOL_group_by = 133,                 /* group_by  */
  YYSYMBOL_order_by = 134,                 /* order_by  */
  YYSYMBOL_order = 135,                    /* order  */
  YYSYMBOL_order_list = 136,               /* order_list  */
  YYSYMBOL_function = 137,                 /* function  */
  YYSYMBOL_null_or_nullable = 138,         /* null_or_nullable  */
  YYSYMBOL_comp_op = 139,                  /* comp_op  */
  YYSYMBOL_load_data_stmt = 140,           /* load_data_stmt  */
  YYSYMBOL_explain_stmt = 141,             /* explain_stmt  */
  YYSYMBOL_set_variable_stmt = 142,        /* set_variable_stmt  */
  YYSYMBOL_opt_semicolon = 143             /* opt_semicolon  */
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
#define YYFINAL  84
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   407

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  83
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  61
/* YYNRULES -- Number of rules.  */
#define YYNRULES  172
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  329

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   333


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
       2,     2,    80,    78,     2,    79,     2,    81,     2,     2,
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
      75,    76,    77,    82
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   237,   237,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,   261,
     262,   263,   264,   265,   266,   270,   276,   281,   287,   293,
     299,   305,   311,   316,   321,   329,   337,   349,   364,   374,
     393,   396,   409,   423,   437,   451,   465,   479,   495,   498,
     499,   500,   501,   502,   505,   523,   526,   538,   553,   556,
     574,   578,   582,   592,   597,   608,   620,   640,   643,   655,
     687,   719,   730,   740,   745,   756,   759,   762,   765,   768,
     772,   775,   783,   791,   799,   807,   815,   819,   826,   833,
     840,   849,   858,   869,   878,   884,   893,   901,   931,   943,
     953,   956,   959,   962,   965,   971,   983,   997,  1001,  1009,
    1019,  1027,  1033,  1041,  1051,  1054,  1059,  1067,  1072,  1083,
    1086,  1100,  1103,  1115,  1126,  1129,  1146,  1173,  1188,  1199,
    1205,  1213,  1216,  1222,  1225,  1232,  1235,  1240,  1295,  1387,
    1390,  1403,  1406,  1411,  1416,  1421,  1429,  1432,  1437,  1445,
    1459,  1474,  1492,  1505,  1525,  1529,  1536,  1537,  1538,  1539,
    1540,  1541,  1542,  1543,  1544,  1545,  1546,  1547,  1551,  1564,
    1572,  1582,  1583
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
  "VALUES", "FROM", "INNER", "JOIN", "WHERE", "AND", "ORDER", "GROUP",
  "BY", "HAVING", "SET", "ON", "LIKE_MARK", "NOT", "LOAD", "DATA",
  "INFILE", "EXPLAIN", "CLEAR", "IS", "IN", "AS", "NULL_T", "NULLABLE",
  "CNT_FUNC", "MAX_FUNC", "MIN_FUNC", "AVG_FUNC", "SUM_FUNC", "ROUND",
  "LENGTH", "DATE_FORMAT", "EQ", "LT", "GT", "LE", "GE", "NE", "NUMBER",
  "FLOAT", "ID", "DATE_STR", "SSS", "'+'", "'-'", "'*'", "'/'", "UMINUS",
  "$accept", "commands", "command_wrapper", "exit_stmt", "help_stmt",
  "sync_stmt", "begin_stmt", "commit_stmt", "rollback_stmt",
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

#define YYPACT_NINF (-227)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     272,    13,    35,    71,   112,   -42,    33,  -227,    -7,    18,
     -17,  -227,  -227,  -227,  -227,  -227,    -9,    24,   272,    70,
      80,   110,  -227,  -227,  -227,  -227,  -227,  -227,  -227,  -227,
    -227,  -227,  -227,  -227,  -227,  -227,  -227,  -227,  -227,  -227,
    -227,  -227,  -227,  -227,    39,   107,    42,    43,    51,    71,
    -227,  -227,  -227,  -227,  -227,  -227,    71,  -227,  -227,   125,
    -227,    62,  -227,  -227,  -227,  -227,  -227,    95,   136,   109,
    -227,   155,    96,   114,  -227,  -227,   106,    68,    74,   113,
      85,   103,  -227,  -227,  -227,  -227,  -227,   140,    87,   118,
    -227,   119,    27,  -227,    71,    71,    71,    71,    71,   158,
      31,   108,  -227,   136,  -227,   136,   136,   136,   136,  -227,
     127,   157,   132,   147,   121,   133,   -48,   150,   149,   138,
     153,   156,  -227,  -227,   -63,   -63,  -227,  -227,  -227,  -227,
    -227,   155,     3,     3,  -227,  -227,   -25,  -227,   209,   121,
    -227,   233,   234,   235,     0,    25,   237,   236,  -227,  -227,
     240,   136,  -227,   196,   243,  -227,   232,    10,   246,   194,
     249,  -227,  -227,   241,   195,   253,  -227,   238,   127,   250,
     290,   282,   307,  -227,   203,  -227,  -227,   307,   180,   307,
     -48,   271,   259,  -227,   261,   136,   133,   121,   287,  -227,
    -227,  -227,  -227,  -227,    -5,   149,   284,   286,   244,   245,
     276,   247,   238,  -227,  -227,   266,   268,   291,   -26,   294,
     296,   298,   302,    78,   311,  -227,   206,    66,   312,   311,
     313,   240,  -227,  -227,   -31,   263,  -227,  -227,  -227,  -227,
    -227,  -227,  -227,   136,   136,   169,   243,  -227,   260,   285,
     279,  -227,   246,  -227,   289,   340,   315,   299,  -227,  -227,
     307,   319,   331,   303,   304,   305,  -227,  -227,   300,  -227,
    -227,   307,   360,  -227,   306,  -227,   307,   307,   363,   136,
     364,   271,  -227,  -227,  -227,   169,  -227,  -227,  -227,  -227,
     365,  -227,  -227,   366,  -227,   136,  -227,    79,   367,  -227,
     307,   136,  -227,   369,   -41,   370,   371,   311,  -227,   205,
     311,   311,  -227,   193,  -227,  -227,   -35,  -227,  -227,  -227,
    -227,   307,   311,  -227,  -227,  -227,  -227,  -227,  -227,   372,
     373,  -227,   330,  -227,  -227,  -227,  -227,  -227,  -227
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,    27,     0,     0,
       0,    28,    29,    30,    26,    25,     0,     0,     0,     0,
       0,   171,    23,    22,    15,    16,    17,    18,     9,    24,
      10,    11,    12,    13,    14,     8,     5,     7,     6,     4,
       3,    19,    20,    21,     0,     0,     0,     0,     0,     0,
     154,   155,    60,    61,    62,    63,     0,    81,    72,    73,
      64,     0,   102,   100,   101,   103,   104,    89,     0,   121,
      88,   121,    71,     0,    35,    33,     0,     0,     0,     0,
       0,     0,   169,    32,     1,   172,     2,     0,     0,     0,
      31,     0,     0,    80,     0,     0,     0,     0,     0,     0,
       0,     0,    87,     0,    98,     0,     0,     0,     0,    99,
       0,     0,     0,     0,   131,     0,     0,     0,     0,     0,
       0,     0,    79,    74,    75,    76,    77,    78,    97,    86,
      90,   121,    82,    83,    84,    85,   114,   128,   129,   131,
      94,     0,     0,     0,   114,     0,     0,     0,   107,    34,
       0,   135,    65,     0,    67,   170,     0,     0,    40,     0,
       0,    38,   122,     0,     0,   117,   127,   124,     0,   141,
       0,     0,     0,    91,     0,   105,    93,     0,     0,     0,
       0,    55,     0,   132,   136,     0,     0,   131,     0,    49,
      50,    51,    52,    53,    43,     0,     0,     0,     0,     0,
     115,     0,   124,   126,   130,     0,   139,     0,   114,     0,
       0,     0,     0,   114,   119,   111,   114,     0,     0,   119,
      58,     0,    54,   164,     0,   162,   166,   156,   157,   158,
     159,   160,   161,     0,   135,    69,    67,    66,     0,     0,
       0,    45,    40,    39,     0,     0,     0,     0,   118,   125,
     146,     0,   133,     0,     0,     0,   150,   149,     0,    92,
     106,     0,     0,   108,     0,   110,     0,     0,     0,     0,
       0,    55,   165,   167,   163,   138,   137,    68,   168,    48,
       0,    47,    41,     0,    36,   135,   116,   143,   147,   142,
       0,   135,    70,     0,   114,     0,     0,   119,    96,   114,
     119,   119,    95,    58,    57,    56,    42,    37,   123,   144,
     145,   146,   119,   134,   152,   151,   153,   120,   109,     0,
       0,    59,     0,    44,   148,   140,   113,   112,    46
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -227,  -227,   376,  -227,  -227,  -227,  -227,  -227,  -227,  -227,
    -227,  -227,  -227,  -227,  -227,  -227,  -227,   154,   200,  -227,
    -227,  -227,   126,   177,    97,    -1,  -227,  -227,   163,   215,
     341,  -227,   309,   202,    -4,  -227,  -110,  -100,  -131,  -212,
     -68,   269,   204,  -227,  -227,   239,  -135,  -227,  -226,  -227,
    -227,  -227,  -227,    93,  -227,  -227,  -227,  -227,  -227,  -227,
    -227
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,   196,   158,   280,
     194,    36,   222,   181,   270,    70,    37,    38,   187,   154,
      39,    40,    58,    59,   182,    72,    73,   287,   175,   262,
     104,   202,   203,   137,   138,   139,   152,   292,   183,   184,
     252,   206,   288,   289,   148,    60,   233,    41,    42,    43,
      86
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      71,   146,    57,   109,   169,   166,   254,   268,   276,    50,
      51,   147,   163,   322,   239,   164,   272,    97,    98,    44,
     173,    45,    46,   323,   273,    52,    53,    77,    54,    55,
     164,   164,   174,    74,   165,   189,   190,   191,   192,   193,
      75,    47,    76,   240,    48,   176,   177,   122,    57,   165,
     165,   129,   237,   241,    78,    57,   164,   100,    79,   308,
     146,   146,   146,   162,   102,   313,    80,   146,   146,   146,
     209,   211,   212,     4,    81,   165,    83,   214,   218,   219,
      84,    61,   260,   107,   108,   317,   265,   266,   319,   320,
      49,   309,   310,    57,    57,    57,    57,    57,   259,   131,
     325,   132,   133,   134,   135,    95,    96,    97,    98,   105,
     106,   107,   108,    85,    87,   155,    88,    89,    90,    50,
      51,    62,    63,    64,    65,    66,    91,   101,    50,    51,
     103,    61,   110,   111,   164,    52,    53,    67,    54,    55,
     146,    68,   112,   113,    52,    53,    94,    54,    55,   114,
      56,   146,   116,   165,   117,    61,   146,   146,   115,   118,
     151,   297,   119,   260,   120,   121,   300,   301,   260,    50,
      51,    62,    63,    64,    65,    66,   103,   140,   128,   220,
     146,   235,   150,   130,   159,    52,    53,    67,    54,    55,
     312,    68,    69,    50,    51,    62,    63,    64,    65,    66,
     215,   146,   136,    95,    96,    97,    98,   149,   153,    52,
      53,    67,    54,    55,   269,    68,    62,    63,    64,    65,
      66,   141,   142,   143,   157,   318,   263,   156,   160,   275,
     168,   161,   144,   105,   106,   107,   108,   145,   264,    62,
      63,    64,    65,    66,   141,   142,   143,   105,   106,   107,
     108,    92,   170,   171,   172,   216,   178,   179,    93,   180,
     217,   164,   164,   185,   186,   303,   188,   195,   198,   197,
     200,   105,   106,   107,   108,   163,     1,     2,   213,   199,
     165,   165,     3,     4,     5,   201,     6,     7,     8,     9,
      10,   205,   221,   238,    11,    12,    13,   124,   125,   126,
     127,   234,    14,    15,   243,   244,   223,   224,   247,   250,
     251,   274,   253,   225,   226,   255,   256,    16,   257,   245,
     246,    17,   248,   258,    18,    19,   227,   228,   229,   230,
     231,   232,   261,   267,   269,   278,   281,   105,   106,   107,
     108,    62,    63,    64,    65,    66,   141,   142,   143,    62,
      63,    64,    65,    66,   141,   142,   143,   208,   279,   210,
     284,   285,   290,   207,   283,   208,    62,    63,    64,    65,
      66,   141,   142,   143,   286,   291,   293,   296,   295,   294,
     298,   299,   208,   302,   304,   306,   307,   328,   311,   314,
     315,   316,   326,   327,    82,   242,   282,   305,   271,   277,
     321,   236,    99,   123,   324,   167,   249,   204
};

static const yytype_int16 yycheck[] =
{
       4,   111,     3,    71,   139,   136,    32,   219,   234,    57,
      58,   111,    37,    48,    19,    56,    47,    80,    81,     6,
      20,     8,     9,    58,    55,    73,    74,    34,    76,    77,
      56,    56,    32,    75,    75,    25,    26,    27,    28,    29,
       7,     6,     9,    48,     9,    20,    21,    20,    49,    75,
      75,    20,   187,    58,    36,    56,    56,    61,    75,   285,
     170,   171,   172,   131,    68,   291,    75,   177,   178,   179,
     170,   171,   172,    11,    50,    75,     6,   177,   178,   179,
       0,    19,   213,    80,    81,   297,    20,    21,   300,   301,
      19,    12,    13,    94,    95,    96,    97,    98,    20,   103,
     312,   105,   106,   107,   108,    78,    79,    80,    81,    78,
      79,    80,    81,     3,    75,   116,     9,    75,    75,    57,
      58,    59,    60,    61,    62,    63,    75,    32,    57,    58,
      21,    19,    36,    19,    56,    73,    74,    75,    76,    77,
     250,    79,    36,    75,    73,    74,    21,    76,    77,    75,
      79,   261,    67,    75,    51,    19,   266,   267,    45,    19,
      39,   261,    75,   294,    46,    46,   266,   267,   299,    57,
      58,    59,    60,    61,    62,    63,    21,    20,    20,   180,
     290,   185,    35,    75,    46,    73,    74,    75,    76,    77,
     290,    79,    80,    57,    58,    59,    60,    61,    62,    63,
      20,   311,    75,    78,    79,    80,    81,    75,    75,    73,
      74,    75,    76,    77,    21,    79,    59,    60,    61,    62,
      63,    64,    65,    66,    75,    20,    20,    77,    75,   233,
      21,    75,    75,    78,    79,    80,    81,    80,    32,    59,
      60,    61,    62,    63,    64,    65,    66,    78,    79,    80,
      81,    49,    19,    19,    19,    75,    19,    21,    56,    19,
      80,    56,    56,    67,    21,   269,    34,    21,    19,    75,
      75,    78,    79,    80,    81,    37,     4,     5,    75,    38,
      75,    75,    10,    11,    12,    32,    14,    15,    16,    17,
      18,    41,    21,     6,    22,    23,    24,    95,    96,    97,
      98,    40,    30,    31,    20,    19,    47,    48,    32,    43,
      42,    48,    21,    54,    55,    21,    20,    45,    20,    75,
      75,    49,    75,    21,    52,    53,    67,    68,    69,    70,
      71,    72,    21,    21,    21,    75,    57,    78,    79,    80,
      81,    59,    60,    61,    62,    63,    64,    65,    66,    59,
      60,    61,    62,    63,    64,    65,    66,    75,    73,    77,
      20,    46,    43,    73,    75,    75,    59,    60,    61,    62,
      63,    64,    65,    66,    75,    44,    73,    77,    73,    75,
      20,    75,    75,    20,    20,    20,    20,    57,    21,    20,
      20,    20,    20,    20,    18,   195,   242,   271,   221,   236,
     303,   186,    61,    94,   311,   136,   202,   168
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     4,     5,    10,    11,    12,    14,    15,    16,    17,
      18,    22,    23,    24,    30,    31,    45,    49,    52,    53,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   104,   109,   110,   113,
     114,   140,   141,   142,     6,     8,     9,     6,     9,    19,
      57,    58,    73,    74,    76,    77,    79,   108,   115,   116,
     138,    19,    59,    60,    61,    62,    63,    75,    79,    80,
     108,   117,   118,   119,    75,     7,     9,    34,    36,    75,
      75,    50,    85,     6,     0,     3,   143,    75,     9,    75,
      75,    75,   116,   116,    21,    78,    79,    80,    81,   113,
     117,    32,   117,    21,   123,    78,    79,    80,    81,   123,
      36,    19,    36,    75,    75,    45,    67,    51,    19,    75,
      46,    46,    20,   115,   116,   116,   116,   116,    20,    20,
      75,   117,   117,   117,   117,   117,    75,   126,   127,   128,
      20,    64,    65,    66,    75,    80,   119,   120,   137,    75,
      35,    39,   129,    75,   112,   108,    77,    75,   101,    46,
      75,    75,   123,    37,    56,    75,   121,   124,    21,   129,
      19,    19,    19,    20,    32,   121,    20,    21,    19,    21,
      19,   106,   117,   131,   132,    67,    21,   111,    34,    25,
      26,    27,    28,    29,   103,    21,   100,    75,    19,    38,
      75,    32,   124,   125,   128,    41,   134,    73,    75,   120,
      77,   120,   120,    75,   120,    20,    75,    80,   120,   120,
     108,    21,   105,    47,    48,    54,    55,    67,    68,    69,
      70,    71,    72,   139,    40,   117,   112,   129,     6,    19,
      48,    58,   101,    20,    19,    75,    75,    32,    75,   125,
      43,    42,   133,    21,    32,    21,    20,    20,    21,    20,
     121,    21,   122,    20,    32,    20,    21,    21,   122,    21,
     107,   106,    47,    55,    48,   117,   131,   111,    75,    73,
     102,    57,   100,    75,    20,    46,    75,   120,   135,   136,
      43,    44,   130,    73,    75,    73,    77,   120,    20,    75,
     120,   120,    20,   117,    20,   105,    20,    20,   131,    12,
      13,    21,   120,   131,    20,    20,    20,   122,    20,   122,
     122,   107,    48,    58,   136,   122,    20,    20,    57
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    83,    84,    85,    85,    85,    85,    85,    85,    85,
      85,    85,    85,    85,    85,    85,    85,    85,    85,    85,
      85,    85,    85,    85,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    97,    98,    99,
     100,   100,   101,   101,   101,   101,   101,   101,   102,   103,
     103,   103,   103,   103,   104,   105,   105,   106,   107,   107,
     108,   108,   108,   108,   108,   109,   110,   111,   111,   112,
     113,   113,   114,   115,   115,   116,   116,   116,   116,   116,
     116,   116,   117,   117,   117,   117,   117,   117,   117,   117,
     117,   117,   117,   117,   117,   117,   117,   117,   118,   118,
     119,   119,   119,   119,   119,   120,   120,   120,   120,   120,
     120,   120,   120,   120,   121,   121,   121,   121,   121,   122,
     122,   123,   123,   124,   125,   125,   126,   127,   127,   128,
     128,   129,   129,   130,   130,   131,   131,   131,   132,   133,
     133,   134,   134,   135,   135,   135,   136,   136,   136,   137,
     137,   137,   137,   137,   138,   138,   139,   139,   139,   139,
     139,   139,   139,   139,   139,   139,   139,   139,   140,   141,
     142,   143,   143
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
       2,     1,     3,     3,     3,     3,     3,     2,     1,     1,
       3,     4,     6,     4,     3,     7,     7,     3,     2,     2,
       1,     1,     1,     1,     1,     2,     4,     1,     4,     6,
       4,     3,     7,     7,     0,     2,     4,     1,     3,     0,
       3,     0,     3,     5,     0,     2,     3,     2,     1,     1,
       3,     0,     2,     0,     2,     0,     1,     3,     3,     0,
       4,     0,     3,     1,     2,     2,     0,     1,     3,     4,
       4,     6,     6,     6,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     1,     2,     1,     2,     7,     2,
       4,     0,     1
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
#line 238 "yacc_sql.y"
  {
    std::unique_ptr<ParsedSqlNode> sql_node = std::unique_ptr<ParsedSqlNode>((yyvsp[-1].sql_node));
    sql_result->add_sql_node(std::move(sql_node));
  }
#line 1905 "yacc_sql.cpp"
    break;

  case 25: /* exit_stmt: EXIT  */
#line 270 "yacc_sql.y"
         {
      (void)yynerrs;  // 这么写为了消除yynerrs未使用的告警。如果你有更好的方法欢迎提PR
      (yyval.sql_node) = new ParsedSqlNode(SCF_EXIT);
    }
#line 1914 "yacc_sql.cpp"
    break;

  case 26: /* help_stmt: HELP  */
#line 276 "yacc_sql.y"
         {
      (yyval.sql_node) = new ParsedSqlNode(SCF_HELP);
    }
#line 1922 "yacc_sql.cpp"
    break;

  case 27: /* sync_stmt: SYNC  */
#line 281 "yacc_sql.y"
         {
      (yyval.sql_node) = new ParsedSqlNode(SCF_SYNC);
    }
#line 1930 "yacc_sql.cpp"
    break;

  case 28: /* begin_stmt: TRX_BEGIN  */
#line 287 "yacc_sql.y"
               {
      (yyval.sql_node) = new ParsedSqlNode(SCF_BEGIN);
    }
#line 1938 "yacc_sql.cpp"
    break;

  case 29: /* commit_stmt: TRX_COMMIT  */
#line 293 "yacc_sql.y"
               {
      (yyval.sql_node) = new ParsedSqlNode(SCF_COMMIT);
    }
#line 1946 "yacc_sql.cpp"
    break;

  case 30: /* rollback_stmt: TRX_ROLLBACK  */
#line 299 "yacc_sql.y"
                  {
      (yyval.sql_node) = new ParsedSqlNode(SCF_ROLLBACK);
    }
#line 1954 "yacc_sql.cpp"
    break;

  case 31: /* drop_table_stmt: DROP TABLE ID  */
#line 305 "yacc_sql.y"
                  {
      (yyval.sql_node) = new ParsedSqlNode(SCF_DROP_TABLE);
      (yyval.sql_node)->drop_table.relation_name = (yyvsp[0].string);
      free((yyvsp[0].string));
    }
#line 1964 "yacc_sql.cpp"
    break;

  case 32: /* clear_table_stmt: CLEAR TABLE  */
#line 311 "yacc_sql.y"
               {
      (yyval.sql_node) = new ParsedSqlNode(SCF_CLEAR_TABLE);
    }
#line 1972 "yacc_sql.cpp"
    break;

  case 33: /* show_tables_stmt: SHOW TABLES  */
#line 316 "yacc_sql.y"
                {
      (yyval.sql_node) = new ParsedSqlNode(SCF_SHOW_TABLES);
    }
#line 1980 "yacc_sql.cpp"
    break;

  case 34: /* show_index_stmt: SHOW INDEX FROM ID  */
#line 321 "yacc_sql.y"
                      {
      (yyval.sql_node) = new ParsedSqlNode(SCF_SHOW_INDEX);
      (yyval.sql_node)->show_index.relation_name = (yyvsp[0].string);
      free((yyvsp[0].string));
    }
#line 1990 "yacc_sql.cpp"
    break;

  case 35: /* desc_table_stmt: DESC ID  */
#line 329 "yacc_sql.y"
             {
      (yyval.sql_node) = new ParsedSqlNode(SCF_DESC_TABLE);
      (yyval.sql_node)->desc_table.relation_name = (yyvsp[0].string);
      free((yyvsp[0].string));
    }
#line 2000 "yacc_sql.cpp"
    break;

  case 36: /* create_index_stmt: CREATE INDEX ID ON ID LBRACE ID RBRACE  */
#line 338 "yacc_sql.y"
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
#line 2016 "yacc_sql.cpp"
    break;

  case 37: /* create_index_stmt: CREATE UNIQUE INDEX ID ON ID LBRACE ID RBRACE  */
#line 350 "yacc_sql.y"
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
#line 2032 "yacc_sql.cpp"
    break;

  case 38: /* drop_index_stmt: DROP INDEX ID ON ID  */
#line 365 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_DROP_INDEX);
      (yyval.sql_node)->drop_index.index_name = (yyvsp[-2].string);
      (yyval.sql_node)->drop_index.relation_name = (yyvsp[0].string);
      free((yyvsp[-2].string));
      free((yyvsp[0].string));
    }
#line 2044 "yacc_sql.cpp"
    break;

  case 39: /* create_table_stmt: CREATE TABLE ID LBRACE attr_def attr_def_list RBRACE  */
#line 375 "yacc_sql.y"
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
#line 2064 "yacc_sql.cpp"
    break;

  case 40: /* attr_def_list: %empty  */
#line 393 "yacc_sql.y"
    {
      (yyval.attr_infos) = nullptr;
    }
#line 2072 "yacc_sql.cpp"
    break;

  case 41: /* attr_def_list: COMMA attr_def attr_def_list  */
#line 397 "yacc_sql.y"
    {
      if ((yyvsp[0].attr_infos) != nullptr) {
        (yyval.attr_infos) = (yyvsp[0].attr_infos);
      } else {
        (yyval.attr_infos) = new std::vector<AttrInfoSqlNode>;
      }
      (yyval.attr_infos)->emplace_back(*(yyvsp[-1].attr_info));
      delete (yyvsp[-1].attr_info);
    }
#line 2086 "yacc_sql.cpp"
    break;

  case 42: /* attr_def: ID type LBRACE number RBRACE  */
#line 410 "yacc_sql.y"
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
#line 2104 "yacc_sql.cpp"
    break;

  case 43: /* attr_def: ID type  */
#line 424 "yacc_sql.y"
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
#line 2122 "yacc_sql.cpp"
    break;

  case 44: /* attr_def: ID type LBRACE number RBRACE NULLABLE  */
#line 438 "yacc_sql.y"
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
#line 2140 "yacc_sql.cpp"
    break;

  case 45: /* attr_def: ID type NULLABLE  */
#line 452 "yacc_sql.y"
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
#line 2158 "yacc_sql.cpp"
    break;

  case 46: /* attr_def: ID type LBRACE number RBRACE NOT NULL_T  */
#line 466 "yacc_sql.y"
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
#line 2176 "yacc_sql.cpp"
    break;

  case 47: /* attr_def: ID type NOT NULL_T  */
#line 480 "yacc_sql.y"
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
#line 2194 "yacc_sql.cpp"
    break;

  case 48: /* number: NUMBER  */
#line 495 "yacc_sql.y"
           {(yyval.number) = (yyvsp[0].number);}
#line 2200 "yacc_sql.cpp"
    break;

  case 49: /* type: INT_T  */
#line 498 "yacc_sql.y"
               { (yyval.number)=INTS; }
#line 2206 "yacc_sql.cpp"
    break;

  case 50: /* type: STRING_T  */
#line 499 "yacc_sql.y"
               { (yyval.number)=CHARS; }
#line 2212 "yacc_sql.cpp"
    break;

  case 51: /* type: FLOAT_T  */
#line 500 "yacc_sql.y"
               { (yyval.number)=FLOATS; }
#line 2218 "yacc_sql.cpp"
    break;

  case 52: /* type: DATE_T  */
#line 501 "yacc_sql.y"
                { (yyval.number)=DATES;}
#line 2224 "yacc_sql.cpp"
    break;

  case 53: /* type: TEXT_T  */
#line 502 "yacc_sql.y"
                { (yyval.number)=TEXTS;}
#line 2230 "yacc_sql.cpp"
    break;

  case 54: /* insert_stmt: INSERT INTO ID VALUES insert_value insert_value_list  */
#line 506 "yacc_sql.y"
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
#line 2249 "yacc_sql.cpp"
    break;

  case 55: /* insert_value_list: %empty  */
#line 523 "yacc_sql.y"
    {
      (yyval.insert_value_list) = nullptr;
    }
#line 2257 "yacc_sql.cpp"
    break;

  case 56: /* insert_value_list: COMMA insert_value insert_value_list  */
#line 527 "yacc_sql.y"
    {
      if ((yyvsp[0].insert_value_list) != nullptr) {
        (yyval.insert_value_list) = (yyvsp[0].insert_value_list);
      } else {
        (yyval.insert_value_list) = new std::vector<InsertValueSqlNode>;
      }
      (yyval.insert_value_list)->emplace_back(*(yyvsp[-1].insert_value));
      delete (yyvsp[-1].insert_value);
    }
#line 2271 "yacc_sql.cpp"
    break;

  case 57: /* insert_value: LBRACE value value_list RBRACE  */
#line 539 "yacc_sql.y"
    {
        (yyval.insert_value) = new InsertValueSqlNode;
        if((yyvsp[-1].value_list) != nullptr){
          (yyval.insert_value)->values.swap(*(yyvsp[-1].value_list));
        }
        (yyval.insert_value)->values.emplace_back(*(yyvsp[-2].value));
        std::reverse((yyval.insert_value)->values.begin(),(yyval.insert_value)->values.end());
        delete (yyvsp[-2].value);
    }
#line 2285 "yacc_sql.cpp"
    break;

  case 58: /* value_list: %empty  */
#line 553 "yacc_sql.y"
    {
      (yyval.value_list) = nullptr;
    }
#line 2293 "yacc_sql.cpp"
    break;

  case 59: /* value_list: COMMA express value_list  */
#line 556 "yacc_sql.y"
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
#line 2314 "yacc_sql.cpp"
    break;

  case 60: /* value: NUMBER  */
#line 574 "yacc_sql.y"
           {
      (yyval.value) = new Value((int)(yyvsp[0].number));
      (yyloc) = (yylsp[0]);
    }
#line 2323 "yacc_sql.cpp"
    break;

  case 61: /* value: FLOAT  */
#line 578 "yacc_sql.y"
           {
      (yyval.value) = new Value((float)(yyvsp[0].floats));
      (yyloc) = (yylsp[0]);
    }
#line 2332 "yacc_sql.cpp"
    break;

  case 62: /* value: DATE_STR  */
#line 582 "yacc_sql.y"
               {
      char *tmp = common::substr((yyvsp[0].string),1,strlen((yyvsp[0].string))-2);
      int y, m, d;
      sscanf(tmp, "%d-%d-%d", &y, &m, &d);


      (yyval.value) = new Value(y,m,d);

      
    }
#line 2347 "yacc_sql.cpp"
    break;

  case 63: /* value: SSS  */
#line 592 "yacc_sql.y"
         {
      char *tmp = common::substr((yyvsp[0].string),1,strlen((yyvsp[0].string))-2);
      (yyval.value) = new Value(tmp);
      free(tmp);
    }
#line 2357 "yacc_sql.cpp"
    break;

  case 64: /* value: null_or_nullable  */
#line 597 "yacc_sql.y"
                     {
      (yyval.value) = new Value(0);
      
      (yyval.value)->set_null(nullptr,4);
      
      
    }
#line 2369 "yacc_sql.cpp"
    break;

  case 65: /* delete_stmt: DELETE FROM ID where  */
#line 609 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_DELETE);
      (yyval.sql_node)->deletion.relation_name = (yyvsp[-1].string);
      if ((yyvsp[0].condition_list) != nullptr) {
        (yyval.sql_node)->deletion.conditions.swap(*(yyvsp[0].condition_list));
        delete (yyvsp[0].condition_list);
      }
      free((yyvsp[-1].string));
    }
#line 2383 "yacc_sql.cpp"
    break;

  case 66: /* update_stmt: UPDATE ID SET set_value set_value_list where  */
#line 621 "yacc_sql.y"
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
#line 2404 "yacc_sql.cpp"
    break;

  case 67: /* set_value_list: %empty  */
#line 640 "yacc_sql.y"
    {
      (yyval.update_value_list) = nullptr;
    }
#line 2412 "yacc_sql.cpp"
    break;

  case 68: /* set_value_list: COMMA set_value set_value_list  */
#line 643 "yacc_sql.y"
                                   {
      if ((yyvsp[0].update_value_list) != nullptr) {
        (yyval.update_value_list) = (yyvsp[0].update_value_list);
      } else {
        (yyval.update_value_list) = new std::vector<UpdateValueSqlNode>;
      }
      (yyval.update_value_list)->emplace_back(*(yyvsp[-1].update_value));
      delete (yyvsp[-1].update_value);

    }
#line 2427 "yacc_sql.cpp"
    break;

  case 69: /* set_value: ID EQ express  */
#line 656 "yacc_sql.y"
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
#line 2453 "yacc_sql.cpp"
    break;

  case 70: /* select_stmt: SELECT select_attr FROM rel_list where order_by group_by having_clause  */
#line 688 "yacc_sql.y"
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
#line 2489 "yacc_sql.cpp"
    break;

  case 71: /* select_stmt: SELECT select_attr  */
#line 720 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_SELECT);
      if((yyvsp[0].express_list) != nullptr){
        (yyval.sql_node)->selection.attributes.swap(*(yyvsp[0].express_list));
        delete (yyvsp[0].express_list);
      }

    }
#line 2502 "yacc_sql.cpp"
    break;

  case 72: /* calc_stmt: CALC expression_list  */
#line 731 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_CALC);
      std::reverse((yyvsp[0].expression_list)->begin(), (yyvsp[0].expression_list)->end());
      (yyval.sql_node)->calc.expressions.swap(*(yyvsp[0].expression_list));
      delete (yyvsp[0].expression_list);
    }
#line 2513 "yacc_sql.cpp"
    break;

  case 73: /* expression_list: expression  */
#line 741 "yacc_sql.y"
    {
      (yyval.expression_list) = new std::vector<Expression*>;
      (yyval.expression_list)->emplace_back((yyvsp[0].expression));
    }
#line 2522 "yacc_sql.cpp"
    break;

  case 74: /* expression_list: expression COMMA expression_list  */
#line 746 "yacc_sql.y"
    {
      if ((yyvsp[0].expression_list) != nullptr) {
        (yyval.expression_list) = (yyvsp[0].expression_list);
      } else {
        (yyval.expression_list) = new std::vector<Expression *>;
      }
      (yyval.expression_list)->emplace_back((yyvsp[-2].expression));
    }
#line 2535 "yacc_sql.cpp"
    break;

  case 75: /* expression: expression '+' expression  */
#line 756 "yacc_sql.y"
                              {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::ADD, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2543 "yacc_sql.cpp"
    break;

  case 76: /* expression: expression '-' expression  */
#line 759 "yacc_sql.y"
                                {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::SUB, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2551 "yacc_sql.cpp"
    break;

  case 77: /* expression: expression '*' expression  */
#line 762 "yacc_sql.y"
                                {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::MUL, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2559 "yacc_sql.cpp"
    break;

  case 78: /* expression: expression '/' expression  */
#line 765 "yacc_sql.y"
                                {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::DIV, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2567 "yacc_sql.cpp"
    break;

  case 79: /* expression: LBRACE expression RBRACE  */
#line 768 "yacc_sql.y"
                               {
      (yyval.expression) = (yyvsp[-1].expression);
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));
    }
#line 2576 "yacc_sql.cpp"
    break;

  case 80: /* expression: '-' expression  */
#line 772 "yacc_sql.y"
                                  {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::NEGATIVE, (yyvsp[0].expression), nullptr, sql_string, &(yyloc));
    }
#line 2584 "yacc_sql.cpp"
    break;

  case 81: /* expression: value  */
#line 775 "yacc_sql.y"
            {
      (yyval.expression) = new ValueExpr(*(yyvsp[0].value));
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));
      delete (yyvsp[0].value);
    }
#line 2594 "yacc_sql.cpp"
    break;

  case 82: /* express: express '+' express  */
#line 783 "yacc_sql.y"
                        {
      (yyval.express) = new ExprSqlNode;
      (yyval.express)->name = token_name(sql_string, &(yyloc));
      (yyval.express)->type = ExpressType::EXPR_T;
      (yyval.express)->add_left_child((yyvsp[-2].express));
      (yyval.express)->comp = ExprOp::ADD;
      (yyval.express)->add_right_child((yyvsp[0].express));
    }
#line 2607 "yacc_sql.cpp"
    break;

  case 83: /* express: express '-' express  */
#line 791 "yacc_sql.y"
                          {
      (yyval.express) = new ExprSqlNode;
      (yyval.express)->name = token_name(sql_string, &(yyloc));
      (yyval.express)->type = ExpressType::EXPR_T;
      (yyval.express)->add_left_child((yyvsp[-2].express));
      (yyval.express)->comp = ExprOp::SUB;
      (yyval.express)->add_right_child((yyvsp[0].express));
    }
#line 2620 "yacc_sql.cpp"
    break;

  case 84: /* express: express '*' express  */
#line 799 "yacc_sql.y"
                          {
      (yyval.express) = new ExprSqlNode;
      (yyval.express)->name = token_name(sql_string, &(yyloc));
      (yyval.express)->type = ExpressType::EXPR_T;
      (yyval.express)->add_left_child((yyvsp[-2].express));
      (yyval.express)->comp = ExprOp::MUL;
      (yyval.express)->add_right_child((yyvsp[0].express));
    }
#line 2633 "yacc_sql.cpp"
    break;

  case 85: /* express: express '/' express  */
#line 807 "yacc_sql.y"
                          {
      (yyval.express) = new ExprSqlNode;
      (yyval.express)->name = token_name(sql_string, &(yyloc));
      (yyval.express)->type = ExpressType::EXPR_T;
      (yyval.express)->add_left_child((yyvsp[-2].express));
      (yyval.express)->comp = ExprOp::DIV;
      (yyval.express)->add_right_child((yyvsp[0].express));
    }
#line 2646 "yacc_sql.cpp"
    break;

  case 86: /* express: LBRACE express RBRACE  */
#line 815 "yacc_sql.y"
                            {
      (yyval.express) = (yyvsp[-1].express);
      (yyval.express)->name = token_name(sql_string, &(yyloc));
    }
#line 2655 "yacc_sql.cpp"
    break;

  case 87: /* express: '-' express  */
#line 819 "yacc_sql.y"
                               {
      (yyval.express) = new ExprSqlNode;
      (yyval.express)->name = token_name(sql_string, &(yyloc));
      (yyval.express)->type = ExpressType::EXPR_T;
      (yyval.express)->add_left_child((yyvsp[0].express));
      (yyval.express)->comp = ExprOp::NEGATIVE;
    }
#line 2667 "yacc_sql.cpp"
    break;

  case 88: /* express: value  */
#line 826 "yacc_sql.y"
            {
      (yyval.express) = new ExprSqlNode;
      (yyval.express)->name = token_name(sql_string, &(yyloc));
      (yyval.express)->type = ExpressType::VALUE_T;
      (yyval.express)->left_value = *(yyvsp[0].value);
      delete (yyvsp[0].value);
    }
#line 2679 "yacc_sql.cpp"
    break;

  case 89: /* express: ID  */
#line 833 "yacc_sql.y"
         {
      (yyval.express) = new ExprSqlNode;
      (yyval.express)->name = token_name(sql_string, &(yyloc));
      (yyval.express)->type = ExpressType::ATTR_T;
      (yyval.express)->left_attr.attribute_name = (yyvsp[0].string);
      free((yyvsp[0].string));
    }
#line 2691 "yacc_sql.cpp"
    break;

  case 90: /* express: ID DOT ID  */
#line 840 "yacc_sql.y"
                {
      (yyval.express) = new ExprSqlNode;
      (yyval.express)->name = token_name(sql_string, &(yyloc));
      (yyval.express)->type = ExpressType::ATTR_T;
      (yyval.express)->left_attr.relation_name = (yyvsp[-2].string);
      (yyval.express)->left_attr.attribute_name = (yyvsp[0].string);
      free((yyvsp[-2].string));
      free((yyvsp[0].string));
    }
#line 2705 "yacc_sql.cpp"
    break;

  case 91: /* express: aggregation_func LBRACE ID RBRACE  */
#line 849 "yacc_sql.y"
                                       {
      (yyval.express) = new ExprSqlNode;
      (yyval.express)->name = token_name(sql_string, &(yyloc));
      (yyval.express)->type = ExpressType::ATTR_T;
      (yyval.express)->left_attr.attribute_name = (yyvsp[-1].string);
      free((yyvsp[-1].string));
      (yyval.express)->left_attr.is_aggregation_func = true;
      (yyval.express)->left_attr.aggr_func_type = (yyvsp[-3].aggr_func);
    }
#line 2719 "yacc_sql.cpp"
    break;

  case 92: /* express: aggregation_func LBRACE ID DOT ID RBRACE  */
#line 858 "yacc_sql.y"
                                              {
      (yyval.express) = new ExprSqlNode;
      (yyval.express)->name = token_name(sql_string, &(yyloc));
      (yyval.express)->type = ExpressType::ATTR_T;
      (yyval.express)->left_attr.relation_name  = (yyvsp[-3].string);
      (yyval.express)->left_attr.attribute_name = (yyvsp[-1].string);
      free((yyvsp[-3].string));
      free((yyvsp[-1].string));
      (yyval.express)->left_attr.is_aggregation_func = true;
      (yyval.express)->left_attr.aggr_func_type = (yyvsp[-5].aggr_func);
    }
#line 2735 "yacc_sql.cpp"
    break;

  case 93: /* express: aggregation_func LBRACE '*' RBRACE  */
#line 869 "yacc_sql.y"
                                        {
      (yyval.express) = new ExprSqlNode;
      (yyval.express)->name = token_name(sql_string, &(yyloc));
      (yyval.express)->type = ExpressType::ATTR_T;
      (yyval.express)->left_attr.relation_name = "";
      (yyval.express)->left_attr.attribute_name = "*";
      (yyval.express)->left_attr.is_aggregation_func = true;
      (yyval.express)->left_attr.aggr_func_type = (yyvsp[-3].aggr_func);
    }
#line 2749 "yacc_sql.cpp"
    break;

  case 94: /* express: aggregation_func LBRACE RBRACE  */
#line 878 "yacc_sql.y"
                                    {
      (yyval.express) = new ExprSqlNode;
      (yyval.express)->name = token_name(sql_string, &(yyloc));
      (yyval.express)->type = ExpressType::ATTR_T;
      (yyval.express)->left_attr.is_syntax_error = true;
    }
#line 2760 "yacc_sql.cpp"
    break;

  case 95: /* express: aggregation_func LBRACE rel_attr COMMA rel_attr attr_list RBRACE  */
#line 884 "yacc_sql.y"
                                                                      {
      (yyval.express) = new ExprSqlNode;
      (yyval.express)->name = token_name(sql_string, &(yyloc));
      (yyval.express)->type = ExpressType::ATTR_T;
      (yyval.express)->left_attr.is_syntax_error = true;
      delete (yyvsp[-4].rel_attr);
      delete (yyvsp[-2].rel_attr);
      delete (yyvsp[-1].rel_attr_list);
    }
#line 2774 "yacc_sql.cpp"
    break;

  case 96: /* express: aggregation_func LBRACE '*' COMMA rel_attr attr_list RBRACE  */
#line 893 "yacc_sql.y"
                                                                 {
      (yyval.express) = new ExprSqlNode;
      (yyval.express)->name = token_name(sql_string, &(yyloc));
      (yyval.express)->type = ExpressType::ATTR_T;
      (yyval.express)->left_attr.is_syntax_error = true;
      delete (yyvsp[-2].rel_attr);
      delete (yyvsp[-1].rel_attr_list);
    }
#line 2787 "yacc_sql.cpp"
    break;

  case 97: /* express: LBRACE select_stmt RBRACE  */
#line 902 "yacc_sql.y"
    {
      (yyval.express) = new ExprSqlNode;
      (yyval.express)->name = token_name(sql_string, &(yyloc));
      (yyval.express)->type = ExpressType::SELECT_T;
      (yyval.express)->left_selects = &((yyvsp[-1].sql_node)->selection);
    }
#line 2798 "yacc_sql.cpp"
    break;

  case 98: /* select_attr: '*' express_list  */
#line 931 "yacc_sql.y"
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
#line 2815 "yacc_sql.cpp"
    break;

  case 99: /* select_attr: express express_list  */
#line 943 "yacc_sql.y"
                           {
      if ((yyvsp[0].express_list) != nullptr) {
        (yyval.express_list) = (yyvsp[0].express_list);
      } else {
        (yyval.express_list) = new std::vector<ExprSqlNode *>;
      }
      (yyval.express_list)->emplace_back((yyvsp[-1].express));
    }
#line 2828 "yacc_sql.cpp"
    break;

  case 100: /* aggregation_func: MAX_FUNC  */
#line 953 "yacc_sql.y"
            {
      (yyval.aggr_func) = MAX;
    }
#line 2836 "yacc_sql.cpp"
    break;

  case 101: /* aggregation_func: MIN_FUNC  */
#line 956 "yacc_sql.y"
              {
      (yyval.aggr_func) = MIN;
    }
#line 2844 "yacc_sql.cpp"
    break;

  case 102: /* aggregation_func: CNT_FUNC  */
#line 959 "yacc_sql.y"
              {
      (yyval.aggr_func) = CNT;
    }
#line 2852 "yacc_sql.cpp"
    break;

  case 103: /* aggregation_func: AVG_FUNC  */
#line 962 "yacc_sql.y"
              {
      (yyval.aggr_func) = AVG;
    }
#line 2860 "yacc_sql.cpp"
    break;

  case 104: /* aggregation_func: SUM_FUNC  */
#line 965 "yacc_sql.y"
              {
      (yyval.aggr_func) = SUM;
    }
#line 2868 "yacc_sql.cpp"
    break;

  case 105: /* rel_attr: ID as_alias  */
#line 971 "yacc_sql.y"
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
#line 2885 "yacc_sql.cpp"
    break;

  case 106: /* rel_attr: ID DOT ID as_alias  */
#line 983 "yacc_sql.y"
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
#line 2904 "yacc_sql.cpp"
    break;

  case 107: /* rel_attr: function  */
#line 998 "yacc_sql.y"
    {
      (yyval.rel_attr) = (yyvsp[0].function);
    }
#line 2912 "yacc_sql.cpp"
    break;

  case 108: /* rel_attr: aggregation_func LBRACE ID RBRACE  */
#line 1001 "yacc_sql.y"
                                       {
      (yyval.rel_attr) = new RelAttrSqlNode;
      (yyval.rel_attr)->attribute_name = (yyvsp[-1].string);
      free((yyvsp[-1].string));
      (yyval.rel_attr)->is_aggregation_func = true;
      (yyval.rel_attr)->aggr_func_type = (yyvsp[-3].aggr_func);

    }
#line 2925 "yacc_sql.cpp"
    break;

  case 109: /* rel_attr: aggregation_func LBRACE ID DOT ID RBRACE  */
#line 1009 "yacc_sql.y"
                                              {
      (yyval.rel_attr) = new RelAttrSqlNode;
      (yyval.rel_attr)->relation_name  = (yyvsp[-3].string);
      (yyval.rel_attr)->attribute_name = (yyvsp[-1].string);
      free((yyvsp[-3].string));
      free((yyvsp[-1].string));
      (yyval.rel_attr)->is_aggregation_func = true;
      (yyval.rel_attr)->aggr_func_type = (yyvsp[-5].aggr_func);

    }
#line 2940 "yacc_sql.cpp"
    break;

  case 110: /* rel_attr: aggregation_func LBRACE '*' RBRACE  */
#line 1019 "yacc_sql.y"
                                        {
      (yyval.rel_attr) = new RelAttrSqlNode;
      (yyval.rel_attr)->relation_name = "";
      (yyval.rel_attr)->attribute_name = "*";
      (yyval.rel_attr)->is_aggregation_func = true;
      (yyval.rel_attr)->aggr_func_type = (yyvsp[-3].aggr_func);

    }
#line 2953 "yacc_sql.cpp"
    break;

  case 111: /* rel_attr: aggregation_func LBRACE RBRACE  */
#line 1027 "yacc_sql.y"
                                    {
      (yyval.rel_attr) = new RelAttrSqlNode;
      (yyval.rel_attr)->is_syntax_error = true;
      (yyval.rel_attr)->aggr_func_type = (yyvsp[-2].aggr_func);

    }
#line 2964 "yacc_sql.cpp"
    break;

  case 112: /* rel_attr: aggregation_func LBRACE rel_attr COMMA rel_attr attr_list RBRACE  */
#line 1033 "yacc_sql.y"
                                                                      {
      (yyval.rel_attr) = new RelAttrSqlNode;
      (yyval.rel_attr)->is_syntax_error = true;
      delete (yyvsp[-4].rel_attr);
      delete (yyvsp[-2].rel_attr);
      delete (yyvsp[-1].rel_attr_list);

    }
#line 2977 "yacc_sql.cpp"
    break;

  case 113: /* rel_attr: aggregation_func LBRACE '*' COMMA rel_attr attr_list RBRACE  */
#line 1041 "yacc_sql.y"
                                                                 {
      (yyval.rel_attr) = new RelAttrSqlNode;
      (yyval.rel_attr)->is_syntax_error = true;
      delete (yyvsp[-2].rel_attr);
      delete (yyvsp[-1].rel_attr_list);

    }
#line 2989 "yacc_sql.cpp"
    break;

  case 114: /* as_alias: %empty  */
#line 1051 "yacc_sql.y"
    {
      (yyval.string) = nullptr;
    }
#line 2997 "yacc_sql.cpp"
    break;

  case 115: /* as_alias: AS ID  */
#line 1054 "yacc_sql.y"
           {
      (yyval.string) = (char*)malloc(strlen((yyvsp[0].string))+1);
      strcpy((yyval.string),(yyvsp[0].string));
      free((yyvsp[0].string));
    }
#line 3007 "yacc_sql.cpp"
    break;

  case 116: /* as_alias: AS ID DOT ID  */
#line 1059 "yacc_sql.y"
                  {
      (yyval.string) = (char*)malloc(strlen((yyvsp[-2].string))+strlen((yyvsp[0].string))+2);
      strcpy((yyval.string),(yyvsp[-2].string));
      strcpy((yyval.string)+strlen((yyvsp[-2].string)),".");
      strcpy((yyval.string)+strlen((yyvsp[-2].string))+1,(yyvsp[0].string));
      free((yyvsp[-2].string));
      free((yyvsp[0].string));
    }
#line 3020 "yacc_sql.cpp"
    break;

  case 117: /* as_alias: ID  */
#line 1067 "yacc_sql.y"
        {
      (yyval.string) = (char*)malloc(strlen((yyvsp[0].string))+1);
      strcpy((yyval.string),(yyvsp[0].string));
      free((yyvsp[0].string));
    }
#line 3030 "yacc_sql.cpp"
    break;

  case 118: /* as_alias: ID DOT ID  */
#line 1072 "yacc_sql.y"
               {
      (yyval.string) = (char*)malloc(strlen((yyvsp[-2].string))+strlen((yyvsp[0].string))+2);
      strcpy((yyval.string),(yyvsp[-2].string));
      strcpy((yyval.string)+strlen((yyvsp[-2].string)),".");
      strcpy((yyval.string)+strlen((yyvsp[-2].string))+1,(yyvsp[0].string));
      free((yyvsp[-2].string));
      free((yyvsp[0].string));
    }
#line 3043 "yacc_sql.cpp"
    break;

  case 119: /* attr_list: %empty  */
#line 1083 "yacc_sql.y"
    {
      (yyval.rel_attr_list) = nullptr;
    }
#line 3051 "yacc_sql.cpp"
    break;

  case 120: /* attr_list: COMMA rel_attr attr_list  */
#line 1086 "yacc_sql.y"
                               {
      if ((yyvsp[0].rel_attr_list) != nullptr) {
        (yyval.rel_attr_list) = (yyvsp[0].rel_attr_list);
      } else {
        (yyval.rel_attr_list) = new std::vector<RelAttrSqlNode>;
      }

      (yyval.rel_attr_list)->emplace_back(*(yyvsp[-1].rel_attr));
      delete (yyvsp[-1].rel_attr);
    }
#line 3066 "yacc_sql.cpp"
    break;

  case 121: /* express_list: %empty  */
#line 1100 "yacc_sql.y"
    {
      (yyval.express_list) = nullptr;
    }
#line 3074 "yacc_sql.cpp"
    break;

  case 122: /* express_list: COMMA express express_list  */
#line 1103 "yacc_sql.y"
                                 {
      if ((yyvsp[0].express_list) != nullptr) {
        (yyval.express_list) = (yyvsp[0].express_list);
      } else {
        (yyval.express_list) = new std::vector<ExprSqlNode *>;
      }

      (yyval.express_list)->emplace_back((yyvsp[-1].express));
    }
#line 3088 "yacc_sql.cpp"
    break;

  case 123: /* inner_join: INNER JOIN ID ON condition_list  */
#line 1116 "yacc_sql.y"
    {
        (yyval.join_rel) = new JoinedRelationSqlNode;
        (yyval.join_rel)->relations.push_back((yyvsp[-2].string));
        for(auto iter:*(yyvsp[0].condition_list)){
          (yyval.join_rel)->join_on_conditions.emplace_back(iter);
        }
        // free($3);
    }
#line 3101 "yacc_sql.cpp"
    break;

  case 124: /* inner_join_list: %empty  */
#line 1126 "yacc_sql.y"
    {
      (yyval.join_rel) = nullptr;
    }
#line 3109 "yacc_sql.cpp"
    break;

  case 125: /* inner_join_list: inner_join inner_join_list  */
#line 1130 "yacc_sql.y"
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
#line 3128 "yacc_sql.cpp"
    break;

  case 126: /* join_relation: ID inner_join inner_join_list  */
#line 1147 "yacc_sql.y"
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
#line 3156 "yacc_sql.cpp"
    break;

  case 127: /* rel_element: ID as_alias  */
#line 1174 "yacc_sql.y"
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
#line 3175 "yacc_sql.cpp"
    break;

  case 128: /* rel_element: join_relation  */
#line 1189 "yacc_sql.y"
    {
      (yyval.relation) = new RelationSqlNode;
      (yyval.relation)->inner_join_sql_node = *(yyvsp[0].join_rel);
      (yyval.relation) -> has_inner_join = true;
      // delete $1;

    }
#line 3187 "yacc_sql.cpp"
    break;

  case 129: /* rel_list: rel_element  */
#line 1200 "yacc_sql.y"
    { 
      (yyval.relation_list) = new std::vector<RelationSqlNode>;
      (yyval.relation_list)->emplace_back(*(yyvsp[0].relation));
      // delete $1;
    }
#line 3197 "yacc_sql.cpp"
    break;

  case 130: /* rel_list: rel_element COMMA rel_list  */
#line 1205 "yacc_sql.y"
                                 {
      (yyval.relation_list) = (yyvsp[0].relation_list);
      (yyval.relation_list)->emplace_back(*(yyvsp[-2].relation));
      // delete $1;
    }
#line 3207 "yacc_sql.cpp"
    break;

  case 131: /* where: %empty  */
#line 1213 "yacc_sql.y"
    {
      (yyval.condition_list) = nullptr;
    }
#line 3215 "yacc_sql.cpp"
    break;

  case 132: /* where: WHERE condition_list  */
#line 1216 "yacc_sql.y"
                           {
      (yyval.condition_list) = (yyvsp[0].condition_list);  
    }
#line 3223 "yacc_sql.cpp"
    break;

  case 133: /* having_clause: %empty  */
#line 1222 "yacc_sql.y"
    {
      (yyval.condition_list) = nullptr;
    }
#line 3231 "yacc_sql.cpp"
    break;

  case 134: /* having_clause: HAVING condition_list  */
#line 1225 "yacc_sql.y"
                            {
      (yyval.condition_list) = (yyvsp[0].condition_list);  
    }
#line 3239 "yacc_sql.cpp"
    break;

  case 135: /* condition_list: %empty  */
#line 1232 "yacc_sql.y"
    {
      (yyval.condition_list) = nullptr;
    }
#line 3247 "yacc_sql.cpp"
    break;

  case 136: /* condition_list: condition  */
#line 1235 "yacc_sql.y"
                {
      (yyval.condition_list) = new std::vector<ConditionSqlNode>;
      (yyval.condition_list)->emplace_back(*(yyvsp[0].condition));
      delete (yyvsp[0].condition);
    }
#line 3257 "yacc_sql.cpp"
    break;

  case 137: /* condition_list: condition AND condition_list  */
#line 1240 "yacc_sql.y"
                                   {
      (yyval.condition_list) = (yyvsp[0].condition_list);
      (yyval.condition_list)->emplace_back(*(yyvsp[-2].condition));
      delete (yyvsp[-2].condition);
    }
#line 3267 "yacc_sql.cpp"
    break;

  case 138: /* condition: express comp_op express  */
#line 1296 "yacc_sql.y"
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
      else {
        (yyval.condition)->left_type = ExpressType::EXPR_T;
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
      else {
        (yyval.condition)->right_type = ExpressType::EXPR_T;
        (yyval.condition)->right_expr = (yyvsp[0].express);
      }
    }
#line 3312 "yacc_sql.cpp"
    break;

  case 139: /* group_by: %empty  */
#line 1387 "yacc_sql.y"
    {
      (yyval.rel_attr_list) = nullptr;
    }
#line 3320 "yacc_sql.cpp"
    break;

  case 140: /* group_by: GROUP BY rel_attr attr_list  */
#line 1390 "yacc_sql.y"
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
#line 3335 "yacc_sql.cpp"
    break;

  case 141: /* order_by: %empty  */
#line 1403 "yacc_sql.y"
    {
      (yyval.order_list) = nullptr;
    }
#line 3343 "yacc_sql.cpp"
    break;

  case 142: /* order_by: ORDER BY order_list  */
#line 1406 "yacc_sql.y"
                          {
      (yyval.order_list) = (yyvsp[0].order_list);
    }
#line 3351 "yacc_sql.cpp"
    break;

  case 143: /* order: rel_attr  */
#line 1411 "yacc_sql.y"
             {
      (yyval.order) = new OrderBySqlNode;
      (yyval.order)->rel_attr = *(yyvsp[0].rel_attr);
      (yyval.order)->direction = OrderByDirection::ASC_ORDER;
    }
#line 3361 "yacc_sql.cpp"
    break;

  case 144: /* order: rel_attr DESC  */
#line 1416 "yacc_sql.y"
                   {
      (yyval.order) = new OrderBySqlNode;
      (yyval.order)->rel_attr = *(yyvsp[-1].rel_attr);
      (yyval.order)->direction = OrderByDirection::DESC_ORDER;
    }
#line 3371 "yacc_sql.cpp"
    break;

  case 145: /* order: rel_attr ASC  */
#line 1421 "yacc_sql.y"
                  {
      (yyval.order) = new OrderBySqlNode;
      (yyval.order)->rel_attr = *(yyvsp[-1].rel_attr);
      (yyval.order)->direction = OrderByDirection::ASC_ORDER;
    }
#line 3381 "yacc_sql.cpp"
    break;

  case 146: /* order_list: %empty  */
#line 1429 "yacc_sql.y"
    {
      (yyval.order_list) = nullptr;
    }
#line 3389 "yacc_sql.cpp"
    break;

  case 147: /* order_list: order  */
#line 1432 "yacc_sql.y"
           {
        (yyval.order_list) = new std::vector<OrderBySqlNode>;
        (yyval.order_list)->emplace_back(*(yyvsp[0].order));
        delete (yyvsp[0].order);
    }
#line 3399 "yacc_sql.cpp"
    break;

  case 148: /* order_list: order COMMA order_list  */
#line 1437 "yacc_sql.y"
                            {
      (yyval.order_list) = (yyvsp[0].order_list);
      (yyval.order_list)->emplace_back(*(yyvsp[-2].order));
      delete (yyvsp[-2].order);
    }
#line 3409 "yacc_sql.cpp"
    break;

  case 149: /* function: LENGTH LBRACE rel_attr RBRACE  */
#line 1446 "yacc_sql.y"
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
#line 3427 "yacc_sql.cpp"
    break;

  case 150: /* function: LENGTH LBRACE SSS RBRACE  */
#line 1460 "yacc_sql.y"
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
#line 3446 "yacc_sql.cpp"
    break;

  case 151: /* function: ROUND LBRACE rel_attr COMMA NUMBER RBRACE  */
#line 1475 "yacc_sql.y"
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
#line 3468 "yacc_sql.cpp"
    break;

  case 152: /* function: ROUND LBRACE NUMBER COMMA NUMBER RBRACE  */
#line 1493 "yacc_sql.y"
    {

        (yyval.function) = new RelAttrSqlNode;
        (yyval.function)->is_function = true;
        (yyval.function)->function_type = FunctionType::ROUND_FUNC;
        FunctionMetaInfo tmp_func_info;
        tmp_func_info.round_type = (int)(yyvsp[-1].number);
        (yyval.function)->function_meta_info = tmp_func_info;
        (yyval.function)->is_constant_value = true;
        (yyval.function)->constant_value.set_value(Value((float)(yyvsp[-3].number)));
        
    }
#line 3485 "yacc_sql.cpp"
    break;

  case 153: /* function: DATE_FORMAT LBRACE rel_attr COMMA SSS RBRACE  */
#line 1506 "yacc_sql.y"
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
#line 3506 "yacc_sql.cpp"
    break;

  case 154: /* null_or_nullable: NULL_T  */
#line 1526 "yacc_sql.y"
    {
      (yyval.number) = 1;
    }
#line 3514 "yacc_sql.cpp"
    break;

  case 155: /* null_or_nullable: NULLABLE  */
#line 1530 "yacc_sql.y"
    {
      (yyval.number) = 1;
    }
#line 3522 "yacc_sql.cpp"
    break;

  case 156: /* comp_op: EQ  */
#line 1536 "yacc_sql.y"
         { (yyval.comp) = EQUAL_TO; }
#line 3528 "yacc_sql.cpp"
    break;

  case 157: /* comp_op: LT  */
#line 1537 "yacc_sql.y"
         { (yyval.comp) = LESS_THAN; }
#line 3534 "yacc_sql.cpp"
    break;

  case 158: /* comp_op: GT  */
#line 1538 "yacc_sql.y"
         { (yyval.comp) = GREAT_THAN; }
#line 3540 "yacc_sql.cpp"
    break;

  case 159: /* comp_op: LE  */
#line 1539 "yacc_sql.y"
         { (yyval.comp) = LESS_EQUAL; }
#line 3546 "yacc_sql.cpp"
    break;

  case 160: /* comp_op: GE  */
#line 1540 "yacc_sql.y"
         { (yyval.comp) = GREAT_EQUAL; }
#line 3552 "yacc_sql.cpp"
    break;

  case 161: /* comp_op: NE  */
#line 1541 "yacc_sql.y"
         { (yyval.comp) = NOT_EQUAL; }
#line 3558 "yacc_sql.cpp"
    break;

  case 162: /* comp_op: IS  */
#line 1542 "yacc_sql.y"
         { (yyval.comp) = IS_EQUAL;}
#line 3564 "yacc_sql.cpp"
    break;

  case 163: /* comp_op: IS NOT  */
#line 1543 "yacc_sql.y"
            {(yyval.comp) = IS_NOT_EQUAL;}
#line 3570 "yacc_sql.cpp"
    break;

  case 164: /* comp_op: LIKE_MARK  */
#line 1544 "yacc_sql.y"
                {(yyval.comp) = LIKE;}
#line 3576 "yacc_sql.cpp"
    break;

  case 165: /* comp_op: NOT LIKE_MARK  */
#line 1545 "yacc_sql.y"
                    {(yyval.comp) = NOT_LIKE;}
#line 3582 "yacc_sql.cpp"
    break;

  case 166: /* comp_op: IN  */
#line 1546 "yacc_sql.y"
         {(yyval.comp) = IN_COMP;}
#line 3588 "yacc_sql.cpp"
    break;

  case 167: /* comp_op: NOT IN  */
#line 1547 "yacc_sql.y"
             {(yyval.comp) = NOT_IN_COMP;}
#line 3594 "yacc_sql.cpp"
    break;

  case 168: /* load_data_stmt: LOAD DATA INFILE SSS INTO TABLE ID  */
#line 1552 "yacc_sql.y"
    {
      char *tmp_file_name = common::substr((yyvsp[-3].string), 1, strlen((yyvsp[-3].string)) - 2);
      
      (yyval.sql_node) = new ParsedSqlNode(SCF_LOAD_DATA);
      (yyval.sql_node)->load_data.relation_name = (yyvsp[0].string);
      (yyval.sql_node)->load_data.file_name = tmp_file_name;
      free((yyvsp[0].string));
      free(tmp_file_name);
    }
#line 3608 "yacc_sql.cpp"
    break;

  case 169: /* explain_stmt: EXPLAIN command_wrapper  */
#line 1565 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_EXPLAIN);
      (yyval.sql_node)->explain.sql_node = std::unique_ptr<ParsedSqlNode>((yyvsp[0].sql_node));
    }
#line 3617 "yacc_sql.cpp"
    break;

  case 170: /* set_variable_stmt: SET ID EQ value  */
#line 1573 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_SET_VARIABLE);
      (yyval.sql_node)->set_variable.name  = (yyvsp[-2].string);
      (yyval.sql_node)->set_variable.value = *(yyvsp[0].value);
      free((yyvsp[-2].string));
      delete (yyvsp[0].value);
    }
#line 3629 "yacc_sql.cpp"
    break;


#line 3633 "yacc_sql.cpp"

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

#line 1585 "yacc_sql.y"

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
