#include<stdio.h>
#include<stdlib.h>

int main()

{
  
    int n,i,j,asteriscos,espacios;


    printf("\nIngresar un numero:");
    scanf("%d",&n);


     asteriscos=1,
     espacios=n-1;


      for(i=1;i<=n;i++)
    {
       
        for(j=1;j<=espacios;j++)
          printf(" ");
        espacios--;
        
         
        
        for(j=1;j<=asteriscos;j++)
          printf("*");
        asteriscos+=2;
       
        printf("\n");

    }
    

  system("pause");
  return 0;
}