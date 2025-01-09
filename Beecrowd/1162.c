// Organizador de Vagões
/*
* Daniel Monteiro Ribeiro
* RA: 176231
*/

#include <stdio.h>

// Troca os valores de lugar
void troca(int *xp,  int *yp) {
  int temp = *yp;
  *yp = *xp;      // Segundo valor recebeo primeiro
  *xp = temp;     // Primeiro valor recebe o segundo
}

int BubbleSort(int n, int v[]) {
  int i, j, trocado;
  int trocas = 0; // Guarda o número de trocas efetuadas

  for (i = 0; i  < n-1; i++) {
    trocado = 0;
    for (j = 0; j < n-1 - i; j++) {
      if (v[j] > v[j + 1]) {
        troca(&v[j], &v[j+1]);
        trocado = 1;
        trocas++;
      }
    }

    // Se nenhuma troca for feita,
    // significa que o vetor está ordenado
    if (trocado == 0) 
      break;
  }

  return trocas; // Retorna o número de trocas
}

int main() {
  int L, N, x, v[50], trocas;
  scanf("%d", &N);

  for (int i = 0; i < N; i++) {
    // Preenche o vetor de vagões
    scanf("%d", &L);
    for (int j = 0; j < L; j++) {
      scanf("%d", &x);
      v[j] = x;
    }
    // Ordena o vetor de vagôes e guarda o númeor de trocas
    trocas = BubbleSort(L, v);

    // Imprime a saída do exercício
    printf("Optimal train swapping takes %d swaps.\n", trocas);
  }
}