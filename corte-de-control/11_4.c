#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
    int num_interno;
    int num_sube;
    char cod_tarifa[11];
    int dia;
    int hora;
}esVIAJES;   //ORDENADO NUMERO DE INTERNO

typedef struct{
    int mes;
    char cod_tarifa[11];
    float precio;
}esTARIFA;   //CONTIENE INFO DE TARIFAS POR MES

typedef struct{
    int num_interno;
    int cant_viajes;
    float recaudacion;
}esCantidadXViajes; //PARA GENERAR ARCHIVO

typedef struct{
    char cod_tarifa[11];
    int cant_viajes;
}esORDENAR; //VECTOR A ORDENAR DESCENDENTE

void inicializaVECxTARIFA(esORDENAR [],esTARIFA[],int);
void ORDENARyMOSTRAR(esORDENAR [],int);
int BUSCAR(esTARIFA [],char[],int);
int LeeRango(int,int);
int FILTRAR (esTARIFA[],int,int);
void PROCESAR (esTARIFA[],int);
void VER1 (char[]);
void VER2 (char[]);


int main()
{
    esTARIFA vec[8];
    int cantidad,mes;

    printf("\n\nIngrese numero de mes:\n");
    mes=LeeRango(1,12);

    cantidad = FILTRAR (vec,8,mes);
    PROCESAR (vec,cantidad);

    VER1("tarifas.dat");
    VER2("viajes.dat");

    printf("\n\n\n");
    system ("pause");
    return 0;
}
//////////FUNCIONES///////////////////////////////////////
int FILTRAR (esTARIFA v[],int n,int mes)
{
    esTARIFA tari;
    int i=0;

    FILE *pf;
    
    pf=fopen("tarifas.dat","rb");
    if(pf==NULL){
        printf("Error al abrir el archivo");
        system("pause");
        exit(1);
    }

    fread(&tari,sizeof(tari),1,pf);
    while(!feof(pf)&&i<n){
        if(tari.mes==mes){
            v[i]=tari;
            i++;
        }
        fread(&tari,sizeof(tari),1,pf);
    }
    fclose(pf);
    return i;
}
//////////////////////////////////////////////////////////
int LeeRango(int LI,int LD)
{
    int x;

    do{
        scanf("%d",&x);
    }while(!(x>=LI&&x<=LD));

    return x;
}
//////////////////////////////////////////////////////////
void PROCESAR (esTARIFA v[],int n)
{
    float imp_total=0;
    int menos_viajes,menos_interno,primero=1,posi;
    
    esCantidadXViajes cXv;
    esORDENAR ordenar[8];
    esVIAJES viajes;

    FILE *pfc, *pfv;

    pfv=fopen("viajes.dat","rb");
    pfc=fopen("cantidadXviajes.dat","wb");

    if(pfc==NULL||pfc==NULL)
    {
        printf("Error al abrir un archivo");
        system("pause");
        exit(1);
    }

    fread(&viajes,sizeof(viajes),1,pfv);
    while(!feof(pfv))
    {
        cXv.cant_viajes=0;
        cXv.recaudacion=0;
        cXv.num_interno=viajes.num_interno;
        
        inicializaVECxTARIFA(ordenar,v,n);

        while(!feof(pfv)&&cXv.num_interno==viajes.num_interno)
        {
            cXv.cant_viajes++;
            posi=BUSCAR(v,viajes.cod_tarifa,n);
            ordenar[posi].cant_viajes++;
            cXv.recaudacion+=v[posi].precio;

            fread(&viajes,sizeof(viajes),1,pfv);
        }
        
        imp_total+=cXv.recaudacion;
        
        fwrite(&cXv,sizeof(cXv),1,pfc);

        if(primero||cXv.cant_viajes<menos_interno)
        {
            menos_viajes =cXv.cant_viajes;
            menos_interno=cXv.num_interno;
            primero=0;
        }

        printf("\n\nInterno %d\n\n",cXv.num_interno);
        ORDENARyMOSTRAR(ordenar,n);
    }

    
    
    if(!primero)
    {
        printf("\n\nEl interno %d realizo menos viajes %d\n",menos_interno,menos_viajes);
        printf("\nImporte total %.2f\n\n",imp_total);
    }
    
    fclose(pfc);
    fclose(pfv);
}
//////////////////////////////////////////////////////////
int BUSCAR(esTARIFA v[],char dato[],int n)
{
    int posi=-1,i=0;
    for(i=0;i<n;i++)
    {
        if(strcmpi(v[i].cod_tarifa,dato)==0)
        posi=i;
        else
        i++;
    }
    return posi;
}
//////////////////////////////////////////////////////////
void VER1 (char Archivo[])
{
    esTARIFA ta;
    FILE *pf;

    pf=fopen(Archivo,"rb");
    if(pf==NULL){
        printf("Error al abrir el archivo");
        system("pause");
        exit(1);
    }
    printf("\n\nTARIFAS\n\n");
    fread(&ta,sizeof(ta),1,pf);
    while(!feof(pf))
    {
        printf("\n%4d   %10s   %4.2f",ta.mes,ta.cod_tarifa,ta.precio);

        fread(&ta,sizeof(ta),1,pf);
    }
    fclose(pf);
}
//////////////////////////////////////////////////////////
void VER2 (char Archivo[])
{
    esVIAJES via;
    FILE *pf;

    pf=fopen(Archivo,"rb");
    if(pf==NULL){
        printf("Error al abrir el archivo");
        system("pause");
        exit(1);
    }

    printf("\n\nVIAJES\n\n");
    fread(&via,sizeof(via),1,pf);
    while (!feof(pf))
    {
        printf("\n%4d   %4d   %10s  %4d  %d",via.num_interno,via.num_sube,via.cod_tarifa,via.dia,via.hora);
        fread(&via,sizeof(via),1,pf);
    }
    
    fclose(pf);
}
//////////////////////////////////////////////////////////
void inicializaVECxTARIFA(esORDENAR orde[],esTARIFA v[],int n)
{
    int i=0;

    for(i=0;i<n;i++)
    {
        strcpy(orde[i].cod_tarifa,v[i].cod_tarifa);
        orde[i].cant_viajes=0;
    }
}
//////////////////////////////////////////////////////////
void ORDENARyMOSTRAR(esORDENAR ord[],int n)
{
    esORDENAR aux;
    int cota,des=1,i;
    cota=n;
    while (des!=0)
    {
        des=0;
        for(i=1;i<cota;i++)
        {
            if(ord[i-1].cant_viajes<ord[i].cant_viajes)
            {
                aux=ord[i-1];
                ord[i-1]=ord[i];
                ord[i]=aux;

                des=i;
            }
        }
        cota=des;
    }

    printf("\n\nPITOFSlknfbsdjafkbg\n\n");
    for(i=0;i<n;i++)
    {
        printf("\n%10s   %d",ord[i].cod_tarifa,ord[i].cant_viajes);
    }
}
//////////////////////////////////////////////////////////