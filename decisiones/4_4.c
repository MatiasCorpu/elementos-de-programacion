#include<stdio.h>
#include<stdlib.h>

int main()

{
   int n1,n2,n3;


   printf("\n\nIngrese 3 numeros enteros:");
    scanf("%d%d%d",&n1,&n2,&n3);

   if(n1>n3&&n2>n3)
   
   printf("\nMayores al tercero\n");

   else
    {
        if(n1==n2&&n2==n3)
        printf("\nTres iguales\n");

        else
         if (n1<n3||n2<n3)
           printf("\nalguno es menor\n");
         


    }
   
 system("pause");
 return 0;
}

 