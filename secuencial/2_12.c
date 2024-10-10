#include<stdio.h>
#include<stdlib.h>

int main()

{
    float p,total;
    int c;

    printf("\nIngrese precio de producto y su código:");
    scanf("%f%d",&p,&c);

    total=p-(p*0.2)*c;

    printf("\nPrecio total:%.2f\n",total);



    system("pause");
    return 0;

}