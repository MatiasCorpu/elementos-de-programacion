#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>


int VALIDA_ENTERO(int);
char VALIDA_TIPO(void);
int VALIDA_RANGO(int,int);
void INFORMA_PUNTOA(float[],int);
void INFORMA_PUNTOB(int[],int);
void INFO_MINI(float[],float,int);
void INFORMA_PUNTOC(float[],int);


int main()

{
  float VGAN[5]={0};
  int VMES[12]={0},i=0,CANT_PRODUC,NUM_SEMANA,MES_PRUDUC;
  char TIPO_PRODUC;

    printf("\n________________________________________________________________\n");
    printf("\nIngrese cantidad de productos realizados en la semana:\n");
    CANT_PRODUC=VALIDA_ENTERO(0);

    while(CANT_PRODUC!=0)
    {
        i++;
        printf("\nIngrese tipo de producto:\n");
        TIPO_PRODUC=VALIDA_TIPO();

        printf("\nIngrese numero de semana de la produccion:\n");
        NUM_SEMANA=VALIDA_RANGO(1,15);

        printf("\nIngrese mes de produccion:\n");
        MES_PRUDUC=VALIDA_RANGO(1,12);


        VGAN[NUM_SEMANA-1]+=(CANT_PRODUC*1750);
        VMES[MES_PRUDUC-1]+=CANT_PRODUC;

        printf("\n________________________________________________________________\n");
        printf("\nIngrese cantidad de productos realizados en la semana:\n");
        CANT_PRODUC=VALIDA_ENTERO(0);
    }
    if(i!=0)
    {
        INFORMA_PUNTOA(VGAN,5);
        INFORMA_PUNTOB(VMES,12);
        INFORMA_PUNTOC(VGAN,5);
    }
    else
    printf("\nNo se ingresaron datos :(\n\n\n");

  system("pause");
  return 0;
}


///////////////////////////////FUNCIONES//////////////////////////////////////////

int VALIDA_ENTERO (int n)
{
    int x;
    do{
        scanf("%d",&x);
    }while(x<n);

    return x;
}

/*--------------------------------------------------------------------------------*/

char VALIDA_TIPO(void)
{
    char t;

    do{
        fflush(stdin);
        scanf("%c",&t);
        t=toupper(t);
    }while(t!='M'&&t!='S'&&t!='R');

    return t;
}

/*--------------------------------------------------------------------------------*/

int VALIDA_RANGO(int li,int ld)
{
    int x;

    do{
        scanf("%d",&x);
    }while(x<li&&x>ld);

    return x;
}

/*--------------------------------------------------------------------------------*/

void INFORMA_PUNTOA(float v[],int n)
{
    int i;
    printf("________________________________________________________________\n");
    printf("\n\nSEMANA          GANANCIA\n\n");

    for(i=0;i<n;i++)
    {
        printf("   %d            $%.2f\n",i+1,v[i]);
    }
}

/*--------------------------------------------------------------------------------*/

void INFORMA_PUNTOB(int v[],int n)
{
    int i;
    printf("________________________________________________________________\n");
    printf("\n\n\nEl/los meses que no se han ingresado producciones:\n");

    for(i=0;i<n;i++)
    {
        if(v[i]==0)
        printf("%d\t",i+1);
    }
}

/*--------------------------------------------------------------------------------*/

void INFORMA_PUNTOC(float v[],int n)
{
    int i=0;
    float Mini=v[0];
    
    for(i=0;i<n;i++)
    {
        if(v[i]<Mini)
        Mini=v[i];
    }

    INFO_MINI(v,Mini,n);
}

/*--------------------------------------------------------------------------------*/

void INFO_MINI(float v[],float dato,int n)
{
    int i;
    printf("\n________________________________________________________________\n");
    printf("\n\n\nMenor ganancia:$%.2f\n",dato);
    printf("\nEn la/s semanas/s:\t");
    for(i=0;i<n;i++)
    {
        if(v[i]==dato)
        printf("%d\t",i+1);
    }
    printf("\n\n\n");
}