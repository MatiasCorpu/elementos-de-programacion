#include<stdio.h>
#include<stdlib.h>

int main()

{
   float suel,vh;
   int ht;

    printf("\nIngrese valor por hora y cantidad de horas trabajadas:\n");
    scanf("%f%d",&vh,&ht);

    if (ht>150)
    suel=vh*ht+1000;

    else 
     {
     if (ht>50)
     suel=vh*ht+500;

     else
      suel=vh*ht;

     }

    printf("\nSueldo:%.2f\n",suel);

  system("pause");
  return 0;
}

 