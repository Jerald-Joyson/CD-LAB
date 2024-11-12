

%{
#include "y.tab.h"
#include <stdio.h>
#include <stdlib.h>
%}

digit   [0-9]
letter  [a-zA-Z]
%%
{digit}   { return DIGIT; }
"while "   { return WHILE; }
"("       { return BROPEN; }
")"       { return BRCLOSE; }
"int "|"float "|"char "|"double "    { return DTYPE; }
"{"     { return COPEN; }
"}"     { return CCLOSE; }
\"      { return QUOTES; }
"%"     { return PER; }
(" ")      {}
{letter}({letter}|{digit}*)*     { return ID; }
">"|"<"|"<="|">="|"=="|"!="   { return RELOP; }
","     { return COMMA; }
";"     { return SEMI; }
"++"|"--"   { return INC; } 
\n     { return NL; }
.      { return yytext[0]; }
%%

int yywrap(void){}