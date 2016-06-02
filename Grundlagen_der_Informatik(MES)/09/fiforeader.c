#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>

#define BUFSIZE 20
#define EXIT_FIFO_ERROR 1

int main(int argc, char* argv[]){

    char buf[BUFSIZE];

    // Open FIFO for reading
    FILE* fifofile;
    if((fifofile=open("fifo007",O_RDONLY))<0){
        printf("Error while opening fifo\n");
        return EXIT_FIFO_ERROR;
    }

    // Read form FIFO
    if(read(fifofile,buf,BUFSIZE)<0){
        printf("Error while reading from pipe!\n");
        return EXIT_FIFO_ERROR;
    }

    // Print buffer
    printf("%s\n",buf);

    // Close FIFO
    close(fifofile);
    return EXIT_SUCCESS;
}
