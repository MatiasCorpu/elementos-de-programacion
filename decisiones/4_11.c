#include<stdio.h>
#include<stdlib.h>

int main()

{
    int a,m;

   printf("\nIngresar año y numero de mes:");
   scanf("%d%d",&a,&m);


   switch (m)
   {
      case 1 :case 3 :case 5 :case 7 :case 8 :case 10 :case 12:
      printf("\n31 dias\n");break;
    
      case 4 :case 6 :case 9 :case 11:
      printf("\n30 dias\n");break;

      case 2:
          if (a%4==0&&a%100!=0||a%400==0)
           printf("\n29 dias\n");     
            else
            printf("\n28 dias\n");
        break;

   
   default: printf("\nerror\n");
   
   }



  system("pause");
  return 0;
}

