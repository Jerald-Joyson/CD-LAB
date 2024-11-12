%{
    #include <stdio.h>
    #include <stdlib.h>
    #include "lex.yy.c"
    int yyerror(char *s);
    int yylex(void);
%}

%token A B NL

%%
    stmt : S NL {printf("valid \n"); exit(0);} ;
    S  : A S B | ;

    %%
    int yyerror(char *s) {
        printf("invalid syntax");
        return 1;
    }
    int main(){
        printf("enter : ");
        yyparse();
        return 0;
    }