#include <stdio.h>

int main()

{
    float N1,pul,yar,cms,mts;

      printf("\nIngrese medida en pies:");
        scanf("%f",&N1);

        pul=N1*12;
        yar=N1/3;
        cms=N1*30.48;
        mts=N1*0.3048;
    
       
      printf("\nEn pulgadas:%.2f",pul);
      printf("\nEn Yardas:%.2f",yar);
      printf("\nEn cms:%.2f",cms);
      printf("\nEn mts:%.2f",mts);
       
    system("pause");
    return 0;


}