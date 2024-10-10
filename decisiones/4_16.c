#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

int main()

{
  int c,cant;
  float total,cuenta;


  printf("\nIngrese codigo y cantidad a comprar:");
  scanf("%d%d",&c,&cant);

  c=tolower(c);

  switch (c)
  {
    case 1:case 10:case 100:
        total=cant*10;break;
    
    
     case 2:case 22:case 222:
        total=(cant/10)*65+(cant%10)*7;break;

     case 3:case 33:
        if (cant>10)
        {
            cuenta=cant*3;
            total=cuenta-(cuenta*0.1);
        }
        else
            total=cant*3;
        
        break;

     case 4:case 44:
        total=cant; break;  
    
    default: 
      printf("\nError de codigo\n");

  }

    printf("\nARTÍCULO %5d CANTIDAD %4d IMPORTE A PAGAR $ %4.2f\n\n",c,cant,total);



  system("pause");
  return 0;
}
