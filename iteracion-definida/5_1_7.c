#include<stdio.h>
#include<stdlib.h>

int main()

{
  
   int i,cont=0,lg;
  float nota;

  for(i=1;i<=5;i++)
    {
        printf("\nIngrese nota y legajo del alumno %d:",i);
        scanf("%f%d",&nota,&lg);

        if(nota>=7)
        printf("\nEl alumno con legajo %d ha promocionado con %.2f",lg,nota);

        else
        {
        if(nota<4)
        cont++;
        }
    }


   printf("\nCantidad de aplazados:%d",cont);


 
  system("pause");
  return 0;
}