%{
#include "y.tab.h"
#include <stdio.h>
#include <stdlib.h>

int line_number = 1;
%}

digit       [0-9]
letter      [a-zA-Z]
identifier  ({letter}|_)({letter}|{digit}|_)*
number      {digit}+
whitespace  [ \t]

%%

"for"       { return FOR; }

"int"|"float"|"char"|"double"|"bool"  { return DTYPE; }

{identifier} { return ID; }

{number}    { return NUMBER; }

"+"         { return PLUS; }
"-"         { return MINUS; }
"*"         { return MULT; }
"/"         { return DIV; }

"++"        { return INCREMENT; }
"--"        { return DECREMENT; }

"+="        { return ASSIGN; }
"-="        { return ASSIGN; }
"*="        { return ASSIGN; }
"/="        { return ASSIGN; }

"="         { return EQUAL; }

"<"         { return RELOP; }
">"         { return RELOP; }
"<="        { return RELOP; }
">="        { return RELOP; }
"=="        { return RELOP; }
"!="        { return RELOP; }

"&&"        { return AND; }
"||"        { return OR; }
"!"         { return NOT; }

"("         { return BROPEN; }
")"         { return BRCLOSE; }
"{"         { return STOPEN; }
"}"         { return STCLOSE; }

","         { return COMMA; }
";"         { return SEMICOLON; }

\n          { line_number++; return NL; }
{whitespace}    { /* ignore whitespace */ }

.           { printf("Unexpected character: %s\n", yytext); }

%%

int yywrap(void) {
    return 1;
}