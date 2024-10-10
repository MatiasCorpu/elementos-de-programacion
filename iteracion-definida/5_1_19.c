#include<stdio.h>
#include<stdlib.h>

int main()

{
    int n,i,j;


    printf("\nIngresar un numero:");
    scanf("%d",&n);

    
  for(i=1;i<=n;i++)
    {
        for(j=1;j<=i;j++)
        {
        printf("*");
        }

        printf("\n");
    }
    


 
  system("pause");
  return 0;
}