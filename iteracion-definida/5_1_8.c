#include<stdio.h>
#include<stdlib.h>
#define n 5


int main()

{
  int i,cont10=0,contalt=0,e;
  float a,estatura=0,edad=0;

   for(i=1;i<=n;i++)
    {
         printf("\nIngrese edad y altura del alumno %d:",i);
         scanf("%d%f",&e,&a);

            edad+=e;
            estatura+=a;
       
        if(e>10)
         cont10++;
        
        
        if(a<1.40)

         contalt++;

    }

  printf("\nEdad prom %.2f",edad/n);
  printf("\nEstatura prom %.2f",estatura/n);
  printf("\nMayores de 10 años %d",cont10);
  printf("\nMayores a 1.40 mts %d\n\n\n",contalt);


 
  system("pause");
  return 0;
}