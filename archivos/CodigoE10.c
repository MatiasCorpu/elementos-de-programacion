#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

typedef struct
{
    char codigo[6];
    char tipo;
    char descripcion_product[31];
    int stock;
    float precio_uni;
}esPRODUCTOS;

typedef struct
{
    char codigo[5];
    int dia_entrega;
    int cantidad;
}esVENTAS;




int BUSCAR(esPRODUCTOS[],char[],int);
void MOSTARproductos(char []);
void MOSTARventas(char []);
void PRODUCTOS(esPRODUCTOS [],int);
void PROCESA_VTAS(esPRODUCTOS[],int);
void INFORMA_SINSTOCK(esPRODUCTOS[],int);
void INFORMA_MAX(esPRODUCTOS[],int, int []);
void GENERA_ACT(esPRODUCTOS[],int);

//void MOSTRARcopia(esPRODUCTOS[],int);





int main()
{
    esPRODUCTOS prod[10];
    printf("\n\n\n==========LISTA DE PRODUCTOS (sin actualizar)==========\n\n");
    MOSTARproductos("PRODUCTOS.dat");
    printf("\n\n\n\n==========LISTA DE VENTAS==========\n\n\n");
    MOSTARventas("VENTAS.dat");
    
    
    PRODUCTOS(prod,10);

    PROCESA_VTAS(prod,10);
    
    
    printf("\n\n\n\n==========archivo INEXISTENTES.dat==========\n\n");
    MOSTARventas("INEXISTENTE.dat");
    printf("\n\n\n\n========== archivo FALTANTES.dat==========\n\n");
    MOSTARventas("FALTANTES.dat");
    printf("\n\n\n\n==========archivo PROD_ACT.dat (actualizado)==========\n\n");
    MOSTARproductos("PROD_ACT.dat");

    system("pause");
    return 0;
}



////////////////////FUNCIONES////////////////////
void MOSTARproductos(char Archivo[])
{
    esPRODUCTOS pro;
    FILE *pf;

    pf=fopen(Archivo,"rb");
    if(pf==NULL)
    {
        printf("\nError al Abrir el archivo\n");
        system("pause");
        exit(1);
    }

    printf("\n\nCODIGO PROD.     TIPO             DESCRIPCION              STOCK    PRECIO c/u");
    fread(&pro,sizeof(pro),1,pf);
    while(!feof(pf))
    {
        printf("\n%5s      %8c    %30s     %5d     %5.2f",pro.codigo,pro.tipo,pro.descripcion_product,pro.stock,pro.precio_uni);
        fread(&pro,sizeof(pro),1,pf);
    }
    printf("\n\n");
}
/////////////////////////////////////////////////
void MOSTARventas(char Archivo[])
{
    esVENTAS ven;
    FILE *pf;

    pf=fopen(Archivo,"rb");
    if(pf==NULL)
    {
        printf("\nError al Abrir el archivo\n");
        system("pause");
        exit(1);
    }

    printf("CODIGO PROD.   DIA DE ENTRAGA    CANTIDAD");
    fread(&ven,sizeof(ven),1,pf);
    while(!feof(pf))
    {
        printf("\n%5s          %7d          %7d",ven.codigo,ven.dia_entrega,ven.cantidad);
        fread(&ven,sizeof(ven),1,pf);
    }
    printf("\n\n");
}
/////////////////////////////////////////////////
void PRODUCTOS(esPRODUCTOS v[],int n)
{
    int i=0;
    esPRODUCTOS prod;
    FILE *pf;

    pf=fopen("PRODUCTOS.dat","rb");
    if(pf==NULL)
    {
        printf("Error al abrir el archivo");
        system("pause");
        exit(1);
    }

    fread(&prod,sizeof(prod),1,pf);
    for(i=0;i<n;i++)
    {
        v[i]=prod;
        fread(&prod,sizeof(prod),1,pf);
    }
    fclose(pf);
}
/////////////////////////////////////////////////
void PROCESA_VTAS(esPRODUCTOS v[],int n)
{
    esVENTAS ven;
    int posi;
    int VentasPorProducto[10]={0};
    FILE *pfVentas,*pfInexistente,*pfFaltantes;

    pfVentas=fopen("VENTAS.dat","rb");
    pfInexistente=fopen("INEXISTENTE.dat","wb");
    pfFaltantes=fopen("FALTANTES.dat","wb");

    if(pfVentas==NULL||pfInexistente==NULL||pfFaltantes==NULL)
    {
        printf("Error al abrir algun archivo >:(");
        system("pause");
        exit(1);
    }
    
    fread(&ven,sizeof(ven),1,pfVentas);
    while(!feof(pfVentas))
    {
        posi=BUSCAR(v,ven.codigo,n);
       
        if(posi==-1)
            fwrite(&ven,sizeof(ven),1,pfInexistente);
        else
        {
            if(v[posi].stock-ven.cantidad>=0)
            {
            v[posi].stock-=ven.cantidad;
            VentasPorProducto[posi]+=ven.cantidad;
            }
            else
            fwrite(&ven,sizeof(ven),1,pfFaltantes);
        }

        fread(&ven,sizeof(ven),1,pfVentas);
    }
    
    
    INFORMA_SINSTOCK(v,n);
    INFORMA_MAX(v,n,VentasPorProducto);
    GENERA_ACT(v,n);

    
    fclose(pfFaltantes);
    fclose(pfInexistente);
    fclose(pfVentas);
}
/////////////////////////////////////////////////
void INFORMA_SINSTOCK(esPRODUCTOS v[],int n)
{
    int i=0;
    printf("\n\n\nEl/los productos que no disponen de stock luego de las ventas:\n");
    for(i=0;i<n;i++)
    {
        if(v[i].stock==0)
        printf("\n%s",v[i].codigo);
    }
}
/////////////////////////////////////////////////
void INFORMA_MAX(esPRODUCTOS v[],int n, int vec[])
{
    int i,maxi;
    
    maxi=vec[0];

    for(i=0;i<n;i++)
    {
        if(vec[i]>maxi)
        maxi=vec[i];
    }

    printf("\n\n\nEl/los productos que han vendido la mayor cantidad:\n");
    
    for(i=0;i<n;i++)
    {
        if(vec[i]==maxi)
        printf("\n%s : %d",v[i].codigo,vec[i]);
    }
}
/////////////////////////////////////////////////
void GENERA_ACT(esPRODUCTOS v[],int n)
{
    int i;
    esPRODUCTOS prod;
    FILE *pf;

    pf=fopen("PROD_ACT.dat","wb");
    if(pf==NULL)
    {
        printf("Error al abrir el archivo");
        system("pause");
        exit(1);
    }

    for(i=0;i<n;i++)
        {
        prod=v[i];
        fwrite(&prod,sizeof(prod),1,pf);
        }
    fclose(pf);
}
/////////////////////////////////////////////////
int BUSCAR(esPRODUCTOS v [],char DATO[],int n)
{
    int i=0,posi=-1;

    while(posi==-1&&i<n)
    {
        if(strcmpi(v[i].codigo,DATO)==0)
        posi=i;
        else
        i++;
    }
    return posi;
}
/////////////////////////////////////////////////
/*void MOSTRARcopia(esPRODUCTOS v[],int n)
{
    int i=0;
    for(i=0;i<n;i++)
    {
        printf("\n%s      %c       %30s       %d        %5.2f",v[i].codigo,v[i].tipo,v[i].descripcion_product,v[i].stock,v[i].precio_uni);
    }
    printf("\n\n\n");
}
*/

/////////////////////////////////////////////////
/////////////////////////////////////////////////