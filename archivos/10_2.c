#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct
{
    int DNI;
    char NombreApellido[81];
    int nota1;
    int nota2;
    float Promedio;
}sAlumno;

void GeneraArchivos();
void Lectura(char []);

int main()

{
    printf("\nARCHIVO ORIGINAL:\n\n\n");
    Lectura("ALUMNOS.dat");
    
    GeneraArchivos();

    printf("\n\n\nPROMOCIONADOS");
    Lectura("PROMOCIONADOS.dat");

    printf("\n\n\nCURSADOS");
    Lectura("CURSADOS.dat");

    printf("\n\n\nREPROBADOS");
    Lectura("REPROBADOS.dat");

    printf("\n\n\n\n\n");
    
  system("pause");
  return 0;
}
///////////////////////////////////////////////
void GeneraArchivos ()
{
    sAlumno al;
    FILE *pf1,*pf2,*pf3,*pf4;

    pf1= fopen("ALUMNOS.dat","rb");
    pf2=fopen("PROMOCIONADOS.dat","wb");
    pf3=fopen("CURSADOS.dat","wb");
    pf4=fopen("REPROBADOS.dat","wb");
    if(pf1==NULL||pf2==NULL||pf3==NULL||pf4==NULL)
    {
        printf("ERROR al abrir alguno de los archivos");
        system("pause");
        exit(1);
    }

    fread(&al,sizeof(al),1,pf1);
    while(!feof(pf1))
    {
        if(al.nota1>=7&&al.nota2>=7)
        fwrite(&al,sizeof(al),1,pf2);
        else
        if(al.nota1>=4&&al.nota2>=4)
        fwrite(&al,sizeof(al),1,pf3);
        else
        fwrite(&al,sizeof(al),1,pf4);

        fread(&al,sizeof(al),1,pf1);
    }
    fclose(pf1);
    fclose(pf2);
    fclose(pf3);
    fclose(pf4);

}
////////////////////////////////////////////////////////////
void Lectura (char QueArchivo[])
{
    sAlumno al;
    FILE *pf;
    pf=fopen(QueArchivo,"rb");
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
        printf("\n%d           %s              %d          %d           %.2f",al.DNI,al.NombreApellido,al.nota1,al.nota2,al.Promedio);
        fread(&al,sizeof(al),1,pf);
    }

    fclose(pf);
}