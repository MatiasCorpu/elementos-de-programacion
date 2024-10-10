#include<stdio.h>
#include<stdlib.h>

int main()

{
    int n,a,b,c,d,sum1,sum2,e,f;

    printf("\nIngrese un número de 4 cifras:");
    scanf("%d",&n);

    a=n/1000;
    b=(n%1000)/100;
    c=((n%1000)%100)/10;
    d=((n%1000)%100)%10;

    sum1=a+b+c+d;
    
    e=sum1/10;
    f=sum1%10;

    sum2=e+f;

    printf("\nInforme:%d\n\n\n",sum2);
    

    
    system("pause");
    return 0;



}