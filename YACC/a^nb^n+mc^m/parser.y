%{
	#include <stdio.h>
	#include <stdlib.h>
	int yyerror(char *msg);
	#include "lex.yy.c"

%}

%token A B C NL

%%

stmt : S X NL { printf("Valid string\n"); exit(0); };
S : A S B | ;
X : B X C | ;

%%

int yyerror(char *msg) {
	printf("Invalid string\n");
	exit(0);
}

int main() {
	printf("Enter the string: ");
	yyparse();
}
