%option noyywrap

%{
// Avoid error "error: `fileno' was not declared in this scope"
extern "C" int fileno(FILE *stream);

#include "parser.tab.hpp"
%}

%%


[[]             { return T_LSQBRACKET; }
[]]             { return T_RSQBRACKET; }
[{]             { return T_LCUBRACKET; }
[}]             { return T_RCUBRACKET; }
[<]             { return T_LTRIBRACKET; }
[>]             { return T_RTRIBRACKET; }
[(]             { return T_LBRACKET; }
[)]             { return T_RBRACKET; }

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
"bool"		{ yylval.string=new std::string(yytext); return T_BOOL; }
"void"		{ yylval.string=new std::string(yytext); return T_VOID; }

"&&"		{ return T_LAND; }
"||"		{ return T_LOR; }
"=="		{ return T_LEQUAL; }
"!="		{ return T_LNOTEQUAL; }
"<="		{ return T_LLESSOREQUAL; }
">="		{ return T_LMOREOREQUAL; }

[*]             { return T_TIMES; }
[/]             { return T_DIVIDE; }
[+]             { return T_PLUS; }
[-]             { return T_MINUS; }
[\^]             { return T_EXPONENT; }

"log"             { return T_LOG;   }
"exp"             { return T_EXP; }
"sqrt"            { return T_SQRT; }

"return"            { return T_RETURN; }

[-]?[0-9]+([.][0-9]*)? { yylval.number=strtod(yytext, 0); return T_NUMBER; }

([A-Z]|[a-z])+          { yylval.string=new std::string(yytext); return T_ID; }

[ \t\r\n]+		{;}

.               { fprintf(stderr, "Invalid token\n"); exit(1); }
%%

void yyerror (char const *s)
{
  fprintf (stderr, "Parse error : %s\n", s);
  exit(1);
}
