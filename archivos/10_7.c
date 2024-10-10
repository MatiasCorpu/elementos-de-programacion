// El ejercicio 10.7 incorpora el concepto de filtro de datos CHABAL¡¡¡¡¡¡
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
    char codigo_aerolinea[11];
    int dia;
    int num_vuelo;
    float costo_pasaje;
    int pasajeros;
}esVUELOS;

typedef struct
{
    int dni;
    int numero_vuelo;
}esPASAJEOROS;

typedef struct{
    int dia;
    int num_vuelo;
    float costo_pasaje;
    int pasajeros;
}esAereo1;

int DescargarVuelos(esVUELOS [],int);
void ACTUALIZARAereo1(esVUELOS [],int);
void GENERARAereo1(esVUELOS[],int);
int BUSCAR(esVUELOS [],int,int);
void MOSTRAR(char[]);

int main()

{
    int maximaPOSI;
    esVUELOS Vuelos[150];
    printf("\nVUELOS JEJE\n\n");
    MOSTRAR("VUELOS.dat");
    maximaPOSI = DescargarVuelos(Vuelos,150);
    
    if(maximaPOSI>0)
    {
    ACTUALIZARAereo1(Vuelos,maximaPOSI);
    GENERARAereo1(Vuelos,maximaPOSI);
    }
    else
    printf("\nNo hay vuelos\n\n");


  system("pause");
  return 0;
}
////////////////////FUNCIONES//////////////////////////
int DescargarVuelos(esVUELOS v[],int n)
{
    int i=0;
    esVUELOS vuelAUX;

    FILE *pf;
    pf=fopen("VUELOS.dat","rb");
    if(pf==NULL)
    {
        printf("Error al abrir el archivo");
        system("pause");
        exit(1);
    }
    
    fread(&vuelAUX,sizeof(vuelAUX),1,pf);
    while (!feof(pf)&&i<n)
    {
        if(strcmpi(vuelAUX.codigo_aerolinea,"Aero1")==0)
        {
            v[i]=vuelAUX;
            i++;
        }
        fread(&vuelAUX,sizeof(vuelAUX),1,pf);
    }
    fclose(pf);
    return i;
}
////////////////////////////////////////////////////////////////////
void ACTUALIZARAereo1(esVUELOS v[],int n)
{
    esPASAJEOROS psa;
    FILE *pf;
    int posi;

    pf=fopen("PASAJEROS.dat","rb");
    if(pf==NULL)
    {
        printf("Error al abrir el archivo");
        system("pause");
        exit(1);
    }
    fread(&psa,sizeof(psa),1,pf);
    while (!feof(pf))
    {
        posi=BUSCAR(v,psa.numero_vuelo,n);
        if(posi==-1)
        v[posi].pasajeros++;

        fread(&psa,sizeof(psa),1,pf);  
    }
    fclose(pf);
}
//////////////////////////////////////////////////////
int BUSCAR(esVUELOS v[],int DATO,int n)
{
    int i=0,posi=-1;

    while(posi==-1&&i<n)
    {
        if(v[i].num_vuelo==DATO)
        posi=i;
        else
        i++;
    }
    return posi;
}
/////////////////////////////////////////////////////
void GENERARAereo1(esVUELOS v[],int n)
{
    esAereo1 are;
    int i=0,opc;
    FILE *pf,*pf2;
    
    pf=fopen("AEREO1.dat","wb");
    if(pf==NULL)
    {
        printf("ERROR");
        system("pause");
        exit(1);
    }
    
    printf("\n\nSi desea exportar a un formato csv Aereo1 presione 1:\n\n");
    scanf("%d",&opc);
    if(opc==1)
    {
        pf2=fopen("Aereo.csv","wt");
        if(pf2==NULL)
        {
            printf("Error");
            system("pause");
            exit(1);
        }
        fprintf(pf2,"Dia;NroVuelo;Costo;Pasajeros\n");//creo titiulo para csv
    }

    for(i=0;i<n;i++)//paso del vector al archivo
    {
        are.costo_pasaje=v[i].costo_pasaje;
        are.dia=v[i].dia;
        are.num_vuelo=v[i].num_vuelo;
        are.pasajeros=v[i].pasajeros;

        fwrite(&are,sizeof(are),1,pf);

        if(opc==1)

            fprintf(pf2,"%d;%.2f;%d;%d\n",are.dia,are.costo_pasaje,are.num_vuelo,are.pasajeros);

    }

    fclose(pf);
    if(opc==1)
    fclose(pf2);
}
////////////////////////////////////////////////////////////////////
void MOSTRAR(char Archivo[])
{
    esVUELOS pr;
    FILE *pf;
    pf=fopen(Archivo,"rb");
    if(pf==NULL)
    {
        printf("Error al abrir el archivo\n");
        system("pause");
        exit(1);
    }

    fread(&pr,sizeof(pr),1,pf);
    while(!feof(pf))
    {
        printf("\n%10.8s       %8.2f       %5d       %5d      %5d",pr.codigo_aerolinea,pr.costo_pasaje,pr.dia,pr.num_vuelo,pr.pasajeros);
        fread(&pr,sizeof(pr),1,pf);
    }
    printf("\n\n\n\n");
    fclose(pf);
}