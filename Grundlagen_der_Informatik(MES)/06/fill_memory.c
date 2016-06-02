#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* vertauscht zwei Variablenwerte */
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

/* Nimmt das letzte Element eines Arrays als Pivot-Element,
   führt alle notwendigen Vertauschungen durch und
   gibt die finale Position des Pivot-Elements zurück  */
int partition(int z[], int left, int right) {
    int x = z[right];
    int i = left-1;
    int j = right;
    // So lange vertauschen, bis links alle kleineren Elemente
    // und rechts alle größeren Elemente als der Pivot stehen
    while(1) {
        while(z[++i] < x){
            ;
        }
        while(z[--j] > x) {
            ;
        }
        if(i < j){
            swap(&z[i], &z[j]);
        }
        else {
            swap(&z[i], &z[right]);
            return i;
        }
    }

}

/**
 TODO
 **/
void quick_sort(int z[], int left, int right){
  if((abs(right - left) <= 1)){
    return;
  }else{
    int pivot = partition(z, left,right);

    quick_sort(z,left, pivot-1);
    quick_sort(z,pivot+1, right);
  }
}

/**
 Hilfsfunktion, die ein Array auf die Konsole ausgibt
 **/
void print_array(int a[], int length){
    int i;
    for(i=0; i < length; i++){
        printf("%d", a[i]);
        if(i < length-1){
            printf(",");
        }
        else{
            puts("\n");
        }
    }
}

void write_output(FILE *outfile, int a[], int length){
  int i;
  for(i=0; i < length; i++){
      fprintf(outfile,"%d", a[i]);
      if(i < length-1){
          fprintf(outfile,",");
      }
      else{
          fprintf(outfile,"\n");
      }
  }
}


int main(void) {
    int mem = 0;
    printf("Für wie viele Integers soll Speicher reserviert werden? ");
    scanf("%d", &mem);
    printf("%d\n",mem);

    // TODO
    // Intializes random number generator
    srand (time(NULL));

    int * list;
    if( (list= (int*) malloc(mem*sizeof(int)))==NULL){
      fprintf(stderr,"Konnte keinen Speicher reservieren!!\n");
      return 1;
  }
    int i;
    for(i=0;i<mem;i++){
      list[i] = rand()%100;
    }

    // Open file and write the original list
    FILE *f = fopen("sortlist.txt","w");
    print_array(list,mem);
    write_output(f,list,mem);

    // Sort the list
    quick_sort(list,0,mem-1);


    // Write result into FILE
    print_array(list,mem);
    write_output(f,list,mem);
    fclose(f);

    free(list);
}
