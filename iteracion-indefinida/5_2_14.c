#include<stdio.h>
#include<stdlib.h>

int main()

{
  int cont10=0,mayor=0,mayorleg=0,canth=0,cantm=0,band=0,lg,an,cat;
  float sb,suel,adi;
  char sexo;

  do{
      printf("\nIngrese legajo:");
      scanf("%d",&lg);
      }while(!(lg>=100&&lg<=5000));
  
  while(lg!=0)
  {
    band=1;

      do{
      printf("\nIngrese sueldo basico:");
      scanf("%f",&sb);
      }while(sb<1000);

      do{
      printf("\nIngrese antiguedad:");
      scanf("%d",&an);
      }while(an<0);

      do{
      fflush(stdin);
      printf("\nIngrese sexo:");
      scanf("%c",&sexo);
      sexo=touppper(sexo);
      }while(sexo!='M'||sexo!='F');
     
      fflush(stdin);
      do{  
      printf("\nIngrese categoria:\n");
      scanf("%d",&cat);
      }while(!(cat>1&&cat<5);


      switch(c)
      {
        case 2:case 2:
        suel=sb+500;break;

        case 4:
        suel=sb+(sb*0.1);break;

        case 5:
        suel=sb+(sb*0.3);break;

        default:
        suel=sb;break;
      }
      if(an>10)
      {
        adi=sb*0.1;
        suel=suel+adi;
        cont10++;
      }
      printf("\nSueldo a abonar del empleado %d es de %.2f\n",lg,suel);

      if(suel>mayor)
      {
        mayor=suel;
        mayorleg=lg;
      }
      if(sexo=='M')
      canth++;
      else
      cantm++;


      do{
      printf("\nIngrese legajo:");
      scanf("%d",&lg);
      }while(!(lg>=100&&lg<=5000));


  }

  if(band==1)
  {
    printf("\nCantidad de empleados mayores a 10 años: %d\n",cont10);
    printf("\nMayor sueldo: %.2f, legajo %d\n",mayor,mayorleg);
    printf("\nCantidad de hombres: %d\n",canth);
    printf("\nCantidad de mujeres: %d\n",cantm);
  }
  else
  printf("\nNo se ingresaron datos xdxdxdxd\n");



  system("pause");
  return 0;
}