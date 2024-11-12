%{
#include "lex.yy.c"
#include <stdio.h>
#include <stdlib.h>
int yyerror(char *s);
%}

%token A B NL

%%
stmt : S NL {printf("valid\n"); exit(0);} ;
S : X A S B Y | Y B S A X | ;
X : A X Y | Y X A | ;
Y : B Y X | X Y B | ;
%%

int yyerror(char *s){
printf("invalid syntax \n");
exit(0);
return 1;
}

int main(){
printf("Enter the string: \n");
yyparse();
return 0;
}
