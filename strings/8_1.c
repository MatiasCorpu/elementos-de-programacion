/*8.1. Ingresar una frase de hasta 500 caracteres y contar cuántas palabras contiene dicha frase.
a. Considerar que las palabras están separadas por un único espacio.
b. Considerar que las palabras pueden estar separadas por más de un espacio consecutivo.*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int ContarPalabras(char []);

int main()
{
    char frase[501];
    int largo;
    
    printf("\nIngrese una frase de nos mas de 500 caracteres:\n");
    fgets(frase,501,stdin);
    largo=(strlen(frase));
    if(frase[largo-1]=='\n');
    frase[largo-1]=='\0';
    
    printf("La frase ingresada tiene %d palabras\n\n",ContarPalabras(frase));

    system("pause");
    return 0;
}
////////funciones////////////////////////
/*int ContarPalabras (char frase[])
{
 int i=0,cont=0;
 while(frase[i]!='\0'){
    if(frase[i]==' ')
    cont++;
    i++;
 }
 return(cont+1);
}*/

 int ContarPalabras (char frase[])
{
  int i=0,cont=0;
 while(frase[i]!='\0'){
    if(i>0&&frase[i]==' '&&frase[i-1]!=' ')
    cont++;
    i++;
 }
 if(i>0&&frase[i-1]!=' ')
 cont++;
 
 return(cont);  
}