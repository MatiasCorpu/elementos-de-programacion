#include<stdio.h>
#include<stdlib.h>
#define pi 3.14


int main()

{
   int c;
   float GoR;

   printf("\nIngrse codigo y unidad:");
   scanf("%d%f",&c,&GoR);

   if (c==1)
   printf("\n%.2f en radianes:%.2f\n",GoR,(pi*GoR)/180);

   if(c==2)

   printf("\n%.2f en grados:%.2f\n",GoR,(180*GoR)/pi);


  system("pause");
  return 0;
}

