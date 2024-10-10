#include<stdio.h>
#include<stdlib.h>


int main()

{
    int CANT_PRODU;
    float PORCE;

    printf("\n\nIngrese cantidad de producciones realizadas en la semana:");
    scanf("%d",&CANT_PRODU);

    if (CANT_PRODU<=0)
        printf("\nCantidad invalida\n\n");

    else
    {
        PORCE=CANT_PRODU*0.4;
        printf("\n\nGanancia semanal:$%.2d\nPorcentaje de produccion respecto al promedio semanal:%.2f%%",CANT_PRODU*1750,PORCE);


        if(PORCE<=25)
        printf("\nNo supero el 25%% de produccion\n\n");

        else
        {
            if(PORCE<=50)
            printf("\nNo supero el 50%% de produccion\n\n");

            else
            {
                if(PORCE<=100)
                printf("\nNo supero el 100%% de produccion\n\n");

                else
                printf("\nExcede el 100%% de produccion\n\n");

            }


        }
    }
    


    system("pause");
    return 0;

}