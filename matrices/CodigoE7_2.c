#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

int VALIDA_ENTERO(int);
int VALIDA_RANGO(int,int);
int BUSCAR(char[],char,int);
void VALIDA_TIPO(int[],int,char[]);
void INFORMA_PUNTOA(int [][5],int,int);
void INFORMA_PUNTOB(int[],int);
void INFORMA_PUNTOC(int[],int);
void INFORMA_PUNTOD(char[],int[],int);

int main()
{
    char VTIPO_LETRA[3]={'M','R','S'};
    int M[12][5]={{0}},VMES_MAYOR[12]={0},i=0,VSEM_0[5]={0},VCANTIPO[3]={0},NUM_SEMANA,MES_PRODUC,CANT_PRODUC;

    printf("\n________________________________________________________________\n");
    printf("\nIngrese cantidad de productos realizados en la semana:\n");
    CANT_PRODUC=VALIDA_ENTERO(0);

    while(CANT_PRODUC!=0)
    {
        i++;
        printf("\nIngrese tipo de producto:\n");
        VALIDA_TIPO(VCANTIPO,3,VTIPO_LETRA);

        printf("\nIngrese numero de semana de la produccion:\n");
        NUM_SEMANA=VALIDA_RANGO(1,15);

        printf("\nIngrese mes de produccion:\n");
        MES_PRODUC=VALIDA_RANGO(1,12);

        M[MES_PRODUC-1][NUM_SEMANA-1]+=CANT_PRODUC;
        VMES_MAYOR[MES_PRODUC-1]+=CANT_PRODUC;
        VSEM_0[NUM_SEMANA-1]+=CANT_PRODUC;

        printf("\n________________________________________________________________\n");
        printf("\nIngrese cantidad de productos realizados en la semana:\n");
        CANT_PRODUC=VALIDA_ENTERO(0);
    }
    if(i!=0)
    {
        INFORMA_PUNTOA(M,12,5);
        INFORMA_PUNTOB(VMES_MAYOR,12);
        INFORMA_PUNTOC(VSEM_0,5);
        INFORMA_PUNTOD(VTIPO_LETRA,VCANTIPO,3);
    }
    else
    printf("\nNo se ingresaron datos :(\n\n\n");

    system("pause");
    return 0;
}

/////////////////////funciones////////////////////////////
int VALIDA_ENTERO (int n)
{
    int x;
    do{
        scanf("%d",&x);
    }while(x<n);

    return x;
}
/*------------------------------------------------------*/
int VALIDA_RANGO(int li,int ld)
{
    int x;

    do{
        scanf("%d",&x);
    }while(x<li&&x>ld);

    return x;
}
/*------------------------------------------------------*/
void VALIDA_TIPO(int v[],int n,char v2[])
{
    char t;
    int posi;
    do{
        fflush(stdin);
        scanf("%c",&t);
        t=toupper(t);
        posi=BUSCAR(v2,t,n);    
    }while(posi==-1);

    v[posi]++;
}
/*------------------------------------------------------*/
void INFORMA_PUNTOA(int m[][5],int f,int c)
{
    int h,i,j;
    printf("\n-----------------------------------------------------\n");
    printf("\t\t   SEMANAS");
    printf("\nMES");
    for(h=0;h<c;h++)
    printf("\t%7d",h+1);

    for(i=0;i<f;i++)
    {
        printf("\n%2d",i+1);
        for(j=0;j<c;j++)
        printf("\t  %5d",m[i][j]);
    }
}
/*------------------------------------------------------*/
void INFORMA_PUNTOB(int v[],int n)
{
    int maxi,i;
    maxi=v[0];

    for(i=0;i<n;i++)
    {
        if(maxi<v[i])
        maxi=v[i];
    }
    printf("\n________________________________________________________________\n");
    printf("\n\nMaxima cantidad de producciones ingresadas en un mismo mes:%d",maxi);
    printf("\nEl/los meses con mayor cantidad de producciones ingresadas:\n");
    i=0;
    for(i=0;i<n;i++)
    {
        if(maxi==v[i])
        printf("MES %d\t",i+1);
    }
}
/*------------------------------------------------------*/
void INFORMA_PUNTOC(int v[],int n)
{
    int i;
    printf("\n________________________________________________________________\n");
    printf("\n\nLa/s semanas que no se han ingresado producciones en todos los meses:\n");
    for(i=0;i<n;i++)
    {
        if(v[i]==0)
        printf("SEMANA %d\t\n",i+1);
    }
}
/*------------------------------------------------------*/
void INFORMA_PUNTOD(char v[],int v1[],int n)
{
    int i;
    printf("\n________________________________________________________________\n");
    printf("\n\nTIPO DE PRODUCCION\tCANTIDAD\n");
    for(i=0;i<n;i++)
    printf("\t%c\t\t%d\n",v[i],v1[i]);
    printf("\n________________________________________________________________\n\n\n");

}
/*------------------------------------------------------*/
int BUSCAR(char v[],char dato,int n)
{
    int posi=-1,i=0;
    
    while(posi==-1&&i<n)
    {
        if(v[i]==dato)
        posi=i;
        else
        i++;
    }
    return posi;
}