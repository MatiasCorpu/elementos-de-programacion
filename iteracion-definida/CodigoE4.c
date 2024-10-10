#include<stdio.h>
#include<stdlib.h>

int main()

{
  int cant_sup=0,posi=0,i,cant_produ;
  float porce,gan,mayor=0;

for(i=1;i<=10;i++)
{
    printf("______________________________________________________________________");
    printf("\nIngrese cantidad de producciones de la semana %d:",i);
    scanf("%d",&cant_produ);

    if(cant_produ<=0)
    {
        printf("\nCantidad invalida vuelva a ingresar\n\n");
        i--;
    }

    else
    {
        porce=cant_produ*0.4;
        gan=cant_produ*1750;
        
        if(porce>100)
        cant_sup++;

        if(gan>mayor)
        {
            mayor=gan;
            posi=i;
        }

         printf("\n\nGanancia semanal:$%.2f\nPorcentaje de produccion respecto al promedio semanal:%%%.2f\n\n\n",gan,porce);
        
    }
}

 printf("______________________________________________________________________\n");
 printf("Cantidad de semanas que superan el 100%% producciones: %d\n",cant_sup);
 printf("Produccion con mayor ganancia ($%.2f) ingreso numero %d\n",mayor,posi);
 printf("______________________________________________________________________\n\n\n\n");

 
  system("pause");
  return 0;
}
