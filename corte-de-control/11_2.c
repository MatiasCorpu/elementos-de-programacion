#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct
{
    char Sucursal[16];
    int Codigo;
    int Cantidad;
}esVENTAS;

typedef struct
{
    int Codigo;
    char Descripcion[21];
    float Precio;
    int Stock;
    int Punto_de_pedido;
    int Cantidad_para_pedido;    
}esPRODUCTOS;


void MOSTRARproduc(char []);
void MOSTRARventas(char []);
int CopiarProductos(char[],esPRODUCTOS [] ,int);
//void MostarVecES(esPRODUCTOS[],int);
void PeocesaVentas();
void ActualizaProductos();

int main()
{
    int cantidad;
    esPRODUCTOS PROD[200];


    MOSTRARproduc("PRODUCTOS.dat");
    MOSTRARventas("VENTAS.DAT");
    cantidad=CopiarProductos("PRODUCTOS.dat",PROD,200); 

    

    //MostarVecES(PROD,cantidad);    
    
    system("pause");
    return 0;
}
//////////////////FUNCIONES////////////////////
void MOSTRARproduc(char Archivo[])
{
    esPRODUCTOS prod;
    FILE *pf;
    pf=fopen(Archivo,"rb");
    if(pf==NULL)
    {
        printf("ERROR");
        system("pause");
        exit(1);
    }
    printf("\n\nCOD       DESC       PRECIO     STOCK   PUNTOde   CANTIDADde\n");
    fread(&prod,sizeof(prod),1,pf);
    while(!feof(pf))
    {
        printf("\n%3d  %11s     %4.2f    %5d    %5d       %5d",prod.Codigo,prod.Descripcion,prod.Precio,prod.Stock,prod.Punto_de_pedido,prod.Cantidad_para_pedido);
        fread(&prod,sizeof(prod),1,pf);
    }
    fclose(pf);
    printf("\n\n");
}
///////////////////////////////////////////////
void MOSTRARventas(char Archivo [])
{
    esVENTAS ven;
    FILE *pf;

    pf=fopen(Archivo,"rb");
    if(pf==NULL)
    {
        printf("ERROR");
        system("pause");
        exit(1);
    }

    printf("\n\nSECURSAL      COD.     CANTI.\n");
    fread(&ven,sizeof(ven),1,pf);
    while(!feof(pf))
    {
        printf("\n%7s    %5d     %5d",ven.Sucursal,ven.Codigo,ven.Cantidad);
        fread(&ven,sizeof(ven),1,pf);
    }
    fclose(pf);
    printf("\n\n\n");
}
///////////////////////////////////////////////
int CopiarProductos(char Archivo[],esPRODUCTOS v[],int N)
{
    esPRODUCTOS prod;
    FILE *pf;
    int i=0;

    pf=fopen(Archivo,"rb");
    if(pf==NULL)
    {
        printf("ERROR");
        system("pause");
        exit(1);
    }

    fread(&prod,sizeof(prod),1,pf);
    while(!feof(pf)&&i<N)
    {
        v[i]=prod;
        i++;
        fread(&prod,sizeof(prod),1,pf);
        
    }

    fclose(pf);
    return i;
}
///////////////////////////////////////////////
void MostarVecES(esPRODUCTOS v[],int n)
{   
    int i=0;
    printf("\n\nCOD       DESC       PRECIO     STOCK   PUNTOde   CANTIDADde\n");

    for(i=0;i<n;i++)
    {
        printf("\n%3d  %11s     %4.2f    %5d    %5d       %5d",v[i].Codigo,v[i].Descripcion,v[i].Precio,v[i].Stock,v[i].Punto_de_pedido,v[i].Cantidad_para_pedido);

    }
    printf("\n\n\n");
}
///////////////////////////////////////////////