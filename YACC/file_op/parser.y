%{
    #include <stdio.h>
    #include <stdlib.h>
    int yyerror(const char *s);
    int yylex(void);
%}

%token SPACE FOP FILENAME MODE QUOTES COMMA BROPEN BRCLOSE SEMI NL

%%

ST      : S NL                  { printf("valid file syntax\n"); exit(0); } ;
        
S       : FOP BROPEN T BRCLOSE SEMI | FOP SPACE BROPEN T BRCLOSE SEMI ;
        
T       : QUOTES FILENAME QUOTES COMMA SPACE QUOTES MODE QUOTES 
        | QUOTES FILENAME QUOTES COMMA QUOTES MODE QUOTES ;

%%

int yyerror(const char *s) {
    printf("invalid file syntax\n");
    return 1;
}

int main() {
    printf("enter the file syntax\n");
    yyparse();
    return 0;
}