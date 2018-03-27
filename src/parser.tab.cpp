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

#line 67 "src/parser.tab.cpp" /* yacc.c:339  */

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
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parser.tab.hpp".  */
#ifndef YY_YY_SRC_PARSER_TAB_HPP_INCLUDED
# define YY_YY_SRC_PARSER_TAB_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 1 "src/parser.y" /* yacc.c:355  */

  #include "ast.hpp"

  #include <cassert>

  extern const ASTNode *g_root; // A way of getting the AST out

  //! This is to fix problems when generating C++
  // We are declaring the functions provided by Flex, so
  // that Bison generated code can call them.
  int yylex(void);
  void yyerror(const char *);

#line 111 "src/parser.tab.cpp" /* yacc.c:355  */

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    T_LSQBRACKET = 258,
    T_RSQBRACKET = 259,
    T_LCUBRACKET = 260,
    T_RCUBRACKET = 261,
    T_LTRIBRACKET = 262,
    T_RTRIBRACKET = 263,
    T_LBRACKET = 264,
    T_RBRACKET = 265,
    T_ASSIGN = 266,
    T_DOT = 267,
    T_COMMA = 268,
    T_COLON = 269,
    T_QMARK = 270,
    T_SEMICOLON = 271,
    T_SPEACHMARK = 272,
    T_APOSTROPHE = 273,
    T_NOT = 274,
    T_AND = 275,
    T_OR = 276,
    T_MORE = 277,
    T_LESS = 278,
    T_XOR = 279,
    T_TILDA = 280,
    T_CHAR = 281,
    T_SIGN_CHAR = 282,
    T_UNSIGN_CHAR = 283,
    T_SHORT = 284,
    T_UNSIGN_SHORT = 285,
    T_INT = 286,
    T_UNSIGN_INT = 287,
    T_LONG = 288,
    T_UNSIGN_LONG = 289,
    T_LONGLONG = 290,
    T_UNSIGN_LONGLONG = 291,
    T_FLOAT = 292,
    T_DOUBLE = 293,
    T_LONGDOUBLE = 294,
    T_VOID = 295,
    T_TIMES = 296,
    T_DIVIDE = 297,
    T_PLUS = 298,
    T_MINUS = 299,
    T_MODULUS = 300,
    T_INC = 301,
    T_DEC = 302,
    T_ADDASSIGN = 303,
    T_SUBASSIGN = 304,
    T_MULASSIGN = 305,
    T_DIVASSIGN = 306,
    T_MODASSIGN = 307,
    T_LSHIFTASSIGN = 308,
    T_RSHIFTASSIGN = 309,
    T_ANDASSIGN = 310,
    T_XORASSIGN = 311,
    T_ORASSIGN = 312,
    T_LAND = 313,
    T_LOR = 314,
    T_LEQUAL = 315,
    T_LNEQUAL = 316,
    T_LLESSEQ = 317,
    T_LMOREEQ = 318,
    T_LSHIFT = 319,
    T_RSHIFT = 320,
    T_NUMBER = 321,
    T_ID = 322,
    T_COMMENT = 323,
    T_RETURN = 324,
    T_SIZE_OF = 325,
    T_ELSE = 326,
    T_IF = 327,
    T_ELIF = 328,
    T_WHILE = 329,
    T_DO = 330,
    T_FOR = 331
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 17 "src/parser.y" /* yacc.c:355  */

  const ASTNode *node;
  double number;
  std::string *string;

#line 206 "src/parser.tab.cpp" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SRC_PARSER_TAB_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 223 "src/parser.tab.cpp" /* yacc.c:358  */

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
#define YYFINAL  21
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   718

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  77
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  42
/* YYNRULES -- Number of rules.  */
#define YYNRULES  132
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  240

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   331

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
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    54,    54,    56,    57,    58,    59,    61,    63,    64,
      65,    67,    68,    69,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    87,
      88,    89,    91,    92,    93,    94,    95,    96,    97,    98,
     100,   101,   103,   104,   105,   106,   108,   110,   111,   113,
     115,   116,   118,   119,   121,   123,   124,   126,   127,   128,
     129,   130,   132,   133,   135,   136,   138,   141,   144,   148,
     151,   151,   154,   155,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   170,   171,   173,   174,
     176,   177,   179,   180,   182,   183,   185,   186,   188,   189,
     190,   192,   193,   194,   195,   196,   198,   199,   200,   202,
     203,   204,   206,   207,   208,   209,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   221,   222,   223,   224,   225,
     227,   228,   229
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_LSQBRACKET", "T_RSQBRACKET",
  "T_LCUBRACKET", "T_RCUBRACKET", "T_LTRIBRACKET", "T_RTRIBRACKET",
  "T_LBRACKET", "T_RBRACKET", "T_ASSIGN", "T_DOT", "T_COMMA", "T_COLON",
  "T_QMARK", "T_SEMICOLON", "T_SPEACHMARK", "T_APOSTROPHE", "T_NOT",
  "T_AND", "T_OR", "T_MORE", "T_LESS", "T_XOR", "T_TILDA", "T_CHAR",
  "T_SIGN_CHAR", "T_UNSIGN_CHAR", "T_SHORT", "T_UNSIGN_SHORT", "T_INT",
  "T_UNSIGN_INT", "T_LONG", "T_UNSIGN_LONG", "T_LONGLONG",
  "T_UNSIGN_LONGLONG", "T_FLOAT", "T_DOUBLE", "T_LONGDOUBLE", "T_VOID",
  "T_TIMES", "T_DIVIDE", "T_PLUS", "T_MINUS", "T_MODULUS", "T_INC",
  "T_DEC", "T_ADDASSIGN", "T_SUBASSIGN", "T_MULASSIGN", "T_DIVASSIGN",
  "T_MODASSIGN", "T_LSHIFTASSIGN", "T_RSHIFTASSIGN", "T_ANDASSIGN",
  "T_XORASSIGN", "T_ORASSIGN", "T_LAND", "T_LOR", "T_LEQUAL", "T_LNEQUAL",
  "T_LLESSEQ", "T_LMOREEQ", "T_LSHIFT", "T_RSHIFT", "T_NUMBER", "T_ID",
  "T_COMMENT", "T_RETURN", "T_SIZE_OF", "T_ELSE", "T_IF", "T_ELIF",
  "T_WHILE", "T_DO", "T_FOR", "$accept", "ROOT", "TOP_LIST",
  "DEC_FUNCTION", "ARGUMENT_LIST", "ARGUMENT_LIST_NO_TYPE", "TYPE", "BODY",
  "STATEMENT", "EXPR_STATEMENT", "FOR_STATEMENT", "NEW_SCOPE",
  "RETURN_STATEMENT", "DEC_STATEMENT", "DEC_VAR_LIST", "DEC_VARIABLE",
  "GLO_DEC_STATEMENT", "GLO_DEC_VAR_LIST", "GLO_DEC_VARIABLE",
  "IFANDORELSEORELIF", "IFANDORELIF", "WHILE_STATEMENT", "DO_STATEMENT",
  "IF_STATEMENT", "ELSE_IF_STATEMENT", "ELSE_STATEMENT", "EXPR_1",
  "EXPR_2", "EXPR_3", "EXPR_4", "EXPR_5", "EXPR_6", "EXPR_7", "EXPR_8",
  "EXPR_9", "EXPR_10", "EXPR_11", "EXPR_12", "EXPR_13", "EXPR_14",
  "EXPR_15", "PRIMATIVES", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331
};
# endif

#define YYPACT_NINF -82

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-82)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     654,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,
     -82,   -82,   -82,   -82,   -82,   -82,    23,   654,   -82,    -6,
     -82,   -82,   -82,   -82,    88,     9,   -82,   654,    34,    25,
     -82,    32,    48,   -26,    40,   -82,   111,   -82,   121,   654,
     -82,    68,   128,   -82,   547,    79,   153,   -82,   547,   601,
     -82,   632,   632,    46,    51,    93,   102,   -82,   661,    77,
      -8,   601,   601,   166,   171,   119,   183,   -82,   -82,   -82,
     -82,   -82,   -82,   -82,    91,   -82,   -82,   -82,    38,   -82,
     175,   134,   137,   184,   182,   187,   -50,   -15,   101,   109,
     -21,   -82,   -82,   -82,   -82,   -82,   235,    72,     3,   -82,
     -82,   158,   -82,   -82,   -82,   -82,   -82,   601,   601,   -82,
     -82,   601,   601,   601,   601,   601,   601,   601,   601,   601,
     601,   -82,    75,   654,   -82,     1,     4,   547,    37,   214,
     103,   -82,   -82,   -82,   223,   601,   -82,   -82,   601,   -82,
     601,   632,   632,   632,   632,   632,   632,   632,   632,   632,
     632,   632,   632,   632,   632,   632,   632,   632,   632,   -82,
     -82,   -82,   118,   -82,   -82,   -82,   -82,   -82,   -82,   -82,
     -82,   -82,   -82,   -82,   -82,   -82,   221,   547,   547,   287,
      89,    89,   601,   119,   -82,   547,    39,   -82,   161,   137,
     184,   182,   187,   -50,   -15,   -15,   101,   101,   101,   101,
     109,   109,   -21,   -21,   -82,   -82,   -82,   -82,   601,   -82,
     339,   391,   159,   586,   593,   -82,   -82,   443,   547,   632,
     -82,   -82,   -82,   601,   547,   132,   547,   144,   -82,   495,
     134,   145,   547,   547,   547,   547,   -82,   -82,   547,   547
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,     0,     2,     5,     0,
       6,     1,     3,     4,    61,     0,    55,    10,     0,     0,
      54,     0,     0,     0,     0,    57,    61,    56,     0,     0,
       9,     0,     0,    58,    31,     0,     0,    59,    31,     0,
      41,     0,     0,     0,     0,     0,     0,   131,   130,     0,
       0,     0,     0,     0,     0,     0,     0,    30,    34,    39,
      38,    32,    33,    35,    63,    36,    37,    65,     0,    72,
      74,    86,    88,    90,    92,    94,    96,    98,   101,   106,
     109,   112,   116,   125,     8,    60,     0,     0,   130,   119,
     120,     0,   123,   131,   124,   121,   122,    13,     0,   126,
     127,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    48,     0,     0,   117,     0,     0,    31,     0,    53,
       0,    50,     7,    29,     0,     0,    64,    62,     0,    40,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    46,
     129,   132,     0,    12,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    85,    84,    47,     0,    31,    31,     0,
       0,     0,     0,     0,    49,    31,     0,    73,     0,    89,
      91,    93,    95,    97,    99,   100,   102,   103,   105,   104,
     107,   108,   110,   111,   113,   114,   115,   128,     0,   118,
       0,     0,     0,     0,     0,    52,    51,     0,    31,     0,
      11,    68,    66,     0,    31,     0,    31,     0,    71,     0,
      87,     0,    45,    31,    44,    31,    69,    67,    43,    42
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -82,   -82,   -82,   215,   -82,   -82,     2,   -48,   -38,   -41,
     -82,   -82,   -82,   106,   -82,    52,   219,   -82,   208,   -82,
     -82,   -82,   -82,   -82,   -82,   -82,   -46,   -81,   -82,    19,
      98,   100,   104,    99,   131,    35,     0,    31,    43,   -47,
     150,   -82
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    16,    17,    18,    31,   162,    65,    66,    67,    68,
      69,    70,    71,    72,   130,   131,    20,    25,    26,    73,
      74,    75,    76,    77,   136,   137,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      96,   123,    19,    97,    99,   100,   177,   148,   149,   178,
     146,   147,   107,   122,   138,   125,   126,   138,    41,    19,
     156,   157,    29,    21,   158,    30,   163,   164,   133,    32,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
      42,    45,    38,    33,   218,    39,    49,   150,   151,   109,
     110,   138,   138,    50,   139,    49,    51,   187,   133,   124,
      49,    24,    52,     1,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    34,   179,
      53,    54,   160,    55,    56,   138,    49,   180,   138,   186,
     101,   175,    36,   121,   188,   101,    51,    27,    49,    28,
      35,   215,    52,    57,    58,    50,    43,    60,    51,   204,
     205,   206,    57,    98,    52,    40,   183,   103,    98,   184,
      53,    54,    28,    55,    56,   176,    44,   220,   207,   210,
     211,   208,    53,    54,    46,    55,    56,   217,    47,   213,
     214,   133,   233,    57,    58,   138,    94,    60,   196,   197,
     198,   199,   154,   155,   235,    57,    58,   138,   138,    60,
     105,   237,   134,    95,   135,   152,   153,   225,   227,   106,
     229,   127,   133,   133,   138,   219,   232,   231,   234,   133,
     128,   194,   195,   200,   201,   238,   129,   239,    48,   132,
     140,   133,    49,   141,   133,   142,   133,   202,   203,    50,
     133,   133,    51,   102,   104,   143,   144,   145,    52,     1,
       2,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,   161,   182,    53,    54,   185,    55,
      56,   209,    22,   223,   181,   216,    23,    37,   230,   189,
      48,   159,   190,   192,    49,     0,     0,   191,     0,    57,
      58,    50,    59,    60,    51,    61,     0,    62,    63,    64,
      52,     1,     2,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,   193,     0,    53,    54,
       0,    55,    56,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    48,   212,     0,     0,    49,     0,     0,     0,
       0,    57,    58,    50,    59,    60,    51,    61,     0,    62,
      63,    64,    52,     1,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,     0,     0,
      53,    54,     0,    55,    56,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    48,   221,     0,     0,    49,     0,
       0,     0,     0,    57,    58,    50,    59,    60,    51,    61,
       0,    62,    63,    64,    52,     1,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
       0,     0,    53,    54,     0,    55,    56,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    48,   222,     0,     0,
      49,     0,     0,     0,     0,    57,    58,    50,    59,    60,
      51,    61,     0,    62,    63,    64,    52,     1,     2,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,     0,     0,    53,    54,     0,    55,    56,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    48,   228,
       0,     0,    49,     0,     0,     0,     0,    57,    58,    50,
      59,    60,    51,    61,     0,    62,    63,    64,    52,     1,
       2,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,     0,     0,    53,    54,     0,    55,
      56,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      48,   236,     0,     0,    49,     0,     0,     0,     0,    57,
      58,    50,    59,    60,    51,    61,     0,    62,    63,    64,
      52,     1,     2,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,     0,     0,    53,    54,
       0,    55,    56,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    48,     0,     0,     0,    49,     0,     0,     0,
       0,    57,    58,    50,    59,    60,    51,    61,     0,    62,
      63,    64,    52,     1,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,     0,     0,
      53,    54,     0,    55,    56,    49,   224,     0,     0,     0,
       0,     0,    49,   226,     0,    51,     0,     0,     0,     0,
      49,    52,    51,    57,    58,     0,    59,    60,    52,    61,
      51,    62,    63,    64,     0,     0,    52,     0,     0,    53,
      54,     0,    55,    56,     0,     0,    53,    54,     0,    55,
      56,    49,     0,     0,    53,    54,     0,    55,    56,     0,
       0,    51,    57,    58,     0,     0,    60,    52,     0,    57,
      58,     0,     0,    60,     0,     0,     0,    57,    58,     0,
     107,    60,   108,     0,     0,    53,    54,     0,    55,    56,
       1,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,     0,     0,     0,    57,    98,
       0,     0,    60,     0,     0,     0,     0,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120
};

static const yytype_int16 yycheck[] =
{
      48,     9,     0,    49,    51,    52,     5,    22,    23,     5,
      60,    61,     9,    59,    13,    61,    62,    13,    44,    17,
      41,    42,    13,     0,    45,    16,   107,   108,    66,    27,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
      66,    39,    10,     9,     5,    13,     9,    62,    63,    46,
      47,    13,    13,    16,    16,     9,    19,   138,    96,    67,
       9,    67,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    44,   127,
      43,    44,    10,    46,    47,    13,     9,   128,    13,   135,
      44,    16,    67,    16,   140,    44,    19,     9,     9,    11,
      66,   182,    25,    66,    67,    16,    66,    70,    19,   156,
     157,   158,    66,    67,    25,    67,    13,    66,    67,    16,
      43,    44,    11,    46,    47,   123,     5,   208,    10,   177,
     178,    13,    43,    44,    66,    46,    47,   185,    10,   180,
     181,   179,    10,    66,    67,    13,    67,    70,   148,   149,
     150,   151,    43,    44,    10,    66,    67,    13,    13,    70,
      67,    16,    71,    10,    73,    64,    65,   213,   214,    67,
     218,     5,   210,   211,    13,    14,   224,   223,   226,   217,
       9,   146,   147,   152,   153,   233,    67,   235,     5,     6,
      15,   229,     9,    59,   232,    58,   234,   154,   155,    16,
     238,   239,    19,    53,    54,    21,    24,    20,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    66,    11,    43,    44,     5,    46,
      47,    10,    17,    74,   128,   183,    17,    29,   219,   141,
       5,     6,   142,   144,     9,    -1,    -1,   143,    -1,    66,
      67,    16,    69,    70,    19,    72,    -1,    74,    75,    76,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,   145,    -1,    43,    44,
      -1,    46,    47,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     5,     6,    -1,    -1,     9,    -1,    -1,    -1,
      -1,    66,    67,    16,    69,    70,    19,    72,    -1,    74,
      75,    76,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    -1,    -1,
      43,    44,    -1,    46,    47,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     5,     6,    -1,    -1,     9,    -1,
      -1,    -1,    -1,    66,    67,    16,    69,    70,    19,    72,
      -1,    74,    75,    76,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      -1,    -1,    43,    44,    -1,    46,    47,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     5,     6,    -1,    -1,
       9,    -1,    -1,    -1,    -1,    66,    67,    16,    69,    70,
      19,    72,    -1,    74,    75,    76,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    -1,    -1,    43,    44,    -1,    46,    47,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     5,     6,
      -1,    -1,     9,    -1,    -1,    -1,    -1,    66,    67,    16,
      69,    70,    19,    72,    -1,    74,    75,    76,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    -1,    -1,    43,    44,    -1,    46,
      47,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       5,     6,    -1,    -1,     9,    -1,    -1,    -1,    -1,    66,
      67,    16,    69,    70,    19,    72,    -1,    74,    75,    76,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    -1,    -1,    43,    44,
      -1,    46,    47,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     5,    -1,    -1,    -1,     9,    -1,    -1,    -1,
      -1,    66,    67,    16,    69,    70,    19,    72,    -1,    74,
      75,    76,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    -1,    -1,
      43,    44,    -1,    46,    47,     9,    10,    -1,    -1,    -1,
      -1,    -1,     9,    10,    -1,    19,    -1,    -1,    -1,    -1,
       9,    25,    19,    66,    67,    -1,    69,    70,    25,    72,
      19,    74,    75,    76,    -1,    -1,    25,    -1,    -1,    43,
      44,    -1,    46,    47,    -1,    -1,    43,    44,    -1,    46,
      47,     9,    -1,    -1,    43,    44,    -1,    46,    47,    -1,
      -1,    19,    66,    67,    -1,    -1,    70,    25,    -1,    66,
      67,    -1,    -1,    70,    -1,    -1,    -1,    66,    67,    -1,
       9,    70,    11,    -1,    -1,    43,    44,    -1,    46,    47,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    -1,    -1,    -1,    66,    67,
      -1,    -1,    70,    -1,    -1,    -1,    -1,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    78,    79,    80,    83,
      93,     0,    80,    93,    67,    94,    95,     9,    11,    13,
      16,    81,    83,     9,    44,    66,    67,    95,    10,    13,
      67,    44,    66,    66,     5,    83,    66,    10,     5,     9,
      16,    19,    25,    43,    44,    46,    47,    66,    67,    69,
      70,    72,    74,    75,    76,    83,    84,    85,    86,    87,
      88,    89,    90,    96,    97,    98,    99,   100,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,    67,    10,    84,   103,    67,   116,
     116,    44,   117,    66,   117,    67,    67,     9,    11,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    16,   103,     9,    67,   103,   103,     5,     9,    67,
      91,    92,     6,    85,    71,    73,   101,   102,    13,    16,
      15,    59,    58,    21,    24,    20,    60,    61,    22,    23,
      62,    63,    64,    65,    43,    44,    41,    42,    45,     6,
      10,    66,    82,   104,   104,   104,   104,   104,   104,   104,
     104,   104,   104,   104,   104,    16,    83,     5,     5,    84,
      86,    90,    11,    13,    16,     5,   103,   104,   103,   107,
     108,   109,   110,   111,   112,   112,   113,   113,   113,   113,
     114,   114,   115,   115,   116,   116,   116,    10,    13,    10,
      84,    84,     6,    86,    86,   104,    92,    84,     5,    14,
     104,     6,     6,    74,    10,   103,    10,   103,     6,    84,
     106,   103,    84,    10,    84,    10,     6,    16,    84,    84
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    77,    78,    79,    79,    79,    79,    80,    81,    81,
      81,    82,    82,    82,    83,    83,    83,    83,    83,    83,
      83,    83,    83,    83,    83,    83,    83,    83,    83,    84,
      84,    84,    85,    85,    85,    85,    85,    85,    85,    85,
      86,    86,    87,    87,    87,    87,    88,    89,    89,    90,
      91,    91,    92,    92,    93,    94,    94,    95,    95,    95,
      95,    95,    96,    96,    97,    97,    98,    99,   100,   101,
     102,   102,   103,   103,   104,   104,   104,   104,   104,   104,
     104,   104,   104,   104,   104,   104,   105,   105,   106,   106,
     107,   107,   108,   108,   109,   109,   110,   110,   111,   111,
     111,   112,   112,   112,   112,   112,   113,   113,   113,   114,
     114,   114,   115,   115,   115,   115,   116,   116,   116,   116,
     116,   116,   116,   116,   116,   117,   117,   117,   117,   117,
     118,   118,   118
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     2,     1,     1,     8,     4,     2,
       0,     3,     1,     0,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       1,     0,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     1,     7,     7,     6,     6,     3,     3,     2,     3,
       1,     3,     3,     1,     3,     1,     3,     3,     4,     5,
       6,     1,     2,     1,     2,     1,     5,     7,     5,     5,
       0,     4,     1,     3,     1,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     1,     5,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     3,
       3,     1,     3,     3,     3,     3,     1,     3,     3,     1,
       3,     3,     1,     3,     3,     3,     1,     2,     4,     2,
       2,     2,     2,     2,     2,     1,     2,     2,     4,     3,
       1,     1,     2
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
#line 54 "src/parser.y" /* yacc.c:1646  */
    { g_root = (yyvsp[0].node); }
#line 1583 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 56 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new Top_List((yyvsp[0].node),(yyvsp[-1].node)); }
#line 1589 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 57 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new Top_List((yyvsp[0].node),(yyvsp[-1].node)); }
#line 1595 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 58 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new Top_List((yyvsp[0].node)); }
#line 1601 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 59 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new Top_List((yyvsp[0].node)); }
#line 1607 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 61 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new Function(*(yyvsp[-7].string), *(yyvsp[-6].string), (yyvsp[-4].node), (yyvsp[-1].node)); }
#line 1613 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 63 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new Argument(*(yyvsp[-1].string), *(yyvsp[0].string), (yyvsp[-3].node)); }
#line 1619 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 64 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new Argument(*(yyvsp[-1].string), *(yyvsp[0].string)); }
#line 1625 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 65 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new Argument(); }
#line 1631 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 67 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new ArgumentNoType((yyvsp[0].node), (yyvsp[-2].node)); }
#line 1637 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 68 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new ArgumentNoType((yyvsp[0].node)); }
#line 1643 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 69 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new ArgumentNoType(); }
#line 1649 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 71 "src/parser.y" /* yacc.c:1646  */
    { (yyval.string) = (yyvsp[0].string); }
#line 1655 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 72 "src/parser.y" /* yacc.c:1646  */
    { (yyval.string) = (yyvsp[0].string); }
#line 1661 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 73 "src/parser.y" /* yacc.c:1646  */
    { (yyval.string) = (yyvsp[0].string); }
#line 1667 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 74 "src/parser.y" /* yacc.c:1646  */
    { (yyval.string) = (yyvsp[0].string); }
#line 1673 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 75 "src/parser.y" /* yacc.c:1646  */
    { (yyval.string) = (yyvsp[0].string); }
#line 1679 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 76 "src/parser.y" /* yacc.c:1646  */
    { (yyval.string) = (yyvsp[0].string); }
#line 1685 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 77 "src/parser.y" /* yacc.c:1646  */
    { (yyval.string) = (yyvsp[0].string); }
#line 1691 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 78 "src/parser.y" /* yacc.c:1646  */
    { (yyval.string) = (yyvsp[0].string); }
#line 1697 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 79 "src/parser.y" /* yacc.c:1646  */
    { (yyval.string) = (yyvsp[0].string); }
#line 1703 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 80 "src/parser.y" /* yacc.c:1646  */
    { (yyval.string) = (yyvsp[0].string); }
#line 1709 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 81 "src/parser.y" /* yacc.c:1646  */
    { (yyval.string) = (yyvsp[0].string); }
#line 1715 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 82 "src/parser.y" /* yacc.c:1646  */
    { (yyval.string) = (yyvsp[0].string); }
#line 1721 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 83 "src/parser.y" /* yacc.c:1646  */
    { (yyval.string) = (yyvsp[0].string); }
#line 1727 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 84 "src/parser.y" /* yacc.c:1646  */
    { (yyval.string) = (yyvsp[0].string); }
#line 1733 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 85 "src/parser.y" /* yacc.c:1646  */
    { (yyval.string) = (yyvsp[0].string); }
#line 1739 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 87 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new Body((yyvsp[0].node),(yyvsp[-1].node)); }
#line 1745 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 88 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new Body((yyvsp[0].node)); }
#line 1751 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 89 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new Body(); }
#line 1757 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 91 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1763 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 92 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1769 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 93 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1775 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 94 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1781 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 95 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1787 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 96 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1793 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 97 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1799 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 98 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1805 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 100 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new ExprStatement((yyvsp[-1].node)); }
#line 1811 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 101 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new ExprStatement; }
#line 1817 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 103 "src/parser.y" /* yacc.c:1646  */
    { new For_Statement((yyvsp[-4].node),(yyvsp[-3].node),(yyvsp[0].node),(yyvsp[-2].node));}
#line 1823 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 104 "src/parser.y" /* yacc.c:1646  */
    { new For_Statement((yyvsp[-4].node),(yyvsp[-3].node),(yyvsp[0].node),(yyvsp[-2].node));}
#line 1829 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 105 "src/parser.y" /* yacc.c:1646  */
    { new For_Statement((yyvsp[-3].node),(yyvsp[-2].node),(yyvsp[0].node));}
#line 1835 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 106 "src/parser.y" /* yacc.c:1646  */
    { new For_Statement((yyvsp[-3].node),(yyvsp[-2].node),(yyvsp[0].node));}
#line 1841 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 108 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new NewScope((yyvsp[-1].node)); }
#line 1847 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 110 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new ReturnStatement((yyvsp[-1].node)); }
#line 1853 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 111 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new ReturnStatement(); }
#line 1859 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 113 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new DeclareStatement(*(yyvsp[-2].string), (yyvsp[-1].node)); }
#line 1865 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 115 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new Dec_Var_List((yyvsp[0].node)); }
#line 1871 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 116 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new Dec_Var_List((yyvsp[0].node),(yyvsp[-2].node)); }
#line 1877 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 118 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new Declare(*(yyvsp[-2].string), (yyvsp[0].node)); }
#line 1883 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 119 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new Declare(*(yyvsp[0].string)); }
#line 1889 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 121 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new DeclareStatement(*(yyvsp[-2].string), (yyvsp[-1].node)); }
#line 1895 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 123 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new Dec_Var_List((yyvsp[0].node)); }
#line 1901 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 124 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new Dec_Var_List((yyvsp[0].node),(yyvsp[-2].node)); }
#line 1907 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 126 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new GlobalDeclare(*(yyvsp[-2].string), (yyvsp[0].number)); }
#line 1913 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 127 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new GlobalDeclare(*(yyvsp[-3].string), -(yyvsp[0].number)); }
#line 1919 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 128 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new GlobalDeclare(*(yyvsp[-4].string), (yyvsp[-1].number)); }
#line 1925 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 129 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new GlobalDeclare(*(yyvsp[-5].string), -(yyvsp[-1].number)); }
#line 1931 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 130 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new GlobalDeclare(*(yyvsp[0].string)); }
#line 1937 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 132 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new IfElseList((yyvsp[-1].node), (yyvsp[0].node)); }
#line 1943 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 133 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1949 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 135 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new IfElseList((yyvsp[-1].node), (yyvsp[0].node)); }
#line 1955 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 136 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1961 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 138 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new While_Statement((yyvsp[-3].node),(yyvsp[-1].node)); }
#line 1967 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 141 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new Do_While_Statement((yyvsp[-4].node),(yyvsp[-1].node)); }
#line 1973 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 144 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new If_Statement((yyvsp[-3].node),(yyvsp[-1].node)); }
#line 1979 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 148 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new ElIf_Statement((yyvsp[-3].node),(yyvsp[-1].node)); }
#line 1985 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 151 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new Else_Statement ((yyvsp[-1].node)); }
#line 1991 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 154 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1997 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 155 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new CommaOp((yyvsp[-2].node), (yyvsp[0].node)); }
#line 2003 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 157 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2009 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 158 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new AssignOp(*(yyvsp[-2].string), (yyvsp[0].node)); }
#line 2015 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 159 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new AssignOp(*(yyvsp[-2].string), new AddOperator(new Variable(*(yyvsp[-2].string)), (yyvsp[0].node))); }
#line 2021 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 160 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new AssignOp(*(yyvsp[-2].string), new SubOperator(new Variable(*(yyvsp[-2].string)), (yyvsp[0].node))); }
#line 2027 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 161 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new AssignOp(*(yyvsp[-2].string), new MulOperator(new Variable(*(yyvsp[-2].string)), (yyvsp[0].node))); }
#line 2033 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 162 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new AssignOp(*(yyvsp[-2].string), new DivOperator(new Variable(*(yyvsp[-2].string)), (yyvsp[0].node))); }
#line 2039 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 163 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new AssignOp(*(yyvsp[-2].string), new ModOperator(new Variable(*(yyvsp[-2].string)), (yyvsp[0].node))); }
#line 2045 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 164 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new AssignOp(*(yyvsp[-2].string), new BLShift(new Variable(*(yyvsp[-2].string)), (yyvsp[0].node))); }
#line 2051 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 165 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new AssignOp(*(yyvsp[-2].string), new BRShift(new Variable(*(yyvsp[-2].string)), (yyvsp[0].node))); }
#line 2057 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 166 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new AssignOp(*(yyvsp[-2].string), new BAnd(new Variable(*(yyvsp[-2].string)), (yyvsp[0].node))); }
#line 2063 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 167 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new AssignOp(*(yyvsp[-2].string), new BOr(new Variable(*(yyvsp[-2].string)), (yyvsp[0].node))); }
#line 2069 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 168 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new AssignOp(*(yyvsp[-2].string), new BXor(new Variable(*(yyvsp[-2].string)), (yyvsp[0].node))); }
#line 2075 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 170 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2081 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 171 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new TenOp((yyvsp[-4].node),(yyvsp[-2].node),(yyvsp[0].node)); }
#line 2087 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 173 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2093 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 174 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new LOr((yyvsp[-2].node),(yyvsp[0].node)); }
#line 2099 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 176 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2105 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 177 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new LAnd((yyvsp[-2].node),(yyvsp[0].node)); }
#line 2111 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 92:
#line 179 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2117 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 93:
#line 180 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new BOr((yyvsp[-2].node),(yyvsp[0].node)); }
#line 2123 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 94:
#line 182 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2129 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 95:
#line 183 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new BXor((yyvsp[-2].node),(yyvsp[0].node)); }
#line 2135 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 96:
#line 185 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2141 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 97:
#line 186 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new BAnd((yyvsp[-2].node),(yyvsp[0].node)); }
#line 2147 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 98:
#line 188 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2153 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 99:
#line 189 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new LEqual((yyvsp[-2].node),(yyvsp[0].node)); }
#line 2159 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 100:
#line 190 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new LNotEqual((yyvsp[-2].node),(yyvsp[0].node)); }
#line 2165 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 101:
#line 192 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2171 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 102:
#line 193 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new LMore((yyvsp[-2].node),(yyvsp[0].node)); }
#line 2177 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 103:
#line 194 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new LLess((yyvsp[-2].node),(yyvsp[0].node)); }
#line 2183 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 104:
#line 195 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new LMoreEqual((yyvsp[-2].node),(yyvsp[0].node)); }
#line 2189 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 105:
#line 196 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new LLessEqual((yyvsp[-2].node),(yyvsp[0].node)); }
#line 2195 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 106:
#line 198 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2201 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 107:
#line 199 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new BLShift((yyvsp[-2].node),(yyvsp[0].node)); }
#line 2207 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 108:
#line 200 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new BRShift((yyvsp[-2].node),(yyvsp[0].node)); }
#line 2213 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 109:
#line 202 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2219 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 110:
#line 203 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new AddOperator( (yyvsp[-2].node) , (yyvsp[0].node) ); }
#line 2225 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 111:
#line 204 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new SubOperator( (yyvsp[-2].node) , (yyvsp[0].node) ); }
#line 2231 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 112:
#line 206 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2237 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 113:
#line 207 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new MulOperator( (yyvsp[-2].node) , (yyvsp[0].node) ); }
#line 2243 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 114:
#line 208 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new DivOperator( (yyvsp[-2].node) , (yyvsp[0].node) ); }
#line 2249 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 115:
#line 209 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new ModOperator( (yyvsp[-2].node) , (yyvsp[0].node) ); }
#line 2255 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 116:
#line 211 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2261 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 117:
#line 212 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new SizeOf(*(yyvsp[0].string)); }
#line 2267 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 118:
#line 213 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new SizeOf(*(yyvsp[-1].string)); }
#line 2273 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 119:
#line 214 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new LNot((yyvsp[0].node)); }
#line 2279 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 120:
#line 215 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new BNot((yyvsp[0].node)); }
#line 2285 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 121:
#line 216 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new AssignOp(*(yyvsp[0].string), new AddOperator(new Variable(*(yyvsp[0].string)), new Number(1,0))); }
#line 2291 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 122:
#line 217 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new AssignOp(*(yyvsp[0].string), new SubOperator(new Variable(*(yyvsp[0].string)), new Number(1,0))); }
#line 2297 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 123:
#line 218 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new PosOp((yyvsp[0].node));}
#line 2303 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 124:
#line 219 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new NegOp((yyvsp[0].node));}
#line 2309 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 125:
#line 221 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2315 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 126:
#line 222 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new AssignOp(*(yyvsp[-1].string), new AddOperator(new Variable(*(yyvsp[-1].string)), new Number(1,0))); }
#line 2321 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 127:
#line 223 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new AssignOp(*(yyvsp[-1].string), new SubOperator(new Variable(*(yyvsp[-1].string)), new Number(1,0))); }
#line 2327 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 128:
#line 224 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new FunctionStatementInExpr(*(yyvsp[-3].string),(yyvsp[-1].node)); }
#line 2333 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 129:
#line 225 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[-1].node); }
#line 2339 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 130:
#line 227 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new Variable( *(yyvsp[0].string) ); }
#line 2345 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 131:
#line 228 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new Number( (yyvsp[0].number) , 0 ); }
#line 2351 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 132:
#line 229 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new Number( 0 , (yyvsp[0].number) ); }
#line 2357 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;


#line 2361 "src/parser.tab.cpp" /* yacc.c:1646  */
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
#line 230 "src/parser.y" /* yacc.c:1906  */


const ASTNode *g_root; // Definition of variable (to match declaration earlier)

const ASTNode *parseAST()
{
  g_root=0;
  yyparse();
  return g_root;
}
