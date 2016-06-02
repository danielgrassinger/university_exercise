#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>
#include  <time.h>

#define MAX  5000
#define LEN  1000

char t[LEN+1];
char *strings[MAX];

void swap(char s1[], char s2[]) {
   char help[LEN+1];
   strcpy(help, s1);
   strcpy(s1, s2);
   strcpy(s2, help);
}

void insert_sort(int n, char *z[]) {
    int  i, j;

    for (i=1; i<n; i++)
       for (j=i;  j>0 && strcmp(z[j], z[j-1]) < 0; j--)
             swap(z[j], z[j-1]);  /*-- Vertauschen von z[j] und z[j-1] */
}
void select_sort(int n, char *z[]) {
    int  i, j, h;

    for (i=0; i<n-1; i++) { /* sucht i. tes Element */
       h = i;
       for (j=i+1; j<n; j++)
          if (strcmp(z[h], z[j]) > 0)
             h = j;  /* Merke neue Position */
       if (h != i)
          swap(z[h], z[i]);  /*-- Vertauschen von z[h] und z[i] */
    }
}
void zeit(int typ, char *sortnam, void (*sort)(int n, char *z[])) {
   int     i, j;
   clock_t start, ende;
   time(start);
   if(typ==1){

   }else if(typ==2){

   }else {
       
   }
   time(ende);
   printf("%s: %d\n",*sortnam,(int)(ende - start) );
   // TODO
}
int  main(int argc, char *argv[]) {
   int i;

   srand(time(NULL));
   for (i=0; i<MAX; i++)
      strings[i] = (char *)malloc(LEN+1);

   printf(".... Guenstigster Fall:\n");
     zeit(1, "Insert-Sort", insert_sort);
     zeit(1, "Select-Sort", select_sort);
   printf(".... Durchschnittlicher Fall:\n");
     zeit(2, "Insert-Sort", insert_sort);
     zeit(2, "Select-Sort", select_sort);
   printf(".... Unguenstigster Fall:\n");
     zeit(3, "Insert-Sort", insert_sort);
     zeit(3, "Select-Sort", select_sort);
   return 0;
}
