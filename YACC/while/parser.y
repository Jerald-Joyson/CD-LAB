%{
#include "y.tab.h"
#include <stdio.h>
#include <stdlib.h>
int yyerror(char *s);
int yylex(void);
%}

%token WHILE BROPEN BRCLOSE DTYPE COPEN CCLOSE QUOTES OPE ID RELOP COMMA SEMI INC PER DIGIT NL

%%

ST: S NL {printf("valid while loop\n"); exit(0);}
S: WHILE BROPEN EXP BRCLOSE COPEN T CCLOSE
EXP: ID RELOP DIGIT |  ID RELOP ID  ;
T:ID BROPEN F BRCLOSE SEMI ID INC SEMI | ;
F:QUOTES PER ID QUOTES COMMA ID | ;

%%

int yyerror(char *s) {
    printf("invalid while syntax\n");
    return 1;
}

int main() {
    printf("enter the file syntax\n");
    yyparse();
    return 0;
}