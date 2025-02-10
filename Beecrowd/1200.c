// Operações em ABP I
/*
* Daniel Monteiro Ribeiro
* RA: 176231
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
  int chave;
  char conteudo;
  struct node *esq, *dir;
} no;

no* newNode(char c) {
  no *novo = malloc(sizeof(no));
  novo->conteudo = c;
  novo->chave = c - 'a';
  novo->esq = novo->dir = NULL;

  return novo;
}

no* insereEmArv(no *r, no* novo) {
  if (r == NULL) return novo;
  if (r->chave > novo->chave)
    r->esq = insereEmArv(r->esq, novo);
  else
    r->dir = insereEmArv(r->dir, novo);
  return r;
}

no* buscaEmArv(no *r, int k) {
  if (r == NULL || r->chave == k) return r;
  if (r->chave > k) 
    buscaEmArv(r->esq, k);
  else 
    buscaEmArv(r->dir, k);
}

void printPre(no *r, int *first) {
  if (r == NULL) return;
  else {
    if (!first) printf(" ");
    printf("%c", r->conteudo);
    printPre(r->esq, 0);
    printPre(r->dir, 0);
  }
}

void printIn(no *r, int *first) {
  if (r == NULL) return;
  else {
    printIn(r->esq, first);
    if (!(*first)) printf(" ");
    *first = 0;
    printf("%c", r->conteudo);
    printIn(r->dir, first);
  }
}

void printPos(no *r, int *first) {
  if(r == NULL) return;
  else {
    printPos(r->esq, first);
    printPos(r->dir, first);
    if (!(*first)) printf(" ");
    printf("%c", r->conteudo);
    *first = 0;
  }
}

int main () {
  int k, *first;
  first = malloc(sizeof (int));
  char input[10], conteudo;
  no *raiz, *novo;

  raiz = NULL; // Inicializa a árvore vazia

  while (scanf("%s", &input) != EOF) {
    *first = 1;

    // Caso "I"
    if (strcmp(input, "I") == 0) 
    {
      getchar();
      scanf("%c", &conteudo);

      novo = newNode(conteudo);
      raiz = insereEmArv(raiz, novo);
    }
    
    // Caso "P"
    else if (strcmp(input, "P") == 0) 
    {
      getchar();
      scanf("%c", &conteudo);
      k = conteudo - 'a';
      if (buscaEmArv(raiz, k) == NULL)
        printf("%c nao existe", conteudo);
      else
        printf("%c existe", conteudo);
      printf("\n");
    }
    
    // Caso "PREFIXA"
    else if (strcmp(input, "PREFIXA") == 0) 
    {
      printPre(raiz, first);
      printf("\n");
    }

    // Caso "INFIXA"
    else if (strcmp(input, "INFIXA") == 0) 
    {
      printIn(raiz, first);
      printf("\n");
    }
    
    // Caso "POSFIXA"
    else if (strcmp(input, "POSFIXA") == 0) 
    {
      printPos(raiz, first);
      printf("\n");
    }
  }
}
