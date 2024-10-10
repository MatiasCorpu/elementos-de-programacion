#include<stdio.h>
#include<stdlib.h>

void cargamatriz (int[][4],int,int);
void sumcolumnas(int[][4],int,int,int []);
void mostrarVEC(int [],int);


int main()

{
    int m[5][4],v[4]={0};
    
    printf("Ingrese matriz\n");
    cargamatriz(m,5,4);
    sumcolumnas(m,5,4,v);
    mostrarVEC(v,4);

  system("pause");
  return 0;
}

void cargamatriz(int m[][4],int f,int c)
{
    int i,j;

    for(i=0;i<f;i++)
    {
        for(j=0;j<c;j++)
        scanf("%d",&m[i][j]);
    }
}
//////////////////////////////////////

void sumcolumnas(int m[][4],int f,int c,int v[])
{
    int i,j;

    for(j=0;j<c;j++)
    {
        for(i=0;i<f;i++)
    v[j]+=m[i][j];
    }
}
///////////////////////////////////////////
void mostrarVEC(int v[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d\t",v[i]);
    }
}