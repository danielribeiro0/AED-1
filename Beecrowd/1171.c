// Frequência de Números
/*
* Daniel Monteiro Ribeiro
* RA: 176231
*/

#include <stdio.h>
#define MAX 2001

int main () {
  int N, n;
  int freq[MAX] = {0};

  scanf("%d", &N);

  for (int i = 0; i < N; i++) {
    scanf("%d", &n);
    freq[n]++;
  }

  for (int i = 1; i < MAX; i++) {
    if (freq[i] > 0) printf("%d aparece %d vez(es)\n", i, freq[i]);
  }

}