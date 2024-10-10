#include<stdio.h>
#include<stdlib.h>
int espar (int);
int resto (int,int);
int esprimo (int);
int validar (int,int,int,int);


int main()

{
    int cantprimos=0,cantpar=0,sumim=0,contim=0,n,a,b,c,i=0;

    do{
    printf("\nIngrese valor\n");
    scanf("%d",&n);
    }while((c=validar(n,1,50,-10))==0);


    while(n!=-10)
    {
        i++;
        
        a=espar(n);
        if(a==1)
        cantpar++;
        else{
        contim++;
        sumim+=n;
        }
        
        b=esprimo(n);
        if(b==1)
        cantprimos++;
        

       do{
       printf("\nIngrese valor\n");
       scanf("%d",&n);
       }while((c=validar(n,1,50,-10))==0);

        

    }
if(i>0){
    printf("\nCantidad de primos:%d\n",cantprimos);
    printf("\nCantidad de pares:%d\n",cantpar);
    if(contim!=0)
    printf("\nProm de numeros pares:%.2f\n",(float)sumim/contim);
    else
    printf("\nNo se ingresaron numeros primos\n");

      }
      else
      printf("\nNo se ingresaron numeros\n\n");

  

  system("pause");
  return 0;
}
/////////////////////////////////////////////////////////


int espar (int x)
{
    int i=0;
    if(x%2==0)
    i=1;

    return i;
}

///////////////////////////////////////////////////////////
int resto (int x, int i)
{
    int resu;
    resu=x%i;
    return resu;
}
//////////////////////////////////////////////////////
int esprimo (int x)
{
    int i=0,r,rst,band=0;
    
    for(i=x;i>=1;i--)
    {
        r=resto(x,i);

        if(r==0)
        rst++;
    }
    if(rst==1)
    band=1;

    return band;
}
//////////////////////////////////////////////////////////
int validar (int x,int li,int ld,int fin)
{
    int i=0;
    if(x==fin)
    i=1;
    else
    {
        if(x>=li&&x<=ld)
        i=2;
    }

    return i;

}
