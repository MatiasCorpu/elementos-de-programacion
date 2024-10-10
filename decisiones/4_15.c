#include<stdio.h>
#include<stdlib.h>

int main()

{
   int dvd;
   float cuenta, total;

   printf("\nIngrese cantidad de DVDs:");
   scanf("%d",&dvd);

   cuenta=(dvd/50)*500+((dvd%50)/10)*120+((dvd%50)%10*15);

    if ((dvd>=1)&&(dvd<=500))
    {
        if (dvd>100)
        total=cuenta-(cuenta*0.1);

        else
            total=cuenta;

    }

 printf("\nTotal:%.2f\n\n",total);   


  system("pause");
  return 0;
}
