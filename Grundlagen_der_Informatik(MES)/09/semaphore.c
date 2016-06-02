#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ipc.h>
#include <sys/sem.h>

#define RECHTE        0666    // Semaphoren-Zugriffsrechte
#define KEY           951753L // beliebiger Schluessel

// Struktur mit Semaphor-Kommandos; wird für den Aufruf von semop() benötigt
struct sembuf semaphore;
// Enthält die ID des verwendeten Semaphors
int semid;

int initSemaphor (void) {
   // Testen, ob das Semaphor bereits existiert
   semid = semget (KEY, 0, IPC_PRIVATE);
   if (semid < 0) {

      // Semaphor ggf. anlegen & initialisieren
      umask(0);
      semid = semget (KEY, 1, IPC_CREAT | IPC_EXCL | RECHTE);
      if (semid < 0) {
         printf ("Fehler beim Anlegen des Semaphors ...\n");
         return -1;
      }
      printf ("(angelegt) Semaphor-ID : %d\n", semid);
      // Semaphor mit 1 initialisieren
      if (semctl (semid, 0, SETVAL, (int) 1) == -1)
         return -1;
   }

   return 1;
}

int setzeSemaphor (int op) {
    semaphore.sem_op = op;
    semaphore.sem_flg = 0;
    if( semop (semid, &semaphore, 1) == -1) {
       printf(" semop ");
       exit (EXIT_FAILURE);
    }
    return 1;
}

int main (void) {
   // Initialisiere Semaphore
   int res;
   res = initSemaphor ();
   if (res < 0)
      return EXIT_FAILURE;
   printf ("Vor dem kritischen Codeausschnitt ...\n");
   // Lock Semaphore
   setzeSemaphor(-1);
   /* BEGINN Kritischer Codeausschnitt */
   printf ("PID %d verwendet Semaphor %d\n",
      getpid(), semid);
   printf ("Im kritischen Codeabschnitt ...\n");
   sleep (10); // Um das Ausprobieren zu erleichtern warten wir hier 10 Sekunden
   /* ENDE Kritischer Codeabschnitt */
   // Unlock Semaphore
   setzeSemaphor(1);
   printf ("Nach dem kritischen Codeausschnitt ...\n");
   return EXIT_SUCCESS;
}
