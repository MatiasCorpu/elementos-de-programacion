#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>


int main()

{
   char na,aux;
    
   
   printf("\n\nIngrese un alfanumerico:");
   scanf("%c",&na);
   aux=tolower(na);
  
     
     switch(aux)
     {
        case 'a':
        printf("\nEs vocal, numero ASCII:%d\n",na);break;
        
        case 'e':
        printf("\nEs vocal, numero ASCII:%d\n",na);break;
       
        case 'i':
        printf("\nEs vocal, numero ASCII:%d\n",na);break;
        
        case 'o':
        printf("\nEs vocal, numero ASCII:%d\n",na);break;
        
        case 'u':
        printf("\nEs vocal, numero ASCII:%d\n",na);break;
               
        
        default : 
        printf("\nNo ingresaste una vocal\n");


     }



  system("pause");
  return 0;
}

 