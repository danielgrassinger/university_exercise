#include<stdio.h>

// use unsigned long and double to hanle big numbers
unsigned long fakultaet(unsigned long n);
double getEuler_rek(int);
double getEuler_it(int);

int main(int argc, char *argv[]){

    int n=0;
    if(sscanf(argv[1],"%d",&n)!=1){
        //Failed to read command line arguments
        printf("Fehler beim lesen der Komandozeilenparameter!\n\
                Bitte in folgender Form eingeben: ./p2 Zahl\n");
        return 1;
    }

    printf("e iterativ: %0.15f\n",getEuler_it((unsigned long)n));
    printf("e rekursiv: %0.15f\n",getEuler_rek((unsigned long)n));

}

unsigned long fakultaet(unsigned long n){
    unsigned long erg=1;
    unsigned long iterator;
    for(iterator=1;iterator<=n;iterator++){
        erg*=iterator;
    }
    return erg;
}

double getEuler_rek(int n){
    if(n==0){
        return 1.0;
    }
    return getEuler_rek(n-1)+1.0/((double)fakultaet(n));
}

double getEuler_it(int n){
    double result = 0;
    int iterator;
    for(iterator=0;iterator<=n;iterator++){
        result+=1.0/((double)fakultaet(iterator));
    }
    return result;
}
