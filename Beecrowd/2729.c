#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 21000 // 1000 * 20 + 1000 (1000 palavras com 20 letras + 999 espacos + 1 '\0')

struct cel {
  char nome[21];
  struct cel *prev;
  struct cel *next;
};

typedef struct cel item;

void checa_alocacao(struct cel *p) {
  if (p == NULL)
    exit(EXIT_FAILURE);
}

// Função para remover o '\n' da entrada caso exista
void remove_novalinha(char input[]) {
  int tam = strlen(input);
  if (input[tam-1] == '\n')
    input[tam-1] = '\0';
}

void print_lista(item *head) {
  if (head == NULL || head->next == NULL) return;
  
  item *aux = head->next;
  while (aux != NULL) {
    printf("%s", aux->nome);
    if(aux->next != NULL) printf(" ");
    aux = aux->next;
  }
}

void insere_item(char input_item[], item *p) {
  item *novo;
  novo = (item*)malloc(sizeof(item));
  checa_alocacao(novo);

  strcpy(novo->nome, input_item);
  novo->prev = p;
  novo->next = p->next;
  p->next = novo;
}

void remove_item(item *p) {
  if(p == NULL) return;
  item *prev = p->prev;
  item *next = p->next;

  prev->next = next;
  next->prev = prev;

  free(p);
}

void insertion_sort(item *head) {
  if(head == NULL || head->next == NULL || head->next->next == NULL) return;
  item *p, *q;
  char temp[21];

  for (q = head->next->next; q != NULL; q = q->next) {
    strcpy(temp, q->nome);
    for (p = q->prev; p->prev != NULL && strcmp(p->nome, temp) > 0; p = p->prev) {
      strcpy(p->next->nome, p->nome);
    }
    strcpy(p->next->nome, temp);
  }
}

int main () {
  int N;
  char input_lista[MAX];
  char *input_item;

  scanf("%d", &N);
  getchar(); // Remove o '\n' deixado pelo scanf

  for (int i = 0; i < N; i++) {
    // Cria uma nova lista
    item *head = (item*)malloc(sizeof(item));
    checa_alocacao(head);
    head->prev = NULL;
    head->next = NULL; // Inicializa a lista vazia

    fgets(input_lista, sizeof(input_lista), stdin);
    remove_novalinha(input_lista);

    input_item = strtok(input_lista, " ");
    item *aux;
    aux = head;

    while (input_item != NULL) {
      insere_item(input_item, aux);
      input_item = strtok(NULL, " ");
      aux = aux->next;
    }

    insertion_sort(head);

    aux = head->next->next;
    while (aux != NULL) {
      if (strcmp(aux->nome, aux->prev->nome) == 0) {
        remove_item(aux->prev);
      }
      aux = aux->next;
    }

    print_lista(head);
    printf("\n");
    
  }
}