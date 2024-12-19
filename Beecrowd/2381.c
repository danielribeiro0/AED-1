// Lista de chamada
/*
* Daniel Monteiro Ribeiro
* RA: 176231
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max 21 //Garante 20 caracteres e o '\0'

typedef struct cel {
  char nome[max];
  struct cel *next;
  struct cel *prev;
} celula;

typedef celula aluno;

void checa_alocacao(struct cel *p)  {
  if (p == NULL) {
    exit(EXIT_FAILURE);
  }
}

void insere_aluno(char nome[], aluno *p) {
  if(p == NULL) return;
  aluno *novo;
  novo = (aluno*)malloc(sizeof(aluno));
  checa_alocacao(novo);

  strcpy(novo->nome, nome);
  novo->next = p->next;
  novo->prev = p;
  p->next = novo;
}

void ordena_por_insercao(aluno *head) {
  if(head == NULL || head->next == NULL || head->next->next == NULL) return;
  celula *p, *q;
  char temp[21];

  for (q = head->next->next; q != NULL; q = q->next) {
    strcpy(temp, q->nome);
    for (p = q->prev; p->prev != NULL && strcmp(p->nome, temp) > 0; p = p->prev) {
      strcpy(p->next->nome, p->nome);
    }
    strcpy(p->next->nome, temp);
  }
}

int main()  {
  aluno *head;
  head = (aluno*)malloc(sizeof(aluno));
  checa_alocacao(head); // Verifica se a alocação foi bem sucedida
  head->prev = NULL;
  head->next = NULL;  // Inicializa a lista


  int N, K; // número de alunos, número do aluno sorteado (respectivamente)
  char input_nome[max];

  scanf("%d", &N);
  scanf("%d", &K);
  getchar(); // Remove o '\n' deixado pelo scanf

  // Insere na lista cada aluno
  aluno *aux = head;
  int i = 0;
  while (i < N) {
    scanf("%20s", input_nome);
    insere_aluno(input_nome, aux);
    aux = aux->next;
    i++;
  }

  ordena_por_insercao(head);

  // Retorna o aluno sorteado
  aux = head;
  i = 0;
  while (i < K) {
    aux = aux->next;
    i++;
  }

  printf("%s\n", aux->nome); // Imprime o aluno sorteado
}