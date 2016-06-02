#include <stdio.h>
#include <stdlib.h>

void combsort(int *input, unsigned int count, float factor);

// Function to swap two values
void swap(int *data, int pos1, int pos2){
    int tmp = data[pos1];
    data[pos1]=data[pos2];
    data[pos2]=tmp;
}

int main(int argc, const char* argv[]) {
    int data[] = {10, 9, 11, 5, 1, 12, 6, 7, 8, 4, 3, 16, 0, 13, 2 };
    float factor;
    // Shrink Factor einlesen
    if(argc > 1){
        factor = atof(argv[1]);
    }

    // Unsortiertes Array ausgeben
    int i;
    int numElements = sizeof(data)/sizeof(int);
    for(i=0;i<numElements;i++){
        printf("%d ",data[i] );
    }
    printf("\n");

    // Sortieren
    combsort(data, (unsigned int) numElements,factor);

    // Sortiertes Array ausgeben
    for(i=0;i<numElements;i++){
        printf("%d ",data[i] );
    }
    printf("\n");

    return 0;
}

void combsort(int *input, unsigned int count, float factor) {
    int gap = count;
    int swapCounter= 0;
    int comparisonCounter= 0;


    for(gap=(int)((float)gap/factor);gap>1;gap=(int)((float)gap/factor)){

        if(gap<=1)break;


        int j=0;
        int i;
        for(i=gap;i<count; i+=gap){

            comparisonCounter++;
            if(input[j]<input[i]){
                swapCounter++;
                swap(input,i, j);
            }
            j=i;
        }

    }

    int localSwapCounter;
    do{
        localSwapCounter=0;
        int i;
        for(i=1;i<count;i++){
            comparisonCounter++;
            if(input[i-1]<input[i]){
                swapCounter++;
                localSwapCounter++;
                swap(input,i-1, i);
            }
        }
        comparisonCounter++;
    }while(localSwapCounter>0);

    printf("Shrink Factor: %0.2f -> Comparisons: %d, Swaps: %d\n",factor, comparisonCounter,swapCounter );
}
