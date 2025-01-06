// Pares e ímpares
/*
* Daniel Monteiro Ribeiro
* RA: 176231
*/

#include <stdio.h>
#define MAX 100000 // Define o tamanho máximo dos vetores

// Função para particionar o vetor em relação a um pivô (utilizada no Quicksort)
int Separa(int p, int r, int v[]) {
  int c, j, k, t;
  c = v[r]; // O pivô é o último elemento do intervalo
  j = p;    // Índice inicial do subvetor

  // Percorre o subvetor e separa os elementos menores ou iguais ao pivô
  for (k = p; k < r; k++) {
    if (v[k] <= c) {
      t = v[j], v[j] = v[k], v[k] = t; // Troca os elementos
      j++;
    }
  }

  // Coloca o pivô na posição correta
  v[r] = v[j], v[j] = c;
  return j; // Retorna a posição do pivô
}

// Implementação do Quicksort
void Quicksort(int p, int r, int v[]) {
  int j;
  if (p < r) {
    j = Separa(p, r, v);         // Particiona o vetor
    Quicksort(p, j - 1, v);      // Ordena o subvetor à esquerda do pivô
    Quicksort(j + 1, r, v);      // Ordena o subvetor à direita do pivô
  }
}

int main() {
  int N;              // Número de elementos a serem lidos
  int n;              // Variável para armazenar o número lido
  int vP[MAX], vI[MAX]; // Vetores para números pares e ímpares
  int a = 0, b = 0;   // Contadores para os vetores pares e ímpares

  scanf("%d", &N); // Lê o número de elementos

  // Lê os números e os separa em pares e ímpares
  for (int i = 0; i < N; i++) {
    scanf("%d", &n);
    if (n % 2 == 0) {
      vP[a++] = n; // Armazena os números pares
    } else {
      vI[b++] = n; // Armazena os números ímpares
    }
  }

  // Ordena os números pares em ordem crescente
  Quicksort(0, a - 1, vP);
  // Ordena os números ímpares em ordem crescente
  Quicksort(0, b - 1, vI);

  // Imprime os números pares em ordem crescente
  for (int i = 0; i < a; i++) {
    printf("%d\n", vP[i]);
  }

  // Imprime os números ímpares em ordem decrescente
  for (int i = b - 1; i >= 0; i--) {
    printf("%d\n", vI[i]);
  }
}