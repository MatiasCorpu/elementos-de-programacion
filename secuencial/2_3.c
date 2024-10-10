#include <stdio.h>
#include <conio.h>
#include <stdlib.h>


int main()
{
  int N1,N2,n1,n3,n4,n5,n6;
    printf("\ningrese 2 números enteros:");
    scanf("%d%d",&N1,&N2);
    
    n3=N1+N2;
    n4=N1*N2;
    n5=N1/N2;
    n6=N1-N2;
    

   printf("\n%d+%d=%d",N1,N2,n3);
   printf("\n%dx%d=%d",N1,N2,n4);
   printf("\n%d/%d=%d",N1,N2,n5);
   printf("\n%d-%d=%d\n\n",N1,N2,n6);


   system("pause");
   return 0;
}