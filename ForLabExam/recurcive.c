// E -> TE'
// E' -> +TE' | $
// T -> FT'
// T' -> *FT' | $
// F -> (E) | id

#include <stdio.h>
#include <string.h>
#include <ctype.h>

char *pt;

int E();
int Edash();
int T();
int Tdash();
int F();

int Edash()
{
    if (*pt == '+')
    {
        printf("%-16s E' -> +TE'\n", pt);
        pt++;
        return (T() && Edash());
    }
    else
    {
        printf("%-16s E' -> $\n", pt);
        return 1;
    }
}

int E()
{
    printf("%-16s E -> TE'\n", pt);

    return (T() && Edash());
}

int Tdash()
{
    if (*pt == '*')
    {
        printf("%-16s T' -> *FT'\n", pt);
        ;
        pt++;
        return (F() && Tdash());
    }
    else
    {
        printf("%-16s T' -> $\n", pt);
        return 1;
    }
}

int T()
{
    printf("%-16s T -> FT'\n", pt);

    return (F() && Tdash());
}

int F()
{
    if (*pt == '(')
    {
        pt++;
        printf("%-16s F -> (E)\n", pt);
        if (E() && *pt == ')')
        {
            pt++;
            return 1;
        }
        else
            return 0;
    }
    else if (strncmp(pt, "id", 2) == 0 && !isalnum(pt[2]))
    {
        printf("%-16s F -> id\n", pt);
        pt += 2;
        return 1;
    }
    else
        return 0;
}

int main()
{
    char buffer[100];
    printf("Enter the string: ");
    scanf("%s", buffer);
    pt = buffer;
    if (E() && *pt == '\0')
    {
        printf("Valid string\n");
    }
    else
    {
        printf("invalid\n");
    }
}