#include <stdio.h>
#include <string.h>
#include <ctype.h>

int priority(char c)
{
    if (c == '^')
    {
        return 3;
    }
    else if (c == '*' || c == '/')
    {
        return 2;
    }
    if (c == '+' || c == '-')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

char stack[100];
int top = -1;

void push(char c)
{
    stack[++top] = c;
}

char pop()
{
    top--;
    return stack[top + 1];
}

void infixtopostfix(char *infix, char *postfix)
{
    strcpy(postfix, "");
    int j = 0;
    for (int i = 0; i < strlen(infix); i++)
    {
        if (isalnum(infix[i]))
        {
            postfix[j++] = infix[i];
        }
        else if (infix[i] == '(')
        {
            push(infix[i]);
        }
        else if (infix[i] == ')')
        {
            while (stack[top] != '(')
            {
                postfix[j++] = pop();
            }

            pop();
        }
        else
        {
            while (priority(stack[top]) >= priority(infix[i]))
            {
                postfix[j++] = pop();
            }

            push(infix[i]);
        }
    }

    while (top >= 0)
    {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';
}

void generateThreecode(char *str)
{
    top = -1;
    int t1 = 90;
    char t2, t3;

    for (int i = 0; i < strlen(str); i++)
    {
        if (isalnum(str[i]))
        {
            push(str[i]);
        }
        else
        {
            t3 = pop();
            t2 = pop();

            printf("%c := %c %c %c\n", t1, t2, str[i], t3);
            push(t1--);
        }
    }
}
int main()
{
    char infix[100], postfix[100];
    printf("Enter the string: ");
    scanf("%s", infix);
    infixtopostfix(infix, postfix);
    generateThreecode(postfix);
}