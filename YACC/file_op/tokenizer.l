%{
    #include "y.tab.h"
    #include <stdio.h>
    #include <stdlib.h>
%}

%%
[ \t]+                        { return SPACE; }
"r"|"w"                       { return MODE; }
\"                            { return QUOTES; }
","                           { return COMMA; }
"("                           { return BROPEN; }
")"                           { return BRCLOSE; }
";"                           { return SEMI; }
"fopen"|"fclose"              { return FOP; }
\n                            { return NL; }
[A-Za-z0-9]+\.[A-Za-z0-9]+    { return FILENAME; }
.                             { return yytext[0]; }
%%

int yywrap(void) {
    return 1;
}