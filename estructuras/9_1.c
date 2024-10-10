/*9.1. Una empresa que vende neumáticos desea realizar un programa para actualizar el total de ventas del mes
de sus productos. Para ello primeramente se ingresan la información de los productos formados por:

STRUCT
• Código (5 caracteres).
• Precio (real).
• Descripción (30 caracteres).
• Cantidad de unidades vendidas (al mes anterior, entero).
• Importe Total Vendido (al mes anterior, real).


Se sabe que la empresa no vende más de 50 productos. CARGA INCOMPLETA CODIGOS NO SE REPITEN STRING 
 El ingreso de la carga de productos finaliza con un producto con descripción “FIN”. ES STRING

INGRESO
Luego ingresan las ventas del mes:
• Código de Producto (5 caracteres). FUNCION BUSCAR
• Cantidad pedida. ENTERO >0

El ingreso de datos de las ventas finaliza con una cantidad igual a 0. FIN DEL INGRESO

 Se solicita:
a. Actualizar la información de los productos con las ventas realizadas en el mes. 
b. Al finalizar, mostrar el listado de productos actualizado, informando:


DESCRIPCION   CANTIDAD UNIDADES     IMPORTE TOTAL
                 VENDIDAS             VENDIDO
                               
   XXXXXXX        XXXX                $XXXXX,XX*/

  



#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
    char codigo[6];
    float precio;
    char descripcion[31];
    int cant_unidades;
    float importe_vendido;
}ES_PRODUCTO;

int BUSCAR(ES_PRODUCTO [],char [],int);
int CARGA(ES_PRODUCTO [],int);
void CARGA_VENTAS(ES_PRODUCTO[],int);
void MOSTRAR(ES_PRODUCTO[],int);
void ORDENAR(ES_PRODUCTO[],int);

int main()
{
    ES_PRODUCTO v_producto[50];
    int posi_max;
    
    posi_max=CARGA(v_producto,50);
    
    if(posi_max>0)
    {
        CARGAR_VENTAS(v_producto,posi_max);
        MOSTRAR(v_producto,posi_max);
        printf("\n\n____________LISTADO ORDENADO(por cantidad)____________\n\n");

        ORDENAR(v_producto,posi_max);
        MOSTRAR(v_producto,posi_max);
    }
    else
    printf("\nNo se ingresaron datos de productos\n");
    
    
  system("pause");
  return 0;
}
////////////////////funciones//////////////////////////
void CARGA_VENTAS(ES_PRODUCTO v[],int n)
{
  int cant,posi;
 char cod[6];


 do{
    printf("\nIngrese cantidad pedida:\n");
    scanf("%d",&cant);
    }while (cant<0);
    fflush(stdin);
    while(cant!=0)
    {
        do{
        printf("\ningrese codigo de producto:\n");
        gets(cod);
        posi=BUSCAR(v->codigo,cod,n);
        if(posi!=1){
            v[posi].cant_unidades+=cant;
            v[posi].importe_vendido+=(cant*v[posi].precio);
        }
        else
        printf("\nCodigo no encontrado vuelva a ingresar\n");
        fflush(stdin);
        }while(posi==-1);
        
        do{
        printf("\nIngrese cantidad pedida:\n");
        scanf("%d",&cant);
        }while (cant<0);
        fflush(stdin);
        
    }
}
////////////////////////////////////////////////////////////////
int BUSCAR(ES_PRODUCTO  v[],char dato [],int n)
{
    int i=0,posi=-1;

    while (posi==-1&&i<n)
    {
        if(strcmpi(v[i].codigo,dato)==0)
        posi=i;
        else
        i++;
    }
    return posi;
}
//////////////////////////////////////////////////////////////////
int CARGA(ES_PRODUCTO v[],int n){
    char des[31],cod[6];
    int i=0,posi,cant;
    float pre;
    
    fflush(stdin);
    printf("\nIngrese descripcion del producto (FIN para terminar)%d:\n",i+1);
    gets(des);
    while(strcmpi(des,"FIN")&&i<n)
    {
        strcpy(v[i].descripcion,des);
        fflush(stdin);
        do{
        printf("\nIngrese codigo %d\n",i+1);
        gets(cod);
        posi=BUSCAR(v[i].codigo,cod,i);
        if(posi==-1){
            strcpy(v[i].codigo,cod);
        }
        else
        printf("\nCodigo ya ingresado\n");
        }while(posi!=-1);
        
        fflush(stdin);
        do{
        printf("\nIngrese precio:\n");
        scanf("%f",&pre);
        }while(pre<0);
        v[i].precio=pre;

        do{
        printf("\nIngrese cantidad de unidades vendidas\n");
        scanf("%d",&cant);
        }while(cant<0);
        v[i].cant_unidades=cant;

        do{
        printf("ingrese el importe total vendido");
        scanf("%f",&v[i].importe_vendido);
        }while(v[i].importe_vendido<0);

        i++;
        fflush(stdin);
        printf("\nIngrese descripcion del producto%d:\n",i+1);
        gets(des);
    }
    return i;
}
////////////////////////////////////////////////////////////////////////////////////////
void MOSTRAR(ES_PRODUCTO v[],int n){
    int i;
    printf("\nDESCRIPCION      CANT. de UNI.     IMP. TOTAL\n");
    for(i=0;i<n;i++){
        printf("\n%s     %d     %.2f",v[i].descripcion,v[i].cant_unidades,v[i].importe_vendido);
    }
    printf("\n\n\n");
}
////////////////////////////////////////////////////////////////////////////////////////
void ORDENAR(ES_PRODUCTO v[],int n){
    int cota=n,des=1,i;
    ES_PRODUCTO aux;

    while(des!=0)
    {
        des=0;
        for(i=1;i<cota;i++)
        {
            if(v[i-1].cant_unidades<v[i].cant_unidades){
                aux=v[i-1];
                v[i-1]=v[i];
                v[i]=aux;

                des=i;
            }
        }
        cota=des;
    }
}
