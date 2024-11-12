%{
#include <stdio.h>
#include <stdlib.h>
int yylex(void);
int yyerror(const char *s);
%}

%token FOR DTYPE ID NUMBER 
%token PLUS MINUS MULT DIV
%token AND OR NOT
%token RELOP /* <, >, <=, >=, ==, != */
%token EQUAL /* = */
%token INCREMENT DECREMENT /* ++, -- */
%token ASSIGN /* +=, -=, *=, /= */
%token SEMICOLON COMMA
%token BROPEN BRCLOSE /* (, ) */
%token STOPEN STCLOSE /* {, } */
%token SPACE NL

%%

program: 
    for_statement NL    { printf("Valid for loop statement\n"); return 0; }
    ;

for_statement:
    FOR BROPEN initialization SEMICOLON condition SEMICOLON update BRCLOSE
    ;

initialization:
    /* empty */
    | var_declaration
    | assignment_list
    ;

var_declaration:
    DTYPE declaration_list
    ;

declaration_list:
    ID EQUAL expression
    | ID
    | declaration_list COMMA ID EQUAL expression
    | declaration_list COMMA ID
    ;

assignment_list:
    assignment
    | assignment_list COMMA assignment
    ;

assignment:
    ID EQUAL expression
    | ID ASSIGN expression
    ;

condition:
    /* empty */
    | condition_expr
    ;

condition_expr:
    expression
    | expression RELOP expression
    | condition_expr AND condition_expr
    | condition_expr OR condition_expr
    | NOT condition_expr
    | BROPEN condition_expr BRCLOSE
    ;

update:
    /* empty */
    | update_list
    ;

update_list:
    update_expr
    | update_list COMMA update_expr
    ;

update_expr:
    ID INCREMENT
    | ID DECREMENT
    | INCREMENT ID
    | DECREMENT ID
    | assignment
    ;

expression:
    ID
    | NUMBER
    | ID PLUS expression
    | ID MINUS expression
    | ID MULT expression
    | ID DIV expression
    | NUMBER PLUS expression
    | NUMBER MINUS expression
    | NUMBER MULT expression
    | NUMBER DIV expression
    | BROPEN expression BRCLOSE
    ;

%%

int yyerror(const char *s) {
    printf("Error: %s\n", s);
    return 1;
}

int main() {
    printf("Enter a for loop statement: ");
    int result = yyparse();
    if (result == 0) {
        printf("Parsing completed successfully\n");
    }
    return result;
}
