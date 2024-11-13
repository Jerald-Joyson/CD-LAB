#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ProductionRule
{
    char left[10];
    char right[10];
};

int main()
{
    char *token1, *token2, prod[10], input[100], stack[100] = "";

    int np;
    struct ProductionRule rules[10];

    printf("Enter the no of productions: ");
    scanf("%d", &np);

    printf("Enter the productions\n");
    for (int i = 0; i < np; i++)
    {
        scanf("%s", prod);
        token1 = strtok(prod, "->");
        token2 = strtok(NULL, "->");
        strcpy(rules[i].left, token1);
        strcpy(rules[i].right, token2);
    }

    printf("Enter the input string: ");
    scanf("%s", input);

    int i = 0;
    while (1)
    {
        if (i < strlen(input))
        {
            char temp[2];
            temp[0] = input[i];
            temp[1] = '\0';
            i++;

            strcat(stack, temp);
            printf("%-16s ", stack);
            for (int j = i; j < strlen(input); j++)
            {
                printf("%c", input[j]);
            }

            printf("\t\t Shift %s\n", temp);
        }

        for (int j = 0; j < np; j++)
        {
            char *substring = strstr(stack, rules[j].right);
            if (substring != NULL)
            {
                int stack_top = strlen(stack) - strlen(substring);
                stack[stack_top] = '\0';
                strcat(stack, rules[j].left);
                printf("%-16s ", stack);
                for (int j = i; j < strlen(input); j++)
                {
                    printf("%c", input[j]);
                }
                printf("\t\t Reduce %s->%s\n", rules[j].left, rules[j].right);
                j = -1;
            }
        }

        if (strcmp(stack, rules[0].left) == 0 && i == strlen(input))
        {
            printf("String successfully parsed\n");
            break;
        }
        else if (i == strlen(input))
        {
            printf("Invalid String\n");
            break;
        }
    }
}