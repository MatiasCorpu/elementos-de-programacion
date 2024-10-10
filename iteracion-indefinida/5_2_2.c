#include<stdio.h>
#include<stdlib.h>

int main()

{
  int mes,dia,anio,n;

 do{
     printf("Ingrese año:");
     scanf("%d",&anio);
    }while(anio<=0);

    do{
     printf("Ingrese mes:");
     scanf("%d",&mes);
     }while(mes<1||mes>12);

    switch (mes)
    {
    case 1:case 3:case 5:case 7:case 8:case 10:case 12:
    n=31;break;

    case 4 :case 6 :case 9 :case 11:
    n=30;break;

    case 2:
    if (anio%4==0&&anio%100!=0||anio%400==0)
    n=29;     
    else
    n=28;break;
    
    }


    do{
     printf("Ingrese dia:");
     scanf("%d",&dia);
    }while(dia<1||dia>n);



  system("pause");
  return 0;
}
