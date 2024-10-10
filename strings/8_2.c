/*8.2. Ingresar dos Strings, uno con el nombre y el otro con el apellido de una persona. Utilizando las funciones
de la biblioteca string.h generar un tercer string formado por: NOMBRE, APELLIDO (nombre coma espacio
y apellido) y mostrarlo.*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void CARGATEXTO(char[],int);

int main()

{
  char NOMBRE[20],APELLIDO[20],ayn[40];

  printf("\nIngrese Nombre\n");
  gets(NOMBRE);
  printf("\nIngrese apellido:\n");
  gets(APELLIDO); 
  
  strcpy(ayn,NOMBRE);
  strcat(ayn,", ");
  strcat(ayn,APELLIDO);
  
  printf("\nNombre y apellido:%s\n\n",ayn);
  system("pause");
  return 0;
}
//////////////funciones///////////////////
void CARGATEXTO(char texto[],int n)
{
    int largo;
    fgets(texto,n,stdin);
    largo=(strlen(texto));
    if(texto[largo-1]=='\n');
    texto[largo-1]=='\0';
}
