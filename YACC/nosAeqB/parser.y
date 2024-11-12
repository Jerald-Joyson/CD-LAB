%{
#include "lex.yy.c"
#include <stdio.h>
#include <stdlib.h>
%}

%token A B NL

%%
stmt : S NL {printf("valid\n"); exit(0);} ;
S : S A S B S | S B S A S | ;
%%

int yyerror(char *s){
printf("invalid syntax \n");
exit(0);
return 1;
}

int main(){
printf("Enter the string: \n");
return 0;
}
