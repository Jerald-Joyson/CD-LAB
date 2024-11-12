#include<stdio.h>

int hasEpsilonTransition[10][10], visited[10],numberOfStates, numberOfTransitions, stateOne, stateTwo;

char inputSymbol;

void closure(int i)
{
     visited[i]=1;
   for(int j=0;j<numberOfStates;j++)
   {
    if(hasEpsilonTransition[i][j] && !visited[j])
    {
        printf(",Q%d",j);
        closure(j);
    }


   }

}

int main()
{
    printf("Number of states:");
    scanf("%d",&numberOfStates);

    printf("number of transtions:");
    scanf("%d",&numberOfTransitions);

    printf("enter the transition table:\nstate symbol state\n");

    for(int i=0;i<numberOfTransitions;i++)
     {
        scanf("%d %c %d",&stateOne,&inputSymbol,&stateTwo);
        if(inputSymbol=='e')

        hasEpsilonTransition[stateOne][stateTwo]=1;

     }

     printf("Epsilone cosure\n");

     for(int i=0;i<numberOfStates;i++)
         {
            printf("\nStates %d:{Q%d",i,i);

            for(int j=0;j<numberOfStates;j++)

            visited[j]=0;
            closure(i);

            printf("}");

         }

         printf("\n\n");
}