#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(int argc, char *argv[]){
    // Init random generator
    time_t t;
    srand((unsigned) time(&t));

    int height=atoi(argv[1]);

    int count = 0;
    int i;
    for(i=height-1;i>=0;i--){
        int o;
        for(o = 0;o<i;o++){
            printf(" ");
        }
        int s;
        for(s=0;s<(height-i)*2-1;s++){
            if(rand()%11){
                printf("*");
            }else{
                printf("O");
            }

        }
        for(o = 0;o<i;o++){
            printf(" ");
        }
        printf("\n");
    }
    int o;
    for(o = 0;o<height-2;o++){
        printf(" ");
    }
    printf("III\n");
}
