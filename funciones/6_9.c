#include<stdio.h>
#include<stdlib.h>
int validarentero(int,int);
int validar(int,int,int);
int dias(int,int,int);
int fecha (int,int,int);

int main()

{
  int dia,mes,ano,f;

  printf("\ningrese fecha d-m-a:\n");
  scanf("%d%d%d",&dia,&mes,&ano);

  f=fecha(dia,mes,ano);

  if(f==1)
  printf("\nLa fecha es correcta\n");
  else
  printf("\nLa fecha es incorrecta\n");

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