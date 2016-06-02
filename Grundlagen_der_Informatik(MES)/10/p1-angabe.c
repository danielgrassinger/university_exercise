#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAXLENGTH 100
#define MAXLINES 100

// TODO (siehe unten)

// P1 a)
char ** readRezeptListe(char* filename);

// P1 b)
void bubble_sort(int n, int z[]);

// P1 c)
void stringBubbleSort(int n, char **s);

// P1 d)
void merge(int z[], int temp[], int links, int mitte, int rechts);
void merge_sort(int z[], int temp[], int links, int rechts);

// P1 e)
void cleanup(char ** stringArray);

// Hilfsfunktionen:
void printStringArray(int n, char **stringArray);
int getArrayLength(char ** stringArray);
void testBubbleSort();
void testStringBubbleSort(char *filename);
void testMergeSort();

int  main(int argc, char *argv[]) {
    char* filename;
    if(argc >1){
        filename = argv[1];
    }
    else{
        filename = "plaetzchen.txt";
    }
    
    testBubbleSort();
    testStringBubbleSort(filename);
    
    return 0;
}



/*
    P1 a)
    BUBBLE SORT
*/
char ** readRezeptListe(char* filename){
    char *line;
    char **result;
    
    // TODO
    
    return result;
}



/*
    P1 b)
    BUBBLE SORT (INTEGERS)
*/
void bubble_sort(int n, int z[]) {
    // TODO
}


/*
    P1 c)
    BUBBLE SORT (STRINGS)
*/
void stringBubbleSort(int n, char **s){
    // TODO
}










/*
    P1 d)
    MERGE SORT
*/

void merge(int z[], int temp[], int links, int mitte, int rechts) {
   int i, j, k;
}
void merge_sort(int z[], int temp[], int links, int rechts) {
   int mitte;
}














/*
    P1 e)
    Aufräumarbeiten
*/
void cleanup(char ** stringArray){
    // wir haben vorher speicher für jeden einzelnen String reserviert...
    // TODO jede Speicherzelle des Arrays freigeben (zweite Ebene)
    // TODO Array GesamtSpeicher wieder freigeben (erste Ebene)
}





/**********************************************************************************
        H I L F S F U N K T I O N E N
**********************************************************************************/
void printStringArray(int n, char ** stringArray){
    int i;
    printf("\n");
    for(i=0;i<n;i++){
        if(*(stringArray+i) == NULL){
            return;
        }
        printf("%s\n",*(stringArray+i));
    }
    printf("\n");
}

int getArrayLength(char ** stringArray){
    int i = 0;
    while(*(stringArray+i)!=NULL){
        i++;
    }
    return i;
}

void testBubbleSort(){
    int size = 10;
    int i, k, zahlen[size];
    
    printf("---- testBubbleSort() -----------------\n");
    
    srand(time(NULL));
    
    for (i=0 ; i<size ; i++)
        zahlen[i] = rand()%100;
    
    printf("-- vor bubble_sort -----------------\n");
    for (k=0; k<size; k++)
        printf("%3d", zahlen[k]);
    printf("\n\n");
    
    bubble_sort(size, zahlen);
    
    printf("-- nach bubble_sort ---------------\n");
    for (k=0; k<size; k++)
        printf("%3d", zahlen[k]);
    printf("\n");
}


void testStringBubbleSort(char *filename){
    int length;
    char** plaetzchenListe;
    
    plaetzchenListe = readPlatzchenListe(filename);
    length = getArrayLength(plaetzchenListe);
    printf("---- testStringBubbleSort() -----------------\n");
    printf("Es sind %i Rezepte in der Liste\n",length);
    
    stringBubbleSort(length,plaetzchenListe);
    
    cleanup(plaetzchenListe); // memory leaks vermeiden -- hier zwar nicht notwendig aber sinnvoll!
}
void testMergeSort(){
    
    int i, k, zahlen[TEST_CASES], temp[TEST_CASES];
    
    printf("---- testMergeSort() -----------------\n");
    
    srand(time(NULL));
    
    for (i=0 ; i<TEST_CASES; i++)
        zahlen[i] = rand()%100;
    
    printf("-- vor merge_sort -----------------\n");
    for (k=0; k<TEST_CASES; k++)
        printf("%3d", zahlen[k]);
    printf("\n\n");
    
    merge_sort(zahlen, temp, 0, TEST_CASES-1);
    
    printf("-- nach merge_sort ---------------\n");
    for (k=0; k<TEST_CASES; k++)
        printf("%3d", zahlen[k]);
    printf("\n");

}


