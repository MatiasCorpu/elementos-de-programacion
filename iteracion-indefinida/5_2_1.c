#include<stdlib.h>
#include<stdio.h>

int main()
{
    int pot=1;
    
    while(pot<600)
    {
        if(pot==1)
        printf("%d\n",pot);

        pot=pot*2;
        
        if(pot<600)
        printf("%d\n",pot);


    }

    system("pause");
    return 0;
}