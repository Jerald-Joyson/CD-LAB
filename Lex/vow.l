%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int vow = 0,cons = 0;
char v[100],c[100];
%}

vowel [AEIOUaeiou]
consonent [BCDFGHJKLMNPQRSTVWXYZbcdfghjklmnpqrstvwxyz]

%%

{vowel}      { vow++; strcat(v,yytext); };
{consonent}  { cons++; strcat(c,yytext); };
.            { };

%%

    int yywrap(void){}

    int main(){

        //printf("Enter the string: ");

        extern FILE *yyin;
        yyin = fopen("file.txt","r");
        yylex();

        printf("no of vowels: %d\n",vow);
        printf("no of consonents: %d\n",cons);
        printf("no of vowels: %s\n",v);
        printf("no of consonents: %s\n",c);

        return 0;
    }