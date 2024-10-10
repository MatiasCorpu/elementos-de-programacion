#include<stdio.h>
#include<stdlib.h>

int main()

{
  int cantprimos=0,posibleprimo=2,n;
  int esprimo,posibledivisor;

  printf("\nIngrese cantidad de primos a mostrar:");
  scanf("%d",&n);

  while(cantprimos<n){
    esprimo=1;
    posibledivisor=2;

    while(esprimo==1&&posibledivisor<posibleprimo){
      if(posibleprimo%posibledivisor==0)
      esprimo=0;
      
      else
      posibledivisor++;
    }
    if(esprimo==1)
    {
      printf("\n%d\n",posibleprimo);
      cantprimos++;
    }
    posibleprimo++;
  }
  system("pause");
  return 0;
}