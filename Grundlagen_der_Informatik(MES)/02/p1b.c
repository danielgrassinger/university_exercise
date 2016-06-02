#include<stdio.h>
int summe(int);

int main(){
	printf("%d", summe(5));

}

int summe(int i){
	if(i>0){
		return i + summe(i-1);
	}else return 0;

}