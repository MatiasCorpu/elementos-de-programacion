#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>


void cargamatriz (int[][3],int,int);
void multiplica(int[][3],int,int,int);
void mostrar(int[][3],int,int);


int main()
{
    int m[3][3],n;

    printf("Ingrese matriz 3x3\n");
    cargamatriz(m,3,3);
    printf("Ingrese numero a multiplicar matriz\n");
    scanf("%d",&n);
    multiplica(m,3,3,n);
    mostrar(m,3,3);
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
void multiplica (int m[][3],int f,int c,int n)
{
   int i,j;

    for(i=0;i<f;i++)
    {
        for(j=0;j<c;j++)
        m[i][j]*=n;
    } 
}/*wuwuwuwuwuwuwuwuwuwuwuwFUNCIONESuwuwuwuwuwuwuwuwuwuwuwuwomONICHAN*/
void mostrar(int m[][3],int f,int c)
{
    int i,j;

    for(i=0;i<f;i++)
    {
        printf("\n");
        for(j=0;j<c;j++)
        printf("%d\t",m[i][j]);
    }
}