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
  YYSYMBOL_SET = 44,                       /* SET  */
  YYSYMBOL_ON = 45,                        /* ON  */
  YYSYMBOL_LIKE_MARK = 46,                 /* LIKE_MARK  */
  YYSYMBOL_NOT = 47,                       /* NOT  */
  YYSYMBOL_LOAD = 48,                      /* LOAD  */
  YYSYMBOL_DATA = 49,                      /* DATA  */
  YYSYMBOL_INFILE = 50,                    /* INFILE  */
  YYSYMBOL_EXPLAIN = 51,                   /* EXPLAIN  */
  YYSYMBOL_CLEAR = 52,                     /* CLEAR  */
  YYSYMBOL_IS = 53,                        /* IS  */
  YYSYMBOL_IN = 54,                        /* IN  */
  YYSYMBOL_AS = 55,                        /* AS  */
  YYSYMBOL_NULL_T = 56,                    /* NULL_T  */
  YYSYMBOL_NULLABLE = 57,                  /* NULLABLE  */
  YYSYMBOL_CNT_FUNC = 58,                  /* CNT_FUNC  */
  YYSYMBOL_MAX_FUNC = 59,                  /* MAX_FUNC  */
  YYSYMBOL_MIN_FUNC = 60,                  /* MIN_FUNC  */
  YYSYMBOL_AVG_FUNC = 61,                  /* AVG_FUNC  */
  YYSYMBOL_SUM_FUNC = 62,                  /* SUM_FUNC  */
  YYSYMBOL_EQ = 63,                        /* EQ  */
  YYSYMBOL_LT = 64,                        /* LT  */
  YYSYMBOL_GT = 65,                        /* GT  */
  YYSYMBOL_LE = 66,                        /* LE  */
  YYSYMBOL_GE = 67,                        /* GE  */
  YYSYMBOL_NE = 68,                        /* NE  */
  YYSYMBOL_NUMBER = 69,                    /* NUMBER  */
  YYSYMBOL_FLOAT = 70,                     /* FLOAT  */
  YYSYMBOL_ID = 71,                        /* ID  */
  YYSYMBOL_DATE_STR = 72,                  /* DATE_STR  */
  YYSYMBOL_SSS = 73,                       /* SSS  */
  YYSYMBOL_74_ = 74,                       /* '+'  */
  YYSYMBOL_75_ = 75,                       /* '-'  */
  YYSYMBOL_76_ = 76,                       /* '*'  */
  YYSYMBOL_77_ = 77,                       /* '/'  */
  YYSYMBOL_UMINUS = 78,                    /* UMINUS  */
  YYSYMBOL_YYACCEPT = 79,                  /* $accept  */
  YYSYMBOL_commands = 80,                  /* commands  */
  YYSYMBOL_command_wrapper = 81,           /* command_wrapper  */
  YYSYMBOL_exit_stmt = 82,                 /* exit_stmt  */
  YYSYMBOL_help_stmt = 83,                 /* help_stmt  */
  YYSYMBOL_sync_stmt = 84,                 /* sync_stmt  */
  YYSYMBOL_begin_stmt = 85,                /* begin_stmt  */
  YYSYMBOL_commit_stmt = 86,               /* commit_stmt  */
  YYSYMBOL_rollback_stmt = 87,             /* rollback_stmt  */
  YYSYMBOL_drop_table_stmt = 88,           /* drop_table_stmt  */
  YYSYMBOL_clear_table_stmt = 89,          /* clear_table_stmt  */
  YYSYMBOL_show_tables_stmt = 90,          /* show_tables_stmt  */
  YYSYMBOL_show_index_stmt = 91,           /* show_index_stmt  */
  YYSYMBOL_desc_table_stmt = 92,           /* desc_table_stmt  */
  YYSYMBOL_create_index_stmt = 93,         /* create_index_stmt  */
  YYSYMBOL_drop_index_stmt = 94,           /* drop_index_stmt  */
  YYSYMBOL_create_table_stmt = 95,         /* create_table_stmt  */
  YYSYMBOL_attr_def_list = 96,             /* attr_def_list  */
  YYSYMBOL_attr_def = 97,                  /* attr_def  */
  YYSYMBOL_number = 98,                    /* number  */
  YYSYMBOL_type = 99,                      /* type  */
  YYSYMBOL_insert_stmt = 100,              /* insert_stmt  */
  YYSYMBOL_insert_value_list = 101,        /* insert_value_list  */
  YYSYMBOL_insert_value = 102,             /* insert_value  */
  YYSYMBOL_value_list = 103,               /* value_list  */
  YYSYMBOL_value = 104,                    /* value  */
  YYSYMBOL_delete_stmt = 105,              /* delete_stmt  */
  YYSYMBOL_update_stmt = 106,              /* update_stmt  */
  YYSYMBOL_set_value_list = 107,           /* set_value_list  */
  YYSYMBOL_set_value = 108,                /* set_value  */
  YYSYMBOL_select_stmt = 109,              /* select_stmt  */
  YYSYMBOL_calc_stmt = 110,                /* calc_stmt  */
  YYSYMBOL_expression_list = 111,          /* expression_list  */
  YYSYMBOL_expression = 112,               /* expression  */
  YYSYMBOL_select_attr = 113,              /* select_attr  */
  YYSYMBOL_aggregation_func = 114,         /* aggregation_func  */
  YYSYMBOL_rel_attr = 115,                 /* rel_attr  */
  YYSYMBOL_as_alias = 116,                 /* as_alias  */
  YYSYMBOL_attr_list = 117,                /* attr_list  */
  YYSYMBOL_inner_join = 118,               /* inner_join  */
  YYSYMBOL_inner_join_list = 119,          /* inner_join_list  */
  YYSYMBOL_join_relation = 120,            /* join_relation  */
  YYSYMBOL_rel_element = 121,              /* rel_element  */
  YYSYMBOL_rel_list = 122,                 /* rel_list  */
  YYSYMBOL_where = 123,                    /* where  */
  YYSYMBOL_condition_list = 124,           /* condition_list  */
  YYSYMBOL_condition = 125,                /* condition  */
  YYSYMBOL_group_by = 126,                 /* group_by  */
  YYSYMBOL_order_by = 127,                 /* order_by  */
  YYSYMBOL_order = 128,                    /* order  */
  YYSYMBOL_order_list = 129,               /* order_list  */
  YYSYMBOL_null_or_nullable = 130,         /* null_or_nullable  */
  YYSYMBOL_comp_op = 131,                  /* comp_op  */
  YYSYMBOL_load_data_stmt = 132,           /* load_data_stmt  */
  YYSYMBOL_explain_stmt = 133,             /* explain_stmt  */
  YYSYMBOL_set_variable_stmt = 134,        /* set_variable_stmt  */
  YYSYMBOL_opt_semicolon = 135             /* opt_semicolon  */
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
#define YYFINAL  81
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   306

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  79
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  57
/* YYNRULES -- Number of rules.  */
#define YYNRULES  149
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  277

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   329


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
       2,     2,    76,    74,     2,    75,     2,    77,     2,     2,
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
      65,    66,    67,    68,    69,    70,    71,    72,    73,    78
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   225,   225,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   258,   264,   269,   275,   281,
     287,   293,   299,   304,   309,   317,   325,   337,   352,   362,
     381,   384,   397,   411,   425,   439,   453,   467,   483,   486,
     487,   488,   489,   490,   493,   511,   514,   526,   541,   544,
     555,   559,   563,   573,   578,   589,   601,   621,   624,   636,
     645,   657,   687,   697,   702,   713,   716,   719,   722,   725,
     729,   732,   740,   751,   762,   765,   768,   771,   774,   780,
     792,   806,   814,   824,   832,   838,   846,   856,   859,   864,
     875,   878,   891,   902,   905,   922,   949,   964,   975,   981,
     989,   992,   998,  1001,  1006,  1013,  1025,  1037,  1049,  1061,
    1073,  1085,  1097,  1112,  1115,  1128,  1131,  1136,  1141,  1146,
    1154,  1157,  1162,  1169,  1173,  1180,  1181,  1182,  1183,  1184,
    1185,  1186,  1187,  1188,  1189,  1193,  1206,  1214,  1224,  1225
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
  "BY", "SET", "ON", "LIKE_MARK", "NOT", "LOAD", "DATA", "INFILE",
  "EXPLAIN", "CLEAR", "IS", "IN", "AS", "NULL_T", "NULLABLE", "CNT_FUNC",
  "MAX_FUNC", "MIN_FUNC", "AVG_FUNC", "SUM_FUNC", "EQ", "LT", "GT", "LE",
  "GE", "NE", "NUMBER", "FLOAT", "ID", "DATE_STR", "SSS", "'+'", "'-'",
  "'*'", "'/'", "UMINUS", "$accept", "commands", "command_wrapper",
  "exit_stmt", "help_stmt", "sync_stmt", "begin_stmt", "commit_stmt",
  "rollback_stmt", "drop_table_stmt", "clear_table_stmt",
  "show_tables_stmt", "show_index_stmt", "desc_table_stmt",
  "create_index_stmt", "drop_index_stmt", "create_table_stmt",
  "attr_def_list", "attr_def", "number", "type", "insert_stmt",
  "insert_value_list", "insert_value", "value_list", "value",
  "delete_stmt", "update_stmt", "set_value_list", "set_value",
  "select_stmt", "calc_stmt", "expression_list", "expression",
  "select_attr", "aggregation_func", "rel_attr", "as_alias", "attr_list",
  "inner_join", "inner_join_list", "join_relation", "rel_element",
  "rel_list", "where", "condition_list", "condition", "group_by",
  "order_by", "order", "order_list", "null_or_nullable", "comp_op",
  "load_data_stmt", "explain_stmt", "set_variable_stmt", "opt_semicolon", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-190)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     172,    15,    67,     8,   -43,   -62,    62,  -190,     3,    12,
      11,  -190,  -190,  -190,  -190,  -190,    19,    30,   172,    91,
      99,   100,  -190,  -190,  -190,  -190,  -190,  -190,  -190,  -190,
    -190,  -190,  -190,  -190,  -190,  -190,  -190,  -190,  -190,  -190,
    -190,  -190,  -190,  -190,    38,    97,    39,    47,    59,     8,
    -190,  -190,  -190,  -190,  -190,  -190,     8,  -190,  -190,    10,
    -190,  -190,  -190,  -190,  -190,  -190,   -19,   110,    96,   123,
     110,  -190,  -190,   107,    98,   108,   126,   115,    94,  -190,
    -190,  -190,  -190,  -190,   161,   114,   136,  -190,   146,   -16,
    -190,     8,     8,     8,     8,     8,   121,   122,  -190,   183,
    -190,   129,    -9,  -190,   130,   169,   166,   135,    84,   134,
     139,   167,   140,   142,  -190,  -190,   -47,   -47,  -190,  -190,
     163,   185,   110,   -17,  -190,   198,   166,  -190,   -10,    68,
     200,  -190,   203,    55,  -190,   168,   211,  -190,   199,    14,
     232,   184,   237,  -190,  -190,   186,  -190,   220,  -190,   222,
     129,   219,  -190,   191,  -190,   183,   183,    84,   242,   253,
     162,   162,  -190,   225,    35,   135,   166,   260,  -190,  -190,
    -190,  -190,  -190,   -13,   139,   247,   249,   201,  -190,   202,
     222,  -190,  -190,   226,   228,    -8,   110,   110,   250,   203,
    -190,   254,  -190,   229,   230,  -190,  -190,  -190,  -190,  -190,
    -190,    77,   102,    55,   253,  -190,   211,  -190,   205,   209,
     223,  -190,   232,  -190,   210,   262,   235,  -190,   183,   240,
    -190,  -190,   264,   265,    84,   266,   242,   162,  -190,  -190,
     253,  -190,  -190,   253,  -190,  -190,  -190,   267,  -190,  -190,
    -190,   268,  -190,  -190,   269,  -190,    55,    81,   270,  -190,
     183,  -190,  -190,   250,  -190,  -190,   178,   272,   273,  -190,
     -22,  -190,  -190,  -190,  -190,   183,   110,  -190,  -190,  -190,
    -190,  -190,   234,  -190,  -190,  -190,  -190
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,    27,     0,     0,
       0,    28,    29,    30,    26,    25,     0,     0,     0,     0,
       0,   148,    23,    22,    15,    16,    17,    18,     9,    24,
      10,    11,    12,    13,    14,     8,     5,     7,     6,     4,
       3,    19,    20,    21,     0,     0,     0,     0,     0,     0,
     133,   134,    60,    61,    62,    63,     0,    81,    72,    73,
      64,    86,    84,    85,    87,    88,    97,   100,     0,     0,
     100,    35,    33,     0,     0,     0,     0,     0,     0,   146,
      32,     1,   149,     2,     0,     0,     0,    31,     0,     0,
      80,     0,     0,     0,     0,     0,     0,     0,    89,     0,
      82,     0,     0,    83,     0,     0,   110,     0,     0,     0,
       0,     0,     0,     0,    79,    74,    75,    76,    77,    78,
      97,    98,   100,    97,   107,   108,   110,    94,    97,     0,
       0,    34,     0,   112,    65,     0,    67,   147,     0,     0,
      40,     0,     0,    38,    90,     0,   101,     0,   106,   103,
       0,   125,    91,     0,    93,     0,     0,     0,    55,     0,
       0,     0,   111,   113,     0,     0,   110,     0,    49,    50,
      51,    52,    53,    43,     0,     0,     0,     0,    99,     0,
     103,   105,   109,     0,   123,    97,   100,   100,    58,     0,
      54,     0,   143,     0,   141,   135,   136,   137,   138,   139,
     140,     0,     0,   112,     0,    69,    67,    66,     0,     0,
       0,    45,    40,    39,     0,     0,     0,   104,   130,     0,
      71,    92,     0,     0,     0,     0,    55,     0,   144,   142,
       0,   116,   118,     0,   115,   117,   114,     0,    68,   145,
      48,     0,    47,    41,     0,    36,   112,   127,   131,   126,
       0,    96,    95,    58,    57,    56,     0,     0,     0,    70,
      42,    37,   102,   128,   129,   130,   100,    59,   121,   122,
     119,   120,     0,    44,   132,   124,    46
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -190,  -190,   276,  -190,  -190,  -190,  -190,  -190,  -190,  -190,
    -190,  -190,  -190,  -190,  -190,  -190,  -190,    83,   124,  -190,
    -190,  -190,    70,   111,    44,  -101,  -190,  -190,    93,   137,
    -158,  -190,   212,    73,  -190,  -190,    -4,  -115,   -67,   181,
     125,  -190,  -190,   151,  -100,  -189,  -190,  -190,  -190,  -190,
      41,  -190,  -159,  -190,  -190,  -190,  -190
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,   175,   140,   241,
     173,    36,   190,   158,   225,    57,    37,    38,   166,   136,
      39,    40,    58,    59,    68,    69,   161,    98,   100,   180,
     181,   124,   125,   126,   134,   162,   163,   220,   184,   248,
     249,    60,   201,    41,    42,    43,    83
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      70,   191,   202,   103,   114,   144,   209,   137,   148,    71,
     152,   127,   221,    96,   236,    61,    62,    63,    64,    65,
     147,    44,   153,    45,    46,   272,   151,    49,    66,    94,
      95,    91,   160,    67,   210,   273,    97,    74,    97,   168,
     169,   170,   171,   172,   211,    97,   237,    97,    75,    61,
      62,    63,    64,    65,   204,   146,   188,   262,    92,    93,
      94,    95,   128,   205,    50,    51,   207,   129,   256,    72,
     144,    73,   257,    47,   159,   258,    48,    52,    53,    78,
      54,    55,    76,    56,    92,    93,    94,    95,   154,   155,
      77,    50,    51,   263,   264,   122,   230,    80,   130,    81,
     231,   234,   160,    82,    52,    53,    85,    54,    55,    84,
      86,    50,    51,    61,    62,    63,    64,    65,    87,   222,
     223,   233,    89,   253,    52,    53,    66,    54,    55,    90,
      88,    99,   101,    50,    51,    61,    62,    63,    64,    65,
      50,    51,   102,   104,   109,   160,    52,    53,    66,    54,
      55,   186,   187,    52,    53,   268,    54,    55,    50,    51,
      61,    62,    63,    64,    65,   116,   117,   118,   119,   105,
     107,    52,    53,    66,    54,    55,     1,     2,   108,   106,
     110,   112,     3,     4,     5,   111,     6,     7,     8,     9,
      10,   113,   120,   121,    11,    12,    13,   232,   235,   275,
     123,   131,    14,    15,   132,   133,   135,   138,   192,   193,
     139,   142,   141,   143,   247,   194,    16,   145,    97,   150,
      17,   156,   157,    18,    19,   195,   196,   197,   198,   199,
     200,   164,   165,   167,    50,    51,    61,    62,    63,    64,
      65,    61,    62,    63,    64,    65,   266,    52,    53,    66,
      54,    55,   269,   174,    66,   176,   177,   178,   179,   147,
     183,   247,   185,   189,     4,   203,   208,   213,   214,   218,
     219,   224,   215,   216,   227,   228,   239,   229,   240,   242,
     246,   244,   245,   250,   251,   252,   254,   259,   260,   261,
     276,   265,   270,   271,    79,   243,   255,   267,   212,   238,
     226,   182,   206,   115,   149,   217,   274
};

static const yytype_int16 yycheck[] =
{
       4,   159,   161,    70,    20,   120,    19,   108,   123,    71,
      20,    20,    20,    32,   203,    58,    59,    60,    61,    62,
      37,     6,    32,     8,     9,    47,   126,    19,    71,    76,
      77,    21,   133,    76,    47,    57,    55,    34,    55,    25,
      26,    27,    28,    29,    57,    55,   204,    55,    36,    58,
      59,    60,    61,    62,    19,   122,   157,   246,    74,    75,
      76,    77,    71,   164,    56,    57,   166,    76,   227,     7,
     185,     9,   230,     6,    19,   233,     9,    69,    70,    49,
      72,    73,    71,    75,    74,    75,    76,    77,    20,    21,
      71,    56,    57,    12,    13,    99,    19,     6,   102,     0,
     201,   202,   203,     3,    69,    70,     9,    72,    73,    71,
      71,    56,    57,    58,    59,    60,    61,    62,    71,   186,
     187,    19,    49,   224,    69,    70,    71,    72,    73,    56,
      71,    21,    36,    56,    57,    58,    59,    60,    61,    62,
      56,    57,    19,    36,    50,   246,    69,    70,    71,    72,
      73,   155,   156,    69,    70,   256,    72,    73,    56,    57,
      58,    59,    60,    61,    62,    92,    93,    94,    95,    71,
      44,    69,    70,    71,    72,    73,     4,     5,    63,    71,
      19,    45,    10,    11,    12,    71,    14,    15,    16,    17,
      18,    45,    71,    71,    22,    23,    24,   201,   202,   266,
      71,    71,    30,    31,    35,    39,    71,    73,    46,    47,
      71,    71,    45,    71,   218,    53,    44,    32,    55,    21,
      48,    21,    19,    51,    52,    63,    64,    65,    66,    67,
      68,    63,    21,    34,    56,    57,    58,    59,    60,    61,
      62,    58,    59,    60,    61,    62,   250,    69,    70,    71,
      72,    73,   256,    21,    71,    71,    19,    71,    38,    37,
      41,   265,    71,    21,    11,    40,     6,    20,    19,    43,
      42,    21,    71,    71,    20,    46,    71,    47,    69,    56,
      45,    71,    20,    43,    20,    20,    20,    20,    20,    20,
      56,    21,    20,    20,    18,   212,   226,   253,   174,   206,
     189,   150,   165,    91,   123,   180,   265
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     4,     5,    10,    11,    12,    14,    15,    16,    17,
      18,    22,    23,    24,    30,    31,    44,    48,    51,    52,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,   100,   105,   106,   109,
     110,   132,   133,   134,     6,     8,     9,     6,     9,    19,
      56,    57,    69,    70,    72,    73,    75,   104,   111,   112,
     130,    58,    59,    60,    61,    62,    71,    76,   113,   114,
     115,    71,     7,     9,    34,    36,    71,    71,    49,    81,
       6,     0,     3,   135,    71,     9,    71,    71,    71,   112,
     112,    21,    74,    75,    76,    77,    32,    55,   116,    21,
     117,    36,    19,   117,    36,    71,    71,    44,    63,    50,
      19,    71,    45,    45,    20,   111,   112,   112,   112,   112,
      71,    71,   115,    71,   120,   121,   122,    20,    71,    76,
     115,    71,    35,    39,   123,    71,   108,   104,    73,    71,
      97,    45,    71,    71,   116,    32,   117,    37,   116,   118,
      21,   123,    20,    32,    20,    21,    21,    19,   102,    19,
     104,   115,   124,   125,    63,    21,   107,    34,    25,    26,
      27,    28,    29,    99,    21,    96,    71,    19,    71,    38,
     118,   119,   122,    41,   127,    71,   115,   115,   104,    21,
     101,   109,    46,    47,    53,    63,    64,    65,    66,    67,
      68,   131,   131,    40,    19,   104,   108,   123,     6,    19,
      47,    57,    97,    20,    19,    71,    71,   119,    43,    42,
     126,    20,   117,   117,    21,   103,   102,    20,    46,    47,
      19,   104,   115,    19,   104,   115,   124,   109,   107,    71,
      69,    98,    56,    96,    71,    20,    45,   115,   128,   129,
      43,    20,    20,   104,    20,   101,   131,   109,   109,    20,
      20,    20,   124,    12,    13,    21,   115,   103,   104,   115,
      20,    20,    47,    57,   129,   117,    56
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    79,    80,    81,    81,    81,    81,    81,    81,    81,
      81,    81,    81,    81,    81,    81,    81,    81,    81,    81,
      81,    81,    81,    81,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    93,    94,    95,
      96,    96,    97,    97,    97,    97,    97,    97,    98,    99,
      99,    99,    99,    99,   100,   101,   101,   102,   103,   103,
     104,   104,   104,   104,   104,   105,   106,   107,   107,   108,
     108,   109,   110,   111,   111,   112,   112,   112,   112,   112,
     112,   112,   113,   113,   114,   114,   114,   114,   114,   115,
     115,   115,   115,   115,   115,   115,   115,   116,   116,   116,
     117,   117,   118,   119,   119,   120,   121,   121,   122,   122,
     123,   123,   124,   124,   124,   125,   125,   125,   125,   125,
     125,   125,   125,   126,   126,   127,   127,   128,   128,   128,
     129,   129,   129,   130,   130,   131,   131,   131,   131,   131,
     131,   131,   131,   131,   131,   132,   133,   134,   135,   135
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
       5,     7,     2,     1,     3,     3,     3,     3,     3,     3,
       2,     1,     2,     2,     1,     1,     1,     1,     1,     2,
       4,     4,     6,     4,     3,     7,     7,     0,     2,     4,
       0,     3,     5,     0,     2,     3,     2,     1,     1,     3,
       0,     2,     0,     1,     3,     3,     3,     3,     3,     5,
       5,     5,     5,     0,     4,     0,     3,     1,     2,     2,
       0,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     1,     2,     7,     2,     4,     0,     1
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
#line 226 "yacc_sql.y"
  {
    std::unique_ptr<ParsedSqlNode> sql_node = std::unique_ptr<ParsedSqlNode>((yyvsp[-1].sql_node));
    sql_result->add_sql_node(std::move(sql_node));
  }
#line 1849 "yacc_sql.cpp"
    break;

  case 25: /* exit_stmt: EXIT  */
#line 258 "yacc_sql.y"
         {
      (void)yynerrs;  // 这么写为了消除yynerrs未使用的告警。如果你有更好的方法欢迎提PR
      (yyval.sql_node) = new ParsedSqlNode(SCF_EXIT);
    }
#line 1858 "yacc_sql.cpp"
    break;

  case 26: /* help_stmt: HELP  */
#line 264 "yacc_sql.y"
         {
      (yyval.sql_node) = new ParsedSqlNode(SCF_HELP);
    }
#line 1866 "yacc_sql.cpp"
    break;

  case 27: /* sync_stmt: SYNC  */
#line 269 "yacc_sql.y"
         {
      (yyval.sql_node) = new ParsedSqlNode(SCF_SYNC);
    }
#line 1874 "yacc_sql.cpp"
    break;

  case 28: /* begin_stmt: TRX_BEGIN  */
#line 275 "yacc_sql.y"
               {
      (yyval.sql_node) = new ParsedSqlNode(SCF_BEGIN);
    }
#line 1882 "yacc_sql.cpp"
    break;

  case 29: /* commit_stmt: TRX_COMMIT  */
#line 281 "yacc_sql.y"
               {
      (yyval.sql_node) = new ParsedSqlNode(SCF_COMMIT);
    }
#line 1890 "yacc_sql.cpp"
    break;

  case 30: /* rollback_stmt: TRX_ROLLBACK  */
#line 287 "yacc_sql.y"
                  {
      (yyval.sql_node) = new ParsedSqlNode(SCF_ROLLBACK);
    }
#line 1898 "yacc_sql.cpp"
    break;

  case 31: /* drop_table_stmt: DROP TABLE ID  */
#line 293 "yacc_sql.y"
                  {
      (yyval.sql_node) = new ParsedSqlNode(SCF_DROP_TABLE);
      (yyval.sql_node)->drop_table.relation_name = (yyvsp[0].string);
      free((yyvsp[0].string));
    }
#line 1908 "yacc_sql.cpp"
    break;

  case 32: /* clear_table_stmt: CLEAR TABLE  */
#line 299 "yacc_sql.y"
               {
      (yyval.sql_node) = new ParsedSqlNode(SCF_CLEAR_TABLE);
    }
#line 1916 "yacc_sql.cpp"
    break;

  case 33: /* show_tables_stmt: SHOW TABLES  */
#line 304 "yacc_sql.y"
                {
      (yyval.sql_node) = new ParsedSqlNode(SCF_SHOW_TABLES);
    }
#line 1924 "yacc_sql.cpp"
    break;

  case 34: /* show_index_stmt: SHOW INDEX FROM ID  */
#line 309 "yacc_sql.y"
                      {
      (yyval.sql_node) = new ParsedSqlNode(SCF_SHOW_INDEX);
      (yyval.sql_node)->show_index.relation_name = (yyvsp[0].string);
      free((yyvsp[0].string));
    }
#line 1934 "yacc_sql.cpp"
    break;

  case 35: /* desc_table_stmt: DESC ID  */
#line 317 "yacc_sql.y"
             {
      (yyval.sql_node) = new ParsedSqlNode(SCF_DESC_TABLE);
      (yyval.sql_node)->desc_table.relation_name = (yyvsp[0].string);
      free((yyvsp[0].string));
    }
#line 1944 "yacc_sql.cpp"
    break;

  case 36: /* create_index_stmt: CREATE INDEX ID ON ID LBRACE ID RBRACE  */
#line 326 "yacc_sql.y"
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
#line 1960 "yacc_sql.cpp"
    break;

  case 37: /* create_index_stmt: CREATE UNIQUE INDEX ID ON ID LBRACE ID RBRACE  */
#line 338 "yacc_sql.y"
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
#line 1976 "yacc_sql.cpp"
    break;

  case 38: /* drop_index_stmt: DROP INDEX ID ON ID  */
#line 353 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_DROP_INDEX);
      (yyval.sql_node)->drop_index.index_name = (yyvsp[-2].string);
      (yyval.sql_node)->drop_index.relation_name = (yyvsp[0].string);
      free((yyvsp[-2].string));
      free((yyvsp[0].string));
    }
#line 1988 "yacc_sql.cpp"
    break;

  case 39: /* create_table_stmt: CREATE TABLE ID LBRACE attr_def attr_def_list RBRACE  */
#line 363 "yacc_sql.y"
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
#line 2008 "yacc_sql.cpp"
    break;

  case 40: /* attr_def_list: %empty  */
#line 381 "yacc_sql.y"
    {
      (yyval.attr_infos) = nullptr;
    }
#line 2016 "yacc_sql.cpp"
    break;

  case 41: /* attr_def_list: COMMA attr_def attr_def_list  */
#line 385 "yacc_sql.y"
    {
      if ((yyvsp[0].attr_infos) != nullptr) {
        (yyval.attr_infos) = (yyvsp[0].attr_infos);
      } else {
        (yyval.attr_infos) = new std::vector<AttrInfoSqlNode>;
      }
      (yyval.attr_infos)->emplace_back(*(yyvsp[-1].attr_info));
      delete (yyvsp[-1].attr_info);
    }
#line 2030 "yacc_sql.cpp"
    break;

  case 42: /* attr_def: ID type LBRACE number RBRACE  */
#line 398 "yacc_sql.y"
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
#line 2048 "yacc_sql.cpp"
    break;

  case 43: /* attr_def: ID type  */
#line 412 "yacc_sql.y"
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
#line 2066 "yacc_sql.cpp"
    break;

  case 44: /* attr_def: ID type LBRACE number RBRACE NULLABLE  */
#line 426 "yacc_sql.y"
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
#line 2084 "yacc_sql.cpp"
    break;

  case 45: /* attr_def: ID type NULLABLE  */
#line 440 "yacc_sql.y"
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
#line 2102 "yacc_sql.cpp"
    break;

  case 46: /* attr_def: ID type LBRACE number RBRACE NOT NULL_T  */
#line 454 "yacc_sql.y"
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
#line 2120 "yacc_sql.cpp"
    break;

  case 47: /* attr_def: ID type NOT NULL_T  */
#line 468 "yacc_sql.y"
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
#line 2138 "yacc_sql.cpp"
    break;

  case 48: /* number: NUMBER  */
#line 483 "yacc_sql.y"
           {(yyval.number) = (yyvsp[0].number);}
#line 2144 "yacc_sql.cpp"
    break;

  case 49: /* type: INT_T  */
#line 486 "yacc_sql.y"
               { (yyval.number)=INTS; }
#line 2150 "yacc_sql.cpp"
    break;

  case 50: /* type: STRING_T  */
#line 487 "yacc_sql.y"
               { (yyval.number)=CHARS; }
#line 2156 "yacc_sql.cpp"
    break;

  case 51: /* type: FLOAT_T  */
#line 488 "yacc_sql.y"
               { (yyval.number)=FLOATS; }
#line 2162 "yacc_sql.cpp"
    break;

  case 52: /* type: DATE_T  */
#line 489 "yacc_sql.y"
                { (yyval.number)=DATES;}
#line 2168 "yacc_sql.cpp"
    break;

  case 53: /* type: TEXT_T  */
#line 490 "yacc_sql.y"
                { (yyval.number)=TEXTS;}
#line 2174 "yacc_sql.cpp"
    break;

  case 54: /* insert_stmt: INSERT INTO ID VALUES insert_value insert_value_list  */
#line 494 "yacc_sql.y"
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
#line 2193 "yacc_sql.cpp"
    break;

  case 55: /* insert_value_list: %empty  */
#line 511 "yacc_sql.y"
    {
      (yyval.insert_value_list) = nullptr;
    }
#line 2201 "yacc_sql.cpp"
    break;

  case 56: /* insert_value_list: COMMA insert_value insert_value_list  */
#line 515 "yacc_sql.y"
    {
      if ((yyvsp[0].insert_value_list) != nullptr) {
        (yyval.insert_value_list) = (yyvsp[0].insert_value_list);
      } else {
        (yyval.insert_value_list) = new std::vector<InsertValueSqlNode>;
      }
      (yyval.insert_value_list)->emplace_back(*(yyvsp[-1].insert_value));
      delete (yyvsp[-1].insert_value);
    }
#line 2215 "yacc_sql.cpp"
    break;

  case 57: /* insert_value: LBRACE value value_list RBRACE  */
#line 527 "yacc_sql.y"
    {
        (yyval.insert_value) = new InsertValueSqlNode;
        if((yyvsp[-1].value_list) != nullptr){
          (yyval.insert_value)->values.swap(*(yyvsp[-1].value_list));
        }
        (yyval.insert_value)->values.emplace_back(*(yyvsp[-2].value));
        std::reverse((yyval.insert_value)->values.begin(),(yyval.insert_value)->values.end());
        delete (yyvsp[-2].value);
    }
#line 2229 "yacc_sql.cpp"
    break;

  case 58: /* value_list: %empty  */
#line 541 "yacc_sql.y"
    {
      (yyval.value_list) = nullptr;
    }
#line 2237 "yacc_sql.cpp"
    break;

  case 59: /* value_list: COMMA value value_list  */
#line 544 "yacc_sql.y"
                              { 
      if ((yyvsp[0].value_list) != nullptr) {
        (yyval.value_list) = (yyvsp[0].value_list);
      } else {
        (yyval.value_list) = new std::vector<Value>;
      }
      (yyval.value_list)->emplace_back(*(yyvsp[-1].value));
      delete (yyvsp[-1].value);
    }
#line 2251 "yacc_sql.cpp"
    break;

  case 60: /* value: NUMBER  */
#line 555 "yacc_sql.y"
           {
      (yyval.value) = new Value((int)(yyvsp[0].number));
      (yyloc) = (yylsp[0]);
    }
#line 2260 "yacc_sql.cpp"
    break;

  case 61: /* value: FLOAT  */
#line 559 "yacc_sql.y"
           {
      (yyval.value) = new Value((float)(yyvsp[0].floats));
      (yyloc) = (yylsp[0]);
    }
#line 2269 "yacc_sql.cpp"
    break;

  case 62: /* value: DATE_STR  */
#line 563 "yacc_sql.y"
               {
      char *tmp = common::substr((yyvsp[0].string),1,strlen((yyvsp[0].string))-2);
      int y, m, d;
      sscanf(tmp, "%d-%d-%d", &y, &m, &d);


      (yyval.value) = new Value(y,m,d);

      
    }
#line 2284 "yacc_sql.cpp"
    break;

  case 63: /* value: SSS  */
#line 573 "yacc_sql.y"
         {
      char *tmp = common::substr((yyvsp[0].string),1,strlen((yyvsp[0].string))-2);
      (yyval.value) = new Value(tmp);
      free(tmp);
    }
#line 2294 "yacc_sql.cpp"
    break;

  case 64: /* value: null_or_nullable  */
#line 578 "yacc_sql.y"
                     {
      (yyval.value) = new Value(0);
      
      (yyval.value)->set_null(nullptr,4);
      
      
    }
#line 2306 "yacc_sql.cpp"
    break;

  case 65: /* delete_stmt: DELETE FROM ID where  */
#line 590 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_DELETE);
      (yyval.sql_node)->deletion.relation_name = (yyvsp[-1].string);
      if ((yyvsp[0].condition_list) != nullptr) {
        (yyval.sql_node)->deletion.conditions.swap(*(yyvsp[0].condition_list));
        delete (yyvsp[0].condition_list);
      }
      free((yyvsp[-1].string));
    }
#line 2320 "yacc_sql.cpp"
    break;

  case 66: /* update_stmt: UPDATE ID SET set_value set_value_list where  */
#line 602 "yacc_sql.y"
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
#line 2341 "yacc_sql.cpp"
    break;

  case 67: /* set_value_list: %empty  */
#line 621 "yacc_sql.y"
    {
      (yyval.update_value_list) = nullptr;
    }
#line 2349 "yacc_sql.cpp"
    break;

  case 68: /* set_value_list: COMMA set_value set_value_list  */
#line 624 "yacc_sql.y"
                                   {
      if ((yyvsp[0].update_value_list) != nullptr) {
        (yyval.update_value_list) = (yyvsp[0].update_value_list);
      } else {
        (yyval.update_value_list) = new std::vector<UpdateValueSqlNode>;
      }
      (yyval.update_value_list)->emplace_back(*(yyvsp[-1].update_value));
      delete (yyvsp[-1].update_value);

    }
#line 2364 "yacc_sql.cpp"
    break;

  case 69: /* set_value: ID EQ value  */
#line 637 "yacc_sql.y"
    {
      (yyval.update_value) = new UpdateValueSqlNode;
      (yyval.update_value)->name = (yyvsp[-2].string);
      (yyval.update_value)->value = *(yyvsp[0].value);

      delete (yyvsp[-2].string);
      delete (yyvsp[0].value);
    }
#line 2377 "yacc_sql.cpp"
    break;

  case 70: /* set_value: ID EQ LBRACE select_stmt RBRACE  */
#line 646 "yacc_sql.y"
    {
      (yyval.update_value) = new UpdateValueSqlNode;
      (yyval.update_value)->name = (yyvsp[-4].string);
      (yyval.update_value)->select_sql_node =  (yyvsp[-1].sql_node)->selection;
      (yyval.update_value)->is_right_selects = true;

      delete (yyvsp[-4].string);
      delete (yyvsp[-1].sql_node);
    }
#line 2391 "yacc_sql.cpp"
    break;

  case 71: /* select_stmt: SELECT select_attr FROM rel_list where order_by group_by  */
#line 658 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_SELECT);
      if ((yyvsp[-5].rel_attr_list) != nullptr) {
        (yyval.sql_node)->selection.attributes.swap(*(yyvsp[-5].rel_attr_list));
        delete (yyvsp[-5].rel_attr_list);
      }
     
      (yyval.sql_node)->selection.relations.swap(*(yyvsp[-3].relation_list));
      delete (yyvsp[-3].relation_list);
      
      std::reverse((yyval.sql_node)->selection.relations.begin(), (yyval.sql_node)->selection.relations.end());

      if ((yyvsp[-2].condition_list) != nullptr) {
        (yyval.sql_node)->selection.conditions.swap(*(yyvsp[-2].condition_list));
        delete (yyvsp[-2].condition_list);
      }
      if ((yyvsp[-1].order_list) != nullptr) {
        (yyval.sql_node)->selection.order_by_sql_nodes.swap(*(yyvsp[-1].order_list));
        delete (yyvsp[-1].order_list);
      }

      if((yyvsp[0].rel_attr_list) != nullptr){
        (yyval.sql_node)->selection.group_by_attributes.swap (*(yyvsp[0].rel_attr_list));
        delete (yyvsp[0].rel_attr_list);
      }

    }
#line 2423 "yacc_sql.cpp"
    break;

  case 72: /* calc_stmt: CALC expression_list  */
#line 688 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_CALC);
      std::reverse((yyvsp[0].expression_list)->begin(), (yyvsp[0].expression_list)->end());
      (yyval.sql_node)->calc.expressions.swap(*(yyvsp[0].expression_list));
      delete (yyvsp[0].expression_list);
    }
#line 2434 "yacc_sql.cpp"
    break;

  case 73: /* expression_list: expression  */
#line 698 "yacc_sql.y"
    {
      (yyval.expression_list) = new std::vector<Expression*>;
      (yyval.expression_list)->emplace_back((yyvsp[0].expression));
    }
#line 2443 "yacc_sql.cpp"
    break;

  case 74: /* expression_list: expression COMMA expression_list  */
#line 703 "yacc_sql.y"
    {
      if ((yyvsp[0].expression_list) != nullptr) {
        (yyval.expression_list) = (yyvsp[0].expression_list);
      } else {
        (yyval.expression_list) = new std::vector<Expression *>;
      }
      (yyval.expression_list)->emplace_back((yyvsp[-2].expression));
    }
#line 2456 "yacc_sql.cpp"
    break;

  case 75: /* expression: expression '+' expression  */
#line 713 "yacc_sql.y"
                              {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::ADD, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2464 "yacc_sql.cpp"
    break;

  case 76: /* expression: expression '-' expression  */
#line 716 "yacc_sql.y"
                                {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::SUB, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2472 "yacc_sql.cpp"
    break;

  case 77: /* expression: expression '*' expression  */
#line 719 "yacc_sql.y"
                                {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::MUL, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2480 "yacc_sql.cpp"
    break;

  case 78: /* expression: expression '/' expression  */
#line 722 "yacc_sql.y"
                                {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::DIV, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2488 "yacc_sql.cpp"
    break;

  case 79: /* expression: LBRACE expression RBRACE  */
#line 725 "yacc_sql.y"
                               {
      (yyval.expression) = (yyvsp[-1].expression);
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));
    }
#line 2497 "yacc_sql.cpp"
    break;

  case 80: /* expression: '-' expression  */
#line 729 "yacc_sql.y"
                                  {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::NEGATIVE, (yyvsp[0].expression), nullptr, sql_string, &(yyloc));
    }
#line 2505 "yacc_sql.cpp"
    break;

  case 81: /* expression: value  */
#line 732 "yacc_sql.y"
            {
      (yyval.expression) = new ValueExpr(*(yyvsp[0].value));
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));
      delete (yyvsp[0].value);
    }
#line 2515 "yacc_sql.cpp"
    break;

  case 82: /* select_attr: '*' attr_list  */
#line 740 "yacc_sql.y"
                  {
      if((yyvsp[0].rel_attr_list) != nullptr){
        (yyval.rel_attr_list) = (yyvsp[0].rel_attr_list);
      } else {
        (yyval.rel_attr_list) = new std::vector<RelAttrSqlNode>;
      }
      RelAttrSqlNode attr;
      attr.relation_name  = "";
      attr.attribute_name = "*";
      (yyval.rel_attr_list)->emplace_back(attr);
    }
#line 2531 "yacc_sql.cpp"
    break;

  case 83: /* select_attr: rel_attr attr_list  */
#line 751 "yacc_sql.y"
                         {
      if ((yyvsp[0].rel_attr_list) != nullptr) {
        (yyval.rel_attr_list) = (yyvsp[0].rel_attr_list);
      } else {
        (yyval.rel_attr_list) = new std::vector<RelAttrSqlNode>;
      }
      (yyval.rel_attr_list)->emplace_back(*(yyvsp[-1].rel_attr));
      delete (yyvsp[-1].rel_attr);
    }
#line 2545 "yacc_sql.cpp"
    break;

  case 84: /* aggregation_func: MAX_FUNC  */
#line 762 "yacc_sql.y"
            {
      (yyval.aggr_func) = MAX;
    }
#line 2553 "yacc_sql.cpp"
    break;

  case 85: /* aggregation_func: MIN_FUNC  */
#line 765 "yacc_sql.y"
              {
      (yyval.aggr_func) = MIN;
    }
#line 2561 "yacc_sql.cpp"
    break;

  case 86: /* aggregation_func: CNT_FUNC  */
#line 768 "yacc_sql.y"
              {
      (yyval.aggr_func) = CNT;
    }
#line 2569 "yacc_sql.cpp"
    break;

  case 87: /* aggregation_func: AVG_FUNC  */
#line 771 "yacc_sql.y"
              {
      (yyval.aggr_func) = AVG;
    }
#line 2577 "yacc_sql.cpp"
    break;

  case 88: /* aggregation_func: SUM_FUNC  */
#line 774 "yacc_sql.y"
              {
      (yyval.aggr_func) = SUM;
    }
#line 2585 "yacc_sql.cpp"
    break;

  case 89: /* rel_attr: ID as_alias  */
#line 780 "yacc_sql.y"
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
#line 2602 "yacc_sql.cpp"
    break;

  case 90: /* rel_attr: ID DOT ID as_alias  */
#line 792 "yacc_sql.y"
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
#line 2621 "yacc_sql.cpp"
    break;

  case 91: /* rel_attr: aggregation_func LBRACE ID RBRACE  */
#line 806 "yacc_sql.y"
                                       {
      (yyval.rel_attr) = new RelAttrSqlNode;
      (yyval.rel_attr)->attribute_name = (yyvsp[-1].string);
      free((yyvsp[-1].string));
      (yyval.rel_attr)->is_aggregation_func = true;
      (yyval.rel_attr)->aggr_func_type = (yyvsp[-3].aggr_func);

    }
#line 2634 "yacc_sql.cpp"
    break;

  case 92: /* rel_attr: aggregation_func LBRACE ID DOT ID RBRACE  */
#line 814 "yacc_sql.y"
                                              {
      (yyval.rel_attr) = new RelAttrSqlNode;
      (yyval.rel_attr)->relation_name  = (yyvsp[-3].string);
      (yyval.rel_attr)->attribute_name = (yyvsp[-1].string);
      free((yyvsp[-3].string));
      free((yyvsp[-1].string));
      (yyval.rel_attr)->is_aggregation_func = true;
      (yyval.rel_attr)->aggr_func_type = (yyvsp[-5].aggr_func);

    }
#line 2649 "yacc_sql.cpp"
    break;

  case 93: /* rel_attr: aggregation_func LBRACE '*' RBRACE  */
#line 824 "yacc_sql.y"
                                        {
      (yyval.rel_attr) = new RelAttrSqlNode;
      (yyval.rel_attr)->relation_name = "";
      (yyval.rel_attr)->attribute_name = "*";
      (yyval.rel_attr)->is_aggregation_func = true;
      (yyval.rel_attr)->aggr_func_type = (yyvsp[-3].aggr_func);

    }
#line 2662 "yacc_sql.cpp"
    break;

  case 94: /* rel_attr: aggregation_func LBRACE RBRACE  */
#line 832 "yacc_sql.y"
                                    {
      (yyval.rel_attr) = new RelAttrSqlNode;
      (yyval.rel_attr)->is_syntax_error = true;
      (yyval.rel_attr)->aggr_func_type = (yyvsp[-2].aggr_func);

    }
#line 2673 "yacc_sql.cpp"
    break;

  case 95: /* rel_attr: aggregation_func LBRACE rel_attr COMMA rel_attr attr_list RBRACE  */
#line 838 "yacc_sql.y"
                                                                      {
      (yyval.rel_attr) = new RelAttrSqlNode;
      (yyval.rel_attr)->is_syntax_error = true;
      delete (yyvsp[-4].rel_attr);
      delete (yyvsp[-2].rel_attr);
      delete (yyvsp[-1].rel_attr_list);

    }
#line 2686 "yacc_sql.cpp"
    break;

  case 96: /* rel_attr: aggregation_func LBRACE '*' COMMA rel_attr attr_list RBRACE  */
#line 846 "yacc_sql.y"
                                                                 {
      (yyval.rel_attr) = new RelAttrSqlNode;
      (yyval.rel_attr)->is_syntax_error = true;
      delete (yyvsp[-2].rel_attr);
      delete (yyvsp[-1].rel_attr_list);

    }
#line 2698 "yacc_sql.cpp"
    break;

  case 97: /* as_alias: %empty  */
#line 856 "yacc_sql.y"
    {
      (yyval.string) = nullptr;
    }
#line 2706 "yacc_sql.cpp"
    break;

  case 98: /* as_alias: AS ID  */
#line 859 "yacc_sql.y"
           {
      (yyval.string) = (char*)malloc(strlen((yyvsp[0].string))+1);
      strcpy((yyval.string),(yyvsp[0].string));
      free((yyvsp[0].string));
    }
#line 2716 "yacc_sql.cpp"
    break;

  case 99: /* as_alias: AS ID DOT ID  */
#line 864 "yacc_sql.y"
                  {
      (yyval.string) = (char*)malloc(strlen((yyvsp[-2].string))+strlen((yyvsp[0].string))+2);
      strcpy((yyval.string),(yyvsp[-2].string));
      strcpy((yyval.string)+strlen((yyvsp[-2].string)),".");
      strcpy((yyval.string)+strlen((yyvsp[-2].string))+1,(yyvsp[0].string));
      free((yyvsp[-2].string));
      free((yyvsp[0].string));
    }
#line 2729 "yacc_sql.cpp"
    break;

  case 100: /* attr_list: %empty  */
#line 875 "yacc_sql.y"
    {
      (yyval.rel_attr_list) = nullptr;
    }
#line 2737 "yacc_sql.cpp"
    break;

  case 101: /* attr_list: COMMA rel_attr attr_list  */
#line 878 "yacc_sql.y"
                               {
      if ((yyvsp[0].rel_attr_list) != nullptr) {
        (yyval.rel_attr_list) = (yyvsp[0].rel_attr_list);
      } else {
        (yyval.rel_attr_list) = new std::vector<RelAttrSqlNode>;
      }

      (yyval.rel_attr_list)->emplace_back(*(yyvsp[-1].rel_attr));
      delete (yyvsp[-1].rel_attr);
    }
#line 2752 "yacc_sql.cpp"
    break;

  case 102: /* inner_join: INNER JOIN ID ON condition_list  */
#line 892 "yacc_sql.y"
    {
        (yyval.join_rel) = new JoinedRelationSqlNode;
        (yyval.join_rel)->relations.push_back((yyvsp[-2].string));
        for(auto iter:*(yyvsp[0].condition_list)){
          (yyval.join_rel)->join_on_conditions.emplace_back(iter);
        }
        // free($3);
    }
#line 2765 "yacc_sql.cpp"
    break;

  case 103: /* inner_join_list: %empty  */
#line 902 "yacc_sql.y"
    {
      (yyval.join_rel) = nullptr;
    }
#line 2773 "yacc_sql.cpp"
    break;

  case 104: /* inner_join_list: inner_join inner_join_list  */
#line 906 "yacc_sql.y"
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
#line 2792 "yacc_sql.cpp"
    break;

  case 105: /* join_relation: ID inner_join inner_join_list  */
#line 923 "yacc_sql.y"
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
#line 2820 "yacc_sql.cpp"
    break;

  case 106: /* rel_element: ID as_alias  */
#line 950 "yacc_sql.y"
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
#line 2839 "yacc_sql.cpp"
    break;

  case 107: /* rel_element: join_relation  */
#line 965 "yacc_sql.y"
    {
      (yyval.relation) = new RelationSqlNode;
      (yyval.relation)->inner_join_sql_node = *(yyvsp[0].join_rel);
      (yyval.relation) -> has_inner_join = true;
      // delete $1;

    }
#line 2851 "yacc_sql.cpp"
    break;

  case 108: /* rel_list: rel_element  */
#line 976 "yacc_sql.y"
    { 
      (yyval.relation_list) = new std::vector<RelationSqlNode>;
      (yyval.relation_list)->emplace_back(*(yyvsp[0].relation));
      // delete $1;
    }
#line 2861 "yacc_sql.cpp"
    break;

  case 109: /* rel_list: rel_element COMMA rel_list  */
#line 981 "yacc_sql.y"
                                 {
      (yyval.relation_list) = (yyvsp[0].relation_list);
      (yyval.relation_list)->emplace_back(*(yyvsp[-2].relation));
      // delete $1;
    }
#line 2871 "yacc_sql.cpp"
    break;

  case 110: /* where: %empty  */
#line 989 "yacc_sql.y"
    {
      (yyval.condition_list) = nullptr;
    }
#line 2879 "yacc_sql.cpp"
    break;

  case 111: /* where: WHERE condition_list  */
#line 992 "yacc_sql.y"
                           {
      (yyval.condition_list) = (yyvsp[0].condition_list);  
    }
#line 2887 "yacc_sql.cpp"
    break;

  case 112: /* condition_list: %empty  */
#line 998 "yacc_sql.y"
    {
      (yyval.condition_list) = nullptr;
    }
#line 2895 "yacc_sql.cpp"
    break;

  case 113: /* condition_list: condition  */
#line 1001 "yacc_sql.y"
                {
      (yyval.condition_list) = new std::vector<ConditionSqlNode>;
      (yyval.condition_list)->emplace_back(*(yyvsp[0].condition));
      delete (yyvsp[0].condition);
    }
#line 2905 "yacc_sql.cpp"
    break;

  case 114: /* condition_list: condition AND condition_list  */
#line 1006 "yacc_sql.y"
                                   {
      (yyval.condition_list) = (yyvsp[0].condition_list);
      (yyval.condition_list)->emplace_back(*(yyvsp[-2].condition));
      delete (yyvsp[-2].condition);
    }
#line 2915 "yacc_sql.cpp"
    break;

  case 115: /* condition: rel_attr comp_op value  */
#line 1014 "yacc_sql.y"
    {
      (yyval.condition) = new ConditionSqlNode;
      (yyval.condition)->left_is_attr = 1;
      (yyval.condition)->left_attr = *(yyvsp[-2].rel_attr);
      (yyval.condition)->right_is_attr = 0;
      (yyval.condition)->right_value = *(yyvsp[0].value);
      (yyval.condition)->comp = (yyvsp[-1].comp);

      delete (yyvsp[-2].rel_attr);
      delete (yyvsp[0].value);
    }
#line 2931 "yacc_sql.cpp"
    break;

  case 116: /* condition: value comp_op value  */
#line 1026 "yacc_sql.y"
    {
      (yyval.condition) = new ConditionSqlNode;
      (yyval.condition)->left_is_attr = 0;
      (yyval.condition)->left_value = *(yyvsp[-2].value);
      (yyval.condition)->right_is_attr = 0;
      (yyval.condition)->right_value = *(yyvsp[0].value);
      (yyval.condition)->comp = (yyvsp[-1].comp);

      delete (yyvsp[-2].value);
      delete (yyvsp[0].value);
    }
#line 2947 "yacc_sql.cpp"
    break;

  case 117: /* condition: rel_attr comp_op rel_attr  */
#line 1038 "yacc_sql.y"
    {
      (yyval.condition) = new ConditionSqlNode;
      (yyval.condition)->left_is_attr = 1;
      (yyval.condition)->left_attr = *(yyvsp[-2].rel_attr);
      (yyval.condition)->right_is_attr = 1;
      (yyval.condition)->right_attr = *(yyvsp[0].rel_attr);
      (yyval.condition)->comp = (yyvsp[-1].comp);

      delete (yyvsp[-2].rel_attr);
      delete (yyvsp[0].rel_attr);
    }
#line 2963 "yacc_sql.cpp"
    break;

  case 118: /* condition: value comp_op rel_attr  */
#line 1050 "yacc_sql.y"
    {
      (yyval.condition) = new ConditionSqlNode;
      (yyval.condition)->left_is_attr = 0;
      (yyval.condition)->left_value = *(yyvsp[-2].value);
      (yyval.condition)->right_is_attr = 1;
      (yyval.condition)->right_attr = *(yyvsp[0].rel_attr);
      (yyval.condition)->comp = (yyvsp[-1].comp);

      delete (yyvsp[-2].value);
      delete (yyvsp[0].rel_attr);
    }
#line 2979 "yacc_sql.cpp"
    break;

  case 119: /* condition: value comp_op LBRACE select_stmt RBRACE  */
#line 1062 "yacc_sql.y"
    {
      (yyval.condition) = new ConditionSqlNode;
      (yyval.condition)->left_is_attr = 0;
      (yyval.condition)->left_value = *(yyvsp[-4].value);
      (yyval.condition)->right_is_attr =2;
      // $$->right_selects = static_cast<SelectSqlNode*>($4);
      (yyval.condition)->comp = (yyvsp[-3].comp);

      delete (yyvsp[-4].value);
      // delete $4;
    }
#line 2995 "yacc_sql.cpp"
    break;

  case 120: /* condition: rel_attr comp_op LBRACE select_stmt RBRACE  */
#line 1074 "yacc_sql.y"
    {
      (yyval.condition) = new ConditionSqlNode;
      (yyval.condition)->left_is_attr = 1;
      (yyval.condition)->left_attr = *(yyvsp[-4].rel_attr);
      (yyval.condition)->right_is_attr = 2;
      // $$->right_selects = static_cast<SelectSqlNode*>($4);
      (yyval.condition)->comp = (yyvsp[-3].comp);

      delete (yyvsp[-4].rel_attr);
      // delete $4;
    }
#line 3011 "yacc_sql.cpp"
    break;

  case 121: /* condition: LBRACE select_stmt RBRACE comp_op value  */
#line 1086 "yacc_sql.y"
    {
      (yyval.condition) = new ConditionSqlNode;
      (yyval.condition)->left_is_attr = 2;
      // $$->left_selects = static_cast<SelectSqlNode*>($2);
      (yyval.condition)->right_is_attr =0;
      (yyval.condition)->right_value = *(yyvsp[0].value);
      (yyval.condition)->comp = (yyvsp[-1].comp);

      // delete $2;
      delete (yyvsp[0].value);
    }
#line 3027 "yacc_sql.cpp"
    break;

  case 122: /* condition: LBRACE select_stmt RBRACE comp_op rel_attr  */
#line 1098 "yacc_sql.y"
    {
      (yyval.condition) = new ConditionSqlNode;
      (yyval.condition)->left_is_attr = 2;
      // $$->left_selects = static_cast<SelectSqlNode*>($2);
      (yyval.condition)->right_is_attr = 1;
      (yyval.condition)->right_attr = *(yyvsp[0].rel_attr);
      (yyval.condition)->comp = (yyvsp[-1].comp);

      // delete $2;
      delete (yyvsp[0].rel_attr);
    }
#line 3043 "yacc_sql.cpp"
    break;

  case 123: /* group_by: %empty  */
#line 1112 "yacc_sql.y"
    {
      (yyval.rel_attr_list) = nullptr;
    }
#line 3051 "yacc_sql.cpp"
    break;

  case 124: /* group_by: GROUP BY rel_attr attr_list  */
#line 1115 "yacc_sql.y"
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
#line 3066 "yacc_sql.cpp"
    break;

  case 125: /* order_by: %empty  */
#line 1128 "yacc_sql.y"
    {
      (yyval.order_list) = nullptr;
    }
#line 3074 "yacc_sql.cpp"
    break;

  case 126: /* order_by: ORDER BY order_list  */
#line 1131 "yacc_sql.y"
                          {
      (yyval.order_list) = (yyvsp[0].order_list);
    }
#line 3082 "yacc_sql.cpp"
    break;

  case 127: /* order: rel_attr  */
#line 1136 "yacc_sql.y"
             {
      (yyval.order) = new OrderBySqlNode;
      (yyval.order)->rel_attr = *(yyvsp[0].rel_attr);
      (yyval.order)->direction = OrderByDirection::ASC_ORDER;
    }
#line 3092 "yacc_sql.cpp"
    break;

  case 128: /* order: rel_attr DESC  */
#line 1141 "yacc_sql.y"
                   {
      (yyval.order) = new OrderBySqlNode;
      (yyval.order)->rel_attr = *(yyvsp[-1].rel_attr);
      (yyval.order)->direction = OrderByDirection::DESC_ORDER;
    }
#line 3102 "yacc_sql.cpp"
    break;

  case 129: /* order: rel_attr ASC  */
#line 1146 "yacc_sql.y"
                  {
      (yyval.order) = new OrderBySqlNode;
      (yyval.order)->rel_attr = *(yyvsp[-1].rel_attr);
      (yyval.order)->direction = OrderByDirection::ASC_ORDER;
    }
#line 3112 "yacc_sql.cpp"
    break;

  case 130: /* order_list: %empty  */
#line 1154 "yacc_sql.y"
    {
      (yyval.order_list) = nullptr;
    }
#line 3120 "yacc_sql.cpp"
    break;

  case 131: /* order_list: order  */
#line 1157 "yacc_sql.y"
           {
        (yyval.order_list) = new std::vector<OrderBySqlNode>;
        (yyval.order_list)->emplace_back(*(yyvsp[0].order));
        delete (yyvsp[0].order);
    }
#line 3130 "yacc_sql.cpp"
    break;

  case 132: /* order_list: order COMMA order_list  */
#line 1162 "yacc_sql.y"
                            {
      (yyval.order_list) = (yyvsp[0].order_list);
      (yyval.order_list)->emplace_back(*(yyvsp[-2].order));
      delete (yyvsp[-2].order);
    }
#line 3140 "yacc_sql.cpp"
    break;

  case 133: /* null_or_nullable: NULL_T  */
#line 1170 "yacc_sql.y"
    {
      (yyval.number) = 1;
    }
#line 3148 "yacc_sql.cpp"
    break;

  case 134: /* null_or_nullable: NULLABLE  */
#line 1174 "yacc_sql.y"
    {
      (yyval.number) = 1;
    }
#line 3156 "yacc_sql.cpp"
    break;

  case 135: /* comp_op: EQ  */
#line 1180 "yacc_sql.y"
         { (yyval.comp) = EQUAL_TO; }
#line 3162 "yacc_sql.cpp"
    break;

  case 136: /* comp_op: LT  */
#line 1181 "yacc_sql.y"
         { (yyval.comp) = LESS_THAN; }
#line 3168 "yacc_sql.cpp"
    break;

  case 137: /* comp_op: GT  */
#line 1182 "yacc_sql.y"
         { (yyval.comp) = GREAT_THAN; }
#line 3174 "yacc_sql.cpp"
    break;

  case 138: /* comp_op: LE  */
#line 1183 "yacc_sql.y"
         { (yyval.comp) = LESS_EQUAL; }
#line 3180 "yacc_sql.cpp"
    break;

  case 139: /* comp_op: GE  */
#line 1184 "yacc_sql.y"
         { (yyval.comp) = GREAT_EQUAL; }
#line 3186 "yacc_sql.cpp"
    break;

  case 140: /* comp_op: NE  */
#line 1185 "yacc_sql.y"
         { (yyval.comp) = NOT_EQUAL; }
#line 3192 "yacc_sql.cpp"
    break;

  case 141: /* comp_op: IS  */
#line 1186 "yacc_sql.y"
         { (yyval.comp) = IS_EQUAL;}
#line 3198 "yacc_sql.cpp"
    break;

  case 142: /* comp_op: IS NOT  */
#line 1187 "yacc_sql.y"
            {(yyval.comp) = IS_NOT_EQUAL;}
#line 3204 "yacc_sql.cpp"
    break;

  case 143: /* comp_op: LIKE_MARK  */
#line 1188 "yacc_sql.y"
                {(yyval.comp) = LIKE;}
#line 3210 "yacc_sql.cpp"
    break;

  case 144: /* comp_op: NOT LIKE_MARK  */
#line 1189 "yacc_sql.y"
                    {(yyval.comp) = NOT_LIKE;}
#line 3216 "yacc_sql.cpp"
    break;

  case 145: /* load_data_stmt: LOAD DATA INFILE SSS INTO TABLE ID  */
#line 1194 "yacc_sql.y"
    {
      char *tmp_file_name = common::substr((yyvsp[-3].string), 1, strlen((yyvsp[-3].string)) - 2);
      
      (yyval.sql_node) = new ParsedSqlNode(SCF_LOAD_DATA);
      (yyval.sql_node)->load_data.relation_name = (yyvsp[0].string);
      (yyval.sql_node)->load_data.file_name = tmp_file_name;
      free((yyvsp[0].string));
      free(tmp_file_name);
    }
#line 3230 "yacc_sql.cpp"
    break;

  case 146: /* explain_stmt: EXPLAIN command_wrapper  */
#line 1207 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_EXPLAIN);
      (yyval.sql_node)->explain.sql_node = std::unique_ptr<ParsedSqlNode>((yyvsp[0].sql_node));
    }
#line 3239 "yacc_sql.cpp"
    break;

  case 147: /* set_variable_stmt: SET ID EQ value  */
#line 1215 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_SET_VARIABLE);
      (yyval.sql_node)->set_variable.name  = (yyvsp[-2].string);
      (yyval.sql_node)->set_variable.value = *(yyvsp[0].value);
      free((yyvsp[-2].string));
      delete (yyvsp[0].value);
    }
#line 3251 "yacc_sql.cpp"
    break;


#line 3255 "yacc_sql.cpp"

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

#line 1227 "yacc_sql.y"

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
