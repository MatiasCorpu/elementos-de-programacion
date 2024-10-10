#include<stdio.h>
#include<stdlib.h> //es para el system pause

#define pi 3.14


int main()
{
    float r;

    printf("\nIngrese valor de radio de un circulo:");
    scanf("%f",&r);

    printf("\nSuperficie:%f\nPerimetro:%f\nVolumen:%f\n",pi*r*r,2*pi*r,4*pi*r*r*r);


    system("pause");
    return 0;
    


}