//CUANDO SE SABE LA CANTIDAD DE REGISTROS;;;ACTIALIZAR COPIAR EN UN VECTOR¡¡¡¡¡

#include<stdlib.h>
#include<stdio.h>
#include<string.h>

typedef struct
{
    int Codigo;
    float Precio;
    char descripcion[51];
}sProducto;

int CopiarArchivo(sProducto[],int);
void MostarProductos( sProducto[], int);
int ModificarPrecios(sProducto[],int);
void ACTUALIZAR(sProducto[],int);
int BUSCAR(sProducto[],int, int);

int main()
{
    sProducto produc[100];
    int CantProd,Modificados;
    
    CantProd=CopiarArchivo(produc,100);
    
    printf("\nLISTA DE PRODUCTOS ACTUALES\n");
    MostrarProductos(produc,CantProd);

    Modificados=ModificarPrecios(produc,CantProd);

    if(Modificados>0)
    {
        printf("Se modificaron los productos:");
        MostrarProductos(produc,CantProd);
        ACTUALIZAR(produc,CantProd);
    }
    else
    printf("\nNo se actualizaron precios\n");


    system("pause");
    return 0;
}
////////////////////FUNCIONES///////////////////////////
int CopiarArchivo(sProducto v[],int n)
{
    int i=0;
    sProducto prod;
    FILE *pf;
    pf=fopen("PRODUCTOS.dat","rb");
    if(pf==NULL)
    {
        printf("error al abrir el archivo");
        system("pause");
        exit(1);
    }

    fread(&prod,sizeof(prod),1,pf);
    while(!feof(pf)&&i<n)
    {
        v[i]=prod;
        i++;
        fread(&prod,sizeof(prod),1,pf);
    }
    fclose(pf);
    return i;
}
////////////////////////////////////////////////////////////
void MostarProductos (sProducto v[],int n)
{
    int i;
    printf("\n\n\nCODIGO   PRECIO     DESCRIPCION\n");
    for(i=0;i<n;i++)
    {
        printf("\n%d        %.2f        %s",v[i].Codigo,v[i].Precio,v[i].descripcion);
    }
}
/////////////////////////////////////////////////////////////////
int ModificarPrecios(sProducto v [],int n)
{
    int cod;
    float precio;
    int posi,cant;
    
    do{
    printf("\nIngrese codigo de producto a actualizar precio (TERMINA CON 0)\n");
    scanf("%d",&cod);
    posi=BUSCAR(v,cod,n);
    if(posi==-1&&cod!=0)
    printf("codigo %d inexistente, vuelva a ingresar",cod);
    }while(!(posi!=-1||cod==0));

    while(cod!=0)
    {
        printf("\nPrecio actual de producto %s es de %.2f\n",v[posi].descripcion,v[posi].Precio);

        do{
        printf("\nIngrese nuevo precio:\n");
        scanf("%f",&precio);
        }while(precio<0);
        
        v[posi].Precio=precio;

        if(precio!=v[posi].Precio)
        cant++;

        do{
         printf("\nIngrese codigo de producto a actualizar precio (TERMINA CON 0)\n");
        scanf("%d",&cod);
        posi=BUSCAR(v,cod,n);
        if(posi==-1&&cod!=0)
        printf("codigo %d inexistente, vuelva a ingresar",cod);
        }while(!(posi!=-1||cod==0));

    }
    return cant;
}
/////////////////////////////////////////////////////////////
void ACTUALIZAR(sProducto v[],int n)
{
    int i;
    FILE *pf1,*pf2;
    pf1=fopen("PRODUCTOS.dat","wb");
    pf2=fopen("productos.csv","wt");

    if(pf1==NULL&&pf2==NULL)
    {
        printf("Error al abrir algun archivo");
        system("pause");
        exit(1);
    }

    for(i=0;i<n;i++)
    {
        fwrite(&v[i],sizeof(v[i]),1,pf1);
        fprintf(pf2,"%d;%.2f;%s\n",v[i].Codigo,v[i].Precio,v[i].descripcion);
    }
    fclose(pf1);
    fclose(pf2);
}
///////////////////////////////////////////////////////////////
int BUSCAR (sProducto v [],int dato, int n)
{
    int i=0,posi=-1;

    while (posi==-1&&i<n)
    {
        if(v[i].descripcion==dato)
        posi=i;
        else
        i++;
    }
    return posi;
}
//////////////////////////////////////////////////////////////////

