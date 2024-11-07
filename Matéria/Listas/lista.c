#include <stdio.h>
#include <stdlib.h>

// Estrutura de um nó (célula) da lista encadeada
struct cel {
  int conteudo;
  struct cel *prox; // Ponteiro para o próximo nó
};

typedef struct cel celula;

// Insere um novo nó com o valor 'x' após o nó apontado por 'p'
void inserir_cel(int x, celula *p) {
  celula *nova = (celula *)malloc(sizeof(celula)); // Aloca memória para o novo nó

  // Verifica se a alocação foi bem-sucedida
  if (nova == NULL) {
    printf("Erro de alocação de memória.\n");
    exit(1);
  }

  nova->conteudo = x;       // Define o conteúdo do novo nó
  nova->prox = p->prox;     // Faz o novo nó apontar para o próximo nó de 'p'
  p->prox = nova;           // Faz 'p' apontar para o novo nó, inserindo-o na lista
}

int main() {
  celula *head = (celula *)malloc(sizeof(celula)); // Cria o nó inicial (cabeça da lista)

  // Verifica se a alocação foi bem-sucedida
  if (head == NULL) {
    printf("Erro de alocação de memória.\n");
    exit(1);
  }

  head->prox = NULL;      // Inicializa a lista como vazia

  inserir_cel(19, head); // Insere um novo nó após 'head' com o valor 19

  printf("Conteudo da celula inserida: %d\n", head->prox->conteudo); // Exibe o valor do novo nó

  // Libera a memória alocada
  free(head->prox);
  free(head);

  return 0;
}
