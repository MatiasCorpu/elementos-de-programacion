#include<stdio.h>
#include<stdlib.h>


int main()

{
    int CANT_PRODU;
    float PORCE;

    printf("\n\nIngrese cantidad de producciones realizadas en la semana:");
    scanf("%d",&CANT_PRODU);

    PORCE=CANT_PRODU*0.4;

    printf("\n\nGanancia semanal:$%.2d\nPorcentaje de produccion respecto al promedio semanal:%%%.2f\n\n\n",CANT_PRODU*1750,PORCE);


    system("pause");
    return 0;

}