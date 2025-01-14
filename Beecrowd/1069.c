// Diamantes e Areia
/*
* Daniel Monteiro Ribeiro
* RA: 176231
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1001

void remove_novalinha(char input[]) {
  int tam = strlen(input);
  if (input[tam-1] == '\n') input[tam-1] = '\0';
}

int extrair(char mina[]) {
  int diamantes = 0;
  int tam = strlen(mina);
  char *p = (char *)malloc(tam * sizeof(char));

  int t = 0;
  for (int i = 0; mina[i] != '\0'; i++) {
    switch (mina[i]) {
      case '<': p[t++] = mina[i];
                break;
      case '>': if (t > 0 && p[t - 1] == '<') {
                  --t;
                  diamantes++;
                }
    }
  }

  return diamantes;
}

int main () {
  int N, diamantes;
  char mina[MAX];
  scanf("%d", &N);
  getchar();

  for (int i = 0; i < N; i++) {
    fgets(mina, sizeof(mina), stdin);
    remove_novalinha(mina);

    diamantes = extrair(mina);

    printf("%d\n", diamantes);
  }
}