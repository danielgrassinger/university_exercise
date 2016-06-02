#include<stdio.h>

void hanoi(int n, int a, int b, int c){
  if (n == 1) {
          printf("Scheibe wird von Stab %d "
                 "nach Stab %d gelegt.\n", a, c);
      } else {
          hanoi(n-1,a, c, b);
          hanoi(1,a, b, c);
          hanoi(n-1,b, a, c);
      }
}

int main(){
int n;
printf("Geben Sie die Anzahl der Scheiben ein: \n");
scanf("%d",&n);
  hanoi(n, 1, 2, 3);
  return 0;
}
