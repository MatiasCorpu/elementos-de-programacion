#include<stdio.h>
int main()

{
    int dia,mes,ano,fecha;

    printf("\nIngrese fech:");
    scanf("%d",&fecha);

    dia=fecha/10000;
    mes=(fecha%10000)/100;
    ano=(fecha%10000)%100;

    printf("\nFecha en formato aammdd:%d/%d/%d",ano,mes,dia);


    system("pause");
    return 0;

}



