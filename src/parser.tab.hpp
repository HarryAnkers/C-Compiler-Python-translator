/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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
#line 1 "src/parser.y" /* yacc.c:1909  */

  #include "ast.hpp"

  #include <cassert>

  extern const ASTNode *g_root; // A way of getting the AST out

  //! This is to fix problems when generating C++
  // We are declaring the functions provided by Flex, so
  // that Bison generated code can call them.
  int yylex(void);
  void yyerror(const char *);

#line 58 "src/parser.tab.hpp" /* yacc.c:1909  */

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
    T_SEMICOLON = 270,
    T_SPEACHMARK = 271,
    T_APOSTROPHE = 272,
    T_NOT = 273,
    T_AND = 274,
    T_OR = 275,
    T_MORE = 276,
    T_LESS = 277,
    T_XOR = 278,
    T_TILDA = 279,
    T_INT = 280,
    T_DOUBLE = 281,
    T_STRING = 282,
    T_BOOL = 283,
    T_VOID = 284,
    T_LONG = 285,
    T_TIMES = 286,
    T_DIVIDE = 287,
    T_PLUS = 288,
    T_MINUS = 289,
    T_MODULUS = 290,
    T_INC = 291,
    T_DEC = 292,
    T_ADDASSIGN = 293,
    T_SUBASSIGN = 294,
    T_MULASSIGN = 295,
    T_DIVASSIGN = 296,
    T_MODASSIGN = 297,
    T_LSHIFTASSIGN = 298,
    T_RSHIFTASSIGN = 299,
    T_ANDASSIGN = 300,
    T_XORASSIGN = 301,
    T_ORASSIGN = 302,
    T_LAND = 303,
    T_LOR = 304,
    T_LEQUAL = 305,
    T_LNEQUAL = 306,
    T_LLESSEQ = 307,
    T_LMOREEQ = 308,
    T_LSHIFT = 309,
    T_RSHIFT = 310,
    T_NUMBER = 311,
    T_ID = 312,
    T_COMMENT = 313,
    T_RETURN = 314,
    T_SIZE_OF = 315,
    T_ELSE = 316,
    T_IF = 317,
    T_WHILE = 318,
    T_DO = 319
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 17 "src/parser.y" /* yacc.c:1909  */

  const ASTNode *node;
  double number;
  std::string *string;

#line 141 "src/parser.tab.hpp" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SRC_PARSER_TAB_HPP_INCLUDED  */
