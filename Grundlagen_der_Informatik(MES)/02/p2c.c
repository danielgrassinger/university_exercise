#include<stdio.h>

int main(){
	char text[128];
	scanf("%s", text);
	int c = 0;
 
   while (text[c] != '\0') {
      if (text[c] >= 'A' && text[c] <= 'Z') {
         text[c] = text[c] + ('a'-'A');
      }else if(text[c]=='Ä')text[c]='ä';
      c++;
   }
   printf("%s\n",text);

   return 0;
}
