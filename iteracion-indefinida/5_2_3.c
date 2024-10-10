#include<stdio.h>
#include<stdlib.h>

int main()

{
  int contalfmay=0,contalfmin=0,contnum=0,contsimb=0;
  char c;
    fflush(stdin);
    printf("Ingresa caracter");
    scanf("%c",&c);

  while(c!='*')
  {
    if(c>='0'&&c<='9')
    contnum++;
    else
    {
        if(c>='a'&&c<='z')
        contalfmin++;

        else
        {
            if(c>='A'&&c<='Z')
             contalfmay++;

             else
             contsimb++;
        }
    }
    fflush(stdin);
    printf("Ingresa caracter");
    scanf("%c",&c);

  }

  
  printf("Cantidad de numeros:%d",contnum);
  printf("Cantidad de letras mayusculas:%d",contalfmay);
  printf("Cantidad de letras minusculas:%d",contalfmin);
  printf("Cantidad de simbolos:%d",contsimb);

  system("pause");
  return 0;
}