#include<stdio.h>
#include<stdlib.h>

int main()

{
   int band=0,contotal=0;
   float imp,imptotal,total=0,desc;

  
   printf("Ingresa importe:\n");
    scanf("%f",&imp);

    while(imp>0)
    {
        if(imp>300)
        {
            
            desc=imp*0.25;
        }
        else
        {
            if(imp<=300&&imp>=151)
            {
                
                desc=imp*0.2;

            }
            else
            {
                if(imp<=150&&imp>=50)
                {
                    
                    desc=imp*0,1;

                }
                else
                desc=imp*0.035;
            }
        }
        contotal++;
        imptotal=imp-desc;
        total+=imptotal;
        band=1;
        printf("Descuneto:%.2f\n",desc);
        printf("Importe total:%.2f\n",imptotal);

     printf("Ingresa importe:\n");
     scanf("%f",&imp);
    }
    printf("Importe promedio de todas las ventas:%.2f\n",total/contotal);

  system("pause");
  return 0;
}