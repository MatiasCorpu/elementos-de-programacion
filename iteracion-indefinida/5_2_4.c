#include<stdio.h>
#include<stdlib.h>

int main()

{
  int conttrj=0,contcheq=0;
  float total,imp,dinero1,efect,dinero2;
  char cod;


  
  do{
    fflush(stdin);
    printf("Ingrese codigo:");
    scanf("%c",&cod);
    cod=toupper(cod);
  }while(cod!='C'&&cod!='E'&&cod!='T'&&cod!='F');


  while(cod!='F')
  {
    do{
    printf("Ingrese importe:");
    scanf("%f",&imp);
    }while(imp<0);
  
    switch(cod)
    {
        case 'C':
        contcheq++;
        dinero1=imp+(imp*0.2);break;
        case 'E':
        efect=imp-(imp*0.1);break;
        case 'T':
        conttrj++;
        dinero2=imp+(imp*0.12);break;
        
    }
    total=dinero1+dinero2+efect;
    do{
    fflush(stdin);
    printf("Ingrese codigo:");
    scanf("%c",&cod);
    cod=toupper(cod);
    }while(cod!='C'&&cod!='E'&&cod!='T'&&cod!='F');
  }

printf("\nEfectivo en caja:%.2f\n",efect);
printf("\nVentas en tarjeta:%d\n",conttrj);
printf("\nVentas en cheques:%d\n",contcheq);
printf("\nTotal de ventas:%.2f\n",total);
printf("\nImporte IVA:%.2f\n",total*0.21);



  system("pause");
  return 0;
}