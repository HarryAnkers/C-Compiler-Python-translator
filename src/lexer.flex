%option noyywrap

%{
// Avoid error "error: `fileno' was not declared in this scope"
extern "C" int fileno(FILE *stream);

#include "parser.tab.hpp"
%}
%%

"//".*          { ; }

[[]             { return T_LSQBRACKET; }
[]]             { return T_RSQBRACKET; }
[{]             { return T_LCUBRACKET; }
[}]             { return T_RCUBRACKET; }
[(]             { return T_LBRACKET; }
[)]             { return T_RBRACKET; }

"+="    { return T_ADDASSIGN; }
"-="    { return T_SUBASSIGN; }
"*="    { return T_MULASSIGN; }
"/="    { return T_DIVASSIGN; }
"%="    { return T_MODASSIGN; }
"<<="   { return T_LSHIFTASSIGN; }
">>="   { return T_RSHIFTASSIGN; }
"&="    { return T_ANDASSIGN; }
"^="    { return T_XORASSIGN; }
"|="    { return T_ORASSIGN; }

"&&"    { return T_LAND; }
"||"    { return T_LOR; }
"=="    { return T_LEQUAL; }
"!="    { return T_LNEQUAL; }
"<="    { return T_LLESSEQ; }
">="    { return T_LMOREEQ; }

"<<"    { return T_LSHIFT; }
">>"    { return T_RSHIFT; }

"++"    { return T_INC; }
"--"    { return T_DEC; }

[&]		  { return T_AND; }
[|]		  { return T_OR; }
[!]		  { return T_NOT; }
[>]     { return T_MORE; }
[<]     { return T_LESS; }
[~]     { return T_TILDA; }
[\^]    { return T_XOR; }

[=]             { return T_ASSIGN; }
[.]             { return T_DOT; }
[,]             { return T_COMMA; }
[:]             { return T_COLON; }
[;]             { return T_SEMICOLON; }
[\"]             { return T_SPEACHMARK; }
[']             { return T_APOSTROPHE; }
[?]             { return T_QMARK; }

"char"                   { yylval.string=new std::string("char"); return T_CHAR; }

"signed char"            { yylval.string=new std::string("signed char"); return T_SIGN_CHAR; }

"unsigned char"          { yylval.string=new std::string("unsigned char"); return T_UNSIGN_CHAR; }

"short"                  { yylval.string=new std::string("short"); return T_SHORT; }
"short int"              { yylval.string=new std::string("short"); return T_SHORT; }
"signed short"           { yylval.string=new std::string("short"); return T_SHORT; }
"signed short int"       { yylval.string=new std::string("short"); return T_SHORT; }

"unsigned short"         { yylval.string=new std::string("unsigned short"); return T_UNSIGN_SHORT; }
"unsigned short int"     { yylval.string=new std::string("unsigned short"); return T_UNSIGN_SHORT; }

"int"                    { yylval.string=new std::string("int"); return T_INT; }
"signed"                 { yylval.string=new std::string("int"); return T_INT; }
"signed int"             { yylval.string=new std::string("int"); return T_INT; }

"unsigned"               { yylval.string=new std::string("unsigned int"); return T_UNSIGN_INT; }
"unsigned int"           { yylval.string=new std::string("unsigned int"); return T_UNSIGN_INT; }

"long"                   { yylval.string=new std::string("long"); return T_LONG; }
"long int"               { yylval.string=new std::string("long"); return T_LONG; }
"signed long"            { yylval.string=new std::string("long"); return T_LONG; }
"signed long int"        { yylval.string=new std::string("long"); return T_LONG; }

"unsigned long"          { yylval.string=new std::string("unsigned long"); return T_UNSIGN_LONG; }
"unsigned long int"      { yylval.string=new std::string("unsigned long"); return T_UNSIGN_LONG; }

"long long"              { yylval.string=new std::string("long long"); return T_LONGLONG; }
"long long int"          { yylval.string=new std::string("long long"); return T_LONGLONG; }
"signed long long"       { yylval.string=new std::string("long long"); return T_LONGLONG; }
"signed long long int"   { yylval.string=new std::string("long long"); return T_LONGLONG; }

"unsigned long long"     { yylval.string=new std::string("unsigned long long"); return T_UNSIGN_LONGLONG; }
"unsigned long long int" { yylval.string=new std::string("unsigned long long"); return T_UNSIGN_LONGLONG; }

"float"                  { yylval.string=new std::string("float"); return T_FLOAT; }

"double"                 { yylval.string=new std::string("double"); return T_DOUBLE; }

"long double"            { yylval.string=new std::string("long double"); return T_LONGDOUBLE; }

"void"                   { yylval.string=new std::string("void"); return T_VOID; }

"size of" {return T_SIZE_OF;}

[*]             { return T_TIMES; }
[/]             { return T_DIVIDE; }
[+]             { return T_PLUS; }
[-]             { return T_MINUS; }
[%]             { return T_MODULUS; }

"return"            { return T_RETURN; }
"while"            { return T_WHILE; }
"do"            { return T_DO; }
"if"            { return T_IF; }
"else"            { return T_ELSE; }

[0-9]+([.][0-9]*)? { yylval.number=strtod(yytext, 0); return T_NUMBER; }

([A-Z]|[a-z])+          { yylval.string=new std::string(yytext); return T_ID; }

[ \t\r\n]+		{;}

.               { fprintf(stderr, "Invalid token\n"); exit(1); }
%%

void yyerror (char const *s)
{
  fprintf (stderr, "Parse error : %s\n", s);
  exit(1);
}