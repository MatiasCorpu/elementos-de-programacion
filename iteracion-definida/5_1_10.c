#include<stdio.h>
#include<stdlib.h>

int main()

{
  int n,i,cont1=0,cont2=0,cont3=0;
  float num;

  printf("\nIngrese cantidad de numeros a ingresar:\n");
    scanf("%d",&n);

  if(n>0&&n<12)
   {
        for(i=1;i<=n;i++)
        {
            scanf("%f",&num);
             if(num>0)
            cont1++;
        
            else
            {
                if(num<0)
                cont2++;
            
                else
                 if (num==0)
                    cont3++;
           
            }

        }


    printf("\nProm positivos:%.2f\n",((float)cont1*100)/n);
    printf("\nProm negativos:%.2f\n",((float)cont2*100)/n);
    printf("\nCantidad de ceros:%d\n",cont3);
    


   }
  else
  {
    if(n>12)
    printf("\nValor excedido\n");

    else
    printf("\nCantidad invalida\n");
  }


 
  system("pause");
  return 0;
}