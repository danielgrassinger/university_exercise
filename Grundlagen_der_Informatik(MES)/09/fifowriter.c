#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>

#define BUFSIZE 20
#define EXIT_FIFO_ERROR 1

int main(int argc, char* argv[]){

    // Init buffer
    char buf[BUFSIZE];
    unlink("fifo007");
    // Copy command line parameter into buffer
    strcpy(buf,argv[1]);

    // Create FIFO
    if(mkfifo("fifo007",0644)<0){
        printf("Error while creating fifo\n");
        return EXIT_FIFO_ERROR;
    }

    // Open FIFO for writing
    FILE* fifofile;
    if((fifofile=open("fifo007",O_WRONLY))<0){
        printf("Error while opening fifo\n");
        return EXIT_FIFO_ERROR;
    }

    // Write into FIFO
    if(write(fifofile,buf,BUFSIZE)<0){
        printf("Error while writing into pipe!\n");
        return EXIT_FIFO_ERROR;
    }

    // Close FIFO
    close(fifofile);
    return EXIT_SUCCESS;
}
