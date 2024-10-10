#include<stdio.h>
#include<stdlib.h>

int main()

{
  int i,n,sum1=0,num,cont=0,sum2=0;

    printf("\nCantidad de numeros a ingresar:");
     scanf("%d",&n);
  for(i=1;i<=n;i++)
    {
        scanf("%d",&num);

        if(num%3==0)
         sum1+=num;

        
        if(num%5==0)
         cont++;
        
        
        if(num%2==0)
         sum2+=num;

    }


    printf("\nSuma multiplos de 3:%d",sum1);
    printf("\nCantidad de mul. de 5:%d",cont);
    printf("\nSuma multiplos de 2:%d\n\n",sum2);





 
  system("pause");
  return 0;
}