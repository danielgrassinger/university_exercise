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


    switch(option){
      case 1: {
        output = zweierkomplement(input);
        break;
      }
      case 2: {
        output = loescheLetzteBits(input);
        break;
      }
      case 3: {
        output = setzeLetzteBits(input);
        break;
      }
      default: {
        printf("Bitte geben Sie eine gueltige Zahl ein!");
        return 1;
      }
    }

    printf("Ergebnis: %d (= 0x%X) \n\n", output, output);
}

int zweierkomplement(int source){
    // TODO implementieren
    int neg = ~source + 1;
    return neg;
}

int loescheLetzteBits(int source){

    int bits = 0;
    printf("Wie viele Bits moechten Sie loeschen? \n");
    scanf("%d",&bits);


    return source & (~0 << bits);
}

int setzeLetzteBits(int source){
  int bits = 0;
  printf("Wie viele Bits moechten Sie setzen? \n");
  scanf("%d",&bits);


  return source | ~(~0 << bits);
}
