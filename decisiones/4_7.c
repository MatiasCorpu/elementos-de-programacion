#include<stdio.h>
#include<stdlib.h>

int main()

{
    int n1,n2,n3;

    printf("\n\nIngrese 3 numeros enteros:");
     scanf("%d%d%d",&n1,&n2,&n3);

     if((n1+n2)==n3)
     printf("\n\nNumeros ingresados forman un triangulo\n\n");

     else
      printf("\n\nNumeros ingresados no forman un triangulo\n\n");


 system("pause");
 return 0;
}

