#include <stdio.h>

int main ()
{
  float N1,N2,Prom;
  
  printf("\nIngrese 2 notas de alumno:");
   scanf("%f%f",&N1,&N2);
    

    Prom=(N1+N2)/2;

    printf("\nNots promedio:%.2f\n\n",Prom);
   
    system("pause");
    return 0;
}