#include<stdio.h>

int main(){
	char text[128];
	scanf("%s", text);
	int a,e,i,o,u = 0;
	
	int x = 0;
	for(;x<128;x++){
		switch(text[x]){
			case 'a':{
				a++;
				break;
			}
			case 'e':{
				e++;
				break;
			}
			case 'i':{
				i++;
				break;
			}
			case 'o':{
				o++;
				break;
			}
			case 'u':{
				u++;
				break;
			}
				
		}
		
	}
	
	printf("a: %d, e: %d, i: %d, o: %d, u: %d\n",a,e,i,o,u);
}