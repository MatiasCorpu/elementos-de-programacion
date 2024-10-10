#include<stdio.h>
#include<stdlib.h>

int main()

{
  int max=0,dnimax=0,i,dni,p;
  

  for(i=1;i<=3;i++)
  {
    printf("\ningrese dni y nota prom\n");
    scanf("%d%f",&dni,&p);

    if(p>max)
    {
         max=p;
        dnimax=dni;
    }

  }

  printf("\nAlumno de mayor promedio: %d\n",dnimax);



  system("pause");
  return 0;
}