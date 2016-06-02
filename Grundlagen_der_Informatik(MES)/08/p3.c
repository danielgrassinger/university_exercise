#include<stdio.h>

int main(int argc, char *argv[]){
    int y;
    for( y= 0;y<10;y++){

        int x;
        for(x = 0;x<10;x++){

            if(x==y){
                printf("0");
            }else{
                printf("*");
            }

        }
        
        printf("\n");

    }
}
