// |Balanço de Parênteses I
/*
* Daniel Monteiro Ribeiro
* RA: 176231
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void remove_novalinha(char input[]) {
  int tam = strlen(input);
  if (input[tam-1] == '\n') input[tam-1] = '\0';
}

int checa_expressao(char s[]) {
  char *p; int t;
  int n = strlen(s);
  p = (char *)malloc(n * sizeof(char));

  t = 0;
  for (int i = 0; s[i] != '\0'; i++) {
    switch(s[i]) {
      case ')': if (t != 0 && p[t-1] == '(') --t;
                else return 0;
                break;
      case '(': p[t++] = s[i];
                break;
    }
  }

  free(p);
  return t == 0;
}

int main() {
  char input_expressao[1001];
  int correto;

  while (fgets(input_expressao, sizeof(input_expressao), stdin) != NULL) {
    if (sizeof(input_expressao) == 0) break;
    remove_novalinha(input_expressao);
    correto = checa_expressao(input_expressao);
    if (correto) printf("correct\n");
    else printf("incorrect\n");
  }
}