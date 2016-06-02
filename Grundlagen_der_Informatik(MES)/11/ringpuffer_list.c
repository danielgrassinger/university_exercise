#include <stdio.h>
#include <stdlib.h>

#define DEFAULT_BUFFER_SIZE 10

typedef struct {
    int value;          // Wert bzw. Inhalt des Elements
    void* nextElement;  // Zeiger auf nächstes Element
} element;

typedef struct {
    int maximumSize;    // Größe des Ringpuffers
    int currentSize;    // Anzahl der belegten Zellen des Ringpuffers
    element *headElement;  // Zeiger auf Kopf-Element
    element *tailElement;  // Zeiger auf Tail-Element
} ringbuffer;

ringbuffer* createBuffer(int size){
    // Reserviere Speicher für Ringpuffer und initialisiere seine Variablen
    ringbuffer* buffer = (ringbuffer*) malloc(sizeof(*buffer));
    buffer->maximumSize = size;
    buffer->currentSize = 0;
    buffer->tailElement = NULL;
    buffer->headElement = NULL;
    return buffer;
}

void destroyBuffer(ringbuffer* buffer){

    while(buffer->headElement!=NULL){
        // free headElement and set pointer to the next element
        element *tmp= buffer->headElement->nextElement;
        free(buffer->headElement);
        buffer->headElement=tmp;
    }
    // free buffer itself
    free(buffer);
}

void put(ringbuffer* buffer, int value){
    // DONE Neues Element anlegen und richtig einsortieren
    if(buffer->tailElement==NULL){
        // first element
        // allocate new element
        buffer->tailElement=calloc(1,sizeof(element));
        // set the headElement pointer to the start
        buffer->headElement=buffer->tailElement;
        // write value into element
        buffer->tailElement->value=value;
        // increase current size variable
        buffer->currentSize++;
    }else{
        if(buffer->currentSize < buffer->maximumSize){
            // allocate new element
            buffer->tailElement->nextElement=calloc(1,sizeof(element));
            // set tailElement pointer to next element
            buffer->tailElement=buffer->tailElement->nextElement;
            // write value into element
            buffer->tailElement->value=value;
            // increase current size variable
            buffer->currentSize++;
        }else{
            fprintf(stderr, "Reached maximum size of ringbuffer!\n");
            exit(1);

        }
}
}

int get(ringbuffer* buffer){
    int returnValue = 0;
    // TODO Wert auslesen, Listenelement entfernen, Verknüpfungen anpassen
    if(buffer->headElement!=NULL){
        // read value
        returnValue = buffer->headElement->value;
        // tmp variable to free the element
        element* tmp = buffer->headElement;
        // set pointer to the next element
        buffer->headElement=buffer->headElement->nextElement;
        free(tmp);
        // decrease current size variable
        buffer->currentSize--;
    }else{
        fprintf(stderr, "Reached end of ringbuffer!\n");
        exit(1);
    }

    return returnValue;
}

int main(int argc, char* argv[]) {
    int bufferSize = DEFAULT_BUFFER_SIZE;
    // Ringpuffergröße einlesen falls vorhanden
    if (argc > 1) {
        bufferSize = atoi(argv[1]);
    }

    // Ringpuffer erstellen
    ringbuffer* buffer = createBuffer(bufferSize);
    int i;
    // Testen von Schreiben und Lesen
    for (i = 1; i <= 45; i++) {
        put(buffer, i);
        if (i % 3 == 0) {
            printf("%d\n",get(buffer));
        }
    }
    // Ringpuffer wieder zerstören
    destroyBuffer(buffer);
    return EXIT_SUCCESS;
}
