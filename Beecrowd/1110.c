// Jogando Cartas Fora
/*
* Daniel Monteiro Ribeiro
* RA: 176231
*/

#include <stdio.h>

#define MAX 50

void push(int n, int pilha[], int *t) {
  pilha[*t] = n;
  (*t)++;
}

int pop(int pilha[], int *t) {
  int x = pilha[(*t) - 1];
  (*t)--;
  return x;
}

void move_topo_para_base(int pilha[], int t) {
  int temp = pilha[t - 1]; // Salva o topo da pilha
  for (int i = t - 1; i > 0; i--) { // Move elementos "para cima"
      pilha[i] = pilha[i - 1];
  }
  pilha[0] = temp; // Coloca o topo na base
}



int main() {
  int cartas_descartadas[MAX]; // Vetor para as cartas descartadas
  int s; // Auxilia no preenchimento do vetor das descartadas
  int x; // Guarda a carta removida
  int pilha_cartas[MAX]; // Vetor para a pilha de cartas
  int t; // Guarda o topo da pilha
  int n; // Número de cartas da pilha

  int ultima_carta;

  // Laço de repetição para cada pilha de cartas
  while (scanf("%d", &n) > 0 && n > 0) {
    t = 0; // Pilha vazia
    s = 0; // Vetor de descartadas vazio
    
    // Preenche a pilha de cartas
    for (int i = n; i > 0; i--) {
      push(i, pilha_cartas, &t);
    }

    // Remove a carta do topo e passa a próxima para a base
    while (t > 2) {
      x = pop(pilha_cartas, &t);
      cartas_descartadas[s++] = x;
      move_topo_para_base(pilha_cartas, t);
    }

    // Remove a penúltima carta
    if (t > 1) {
      x = pop(pilha_cartas, &t);
      cartas_descartadas[s++] = x;
    }

    // Guarda a última carta
    ultima_carta = pilha_cartas[t-1];

    // Imprime o resultado
    if (s == 0) {
      printf("Discarded cards: \n");
    } else {
      printf("Discarded cards: ");
    }
    for (int i = 0; i < s; i++) {
      if (i == s-1) 
        printf("%d\n", cartas_descartadas[i]);
      else
        printf("%d, ", cartas_descartadas[i]);
    }
    printf("Remaining card: %d\n", ultima_carta);
  }
  
}