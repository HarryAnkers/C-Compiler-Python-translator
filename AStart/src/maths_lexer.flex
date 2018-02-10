%option noyywrap

%{
// Avoid error "error: `fileno' was not declared in this scope"
extern "C" int fileno(FILE *stream);

#include "maths_parser.tab.hpp"
%}

%%

//main
[main]          { return T_MAIN; }

//BRACKET SYMBOLS
[(]             { return T_LSQBRACKET; }
[)]             { return T_RSQBRACKET; }
[{]             { return T_LCUBRACKET; }
[}]             { return T_RCUBRACKET; }
[(]             { return T_LBRACKET; }
[)]             { return T_RBRACKET; }

//SYMBOLS
[=]             { return T_ASSIGN; }
[.]             { return T_DOT; }
[,]             { return T_COMMA; }
[:]             { return T_COLON; }
[;]             { return T_SEMICOLON; }

//TYPES
[int]		{ return T_INT; }
[double]	{ return T_DOUBLE; }
[string]	{ return T_STRING; }
[bool]		{ return T_BOOL; }
[void]		{ return T_VOID; }

//LOGICAL OPERATORS
[&&]		{ return T_LAND; }
[||]		{ return T_LOR; }
[==]		{ return T_LEQUAL; }
[!=]		{ return T_LNOTEQUAL; }
[<=]		{ return T_LMOREORLESS; }
[>=]		{ return T_LMOREOREQUAL; }

//MATHS OPERATORS
[*]             { return T_TIMES; }
[/]             { return T_DIVIDE; }
[+]             { return T_PLUS; }
[-]             { return T_MINUS; }
[\^]             { return T_EXPONENT; }

log             { return T_LOG;   }
exp             { return T_EXP; }
sqrt            { return T_SQRT; }

[-]?[0-9]+([.][0-9]*)? { yylval.number=strtod(yytext, 0); return T_NUMBER; }

([A-Z][a-z])+          { yylval.string=new std::string(yytext); return T_VARIABLE; }

[ \t\r\n]+		{;}

.               { fprintf(stderr, "Invalid token\n"); exit(1); }
%%

void yyerror (char const *s)
{
  fprintf (stderr, "Parse error : %s\n", s);
  exit(1);
}
