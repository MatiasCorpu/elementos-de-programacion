/*8.3. Ingresar nombre y DNI de los alumnos de un curso. Como máximo el curso puede tener 50 alumnos. La
carga finaliza con un alumno de nombre FIN. Luego de cargar los alumnos se pide:
a. Ingresar nombres de a uno en uno y buscarlos. Si el nombre está en el curso mostrar su DNI y sino
informar que no está. Seguir ingresando nombres hasta que se ingrese un nombre igual a
NOBUSCARMAS.
b. Mostrar el listado de alumnos ordenado alfabéticamente de menor a mayor.*/


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>


int CARGARnombresydni(char[][51],int[],int,char[]);
int BUSCAR(char [][51],char[],int);
void ORDENAR(char[][51],int);
void MOSTRAR(char [][51],int);

int main()

{
  char NOM_ALUM[50][51],FIN1[4]={"FIN"},FIN2[12]={"NOBUSCARMAS"},NOMBRE[51];
  int VDNI[50],posi,i=0,posi2;

  posi= CARGARnombresydni(NOM_ALUM,VDNI,50,FIN1);
    
    printf("\nIngrese nombre de alumno a buscar\n");
    fflush(stdin);   
    gets(NOMBRE);
    

    while(strcmpi(NOMBRE,FIN2)!=0&&posi>0){
        
        posi2=BUSCAR(NOM_ALUM,NOMBRE,posi);
        
        if(posi2!=-1)
        printf("Su dni es :%d",VDNI[posi2]);
       
        else
        printf("\nnombre no encontrado ingresar nuevamente\n\n");
         
        i++;
        
        printf("\nIngrese nombre de alumno a buscar\n");
        fflush(stdin);
        gets(NOMBRE);
        
    }
    if (posi>0)
    {
        ORDENAR(NOM_ALUM,posi);
        MOSTRAR(NOM_ALUM,posi);
    }
    


  system("pause");
  return 0;
}
//////funciones///////////////
int CARGARnombresydni(char M[][51],int v[],int n,char f[])
{
    int i=0;
    
    printf("\nIngrese Nombre del alumno:\n");
    fflush(stdin);
    gets(M[i]);
    
    while (strcmpi(M[i],f)!=0&&i<n)
    {
       printf("\ningrese numero de dni:\n");
        scanf("%d",&v[i]);
        i++;
        
        printf("\nIngrese Nombre del alumno:\n");
        fflush(stdin);
        gets(M[i]);
    }
    return i;
    
}
////////////////////////////////
int BUSCAR (char M[][51],char v[],int n)
{
    int i=0,posi=-1;
    while(posi==-1&&i<n)
    {
        if (strcmpi(M[i],v)==0)
        {
            posi=i;
        }
        else
        i++;
        
    }
    return posi;
}
//////////////////////////////
void ORDENAR(char m[][51],int n)
{
    char aux[51];
    int cota=n,des=1,i;

    while (des!=0)
    {
        des=0;
        for(i==1;i<cota;i++)
        {
            if(strcmpi(m[i-1],m[i])>0)
            {
                strcpy(aux,m[i-1]);
                strcpy(m[i-1],m[i]);
                strcpy(m[i],aux);

                des=i;
            }
        }
        cota=des;
    }
    

}
////////////////////////////////////////
void MOSTRAR (char m[][51],int n)
{
    int i;
    //system("cls");
    for(i=0;i<n;i++)
    printf("\n%s\n",m[i]);
}