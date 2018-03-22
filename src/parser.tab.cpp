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
    T_WHILE = 328,
    T_DO = 329
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

#line 204 "src/parser.tab.cpp" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SRC_PARSER_TAB_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 221 "src/parser.tab.cpp" /* yacc.c:358  */

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
#define YYFINAL  22
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   629

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  75
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  38
/* YYNRULES -- Number of rules.  */
#define YYNRULES  115
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  205

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   329

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
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    52,    52,    55,    57,    58,    59,    60,    62,    64,
      65,    66,    68,    69,    70,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      88,    89,    90,    92,    93,    94,    95,    96,    97,    98,
      99,   101,   102,   104,   106,   107,   109,   110,   112,   114,
     115,   117,   118,   120,   122,   124,   126,   128,   130,   131,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   146,   147,   149,   150,   152,   153,   155,   156,
     158,   159,   161,   162,   164,   165,   166,   168,   169,   170,
     171,   172,   174,   175,   176,   178,   179,   180,   182,   183,
     184,   185,   187,   188,   189,   190,   191,   192,   193,   195,
     196,   197,   198,   200,   201,   202
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
  "T_COMMENT", "T_RETURN", "T_SIZE_OF", "T_ELSE", "T_IF", "T_WHILE",
  "T_DO", "$accept", "ROOT", "TOP_LEVEL", "TOP_LIST", "DEC_FUNCTION",
  "ARGUMENT_LIST", "ARGUMENT_LIST_NO_TYPE", "TYPE", "BODY", "STATEMENT",
  "NEW_SCOPE", "RETURN_STATEMENT", "DEC_VARIABLE", "GLO_DEC_VARIABLE",
  "FUNCTION_STATEMENT", "IFANDORELSEORELIF", "IFANDORELIF",
  "WHILE_STATEMENT", "DO_STATEMENT", "IF_STATEMENT", "ELSE_IF_STATEMENT",
  "ELSE_STATEMENT", "EXPR_1", "EXPR_2", "EXPR_3", "EXPR_4", "EXPR_5",
  "EXPR_6", "EXPR_7", "EXPR_8", "EXPR_9", "EXPR_10", "EXPR_11", "EXPR_12",
  "EXPR_13", "EXPR_14", "EXPR_15", "PRIMATIVES", YY_NULLPTR
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
     325,   326,   327,   328,   329
};
# endif

#define YYPACT_NINF -84

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-84)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     589,   -84,   -84,   -84,   -84,   -84,   -84,   -84,   -84,   -84,
     -84,   -84,   -84,   -84,   -84,   -84,    18,   -84,   589,   -84,
     -43,   -84,   -84,   -84,   -84,     5,   589,   509,   -84,     7,
     -33,   514,   514,   -28,    -9,    28,   -84,    -5,    16,    19,
     -84,    90,    52,    58,   106,   108,   110,    49,    63,    57,
      80,   -19,   -84,   -84,   -84,   150,   589,   -84,    47,   -84,
     -84,   -84,   -84,   -84,   509,   509,   -84,   -84,   509,   509,
     509,   509,   509,   509,   509,   509,   509,   509,   589,   -84,
     509,   -84,   509,   514,   514,   514,   514,   514,   514,   514,
     514,   514,   514,   514,   514,   514,   514,   514,   514,   514,
     514,   478,    97,    23,   144,   -84,   -84,   -84,   -84,   -84,
     -84,   -84,   -84,   -84,   -84,   -84,   155,   -84,   115,    58,
     106,   108,   110,    49,    63,    63,    57,    57,    57,    57,
      80,    80,   -19,   -19,   -84,   -84,   -84,    34,   557,   509,
     509,   509,   161,   100,   114,   -84,   -84,   -84,   -84,   -84,
     -84,    98,   -84,   -84,   -84,    74,   -84,   -84,   509,   -84,
     514,   -84,   166,   509,    75,    -3,    -2,   478,    -4,   -84,
     -84,    10,   -84,   -84,   -84,   144,    52,   -84,    79,   -84,
     478,   478,   218,   509,   -84,   478,   509,   152,   270,   322,
     101,    83,   374,     0,   -84,   -84,   -84,   509,   -84,   -84,
     478,   102,   426,   -84,   -84
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,     0,     2,     3,     6,
       0,     7,     1,     4,     5,     0,    11,     0,    47,     0,
       0,     0,     0,     0,     0,     0,   114,   113,     0,     0,
      58,    60,    72,    74,    76,    78,    80,    82,    84,    87,
      92,    95,    98,   102,   109,     0,     0,    10,   113,   105,
     106,   115,   107,   108,    14,     0,   110,   111,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   103,
       0,    46,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    32,     0,     0,    13,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    71,    70,     0,    59,     0,    75,
      77,    79,    81,    83,    85,    86,    88,    89,    91,    90,
      93,    94,    96,    97,    99,   100,   101,     0,   113,     0,
       0,     0,     0,     0,     0,    31,    40,    33,    34,    35,
      37,    50,    38,    39,    52,     0,     9,   112,     0,   104,
       0,    42,     0,    14,     0,     0,     0,    32,     0,     8,
      30,     0,    51,    49,    36,    12,    73,    41,     0,    43,
      32,    32,     0,     0,    45,    32,     0,   112,     0,     0,
       0,     0,     0,     0,    48,    55,    53,     0,    44,    57,
      32,     0,     0,    54,    56
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -84,   -84,   -84,   -84,   157,   -84,    13,     1,   -83,   375,
     -84,   -84,   -84,   159,   -84,   -84,   -84,   -84,   -84,   -84,
     -84,   -84,   -27,   517,   -84,    22,    95,    89,    94,   103,
     120,    46,   -62,    43,    66,   -23,   -84,   -84
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    16,    17,    18,    19,    29,   103,   143,   144,   145,
     146,   147,   148,    21,   149,   150,   151,   152,   153,   154,
     172,   173,   155,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      39,    20,   180,   181,    64,   200,    65,   183,    59,    60,
      80,    80,   184,    80,    26,   185,    27,    55,    22,    20,
      56,    28,    98,    99,    25,    78,   100,    30,   126,   127,
     128,   129,    80,   157,    57,    81,   158,   104,    61,   137,
     161,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    31,   162,   118,    64,   102,    62,    32,
       1,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,   134,   135,   136,    33,   116,
      34,    35,   186,    79,   182,    90,    91,    80,    80,   187,
     174,   179,   158,    66,    67,    63,    80,   188,   189,   198,
      36,   138,   192,   139,    38,    82,   140,   141,   142,    88,
      89,    83,   164,   165,   166,    80,    84,   202,   203,   137,
     169,    94,    95,    96,    97,    92,    93,    85,    80,   160,
      87,   175,    86,    31,   124,   125,   104,   130,   131,    32,
       1,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,   101,   191,    80,    33,   193,
      34,    35,   132,   133,   156,   159,   167,   168,   194,   171,
     201,   137,   177,   120,   197,    23,   178,    24,   119,   121,
      36,   138,   176,   139,    38,    31,   140,   141,   142,   122,
       0,    32,     1,     2,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,   123,     0,     0,
      33,     0,    34,    35,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   137,   190,     0,     0,     0,     0,     0,
       0,     0,    36,   138,     0,   139,    38,    31,   140,   141,
     142,     0,     0,    32,     1,     2,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,     0,
       0,     0,    33,     0,    34,    35,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   137,   195,     0,     0,     0,
       0,     0,     0,     0,    36,   138,     0,   139,    38,    31,
     140,   141,   142,     0,     0,    32,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,     0,     0,     0,    33,     0,    34,    35,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   137,   196,     0,
       0,     0,     0,     0,     0,     0,    36,   138,     0,   139,
      38,    31,   140,   141,   142,     0,     0,    32,     1,     2,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,     0,     0,     0,    33,     0,    34,    35,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   137,
     199,     0,     0,     0,     0,     0,     0,     0,    36,   138,
       0,   139,    38,    31,   140,   141,   142,     0,     0,    32,
       1,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,     0,     0,     0,    33,     0,
      34,    35,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   137,   204,     0,     0,     0,     0,     0,     0,     0,
      36,   138,     0,   139,    38,    31,   140,   141,   142,     0,
       0,    32,     1,     2,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,     0,     0,     0,
      33,     0,    34,    35,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   137,     0,     0,     0,     0,     0,     0,
       0,     0,    36,   138,     0,   139,    38,    31,   140,   141,
     142,     0,     0,    32,     1,     2,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,   170,
       0,     0,    33,     0,    34,    35,     0,     0,    31,     0,
       0,     0,     0,    31,    32,     0,     0,   170,     0,    32,
       0,     0,     0,     0,    36,   138,     0,   139,    38,     0,
     140,   141,   142,    33,     0,    34,    35,   170,    33,     0,
      34,    35,     0,   170,   170,     0,   163,   170,    65,     0,
       0,     0,     0,     0,     0,    36,    37,   170,     0,    38,
      36,    58,   105,     0,    38,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,     0,     0,   117,     0,     0,
       0,     0,     0,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,     1,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15
};

static const yytype_int16 yycheck[] =
{
      27,     0,     5,     5,     9,     5,    11,    11,    31,    32,
      13,    13,    16,    13,     9,     5,    11,    10,     0,    18,
      13,    16,    41,    42,    67,     9,    45,    26,    90,    91,
      92,    93,    13,    10,    67,    16,    13,    64,    66,     5,
       6,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    19,   137,    82,     9,    56,    67,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    98,    99,   100,    44,    78,
      46,    47,    72,    67,   167,    22,    23,    13,    13,    10,
      16,    16,    13,    46,    47,    67,    13,   180,   181,    16,
      66,    67,   185,    69,    70,    15,    72,    73,    74,    60,
      61,    59,   139,   140,   141,    13,    58,   200,    16,     5,
       6,    64,    65,    43,    44,    62,    63,    21,    13,    14,
      20,   158,    24,    19,    88,    89,   163,    94,    95,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,     5,   183,    13,    44,   186,
      46,    47,    96,    97,    67,    10,     5,    67,    16,    71,
     197,     5,     6,    84,    73,    18,   163,    18,    83,    85,
      66,    67,   160,    69,    70,    19,    72,    73,    74,    86,
      -1,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    87,    -1,    -1,
      44,    -1,    46,    47,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     5,     6,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    66,    67,    -1,    69,    70,    19,    72,    73,
      74,    -1,    -1,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    -1,
      -1,    -1,    44,    -1,    46,    47,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     5,     6,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    66,    67,    -1,    69,    70,    19,
      72,    73,    74,    -1,    -1,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    -1,    -1,    -1,    44,    -1,    46,    47,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     5,     6,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    66,    67,    -1,    69,
      70,    19,    72,    73,    74,    -1,    -1,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    -1,    -1,    -1,    44,    -1,    46,    47,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     5,
       6,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    66,    67,
      -1,    69,    70,    19,    72,    73,    74,    -1,    -1,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    -1,    -1,    -1,    44,    -1,
      46,    47,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     5,     6,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      66,    67,    -1,    69,    70,    19,    72,    73,    74,    -1,
      -1,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    -1,    -1,    -1,
      44,    -1,    46,    47,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     5,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    66,    67,    -1,    69,    70,    19,    72,    73,
      74,    -1,    -1,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,   144,
      -1,    -1,    44,    -1,    46,    47,    -1,    -1,    19,    -1,
      -1,    -1,    -1,    19,    25,    -1,    -1,   162,    -1,    25,
      -1,    -1,    -1,    -1,    66,    67,    -1,    69,    70,    -1,
      72,    73,    74,    44,    -1,    46,    47,   182,    44,    -1,
      46,    47,    -1,   188,   189,    -1,     9,   192,    11,    -1,
      -1,    -1,    -1,    -1,    -1,    66,    67,   202,    -1,    70,
      66,    67,    65,    -1,    70,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,    -1,    80,    -1,    -1,
      -1,    -1,    -1,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    76,    77,    78,    79,
      82,    88,     0,    79,    88,    67,     9,    11,    16,    80,
      82,    19,    25,    44,    46,    47,    66,    67,    70,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,    10,    13,    67,    67,   110,
     110,    66,    67,    67,     9,    11,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,     9,    67,
      13,    16,    15,    59,    58,    21,    24,    20,    60,    61,
      22,    23,    62,    63,    64,    65,    43,    44,    41,    42,
      45,     5,    82,    81,    97,    98,    98,    98,    98,    98,
      98,    98,    98,    98,    98,    98,    82,    98,    97,   101,
     102,   103,   104,   105,   106,   106,   107,   107,   107,   107,
     108,   108,   109,   109,   110,   110,   110,     5,    67,    69,
      72,    73,    74,    82,    83,    84,    85,    86,    87,    89,
      90,    91,    92,    93,    94,    97,    67,    10,    13,    10,
      14,     6,    83,     9,    97,    97,    97,     5,    67,     6,
      84,    71,    95,    96,    16,    97,   100,     6,    81,    16,
       5,     5,    83,    11,    16,     5,    72,    10,    83,    83,
       6,    97,    83,    97,    16,     6,     6,    73,    16,     6,
       5,    97,    83,    16,     6
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    75,    76,    77,    78,    78,    78,    78,    79,    80,
      80,    80,    81,    81,    81,    82,    82,    82,    82,    82,
      82,    82,    82,    82,    82,    82,    82,    82,    82,    82,
      83,    83,    83,    84,    84,    84,    84,    84,    84,    84,
      84,    85,    85,    86,    87,    87,    88,    88,    89,    90,
      90,    91,    91,    92,    93,    94,    95,    96,    97,    97,
      98,    98,    98,    98,    98,    98,    98,    98,    98,    98,
      98,    98,    99,    99,   100,   100,   101,   101,   102,   102,
     103,   103,   104,   104,   105,   105,   105,   106,   106,   106,
     106,   106,   107,   107,   107,   108,   108,   108,   109,   109,
     109,   109,   110,   110,   110,   110,   110,   110,   110,   111,
     111,   111,   111,   112,   112,   112
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     2,     1,     1,     8,     4,
       2,     0,     3,     1,     0,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     1,     0,     1,     1,     1,     2,     1,     1,     1,
       1,     3,     2,     3,     5,     3,     5,     3,     5,     2,
       1,     2,     1,     5,     7,     5,     6,     4,     1,     3,
       1,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     1,     5,     1,     3,     1,     3,     1,     3,
       1,     3,     1,     3,     1,     3,     3,     1,     3,     3,
       3,     3,     1,     3,     3,     1,     3,     3,     1,     3,
       3,     3,     1,     2,     4,     2,     2,     2,     2,     1,
       2,     2,     4,     1,     1,     2
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
#line 52 "src/parser.y" /* yacc.c:1646  */
    { g_root = (yyvsp[0].node); }
#line 1543 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 55 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1549 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 57 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node) = new Top_List((yyvsp[0].node),(yyvsp[-1].node)); }
#line 1555 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 58 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node) = new Top_List((yyvsp[0].node),(yyvsp[-1].node)); }
#line 1561 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 59 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node); }
#line 1567 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 60 "src/parser.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node); }
#line 1573 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 62 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new Function(*(yyvsp[-7].string), *(yyvsp[-6].string), (yyvsp[-4].node), (yyvsp[-1].node)); }
#line 1579 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 64 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new Argument(*(yyvsp[-1].string), *(yyvsp[0].string), (yyvsp[-3].node)); }
#line 1585 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 65 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new Argument(*(yyvsp[-1].string), *(yyvsp[0].string)); }
#line 1591 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 66 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new Argument(); }
#line 1597 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 68 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new ArgumentNoType((yyvsp[0].node), (yyvsp[-2].node)); }
#line 1603 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 69 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new ArgumentNoType((yyvsp[0].node)); }
#line 1609 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 70 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new ArgumentNoType(); }
#line 1615 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 72 "src/parser.y" /* yacc.c:1646  */
    { (yyval.string) = (yyvsp[0].string); }
#line 1621 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 73 "src/parser.y" /* yacc.c:1646  */
    { (yyval.string) = (yyvsp[0].string); }
#line 1627 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 74 "src/parser.y" /* yacc.c:1646  */
    { (yyval.string) = (yyvsp[0].string); }
#line 1633 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 75 "src/parser.y" /* yacc.c:1646  */
    { (yyval.string) = (yyvsp[0].string); }
#line 1639 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 76 "src/parser.y" /* yacc.c:1646  */
    { (yyval.string) = (yyvsp[0].string); }
#line 1645 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 77 "src/parser.y" /* yacc.c:1646  */
    { (yyval.string) = (yyvsp[0].string); }
#line 1651 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 78 "src/parser.y" /* yacc.c:1646  */
    { (yyval.string) = (yyvsp[0].string); }
#line 1657 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 79 "src/parser.y" /* yacc.c:1646  */
    { (yyval.string) = (yyvsp[0].string); }
#line 1663 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 80 "src/parser.y" /* yacc.c:1646  */
    { (yyval.string) = (yyvsp[0].string); }
#line 1669 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 81 "src/parser.y" /* yacc.c:1646  */
    { (yyval.string) = (yyvsp[0].string); }
#line 1675 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 82 "src/parser.y" /* yacc.c:1646  */
    { (yyval.string) = (yyvsp[0].string); }
#line 1681 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 83 "src/parser.y" /* yacc.c:1646  */
    { (yyval.string) = (yyvsp[0].string); }
#line 1687 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 84 "src/parser.y" /* yacc.c:1646  */
    { (yyval.string) = (yyvsp[0].string); }
#line 1693 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 85 "src/parser.y" /* yacc.c:1646  */
    { (yyval.string) = (yyvsp[0].string); }
#line 1699 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 86 "src/parser.y" /* yacc.c:1646  */
    { (yyval.string) = (yyvsp[0].string); }
#line 1705 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 88 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new Body((yyvsp[0].node),(yyvsp[-1].node)); }
#line 1711 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 89 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1717 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 90 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new Body(); }
#line 1723 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 92 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1729 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 93 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1735 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 94 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1741 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 95 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new ExprStatement((yyvsp[-1].node)); }
#line 1747 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 96 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1753 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 97 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1759 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 98 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1765 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 99 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1771 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 101 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new NewScope((yyvsp[-1].node)); }
#line 1777 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 102 "src/parser.y" /* yacc.c:1646  */
    { ; }
#line 1783 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 104 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new ReturnStatement((yyvsp[-1].node)); }
#line 1789 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 106 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new DeclareStatement(*(yyvsp[-4].string), *(yyvsp[-3].string), (yyvsp[-1].node)); }
#line 1795 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 107 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new DeclareStatement(*(yyvsp[-2].string), *(yyvsp[-1].string)); }
#line 1801 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 109 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new GlobalDeclareStatement(*(yyvsp[-4].string), *(yyvsp[-3].string), (yyvsp[-1].node)); }
#line 1807 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 110 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new GlobalDeclareStatement(*(yyvsp[-2].string), *(yyvsp[-1].string)); }
#line 1813 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 112 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new FunctionStatement(*(yyvsp[-4].string),(yyvsp[-2].node)); }
#line 1819 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 114 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new IfElseList((yyvsp[-1].node), (yyvsp[0].node)); }
#line 1825 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 115 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1831 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 117 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new IfElseList((yyvsp[-1].node), (yyvsp[0].node)); }
#line 1837 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 118 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1843 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 120 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new While_Statement((yyvsp[-3].node),(yyvsp[-1].node)); }
#line 1849 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 122 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new Do_While_Statement((yyvsp[-4].node),(yyvsp[-1].node)); }
#line 1855 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 124 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new If_Statement((yyvsp[-3].node),(yyvsp[-1].node)); }
#line 1861 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 126 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new ElIf_Statement((yyvsp[-3].node),(yyvsp[-1].node)); }
#line 1867 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 128 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new Else_Statement ((yyvsp[-1].node)); }
#line 1873 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 130 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1879 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 131 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new CommaOp((yyvsp[-2].node), (yyvsp[0].node)); }
#line 1885 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 133 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1891 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 134 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new AssignOp(*(yyvsp[-2].string), (yyvsp[0].node)); }
#line 1897 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 135 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new AssignOp(*(yyvsp[-2].string), new AddOperator(new Variable(*(yyvsp[-2].string)), (yyvsp[0].node))); }
#line 1903 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 136 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new AssignOp(*(yyvsp[-2].string), new SubOperator(new Variable(*(yyvsp[-2].string)), (yyvsp[0].node))); }
#line 1909 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 137 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new AssignOp(*(yyvsp[-2].string), new MulOperator(new Variable(*(yyvsp[-2].string)), (yyvsp[0].node))); }
#line 1915 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 138 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new AssignOp(*(yyvsp[-2].string), new DivOperator(new Variable(*(yyvsp[-2].string)), (yyvsp[0].node))); }
#line 1921 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 139 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new AssignOp(*(yyvsp[-2].string), new ModOperator(new Variable(*(yyvsp[-2].string)), (yyvsp[0].node))); }
#line 1927 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 140 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new AssignOp(*(yyvsp[-2].string), new BLShift(new Variable(*(yyvsp[-2].string)), (yyvsp[0].node))); }
#line 1933 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 141 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new AssignOp(*(yyvsp[-2].string), new BRShift(new Variable(*(yyvsp[-2].string)), (yyvsp[0].node))); }
#line 1939 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 142 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new AssignOp(*(yyvsp[-2].string), new BAnd(new Variable(*(yyvsp[-2].string)), (yyvsp[0].node))); }
#line 1945 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 143 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new AssignOp(*(yyvsp[-2].string), new BOr(new Variable(*(yyvsp[-2].string)), (yyvsp[0].node))); }
#line 1951 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 144 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new AssignOp(*(yyvsp[-2].string), new BXor(new Variable(*(yyvsp[-2].string)), (yyvsp[0].node))); }
#line 1957 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 146 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1963 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 147 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new TenOp((yyvsp[-4].node),(yyvsp[-2].node),(yyvsp[0].node)); }
#line 1969 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 149 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1975 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 150 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new LOr((yyvsp[-2].node),(yyvsp[0].node)); }
#line 1981 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 152 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1987 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 153 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new LAnd((yyvsp[-2].node),(yyvsp[0].node)); }
#line 1993 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 155 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1999 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 156 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new BOr((yyvsp[-2].node),(yyvsp[0].node)); }
#line 2005 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 158 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2011 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 159 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new BXor((yyvsp[-2].node),(yyvsp[0].node)); }
#line 2017 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 161 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2023 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 162 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new BAnd((yyvsp[-2].node),(yyvsp[0].node)); }
#line 2029 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 164 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2035 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 165 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new LEqual((yyvsp[-2].node),(yyvsp[0].node)); }
#line 2041 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 166 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new LNotEqual((yyvsp[-2].node),(yyvsp[0].node)); }
#line 2047 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 168 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2053 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 169 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new LMore((yyvsp[-2].node),(yyvsp[0].node)); }
#line 2059 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 170 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new LLess((yyvsp[-2].node),(yyvsp[0].node)); }
#line 2065 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 171 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new LMoreEqual((yyvsp[-2].node),(yyvsp[0].node)); }
#line 2071 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 172 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new LLessEqual((yyvsp[-2].node),(yyvsp[0].node)); }
#line 2077 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 92:
#line 174 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2083 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 93:
#line 175 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new BLShift((yyvsp[-2].node),(yyvsp[0].node)); }
#line 2089 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 94:
#line 176 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new BRShift((yyvsp[-2].node),(yyvsp[0].node)); }
#line 2095 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 95:
#line 178 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2101 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 96:
#line 179 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new AddOperator( (yyvsp[-2].node) , (yyvsp[0].node) ); }
#line 2107 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 97:
#line 180 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new SubOperator( (yyvsp[-2].node) , (yyvsp[0].node) ); }
#line 2113 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 98:
#line 182 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2119 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 99:
#line 183 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new MulOperator( (yyvsp[-2].node) , (yyvsp[0].node) ); }
#line 2125 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 100:
#line 184 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new DivOperator( (yyvsp[-2].node) , (yyvsp[0].node) ); }
#line 2131 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 101:
#line 185 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new ModOperator( (yyvsp[-2].node) , (yyvsp[0].node) ); }
#line 2137 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 102:
#line 187 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2143 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 103:
#line 188 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new SizeOf(*(yyvsp[0].string)); }
#line 2149 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 104:
#line 189 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new SizeOf(*(yyvsp[-1].string)); }
#line 2155 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 105:
#line 190 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new LNot((yyvsp[0].node)); }
#line 2161 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 106:
#line 191 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new BNot((yyvsp[0].node)); }
#line 2167 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 107:
#line 192 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new AssignOp(*(yyvsp[0].string), new AddOperator(new Variable(*(yyvsp[0].string)), new Number(1,0))); }
#line 2173 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 108:
#line 193 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new AssignOp(*(yyvsp[0].string), new SubOperator(new Variable(*(yyvsp[0].string)), new Number(1,0))); }
#line 2179 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 109:
#line 195 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2185 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 110:
#line 196 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new AssignOp(*(yyvsp[-1].string), new AddOperator(new Variable(*(yyvsp[-1].string)), new Number(1,0))); }
#line 2191 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 111:
#line 197 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new AssignOp(*(yyvsp[-1].string), new SubOperator(new Variable(*(yyvsp[-1].string)), new Number(1,0))); }
#line 2197 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 112:
#line 198 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new FunctionStatementInExpr(*(yyvsp[-3].string),(yyvsp[-1].node)); }
#line 2203 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 113:
#line 200 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new Variable( *(yyvsp[0].string) ); }
#line 2209 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 114:
#line 201 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new Number( (yyvsp[0].number) , 0 ); }
#line 2215 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 115:
#line 202 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new Number( 0 , (yyvsp[0].number) ); }
#line 2221 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;


#line 2225 "src/parser.tab.cpp" /* yacc.c:1646  */
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
#line 203 "src/parser.y" /* yacc.c:1906  */


const ASTNode *g_root; // Definition of variable (to match declaration earlier)

const ASTNode *parseAST()
{
  g_root=0;
  yyparse();
  return g_root;
}
