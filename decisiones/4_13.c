#include<stdio.h>
#include<stdlib.h>

int main()

{
   int n;

   printf("\nIngrese numero de catalogo:\n");
   scanf("%d",&n);

   if ((n>=12121&&n<=18081)||(n>=30012&&n<=45565)||(n>=67000&&n<=68000))
   
    printf("\nEs defectuaoso\n");

    else
      if (n>=1200&&n<=90000)
       printf("\nNo defectuoso\n");

       else
       printf("\nFuera del catalogo\n");
   



  system("pause");
  return 0;
}

