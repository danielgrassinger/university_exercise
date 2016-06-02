#include <stdio.h>
int sumitup(int,int);

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
	
	int summe = sumitup(a,b);
	
	printf("Die Summe von %d und %d ist: %d\n", a, b, summe);

    return 0;
}

int sumitup(int a, int b){
	if(b<=a){
		return b;
	}else{
		return b + sumitup(a,b-1);	
	}
}