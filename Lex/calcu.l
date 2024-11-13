%{
    #include <stdio.h>
    #include <stdlib.h>
    int i=0,values[2];
    char op;
%}

digit [0-9]
operator ("-"|"*"|"+"|"/"|"%")
%%
{digit}+   { values[i++] = atoi(yytext); };
{operator} { op = yytext[0]; };
.          { };
%%

int yywrap(void){}

int main() {

	printf("\nEnter the operation: \n");

	yylex();
	
	int result;
	
	switch (op) {
		case '+':
			result = values[0] + values[1];
			break;
		case '-':
			result = values[0] - values[1];
			break;
		case '*':
			result = values[0] * values[1];
			break;
		case '/':
			result = values[0] / values[1];
			break;
		case '%':
			result = values[0] % values[1];
			break;
	}
	
	printf("\nResult: %d", result);

	printf("\n\n");

	return 0;
}