#include<stdio.h>
#include<stdlib.h>

int main()

{
  int i,n,sum=0;

  printf("\nIngresar un numero:");
  scanf("%d",&n);

  
  for(i=1;i<=n;i+=1)
    sum+=i;
      
   printf("\nSUMA:%d\n",sum);
 
  system("pause");
  return 0;
}