#include<stdio.h>
#include "complex.h"

int main(int argc, char **argv){

  complex a, b;
  int in = 0;
  in =  sscanf(argv[1],"%f",&(a.Re));
  in*=  sscanf(argv[2],"%f",&(a.Im));
  in*=  sscanf(argv[3],"%f",&(b.Re));
  in*=  sscanf(argv[4],"%f",&(b.Im));
  if(in<=0){
    printf("Bitte geben Sie das Programm wie folgt ./a.out Re1 Im1 Re2 Im2");
    return 10;
  }


  FILE * fp;
  fp = fopen("results.txt","w");
  if (fp == NULL)
{
    printf("Error opening file!\n");
    return 12;
}
   complex cadd = add(a,b);
   complex csub = sub(a,b);
   complex cmul = mul(a,b);
   complex cdiv = div(a,b);
  fprintf(fp,"(%0.2f + %0.2fi) + (%0.2f + %0.2fi) = (%0.2f + %0.2fi)\n",a.Re,a.Im,b.Re,b.Im,cadd.Re,cadd.Im);
  fprintf(fp,"(%0.2f + %0.2fi) - (%0.2f + %0.2fi) = (%0.2f + %0.2fi)\n",a.Re,a.Im,b.Re,b.Im,csub.Re,csub.Im);
  fprintf(fp,"(%0.2f + %0.2fi) * (%0.2f + %0.2fi) = (%0.2f + %0.2fi)\n",a.Re,a.Im,b.Re,b.Im,cmul.Re,cmul.Im);
  fprintf(fp,"(%0.2f + %0.2fi) / (%0.2f + %0.2fi) = (%0.2f + %0.2fi)\n",a.Re,a.Im,b.Re,b.Im,cdiv.Re,cdiv.Im);
  fclose(fp);

  return 0;
}
