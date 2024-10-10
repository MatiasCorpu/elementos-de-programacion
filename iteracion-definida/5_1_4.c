#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>


int main()

{
  int cont=0,i;
  char L;

    for(i=1;i<=10;i++)
    {
        printf("\nINgrese letra numero %d:",i);
        fflush(stdin);
        scanf("%c",&L);

        L=tolower(L);

        if (L=='a'||L=='e'||L=='i'||L=='o'||L=='u')
            cont++;
       
    }


    printf("\nCantida de vocales %d\n\n",cont);



 
  system("pause");
  return 0;
}