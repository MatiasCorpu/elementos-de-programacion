#include<stdio.h>
#include<stdlib.h>

int main()

{
  int n,i,produ=1;

  printf("\nIngrese un numero entero:");
    scanf("%d",&n);

    for(i=1;i<=n;i++)
    produ*=i;

    printf("\nFactorial de %d es %d\n\n\n",n,produ);


 
  system("pause");
  return 0;
}