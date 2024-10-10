#include<stdio.h>
#include<stdlib.h>

int sumamatriz(int[][15],int,int);
void mostrar(int[][15],int,int);

int main()

{
  int m[5][15],piso,dep,suma;

  printf("\nIngrese num de piso:\n");
  scanf("%d",&piso);

  while (piso!=99)
  {
    printf("\nIngrese num de departamento:\n");
    scanf("%d",&dep);

    m[piso-1][dep-1]+=1000;

    printf("\nIngrese num de piso:\n");
  scanf("%d",&piso);

  }

  suma=sumamatriz(m,5,15);

  printf("\nTotal recaudado xdxdxdx:%d\n",suma);
  mostrar(m,5,15);

  system("pause");
  return 0;
}
////////////////////////////////////////////

void mostrar(int m[][15],int f,int c)
{
    int i,j;

    for(i=0;i<f;i++)
    {
        printf("\n");
        for(j=0;j<c;j++)
        if(m[i][j])
        printf("X\t");
        else
        printf(" ");
        
    }
}
////////////////////////////////////////////
int sumamatriz(int m[][15],int f,int c)
{
    int i,j,s;

    for(i=0;i<f;i++)
    {
        for(j=0;j<c;j++)
        s+=m[i][j];
    } 
    return s;
}