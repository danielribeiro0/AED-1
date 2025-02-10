// Árvore Binária de Busca
/*
* Daniel Monteiro Ribeiro
* RA: 176231
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
  int chave;
  // int conteudo;
  struct node *esq, *dir;
} no;

no* newNode(int k) {
  no *novo = malloc(sizeof(no));
  novo->chave = k;
  // novo->chave = c - 'a';
  novo->esq = novo->dir = NULL;

  return novo;
}

void liberaArvore(no *r) {
  if (r == NULL) return;
  liberaArvore(r->esq);
  liberaArvore(r->dir);
  free(r);
}

no* insereEmArv(no *r, no* novo) {
  if (r == NULL) return novo;
  if (r->chave > novo->chave)
    r->esq = insereEmArv(r->esq, novo);
  else
    r->dir = insereEmArv(r->dir, novo);
  return r;
}

void printPre(no *r, int *first) {
  if (r == NULL) return;
  else {
    if (!(*first)) printf(" ");
    printf("%d", r->chave);
    *first = 0;
    printPre(r->esq, first);
    printPre(r->dir, first);
  }
}

void printIn(no *r, int *first) {
  if (r == NULL) return;
  else {
    printIn(r->esq, first);
    if (!(*first)) printf(" ");
    printf("%d", r->chave);
    *first = 0;
    printIn(r->dir, first);
  }
}

void printPos(no *r, int *first) {
  if(r == NULL) return;
  else {
    printPos(r->esq, first);
    printPos(r->dir, first);
    if (!(*first)) printf(" ");
    printf("%d", r->chave);
    *first = 0;
  }
}

int main () {
  int i, c, n, C, N, first;
  no *raiz, *novo;
  scanf("%d", &C);

  for (c = 1; c <= C; c++) {
    raiz = NULL;
    scanf("%d", &N);
    for (i = 0; i < N; i++) {
      scanf("%d", &n);
      if (n >= 0) {
        novo = newNode(n);
        raiz = insereEmArv(raiz, novo);
      }
    }

    printf("Case %d:\n", c);

    first = 1;
    printf("Pre.: ");
    printPre(raiz, &first);
    printf("\n");
    
    first = 1;
    printf("In..: ");
    printIn(raiz, &first);
    printf("\n");
    
    first = 1;
    printf("Post: ");
    printPos(raiz, &first);
    printf("\n");
    printf("\n");

    liberaArvore(raiz);
  }
}