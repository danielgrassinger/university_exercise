#include <stdio.h>

int main(void){
    int a, b;

    printf("Bitte geben Sie zwei ganze Zahlen ein! \nGeben Sie die kleinere Zahl zuerst ein! \n");
    scanf("%d %d", &a, &b);
	
	if(b<0) {
		printf("Die groesse Zahl ist negativ ... Abbruch !\n");
		return 20;	
	}
	
	if(a>b){
		printf("Erste Zahl ist nicht kleiner als die zweite Zahl ... Abbruch !\n");
		return 10;
	}
	
    printf("Sie haben eingegeben: %d und %d \n", a, b);


    return 0;
}
