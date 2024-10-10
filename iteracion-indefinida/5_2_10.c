#include<stdio.h>
#include<stdlib.h>

int main()

{
    int min=0,ordenmin=0,ordenmax=0,posi=0;
    float temp,max=0;

    printf("\nIngrese temperatura:");
    scanf("%f",&temp);

    while(temp!=-50)
    {
        posi++;
        if(posi==1)
        {
            max=temp;
            ordenmax=posi;
            min=temp;
            ordenmin=posi;
        }
        else
        {
          if(max<temp)
           {
             max=temp;
             ordenmax=posi;
           }
            else
           {
            if(min>temp)
            {
                min=temp;
                ordenmin=posi;
            }
           }
        }
        printf("\nIngrese temperatura:");
        scanf("%f",&temp);

    }
    if(posi>0)
    {
        printf("\nMaximo %.2f ingreso %d\n",max,ordenmax);
        printf("\nMinimo %.2f ingreso %d\n",min,ordenmin);
    }

  system("pause");
  return 0;
}