/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "parser.y" /* yacc.c:339  */
 
#include <iostream>
#include <cstdio>
#include<cstring>
#include"semantics.h"
#include<map>
#include<list>
#include<vector>
using namespace std;

// stuff from flex that bison needs to know about:
extern "C" int yylex();
extern "C" int yyparse();
extern "C" FILE *yyin;
extern int line;
int lCount,sCount;
void yyerror(const char *s);

struct cmp_str
{
bool operator()(char const*a, char const *b ){
return strcmp(a,b)<0;
}
};
map<char*,symbolData*,cmp_str> symbolTable;
map <int,char*> types;
///////// Quadruples//////////
FILE *file = fopen("quad.txt", "w");
struct code
{
	char* opr;
	char* opd1;
	char* opd2;
	char* res;
};
list<code> quads;
int tmp_count=0;
int label=0;
bool err=false;
vector<int> labels;
vector<int> loop_labels;

#line 109 "parser.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parser.tab.h".  */
#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    SEMICOLON = 258,
    END = 259,
    PROGRAM = 260,
    CONST = 261,
    S = 262,
    INC = 263,
    DEC = 264,
    INT = 265,
    FLOAT = 266,
    BOOL = 267,
    AND = 268,
    OR = 269,
    NOT = 270,
    WHILE = 271,
    IF = 272,
    THEN = 273,
    ELSE = 274,
    ENDIF = 275,
    SWITCH = 276,
    CASE = 277,
    DEFAULT = 278,
    BREAK = 279,
    CONTINUE = 280,
    PLUS = 281,
    MINUS = 282,
    MUL = 283,
    DIV = 284,
    GTE = 285,
    LTE = 286,
    GT = 287,
    LT = 288,
    EQ = 289,
    NE = 290,
    COLON = 291,
    DO = 292,
    FOR = 293,
    FNUM = 294,
    INUM = 295,
    TRUE = 296,
    FALSE = 297,
    IDENTIFIER = 298
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 45 "parser.y" /* yacc.c:355  */

	int ival;
	float fval;
	char *sval;
	bool bval;
	struct exptype *eval;
	struct num *nval;

#line 202 "parser.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 219 "parser.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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


#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   279

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  49
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  40
/* YYNRULES -- Number of rules.  */
#define YYNRULES  83
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  156

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   298

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      31,    32,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    26,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    39,     2,    41,     2,     2,     2,     2,
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
      25,    27,    28,    29,    30,    33,    34,    35,    36,    37,
      38,    40,    42,    43,    44,    45,    46,    47,    48
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,   126,   126,   129,   130,   131,   134,   135,   136,   137,
     141,   142,   146,   147,   150,   151,   152,   153,   154,   155,
     156,   157,   162,   163,   166,   167,   179,   180,   181,   182,
     183,   184,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   214,   214,   215,   216,   216,   217,   219,
     220,   221,   219,   226,   227,   227,   228,   226,   233,   233,
     235,   235,   237,   238,   238,   239,   241,   241,   241,   249,
     249,   251,   252,   249
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "SEMICOLON", "END", "PROGRAM", "CONST",
  "S", "INC", "DEC", "INT", "FLOAT", "BOOL", "AND", "OR", "NOT", "WHILE",
  "IF", "THEN", "ELSE", "ENDIF", "SWITCH", "CASE", "DEFAULT", "BREAK",
  "CONTINUE", "'='", "PLUS", "MINUS", "MUL", "DIV", "'('", "')'", "GTE",
  "LTE", "GT", "LT", "EQ", "NE", "'{'", "COLON", "'}'", "DO", "FOR",
  "FNUM", "INUM", "TRUE", "FALSE", "IDENTIFIER", "$accept", "program",
  "type", "declaration", "declarations", "statements", "statement", "bval",
  "assignment", "fnum", "inum", "number", "expr", "if_", "$@1", "if_else",
  "$@2", "if_stmt", "while_stsmt", "$@3", "$@4", "$@5", "do_while_stmt",
  "$@6", "$@7", "$@8", "$@9", "pint", "s_stmt", "case", "cases", "default",
  "switch_stmt", "$@10", "$@11", "for_stmt", "$@12", "$@13", "$@14",
  "$@15", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,    61,   281,   282,   283,
     284,    40,    41,   285,   286,   287,   288,   289,   290,   123,
     291,   125,   292,   293,   294,   295,   296,   297,   298
};
# endif

#define YYPACT_NINF -59

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-59)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       9,   -59,    24,   122,   -59,    39,   -59,   -59,   -59,   -59,
     -21,    29,     5,     4,   -59,   -59,    31,   -59,   -59,    28,
      37,   -59,   -59,    21,    41,    36,    67,   -59,   -15,   -59,
     -59,   -59,   -59,   -59,    20,    42,    82,    35,   -59,    38,
      30,   -59,   -59,   -59,   -59,   -26,   -59,   -59,   -59,   -59,
     -59,   -59,   -59,    82,    82,    82,   -59,   -59,   -59,   229,
     -59,   -59,   -59,   -59,   229,   -59,   -59,   -59,   229,   241,
     217,    82,    82,    82,    82,    82,    82,    82,    82,    82,
      82,    54,    77,    47,    49,    95,    62,   124,    57,   -59,
     241,   171,     1,     1,   -59,   -59,   -17,   -17,   -17,   -17,
     -59,   -59,   205,   -59,   -59,   205,    72,    52,   -59,    82,
     -59,    64,   -59,   -59,    80,   229,   -59,   172,   -59,    73,
      53,   -59,    68,    33,   -59,    82,   134,   -59,   -19,    74,
     -59,   -59,    82,   189,   -59,    70,   -59,    78,   -59,   229,
     -22,   -59,   -59,   172,    85,   -59,   -59,   -59,   172,   -59,
      99,    96,   -59,   -59,   144,   -59
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    10,     0,     0,     1,     0,    12,     3,     4,     5,
       0,     0,     0,     0,     9,    11,     0,     2,    59,     0,
       0,    20,    21,     0,     0,     0,     0,    14,     0,    15,
      16,    17,    19,    18,     0,     0,     0,     0,    63,     0,
       0,    13,    56,    55,    58,     0,    26,    28,    22,    23,
       8,     7,     6,     0,     0,     0,    34,    32,    33,    53,
      76,    12,    79,    25,    24,    12,    27,    29,    60,    51,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    52,
      49,    50,    35,    36,    37,    38,    40,    42,    39,    41,
      45,    46,    44,    47,    48,    43,     0,     0,    64,     0,
      57,     0,    12,    77,     0,    80,    61,    54,    73,     0,
       0,    12,     0,    71,    65,     0,     0,    78,     0,     0,
      74,    70,     0,     0,    62,     0,    68,     0,    12,    66,
       0,    69,    12,    75,     0,    30,    31,    81,    72,    67,
       0,     0,    82,    12,     0,    83
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -59,   -59,   137,   -59,   -59,   -58,   -59,   106,   -59,   -34,
     -33,   -59,   -38,   -59,   -59,   -59,   -59,   -59,   -59,   -59,
     -59,   -59,   -59,   -59,   -59,   -59,   -59,   -59,   -59,   -59,
     -59,   -59,   -59,   -59,   -59,   -59,   -59,   -59,   -59,   -59
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    10,    11,     3,    13,    26,    50,    27,    57,
      58,   147,    59,    28,    83,    44,    65,    29,    30,    35,
      88,   121,    31,    61,   114,   132,   144,   137,   122,   130,
     123,   131,    32,    84,   118,    33,    86,   120,   150,   153
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      51,    52,    64,    85,    42,    43,    45,    87,    17,   135,
      73,    74,    75,    76,     1,    68,    69,    70,    66,    67,
      18,    19,    46,    47,     4,    20,   136,    14,    21,    22,
      75,    76,    15,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   102,   105,    54,    23,    24,    45,     7,
       8,     9,    25,    16,   117,   128,   129,    34,    45,    36,
      38,    55,    40,   126,    46,    47,    48,    49,    37,    54,
      41,   115,    39,    53,    46,    47,    48,    49,    56,   106,
     143,   107,    45,    60,   148,    55,    62,   133,   109,   111,
     112,   113,    54,   125,   139,   154,   119,    54,    46,    47,
     100,   101,    56,   116,   124,    45,   145,   146,    55,   127,
      45,    18,    19,    55,   138,   141,    20,   149,   142,    21,
      22,    46,    47,   103,   104,    56,    46,    47,     5,     6,
      56,   151,     7,     8,     9,   152,   108,    23,    24,     0,
      18,    19,    12,    25,   110,    20,    63,     0,    21,    22,
      18,    19,     0,     0,     0,    20,     0,     0,    21,    22,
      18,    19,     0,     0,     0,    20,    23,    24,    21,    22,
       0,     0,    25,     0,     0,   134,    23,    24,     0,     0,
       0,     0,    25,     0,    71,   155,    23,    24,    18,    19,
       0,     0,    25,    20,     0,     0,    21,    22,    73,    74,
      75,    76,    71,    72,    77,    78,    79,    80,    81,    82,
       0,     0,     0,     0,    23,    24,    73,    74,    75,    76,
      25,     0,    77,    78,    79,    80,    81,    82,     0,   140,
      71,    72,    73,    74,    75,    76,     0,     0,    77,    78,
      79,    80,    71,    72,    73,    74,    75,    76,     0,    89,
      77,    78,    79,    80,    81,    82,    73,    74,    75,    76,
       0,     0,    77,    78,    79,    80,    81,    82,    73,    74,
      75,    76,     0,     0,    77,    78,    79,    80,    81,    82
};

static const yytype_int16 yycheck[] =
{
      34,    34,    40,    61,    19,    20,    28,    65,     4,    28,
      27,    28,    29,    30,     5,    53,    54,    55,    44,    45,
      16,    17,    44,    45,     0,    21,    45,    48,    24,    25,
      29,    30,     3,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    15,    42,    43,    28,    10,
      11,    12,    48,    48,   112,    22,    23,    26,    28,    31,
      39,    31,    26,   121,    44,    45,    46,    47,    31,    15,
       3,   109,    31,    31,    44,    45,    46,    47,    48,    32,
     138,    32,    28,    48,   142,    31,    48,   125,    26,    32,
      18,    39,    15,    40,   132,   153,    16,    15,    44,    45,
      46,    47,    48,    39,    31,    28,   140,   140,    31,    41,
      28,    16,    17,    31,    40,    45,    21,    32,    40,    24,
      25,    44,    45,    46,    47,    48,    44,    45,     6,     7,
      48,    32,    10,    11,    12,    39,    41,    42,    43,    -1,
      16,    17,     5,    48,    20,    21,    40,    -1,    24,    25,
      16,    17,    -1,    -1,    -1,    21,    -1,    -1,    24,    25,
      16,    17,    -1,    -1,    -1,    21,    42,    43,    24,    25,
      -1,    -1,    48,    -1,    -1,    41,    42,    43,    -1,    -1,
      -1,    -1,    48,    -1,    13,    41,    42,    43,    16,    17,
      -1,    -1,    48,    21,    -1,    -1,    24,    25,    27,    28,
      29,    30,    13,    14,    33,    34,    35,    36,    37,    38,
      -1,    -1,    -1,    -1,    42,    43,    27,    28,    29,    30,
      48,    -1,    33,    34,    35,    36,    37,    38,    -1,    40,
      13,    14,    27,    28,    29,    30,    -1,    -1,    33,    34,
      35,    36,    13,    14,    27,    28,    29,    30,    -1,    32,
      33,    34,    35,    36,    37,    38,    27,    28,    29,    30,
      -1,    -1,    33,    34,    35,    36,    37,    38,    27,    28,
      29,    30,    -1,    -1,    33,    34,    35,    36,    37,    38
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     5,    50,    53,     0,     6,     7,    10,    11,    12,
      51,    52,    51,    54,    48,     3,    48,     4,    16,    17,
      21,    24,    25,    42,    43,    48,    55,    57,    62,    66,
      67,    71,    81,    84,    26,    68,    31,    31,    39,    31,
      26,     3,    19,    20,    64,    28,    44,    45,    46,    47,
      56,    58,    59,    31,    15,    31,    48,    58,    59,    61,
      48,    72,    48,    56,    61,    65,    44,    45,    61,    61,
      61,    13,    14,    27,    28,    29,    30,    33,    34,    35,
      36,    37,    38,    63,    82,    54,    85,    54,    69,    32,
      61,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      46,    47,    61,    46,    47,    61,    32,    32,    41,    26,
      20,    32,    18,    39,    73,    61,    39,    54,    83,    16,
      86,    70,    77,    79,    31,    40,    54,    41,    22,    23,
      78,    80,    74,    61,    41,    28,    45,    76,    40,    61,
      40,    45,    40,    54,    75,    58,    59,    60,    54,    32,
      87,    32,    39,    88,    54,    41
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    49,    50,    51,    51,    51,    52,    52,    52,    52,
      53,    53,    54,    54,    55,    55,    55,    55,    55,    55,
      55,    55,    56,    56,    57,    57,    58,    58,    59,    59,
      60,    60,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    61,    63,    62,    64,    65,    64,    66,    68,
      69,    70,    67,    72,    73,    74,    75,    71,    76,    76,
      77,    77,    78,    79,    79,    80,    82,    83,    81,    85,
      86,    87,    88,    84
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     5,     1,     1,     1,     5,     5,     5,     2,
       0,     3,     0,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     3,     1,     2,     1,     2,
       1,     1,     1,     1,     1,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     2,     3,     0,     7,     1,     0,     4,     2,     0,
       0,     0,    10,     0,     0,     0,     0,    12,     1,     2,
       2,     1,     4,     0,     2,     3,     0,     0,     9,     0,
       0,     0,     0,    17
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
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
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
            /* Fall through.  */
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

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
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
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
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
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
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
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 126 "parser.y" /* yacc.c:1646  */
    { cout<< "program skeleton defined"<<endl; }
#line 1431 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 129 "parser.y" /* yacc.c:1646  */
    {(yyval.ival)=1;}
#line 1437 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 130 "parser.y" /* yacc.c:1646  */
    {(yyval.ival)=2;}
#line 1443 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 131 "parser.y" /* yacc.c:1646  */
    {(yyval.ival)=3;}
#line 1449 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 134 "parser.y" /* yacc.c:1646  */
    {addConst((yyvsp[-2].sval),(yyvsp[-3].ival),iToCa((yyvsp[0].ival)),1);/*cout << "constant defined " << $3<<endl;*/}
#line 1455 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 135 "parser.y" /* yacc.c:1646  */
    {addConst((yyvsp[-2].sval),(yyvsp[-3].ival),fToCa((yyvsp[0].fval)),2);}
#line 1461 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 136 "parser.y" /* yacc.c:1646  */
    {addConst((yyvsp[-2].sval),(yyvsp[-3].ival),(yyvsp[0].sval),3);/*cout << "constant defined " << $3<<endl;*/}
#line 1467 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 137 "parser.y" /* yacc.c:1646  */
    {addVar((yyvsp[0].sval),(yyvsp[-1].ival)); /*cout << "variable defined " << $2 <<endl;*/}
#line 1473 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 150 "parser.y" /* yacc.c:1646  */
    {/*cout <<line<<": assignemt statemet" <<endl;*/}
#line 1479 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 151 "parser.y" /* yacc.c:1646  */
    {/*cout <<line<<": if statemet" <<endl;*/}
#line 1485 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 152 "parser.y" /* yacc.c:1646  */
    {/*cout <<"while loop " <<endl;*/}
#line 1491 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 153 "parser.y" /* yacc.c:1646  */
    {/*cout <<"do while loop" <<endl;*/}
#line 1497 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 154 "parser.y" /* yacc.c:1646  */
    {/*cout << "for loop" ;*/}
#line 1503 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 155 "parser.y" /* yacc.c:1646  */
    {/*cout <<"switch statemet" <<endl;*/}
#line 1509 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 156 "parser.y" /* yacc.c:1646  */
    {checkBreak();/*addQuad((char*)"goto",iToCa(loop_labels[loop_labels.size()-2]),NULL,NULL);*/}
#line 1515 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 157 "parser.y" /* yacc.c:1646  */
    {checkContinue();addQuad((char*)"goto",iToCa(loop_labels.back()),NULL,NULL);}
#line 1521 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 162 "parser.y" /* yacc.c:1646  */
    {(yyval.sval)=(char*)"1";}
#line 1527 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 163 "parser.y" /* yacc.c:1646  */
    {(yyval.sval)=(char*)"0";}
#line 1533 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 166 "parser.y" /* yacc.c:1646  */
    {checkAssignExp((yyvsp[-2].sval),(yyvsp[0].eval));addQuad((char*)"=",(yyvsp[0].eval)->name,NULL,(yyvsp[-2].sval));}
#line 1539 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 168 "parser.y" /* yacc.c:1646  */
    {checkAssignBool((yyvsp[-2].sval),(yyvsp[0].sval));char* v;if((yyvsp[0].sval)=="1")v=(char*)"true";else v=(char*)"false";addQuad((char*)"=",v,NULL,(yyvsp[-2].sval));}
#line 1545 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 179 "parser.y" /* yacc.c:1646  */
    {(yyval.fval)=(yyvsp[0].fval);}
#line 1551 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 180 "parser.y" /* yacc.c:1646  */
    {(yyval.fval)=-1*(yyvsp[0].fval);}
#line 1557 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 181 "parser.y" /* yacc.c:1646  */
    {(yyval.ival)=(yyvsp[0].ival);}
#line 1563 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 182 "parser.y" /* yacc.c:1646  */
    {(yyval.ival)=-1*(yyvsp[0].ival);}
#line 1569 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 183 "parser.y" /* yacc.c:1646  */
    {(yyval.nval)=createNum(2,fToCa((yyvsp[0].fval)));}
#line 1575 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 184 "parser.y" /* yacc.c:1646  */
    {(yyval.nval)=createNum(1,iToCa((yyvsp[0].ival)));}
#line 1581 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 187 "parser.y" /* yacc.c:1646  */
    {(yyval.eval) = createExpr(2,fToCa((yyvsp[0].fval)),0,NULL);(yyval.eval)->name=addQuad((char*)"=",fToCa((yyvsp[0].fval)),NULL,NULL);}
#line 1587 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 188 "parser.y" /* yacc.c:1646  */
    {(yyval.eval) = createExpr(1,iToCa((yyvsp[0].ival)),0,NULL);(yyval.eval)->name=addQuad((char*)"=",iToCa((yyvsp[0].ival)),NULL,NULL);}
#line 1593 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 189 "parser.y" /* yacc.c:1646  */
    {(yyval.eval) = createExpr(0,NULL,1,(yyvsp[0].sval));}
#line 1599 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 190 "parser.y" /* yacc.c:1646  */
    {(yyval.eval) = checkArithm((yyvsp[-2].eval),'+',(yyvsp[0].eval));(yyval.eval)->name=addQuad((char*)"+",(yyvsp[-2].eval)->name,(yyvsp[0].eval)->name,NULL);}
#line 1605 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 191 "parser.y" /* yacc.c:1646  */
    {(yyval.eval) = checkArithm((yyvsp[-2].eval),'-',(yyvsp[0].eval));(yyval.eval)->name=addQuad((char*)"-",(yyvsp[-2].eval)->name,(yyvsp[0].eval)->name,NULL);}
#line 1611 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 192 "parser.y" /* yacc.c:1646  */
    {(yyval.eval) = checkArithm((yyvsp[-2].eval),'*',(yyvsp[0].eval));(yyval.eval)->name=addQuad((char*)"*",(yyvsp[-2].eval)->name,(yyvsp[0].eval)->name,NULL);}
#line 1617 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 193 "parser.y" /* yacc.c:1646  */
    {(yyval.eval) = checkArithm((yyvsp[-2].eval),'/',(yyvsp[0].eval));(yyval.eval)->name=addQuad((char*)"/",(yyvsp[-2].eval)->name,(yyvsp[0].eval)->name,NULL);}
#line 1623 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 194 "parser.y" /* yacc.c:1646  */
    {(yyval.eval) = checkComparison((yyvsp[-2].eval),(char*)">" ,(yyvsp[0].eval));(yyval.eval)->name=addQuad((char*)">",(yyvsp[-2].eval)->name,(yyvsp[0].eval)->name,NULL);}
#line 1629 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 195 "parser.y" /* yacc.c:1646  */
    {(yyval.eval) = checkComparison((yyvsp[-2].eval),(char*)">=",(yyvsp[0].eval));(yyval.eval)->name=addQuad((char*)">=",(yyvsp[-2].eval)->name,(yyvsp[0].eval)->name,NULL);}
#line 1635 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 196 "parser.y" /* yacc.c:1646  */
    {(yyval.eval) = checkComparison((yyvsp[-2].eval),(char*)"<" ,(yyvsp[0].eval));(yyval.eval)->name=addQuad((char*)"<",(yyvsp[-2].eval)->name,(yyvsp[0].eval)->name,NULL);}
#line 1641 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 197 "parser.y" /* yacc.c:1646  */
    {(yyval.eval) = checkComparison((yyvsp[-2].eval),(char*)"<=",(yyvsp[0].eval));(yyval.eval)->name=addQuad((char*)"<=",(yyvsp[-2].eval)->name,(yyvsp[0].eval)->name,NULL);}
#line 1647 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 198 "parser.y" /* yacc.c:1646  */
    {(yyval.eval) = checkComparison((yyvsp[-2].eval),(char*)"!=",(yyvsp[0].eval));(yyval.eval)->name=addQuad((char*)"!=",(yyvsp[-2].eval)->name,(yyvsp[0].eval)->name,NULL);}
#line 1653 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 199 "parser.y" /* yacc.c:1646  */
    {(yyval.eval) = checkComparison((yyvsp[-2].eval),(char*)"==",(yyvsp[0].eval));(yyval.eval)->name=addQuad((char*)"==",(yyvsp[-2].eval)->name,(yyvsp[0].eval)->name,NULL);}
#line 1659 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 200 "parser.y" /* yacc.c:1646  */
    {(yyval.eval) = checkBoolComparison((yyvsp[-2].eval),(char*)"==",(yyvsp[0].bval));(yyval.eval)->name=addQuad((char*)"==",(yyvsp[-2].eval)->name,(char*)"true",NULL);}
#line 1665 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 201 "parser.y" /* yacc.c:1646  */
    {(yyval.eval) = checkBoolComparison((yyvsp[-2].eval),(char*)"==",(yyvsp[0].bval));(yyval.eval)->name=addQuad((char*)"==",(yyvsp[-2].eval)->name,(char*)"false",NULL);}
#line 1671 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 202 "parser.y" /* yacc.c:1646  */
    {(yyval.eval) = checkBoolComparison((yyvsp[-2].eval),(char*)"!=",(yyvsp[0].bval));(yyval.eval)->name=addQuad((char*)"!=",(yyvsp[-2].eval)->name,(char*)"true",NULL);}
#line 1677 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 203 "parser.y" /* yacc.c:1646  */
    {(yyval.eval) = checkBoolComparison((yyvsp[-2].eval),(char*)"!=",(yyvsp[0].bval));(yyval.eval)->name=addQuad((char*)"!=",(yyvsp[-2].eval)->name,(char*)"false",NULL);}
#line 1683 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 204 "parser.y" /* yacc.c:1646  */
    {(yyval.eval) = checkLogical((yyvsp[-2].eval),(char*)"&",(yyvsp[0].eval));(yyval.eval)->name=addQuad((char*)"and",(yyvsp[-2].eval)->name,(yyvsp[0].eval)->name,NULL);}
#line 1689 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 205 "parser.y" /* yacc.c:1646  */
    {(yyval.eval) = checkLogical((yyvsp[-2].eval),(char*)"|",(yyvsp[0].eval));(yyval.eval)->name=addQuad((char*)"or",(yyvsp[-2].eval)->name,(yyvsp[0].eval)->name,NULL);}
#line 1695 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 206 "parser.y" /* yacc.c:1646  */
    {(yyval.eval) = checkNot((yyvsp[0].eval));(yyval.eval)->name=addQuad((char*)"not",(yyvsp[0].eval)->name,NULL,NULL);}
#line 1701 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 207 "parser.y" /* yacc.c:1646  */
    {(yyval.eval)=(yyvsp[-1].eval);}
#line 1707 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 214 "parser.y" /* yacc.c:1646  */
    {checkCond((yyvsp[0].eval));addQuad((char*)"false",iToCa(label),(yyvsp[0].eval)->name,NULL);labels.push_back(label);label++;}
#line 1713 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 216 "parser.y" /* yacc.c:1646  */
    {addQuad((char*)"goto",iToCa(label),NULL,NULL);addQuad((char*)"l",iToCa(labels.back()),NULL,NULL); 			labels.pop_back();labels.push_back(label);label++;}
#line 1719 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 217 "parser.y" /* yacc.c:1646  */
    {addQuad((char*)"l",iToCa(labels.back()),NULL,NULL);labels.pop_back();}
#line 1725 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 219 "parser.y" /* yacc.c:1646  */
    {addQuad((char*)"l",iToCa(label),NULL,NULL);label++;push_l();label--;}
#line 1731 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 220 "parser.y" /* yacc.c:1646  */
    {checkCond((yyvsp[0].eval));addQuad((char*)"false",iToCa(label),(yyvsp[0].eval)->name,NULL);label--;push_l();label++;}
#line 1737 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 221 "parser.y" /* yacc.c:1646  */
    {lCount++;}
#line 1743 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 221 "parser.y" /* yacc.c:1646  */
    {lCount--;
		addQuad((char*)"goto",iToCa(loop_labels.back()),NULL,NULL);loop_labels.pop_back();
		addQuad((char*)"l",iToCa(loop_labels.back()),NULL,NULL);loop_labels.pop_back();}
#line 1751 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 226 "parser.y" /* yacc.c:1646  */
    {lCount++;addQuad((char*)"l",iToCa(label),NULL,NULL);push_l();push_l();push_l();}
#line 1757 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 227 "parser.y" /* yacc.c:1646  */
    {lCount--;}
#line 1763 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 227 "parser.y" /* yacc.c:1646  */
    {addQuad((char*)"l",iToCa(loop_labels.back()),NULL,NULL);loop_labels.pop_back();}
#line 1769 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 228 "parser.y" /* yacc.c:1646  */
    {checkCond((yyvsp[0].eval));addQuad((char*)"true",iToCa(loop_labels[loop_labels.size()-2]),(yyvsp[0].eval)->name,NULL);
		addQuad((char*)"l",iToCa(loop_labels.back()),NULL,NULL);loop_labels.pop_back();loop_labels.pop_back();}
#line 1776 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 241 "parser.y" /* yacc.c:1646  */
    {checkType((yyvsp[0].sval),1,2);}
#line 1782 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 241 "parser.y" /* yacc.c:1646  */
    {sCount++;}
#line 1788 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 241 "parser.y" /* yacc.c:1646  */
    {sCount--;}
#line 1794 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 249 "parser.y" /* yacc.c:1646  */
    {checkType((yyvsp[0].sval),1,1);}
#line 1800 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 249 "parser.y" /* yacc.c:1646  */
    {checkAssignExp((yyvsp[-3].sval),(yyvsp[0].eval));addQuad((char*)"=",(yyvsp[0].eval)->name,NULL,(yyvsp[-3].sval));
	addQuad((char*)"l",iToCa(label),NULL,NULL);push_l();}
#line 1807 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 251 "parser.y" /* yacc.c:1646  */
    {checkType((yyvsp[-8].sval),(yyvsp[0].nval)->type,3);addQuad((char*)"false",iToCa(label),(yyvsp[-2].eval)->name,NULL);push_l();push_l();}
#line 1813 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 252 "parser.y" /* yacc.c:1646  */
    {lCount++;}
#line 1819 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 253 "parser.y" /* yacc.c:1646  */
    {lCount--;addQuad((char*)"l",iToCa(loop_labels.back()),NULL,NULL);loop_labels.pop_back();
	addQuad((char*)"=",addQuad((char*)"+",(yyvsp[-14].sval),addQuad((char*)"=",(yyvsp[-6].nval)->val,NULL,NULL),NULL),NULL,(yyvsp[-14].sval));
	addQuad((char*)"goto",iToCa(loop_labels[loop_labels.size()-2]),NULL,NULL);
	addQuad((char*)"l",iToCa(loop_labels.back()),NULL,NULL);
	loop_labels.pop_back();loop_labels.pop_back();}
#line 1829 "parser.tab.c" /* yacc.c:1646  */
    break;


#line 1833 "parser.tab.c" /* yacc.c:1646  */
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



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
                      yytoken, &yylval);
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 277 "parser.y" /* yacc.c:1906  */
 
//end of grammar

int main(int, char**) {
	//Loops =0, Switch cases=0
	lCount=0;sCount=0;
	//initialize types map
	types[0]= (char*)"unknown";
	types[1]= (char*)"int"; 
	types[2]= (char*)"float";
	types[3]= (char*)"bool";
	// open a file handle to a particular file:
	FILE *myfile = fopen("temp.txt", "r");
	// make sure it is valid:
	if (!myfile) {
		cout << "I can't open a.snazzle.file!" << endl;
		return -1;
	}
	// set flex to read from it instead of defaulting to STDIN:
	yyin = myfile;
	// make sure it is valid:
	if (!file) {
		cout << "can't open file" << endl;
		return -1;
	}
	// parse through the input until there is no more:
	do {
		yyparse();
	} while (!feof(yyin));
	checkUnused();
	if(!err)
		printQuads();
	
}

void yyerror(const char *s) {
	//cout << "oops, parse error in line "<<line<<"!  Message: " << s << endl;
		
	fprintf(stderr,"Error: %s at line %d\n", s,line);	
	//fprintf(stderr, "Parser does not expect '%s\n'",yytext);
	exit(-1);
}

////////// Quadriples /////////////////
char* addQuad(char* opr,char* opd1,char* opd2,char* res)
{
	struct code q;
	q.opr=opr;
	q.opd1=opd1;
	q.opd2=opd2;
	if(res==NULL && opr!=(char*)"false" && opr!=(char*)"true" && opr!=(char*)"l" && opr!=(char*)"goto")
	{
		char* t=(char*)"t";
		char* tmp = (char *) malloc(1 + strlen(t)+ strlen(iToCa(tmp_count)) );
		strcpy(tmp, t);
		strcat(tmp, iToCa(tmp_count));
		q.res=tmp;
		tmp_count++;
	}
	else
		q.res=res;
	quads.push_back(q);
	return q.res;
}
void printQuads()
{
	while(!quads.empty())
	{
		struct code q=quads.front();
		if(q.opr==(char*)"false")
		{
			fprintf(file,"if not %s goto L%s\n",q.opd2,q.opd1);
		}
		else if(q.opr==(char*)"true")
		{
			fprintf(file,"if %s goto L%s\n",q.opd2,q.opd1);
		}
		else if(q.opr==(char*)"l")
		{
			fprintf(file,"L%s:\n",q.opd1);
		}
		else if(q.opr==(char*)"goto")
		{
			fprintf(file,"goto L%s\n",q.opd1);
		}
		else if(q.opr==(char*)"=")
		{
			fprintf(file, "%s %s %s\n",q.res,q.opr,q.opd1);
		}
		else if(q.opr==(char*)"not")
		{
			fprintf(file,"%s = %s %s",q.res,q.opr,q.opd1);
		}
		else
		{
			fprintf(file,"%s = %s %s %s\n",q.res,q.opd1,q.opr,q.opd2);
		}
		quads.pop_front();
	}
}
void push_l()
{
	loop_labels.push_back(label);
	label++;
}
/** Functions used for semantic analysis **/

void checkType(char*id,int t,int m){
if(isDeclared(id))
symbolTable[id]->used=1;
//Switch case
if(m==2){
if(!isDeclared(id)){
err=true;
msg(undeclared,line,id,NULL);
return;
}
if(!isInit(id)){
err=true;
msg(uninit,line,id,NULL);
return;
}
}
else if(m==1){
	if(!isDeclared(id)){
	err=true;
	return;
	}
	if(symbolTable[id]->type !=1 && symbolTable[id]->type !=2){
	err=true;
	printf("Semantic ERROR line: %d :: Loop counter must have int or float type",line);
	}
}
else{
	if(!isDeclared(id)){
	err=true;
	return;
	}
	if(symbolTable[id]->type == 2)
		return;
	if(t!=1){
	err=true;
	printf("Semantic ERROR line: %d :: Step has to be integer for integer counter\n",line);
}

}
}
void checkUnused(){
map<char*,symbolData*> ::iterator it;
for(it=symbolTable.begin();it!=symbolTable.end();it++){
	if(!it->second->used){
		if(it->second->cl==1)
		msg(unusedConst,0,it->first,NULL);
		else
		msg(unusedVar,0,it->first,NULL);
	}

}

}
bool isDeclared(char*id){
map<char*,symbolData*>::iterator it = symbolTable.find(id);
return it!=symbolTable.end();
}
//Convert integer to char*
char*iToCa(int i){
 char*str = (char*)malloc(sizeof(int));	
 sprintf(str, "%d", i);
return str;
}
//Convert float to char*
char*fToCa(float n){
char *b = (char*)malloc(sizeof(float));
int ret = snprintf(b, sizeof b, "%f", n);
//cout<<"Converted Value: "<<b<<endl;
return b;
}
//uninitVar=6,unusedVar=7

void msg(int m, int l,char* t1,char* t2){
if(m==1)
	printf("Semantic ERROR line: %d :: Usage of undeclared variable %s \n",line,t1);	
else if(m==2)
	printf("Semantic ERROR line: %d :: Usage of uninitialized variable %s \n",l,t1);
else if(m==3)
	printf("Semantic ERROR line: %d :: Type Mismatch: can't assign %s to %s \n",line,t1,t2);
else if(m==4)
	printf("Semantic ERROR line: %d :: Type Mismatch: can't Compare %s to %s \n",l,t1,t2);
else if(m==5)
	printf("Semantic ERROR line: %d :: Both expressions should have numerical values \n",l);
else if(m==6)
	printf("Semantic WARNING :: Uninitialized Variable %s \n",t1);
else if(m==7)
	printf("Semantic WARNING :: Unused Variable %s \n",t1);
else if(m==8)
	printf("Semantic ERROR line: %d :: Break statement not within loop or switch case \n",l);
else if(m==9)
	printf("Semantic ERROR line: %d :: Continue statement not within loop \n",l);
else if(m==10)
	printf("Semantic WARNING :: Constant %s is unused \n",t1);

}

bool isInit(char*id){
return symbolTable[id]->val!=NULL;
}

void checkBreak(){
if(lCount == 0 && sCount==0){
err=true;
msg(brk,line,NULL,NULL);
}
}
void checkContinue(){
if(lCount == 0){
err=true;
msg(cont,line,NULL,NULL);
}
}

// Constant declaration
void addConst(char*id, int t1,char* val, int t2){

if(isDeclared(id)){
err=true;
printf("Semantic ERROR line: %d :: Multiple declarations for Const %s",line,id);
return;
}
symbolData* d = (symbolData*)malloc(sizeof(struct symbolData));

if(t1!=t2){
err=true;
msg(assignMismatch,line,types[t2],types[t1]);
d->val=NULL;
}
else{
d->val = (char*)malloc(sizeof(val));
strncpy(d->val,val,sizeof(d->val));
}

d->type=t1;
d->cl=1;
d->used=0;
symbolTable[id]=d;
printf("%d: %s Const %s %s\n",line,types[t1],id,d->val);
}

/******************Variable declaration*******************/

void addVar(char*id, int t){
if(isDeclared(id))
{
err=true;
printf("Semantic ERROR line: %d :: Multiple declarations for variable %s \n",line,id);
return;
}

symbolData* d = (symbolData*)malloc(sizeof(struct symbolData));
d->val=NULL;
d->type=t;
d->cl=0;
d->used=0;
symbolTable[id]=d;
printf("%d: %s Var %s %s\n",line,types[t],id,d->val);
}
/********************Bool Assignment Statement Check***********/
void checkAssignBool(char*id1,char*bolval){
if(!isDeclared(id1)){
err=true;
msg(undeclared,line,id1,NULL);
return;
}
symbolData* d = symbolTable[id1];
//Constant can't be changed
if(d->cl == 1){
err=true;
printf("Semantic ERROR line: %d :: Invalid Assignment to a constant\n",line);
return;
}
//Check type mismatch
if(d->type != 3){
err=true;
if(d->type!=0)
	msg(assignMismatch,line,types[3],types[d->type]);
return;
}

d->val = (char*)malloc(sizeof(bolval));
strncpy(d->val,bolval,sizeof(d->val));
printf("%d: %s %s %s \n",line,types[3],id1,d->val);
}
/********************Expression Assignment Statement Check***********/
void checkAssignExp(char*id1,exptype*e){

//Check identifier is declared prevoiusly
if(!isDeclared(id1)){
	err=true;
	msg(undeclared,line,id1,NULL);
	return;
}

if(e->id){
	if(!isDeclared(e->name)){
	err=true;	
	return;
	}
	else{ 
	symbolTable[e->name]->used=1;
	if (!isInit(e->name)){
	err=true;
	printf("Semantic ERROR line: %d :: RHS has no value, LHS unchanged! \n",line);
	return;
	}
	}
}


symbolData* d = symbolTable[id1];
//Constant can't be changed
if(d->cl == 1){
err=true;
printf("Semantic ERROR line: %d :: Invalid Assignment to a constant\n",line);
return;
}
//
if(e->val == NULL){
err=true;
printf("Semantic ERROR line: %d :: RHS has no value, LHS unchanged! \n",line);
return;
}
//Check type mismatch
if(d->type != e->type){
err=true;
if(e->type!=0 && d->type!=0)
	msg(assignMismatch,line,types[e->type],types[d->type]);
return;
}

d->val = (char*)malloc(sizeof(e->val));
strncpy(d->val,e->val,sizeof(d->val));

printf("%d: %s %s %s \n",line,types[d->type],id1,d->val);
}
/*******************Create Expression *******************/
num*createNum(int t,char* v){
num* n = (num*)malloc(sizeof(struct num));
n->type=t;
n->val=v;
return n;
}

/*******************Create Expression *******************/
exptype*createExpr(int i, char* c, int id1, char*n){

exptype* t = (exptype*)malloc(sizeof(struct exptype));

if(id1==1)
{
	if(!isDeclared(n))
	{
		err=true;
		msg(undeclared,line,n,NULL);
		t->type=0;
		t->val = NULL;
	}
	else if(!isInit(n)){
		err=true;
		msg(uninit,line,n,NULL);
		t->type=symbolTable[n]->type;
		t->val = NULL;
		}
	else{
		t->type=symbolTable[n]->type;
		t->val=symbolTable[n]->val;
	}
}
else{
	t->type=i;
	t->val = allocValue(sizeof(c));
	strncpy(t->val,c,sizeof(t->val));	
}
t->id=id1;
t->name=n;

return t;
}

/*********************   Check Arithmetic Operations ******************/
exptype* checkArithm(exptype*e1,char op,exptype*e2){
exptype* t = (exptype*)malloc(sizeof(struct exptype));
//Mark Used Variables
if(isDeclared(e1->name))
symbolTable[e1->name]->used=1;

if(isDeclared(e2->name))
symbolTable[e2->name]->used=1;

if(invalidExpressions(e1,e2)){
	t->type=0;
	t->val=NULL;
	t->name=NULL;
	t->id=0;
return t;
}


//One of the expressions is bool
if(e1->type==3 || e2->type==3)
{
	err=true;
	if(e1->type!=0 && e2->type!=0)
		msg(numerical,line,NULL,NULL);
	t->type=0;
	t->val=NULL;
	t->name=NULL;
	t->id=0;
	return t;
}



//One of the expressions is float
if(e1->type == 2 || e2->type == 2)
{
	double x1 = (double)atof(e1->val);
	double x2 = (double)atof(e2->val);
	double res = calcFloat(x1, op,x2);
	cout<<line<<": Result: "<<res<<endl;
	t->type = 2;
	t->val = fToCa(res);
	t->id = 0;
	t->name = NULL;
	return t;
}
//Both expressions are integers
	long x1 = (long)atoi(e1->val);
	long x2 = (long)atoi(e2->val);
	if(op=='/'){
	double res = calcFloat((double)x1,op,(double)x2);
	t->type = 2;
	t->val = fToCa(res);
	cout<<line<<": Result: "<<res<<endl;
	}
	else{
	long res = calcInt(x1, op,x2);
	t->type = 1;
	t->val = iToCa(res);
	cout<<line<<": Result: "<<res<<endl;
	}		
	
	t->id = 0;
	t->name = NULL;
	return t;
}

double calcFloat(double x1, char op, double x2){
switch(op){
case '+':
	return x1+x2;
	break;
case '-':
	return x1-x2;
	break;
case '*':
	return x1*x2;
	break;
case '/':
	if(x2==0.0){
	printf("Semantic ERROR line: %d :: Can't divide by zero\n",line);
	return 0;
	}
	else{
	return x1/x2;
	}
	break;
}
}

long calcInt(long x1, char op, long x2){
switch(op){
case '+':
	return x1+x2;
	break;
case '-':
	return x1-x2;
	break;
case '*':
	return x1*x2;
	break;
case '/':
	if(x2==0){
	printf("Semantic ERROR line: %d :: Can't divide by zero\n",line);
	return 0;
	}
	else{
	return x1/x2;
	}
	break;
}
}
/******************** Check Comparison statements ******************/
exptype* checkComparison(exptype*e1,char*op,exptype*e2){
exptype* t = (exptype*)malloc(sizeof(struct exptype));

//Mark Used Variables
if(isDeclared(e1->name))
symbolTable[e1->name]->used=1;

if(isDeclared(e2->name))
symbolTable[e2->name]->used=1;


//One of the expressions is not integer or float
if((e1->type != 1 && e1->type != 2) || (e2->type != 1 && e2->type != 2))
{
	//Comparison operands must have numerical values only
	if(op != "!="&&op!="=="){
		err=true;
		if(e1->type!=0 && e2->type!=0)
		msg(numerical,line,NULL,NULL);
		t->type = 0;
		t->val = NULL;
		t->id = 0;
		t->name = NULL;
		return t;
	}
}

if(invalidExpressions(e1,e2)){
	err=true;
	t->type=0;
	t->val=NULL;
	t->name=NULL;
	t->id=0;
return t;
}


//Compare 2 integers
if(e1->type == 1 && e2->type==1){

	long x1 = (long)atoi(e1->val);
	long x2 = (long)atoi(e2->val);
	bool res = compareInt(x1,op,x2);
	cout<<line<<": Result: "<<res<<endl;
	t->type = 3;
	if(res)
		t->val = (char*)"1";
	else
		t->val=(char*)"0";
	t->id = 0;
	t->name = NULL;
	return t;
}

//Compare 2 floats
if(e1->type == 2 && e2->type==2){

	double x1 = (double)atoi(e1->val);
	double x2 = (double)atoi(e2->val);
	bool res = compareFloat(x1,op,x2);
	cout<<line<<": Result: "<<res<<endl;
	t->type = 3;
	if(res)
		t->val = (char*)"1";
	else
		t->val=(char*)"0";
	t->id = 0;
	t->name = NULL;
	return t;
}

//Compare 2 Booleans
if(e1->type == 3 && e2->type==3){
	if(op!="!=" && op!="==")
	{
	err=true;
	printf("Semantic ERROR line: %d :: Can't Compare boolean values \n",line);
	t->type = 0;
	t->val = NULL;
	t->id = 0;
	t->name = NULL;
	return t;
	}

	bool x1,x2;
	if(e1->val=="1")
	x1=true;
	else 
	x1=false;
	if(e2->val=="1")
	x2=true;
	else 
	x2=false;
		
	bool res = compareBool(x1,op,x2);
	cout<<line<<": Result: "<<res<<endl;
	t->type = 3;
	if(res)
		t->val = (char*)"1";
	else
		t->val=(char*)"0";
	t->id = 0;
	t->name = NULL;
	return t;
}
if(e1->type!=0 && e2->type!=0)
	msg(compareMismatch,line,types[e1->type],types[e2->type]);
t->type =0;
t->val = NULL;
t->id = 0;
t->name = NULL;
return t;
}

/******************************Check boolean comparison***********************************/
exptype* checkBoolComparison(exptype*e,char*op,bool bolval){
exptype* t = (exptype*)malloc(sizeof(struct exptype));
//Mark used variables
if(e->id && isDeclared(e->name))
symbolTable[e->name]->used=1;

bool v=false;
if(e->id &&!isDeclared(e->name)){
err=true;
msg(undeclared,line,e->name,NULL);
v=true;
}
else if(e->type!=3){
err=true;
if(e->type!=0)
	msg(compareMismatch,line,types[e->type],types[3]);
v=true;
}
//uninitialized
else if (e->id && !isInit(e->name)){
err=true;
msg(uninit,line,e->name,NULL);
v=true;
}

if(v){
t->type =0;
t->val = NULL;
t->id = 0;
t->name = NULL;
return t;
}


bool x1;
if(e->val == "1")
x1=true;
else
x1=false;

bool res = compareBool(x1,op,bolval);
cout<<line<<": Result: "<<res<<endl;
t->type = 3;
if(res)
	t->val = (char*)"1";
else
	t->val=(char*)"0";
t->id = 0;
t->name = NULL;
return t;
}
/**************** Check Logical Operations *********************/
exptype*checkLogical(exptype*e1,char*op,exptype*e2){
exptype* t = (exptype*)malloc(sizeof(struct exptype));
//One of the expressions is not boolean
bool v = false;
if(e1->type!=3 || e2->type!=3){
err=true;
if(e1->type!=0 && e2->type!=0)
	printf("Semantic ERROR line: %d :: Both values have to be bool \n",line);
v=true;
}
//One of them is undeclared or unintialiazed
if(invalidExpressions(e1,e2)||v){
err=true;
t->type=0;
t->val=NULL;
t->name=NULL;
t->id=0;
return t;
}

bool x1 = (strcmp(e1->val,"1")==0)?true:false; 
bool x2 = (strcmp(e2->val,"1")==0)?true:false;
bool res = logical(x1,op,x2);
t->type=3;
t->val=res?(char*)"1":(char*)"0";
cout<<line<<": Result: "<<res<<endl;
t->name=NULL;
t->id=0;
}

exptype*checkNot(exptype*e){
exptype* t = (exptype*)malloc(sizeof(struct exptype));
if(!isDeclared(e->name)){
err=true;
t->type=3;
t->val=NULL;
t->name=NULL;
t->id=0;
return t;
}
if(e->type!=3){
printf("Semantic ERROR line: %d :: Can't apply NOT on %s variable!\n",line,types[e->type]);
err=true;
t->type=3;
t->val=NULL;
t->name=NULL;
t->id=0;
return t;
}


bool x = (strcmp(e->val,"1")==0)?true:false;
if(!x)
t->val=(char*)"1";
else
t->val=(char*)"0";

t->type=3;
t->name=NULL;
t->id=0;
return t;

}

void checkCond(exptype*e){
if(e->id==1){
if(!isDeclared(e->name)){
err=true;
msg(undeclared,line,e->name,NULL);
return;
}
if(!isInit(e->name))
err=true;
msg(uninit,line,e->name,NULL);
return;
}
if(e->type!=3){
err=true;
if(e->type!=0)
	printf("Semantic ERROR line: %d :: Condition must have a bool value \n",line);
}
}
bool logical(bool x1, char*op,bool x2){
if(op == "&")
return x1&&x2;
if(op=="|")
return x1||x2;
if(op=="!")
return !x2;
}


bool invalidExpressions(exptype*e1,exptype*e2){
bool udec1 = false, udec2 = false, uin1 = false, uin2 = false;
//Expression 1 is identifier
if(e1->id){
	//undelcared
	if(!isDeclared(e1->name)){
	udec1=true;
	return true;
	}
	symbolTable[e1->name]->used=1;
	//uninitialized
	if (!isInit(e1->name)){
	uin1=true;
	}
		
}
//Expression 2 is identifier
if(e2->id){
	//undelcared
	if(!isDeclared(e2->name)){
	udec2=true;
	return true;
	}
	symbolTable[e2->name]->used=1;	
	//uninitialized
	if (!isInit(e2->name)){
	uin2=true;

	}
		
}

return (udec1 || udec2 || uin1 || uin2);
}
bool compareInt(int x1,char*op, int x2){
if(op == ">")
return x1>x2;
if(op=="<")
return x1<x2;
if(op==">=")
return x1>=x2;
if(op=="<=")
return x1<=x2;
if(op=="==")
return x1==x2;
if(op=="!=")
return x1!=x2;
}

bool compareFloat(float x1, char*op, float x2){
if(op == ">")
return x1>x2;
if(op=="<")
return x1<x2;
if(op==">=")
return x1>=x2;
if(op=="<=")
return x1<=x2;
if(op=="==")
return x1==x2;
if(op=="!=")
return x1!=x2;
}

bool compareBool(bool x1, char*op, bool x2){
if(op == ">")
return x1>x2;
if(op=="<")
return x1<x2;
if(op==">=")
return x1>=x2;
if(op=="<=")
return x1<=x2;
if(op=="==")
return x1==x2;
if(op=="!=")
return x1!=x2;
}

char*allocValue(int t){
if (t==1)
return (char*)malloc(sizeof(int));
else if(t==2)
return (char*)malloc(sizeof(float));
else
return (char*)malloc(2*sizeof(char));
}



