#include<stdio.h>
#include<stdlib.h>

int main()

{
  int i,sum=0;


  for(i=50;i<=100;i+=5)
    sum+=i;
      
      
      printf("\t%d\n",sum);
    

  system("pause");
  return 0;
}