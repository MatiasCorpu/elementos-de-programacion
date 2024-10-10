#include<stdio.h>
#include<stdlib.h>
#include<string.h>



typedef struct{
    int Num_canal;
    char Programa[36];
    float Rating;
}esRATING;

typedef struct{
    int Num_canal;
    float promedio_rating;
}esPromRATING;




void Mostrar(char[]);
void InformarCREARarch(char[]);
void MostrarProm(char[]);

int main()
{
    Mostrar("RATING.dat");
    InformarCREARarch("RATING.dat");
    MostrarProm("RATING_PROM.dat");

  system("pause");
  return 0;
}



////////////////////FUNCIONES////////////////////////
void Mostrar(char Archivo[])
{
    esRATING rat;
    FILE *pf;

    pf=fopen(Archivo,"rb");
    if(pf==NULL)
    {
        printf("No se pudo abrir el archivo");
        system("pause");
        exit(1);
    }
    printf("\n\nNUM.CANAL                 PROGRAMA                RATING\n");
    fread(&rat,sizeof(rat),1,pf);
    while(!feof(pf))
    {
        printf("\n%5d    %30s         %8.2f",rat.Num_canal,rat.Programa,rat.Rating);

        fread(&rat,sizeof(rat),1,pf);
    }
    fclose(pf);
    printf("\n\n");
}
/////////////////////////////////////////////////////////
void InformarCREARarch(char Archivo[])
{
    esRATING rat,anterior_rat;
    esPromRATING prom;
    FILE *pfrat, *pfprom;
    float sum_rating,maxi;
    int contador_cnales;
    int primero=1,canalmaxi;

    
    
    pfrat=fopen(Archivo,"rb");
    pfprom=fopen("RATING_PROM.dat","wb");

    if(pfprom==NULL||pfrat==NULL)
    {
        printf("\n Error ala abrir el archivo");
        system("pause");
        exit(1);
    }
    
    fread(&rat,sizeof(rat),1,pfrat);
    while (!feof(pfrat))
    {
        sum_rating=0;
        contador_cnales=0;
        anterior_rat.Num_canal=rat.Num_canal;
        
        while(anterior_rat.Num_canal==rat.Num_canal && !feof(pfrat))
        {
            sum_rating+=rat.Rating;
            contador_cnales++;

            fread(&rat,sizeof(rat),1,pfrat);
        }
        
        if(primero||sum_rating>maxi)
        {
            maxi=sum_rating;
            canalmaxi=anterior_rat.Num_canal;
            primero=0;
        }

        if(sum_rating<(float)15)
        printf("\nCANAL %d no supero los 15 puntos de rating totales\n\n",anterior_rat.Num_canal);
        
        prom.Num_canal=anterior_rat.Num_canal;
        prom.promedio_rating=(sum_rating/contador_cnales);
        fwrite(&prom,sizeof(prom),1,pfprom);
    }

    fclose(pfprom);
    fclose(pfrat);

    if(!primero)
        printf("\n\nEl canal mas visto fue %d con %.2f\n\n",canalmaxi,maxi);
    else
    printf("\nNO datos xd\n");
    
}
//////////////////////////////////////////////////
void MostrarProm(char Archivo[])
{
    esPromRATING prom;
    FILE *pf;

    pf=fopen(Archivo,"rb");
    if(pf==NULL){
        printf("Error");
        system("pause");
        exit(1);
    }
    printf("\n\n\n\n\nNUM.CANAL    PROMEDIO\n");
    fread(&prom,sizeof(prom),1,pf);
    while(!feof(pf)){
        printf("\n%5d        %5.2f",prom.Num_canal,prom.promedio_rating);
        
        fread(&prom,sizeof(prom),1,pf);

    }
    printf("\n\n\n");
    fclose(pf);
}
/////////////////////////////////////////////////////////