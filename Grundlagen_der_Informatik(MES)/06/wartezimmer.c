#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 20 // maximale Laenge des Namens eines Patienten

// Element einer verketteten Liste
struct patient {
    char name[MAX];
    char vorname[MAX];
    int rnummer;
    struct patient *previous;
};
typedef struct patient Patient;

Patient *platzhalter;
static int nummer = 1;

int schlange_init(void) {
    if((platzhalter=malloc(sizeof(Patient))) != NULL)  {
        strcpy(platzhalter->name,"platzhalter");
        strcpy(platzhalter->vorname,"platzhalter");
        platzhalter->rnummer=0;
        platzhalter->previous=NULL;
        return 1;
    }
    else {
        fprintf(stderr,"Konnte keinen Speicher reservieren!!\n");
        return 0;
    }
}

/* Wir hängen ein neues Element an das Ende der Schlange. */
int put(Patient *neu) {
    Patient *cursor;

    /* Ist es das 1. Element in der Schlange? */
    if(platzhalter->previous == NULL) { /* Es ist das 1. Element. */
        platzhalter->previous=neu;
        neu->previous=NULL;
        return 1;
    }
    /* Es ist nicht das 1. Element. */
    else {
        cursor=platzhalter;
        /* Wir suchen das Ende der Schlange. */
        while(cursor->previous != NULL)
            cursor=cursor->previous;
        cursor->previous=neu;
        neu->previous=NULL;
        return 1;
    }
}


/* Wir benötigen das 1. Element der Liste, das wir auch als 1.
 * eingegeben haben. */
// TODO
void get(void) {
    if(platzhalter->previous != NULL){
      Patient *swap;

      swap = platzhalter->previous;
      free(platzhalter);
      platzhalter = swap;
    }
}

void eingabe(void) {
    Patient *neu;
    char n[MAX],vn[MAX];

    if((neu=(Patient *)
        malloc(sizeof(Patient))) != NULL) {
        printf("Vorname..: ");
        fgets(vn, MAX, stdin);
        strcpy(neu->vorname,strtok(vn,"\n"));
        printf("Name.....: ");
        fgets(n, MAX, stdin);
        strcpy(neu->name, strtok(n,"\n"));
        printf("Nummer...: ");
        printf("%d\n\n",neu->rnummer = nummer++);
        neu->previous=NULL;
        put(neu);
    }
}

void ausgabe(void) {
    if(platzhalter->previous != NULL) {
        printf("\n%s, %s Nummer.: %d \n\n",
               platzhalter->previous->name,platzhalter->previous->vorname,
               platzhalter->previous->rnummer);
        get();
    }
    else
        printf("Keine Patienten im Wartezimmer vorhanden.\n");
}

int main(void) {
    int wahl;

    schlange_init();
    do {
        printf("-1- patient eingeben\n");
        printf("-2- Naechster Patient\n");
        printf("-3- Programmende\n\n");
        printf("Ihre Wahl : ");
        scanf("%d",&wahl);
        getchar();
        switch(wahl) {
            case 1  :
                eingabe();
                break;
            case 2  :
                ausgabe();
                break;
            case 3  :
                if(platzhalter->previous != NULL) {
                    printf("Es sind noch Patienten"
                           " im Wartezimmer.\n\n");
                    wahl = 4; /* Abhauen gilt nicht */
                }
                break;
            case 4  :
                break;
            default :
                printf("Falsche Eingabe!!\n\n");
        }
    } while(wahl != 3);
    printf("\n\nFeierabend\n");
    return EXIT_SUCCESS;
}
