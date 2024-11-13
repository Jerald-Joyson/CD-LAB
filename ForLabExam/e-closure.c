#include <stdio.h>

int hasEpsilonTransition[10][10], visited[10], ns, nt, stateOne, stateTwo;

char inputSymbol;

void closure(int i)
{
    visited[i] = 1;
    for (int j = 0; j < ns; j++)
    {
        if (hasEpsilonTransition[i][j] && !visited[j])
        {
            printf(", Q%d ", j);
            closure(j);
        }
    }
}

int main()
{
    printf("Enter the number of states: ");
    scanf("%d", &ns);
    printf("\nEnter the number of input symbols: ");
    scanf("%d", &nt);
    printf("Enter transistion table:\nState Symbol State\n");
    for (int i = 0; i < nt; i++)
    {
        scanf("%d %c %d", &stateOne, &inputSymbol, &stateTwo);
        if (inputSymbol == 'e')
        {
            hasEpsilonTransition[stateOne][stateTwo] = 1;
        }
    }
    printf("Epsilon Closures:");
    for (int i = 0; i < ns; i++)
    {
        printf("State %d: { Q%d ", i, i);
        for (int j = 0; j < ns; j++)
        {
            visited[j] = 0;
        }
        closure(i);
        printf("}\n");
    }

    printf("\n");
}