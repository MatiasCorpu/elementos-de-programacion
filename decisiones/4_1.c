#include<stdio.h>
#include<stdlib.h>

int main()

{
    int MAY,N1,N2,N3;
    printf("\n\nIngrese 3 númros enteros:");
    scanf("%d%d%d",&N1,&N2,&N3);

    if ((N1>N2)&&(N1>N3))
        MAY=N1;
    
    else
    {
            if (N2>N3)
            MAY=N2;

            else
            MAY=N3;
            

    }
    
    printf("\n\nEl mayor es:%d\n\n",MAY);


  system("pause");
  return 0;
}