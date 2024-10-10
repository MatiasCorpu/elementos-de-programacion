#include<stdio.h>

int main()

{
    float n,m,g,t;

    printf("\nIngrese valor expresado en KIB:");
    scanf("%f",&n);

    m=n/1024;
    g=m/1024;
    t=g/1024;

    printf("\nValor en MIB:%f\nValor en GIB:%f\nValor en TIB:%f\n",m,g,t);

    system("pause");
    return 0;

}