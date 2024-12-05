#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 400000

int RandomInt(int min, int max) {
  return min + rand() % (max - min + 1);
}

void insertionSort(int n, int v[]) {
  int i, j, x;
  for (j = 1; j < n; j++) {
    x = v[j];
    for (i = j - 1; i >= 0 && v[i] > x; i--) {
      v[i+1] = v[i];
    }
    v[i+1] = x;
  }
}

int main () {
  clock_t t;
  int vetor[TAM];

  srand((unsigned)time(NULL));

  for (int i = 0; i<TAM; i++) {
    vetor[i] = RandomInt(0, 100);
  }
  
  t = clock();
  insertionSort(TAM, vetor);
  t = clock() - t;

  printf("Tempo de execucao: %lf", (double)t*1000 / (CLOCKS_PER_SEC) );
}