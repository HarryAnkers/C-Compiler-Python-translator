%code requires{
  #include "ast.hpp"

  #include <cassert>

  extern const MainBody *g_root; // A way of getting the AST out

  //! This is to fix problems when generating C++
  // We are declaring the functions provided by Flex, so
  // that Bison generated code can call them.
  int yylex(void);
  void yyerror(const char *);
}

// Represents the value associated with any kind of
// AST node.
%union{
  const MainBody *compptr;
  const Expression *expr;
  double number;
  std::string *string;
}

%token T_LSQBRACKET T_RSQBRACKET T_LCUBRACKET T_RCUBRACKET T_LTRIBRACKET T_RTRIBRACKET T_LBRACKET T_RBRACKET
%token T_ASSIGN T_DOT T_COMMA T_COLON T_SEMICOLON T_SPEACHMARK T_APOSTROPHE
%token T_LAND T_LOR T_LNOT T_LEQUAL T_LNOTEQUAL T_LLESSEQUAL T_LMOREEQUAL T_LMORE T_LLESS
%token T_INT T_DOUBLE T_STRING T_BOOL T_VOID
%token T_TIMES T_DIVIDE T_PLUS T_MINUS T_EXPONENT
%token T_LOG T_EXP T_SQRT
%token T_NUMBER T_ID 
%token T_RETURN T_ELSE T_IF T_WHILE

%type <compptr> MAIN_BODY FUNCTION_LIST DEC_FUNCTION BODY
%type <compptr> STATEMENT RETURN_STATEMENT DEC_VARIABLE ASSIGN_STATEMENT FUNCTION_STATEMENT
%type <compptr> IFANDORELIF IF_STATEMENT ELSE_IF_STATEMENT ELSE_STATEMENT IFANDORELSEORELIF
%type <compptr> WHILE_STATEMENT
%type <compptr> ARGUMENT_LIST ARGUMENT_LIST_NO_TYPE
%type <expr> EXPR EXPR_TOP TERM FACTOR CONDITION
%type <number> T_NUMBER
%type <string> T_ID 
%type <string> T_LOG T_EXP T_SQRT
%type <string> TYPE T_INT T_DOUBLE T_STRING T_BOOL T_VOID

%start ROOT

%%
//syntax notes P_ means its a primative

ROOT : MAIN_BODY { g_root = $1; }

//choose main in main body so it gets priority
MAIN_BODY : FUNCTION_LIST {$$ = $1; }

FUNCTION_LIST : FUNCTION_LIST DEC_FUNCTION      {$$ = new Function_List($2,$1);}
        | FUNCTION_LIST DEC_VARIABLE             {$$ = new Function_List($2,$1);}
        | DEC_FUNCTION                              {$$ = $1;}
        | DEC_VARIABLE

DEC_FUNCTION : TYPE T_ID T_LBRACKET ARGUMENT_LIST T_RBRACKET T_LCUBRACKET BODY T_RCUBRACKET {$$ = new Function(*$1, *$2, $4, $7);}

ARGUMENT_LIST : ARGUMENT_LIST T_COMMA TYPE T_ID     {$$ = new Argument(*$3, *$4, $1);}
     | TYPE T_ID                                     {$$ = new Argument(*$1, *$2);}
        | %empty                                        {$$ = new Argument();}

ARGUMENT_LIST_NO_TYPE : ARGUMENT_LIST_NO_TYPE T_COMMA T_ID      {$$ = new ArgumentNoType(*$3, $1);}
        | T_ID                                                      {$$ = new ArgumentNoType(*$1);}
        | %empty                                                    {$$ = new ArgumentNoType();}

TYPE : T_INT      {$$=$1;}
        | T_DOUBLE    {$$=$1;}
        | T_STRING    {$$=$1;}
        | T_VOID      {$$=$1;}
        | T_BOOL      {$$=$1;}

BODY : BODY STATEMENT   {$$ = new Body($2,$1);}
        | STATEMENT         {$$ = $1;}
        | %empty          {$$ = new Body();}
    
STATEMENT :  RETURN_STATEMENT       {$$=$1;}
        | DEC_VARIABLE                   {$$=$1;}
        | FUNCTION_STATEMENT            {$$=$1;}
        | ASSIGN_STATEMENT              {$$=$1;}
        | IFANDORELSEORELIF             {$$=$1;}
        | WHILE_STATEMENT               {$$=$1;}

RETURN_STATEMENT : T_RETURN EXPR T_SEMICOLON {$$ = new ReturnStatement($2);}

DEC_VARIABLE : TYPE T_ID T_ASSIGN EXPR T_SEMICOLON   {$$ = new DeclareStatement(*$1, *$2, $4);}  
        | TYPE T_ID T_SEMICOLON                         {$$ = new DeclareStatement(*$1, *$2);}

ASSIGN_STATEMENT : T_ID T_ASSIGN EXPR T_SEMICOLON {$$ = new AssignStatement(*$1, $3);}

FUNCTION_STATEMENT : T_ID T_LBRACKET ARGUMENT_LIST_NO_TYPE T_RBRACKET T_SEMICOLON {$$ = new FunctionStatement(*$1,$3);}

IFANDORELSEORELIF : IFANDORELIF ELSE_STATEMENT  {$$=new IfElseList($1, $2);}
        | IFANDORELIF                           {$$=$1;}

IFANDORELIF : IFANDORELIF ELSE_IF_STATEMENT     {$$=new IfElseList($1, $2);}
        | IF_STATEMENT                          {$$=$1;}

WHILE_STATEMENT : T_WHILE CONDITION T_LCUBRACKET BODY T_RCUBRACKET   {$$ = new While_Statement($2,$4);}

IF_STATEMENT : T_IF CONDITION  T_LCUBRACKET BODY T_RCUBRACKET   {$$ = new If_Statement($2,$4);}

ELSE_IF_STATEMENT : T_ELSE T_IF CONDITION T_LCUBRACKET BODY T_RCUBRACKET   {$$ = new ElIf_Statement($3,$5);}

ELSE_STATEMENT : T_ELSE T_LCUBRACKET BODY T_RCUBRACKET   {$$ = new Else_Statement ($3);}

CONDITION :  CONDITION T_LEQUAL CONDITION   {$$ = new LEqual($1,$3);}
        | CONDITION T_LAND CONDITION        {$$ = new LAnd($1,$3);}
        | CONDITION T_LOR CONDITION         {$$ = new LOr($1,$3);}
        | T_LNOT CONDITION                  {$$ = new LNot($2);}
        | CONDITION T_LNOTEQUAL CONDITION   {$$ = new LNotEqual($1,$3);}
        | CONDITION T_LMORE CONDITION       {$$ = new LMore($1,$3);}
        | CONDITION T_LLESS CONDITION       {$$ = new LLess($1,$3);}
        | CONDITION T_LMOREEQUAL CONDITION  {$$ = new LMoreEqual($1,$3);}
        | CONDITION T_LLESSEQUAL CONDITION  {$$ = new LLessEqual($1,$3);}
        | EXPR                              {$$ = $1;}
        | T_LBRACKET CONDITION T_RBRACKET   {$$ = $2;}

EXPR_TOP : EXPR                             {$$=$1;}
        | T_SPEACHMARK T_ID T_SPEACHMARK    {$$= new String(*$2);}
        | T_APOSTROPHE T_ID T_APOSTROPHE    {$$= new Char(*$2);}

EXPR : TERM                                 { $$ = $1; }
        | EXPR T_PLUS TERM                  { $$ = new AddOperator( $1 , $3 ); }
        | EXPR T_MINUS TERM                 { $$ = new SubOperator( $1 , $3 ); }

TERM : FACTOR                       { $$ = $1; }
        | TERM T_TIMES FACTOR       { $$ = new MulOperator( $1 , $3 ); }
        | TERM T_DIVIDE FACTOR      { $$ = new DivOperator( $1 , $3 ); }
        | FACTOR T_EXPONENT TERM    { $$ = new ExpOperator( $1 , $3 ); }

FACTOR : T_NUMBER                           { $$ = new Number( $1 ); }
        | T_LBRACKET EXPR T_RBRACKET        { $$ = $2; }
        | T_ID                              { $$ = new Variable( *$1 );}
        | T_LOG T_LBRACKET EXPR T_RBRACKET  { $$ = new LogFunction( $3 ); }
        | T_EXP T_LBRACKET EXPR T_RBRACKET  { $$ = new ExpFunction( $3 ); }
        | T_SQRT T_LBRACKET EXPR T_RBRACKET { $$ = new SqrtFunction( $3 ); }
%%

const MainBody *g_root; // Definition of variable (to match declaration earlier)

const MainBody *parseAST()
{
  g_root=0;
  yyparse();
  return g_root;
}