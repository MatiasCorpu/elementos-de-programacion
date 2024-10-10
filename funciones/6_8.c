#include<stdio.h>
#include<stdlib.h>
int dias(int,int);


int main()

{
  int mes, ano,d;
  do{
  printf("\nIngrese mes-año\n");
  scanf("%d%d",&mes,&ano);
  }while(!(mes>0&&mes<12)||ano<0);

  d=dias(mes,ano);

  printf("\nCantidad de dias:%d\n",d);

  system("pause");
  return 0;
}
/////////////////////////////////////////////////
int dias (int x,int y)
{
    int a;
    switch(x)
    {
        case 1 :case 3 :case 5 :case 7 :case 8 :case 10 :case 12:
      a=31;break;
    
      case 4 :case 6 :case 9 :case 11:
      a=30;break;

      case 2:
          if (y%4==0&&y%100!=0||y%400==0)
           a=29;     
            else
            a=28;
        break;
    }

    return a;
}