#include<stdio.h>
#include<stdlib.h>

int main()

{
  int posi=0,max1=0,max2=0,min=0,n;

  printf("Ingresa numero entero:");
    scanf("%d",&n);

    while(n!=0)
    {
        posi++;
        if(posi==1)
        {
            max1=n;
            max2=n;
            //min=n;
        }
        else
        {
            if(max1<n)
            max1=n;

            else
            {
                if(min>n)
                min=n;

                else
                {
                    if(n>min&&n<max1)
                    max2=n;
                }
            }
        }
        
        printf("Ingresa numero entero:");
        scanf("%d",&n);
    }
    if(posi==0)
    printf("\nNo se ingreso numeros\n");
    else
    {
        if(posi==1)
        printf("\nSe ingreso un solo numero:%d\n",n);
        else
        printf("\nlos dos numeors maximos: %d y %d\n",max1,max2);
    }
    


  system("pause");
  return 0;
}