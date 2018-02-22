%code requires{
  #include "ast.hpp"

  #include <cassert>

  extern const Expression *g_root; // A way of getting the AST out

  //! This is to fix problems when generating C++
  // We are declaring the functions provided by Flex, so
  // that Bison generated code can call them.
  int yylex(void);
  void yyerror(const char *);
}

// Represents the value associated with any kind of
// AST node.
%union{
  const Expression *expr;
  double number;
  std::string *string;
}

%token T_TIMES T_DIVIDE T_PLUS T_MINUS T_EXPONENT
%token T_LBRACKET T_RBRACKET T_LSQBRACKET T_RSQBRACKET T_LCUBRACKET T_RCUBRACKET
%token T_LOG T_EXP T_SQRT
%token T_NUMBER T_VARIABLE
%token T_ASSIGN T_DOT T_COMMA T_COLON T_SEMICOLON
%token T_INT T_DOUBLE T_STRING T_BOOL T_VOID
%token T_MAIN

%type <expr> EXPR TERM FACTOR TYPE FUNCTION ID T_MAIN
%type <number> T_NUMBER
%type <string> T_VARIABLE T_LOG T_EXP T_SQRT FUNCTION_NAME
%type <string> T_INT T_DOUBLE T_STRING T_BOOL T_VOID

%start ROOT

%%

ROOT : MAIN_BODY { g_root = $1; }

//choose main in main body so it gets priority
MAIN_BODY : DEC_FUNCTION
    | TYPE MAIN LBRACKET DEC_ARG RBRACKET LCURLY BODY RCURLY

DEC_FUNCTION : TYPE FUNC_ID LBRACKET RBRACKET LCURLY BODY RCURLY

//delcares a new function with the func_id and runs through body recursively arg implimented late

//this contains nothing not sure yet
DEC_ARG : DEC_ARG TYPE ARG
    | TYPE ARG

//terminal cases
TYPE : INT
    | DOUBLE
    | STRING
    | VOID
    | CHAR
    | BOOL

//recursive with each line of code left associative
BODY : STATEMENT BODY
    | STATEMENT


STATEMENT :  ASSIGN_STATEMENT
    | RETURN_STATEMENT
    | DECLARE_VAR

%%

const Expression *g_root; // Definition of variable (to match declaration earlier)

const Expression *parseAST()
{
  g_root=0;
  yyparse();
  return g_root;
}
