%{
#include <stdio.h>
#include <ctype.h>

%}

%%
[a-z]+  {for(int i=0;yytext[i]!='\0';i++){yytext[i] = toupper(yytext[i]); }printf("%s\n",yytext);}

%%

int yywrap(void){}
int main(){

extern FILE *yyin;
yyin = fopen("file.txt","r");
yylex();
return 0;
}
