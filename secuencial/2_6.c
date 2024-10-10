#include<stdio.h>

int main()
{
    int n1,n2,r1,r2;

    printf("\nIngrese cantidad de pasajes vendido, clase tuurista y pro¿imera clase:");
    scanf("%d%d",&n1,&n2);

    r1=8800*n1;
    r2=((8800*30)/100+8800)*n2;


    printf("\nrecaudacion total:%d$\n",r1+r2);

    system("pause");
    return 0;   

}