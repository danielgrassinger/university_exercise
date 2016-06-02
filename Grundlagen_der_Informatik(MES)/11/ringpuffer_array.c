#include <stdio.h>
#include <stdlib.h>

#define DEFAULT_BUFFER_SIZE 10

typedef struct {
    int *cells;         // Zeigt auf das Array mit den Ringpuffer-Elementen
    int maximumSize;    // Größe des Ringpuffers
    int currentSize;    // Anzahl der belegten Zellen des Ringpuffers
    int headIndex;      // Position des jüngsten Elements
    int tailIndex;      // Position des ältesten Elements
} ringbuffer;

ringbuffer* createBuffer(int size){
    // Reserviere Speicher für Ringpuffer und initialisiere seine Variablen
    ringbuffer* buffer = (ringbuffer*) malloc(sizeof(*buffer));
    buffer->maximumSize = size;
    buffer->currentSize = 0;
    buffer->tailIndex = 0;
    buffer->headIndex = -1;
    buffer->cells = (int*) calloc(size, sizeof(*(buffer->cells)));
    return buffer;
}

void destroyBuffer(ringbuffer* buffer){
    // DONE allen Speicher freigeben, der reserviert wurde
    // free the cells
    free(buffer->cells);
    // free the buffer itself
    free(buffer);
}

void put(ringbuffer* buffer, int value){
    // DONE Neues Element anlegen und richtig einsortieren
    if(buffer->currentSize < buffer->maximumSize){
        // write value
        buffer->cells[buffer->headIndex]=value;
        // increase tail index
        buffer->tailIndex=(buffer->tailIndex+1)%buffer->maximumSize;
        // increase current size variable
        buffer->currentSize++;
    }else{
        fprintf(stderr, "Reached maximum size of ringbuffer!\n");
        exit(1);
    }
}

int get(ringbuffer* buffer){
    int returnValue = 0;

    // DONE Wert auslesen, Listenelement "entfernen", Indizes anpassen
    returnValue = *((*buffer).cells+buffer->headIndex);
    *((*buffer).cells+buffer->headIndex) = 0;
    buffer->headIndex=(buffer->headIndex+1)%buffer->maximumSize;
    buffer->currentSize--;

    return returnValue;
}

int main(int argc, char* argv[]) {
    int bufferSize = DEFAULT_BUFFER_SIZE;
    if (argc > 1) {
        bufferSize = atoi(argv[1]);
    }
    // Ringpuffer erstellen
    ringbuffer* buffer = createBuffer(bufferSize);
    // Testen von Schreiben und Lesen
    int i;
    for (i = 1; i <= 45; i++) {
        put(buffer, i);
        if (i % 3 == 0) {
            printf( "%d\n", get(buffer));
        }
    }
    // Ringpuffer wieder entfernen
    destroyBuffer(buffer);
    return EXIT_SUCCESS;
}
