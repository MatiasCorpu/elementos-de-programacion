#include<stdlib.h>
#include<stdio.h>
#include<string.h>

typedef struct
{
    int DNI;
    char NombreApellido[81];
    int nota1;
    int nota2;
    float Promedio;
}sAlumno;

void CARGAalumnos();
void LECTURA();

int main()
{
    CARGAalumnos();
    LECTURA();

    system("pause");
    return 0;
}
/////////funciones////////////
void CARGAalumnos()
{
    sAlumno alum;
    int i=0;

    FILE* ap;
    ap= fopen("ALUMNOS.dat","wb");
    if(ap==NULL)
    {
        printf("Error al abrir el archivo");
        system("pause");
        exit(1);
    }

    do{
    printf("\nIngrese numero de DNI de alumno %d:\n",i+1);
    scanf("%d",&alum.DNI);
    }while(alum.DNI<0);

    while(alum.DNI!=0)
    {
        i++;
        fflush(stdin);
        printf("\nIngrese su nombre y apellido:\n");
        gets(alum.NombreApellido);

        do{
        printf("\ningrese Nota 1:\n");
        scanf("%d",&alum.nota1);
        }while(alum.nota1<0);

        do{
        printf("\ningrese Nota 2:\n");
        scanf("%d",&alum.nota2);
        }while(alum.nota2<0);

        alum.Promedio=(alum.nota1+alum.nota2)/2;

        fwrite(&alum,sizeof(alum),1,ap);

        do{
        printf("\nIngrese numero de DNI de alumno %d:\n",i+1);
        scanf("%d",&alum.DNI);
        }while(alum.DNI<0);

    }
    
    fclose(ap);
}
////////////////////////////////////////////////////////////
void LECTURA()
{
    sAlumno al;
    FILE* pf;
    pf=fopen("ALUMNOS.dat","rb");
    if(pf==NULL)
    {
        printf("Error al abrir el archivo");
        system("pause");
        exit (1);
    }

    printf("\n\nDNI       nombre y apellido     nota1 nota 2    promedio\n");

    fread(&al,sizeof(al),1,pf);
    while(!feof(pf))
    {
        printf("\n%d     %s        %d     %d      %.2f",al.DNI,al.NombreApellido,al.nota1,al.nota2,al.Promedio);
        fread(&al,sizeof(al),1,pf);
    }

    fclose(pf);
}
