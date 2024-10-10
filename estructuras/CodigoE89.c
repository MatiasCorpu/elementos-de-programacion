#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

typedef struct{
    char Codigo_producto[6];
    char Tipo_produccion;
    char Descripcion_producto[36];
    int Stock_disponible;
    float Precio_unitario;
}STOCK;


int BUSCAR( STOCK [],char[],int);
char VALIDA_TIPO(char,char,char);
int VALIDA_RANGO(int,int);
int VALIDA_ENTERO(int);
void CARGA(STOCK [],int);
void CARGA_PEDIDOS(STOCK [], int);
void INFORMA_FALTANTES(STOCK [],int [],int);
void INFORMA_SINPEDIDOS(STOCK [],float [],int);
void INFORMA_GANANCIA(STOCK [],float [],int);


int main()

{
    STOCK VSTOCK[10];

    CARGA(VSTOCK,10);

    CARGA_PEDIDOS(VSTOCK,10);

  system("pause");
  return 0;
}
///////////////////////////funciones///////////////////////////
void CARGA(STOCK V[],int N)
{
    int i,posi;

    printf("\n\nCARGA DE INFORMACION DE 10 PRODUCTOS\n");
    
    for(i=0;i<N;i++)
    {
        do{
        printf("--------------------------------------------------------------------------");
        fflush(stdin);
        printf("\n\nIngrese codigo de producto numero %d:",i+1);
        gets(V[i].Codigo_producto);
        posi=BUSCAR(V,V[i].Codigo_producto,i);
        if (posi!=-1)
        {
            printf("\nCodigo ya ingresado, ingresar nuevamente");
        }
        }while(posi!=-1);

        printf("\n\nIngrese el TIPO de produccion:");
        V[i].Tipo_produccion=VALIDA_TIPO('M','S','R');

        fflush(stdin);
        printf("\n\nIngrese DESCRIPCION del producto:");
        gets(V[i].Descripcion_producto);

        fflush(stdin);
        printf("\n\nIngrese CANTIDAD DE STOCK disponible:");
        V[i].Stock_disponible=VALIDA_RANGO(1,15);

        printf("\n\nIngrese PRECIO UNITARIO del producto:");
        V[i].Precio_unitario=VALIDA_ENTERO(0);

    }
}
///////////////////////////////////////////////////////////////
void CARGA_PEDIDOS(STOCK V[], int N)
{
    int posi,dia,cant,faltante[10]={0},band=0;
    char cod[6];
    float ganancia[10]={0};
    
    printf("\n\n\n\nINGRESOS DE PEDIDOS\n");
    printf("--------------------------------------------------------------------------");
    do{
    printf("\nIngrese CODIGO de producto (termina con BASTA):");
    scanf("%s",&cod);
    posi=BUSCAR(V,cod,N);
    if(posi==-1&&strcmpi(cod,"BASTA")!=0)
    {
        printf("\nCódigo de producto %s inexistente\n",cod);
    }
    }while(!(posi!=-1||strcmpi(cod,"BASTA")==0));

    while(strcmpi(cod,"BASTA")!=0)
    {
        band=1;
        printf("\nIngrese DIA de ENTREGA:");
        dia=VALIDA_RANGO(1,31);

        fflush(stdin);
        printf("\nIngrese CANTIDAD solicitada:");
        cant=VALIDA_ENTERO(0);

        if(V[posi].Stock_disponible-cant>=0)
        {
        V[posi].Stock_disponible-=cant;
        ganancia[posi]+=(V[posi].Precio_unitario*cant);
        }
        else{
        printf("\nCódigo de producto %s no dispone de la cantidad solicitada %d\n",cod,cant);
            faltante[posi]+=(cant-V[posi].Stock_disponible);
        }
        printf("--------------------------------------------------------------------------");
        do{
        printf("\nIngrese CODIGO de producto (termina con BASTA):");
        scanf("%s",&cod);
        posi=BUSCAR(V,cod,N);
        if(posi==-1&&strcmpi(cod,"BASTA")!=0)
        {
            printf("\nCódigo de producto %s inexistente\n",cod);
        }
        }while(!(posi!=-1||strcmpi(cod,"BASTA")==0));
    }
    if(band!=0)
    {
       printf("\n\n");
       printf("--------------------------------------------------------------------------");
       INFORMA_FALTANTES(V,faltante,N);
       printf("\n\n");
       printf("--------------------------------------------------------------------------");
       INFORMA_SINPEDIDOS(V,ganancia,N);
       printf("\n\n");
       printf("--------------------------------------------------------------------------");
       INFORMA_GANANCIA(V,ganancia,N);
       printf("\n\n\n");
    }
    else
    printf("\nNo se realizo ningun pedido :(\n\n\n");
}
///////////////////////////////////////////////////////////////
int BUSCAR( STOCK V[],char DATO[],int N)
{
    int i=0,posi=-1;

    while(posi==-1&&i<N)
    {
        if(strcmpi(V[i].Codigo_producto,DATO)==0)
        posi=i;
        else 
        i++;
    }
    return posi;
}
///////////////////////////////////////////////////////////////
char VALIDA_TIPO(char x,char y,char z)
{
    char A;
    do{
        fflush(stdin);
        scanf("%c",&A);
        A=toupper(A);
    }while(!(A==x||A==y||A==z));
    return A;
}
///////////////////////////////////////////////////////////////
int VALIDA_RANGO(int li ,int ld)
{
    int x;
    do{
        scanf("%d",&x);
    }while(x<li||x>ld);
    return x;
}
///////////////////////////////////////////////////////////////
int VALIDA_ENTERO(int N)
{
    int x;
    do{
        scanf("%d",&x);
    }while(x<N);
    return x;
}
///////////////////////////////////////////////////////////////
void INFORMA_FALTANTES(STOCK V[],int falta[],int n)
{
    int i;
    printf("\n\n\nCOD.PRODUCTO         DESCRIPCION               FALTANTE\n");

    for(i=0;i<n;i++)
    {
        printf("\n  %s        %s       %d",V[i].Codigo_producto,V[i].Descripcion_producto,falta[i]);
    }
}
///////////////////////////////////////////////////////////////
void INFORMA_SINPEDIDOS(STOCK V [],float Sinp[], int n)
{
    int i;
    printf("\n\n\nNO SE INGRESARON PEDIDOS DE:\n");
    for(i=0;i<n;i++)
    {
        if(Sinp[i]==0)
        printf("\n%s",V[i].Codigo_producto);
    }
}
///////////////////////////////////////////////////////////////
void INFORMA_GANANCIA(STOCK V [],float gan [],int n)
{
    int i;
    printf("\n\n\nCOD.PRODUCTO       GANANCIA\n");

    for(i=0;i<n;i++)
    {
        if(gan[i]!=0)
        printf("\n%s                $%.2f",V[i].Codigo_producto,gan[i]);
    }
}