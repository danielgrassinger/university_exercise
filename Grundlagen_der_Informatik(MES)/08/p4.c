#include<stdio.h>
#include<stdlib.h>

int isPalindrome(char*,int);
char* getConcatString_dynamic(char*,char*);
char* getConcatString_static(char*,char*);


int main(int argc, char *argv[]){

    printf("Ist Palindrom: %d\n", isPalindrome(argv[1],4));

    char st1[]="Hallo ";
    char st2[]="Welt";
    printf("%s \n",getConcatString_dynamic(st1,st2));
    printf("%s \n",getConcatString_static(st1,st2));
}

int isPalindrome(char* word,int lenght){

    int iterator;
    for(iterator=0;iterator<lenght;iterator++){
        if(word[iterator]>='A'&& word[iterator]<='Z'){
                word[iterator] += 32;
        }

    }
    for(iterator=0;iterator<=lenght/2;iterator++){
        if(word[iterator]!=word[lenght-1-iterator]){
            return 0;
        }
    }

    return 1;
}

char* getConcatString_static(char* string1,char* string2){
    int strleng1=0;
    while(string1[strleng1]!='\0'){
        strleng1++;
    }
    int strleng2=0;
    while(string2[strleng2]!='\0'){
        strleng2++;
    }

    //lenght of string1 and string2 plus null terminator
    int strleng = strleng1 +  strleng2 +1;

    char concatString[strleng];

    int iterator;
    for(iterator=0;iterator<strleng1;iterator++){
        concatString[iterator]=string1[iterator];
    }
    for(;iterator<=strleng1+strleng2;iterator++){
        concatString[iterator]=string2[iterator-strleng1];
    }

    return concatString;
}

char* getConcatString_dynamic(char* string1,char* string2){
    int strleng1=0;
    while(string1[strleng1]!='\0'){
        strleng1++;
    }
    int strleng2=0;
    while(string2[strleng2]!='\0'){
        strleng2++;
    }

    //lenght of string1 and string2 plus null terminator
    int strleng = strleng1 +  strleng2 +1;

    char* concatString= (char*)malloc(strleng*sizeof(char));

    int iterator;
    for(iterator=0;iterator<strleng1;iterator++){
        concatString[iterator]=string1[iterator];
    }
    for(;iterator<=strleng1+strleng2;iterator++){
        concatString[iterator]=string2[iterator-strleng1];
    }

    return concatString;
}
