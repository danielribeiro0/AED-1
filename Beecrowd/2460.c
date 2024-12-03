// Fila
/*
* Daniel Monteiro Ribeiro
* RA: 176231
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct cel {
  int id;
  struct cel *prox;
} fila;

void checa_alocacao(struct cel *p)  {
  if (p == NULL) {
    exit(EXIT_FAILURE);
  }
}

// Imprime a fila começando do primeiro na fila
void imprime_fila(fila *inicio) {
  if (inicio == NULL || inicio->prox == NULL) return; // Fila vazia
  
  fila *p = inicio->prox;
  while (p != NULL) {
    // Imprime sem espaço se for o último
    if (p->prox == NULL)
      printf("%d", p->id);
    else
      printf("%d ", p->id);
    p = p->prox;
  }
  printf("\n");
}

void insere_fila(int n, fila *p) {
  if (p == NULL) return;
  fila *novo;
  novo = (fila *)malloc(sizeof(fila));
  checa_alocacao(novo);

  novo->id = n;
  novo->prox = p->prox;
  p->prox = novo;
}

void busca_remove_fila(int n, fila *head) {
  if (head == NULL || head->prox == NULL) return; // Fila vazia

  fila *p = head;
  while (p->prox != NULL && p->prox->id != n) {
    p = p->prox;
  }

  if (p->prox == NULL) return; // 'n' não foi encontrado na fila
  else {  // Remove 'n' da fila
    fila *aux = p->prox;
    p->prox = aux->prox;
    free(aux);
  }
}

int main() {
  fila *head;
  head = (fila *)malloc(sizeof(fila));
  checa_alocacao(head);

  fila *inicio = head; // Head é o início da fila
  inicio->prox = NULL; // Inicia a fila como vazia

  int n, N;
  int m, M;

  scanf("%d", &N); // Lê quantidade de pessoas no estado incial da fila

  /* Insere cada pessoa no estado inicial da fila
   * Insere sempre no fim da fila */
  struct cel *fim = inicio;
  int i = 0;
  while (i < N) {
    scanf("%d", &n);
    insere_fila(n, fim);
    fim = fim->prox;
    i++;
  }

  scanf("%d", &M); //Lê quantidade dos que saíram da fila

  // Remove da fila os que saíram
  for(int i = 0; i < M; i++) {
    scanf("%d", &m);
    busca_remove_fila(m, inicio);
  }

  // Imprime estado final da fila
  imprime_fila(inicio);

}