%{
#include "y.tab.h"
#include <stdio.h>
#include <stdlib.h>

%}

%%
[aA] {return A;}
[bB] {return B;}
\n   {return NL;}
.    {return yytext(0);}
%%
int yywrap(void){}
