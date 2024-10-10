#include<stdio.h>
#include<stdlib.h>

int main()

{
    float cobrar,desc,n;
    printf("\nINgrese importe:");
    scanf("%f",&n);

    if (n>100)
    {
     desc=n*0.105;
     cobrar=n-desc;
    }
    else
        if (n>=55&&n<=100)
        {
           desc=n*0.08;
           cobrar=n-desc; 
        }
        else
            {
            desc=n*0.045;
            cobrar=n-desc;
            }

    printf("\nDescuento:%.2f\nPresio a cobrar:%.2f\n\n",desc,cobrar);



 system("pause");
 return 0;
}
