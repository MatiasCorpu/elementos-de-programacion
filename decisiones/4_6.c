#include<stdio.h>
#include<stdlib.h>

int main()

{
   int n1,n2,n3,n4;
   int posi=0,num=0;


   printf("\n\nIngrese 4 numeros enteros:");
    scanf("%d%d%d%d",&n1,&n2,&n3,&n4);

    if ((n1<n2)&&(n1<n3)&&(n1<n4))
    {
     posi=1;
     num=n1;
    }
    else
        if ((n2<n3)&&(n2<n4))
        {
         posi=2;
         num=n2;
        }
        else
        if (n3<n4)
        {
            posi=3;
            num=n3;
        }
        else
        {
        posi=4;
        num=n4;
        }


    printf("\n\nValores ingresados %d-%d-%d-%d\nEl menor es %d, orden %d\n\n\n",n1,n2,n3,n4,num,posi);

system("pause");
return 0;
}

