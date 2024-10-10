#include<stdio.h>
#include<stdlib.h>

int main()

{
  int i,cantposi=0,cantnega=0;
  float t;
  for(i=1;i<=5;i++)
  {
    printf("\nIngrrese temperatura:");
    scanf("%f",&t);

    if(t>0)
    cantposi++;

    else
    cantnega++;

  }

    printf("\nTernas positivas %d\n",cantposi/3);
    printf("\nTernas negativas %d\n",cantnega/3);


 
  system("pause");
  return 0;
}