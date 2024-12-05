#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 400000  // Tamanho do vetor a ser ordenado

// Gera um número inteiro aleatório no intervalo [min, max]
int RandomInt(int min, int max) {
  return min + rand() % (max - min + 1);
}

// Implementa o algoritmo Insertion Sort para ordenar o vetor
void insertionSort(int n, int v[]) {
  int i, j, x;
  for (j = 1; j < n; j++) {  // Itera sobre os elementos do vetor
    x = v[j];
    for (i = j - 1; i >= 0 && v[i] > x; i--) {
      v[i+1] = v[i];  // Move os elementos maiores que x para frente
    }
    v[i+1] = x;  // Insere o elemento na posição correta
  }
}

int main() {
  clock_t t;  // Para medir o tempo de execução
  int vetor[TAM];

  srand((unsigned)time(NULL));  // Inicializa o gerador de números aleatórios

  // Preenche o vetor com valores aleatórios no intervalo [0, 100]
  for (int i = 0; i < TAM; i++) {
    vetor[i] = RandomInt(0, 100);
  }
  
  t = clock();  // Marca o início da execução
  insertionSort(TAM, vetor);  // Ordena o vetor usando Insertion Sort
  t = clock() - t;  // Calcula o tempo de execução

  // Exibe o tempo de execução em milissegundos
  printf("Tempo de execucao: %lf ms\n", (double)t * 1000 / CLOCKS_PER_SEC);

  return 0;
}