#include <stdio.h>

int main ()
{
int HT;
float VPH,SDO;

printf("\n Ingrese horas trabajadas:");
   scanf("%d",&HT);

printf("\n Ingrese paga por hora:");
   scanf("%f",&VPH);

SDO=HT*VPH;

printf("\n Su sueldo es: %.2f",SDO);

system("pause");
return 0;
}
