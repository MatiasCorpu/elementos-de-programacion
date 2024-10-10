#include<stdio.h>
#include<stdlib.h>

int main()

{
   int n1,n2,n3,uno,dos,tres;

   printf("\n\nIngrese 3 numeros enteros:");
    scanf("%d%d%d",&n1,&n2,&n3);

    if (n1<n2&&n1<n3)
    {
        uno=n1;

        if (n2<n3)
        {
        dos=n2;
        tres=n3;
        }
        else
        {
        dos=n3;
        tres=n2;
        }
        
    }
    else
    {
        if (n1>n2&&n1>n3)
        tres=n1;
    
        if (n2<n3)
        {
        dos=n2;
        tres=n3;
        }

        else
        {
        dos=n3;
        tres=n2;
        }

        
    }
    
    printf("\nDemayor a menor:%d-%d-%d",uno,dos,tres);

 system("pause");
 return 0;
}

