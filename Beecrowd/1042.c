// Sort Simples
/*
* Daniel Monteiro Ribeiro
* RA: 176231
*/

#include <stdio.h>
#define max 3

void InsertionSort(int n, int v[]) {
  int i, j, x;
  for (j = 1; j < n; j++) {
    x = v[j];
    for (i = j-1; i >= 0 && v[i] > x; i--) {
      v[i+1] = v[i];
    }
    v[i+1] = x;
  }
}

int main () {
  int n;
  int v1[max], v2[max];
  for (int i = 0; i < max; i++) {
    scanf("%d", &n);
    v1[i] = n;
    v2[i] = n;
  }

  InsertionSort(max, v1);

  for(int i = 0; i < max; i++) printf("%d\n", v1[i]);
  printf("\n");
  for(int i = 0; i < max; i++) printf("%d\n", v2[i]);
}