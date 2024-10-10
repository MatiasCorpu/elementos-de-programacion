#include<stdio.h>
#include<stdlib.h>


int main()

{
  int j,i,sum=0;
  
   printf("\nNumeros perfectos:");

    for(i=1;i<=9000;i++)
    {
        for(j=1;j<=i;j++)
        {
            if((i%j)==0)
            sum=sum+j;
        }

        if((sum-i)==i)
        printf("%d\n",i);

        sum=0;
    }

 
  system("pause");
  return 0;
}