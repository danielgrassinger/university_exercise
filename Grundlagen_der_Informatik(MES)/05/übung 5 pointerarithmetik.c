#include <stdio.h>

void swap(int*, int*);

int main(void ){
	int a = 5, b = 3;
	swap(&a, &b);
	printf("a: %d, b: %d\n",a,b);
	
	return 0;
}
void swap(int* a, int* b){
	int c = *a;
	*a = *b;
	*b = *c;	
}