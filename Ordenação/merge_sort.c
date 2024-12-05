#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 400000  // Tamanho do vetor a ser ordenado

// Gera um número inteiro aleatório no intervalo [min, max]
int RandomInt(int min, int max) {
  return min + rand() % (max - min + 1);
}

// Intercala dois subarrays ordenados [p, q) e [q, r) em um único subarray ordenado
void Intercala(int p, int q, int r, int v[]) {
  int i = p, j = q, k = 0;
  int *w = malloc((r - p) * sizeof(int));  // Array temporário para armazenar o merge

  // Intercala os subarrays
  while (i < q && j < r) 
    w[k++] = (v[i] <= v[j]) ? v[i++] : v[j++];
  
  // Copia elementos restantes (se houver)
  while (i < q) w[k++] = v[i++];
  while (j < r) w[k++] = v[j++];

  // Transfere os valores de volta ao vetor original
  for (i = p; i < r; i++) 
    v[i] = w[i - p];

  free(w);  // Libera memória temporária
}

// Implementa o algoritmo Merge Sort para ordenar o vetor v no intervalo [p, r)
void Mergesort(int p, int r, int v[]) {
  if (p < r - 1) {  // Verifica se o subarray tem mais de um elemento
    int q = (p + r) / 2;
    Mergesort(p, q, v);  // Ordena a primeira metade
    Mergesort(q, r, v);  // Ordena a segunda metade
    Intercala(p, q, r, v);  // Intercala as duas metades
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
  Mergesort(0, TAM, vetor);  // Ordena o vetor usando Merge Sort
  t = clock() - t;  // Calcula o tempo de execução

  // Exibe o tempo de execução em segundos
  printf("Tempo de execucao: %lf segundos\n", (double)t / CLOCKS_PER_SEC);

  return 0;
}