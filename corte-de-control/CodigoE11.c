#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct 
{
    char codigo_producto[6];
    int dia_entrega;
    int cant_vendida;
    float total_vendido;
}esVENTAS;

void MOSTRAR(char[]);
void PROCESAR(char[]);

int main()
{
  printf("\n\t\t  ==========VENTAS==========");
  MOSTRAR("ventas.dat");

  PROCESAR("ventas.dat");

  system("pause");
  return 0;
}
/////////////////////FUNCIONES//////////////////////
void MOSTRAR(char Archivo[])
{
    esVENTAS ven;
    FILE *pf;
    pf=fopen(Archivo,"rb");
    if(pf==NULL)
    {
        printf("\nError al abrir el archivo");
        system("pause");
        exit(1);
    }
    printf("\n\n\nCOD.PRODUCTO      DIA ENTREGA      CANT.VENDIDA      TOTAL VENDIDO\n");
    fread(&ven,sizeof(ven),1,pf);
    while(!feof(pf))
    {
        printf("\n%6s               %3d             %5d            %5.2f",ven.codigo_producto,ven.dia_entrega,ven.cant_vendida,ven.total_vendido);
        fread(&ven,sizeof(ven),1,pf);
    }
    printf("\n\n");
    fclose(pf);
}
////////////////////////////////////////////////////
void PROCESAR(char Archivo[])
{
    int cant_ven_xDIA,dia_anterior,cont_prod,sum_cant_vendido_xCOD;
    float Total_recau=0;
    char Cod_anterior[6];

    esVENTAS ven;
    FILE *pf;
    
    
    pf=fopen(Archivo,"rb");
    if(pf==NULL)
    {
        printf("\nError al abrir el archivo");
        system("pause");
        exit(1);
    }


    fread(&ven,sizeof(ven),1,pf);

    while(!feof(pf))
    {
        
        cont_prod=0;
        sum_cant_vendido_xCOD=0;
        
        strcpy(Cod_anterior,ven.codigo_producto);

        while(!feof(pf)&&strcmp(Cod_anterior,ven.codigo_producto)==0)
        {
            

            cant_ven_xDIA=0;
            dia_anterior=ven.dia_entrega;

            while (dia_anterior==ven.dia_entrega&&!feof(pf)&&strcmp(Cod_anterior,ven.codigo_producto)==0)
            {
                cont_prod++;
                sum_cant_vendido_xCOD+=ven.cant_vendida;
                Total_recau+=ven.total_vendido;
                cant_ven_xDIA+=ven.cant_vendida;
                fread(&ven,sizeof(ven),1,pf);
            }
            printf("\n============================================\n");
            printf("\nCOD:%s  DIA ENTREGA:%d  CANTIDAD VEN.:%d",Cod_anterior,dia_anterior,cant_ven_xDIA);
        }
        
        printf("\n============================================\n");
        printf("\nCOD:%s PROMEDIO:%.2f\n",Cod_anterior,(float)sum_cant_vendido_xCOD/cont_prod);
        printf("\n\n\n");
    }
    
    printf("\n\nTOTAL RECAUDADO DE VENTAS PROCESADAS:$%.2f\n\n\n",Total_recau);
    fclose(pf);
}