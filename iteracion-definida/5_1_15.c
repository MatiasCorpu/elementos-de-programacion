#include<stdio.h>
#include<stdlib.h>

int main()

{
  int i,j,cont1=0,cont2=0,cont3=0,cont4=0,contc=0,x,y;

    for(i=1;i<=5;i++)
    {
        printf("\n\nParticipante:%d\n",i);

        for(j=1;j<=3;j++)
        {
        printf("\ndisparo:%d\n",j);
        scanf("%d%d",&x,&y);

        if(x>0&&y>0)
        cont1++;
        
        if(x<0&&y>0)
        cont2++;
        
        if(x<0&&y<0)
        cont3++;
        
        if(x>0&&y<0)
        cont4++;
        
        if(x==0&&y==0)
        contc++;

        }

        printf("\nprimer cuadrante:%d",cont1);
        printf("\nsegundo cuadrante:%d",cont2);
        printf("\ntercer cuadrante:%d",cont3);
        printf("\ncuarto cuadrante:%d",cont4);
           
        cont1=0;
        cont2=0;
        cont3=0;
        cont4=0;


    }

    printf("\nDisparos totales en el centro:%d\n\n",contc);

 
  system("pause");
  return 0;
}