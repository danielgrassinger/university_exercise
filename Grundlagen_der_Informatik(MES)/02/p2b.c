#include<stdio.h>

int main(){
	char text[128];
	scanf("%s", text);
	
	int len = 0;
	for(;text[len]!='\0';len++);
	printf("%d\n",len);
	
	int i = len-1;
	char retext[i];
	for(;i>=0;i--){
		retext[len-1-i]=text[i];
	}
	printf("%s\n", retext);
}