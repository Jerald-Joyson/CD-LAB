#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

struct Expression
{
    char op1[5], op2[5], op[2], result[5];
    int isRemoved;
};

void propogateConstant(struct Expression expressions[], int ne, int current, int result)
{
    char res_copy[5];
    sprintf(res_copy, "%d", result);
    for (int i = current + 1; i < ne; i++)
    {
        if (strcmp(expressions[current].result, expressions[i].op1) == 0)
        {
            strcpy(expressions[i].op1, res_copy);
        }
        if (strcmp(expressions[current].result, expressions[i].op2) == 0)
        {
            strcpy(expressions[i].op2, res_copy);
        }
    }
}

void scanQuadruples(struct Expression expressions[], int ne)
{
    int result;
    for (int i = 0; i < ne; i++)
    {
        printf("processing: %s %s %s %s\n", expressions[i].op, expressions[i].op1, expressions[i].op2, expressions[i].result);
        if ((isdigit(expressions[i].op1[0]) && isdigit(expressions[i].op2[0])) || strcmp(expressions[i].op, "=") == 0)
        {
            int op1 = atoi(expressions[i].op1);
            int op2 = atoi(expressions[i].op2);

            switch (expressions[i].op[0])
            {
            case '+':
                result = op1 + op2;
                break;

            case '-':
                result = op1 - op2;
                break;

            case '*':
                result = op1 * op2;
                break;
            case '/':
                result = op1 / op2;
                break;

            case '=':
                result = op1;
                break;

            default:
                break;
            }
            if (strcmp(expressions[i].op, "=") != 0)
            {
                expressions[i].isRemoved = 1;
            }
            printf("optimised: %s %s %s %s -> result: %d\n", expressions[i].op, expressions[i].op1, expressions[i].op2, expressions[i].result, result);

            propogateConstant(expressions, ne, i, result);
        }
    }
}

int main()
{
    struct Expression expressions[100];
    int ne;

    printf("Enter the no of expressions: ");
    scanf("%d", &ne);
    printf("Enter the input:-\n");

    for (int i = 0; i < ne; i++)
    {
        scanf("%s %s %s %s", expressions[i].op, expressions[i].op1, expressions[i].op2, expressions[i].result);
        expressions[i].isRemoved = 0;
    }

    scanQuadruples(expressions, ne);

    printf("Optimised code:-\n");
    for (int i = 0; i < ne; i++)
    {
        if (!expressions[i].isRemoved)
        {
            printf("%s %s %s %s\n", expressions[i].op, expressions[i].op1, expressions[i].op2, expressions[i].result);
        }
    }
}
