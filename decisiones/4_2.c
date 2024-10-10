#include<stdio.h>
#include<stdlib.h>

int main()

{
   int n1,n2,n3;

   printf("\n\nIngrese 3 numeros enteros:");
    scanf("%d%d%d",&n1,&n2,&n3);

    if ((n1<n2)&&(n1<n3))

     printf("\nEl primero es el menor");

    else
    printf("\nEl primero no es el menor\n\n\n");
    

  system("pause");
  return 0;
}

 