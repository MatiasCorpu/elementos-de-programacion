#include<stdio.h>
#include<stdlib.h>
int MOSTRAR_MENU (int,int);
int OPERACIONES (int,int);


int main()

{
    int n1,n2,opcion;

    printf("\nIngrese 2 numeros enteros:\n");
    scanf("%d%d",&n1,&n2);

    while(opcion!=6)
    {
        opcion=MOSTRAR_MENU(n1,n2);

        if(opcion!=5)
        OPERACIONES(n1,n2);
        else
        printf("\nIngresar nuevos numeros:\n");
        
        if(opcion!=6){
        printf("\nIngrese 2 numeros enteros:\n");
        scanf("%d%d",&n1,&n2);
        }

    }

  system("pause");
  return 0;
}
/////////////////////////////////////////////////////////////
//funciones 

int MOSTRAR_MENU (int x , int y)
{
    int op;

    printf("\nMenu de Opciones\n---- -- --------\nNumero 1: xx Numero 2: xx\n1) Sumar\n2) Restar\n3) Multiplicar\n4) Dividir\n5) Ingresar Nuevos Números\n6) Salir\nIngrese su opcion:");

    do
    {
       scanf("%d",&op);
    } while (op>6||op<1);

    return op;
    
}
////////////////////////////////////////////////////////////

int OPERACIONES (int x , int y)
{
    int c;

    switch(c)
    {
        case 1:c=x+y;break;
        case 2:c=x-y;break;
        case 3:c=x*y;break;
        case 4:c=x/y;break;
        case 6:c=6;break;
    }
    if(c!=6)
    printf("\nResultado: %d\n",c);
    else
    return c;
    
}


