%code requires{
  #include "ast.hpp"

  #include <cassert>

  extern const ASTNode *g_root; // A way of getting the AST out

  //! This is to fix problems when generating C++
  // We are declaring the functions provided by Flex, so
  // that Bison generated code can call them.
  int yylex(void);
  void yyerror(const char *);
}

// Represents the value associated with any kind of
// AST node.
%union{
  const ASTNode *node;
  double number;
  std::string *string;
}

%token T_LSQBRACKET T_RSQBRACKET T_LCUBRACKET T_RCUBRACKET T_LTRIBRACKET T_RTRIBRACKET T_LBRACKET T_RBRACKET
%token T_ASSIGN T_DOT T_COMMA T_COLON T_QMARK T_SEMICOLON T_SPEACHMARK T_APOSTROPHE
%token T_NOT T_AND T_OR T_MORE T_LESS T_XOR T_TILDA
%token T_INT T_DOUBLE T_STRING T_BOOL T_VOID T_LONG
%token T_TIMES T_DIVIDE T_PLUS T_MINUS T_MODULUS T_INC T_DEC
%token T_ADDASSIGN T_SUBASSIGN T_MULASSIGN T_DIVASSIGN T_MODASSIGN 
%token T_LSHIFTASSIGN T_RSHIFTASSIGN T_ANDASSIGN T_XORASSIGN T_ORASSIGN
%token T_LAND T_LOR T_LEQUAL T_LNEQUAL T_LLESSEQ T_LMOREEQ T_LSHIFT T_RSHIFT
%token T_NUMBER T_ID T_COMMENT
%token T_RETURN T_SIZE_OF T_ELSE T_IF T_WHILE T_DO

%type <node> TOP_LEVEL TOP_LIST DEC_FUNCTION BODY
%type <node> STATEMENT RETURN_STATEMENT DEC_VARIABLE FUNCTION_STATEMENT
%type <node> IFANDORELIF IF_STATEMENT ELSE_IF_STATEMENT ELSE_STATEMENT IFANDORELSEORELIF
%type <node> WHILE_STATEMENT DO_STATEMENT GLO_DEC_VARIABLE NEW_SCOPE
%type <node> ARGUMENT_LIST ARGUMENT_LIST_NO_TYPE
%type <node> EXPR TERM FACTOR CONDITIONOP ASSIGNOP BITWISEOP
%type <node> NUMBER
%type <number> T_NUMBER
%type <string> T_ID
%type <string> TYPE T_INT T_DOUBLE T_STRING T_BOOL T_VOID T_LONG

%start ROOT

%%
//syntax notes P_ means its a primative

ROOT : TOP_LEVEL { g_root = $1; }

//choose main in main body so it gets priority
TOP_LEVEL : TOP_LIST {$$ = $1; }

TOP_LIST : TOP_LIST DEC_FUNCTION      {$$ = new Top_List($2,$1);}
        | TOP_LIST GLO_DEC_VARIABLE            {$$ = new Top_List($2,$1);}
        | DEC_FUNCTION                          {$$ = $1;}
        | GLO_DEC_VARIABLE                          {$$ = $1;}

DEC_FUNCTION : TYPE T_ID T_LBRACKET ARGUMENT_LIST T_RBRACKET T_LCUBRACKET BODY T_RCUBRACKET {$$ = new Function(*$1, *$2, $4, $7);}

ARGUMENT_LIST : ARGUMENT_LIST T_COMMA TYPE T_ID         {$$ = new Argument(*$3, *$4, $1);}
        | TYPE T_ID                                     {$$ = new Argument(*$1, *$2);}
        | %empty                                        {$$ = new Argument();}

ARGUMENT_LIST_NO_TYPE : ARGUMENT_LIST_NO_TYPE T_COMMA EXPR      {$$ = new ArgumentNoType($3, $1);}
        | EXPR                                                  {$$ = new ArgumentNoType($1);}
        | %empty                                                {$$ = new ArgumentNoType();}

TYPE : T_INT      {$$=$1;}
        | T_DOUBLE    {$$=$1;}
        | T_STRING    {$$=$1;}
        | T_VOID      {$$=$1;}
        | T_LONG        {$$=$1;}

BODY : BODY STATEMENT   {$$ = new Body($2,$1);}
        | STATEMENT         {$$ = $1;}
        | %empty          {$$ = new Body();}
    
STATEMENT :  RETURN_STATEMENT       {$$=$1;}
        | DEC_VARIABLE                   {$$=$1;}
        | FUNCTION_STATEMENT            {$$=$1;}
        | EXPR T_SEMICOLON              {$$= new ExprStatement($1);}
        | IFANDORELSEORELIF             {$$=$1;}
        | WHILE_STATEMENT               {$$=$1;}
        | DO_STATEMENT                  {$$=$1;}
        | NEW_SCOPE                     {$$=$1;}

NEW_SCOPE : T_LCUBRACKET BODY T_RCUBRACKET      {$$ = new NewScope($2);}
        | T_LCUBRACKET T_RCUBRACKET             {;}

RETURN_STATEMENT : T_RETURN EXPR T_SEMICOLON {$$ = new ReturnStatement($2);}

DEC_VARIABLE : TYPE T_ID T_ASSIGN EXPR T_SEMICOLON   {$$ = new DeclareStatement(*$1, *$2, $4);}  
        | TYPE T_ID T_SEMICOLON                         {$$ = new DeclareStatement(*$1, *$2);}

GLO_DEC_VARIABLE : TYPE T_ID T_ASSIGN EXPR T_SEMICOLON      {$$ = new GlobalDeclareStatement(*$1, *$2, $4);}  
        | TYPE T_ID T_SEMICOLON                                 {$$ = new GlobalDeclareStatement(*$1, *$2);}

FUNCTION_STATEMENT : T_ID T_LBRACKET ARGUMENT_LIST_NO_TYPE T_RBRACKET T_SEMICOLON {$$ = new FunctionStatement(*$1,$3);}

IFANDORELSEORELIF : IFANDORELIF ELSE_STATEMENT  {$$=new IfElseList($1, $2);}
        | IFANDORELIF                           {$$=$1;}

IFANDORELIF : IFANDORELIF ELSE_IF_STATEMENT     {$$=new IfElseList($1, $2);}
        | IF_STATEMENT                          {$$=$1;}

WHILE_STATEMENT : T_WHILE EXPR T_LCUBRACKET BODY T_RCUBRACKET   {$$ = new While_Statement($2,$4);}

DO_STATEMENT : T_DO T_LCUBRACKET BODY T_RCUBRACKET T_WHILE EXPR T_SEMICOLON  {$$ = new Do_While_Statement($3,$6);}

IF_STATEMENT : T_IF EXPR  T_LCUBRACKET BODY T_RCUBRACKET   {$$ = new If_Statement($2,$4);}

ELSE_IF_STATEMENT : T_ELSE T_IF EXPR T_LCUBRACKET BODY T_RCUBRACKET   {$$ = new ElIf_Statement($3,$5);}

ELSE_STATEMENT : T_ELSE T_LCUBRACKET BODY T_RCUBRACKET   {$$ = new Else_Statement ($3);}



EXPR : TERM                                 { $$ = $1; }
        | EXPR T_PLUS TERM                  { $$ = new AddOperator( $1 , $3 ); }
        | EXPR T_MINUS TERM                 { $$ = new SubOperator( $1 , $3 ); }
        | T_ID T_INC                        {$$ = new AssignOp(*$1, new AddOperator(new Variable(*$1), new Number(1,0)));}
        | T_ID T_DEC                        {$$ = new AssignOp(*$1, new SubOperator(new Variable(*$1), new Number(1,0)));}
        | ASSIGNOP                          { $$ = $1; }
        | BITWISEOP                         { $$ = $1; }
        | CONDITIONOP                       { $$ = $1; }

TERM : FACTOR                       { $$ = $1; }
        | TERM T_TIMES FACTOR       { $$ = new MulOperator( $1 , $3 ); }
        | TERM T_DIVIDE FACTOR      { $$ = new DivOperator( $1 , $3 ); }
        | TERM T_MODULUS FACTOR     { $$ = new ModOperator( $1 , $3 ); }

FACTOR : T_LBRACKET EXPR T_RBRACKET    { $$ = $2;}
        | T_ID T_LBRACKET ARGUMENT_LIST_NO_TYPE T_RBRACKET {$$ = new FunctionStatementInExpr(*$1,$3);}
        | NUMBER                {$$ = $1; }
        | T_ID                    { $$ = new Variable( *$1 );}
        | T_SIZE_OF T_ID             {$$ = new SizeOf(*$2);}
        | EXPR T_QMARK EXPR T_COLON EXPR        {$$ = new TenOp($1,$3,$5);} 

NUMBER : T_NUMBER                       { $$ = new Number( $1 , 0 ); }
        | T_MINUS T_NUMBER              { $$ = new Number( 0 , $2 );}

BITWISEOP : EXPR T_AND TERM             {$$ = new BAnd($1,$3);}
        | EXPR T_OR TERM                {$$ = new BOr($1,$3);}
        | EXPR T_XOR TERM               {$$ = new BXor($1,$3);}
        | T_TILDA TERM                  {$$ = new BNot($2);}
        | EXPR T_LSHIFT TERM            {$$ = new BLShift($1,$3);}
        | EXPR T_RSHIFT TERM            {$$ = new BRShift($1,$3);}

ASSIGNOP : T_ID T_ASSIGN EXPR                   {$$ = new AssignOp(*$1, $3);}
        | T_ID T_ADDASSIGN EXPR             {$$ = new AssignOp(*$1, new AddOperator(new Variable(*$1), $3));}
        | T_ID T_SUBASSIGN EXPR            {$$ = new AssignOp(*$1, new SubOperator(new Variable(*$1), $3));}
        | T_ID T_MULASSIGN EXPR            {$$ = new AssignOp(*$1, new MulOperator(new Variable(*$1), $3));}
        | T_ID T_DIVASSIGN EXPR           {$$ = new AssignOp(*$1, new DivOperator(new Variable(*$1), $3));}
        | T_ID T_MODASSIGN EXPR          {$$ = new AssignOp(*$1, new ModOperator(new Variable(*$1), $3));}
        | T_ID T_LSHIFTASSIGN EXPR      {$$ = new AssignOp(*$1, new BLShift(new Variable(*$1), $3));}
        | T_ID T_RSHIFTASSIGN EXPR      {$$ = new AssignOp(*$1, new BRShift(new Variable(*$1), $3));}
        | T_ID T_ANDASSIGN EXPR              {$$ = new AssignOp(*$1, new BAnd(new Variable(*$1), $3));}
        | T_ID T_ORASSIGN EXPR               {$$ = new AssignOp(*$1, new BOr(new Variable(*$1), $3));}
        | T_ID T_XORASSIGN EXPR              {$$ = new AssignOp(*$1, new BXor(new Variable(*$1), $3));}

CONDITIONOP :  EXPR T_LEQUAL TERM   {$$ = new LEqual($1,$3);}
        | EXPR T_LAND TERM       {$$ = new LAnd($1,$3);}
        | EXPR T_LOR TERM         {$$ = new LOr($1,$3);}
        | T_NOT TERM                       {$$ = new LNot($2);}
        | EXPR T_LNEQUAL TERM    {$$ = new LNotEqual($1,$3);}
        | EXPR T_MORE TERM            {$$ = new LMore($1,$3);}
        | EXPR T_LESS TERM            {$$ = new LLess($1,$3);}
        | EXPR T_LMOREEQ TERM   {$$ = new LMoreEqual($1,$3);}
        | EXPR T_LLESSEQ TERM   {$$ = new LLessEqual($1,$3);}
%%

const ASTNode *g_root; // Definition of variable (to match declaration earlier)

const ASTNode *parseAST()
{
  g_root=0;
  yyparse();
  return g_root;
}