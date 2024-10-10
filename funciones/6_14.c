#include<stdio.h>
#include<stdlib.h>
int validarentero(int,int);
int validar(int,int,int);
int dias(int,int,int);
int fecha (int,int,int);
void edad(int,int,int,int,int,int);


int main()

{
  int dia,mes,ano,f,dia2,mes2,ano2,f2,band=0;

  printf("\ningrese fecha actual d-m-a:\n");
  scanf("%d%d%d",&dia,&mes,&ano);
  f=fecha(dia,mes,ano);

  if(f==1)
  printf("\nLa fecha actual es correcta\n");
  else
  printf("\nLa fecha actual es incorrecta\n");
  
 
  while(f==1)
  {
    printf("\nIngrese fecha de cumpleaños d-m-a:\n");
    scanf("%d%d%d",&dia2,&mes2,&ano2);
    f2=fecha(dia2,mes2,ano2);

    if(f2==1)
    {
        printf("\nLa fecha de cumpleaños es correcta\n");
        printf("\nEdad acutual:\n");
        edad(dia,mes,ano,dia2,mes2,ano2);
    }
    else
    printf("\nFecha de cumpleaños esta mal\n");

    printf("\ningrese fecha actual d-m-a:\n");
    scanf("%d%d%d",&dia,&mes,&ano);
    f=fecha(dia,mes,ano);
  }


  system("pause");
  return 0;
}
//////////////////////////////////////////////////////////////////
int fecha (int x,int y,int z)
{
    int i=0,a,b,c;

    a=validarentero(z,0);
    b=validar(y,1,12);
    c=dias(x,y,z);

    if(a==1&&b==1&&c==1)
    i=1;

    return i;
}
////////////////////////////////////////////////////////////////////
int validarentero(int x, int n)
{
    int i=0;
    if(x>n)
    i=1;

    return i;
}
/////////////////////////////////////////////////////////////////////

int validar(int x,int li,int ld)
{
    int i=0;
    if(x>=li&&x<=ld)
    i=1;

    return i;
}
////////////////////////////////////////////////////////////////////////
int dias (int x,int y,int z)
{
    int i=0;
    switch(y)
    {
        case 1 :case 3 :case 5 :case 7 :case 8 :case 10 :case 12:
      if(x<=31&&x>=1)
      i=1;
      break;
    
      case 4 :case 6 :case 9 :case 11:
      if(x<=30&&x>=1)
      i=1;
      break;

      case 2:
          if (z%4==0&&z%100!=0||z%400==0)
           if(x<=29&&x>=1)
           i=1;    
            else
            if(x<=28&&x>=1)
            i=1;
        break;
    }

    return i;
}
////////////////////////////////////////////////////////////////////////
void edad (int dia,int mes,int ano,int dia1,int mes1,int ano1)
{
    int n;
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
}