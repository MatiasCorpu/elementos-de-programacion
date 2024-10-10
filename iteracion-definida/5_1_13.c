#include<stdio.h>
#include<stdlib.h>

int main()

{
  int contd=0,contp=0,i,j;

    printf("\nNumeros primos entre el 1 y 100:");
    
    
    for(i=1;i<=100;i++)
   {
        for(j=1;j<=i;j++)
        {
            if ((i%j)==0)
            contd++;
           
        }

        if(contd==2)
        {
            contp++;
            printf("\n%d",i);
        }
        contd==0;
   }

    printf("\nCantidad de numeros primos:%d\n\n",contp);


 
  system("pause");
  return 0;
}