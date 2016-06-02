/**
 * e) Die rekursive Funktion rechnet wesentlich laenger als die iterative
 * Funktion. Ausserdem treten bei n = 55 negative Zahlen auf. Grund ist hierfuer
 * der Integer ueberlauf.
 */
#include<stdio.h>

int calc_ggt(int , int );
int fibonacci_rec(int);
int fibonacci_it(int);
void print_fibonacci_sequence(int);
void fibonacci_ggt(int);

int main(int argc, char *argv[]){

    // d)
    int n=0;
    if(sscanf(argv[1],"%d",&n)!=1){
        //Failed to read command line arguments
        printf("Fehler beim lesen der Komandozeilenparameter!\n\
                Bitte in folgender Form eingeben: ./fibonacci Zahl\n");
        return 1;
    }

    // a)
    printf("Fibonacci rekursiv: %d\n",fibonacci_rec(n));
    // b)
    printf("Fibonacci iterativ: %d\n",fibonacci_it(n));
    // c)
    //print_fibonacci_sequence(n);
    // f)
    fibonacci_ggt(n);

}

// Function which calculate ggt
int calc_ggt(int number1, int number2){
	while (number1 != number2)
	{
	    if (number1 > number2)
			{
	        number1 = number1 - number2;
	    }
		else
		{
		    number2 = number2 - number1;
		}
	}
	return number1;
}

int fibonacci_rec(int n){
    if(n==1 || n==0){
        return 1;
    }else{
        return fibonacci_rec(n-1) + fibonacci_rec(n-2);
    }
}

int fibonacci_it(int n){
    int fibonacciszahlen[n+1];
    fibonacciszahlen[0]=1;
    fibonacciszahlen[1]=1;

    int iterator;
    for(iterator=2;iterator<=n;iterator++){

        fibonacciszahlen[iterator]= fibonacciszahlen[iterator-1]
                                  + fibonacciszahlen[iterator-2];

    }
    return fibonacciszahlen[n];
}

void print_fibonacci_sequence(int n){

    int iterator;
    for(iterator=0;iterator<=n;iterator++){
        printf("%d\n",fibonacci_it(iterator));
    }
}

void fibonacci_ggt(int n){
    int fibonacciszahlen[n+1];
    fibonacciszahlen[0]=1;
    fibonacciszahlen[1]=1;

    int iterator;
    for(iterator=2;iterator<=n;iterator++){

        fibonacciszahlen[iterator]= fibonacciszahlen[iterator-1]
                                  + fibonacciszahlen[iterator-2];

        printf("GGT von %d und %d ist: %d\n",
               fibonacciszahlen[iterator],fibonacciszahlen[iterator-1],
               calc_ggt(fibonacciszahlen[iterator],fibonacciszahlen[iterator-1]));
    }

}
