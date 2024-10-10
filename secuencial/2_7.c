#include <stdio.h>

int main()
{
   int n,cen,dec,uni;

   printf("\nIngrese un numero entero de 3 cifras:");
    scanf("%d",&n);


    cen=n/100;
    dec=(n%100)/10;
    uni=(n%100)%10;

    printf("\nUnidad:%d",uni);
    printf("\nDecena:%d",dec);
    printf("\nCentena:%d\n",cen);
    
    
    system("pause");
return 0;    
}