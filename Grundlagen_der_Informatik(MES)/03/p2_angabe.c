#include <stdio.h>

int zweierkomplement(int);
int loescheLetzteBits(int);
int setzeLetzteBits(int);

int main(void){
    int input, option;
    int output = 0;
    
    puts("Geben Sie eine Ganzzahl ein...");
    scanf("%d", &input);
    printf("Sie haben eingegeben: %d (= 0x%X) \n\n", input, input);
    
    puts("Was möchten Sie tun? Bitte Ziffer eingeben...");
    puts("  - 1) Zweierkomplement bilden");
    puts("  - 2) die letzten x Bits löschen");
    puts("  - 3) die letzten x Bits setzen");
    scanf("%d", &option);
    
    // TODO: richtige Funktion aufrufen
    
    printf("Ergebnis: %d (= 0x%X) \n\n", output, output);
}

int zweierkomplement(int source){
    // TODO implementieren
    return 0;
}

int loescheLetzteBits(int source){
    // TODO implementieren
    return 0;
}

int setzeLetzteBits(int source){
    // TODO implementieren
    return 0;
}