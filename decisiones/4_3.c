#include<stdio.h>
#include<stdlib.h>

int main()

{
   int igual,n1,n2,n3,band=0;


   printf("\n\nIngrese 3 numeros enteros:");
    scanf("%d%d%d",&n1,&n2,&n3);

    if ((n2+n3)==n1)
        igual=n1;

    else
    { 
        if ((n1+n3)==n2)
            igual=n2;

            else
            {
                if ((n1+n2)==n3)
                igual=n3;

                else
                band=1;
            }
        

    }   

    if (band==0)
        printf("\n%d es igual a la suma de los otros dos\n\n",igual);
    
    else
        printf("\nNinguno es igual a la suma de los otros dos\n\n"); 



 system("pause");
 return 0;
}

