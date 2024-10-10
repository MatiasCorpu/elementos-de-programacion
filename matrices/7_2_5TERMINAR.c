#include<stdio.h>
#include<stdlib.h>
void mostrar(char[][9],int,int);
int rango (int,int);
void cargamatriz (char[][9],int,int);


int main()

{
  int butaca,fila,cantdisp=0,cantres=0,cantfva=0,v1[12]={0},v2[9]={8,6,4,2,1,3,5,7,9},v3[9]={0};
  char m[12][9];

  int i=0,x=0,y=0;
  
   cargamatriz(m,12,9); 
  
  mostrar(m,12,9);
  printf("\n\nIngrese fila:");
  fila=rango(1,12);
  while(fila>0)
  {
    i++;
    printf("INgrese num de butacas:");
    butaca=rango(1,9);

    if(m[fila-1][butaca-1]=='d')
    {
        m[fila][butaca]='r';
    }
    else
    printf("\n\nAsiento ocupao\n");

    mostrar(m,12,9);
  printf("\n\nIngrese fila:");
  fila=rango(1,12);
  
  }

  if (i!=0)
  {
    for(x=0;x<12;x++)
    {
        for(y=0;y<9;y++)
        {
            if (m[x][y]=='d')
            {
                cantdisp++;
            }
            else
            cantres++;
            
        }
        if(cantdisp==9)
        cantfva++;

    }
  }

  system("pause");
  return 0;
}

//////////////////////////////////////////////////////

void cargamatriz (char m[][9],int f,int c)
{
    int i,j;

    fflush(stdin);
    for(i=0;i<f;i++)
    {
        for(j=0;j<c;j++)
        m[i][j]='d';
    }
}

//////////////////////////
void mostrar(char m[][9],int f,int c)
{
    int i,j;

    for(i=0;i<f;i++)
    {
        printf("\n");
        for(j=0;j<c;j++)
        printf("%c\t",m[i][j]);
    }
}
////////////////////////////////////
int rango(int x,int y)
{
    int n;
    do{
        scanf("%d",&n);
    }while(n<x||x>y);
    return x;
}