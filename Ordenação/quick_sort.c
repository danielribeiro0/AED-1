#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 400000  // Tamanho do vetor a ser ordenado

// Gera um número inteiro aleatório no intervalo [min, max]
int RandomInt(int min, int max) {
  return min + rand() % (max - min + 1);
}

// Implementa o algoritmo Quick Sort para ordenar o vetor
int Separa (int p, int r, int v[]) {
  int c, j, k, t;
  c = v[r]; j = p;
  for (k = p; /*A*/ k < r; k++) {
    if (v[k] <= c) {
      t = v[j], v[j] = v[k], v[k] = t;
      j++;
    }
  }
  v[r] = v[j], v[j] = c;
  return j;
}

void Quicksort (int p, int r, int v[]) {
  int j;
  if (p < r) {
    j = Separa (p, r, v);
    Quicksort (p, j - 1, v);
    Quicksort (j + 1, r, v);
  }
}


int main() {
  clock_t T, t1, t2;  // Para medir o tempo de execução
  int vetor[TAM], p = 0, r = TAM;
  double soma = 0.0;

  srand((unsigned)time(NULL));  // Inicializa o gerador de números aleatórios

  printf("n = %d\n", TAM);

  // Preenche o vetor com valores aleatórios no intervalo [0, 100]
  for (int j = 0; j < 3; j++) {
    for (int i = 0; i < TAM; i++) {
      vetor[i] = RandomInt(0, 100);
    }
    
    t1 = clock();  // Marca o início da execução
    Quicksort(0, r, vetor);
    t2 = clock();  // Calcula o tempo de execução
    T = t2 - t1;

    soma = soma + ((double)T / CLOCKS_PER_SEC);

    // Exibe o tempo de execução em milissegundos
    printf("Tempo de execucao: %lf segundos\n", (double)T / CLOCKS_PER_SEC);
    }
  printf("Media: %lf segundos\n", soma/3);

  return 0;
}