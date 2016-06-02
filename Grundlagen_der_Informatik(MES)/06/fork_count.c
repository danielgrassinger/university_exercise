#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void count( n) {
	int pid, i, j, counter;
	counter = 0;

	// Prozess teilen; Der return-Wert gibt uns Aufschluss darüber,
	// in welchem Prozess wir uns danach befinden
	pid = fork();
	if (pid == 0) {
		/*
		 * Kindprozess
		 */
		 pid = fork();
		 if(pid == 0){
			 for (j = 0; j < n; j++) {
	 			counter++;
	 			printf("Kind Kind: %d\n", counter);

	 		}
	 		printf("Kind Kind fertig!\n");
	 		exit(0);
		}else if(pid >0){
			 for (j = 0; j < n; j++) {
	 			counter++;
	 			printf("Kind : %d\n", counter);

	 		}
	 		printf("Kind fertig!\n");
	 		exit(0);
		} else{
			/* Wird ein negativer Wert zurückgegeben, ist ein Fehler aufgetreten */
			fprintf(stderr, "Error");
			exit(1);
		}


	} else if (pid > 0) {
		/*
		 * Elternprozess
		 */
		for (i = 0; i < n; i++) {
			counter++;
			printf("Vater: %d\n", counter);
		}
		printf("Vater fertig!\n");
		exit(0);

	} else {
		/* Wird ein negativer Wert zurückgegeben, ist ein Fehler aufgetreten */
		fprintf(stderr, "Error");
		exit(1);
	}
}

int main(void) {
	int n;

	puts("Wie hoch soll das n sein?");
	scanf("%d", &n);
	count(n);

	return EXIT_SUCCESS;
}
