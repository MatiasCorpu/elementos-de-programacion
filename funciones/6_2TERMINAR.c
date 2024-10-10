#include<stdio.h>
#include<stdlib.h>
int leeryvalidar (int,int);
int estadentrodelrango (int,int,int);


int main()

{
  int sum=0,cont1=0,cont2=0,cont3=0,num;
  int c1,c2,c3,band=0;

    printf("\nIngresar numero entre 100 y 2000\n");
    num=leeryvalidar(99,2000);

    while(num!=99)
    {
     band=1;

    c1=estadentrodelrango(num,100,500);
    if(c1==1)
    cont1++;
    

    c2=estadentrodelrango(num,500,1200);
    if(c2==1)
    cont2++;
    

    c3=estadentrodelrango(num,1200,2000);
    if(c3==1)
    cont3++;
    
    if(num>=1200&&num<=2000)
        sum+=num;

    printf("\nIngresar numero entre 100 y 2000\n");
    num=leeryvalidar(99,2000);
    }
    
    
    if(band==1)
    {
    printf("\nCantidad de numeros(100,500):%d\n",cont1);
    printf("\nCantidad de numeoros(500,1200):%d\n",cont2);

    if(c3>0)
    printf("promedio de (1200,2000):%d\n",sum/cont3);
    else
    printf("\n\npromedio:%d\n",sum);
    }
    else
    printf("\nNo se ingreso nada xd\n");


  system("pause");
  return 0;
}

////////////////////////////////////////////////

int leeryvalidar (int li, int ld)
{
    int x;

    do{
        scanf("%d",&x);
    }while(x<li||x>ld);

    return x;
}

///////////////////////////////////////////////////
int estadentrodelrango (int x ,int li , int ld)
{
    int i=0;

    if(x>li&&x<ld)
    i=1;

    return i;
}




