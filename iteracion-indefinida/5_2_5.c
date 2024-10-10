#include<stdio.h>
#include<stdlib.h>

int main()

{
    int cont=0,contp=0,dni;
    float n1,n2,sum=0;

     printf("Ingrese dni:");
     scanf("%d",&dni);

     while(dni>0){
        cont++;
    
      do{
      printf("Ingrese 2 notas de parcial:");
      scanf("%f%f",&n1,&n2);
      }while(n1<0||n2<0);

      if(n1>=7&&n2>=7){
        printf("\nEl alumno %d obtuvo nota %.2f y %.2f, PROMOCIONO XD\n",dni,n1,n2);

        contp++;
        sum+=n1+n2;
      }
      else{
        if(n1>=4&&n2>=4)
         printf("\nEl alumno %d obtuvo nota %.2f y %.2f, RINDE FINAL XD\n",dni,n1,n2);

         else
          printf("\nEl alumno %d obtuvo nota %.2f y %.2f, RECURSOP XDXDXDXDDDD");

      }
      printf("Ingrese dni:");
     scanf("%d",&dni);

     }
   
 if(cont==0)
 printf("\nNo se ingresaron datos\n");
 else
 printf("\nNota promedio de los que promocionaron:%.2f\n",sum/(contp*2));




  system("pause");
  return 0;
}