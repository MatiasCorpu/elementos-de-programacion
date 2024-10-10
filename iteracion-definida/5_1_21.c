#include<stdio.h>
#include<stdlib.h>

int main()

{
  
    int n,i,j,asteriscos,k,l;


    printf("\nIngresar un numero:");
    scanf("%d",&n);


     asteriscos=1;
     


      for(i=1;i<=n;i++)
    {
       
        for(j=1;j<=asteriscos;j++)
          printf("*");
        asteriscos+=2;
        printf("\n");
    }
    
    
      for(k=1;k<=n;k++)
    {
        
        for(l=1;l<=asteriscos;l++)
          printf("*");
         asteriscos-=2;
        printf("\n");
    }


      printf("*\ns");  
    

  system("pause");
  return 0;
}