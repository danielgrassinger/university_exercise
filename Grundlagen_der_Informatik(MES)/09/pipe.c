#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define BUFSIZE 20
#define EXIT_PIPE_ERROR 1
#define EXIT_FORK_ERROR 2

int main(void)
{
    int pid, status, exitCode;
    int fd[2]; /* 1==write, 0==read */
    char buf[BUFSIZE];

    // TODO Pipe erzeugen
    if(pipe(fd)<0){
        printf("Error while initializing pipe!\n");
        return EXIT_PIPE_ERROR;
    }
    // TODO: Forking
    pid = fork();

    // TODO: Fallunterscheidung
        // Kindprozess:  Lesen
        // Vaterprozess: Schreiben
    if(pid==0){

        if(read(fd[0],buf,BUFSIZE)<0){
            printf("Error in child while reading pipe!\n");

            return EXIT_PIPE_ERROR;
        }

        printf("%s\n",buf);
        close(fd[0]);
        printf("Child end!\n" );


    }else if(pid>0){
        strcpy(buf,"Hello Prozess");

        if(write(fd[1],buf,BUFSIZE)<0){
            printf("Error while writing into pipe!\n");
            return EXIT_PIPE_ERROR;
        }

        close(fd[1]);
        // Warten bis der Kindprozess zu Ende ist, dann Vaterprozess beenden...
        while (wait(&status) !=pid);
        printf("Parent Ende!\n" );

    }else{
        printf("Error while creating child process!\n");
        return EXIT_FORK_ERROR;
    }


    return EXIT_SUCCESS;
}
