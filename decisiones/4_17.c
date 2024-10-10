#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<conio.h>

int main()

{
  int nh,band=0,impo;
  char cod;

    printf("\nIngrese numero de histria:");
    scanf("%d",&nh);
    
    
    printf("\nIngrese codigo:");
    fflush(stdin);
    scanf("%c",&cod);
    cod=toupper(cod);

    
        switch (cod)
        {
         case 'A':impo=20;break;
         
         case 'D':impo=40;break;
         
         case 'F':impo=60;break;
         
         case 'M':impo=150;break;
         
         case 'T':impo=150;break;
        
         default:band=1;
        }

    if (band==0)
        printf("\nNumero de historia %d, codigo %c, importe a pagar $%d\n\n",nh,cod,impo);
    
    else
        printf("\nError de codigo\n\n");


 
  system("pause");
  return 0;
}
