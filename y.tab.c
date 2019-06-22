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
#line 1 "ccode.y" /* yacc.c:339  */

#include <stdio.h>
#include <stdlib.h>
#define red "\033[0;31m"
#define cyan "\033[1;36m"
#define green "\033[4;32m"
#define blue "\0\33[9;34m"
#define none "\033[0m"

extern FILE *fp;
FILE * f1 /*archivo para codigo intermedio*/;
FILE * f2 /*archivo para codigo asm*/;
void validar_entrada(int argc, char *argv[]);
void yyerror(const char *s);
void push();
void codegen_logical();
void codegen_algebric();
void codegen_assign();
void if_label1();
void if_label2();
void if_label3();
void while_start();
void while_rep();
void while_end();
void switch_start();
void switch_case();
void switch_default();
void switch_break();
void switch_nobreak();
void switch_end();
void check();
void setType();
void STMT_DECLARE();
void intermediateCode();
void inicio_codigo();
void final_codigo();
int string_to_num(char* op1);
void generarVariables();



#line 108 "y.tab.c" /* yacc.c:339  */

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
    INT = 258,
    VOID = 259,
    UINT = 260,
    WHILE = 261,
    IF = 262,
    ELSE = 263,
    SWITCH = 264,
    CASE = 265,
    BREAK = 266,
    DEFAULT = 267,
    NUM = 268,
    ID = 269,
    INCLUDE = 270,
    ASGN = 271,
    LOR = 272,
    LAND = 273,
    BOR = 274,
    BXOR = 275,
    BAND = 276,
    EQ = 277,
    NE = 278,
    LE = 279,
    GE = 280,
    LT = 281,
    GT = 282,
    IFX = 283,
    IFX1 = 284
  };
#endif
/* Tokens.  */
#define INT 258
#define VOID 259
#define UINT 260
#define WHILE 261
#define IF 262
#define ELSE 263
#define SWITCH 264
#define CASE 265
#define BREAK 266
#define DEFAULT 267
#define NUM 268
#define ID 269
#define INCLUDE 270
#define ASGN 271
#define LOR 272
#define LAND 273
#define BOR 274
#define BXOR 275
#define BAND 276
#define EQ 277
#define NE 278
#define LE 279
#define GE 280
#define LT 281
#define GT 282
#define IFX 283
#define IFX1 284

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);



/* Copy the second part of user declarations.  */

#line 214 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  8
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   839

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  43
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  52
/* YYNRULES -- Number of rules.  */
#define YYNRULES  97
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  173

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   284

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
      36,    37,    30,    28,    42,    29,     2,    31,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    41,    40,
       2,     2,     2,     2,    32,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    38,     2,    39,    33,     2,     2,     2,
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
      25,    26,    27,    34,    35
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    68,    68,    69,    70,    71,    72,    75,    76,    77,
      83,    84,    88,    89,    90,    91,    92,    93,    99,    99,
     100,   100,   101,   101,   102,   102,   103,   103,   104,   104,
     105,   105,   106,   106,   107,   107,   108,   108,   109,   109,
     110,   110,   111,   111,   112,   112,   113,   113,   115,   116,
     117,   118,   120,   121,   122,   127,   127,   131,   131,   132,
     136,   136,   138,   139,   142,   143,   147,   147,   148,   152,
     152,   153,   153,   157,   157,   161,   161,   162,   167,   168,
     173,   173,   173,   177,   178,   182,   182,   182,   187,   188,
     188,   193,   193,   193,   193,   198,   199,   200
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT", "VOID", "UINT", "WHILE", "IF",
  "ELSE", "SWITCH", "CASE", "BREAK", "DEFAULT", "NUM", "ID", "INCLUDE",
  "ASGN", "LOR", "LAND", "BOR", "BXOR", "BAND", "EQ", "NE", "LE", "GE",
  "LT", "GT", "'+'", "'-'", "'*'", "'/'", "'@'", "'~'", "IFX", "IFX1",
  "'('", "')'", "'{'", "'}'", "';'", "':'", "','", "$accept", "pgmstart",
  "STMTS", "STMT1", "STMT", "EXP", "$@1", "$@2", "$@3", "$@4", "$@5",
  "$@6", "$@7", "$@8", "$@9", "$@10", "$@11", "$@12", "$@13", "$@14",
  "$@15", "STMT_IF", "$@16", "ELSESTMT", "$@17", "STMT_SWITCH", "$@18",
  "SWITCHBODY", "CASES", "$@19", "BREAKSTMT", "$@20", "$@21",
  "DEFAULTSTMT", "$@22", "DE", "$@23", "SWITCHEXP", "STMT_WHILE", "$@24",
  "$@25", "WHILEBODY", "STMT_DECLARE", "$@26", "$@27", "IDS", "$@28",
  "STMT_ASSGN", "$@29", "$@30", "$@31", "TYPE", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,    43,    45,
      42,    47,    64,   126,   283,   284,    40,    41,   123,   125,
      59,    58,    44
};
# endif

#define YYPACT_NINF -95

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-95)))

#define YYTABLE_NINF -94

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     189,    -5,   -95,   -95,   -95,    41,     9,    16,   -95,    27,
      14,     5,    42,    43,    12,    10,    10,    10,    10,    10,
     119,   119,   -95,   -95,   -95,   -95,   -95,    64,    66,   -95,
     -95,    67,   119,   -95,   -95,   -95,    97,   -95,   -95,   -95,
       6,   100,   153,    94,   -95,   -95,    75,    98,   -95,   -95,
       7,   -95,   -95,   100,   678,   647,   709,   -95,   100,   -95,
     740,   771,   100,   -95,   -95,   -95,   -95,   -95,   -95,   -95,
     -95,   -95,   -95,   -95,    99,   101,    96,   107,   108,    79,
     117,   -95,   100,   802,   -24,   -95,    68,   -95,   120,   100,
     100,   100,   100,   100,   100,   100,   100,   100,   100,    10,
     100,   100,   100,   100,   100,   122,   122,   118,   616,   -95,
     -95,   144,   -95,   151,   182,   213,   244,   275,   306,   337,
     368,   399,   430,   126,   461,   492,   523,   554,   585,   148,
     123,   152,   147,   122,   125,    69,   -95,   -95,   -95,   -95,
     -95,   -95,   -95,   -95,   156,   -95,   -95,   -95,   -95,   -24,
      10,   146,   155,   -95,   -95,   -95,    69,    69,   -95,   -95,
     186,   187,   -95,   -95,   122,   -95,   -95,   175,   -95,   176,
     122,   -95,   -95
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,    95,    96,    97,     0,     0,     0,     1,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      11,    11,     3,     4,     5,     6,     2,     0,     0,    91,
      17,     0,    11,    14,    16,    15,     0,    12,    13,    85,
       0,     0,     0,     0,     8,    10,     0,     0,     9,     7,
       0,    53,    52,     0,     0,     0,     0,    92,     0,    86,
       0,     0,     0,    28,    26,    20,    24,    18,    22,    30,
      32,    34,    36,    55,     0,     0,     0,     0,     0,     0,
       0,    60,     0,     0,     0,    50,     0,    49,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    68,    68,     0,     0,    81,
      88,     0,    87,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    59,     0,     0,     0,     0,     0,     0,
       0,    64,     0,    68,     0,     0,    89,    57,    56,    66,
      63,    73,    65,    62,     0,    94,    83,    84,    82,     0,
       0,     0,     0,    61,    90,    58,     0,     0,    78,    79,
      71,    77,    69,    67,    68,    75,    74,     0,    72,     0,
      68,    76,    70
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -95,   -95,   -15,    19,    28,   -36,   -95,   -95,   -95,   -95,
     -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,
     -95,   -95,   -95,   -95,   -95,   -95,   -95,   -94,   -93,   -95,
     -95,   -95,   -95,   -95,   -95,   -95,   -95,    60,   -95,   -95,
     -95,   -95,   -95,   -95,   -95,    71,   -95,   -95,   -95,   -95,
     -95,   218
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     5,   158,    31,    32,    88,    93,    91,    94,    92,
      90,    89,    95,    96,    97,    98,    74,    75,    76,    77,
      78,    33,    99,   138,   150,    34,   107,   130,   131,   151,
     163,   167,   164,   142,   152,   166,   169,   160,    35,    36,
     135,   148,    37,    47,    84,   112,   149,    38,    43,    82,
     134,    39
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      22,    23,    24,    25,    26,    54,    56,    48,    50,     7,
       9,    20,   132,    18,    60,    13,   110,    61,   111,    60,
      51,    52,    83,    10,   -54,   -54,   -54,   -54,   -54,   -54,
     -54,   -54,   -54,   -54,   -54,   -54,   -54,   -54,   -54,   144,
      40,     8,    15,    53,   -54,    49,   108,   -54,    21,    19,
      14,    45,    11,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,    12,   124,   125,   126,   127,   128,    50,
      20,   168,     2,     3,     4,   -80,    27,   172,    28,    16,
      17,    51,    52,    29,   123,   -51,   -51,   -51,   -51,   -51,
     -51,   -51,   -51,   -51,   -51,   -51,   -51,   -51,   -51,   -51,
      41,    50,    42,    46,    53,   -51,    44,    21,   -51,    30,
      57,    58,    59,    51,    52,   102,   100,   105,    50,   101,
     146,    62,     2,     3,     4,   -80,    27,   103,    28,   104,
      51,    52,   129,    29,   137,   155,    53,   -38,   -40,   -42,
     -44,   -46,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    62,    53,    55,   106,   133,   -48,   136,    30,
     -48,   139,   140,   147,   141,   145,    51,    52,   -29,   -29,
     -29,   -29,   -29,   -29,   -29,    65,    66,    67,    68,    69,
      70,    71,    72,    62,   159,   159,   143,   156,   -29,    53,
       1,   -29,     2,     3,     4,   153,   157,   162,   165,   -27,
     -27,   -27,   -27,   -27,   -27,   -27,    65,    66,    67,    68,
      69,    70,    71,    72,    62,   170,   171,   161,     6,   -27,
     154,     0,   -27,     0,     0,     0,     0,     0,     0,     0,
     -21,   -21,   -21,   -21,   -21,   -21,   -21,   -21,   -21,   -21,
     -21,    69,    70,    71,    72,    62,     0,     0,     0,     0,
     -21,     0,     0,   -21,     0,     0,     0,     0,     0,     0,
       0,   -25,   -25,   -25,   -25,   -25,   -25,   -25,   -25,   -25,
     -25,   -25,    69,    70,    71,    72,    62,     0,     0,     0,
       0,   -25,     0,     0,   -25,     0,     0,     0,     0,     0,
       0,     0,   -19,   -19,   -19,   -19,   -19,   -19,   -19,   -19,
     -19,   -19,   -19,    69,    70,    71,    72,    62,     0,     0,
       0,     0,   -19,     0,     0,   -19,     0,     0,     0,     0,
       0,     0,     0,   -23,   -23,   -23,   -23,   -23,   -23,   -23,
     -23,   -23,   -23,   -23,    69,    70,    71,    72,    62,     0,
       0,     0,     0,   -23,     0,     0,   -23,     0,     0,     0,
       0,     0,     0,     0,   -31,   -31,   -31,   -31,   -31,   -31,
     -31,   -31,   -31,   -31,   -31,   -31,   -31,    71,    72,    62,
       0,     0,     0,     0,   -31,     0,     0,   -31,     0,     0,
       0,     0,     0,     0,     0,   -33,   -33,   -33,   -33,   -33,
     -33,   -33,   -33,   -33,   -33,   -33,   -33,   -33,    71,    72,
      62,     0,     0,     0,     0,   -33,     0,     0,   -33,     0,
       0,     0,     0,     0,     0,     0,   -35,   -35,   -35,   -35,
     -35,   -35,   -35,   -35,   -35,   -35,   -35,   -35,   -35,   -35,
     -35,    62,     0,     0,     0,     0,   -35,     0,     0,   -35,
       0,     0,     0,     0,     0,     0,     0,   -37,   -37,   -37,
     -37,   -37,   -37,   -37,   -37,   -37,   -37,   -37,   -37,   -37,
     -37,   -37,    62,     0,     0,     0,     0,   -37,     0,     0,
     -37,     0,     0,     0,     0,     0,     0,     0,   -38,   -39,
     -39,   -39,   -39,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    62,     0,     0,     0,     0,   -39,     0,
       0,   -39,     0,     0,     0,     0,     0,     0,     0,   -38,
     -40,   -41,   -41,   -41,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    62,     0,     0,     0,     0,   -41,
       0,     0,   -41,     0,     0,     0,     0,     0,     0,     0,
     -38,   -40,   -42,   -43,   -43,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    62,     0,     0,     0,     0,
     -43,     0,     0,   -43,     0,     0,     0,     0,     0,     0,
       0,   -38,   -40,   -42,   -44,   -45,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    62,     0,     0,     0,
       0,   -45,     0,     0,   -45,     0,     0,     0,     0,     0,
       0,     0,   -38,   -40,   -42,   -44,   -46,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    62,     0,     0,
       0,     0,   -47,     0,     0,   -47,     0,     0,     0,     0,
       0,     0,     0,   -38,   -40,   -42,   -44,   -46,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    50,     0,
       0,     0,     0,     0,     0,     0,   -93,     0,     0,     0,
      51,    52,     0,     0,   -54,   -54,   -54,   -54,   -54,   -54,
     -54,   -54,   -54,   -54,   -54,   -54,   -54,   -54,   -54,    62,
       0,     0,     0,    53,    79,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   -38,   -40,   -42,   -44,   -46,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      80,     0,     0,     0,     0,    73,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   -38,   -40,   -42,   -44,
     -46,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    62,     0,     0,     0,     0,    81,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   -38,   -40,   -42,
     -44,   -46,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    86,     0,     0,     0,     0,    85,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   -38,   -40,
     -42,   -44,   -46,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    62,     0,     0,     0,     0,    87,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   -38,
     -40,   -42,   -44,   -46,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,     0,     0,     0,     0,     0,   109
};

static const yytype_int16 yycheck[] =
{
      15,    16,    17,    18,    19,    41,    42,     1,     1,    14,
       1,     1,   106,     1,    50,     1,    40,    53,    42,    55,
      13,    14,    58,    14,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,   133,
      21,     0,    37,    36,    37,    39,    82,    40,    38,    37,
      36,    32,    36,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    36,   100,   101,   102,   103,   104,     1,
       1,   164,     3,     4,     5,     6,     7,   170,     9,    37,
      37,    13,    14,    14,    99,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      36,     1,    36,     6,    36,    37,    39,    38,    40,    40,
      16,    36,    14,    13,    14,    19,    17,    38,     1,    18,
     135,     1,     3,     4,     5,     6,     7,    20,     9,    21,
      13,    14,    10,    14,     8,   150,    36,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,     1,    36,     1,    38,    38,    37,    14,    40,
      40,    13,    39,   135,    12,    40,    13,    14,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,     1,   156,   157,    39,    41,    37,    36,
       1,    40,     3,     4,     5,    39,    41,    11,    11,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,     1,    40,    40,   157,     0,    37,
     149,    -1,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,     1,    -1,    -1,    -1,    -1,
      37,    -1,    -1,    40,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,     1,    -1,    -1,    -1,
      -1,    37,    -1,    -1,    40,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,     1,    -1,    -1,
      -1,    -1,    37,    -1,    -1,    40,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,     1,    -1,
      -1,    -1,    -1,    37,    -1,    -1,    40,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,     1,
      -1,    -1,    -1,    -1,    37,    -1,    -1,    40,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
       1,    -1,    -1,    -1,    -1,    37,    -1,    -1,    40,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,     1,    -1,    -1,    -1,    -1,    37,    -1,    -1,    40,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,     1,    -1,    -1,    -1,    -1,    37,    -1,    -1,
      40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,     1,    -1,    -1,    -1,    -1,    37,    -1,
      -1,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,     1,    -1,    -1,    -1,    -1,    37,
      -1,    -1,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,     1,    -1,    -1,    -1,    -1,
      37,    -1,    -1,    40,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,     1,    -1,    -1,    -1,
      -1,    37,    -1,    -1,    40,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,     1,    -1,    -1,
      -1,    -1,    37,    -1,    -1,    40,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,     1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    40,    -1,    -1,    -1,
      13,    14,    -1,    -1,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,     1,
      -1,    -1,    -1,    36,    37,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
       1,    -1,    -1,    -1,    -1,    37,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,     1,    -1,    -1,    -1,    -1,    37,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,     1,    -1,    -1,    -1,    -1,    37,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,     1,    -1,    -1,    -1,    -1,    37,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    -1,    -1,    -1,    -1,    -1,    37
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     3,     4,     5,    44,    94,    14,     0,     1,
      14,    36,    36,     1,    36,    37,    37,    37,     1,    37,
       1,    38,    45,    45,    45,    45,    45,     7,     9,    14,
      40,    46,    47,    64,    68,    81,    82,    85,    90,    94,
      46,    36,    36,    91,    39,    46,     6,    86,     1,    39,
       1,    13,    14,    36,    48,     1,    48,    16,    36,    14,
      48,    48,     1,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    37,    59,    60,    61,    62,    63,    37,
       1,    37,    92,    48,    87,    37,     1,    37,    48,    54,
      53,    50,    52,    49,    51,    55,    56,    57,    58,    65,
      17,    18,    19,    20,    21,    38,    38,    69,    48,    37,
      40,    42,    88,    48,    48,    48,    48,    48,    48,    48,
      48,    48,    48,    45,    48,    48,    48,    48,    48,    10,
      70,    71,    70,    38,    93,    83,    14,     8,    66,    13,
      39,    12,    76,    39,    70,    40,    45,    47,    84,    89,
      67,    72,    77,    39,    88,    45,    41,    41,    45,    47,
      80,    80,    11,    73,    75,    11,    78,    74,    71,    79,
      40,    40,    71
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    43,    44,    44,    44,    44,    44,    45,    45,    45,
      46,    46,    47,    47,    47,    47,    47,    47,    49,    48,
      50,    48,    51,    48,    52,    48,    53,    48,    54,    48,
      55,    48,    56,    48,    57,    48,    58,    48,    59,    48,
      60,    48,    61,    48,    62,    48,    63,    48,    48,    48,
      48,    48,    48,    48,    48,    65,    64,    67,    66,    66,
      69,    68,    68,    68,    70,    70,    72,    71,    71,    74,
      73,    75,    73,    77,    76,    79,    78,    78,    80,    80,
      82,    83,    81,    84,    84,    86,    87,    85,    88,    89,
      88,    91,    92,    93,    90,    94,    94,    94
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     5,     5,     5,     5,     5,     3,     3,     3,
       2,     0,     1,     1,     1,     1,     1,     1,     0,     4,
       0,     4,     0,     4,     0,     4,     0,     4,     0,     4,
       0,     4,     0,     4,     0,     4,     0,     4,     0,     4,
       0,     4,     0,     4,     0,     4,     0,     4,     3,     3,
       3,     3,     1,     1,     1,     0,     7,     0,     3,     0,
       0,     8,     7,     7,     1,     2,     0,     6,     0,     0,
       4,     0,     2,     0,     5,     0,     3,     0,     1,     1,
       0,     0,     7,     1,     1,     0,     0,     5,     1,     0,
       4,     0,     0,     0,     7,     1,     1,     1
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
#line 68 "ccode.y" /* yacc.c:1646  */
    { printf("Analizando programa...\n");}
#line 1550 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 69 "ccode.y" /* yacc.c:1646  */
    { yyerror("ID inesperado, se esperaba void o  int"); }
#line 1556 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 70 "ccode.y" /* yacc.c:1646  */
    { yyerror("Se esperaba ID"); }
#line 1562 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 71 "ccode.y" /* yacc.c:1646  */
    { yyerror("Falta ("); }
#line 1568 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 72 "ccode.y" /* yacc.c:1646  */
    { yyerror("Falta )"); }
#line 1574 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 76 "ccode.y" /* yacc.c:1646  */
    { yyerror("Falta {"); }
#line 1580 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 77 "ccode.y" /* yacc.c:1646  */
    { yyerror("Falta }"); }
#line 1586 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 99 "ccode.y" /* yacc.c:1646  */
    {push();}
#line 1592 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 99 "ccode.y" /* yacc.c:1646  */
    {codegen_logical();}
#line 1598 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 100 "ccode.y" /* yacc.c:1646  */
    {push();}
#line 1604 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 100 "ccode.y" /* yacc.c:1646  */
    {codegen_logical();}
#line 1610 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 101 "ccode.y" /* yacc.c:1646  */
    {push();}
#line 1616 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 101 "ccode.y" /* yacc.c:1646  */
    {codegen_logical();}
#line 1622 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 102 "ccode.y" /* yacc.c:1646  */
    {push();}
#line 1628 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 102 "ccode.y" /* yacc.c:1646  */
    {codegen_logical();}
#line 1634 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 103 "ccode.y" /* yacc.c:1646  */
    {push();}
#line 1640 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 103 "ccode.y" /* yacc.c:1646  */
    {codegen_logical();}
#line 1646 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 104 "ccode.y" /* yacc.c:1646  */
    {push();}
#line 1652 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 104 "ccode.y" /* yacc.c:1646  */
    {codegen_logical();}
#line 1658 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 105 "ccode.y" /* yacc.c:1646  */
    {push();}
#line 1664 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 105 "ccode.y" /* yacc.c:1646  */
    {codegen_algebric();}
#line 1670 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 106 "ccode.y" /* yacc.c:1646  */
    {push();}
#line 1676 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 106 "ccode.y" /* yacc.c:1646  */
    {codegen_algebric();}
#line 1682 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 107 "ccode.y" /* yacc.c:1646  */
    {push();}
#line 1688 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 107 "ccode.y" /* yacc.c:1646  */
    {codegen_algebric();}
#line 1694 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 108 "ccode.y" /* yacc.c:1646  */
    {push();}
#line 1700 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 108 "ccode.y" /* yacc.c:1646  */
    {codegen_algebric();}
#line 1706 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 109 "ccode.y" /* yacc.c:1646  */
    {push();}
#line 1712 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 109 "ccode.y" /* yacc.c:1646  */
    {codegen_logical();}
#line 1718 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 110 "ccode.y" /* yacc.c:1646  */
    {push();}
#line 1724 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 110 "ccode.y" /* yacc.c:1646  */
    {codegen_logical();}
#line 1730 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 111 "ccode.y" /* yacc.c:1646  */
    {push();}
#line 1736 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 111 "ccode.y" /* yacc.c:1646  */
    {codegen_logical();}
#line 1742 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 112 "ccode.y" /* yacc.c:1646  */
    {push();}
#line 1748 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 112 "ccode.y" /* yacc.c:1646  */
    {codegen_logical();}
#line 1754 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 113 "ccode.y" /* yacc.c:1646  */
    {push();}
#line 1760 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 113 "ccode.y" /* yacc.c:1646  */
    {codegen_logical();}
#line 1766 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 115 "ccode.y" /* yacc.c:1646  */
    { yyerror("Esperaba operador"); }
#line 1772 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 117 "ccode.y" /* yacc.c:1646  */
    { yyerror("Falta ("); }
#line 1778 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 118 "ccode.y" /* yacc.c:1646  */
    { yyerror("Falta )"); }
#line 1784 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 120 "ccode.y" /* yacc.c:1646  */
    {check();push();}
#line 1790 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 121 "ccode.y" /* yacc.c:1646  */
    {push();}
#line 1796 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 122 "ccode.y" /* yacc.c:1646  */
    { yyerror("Esperaba numero o ID"); }
#line 1802 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 127 "ccode.y" /* yacc.c:1646  */
    {if_label1();}
#line 1808 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 131 "ccode.y" /* yacc.c:1646  */
    {if_label2();}
#line 1814 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 131 "ccode.y" /* yacc.c:1646  */
    {if_label3();}
#line 1820 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 132 "ccode.y" /* yacc.c:1646  */
    {if_label3();}
#line 1826 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 136 "ccode.y" /* yacc.c:1646  */
    {switch_start();}
#line 1832 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 138 "ccode.y" /* yacc.c:1646  */
    { yyerror("Se esperaba )"); }
#line 1838 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 139 "ccode.y" /* yacc.c:1646  */
    { yyerror("Se esperaba exp"); }
#line 1844 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 142 "ccode.y" /* yacc.c:1646  */
    {switch_end();}
#line 1850 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 143 "ccode.y" /* yacc.c:1646  */
    {switch_end();}
#line 1856 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 147 "ccode.y" /* yacc.c:1646  */
    {switch_case();}
#line 1862 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 152 "ccode.y" /* yacc.c:1646  */
    {switch_break();}
#line 1868 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 153 "ccode.y" /* yacc.c:1646  */
    {switch_nobreak();}
#line 1874 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 157 "ccode.y" /* yacc.c:1646  */
    {switch_default();}
#line 1880 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 161 "ccode.y" /* yacc.c:1646  */
    {switch_break();}
#line 1886 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 173 "ccode.y" /* yacc.c:1646  */
    {while_start();}
#line 1892 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 173 "ccode.y" /* yacc.c:1646  */
    {while_rep();}
#line 1898 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 177 "ccode.y" /* yacc.c:1646  */
    {while_end();}
#line 1904 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 178 "ccode.y" /* yacc.c:1646  */
    {while_end();}
#line 1910 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 182 "ccode.y" /* yacc.c:1646  */
    {setType();}
#line 1916 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 182 "ccode.y" /* yacc.c:1646  */
    {STMT_DECLARE();}
#line 1922 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 188 "ccode.y" /* yacc.c:1646  */
    {STMT_DECLARE();}
#line 1928 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 193 "ccode.y" /* yacc.c:1646  */
    {check(); push();}
#line 1934 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 193 "ccode.y" /* yacc.c:1646  */
    {push();}
#line 1940 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 193 "ccode.y" /* yacc.c:1646  */
    {codegen_assign();}
#line 1946 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1950 "y.tab.c" /* yacc.c:1646  */
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
#line 203 "ccode.y" /* yacc.c:1906  */


#include <ctype.h>
#include"lex.yy.c"
int count=0;

char st[1000][10]; //stack para guardar nodos
int top=0;
int i=0;
char temp[2]="t";

int label[200]; //para guardar etiquetas
int lnum=0;
int ltop=0;
int switch_stack[1000];
int stop=0;
char type[10];
int numtemps = 0;

struct Table
{
	char id[20];
	char type[10];
}table[10000]; //tabla de simbolos

int tableCount=0;

int huboError = 0; //0 falso, 1 true

void validar_entrada(int argc, char *argv[])
{
	if (argc != 2){
		printf("------Mini compilador de lenguaje C------\n");
		printf("Error en cantidad de argumentos al usar el comando\n");
		printf("Para correr este programa debe primero usar el comando ./programa3 ");
		printf("y luego pasar el nombre del archivo con la extension .c\n");
		exit(0);
	}else{

		yyin = fopen(argv[1], "r");
		if (yyin)
		{
			f1 = fopen("output","w");
			f2 = fopen("salida.asm","w");
			inicio_codigo();
			if (!yyparse())
			{
				printf("Parsing completado\n");
			}else
			{
				printf("Parsing fallado\n");
				exit(0);
			}
			generarVariables();
			final_codigo();			
			fclose(yyin);
			fclose(f1);
			//intermediateCode(); //esto hace print del archivo output
			fclose(f2);
		}else
		{
			printf("Error al abrir el archivo\n");
			huboError = 1;
		}	
	}


}

int main(int argc, char *argv[])
{
	validar_entrada(argc, argv);
	
    	return 0;
}
         
void yyerror(const char *s) {
	printf("%s Error en linea: %s%d%s : %s culpable: %s%s%s\n",red,cyan,yylineno,none,s,cyan,yytext,none);
	huboError = 1;
}

//funcion que hace push en el stack
void push()
{
  	strcpy(st[++top],yytext);
}

void codegen_logical()
{
 	sprintf(temp,"$t%d",i);
  	fprintf(f1,"%s\t=\t%s\t%s\t%s\n",temp,st[top-2],st[top-1],st[top]);
	//ensamblador
	char* operador = st[top-1];
        char* op1= st[top-2]; char* op2= st[top];
	int num1 = string_to_num(op1); int num2 = string_to_num(op2);
	if(strcmp(operador,"<") == 0){  
		// op1 - op2 		si da positivo = 0      si da negativo = 1 
		if(num1 == 1 && num2 ==1){  
			int resultado = op1 < op2;
			fprintf(f2,"\tmov [%s],%d ",temp,resultado);
		}else{
			if(!isdigit(num1) && !isdigit(num2)){ //op1 y op2 son variables
				fprintf(f2,"\tmov rax,[%s]   ;Inicio <\n",op1);
				fprintf(f2,"\tmov rbx,[%s]\n",op2);
				fprintf(f2,"\tsub rax,rbx\n");
				fprintf(f2,"\tmov rcx,0\n");
				fprintf(f2,"\tmov rdx,1\n");
				fprintf(f2,"\tcmovae rax,rcx \n \tcmovb rax,rdx\n");
				fprintf(f2,"\tmov [%s],rax \n\n",temp);
			}
			else if(!isdigit(num1)){ //op1 es var	
				fprintf(f2,"\tmov rax,[%s]   ;Inicio <\n",op1);
				fprintf(f2,"\tmov rbx,%s\n",op2);
				fprintf(f2,"\tsub rax,rbx\n");
				fprintf(f2,"\tmov rcx,0\n");
				fprintf(f2,"\tmov rdx,1\n");
				fprintf(f2,"\tcmovae rax,rcx \n \tcmovb rax,rdx\n");
				fprintf(f2,"\tmov [%s],rax \n\n",temp);		
			}
			else if(isdigit(num1)){ //op2 es var
				fprintf(f2,"\tmov rax,%s   ;Inicio <\n",op1);
				fprintf(f2,"\tmov rbx,[%s]\n",op2);
				fprintf(f2,"\tsub rax,rbx\n");
				fprintf(f2,"\tmov rcx,0\n");
				fprintf(f2,"\tmov rdx,1\n");
				fprintf(f2,"\tcmovae rax,rcx \n \tcmovb rax,rdx\n");
				fprintf(f2,"\tmov [%s],rax \n\n",temp);
			}
		}
	}
	if(strcmp(operador,"<=") == 0){
		if(num1 == 1 && num2 ==1){  
			int resultado = op1 <= op2;
			fprintf(f2,"\tmov [%s],%d ",temp,resultado);
		}else{
			if(!isdigit(num1) && !isdigit(num2)){ //op1 y op2 son variables
				fprintf(f2,"\tmov rax,[%s]   ;Inicio <=\n",op1);
				fprintf(f2,"\tmov rbx,[%s]\n",op2);
				fprintf(f2,"\tsub rax,rbx\n");
				fprintf(f2,"\tmov rcx,0\n");
				fprintf(f2,"\tmov rdx,1\n");
				fprintf(f2,"\tcmovbe rax,rdx \n \tcmova rax,rcx\n");
				fprintf(f2,"\tmov [%s],rax \n\n",temp);
			}
			else if(!isdigit(num1)){ //op1 es var	
				fprintf(f2,"\tmov rax,[%s]   ;Inicio <=\n",op1);
				fprintf(f2,"\tmov rbx,%s\n",op2);
				fprintf(f2,"\tsub rax,rbx\n");
				fprintf(f2,"\tmov rcx,0\n");
				fprintf(f2,"\tmov rdx,1\n");
				fprintf(f2,"\tcmovbe rax,rdx \n \tcmova rax,rcx\n");
				fprintf(f2,"\tmov [%s],rax \n\n",temp);		
			}
			else if(isdigit(num1)){ //op2 es var
				fprintf(f2,"\tmov rax,%s   ;Inicio <=\n",op1);
				fprintf(f2,"\tmov rbx,[%s]\n",op2);
				fprintf(f2,"\tsub rax,rbx\n");
				fprintf(f2,"\tmov rcx,0\n");
				fprintf(f2,"\tmov rdx,1\n");
				fprintf(f2,"\tcmovbe rax,rdx \n \tcmova rax,rcx \n");
				fprintf(f2,"\tmov [%s],rax \n\n",temp);
			}
		}
	}
	if(strcmp(operador,">") == 0){
		// op1 - op2 		si da negativo = 0      si da positivo = 1 
		if(num1 == 1 && num2 ==1){  
			int resultado = op1 > op2;
			fprintf(f2,"\tmov [%s],%d ",temp,resultado);
		}else{
			if(!isdigit(num1) && !isdigit(num2)){ //op1 y op2 son variables
				fprintf(f2,"\tmov rax,[%s]   ;Inicio >\n",op1);
				fprintf(f2,"\tmov rbx,[%s]\n",op2);
				fprintf(f2,"\tsub rax,rbx\n");
				fprintf(f2,"\tmov rcx,0\n");
				fprintf(f2,"\tmov rdx,1\n");
				fprintf(f2,"\tcmova rax,rdx \n \t cmovbe rax,rcx\n");
				fprintf(f2,"\tmov [%s],rax \n\n",temp);
			}
			else if(!isdigit(num1)){ //op1 es var	
				fprintf(f2,"\tmov rax,[%s]   ;Inicio >\n",op1);
				fprintf(f2,"\tmov rbx,%s\n",op2);
				fprintf(f2,"\tsub rax,rbx\n");
				fprintf(f2,"\tmov rcx,0\n");
				fprintf(f2,"\tmov rdx,1\n");
				fprintf(f2,"\tcmova rax,rdx \n \t cmovbe rax,rcx\n");
				fprintf(f2,"\tmov [%s],rax \n\n",temp);		
			}
			else if(isdigit(num1)){ //op2 es var
				fprintf(f2,"\tmov rax,%s   ;Inicio >\n",op1);
				fprintf(f2,"\tmov rbx,[%s]\n",op2);
				fprintf(f2,"\tsub rax,rbx\n");
				fprintf(f2,"\tmov rcx,0\n");
				fprintf(f2,"\tmov rdx,1\n");
				fprintf(f2,"\tcmova rax,rdx \n \t cmovbe rax,rcx\n");
				fprintf(f2,"\tmov [%s],rax\n\n ",temp);
			}
		}
	}
	if(strcmp(operador,">=") == 0){
		if(num1 == 1 && num2 ==1){  
			int resultado = op1 <= op2;
			fprintf(f2,"\tmov [%s],%d ",temp,resultado);
		}else{
			if(!isdigit(num1) && !isdigit(num2)){ //op1 y op2 son variables
				fprintf(f2,"\tmov rax,[%s]   ;Inicio >=\n",op1);
				fprintf(f2,"\tmov rbx,[%s]\n",op2);
				fprintf(f2,"\tsub rax,rbx\n");
				fprintf(f2,"\tmov rcx,0\n");
				fprintf(f2,"\tmov rdx,1\n");
				fprintf(f2,"\tcmovae rax,rdx \n \t cmovb rax,rcx\n");
				fprintf(f2,"\tmov [%s],rax\n\n ",temp);
			}
			else if(!isdigit(num1)){ //op1 es var	
				fprintf(f2,"\tmov rax,[%s]   ;Inicio >=\n",op1);
				fprintf(f2,"\tmov rbx,%s\n",op2);
				fprintf(f2,"\tsub rax,rbx\n");
				fprintf(f2,"\tmov rcx,0\n");
				fprintf(f2,"\tmov rdx,1\n");
				fprintf(f2,"\tcmovae rax,rdx \n \t cmovb rax,rcx\n");
				fprintf(f2,"\tmov [%s],rax \n\n",temp);		
			}
			else if(isdigit(num1)){ //op2 es var
				fprintf(f2,"\tmov rax,%s   ;Inicio >=\n",op1);
				fprintf(f2,"\tmov rbx,[%s]\n",op2);
				fprintf(f2,"\tsub rax,rbx\n");
				fprintf(f2,"\tmov rcx,0\n");
				fprintf(f2,"\tmov rdx,1\n");
				fprintf(f2,"\tcmovae rax,rdx \n \t cmovb rax,rcx\n");
				fprintf(f2,"\tmov [%s],rax \n\n",temp);
			}
		}
	}
	if(strcmp(operador,"&&") == 0){
		if(num1 == 1 && num2 ==1){  
			int resultado = op1 && op2;
			fprintf(f2,"\tmov [%s],%d ",temp,resultado);
		}else{
			if(!isdigit(num1) && !isdigit(num2)){ //op1 y op2 son variables
				fprintf(f2,"\tmov rax,[%s]  ;  Inicio &&\n",op1);
				fprintf(f2,"\tmov rbx,[%s]\n",op2);
				fprintf(f2,"\tAND rax,rbx\n");
				fprintf(f2,"\tmov [%s],rax \n\n",temp);	
			}
			else if(!isdigit(num1)){ //op1 es var	
				fprintf(f2,"\tmov rax,[%s]  ;  Inicio &&\n",op1);
				fprintf(f2,"\tmov rbx,%s\n",op2);
				fprintf(f2,"\tAND rax,rbx\n");
				fprintf(f2,"\tmov [%s],rax \n\n",temp);		
			}
			else if(isdigit(num1)){ //op2 es var
				fprintf(f2,"\tmov rax,%s  ;  Inicio &&\n",op1);
				fprintf(f2,"\tmov rbx,[%s]\n",op2);
				fprintf(f2,"\tAND rax,rbx\n");
				fprintf(f2,"\tmov [%s],rax \n\n",temp);
			}
		}
	}
	if(strcmp(operador,"||") == 0){
		if(num1 == 1 && num2 ==1){  
			int resultado = op1 || op2;
			fprintf(f2,"\tmov [%s],%d ",temp,resultado);
		}else{
			if(!isdigit(num1) && !isdigit(num2)){ //op1 y op2 son variables
				fprintf(f2,"\tmov rax,[%s]  ;  Inicio ||\n",op1);
				fprintf(f2,"\tmov rbx,[%s]\n",op2);
				fprintf(f2,"\tOR rax,rbx\n");
				fprintf(f2,"\tmov [%s],rax\n\n",temp);	
			}
			else if(!isdigit(num1)){ //op1 es var	
				fprintf(f2,"\tmov rax,[%s]  ;  Inicio ||\n",op1);
				fprintf(f2,"\tmov rbx,%s\n",op2);
				fprintf(f2,"\tOR rax,rbx\n");
				fprintf(f2,"\tmov [%s],rax\n\n",temp);		
			}
			else if(isdigit(num1)){ //op2 es var
				fprintf(f2,"\tmov rax,%s  ;  Inicio ||\n",op1);
				fprintf(f2,"\tmov rbx,[%s]\n",op2);
				fprintf(f2,"\tOR rax,rbx\n");
				fprintf(f2,"\tmov [%s],rax\n \n",temp);
			}
		}
	}
	if(numtemps < temp[2]-48){ numtemps = temp[2]-48;} //contador temps
  	top-=2;
 	strcpy(st[top],temp);
 	i++;
}

void codegen_algebric()
{
 	sprintf(temp,"$t%d",i); // converts temp to reqd format
	char* operador = st[top-1];
        char* op1= st[top-2]; char* op2= st[top];
	int num1 = string_to_num(op1); int num2 = string_to_num(op2);
        //ensamblador
	if(strcmp(operador,"+") == 0){
	   if(num1 == 1 && num2 ==1){
		int resultado = atoi(op1) + atoi(op2);
           	//printf("Resultado de suma: %d \n",resultado);
  	        fprintf(f1,"%s\t=\t%d\n",temp,resultado);
		//hacer asignacion
		fprintf(f2,"%s %d %s \n","\tmov rax, ", resultado , "; Inicio asignacion");
		fprintf(f2,"%s%s%s \n\n","\tmov [",temp,"], rax");
		
	   }else{  	
		fprintf(f1,"%s\t=\t%s\t%s\t%s\n",temp,st[top-2],st[top-1],st[top]);
		//hacer suma
		if(!isdigit(num1) && !isdigit(num2)){ //op1 y op2 son variables
			fprintf(f2,"%s%s%s  %s \n","\tmov rax, [",op1,"]","; Inicio suma");
			fprintf(f2,"\tmov rbx, [%s]\n",op2);
			fprintf(f2,"%s \n\n","\tadd rax,rbx");
		}
		else if(!isdigit(num1)){ //op1 es var
			fprintf(f2,"%s%s%s  %s \n","\tmov rax, [",op1,"]","; Inicio suma");
			fprintf(f2,"%s %s  \n","\tmov rbx, ",op2);
			fprintf(f2,"%s \n\n","\tadd rax,rbx");		
		} 
		else if(isdigit(num1)){ //op2 es var
			fprintf(f2,"%s%s%s  %s \n","\tmov rax, [",op2,"]","; Inicio suma");
			fprintf(f2,"%s %s  \n","\tmov rbx, ",op1);
			fprintf(f2,"%s \n\n","\tadd rax,rbx");		
 		}
		// hacer asignacion
		fprintf(f2,"%s%s%s   %s\n\n","\tmov [",temp,"], rax","; Inicio asignacion");
		}
		
	}
	if(strcmp(operador,"*") == 0){
	   if(num1 == 1 && num2 ==1){
		int resultado = atoi(op1) * atoi(op2);
           	//printf("Resultado de mult: %d \n",resultado);
		fprintf(f1,"%s\t=\t%d\n",temp,resultado);
		//hacer asignacion
		fprintf(f2,"%s %d %s \n","\tmov rax, ", resultado , "; Inicio asignacion");
		fprintf(f2,"%s%s%s \n\n","\tmov [",temp,"], rax");
	   }else{  	
		fprintf(f1,"%s\t=\t%s\t%s\t%s\n",temp,st[top-2],st[top-1],st[top]);
		//hacer mul
		if(!isdigit(num1) && !isdigit(num2)){ //op1 y op2 son variables
			fprintf(f2,"%s%s%s  %s \n","\tmov rax, [",op1,"]","; Inicio mul");
			fprintf(f2,"%s%s%s \n","\tmov rbx, [",op2,"]");
			fprintf(f2,"%s \n\n","\tmul rax,rbx");
		}
		else if(!isdigit(num1)){ //op1 es var
			fprintf(f2,"%s%s%s  %s \n","\tmov rax, [",op1,"]","; Inicio mul");
			fprintf(f2,"%s %s  \n","\tmov rbx, ",op2);
			fprintf(f2,"%s \n\n","\tmul rax,rbx");		
		} 
		else if(isdigit(num1)){ //op2 es var
			fprintf(f2,"%s%s%s  %s \n","\tmov rax, [",op2,"]","; Inicio mul");
			fprintf(f2,"%s %s  \n","\tmov rbx, ",op1);
			fprintf(f2,"%s \n\n","\tmul rax,rbx");		
 		}

		// hacer asignacion
		fprintf(f2,"%s%s%s %s\n\n","\tmov [",temp,"], rax","; Inicio asignacion ");
		}
	}

	if(strcmp(operador,"-") == 0){
	   if(num1 == 1 && num2 ==1){
		int resultado = atoi(op1) - atoi(op2);
           	//printf("Resultado de resta: %d \n",resultado);
		fprintf(f1,"%s\t=\t%d\n",temp,resultado);
		//hacer asignacion
		fprintf(f2,"%s %d %s \n","\tmov rax, ", resultado , "; Inicio asignacion ");
		fprintf(f2,"%s%s%s \n\n","\tmov [",temp,"], rax");
	   }else{ 
 		fprintf(f1,"%s\t=\t%s\t%s\t%s\n",temp,st[top-2],st[top-1],st[top]);
		//hacer resta
		if(!isdigit(num1) && !isdigit(num2)){ //op1 y op2 son variables
			fprintf(f2,"%s%s%s  %s \n","\tmov rax, [",op1,"]","; Inicio resta");
			fprintf(f2,"%s %s %s \n","\tmov rbx, [",op2,"]");
			fprintf(f2,"%s \n\n","\tsub rax,rbx");
		}
		else if(!isdigit(num1)){ //op1 es var
			fprintf(f2,"%s%s%s  %s \n","\tmov rax, [",op1,"]","; Inicio resta");
			fprintf(f2,"%s %s  \n","\tmov rbx, ",op2);
			fprintf(f2,"%s \n\n","\tsub rax,rbx");		
		} 
		else if(isdigit(num1)){ //op2 es var
			fprintf(f2,"%s%s%s  %s \n","\tmov rax, [",op2,"]","; Inicio resta");
			fprintf(f2,"%s %s  \n","\tmov rbx, ",op1);
			fprintf(f2,"%s \n\n","\tsub rax,rbx");		
 		}

		// hacer asignacion
		fprintf(f2,"%s%s%s   %s\n\n","\tmov [",temp,"], rax","; Inicio asignacion ");
		}
	
	}

	if(strcmp(operador,"/") == 0){
	   if(num1 == 1 && num2 ==1){
		int resultado = atoi(op1) / atoi(op2);
           	//printf("Resultado de division: %d \n",resultado);
		fprintf(f1,"%s\t=\t%d\n",temp,resultado);
		//hacer asignacion
		fprintf(f2,"%s %d %s \n","\tmov rax, ", resultado , "; Inicio asignacion ");
		fprintf(f2,"%s%s%s \n\n","\tmov [",temp,"], rax");
	   }else{  	
		fprintf(f1,"%s\t=\t%s\t%s\t%s\n",temp,st[top-2],st[top-1],st[top]);
		if(!isdigit(num1) && !isdigit(num2)){ //op1 y op2 son variables
			fprintf(f2,"%s %s \n","\txor rdx,rdx","; Inicio div");
			fprintf(f2,"%s %s  \n","\tmov rax,",op1);
			fprintf(f2,"%s %s \n","\tmov rcx,",op2);
			fprintf(f2,"%s\n","\tidiv rcx");
			fprintf(f2,"%s%s%s\n\n","\tmov [",temp,"],rax");
		}
		else if(!isdigit(num1)){ //op1 es var
			fprintf(f2,"%s %s \n","\txor rdx,rdx","; Inicio div");
			fprintf(f2,"%s%s%s \n","\tmov rax, [",op1,"]");
			fprintf(f2,"%s %s\n","\tmov rcx,",op2);
			fprintf(f2,"%s\n","\tidiv rcx");
			fprintf(f2,"%s%s%s \n\n","\tmov [",temp,"],rax");			
		} 
		else if(isdigit(num1)){ //op2 es var	
			fprintf(f2,"%s %s \n","\txor rdx,rdx","; Inicio div");
			fprintf(f2,"%s %s  \n","\tmov rax,",op1);
			fprintf(f2,"%s%s%s\n","\tmov rcx, [",op2,"]");
			fprintf(f2,"%s\n","\tidiv rcx");
			fprintf(f2,"%s%s%s\n\n","\tmov [",temp,"],rax");		
 		}

		// hacer asignacion
		fprintf(f2,"%s%s%s   %s\n\n","\tmov [",temp,"], rax","; Inicio asignacion ");
		}
	}
	if(numtemps < temp[2]-48){ numtemps = temp[2]-48;}	//contador temps
  	top-=2;
 	strcpy(st[top],temp);
 	i++;
}


int string_to_num(char* op1){
	int length = strlen(op1);
	for(int y=0;y<length;y++){
		if(!isdigit(op1[y])){
			//es una var
			return 0;
		   }
	}
	return 1; //es un num
}

void codegen_assign()
{
 	fprintf(f1,"%s\t=\t%s\n",st[top-2],st[top]);
	//ensamblador
	char* op = st[top];
	int num1 = string_to_num(op); 
	if(num1 == 1){ //es un num
		fprintf(f2,"\tmov rax, %s ;\n",op);
		fprintf(f2,"\tmov [%s],rax ; Inicio asignacion\n\n",st[top-2]);
	}
	else{
		fprintf(f2,"\tmov rax, [%s] ;\n",op);
		fprintf(f2,"\tmov [%s],rax ; Inicio asignacion\n\n",st[top-2]);
	}
 	top-=3;
}
 
void if_label1()
{
 	lnum++;
 	fprintf(f1,"\tif( not %s)",st[top]);
 	fprintf(f1,"\tgoto $L%d\n",lnum);
	//ensamblador
	fprintf(f2,"\tmov rax,[%s]    ;Inicio if \n",st[top]);
	fprintf(f2,"\tmov rbx, 1 \n");
	fprintf(f2,"\tcmp rax,rbx \n");
	fprintf(f2,"\tjne $L%d \n",lnum);

 	label[++ltop]=lnum;
}

void if_label2()
{
	int x;
	lnum++;
	x=label[ltop--]; 
	fprintf(f1,"\t\tgoto $L%d\n",lnum);
	fprintf(f1,"$L%d: \n",x); 
	//ensamblador
	fprintf(f2,"\tjmp $L%d\n",lnum);
	fprintf(f2,"$L%d: \n",x); 

	label[++ltop]=lnum;
}

void if_label3()
{
	int y;
	y=label[ltop--];
	fprintf(f1,"$L%d: \n",y);
	//ensamblador
	fprintf(f2,"$L%d: \n",y);

	top--;
}
void while_start()
{
	lnum++;
	label[++ltop]=lnum;
	fprintf(f1,"$L%d:\n",lnum);
	//ensamblador
	fprintf(f2,"$L%d:    %s\n",lnum,"; Ciclo while");
}
void while_rep()
{
	lnum++;
 	fprintf(f1,"if( not %s)",st[top]);
 	fprintf(f1,"\tgoto $L%d\n",lnum);
	//ensamblador
	fprintf(f2,"\tmov rax,[%s]     ;Ver si cumple condicion \n",st[top]);
	fprintf(f2,"\tcmp rax,0\n");
	fprintf(f2,"\tjne $L%d\n\n",lnum);
 	label[++ltop]=lnum;
}
void while_end()
{
	int x,y;
	y=label[ltop--];
	x=label[ltop--];
	fprintf(f1,"\t\tgoto $L%d\n",x);
	fprintf(f1,"$L%d: \n",y);
	//ensamblador
	fprintf(f2,"\tjmp $L%d\n",x);
	fprintf(f2,"$L%d: \n",y);
	top--;
}
void switch_start()
{
	lnum++;
	label[++ltop]=lnum;
	lnum++;
	label[++ltop]=lnum;
	switch_stack[++stop]=1;
	fprintf(f2,"; 	Inicio de switch\n");
}
void switch_case()
{
	int x,y,z;
	z=switch_stack[stop--];
	if(z==1)
	{
		x=label[ltop--];
	}
	else if(z==2)
	{
		y=label[ltop--];
		x=label[ltop--];
	}
	fprintf(f1,"$L%d:\n",x);
	//ensamblador
	fprintf(f2,"$L%d:\n",x);

	lnum++;
	label[++ltop]=lnum;
 	fprintf(f1,"if(%s != %s)",st[top],yytext);
 	fprintf(f1,"\tgoto $L%d\n",label[ltop]);
	//ensamblador
	fprintf(f2,"\tmov rax,[%s]\n",st[top]);
	fprintf(f2,"\tmov rbx,%s\n",yytext);
	fprintf(f2,"\tcmp rax,rbx\n");
	fprintf(f2,"\tjne $L%d\n",label[ltop]);
	
 	if(z==2)
 	{
 		fprintf(f1,"$L%d:\n",y);
		//ensamblador
		fprintf(f2,"$L%d:\n",y);
 	}
}
void switch_default()
{
	int x=label[ltop--];
	fprintf(f1,"$L%d:\n",x);
	lnum++;
	label[++ltop]=lnum;
}
void switch_break()
{
	switch_stack[++stop]=1;
	fprintf(f1,"\t\tgoto $L%d\n",label[ltop-1]);
	//ensamblador
	fprintf(f2,"\tjmp $L%d\n",label[ltop-1]);	
}
void switch_nobreak()
{
	switch_stack[++stop]=2;
	lnum++;
	label[++ltop]=lnum;
	fprintf(f1,"\t\tgoto $L%d\n",label[ltop]);
	//ensamblador
	fprintf(f2,"\tjmp $L%d\n",label[ltop]);
}
void switch_end()
{
	int x=label[ltop--];
	fprintf(f1,"$L%d:\n",x);
	//ensamblador
	fprintf(f2,"$L%d:\n",x);

	x=label[ltop--];
	fprintf(f1,"$L%d:\n",x);
	//ensamblador
	fprintf(f2,"$L%d:\n",x);
	fprintf(f2,";    Termino switch \n");
	top--;
	stop--;
}


/* verificar si una variable ya esta definida*/

void check()
{
	char temp[20];
	strcpy(temp,yytext);
	int flag=0;
	for(i=0;i<tableCount;i++)
	{
		if(!strcmp(table[i].id,temp))
		{
			flag=1;
			break;
		}
	}
	if(!flag)
	{
		yyerror("Variable no declarada");
		STMT_DECLARE();
		
	}
}

void setType()
{
	strcpy(type,yytext);
}


/*verifica si variable declarada ya ha sido dclarada previamente*/
void STMT_DECLARE()
{
	char temp[20];
	int i,flag;
	flag=0;
	strcpy(temp,yytext);
	for(i=0;i<tableCount;i++)
	{
		if(!strcmp(table[i].id,temp))
			{
			flag=1;
			break;
				}
	}
	if(flag)
	{
		yyerror("Redeclaracion, ");
	}
	else
	{
		strcpy(table[tableCount].id,temp);
		strcpy(table[tableCount].type,type);
		tableCount++;
	}
}

void intermediateCode()
{
	int Labels[100000];
	char buf[100];
	f1=fopen("output","r");
	int flag=0,lineno=1;
	memset(Labels,0,sizeof(Labels));
	while(fgets(buf,sizeof(buf),f1)!=NULL)
	{
		//printf("%s",buf);
		if(buf[0]=='$'&&buf[1]=='$'&&buf[2]=='L')
		{
			int k=atoi(&buf[3]);
			//printf("hi %d\n",k);
			Labels[k]=lineno;
		}
		else
		{
			lineno++;
		}
	}
	fclose(f1);
	f1=fopen("output","r");
	lineno=0;

	//printf("\n\n\n*********************InterMediate Code***************************\n\n");
	while(fgets(buf,sizeof(buf),f1)!=NULL)
	{
		//printf("%s",buf);
		if(buf[0]=='$'&&buf[1]=='$'&&buf[2]=='L')
		{
			;
		}
		else
		{
			flag=0;
			lineno++;
			printf("%3d:\t",lineno);
			int len=strlen(buf),i,flag1=0;
			for(i=len-3;i>=0;i--)
			{
				if(buf[i]=='$'&&buf[i+1]=='$'&&buf[i+2]=='L')
				{
					flag1=1;
					break;
				}
			}
			if(flag1)
			{
				buf[i]=='\0';
				int k=atoi(&buf[i+3]),j;
				//printf("%s",buf);
				for(j=0;j<i;j++)
					printf("%c",buf[j]);
				printf(" %d\n",Labels[k]);
			}
			else printf("%s",buf);
		}
	}
	printf("%3d:\tend\n",++lineno);
	fclose(f1);
}

void inicio_codigo()
{
	fprintf(f2,";=====Inicio de codigo=====\n");
	fprintf(f2,"section .text\n");
	fprintf(f2,"\tglobal _start\n\n");
	fprintf(f2,"_start:\n");
}

void final_codigo(){

	fprintf(f2,"\t;   cmovb =  mueve si a es menor que b \n");
	fprintf(f2,"\t;   cmovbe =  mueve si a es menor o igual que b \n");
	fprintf(f2,"\t;   cmovae =  mueve si a es mayor o igual que b \n");
	fprintf(f2,"\t;   cmova =  mueve si a es mayor que b \n");
}

void generarVariables()
{
	fprintf(f2,"section .data\n");
	int cant = 0;
	for (cant = 0; cant < tableCount; cant++){
		//printf("Variable: %s\n",table[cant].id);
		fprintf(f2,"\t%s dq 0\n", table[cant].id);	
	}
	fprintf(f2,"\n");

	for (cant = 0; cant <= numtemps; cant++)
	{
		fprintf(f2,"\t$t%d dq 0\n",cant);
	}
	fprintf(f2,"\n");
}


