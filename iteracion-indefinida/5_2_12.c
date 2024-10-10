#include<stdio.h>
#include<stdlib.h>

int main()

{
    int max=0,cont=1,posi=0,cont7=0,sum=0,n1,n2,n3;

    while(cont<=6)
    {
        cont++;
        printf("\nIngrese 3 numeros eneros:\n");
        scanf("%d%d%d",&n1,&n2,&n3);

        max=n1;
        posi=1;

        if(max<n2)
        {
            max=n2;
            posi=2;
        }
        
        
        if(max<n3)
         {
          max=n3;
          posi=3;
         }
        
        if(n1%7==0||n2%7==0||n3%7==0)
        cont7++;

        sum+=n1;

        printf("\nMayor valor de terna %d en la posicion %d\n",max,posi);
        printf("\nMultiplos de 7 xd: %d\n",cont7);
    } 

    printf("\nPromedio de los primeros numeros %.2f\n",(float)sum/6);



  system("pause");
  return 0;
}