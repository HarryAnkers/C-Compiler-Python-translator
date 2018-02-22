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
//syntax notes P_ means its a primative

ROOT : MAIN_BODY { g_root = $1; }

//choose main in main body so it gets priority
MAIN_BODY : DEC_FUNCTION

//delcares a new function with the func_id and runs through body recursively arg implimented late
DEC_FUNCTION : TYPE T_VARIABLE T_LBRACKET T_RBRACKET T_LCURLY BODY T_RCURLY {$$ = new Function($2, $6);}

//terminal cases
TYPE : T_INT      {$$=$1;}
    | T_DOUBLE    {$$=$1;}
    | T_STRING    {$$=$1;}
    | T_VOID      {$$=$1;}
    | T_CHAR      {$$=$1;}
    | T_BOOL      {$$=$1;}

//recursive with each line of code left associative
//each body contains one statement and a body pointer
BODY : STATEMENT BODY   {$$ = new Body($1,$2)}
    | STATEMENT         {$$ = new Body($1)}

STATEMENT :  ASSIGN_STATEMENT   {$$=$1;}
    | RETURN_STATEMENT          {$$=$1;}
    | DECLARE_VAR               {$$=$1;}
    | FUNCTION                  {$$=$1;}

RETURN_STATEMENT : T_RETURN EXPRESSION T_SEMICOLON {$$ = new Return($2);}

DECLARE_VAR : TYPE T_VARIABLE T_ASSIGN EXPRESSION T_SEMICOLON {$$ = new DeclareVar($2, $4);}  
    | TYPE T_VARIABLE T_SEMICOLON {$$ = new DeclareVar($2);}

FUNCTION : T_VARIABLE T_LBRACKET T_RBRACKET T_SEMICOLON;

%%

const Expression *g_root; // Definition of variable (to match declaration earlier)

const Expression *parseAST()
{
  g_root=0;
  yyparse();
  return g_root;
}