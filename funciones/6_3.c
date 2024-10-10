#include<stdio.h>
#include<stdlib.h>
int cuadrante (int,int);
int puntaje (int,int,int,int,int);

int main()

{
  int cont0tot=0,c,band=0,cont1=0,cont2=0,cont3=0,cont4=0,cont0=0,i=0;
  int np,x,y,punt,ganador,puntajE;

  printf("\nIngrese numero de participante:\n");
  scanf("%d",&np);

  while(np>=0)
  {

    cont1=0;
    cont2=0;
    cont3=0;
    cont4=0;
    cont0=0;

    for(i=1;i<=5;i++)
    {
        do{
        printf("\nDisparo %d\n",i);
        scanf("%d%d",&x,&y);
        }while(x==0&&y!=0||x!=0&&y==0);
    
    
        c=cuadrante(x,y);

        switch(c)
        {
        case 1:cont1++;break;
        case 2:cont2++;break;
        case 3:cont3++;break;
        case 4:cont4++;break;
        case 0:
        cont0++;
        cont0tot++;break;
        }

  

    }
    band++;

    punt= puntaje (cont1,cont2,cont3,cont4,cont0);

    printf("\nPuntaje participante %d:%d\n",band,punt);

    
    

    if(band==1){
        ganador=np;
        puntajE=punt;
      }
    else{
     if(puntajE<punt)
     {
        ganador=np;
        puntajE=punt;
     }
    }
    printf("\nIngrese numero de participante:\n");
    scanf("%d",&np);
    
  }

    printf("\nGanador:%d\n",ganador);
    printf("Su puntaje:%d\n",puntajE);
    printf("\nCantidad total (0,0):%d\n",cont0tot);


  system("pause");
  return 0;
}
/////////////////////////////////////////////////////
int cuadrante (int x , int y)
{
   int i=0;
    
    if(x>0&&y>0)
        i=1;
        
        if(x<0&&y>0)
        i=2;
        
        if(x<0&&y<0)
        i=3;
        
        if(x>0&&y<0)
        i=4;

    return i;    
}
/////////////////////////////////////////////////////////

int puntaje (int x,int y,int j, int k,int l)
{
    int p;

    p=(x+y)*50+(j+k)*40+l*100;

    return p;
}
