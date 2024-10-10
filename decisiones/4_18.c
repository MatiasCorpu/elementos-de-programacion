#include<stdio.h>
#include<stdlib.h>

int main()

{
  int dia,mes,ano,dia1,mes1,ano1,n;

  printf("\nIngrese dia-mes-año actual:\n");
  scanf("%d%d%d",&dia,&mes,&ano);
  
  printf("\nIngrese dia-mes-año de naciminto:\n");
  scanf("%d%d%d",&dia1,&mes1,&ano1);

  n=ano-ano1;

  if (mes>mes1)
  printf("\nAños:%d\n",n);

  else
    if (mes<mes1)
    printf("\nAños:%d\n",n-1);

    else
        if(dia>dia1)
         printf("\nAños:%d\n",n);

        else
            printf("\nAños:%d\n",n-1);


 
  system("pause");
  return 0;
}
