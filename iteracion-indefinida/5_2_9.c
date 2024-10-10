#include<stdio.h>
#include<stdlib.h>

int main()

{
    int i=0,ingre,ant,chij;
    float sb,sueldo,sueldonuevo,sueldoS;
    char es;

    printf("\nDesea ingresar datos de empleado 1=si 0=no:");
    scanf("%d",&ingre);

    while(ingre==1)
    {
        do{
            printf("\ningrese sueldo basico:");
            scanf("%f",&sb);
        }while(sb<=0);

        do{
            printf("\ningrese antiguedad:");
            scanf("%d",&ant);
        }while(ant<=0);

        do{
            printf("\ningrese cantidad de hijos:");
            scanf("%d",&chij);
        }while(chij<0);

        do{
            fflush(stdin);
            printf("\nEstudios sum¡periores:");
            scanf("%c",&es);
            es=toupper(es);
        }while(es!='S'&&es!='N');

        if(ant>10)
        sueldo+=sb*0.1;

        if(chij>2)
        sueldo+=sb*0.1;
        else
        {
            if(chij==1)
            sueldo+=sb*0.05;

        }

        if(es=='S')
        sueldo+=sb*0.5;

        i++;

        sueldonuevo=sb+sueldo;

        printf("\nNumero de empleado:%d\n",i);
        printf("\nSueldo basico:%.2f\n",sb);
        printf("\nNuevo sueldo:%.2f\n",sueldonuevo);

        sueldoS+=sueldonuevo;

        printf("\nDesea ingresar datos de empleado 1=si 0=no:");
        scanf("%d",&ingre);

    }

    if(i>0)
    printf("\nPromedio nuevo sueldo:%.2f\n",sueldoS/i);
    else
    printf("\nNo se ingresaros empleados\n");

  system("pause");
  return 0;
}