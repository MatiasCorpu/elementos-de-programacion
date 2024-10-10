#include<stdio.h>
#include<stdlib.h>

int main()

{
  int i,j;
     printf("\n\n");



  for(i=1;i<=9;i++)
    {
        for(j=1;j<=9;j++)
        {
        printf("%d\t",j*i);
        }

        printf("\n");
    }
    
    printf("\n\n");

  system("pause");
  return 0;
}