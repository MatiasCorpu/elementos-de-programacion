#include <stdio.h>


int main()


{
    int tarros;

    printf("\nIngrese cantidad de tarros:");
    scanf("%d",&tarros);

      printf("\nTarros de 1LT:%d",(tarros*50)/100);
      printf("\nTarros de 4LTS:%d",(tarros*30)/100);
      printf("\nTarros de 20LTS:%d\n\n",(tarros*20)/100);
      
 system("pause");
 return 0;
}