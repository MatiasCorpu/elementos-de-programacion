#include<stdio.h>
#include<stdlib.h>

int main()
{
    int empanadas;
    float doc,uni;

    printf("\nIngrese cantidad de enmpanadas:");
    scanf("%d",&empanadas);

    doc=(empanadas/12)*300;
    uni=(empanadas%12)*30;

    printf("\nPresio tatal:%.2f\n",doc+uni);


    system("pause");
    return 0;       


}