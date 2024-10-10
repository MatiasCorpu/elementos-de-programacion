#include<stdio.h>
#include<stdlib.h>
void mayormenor(int,int,int);

int main()

{
  int n1,n2,n3;


  do{
  printf("\nIngrese 3 numeros:\n\n");
  scanf("%d%d%d",&n1,&n2,&n3);
  }while(!((n1>0&&n1<99)&&(n2>0&&n2<99)&&(n3>0&&n3<99)));

  while(n1!=96&&n2!=97&&n3!=98)
  {
    mayormenor(n1,n2,n3);

    do{
  printf("\nIngrese 3 numeros:\n\n");
  scanf("%d%d%d",&n1,&n2,&n3);
  }while(!((n1<0&&n1>99)&&(n2<0&&n2>99)&&(n3<0&&n3>99)));
  }

  system("pause");
  return 0;
}
///////////////////////////////////////////////////////

void mayormenor (int x,int y,int z)
{
    if(x>y&&x>z)
    printf("\nEl mayor es:%d\n",x);
    else
    {
        if(y>z)
        printf("\nEl menor es:%d\n",z);
        else
        printf("\nEl menor es:%d\n",y);
        
    }

    if(y>x&&y>z)
    printf("\nEl mayor es:%d\n",y);
    else
    {
        if(x>z)
        printf("\nEl menor es:%d\n",z);
        else
        printf("\nEl menor es:%d\n",x);
        
    }

    if(z>x&&z>y)
    printf("\nEl mayor es:%d\n",z);
    else
    {
        if(x>y)
        printf("\nEl menor es:%d\n",y);
        else
        printf("\nEl menor es:%d\n",x);
        
    }
    
}