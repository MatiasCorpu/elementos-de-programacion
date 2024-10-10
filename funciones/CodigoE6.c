#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

char valida_tipo(char,char,char);
void info_pd(int,int,int);
float prome(int,float);

int main()

{
  int cantidad=0,i=0,cant50=0,cant_m=0,cant_s=0,cant_r=0,cant_produ;
  float sum50=0,menor_porce=0,menor_ganan=0,ganan,porce,p;
  char tipo;


  do
  {
    printf("\nIngrese cantidad de productos realizados en la semana %d:\n",i+1);
    scanf("%d",&cant_produ);
  } while (cant_produ<0);
  
  while (cant_produ!=0)
  {
    printf("\nIngrese tipo de producto:\n");
    tipo=valida_tipo('M','S','R');
    
    switch(tipo)
    {
        case 'M':cant_m+=cant_produ;break;
        case 'S':cant_s+=cant_produ;break;
        case 'R':cant_r+=cant_produ;break;
    }

    ganan=cant_produ*1750;
    porce=cant_produ*0.4;

    if(porce<=50)
    {
        cant50++;
        sum50+=cant_produ;
    }

    i++;
    
    if(i==1)
    {
        menor_porce=porce;
        menor_ganan=ganan;
        cantidad=cant_produ;
    }
    if(porce<menor_porce)
    {
       menor_porce=porce;
       menor_ganan=ganan;
       cantidad=cant_produ; 
    }
    printf("-------------------------------------------------------");
    printf("\nGanancia semana %d:$%.2f\n",i,ganan);
    printf("\nPorcentaje semana %d:%.2f%%\n",i,porce);
    printf("-------------------------------------------------------");

    do
  {
    printf("\nIngrese cantidad de productos realizados en la semana %d:\n",i+1);
    scanf("%d",&cant_produ);
  } while (cant_produ<0);


  }

  if(i!=0)
  {
    printf("\n\n\n-------------------------------------------------------");
    printf("\nPromedio de cantidad de producciones que no superan 50%%: %.2f\n",prome(cant50,sum50));
    printf("-------------------------------------------------------");
    printf("\nMenor porcentaje: %.2f%%\n",menor_porce);
    printf("\nSu ganancia: $%.2f\n",menor_ganan);
    printf("\nLa cantidad de productos: %d\n",cantidad);
    info_pd(cant_m,cant_s,cant_r);

    
  }
  else
  printf("\nNo se ingreso datos :(\n");
  printf("--------------------------------------------\n\n\n");
  

  system("pause");
  return 0;
}
///////////////////////////////////FUNCIONES////////////////////////////////////////////////
char valida_tipo (char x,char y,char z)
{
    char tipo_produc;
    do
    {
       fflush(stdin);
       scanf("%c",&tipo_produc);
       tipo_produc=toupper(tipo_produc);
    } while (tipo_produc!=x&&tipo_produc!=y&&tipo_produc!=z);

    return tipo_produc;
    
}
/*----------------------------------------------------------------------*/
void info_pd(int x,int y,int z)
{
    printf("-------------------------------------------------------");
    printf("\nCantidad de mesas: %d\n",x);
    printf("\nCantidad de sillas: %d\n",y);
    printf("\nCantidad de mesas ratonas: %d\n",z);
}
/*----------------------------------------------------------------------*/
float prome (int x,float y)
{
    return (y/x);
}