#include<stdio.h>
#include<stdlib.h>

int LEECONTROLRANGO(int,int);
int BUSQUEDA(int[],int,int);
float MAXIMO (float[],int);
void MOSTRARMAXIMO (float[],int,float);
void SUMAFILAS(float[][12],int,int,float[]);
void ORDENAR(float[],int[],int);
int CARGAESTACIONES(int[],int,int,int);
void MOSTRARA(float[][12],int[],int,int);
void MOSTRARB(float[][12],int,int,float[],int);
void MOSTRARC(float[][12],int,int,float[],int[]);


int main()
{
    float VSUMF[20]={0},VMAY[12]={0},MLLUV[20][12]={{0}};
    int VEST[20]={0},i=0;
    int dia,mes,cod,posi,preci,posi_est;

    posi_est=CARGAESTACIONES(VEST,20,99,999);

    printf("\nIngrese dia:\n");
    dia=LEECONTROLRANGO(0,31);

    while(dia!=0)
    {
        i++;

        printf("\nIngrese mes:\n");
        mes=LEECONTROLRANGO(1,12);

        do{
            printf("\nIngrese cod de estacion:\n");
            scanf("%d",&cod);

            posi=BUSQUEDA(VEST,cod,posi_est);
            
            if(posi==-1)
            printf("\nCodigo no encontrado, ingrese de nuevo\n");
        }while(posi==-1);

        do{
            printf("\nIngrese cantidad de precipitaciones:\n");
            scanf("%d",&preci);
        }while(preci<0);

        MLLUV[posi][mes-1]+=preci;

        printf("\nIngrese dia:\n");
        dia=LEECONTROLRANGO(0,31);
    }
    if(i!=0)
    {
        MOSTRARA(MLLUV,VEST,posi_est,12);
        MOSTRARB(MLLUV,posi_est,12,VMAY,4);
        MOSTRARC(MLLUV,posi_est,12,VSUMF,VEST);
    }
    else
    printf("\nNO SE INGREARON DATOS XDXDXDDDDDD\n");

    system("pause");
    return 0;
}
///////////////////////////funciones/////////////////////////////

int CARGAESTACIONES (int v[],int n,int li,int ld)
{
    int i=0,x;

    printf("\nCarga estaciones\n");
    x=LEECONTROLRANGO(li,ld);

    while(x!=99&&i<n)
    {
        v[i]=x;
        i++;
        x=LEECONTROLRANGO(li,ld);
    }
    return i;
}
///////////////////////////////////////////////////
int LEECONTROLRANGO(int li,int ld)
{
    int x;
    do{
        scanf("%d",&x);
    }while(x<li||x>ld);
    return x;
}
/////////////////////////////////////////////////////
int BUSQUEDA (int v[],int dato,int n)
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
///////////////////////////////////////////////////////
void MOSTRARA (float m[][12],int v[],int f,int c)
{
    int h=0,i,j;

    printf("\nESTACION\t");
    for(h=1;h<=12;h++)
    printf("%d\t",h);

    for(i=0;i<f;i++)
    {
        printf("\n%d\t\t",v[i]);
        for(j=0;j<c;j++)
        printf("%4.2f\t",m[i][j]);
    }
}
///////////////////////////////////////////////////////////
void MOSTRARB(float m[][12],int f,int c,float v[],int n)
{
    int i,j;
    float mayor;
    for(i=0;i<f;i++)
    {
        for(j=0;j<c;j++)
        v[j]+=m[i][j];
    }
mayor=MAXIMO(v,n);
MOSTRARMAXIMO(v,n,mayor);
}
/////////////////////////////////////////////////////////////
float MAXIMO(float v[],int n)
{
    float maxi;
    int i;
    maxi=v[0];

    for(i=0;i<n;i++)
    {
        if(maxi<v[i])
        maxi=v[i];
    }
    return maxi;
}
/////////////////////////////////////////////////////////////
void MOSTRARMAXIMO(float v[],int n,float maxi)
{
    int i;
    printf("\n\n\nMaximo:%.2f\n",maxi);
    printf("\nEn el/los trimestre/s:\n");

    for(i=0;i<n;i++)
    {
        if(v[i]==maxi)
        printf("%d\t",i+1);
    }
}
///////////////////////////////////////////////////////////
void MOSTRARC(float m[][12],int f,int c,float v[],int ve[])
{
    int i;
    SUMAFILAS(m,f,c,v);
    ORDENAR(v,ve,f);
    for(i=0;i<f;i++)
    printf("\n");
    printf("\n%d : %.2f",ve[i],v[i]);
    
}
//////////////////////////////////////////////////////////
void SUMAFILAS(float m[][12],int f,int c,float v[])
{
    int i,j;
    for(i=0;i<f;i+=3)
    {
        for(j=0;j<c;j++)
        v[i]+=m[i][j];
    }
}
//////////////////////////////////////////////////////////
void ORDENAR(float v[],int ve[],int n)
{
    int des,cota,aux1,i;
    float aux;
    des=1;
    cota=n;

    while(des!=0)
    {
        des=0;
        for(i=1;i<cota;i++)
        {
            if(v[i-1]>v[i])
            {
                aux=v[i-1];
                v[i-1]=v[i];
                v[i]=aux;

                aux1=ve[i-1];
                ve[i-1]=ve[i];
                ve[i]=aux1;

                des=i;
            }
            cota=des;
        }
    }
}