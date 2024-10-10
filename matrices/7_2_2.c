#include<stdio.h>
#include<stdlib.h>

void cargamatriz (int[][3],int,int);
void trasponer(int[][3],int,int,int[][2]);
void mostrar(int[][2],int,int);

int main()

{
  int mt[3][2]={{0}},m[2][3];

  printf("Ingrese matriz\n");
    cargamatriz(m,2,3);

    trasponer(m,2,3,mt);
    
    mostrar(mt,3,2);

  system("pause");
  return 0;
}
/*wuwuwuwuwuwuwuwuwuwuwuwFUNCIONESuwuwuwuwuwuwuwuwuwuwuwuwomONICHAN*/

void cargamatriz(int m[][3],int f,int c)
{
    int i,j;

    for(i=0;i<f;i++)
    {
        for(j=0;j<c;j++)
        scanf("%d",&m[i][j]);
    }
}
/*wuwuwuwuwuwuwuwuwuwuwuwFUNCIONESuwuwuwuwuwuwuwuwuwuwuwuwomONICHAN*/

void mostrar(int m[][2],int f,int c)
{
    int i,j;

    for(i=0;i<f;i++)
    {
        printf("\n");
        for(j=0;j<c;j++)
        printf("%d\t",m[i][j]);
    }
}
/*wuwuwuwuwuwuwuwuwuwuwuwFUNCIONESuwuwuwuwuwuwuwuwuwuwuwuwomONICHAN*/
void trasponer(int m[][3],int f,int c ,int mt[][2])
{
    int i,j;

    for(j=0;j<c;j++)
    {
        
        for(i=0;i<f;i++)
        mt[j][i]=m[i][j];
    }    
}