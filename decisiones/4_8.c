#include<stdio.h>
#include<stdlib.h>

int main()

{
   int n1,n2;
   printf("\n\nIngrese dos numeros:");
    scanf("%d%d",&n1,&n2);

    if(n1%n2==0)
     printf("\n\nEs divisible\n\n");
    
    else
    printf("\n\nNo es divisible\n\n");
   
 system("pause");
 return 0;
}

