
#include <stdio.h>

int main(){
int rows, columns = 0;
char text[127];

printf("Bitte geben Sie Anzahl der Zeilen ein: \n");
scanf("%d", &rows);
printf("Geben nun die Anzahl der Spalten ein: \n");
scanf("%d",&columns);

printf("Bitte geben Sie den Text ein, der verschluesselt werden soll: \n");


// nach folgende while-Schleife ist noetig, damit fgets funktioniert
char c;
while (c != '\n' && c != EOF){
  c = getchar();
}

fgets(text,127,stdin);


char gitter[rows][columns];
int i=0;
int x,y=0;


for(y=0;y<rows;y++){
  for(x=0;x<columns;x++){
    gitter[x][y]=text[i];
    i++;
  }
}
i=0;
for(x=0;x<columns;x++){
  for(y=0;y<rows;y++){
    text[i]=gitter[x][y];
    i++;
  }
}

printf("%s",text);

  return 0;
}
