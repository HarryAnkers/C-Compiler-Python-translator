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

"&&"		{ return T_LAND; }
"||"		{ return T_LOR; }
"=="		{ return T_LEQUAL; }
[!]		  { return T_LNOT; }
"!="		{ return T_LNOTEQUAL; }
"<="		{ return T_LLESSEQUAL; }
">="		{ return T_LMOREEQUAL; }
[<]     { return T_LMORE; }
[>]     { return T_LLESS; }

[=]             { return T_ASSIGN; }
[.]             { return T_DOT; }
[,]             { return T_COMMA; }
[:]             { return T_COLON; }
[;]             { return T_SEMICOLON; }
[\"]             { return T_SPEACHMARK; }
[']             { return T_APOSTROPHE; }

"int"   	{ yylval.string=new std::string(yytext); return T_INT; }
"double"	{ yylval.string=new std::string(yytext); return T_DOUBLE; }
"string"	{ yylval.string=new std::string(yytext); return T_STRING; }
"void"		{ yylval.string=new std::string(yytext); return T_VOID; }

[*]             { return T_TIMES; }
[/]             { return T_DIVIDE; }
[+]             { return T_PLUS; }
[-]             { return T_MINUS; }
[\^]             { return T_EXPONENT; }

"return"            { return T_RETURN; }
"while"            { return T_WHILE; }
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