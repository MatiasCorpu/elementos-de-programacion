#include<stdio.h>
#include<stdlib.h>

int main()

{
  int i,cont=0,sum=0,n;
  
  printf("\nIngresar 10 numeros enteros\n");



  for(i=1;i<=10;i+=1)
    {
      scanf("%d",&n);

        if(n%2==0)
        {
            sum+=n;
            cont++;
        }
    }
    
    if(cont>0)
    printf("\nProm de numeros pares %.2f\n",(float)sum/cont);

    else
    printf("\nNo se ingresaron numeros pares\n");


  system("pause");
  return 0;
}