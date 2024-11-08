/*
*  |Filas
*  First in, first out
*/

// | Fila com vetor

#include <stdio.h>

void print_fila(int fila[], int s, int t) {
  int i=s;
  while (i<t) {
    printf("%d ", fila[i++]);
  }
  printf("\n");
}

void push(int fila[], int *t, int y) {
  fila[(*t)++] = y;
}

int pop(int fila[], int *s) {
  int x;
  x = fila[(*s)++];
  return x;
}


int main() {
  int fila[10] = {0};
  int s=0, t=0;
}