//CUANDO NO SE SABE LA CANTIDAD DE REGISTROS,actualizar masivamente, no tengo que buscar codigos;;;ACTUALIZAR EN OTRO ARCHIVO¡¡¡
//MODIFICO EN UN VECTOR Y LUEGO COPIO/ESCRIBO EN OTRO ARCHIVO¡¡¡

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
    int codigo;
    float precio;
    char descripcion[51];
}esPRECIOS;

void MOSTRAR(char[]);
void ACTUALIZARenotroARCHIVO(float);

int main()
{
    float porce;

    printf("\nLISTA DE PRECIOS DE PRECIOS.dat=\n\n");
    MOSTRAR("PRECIOS.dat");
    
    do{
    printf("\n\nIngrese porcentaje de incremento de precios:\n\n");
    scanf("%f",&porce);
    }while(porce<=0||porce>100);

    ACTUALIZARenotroARCHIVO(porce);
    printf("\n\nLISTA DE PRECIOS DE PRECIOS_ACTUALIZADOS.dat=\n\n");
    MOSTRAR("PRECIOS_ACTUAIZADOS.dat");

    system("pause");
    return 0;
}
///////////////////////FUNCIONES/////////////////////////
void MOSTRAR(char Archivo[])
{
    esPRECIOS pr;
    FILE *pf;
    pf=fopen(Archivo,"rb");
    if(pf==NULL)
    {
        printf("Error al abrir el archivo\n");
        system("pause");
        exit(1);
    }
    printf("CODIGO     PRECIO     DESCRIPCION");
    fread(&pr,sizeof(pr),1,pf);
    while(!feof(pf))
    {
        printf("\n%d       %.2f       %s",pr.codigo,pr.precio,pr.descripcion);
        fread(&pr,sizeof(pr),1,pf);
    }
    printf("\n\n\n\n");
    fclose(pf);
}
//////////////////////////////////////////////////////////////
void ACTUALIZARenotroARCHIVO(float porce)
{
    esPRECIOS pro;
    float precioNuevo;

    FILE *pfNOactualizado,*pfactualizado;
    

    pfNOactualizado=fopen("PRECIOS.dat","rb");
    pfactualizado=fopen("PRECIOS_ACTUAIZADOS.dat","wb");
    if(pfactualizado==NULL||pfNOactualizado==NULL)
    {
        printf("Error al abrir algun archivo");
        system("pause");
        exit(1);
    }

    fread(&pro,sizeof(pro),1,pfNOactualizado);
    while (!feof(pfNOactualizado))
    {
        pro.precio+=(pro.precio*porce)/100;
        fwrite(&pro,sizeof(pro),1,pfactualizado);

        fread(&pro,sizeof(pro),1,pfNOactualizado);
    }
    fclose(pfactualizado);
    fclose(pfNOactualizado);
}