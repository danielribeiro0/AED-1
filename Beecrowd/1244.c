// Ordenação por Tamanho
/*
* Daniel Monteiro Ribeiro
* RA: 176231
*/

/*
 * void troca(char *sp, char *tp) {
 *   char temp[max];
 *   strcpy(temp, tp);
 *   strcpy(tp, sp);
 *   strcpy(sp, temp);
 * }
 * 
 * void BubbleSort(char strs[][max], int n) {
 *   int i, j, trocado;
 *   for (i = 0; i < n - 1; i++) {
 *     trocado = 0;
 *     for (j = 0; j < n - 1 - i; j++) {
 *       if (strlen(strs[j]) < strlen(strs[j + 1])) {
 *         troca(strs[j], strs[j + 1]);
 *         trocado = 1;
 *       }
 *     }
 * 
 *     if (trocado == 0) 
 *       break;
 *   }
 * }
 * 
 *
 * void InsertionSort(char strs[][max], int n) {
 *  int i, j;
 *  char x[max];
 *  for (j = 1; j < n; j++) {
 *    strcpy(x, strs[j]);
 *    for (i = j-1; i >= 0 && strlen(strs[i]) < strlen(x); i--) {
 *      strcpy(strs[i + 1], strs[i]);
 *    }
 *    strcpy(strs[i + 1], x);
 *  }
 * }
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define max 51
#define MAX 2550 // 50 * 50 + 50 (50 palavras com 50 letras + 49 espaços e um \0)

// Função para remover o '\n' da entrada caso exista
void remove_novalinha(char input[]) {
    int tam = strlen(input);
    if (tam > 0 && input[tam - 1] == '\n')
        input[tam - 1] = '\0';
}

// Função para intercalar dois subarrays ordenados
void Intercala(int p, int q, int r, char v[][max]) {
    int i = p, j = q, k = 0;
    char (*w)[max] = malloc((r - p) * sizeof(char[max]));

    while (i < q && j < r) {
        if (strlen(v[i]) >= strlen(v[j])) // Ordena por comprimento, decrescente
            strcpy(w[k++], v[i++]);
        else
            strcpy(w[k++], v[j++]);
    }

    while (i < q)
        strcpy(w[k++], v[i++]);
    while (j < r)
        strcpy(w[k++], v[j++]);

    for (i = p, k = 0; i < r; i++, k++)
        strcpy(v[i], w[k]);

    free(w);
}

// Função recursiva do MergeSort
void Mergesort(int p, int r, char v[][max]) {
    if (p < r - 1) {
        int q = (p + r) / 2;
        Mergesort(p, q, v);
        Mergesort(q, r, v);
        Intercala(p, q, r, v);
    }
}

int main() {
    int N, i;
    char *str, strings[50][max], input_strings[MAX];

    scanf("%d", &N);
    getchar();

    for (int k = 0; k < N; k++) {
        fgets(input_strings, sizeof(input_strings), stdin);
        remove_novalinha(input_strings);

        str = strtok(input_strings, " ");
        i = 0;
        while (str != NULL) {
            strcpy(strings[i++], str);
            str = strtok(NULL, " ");
        }

        // Ordena as strings por comprimento usando MergeSort
        Mergesort(0, i, strings);

        for (int j = 0; j < i; j++) {
          printf("%s", strings[j]);
          if (j < i - 1) {
              printf(" "); // Adiciona espaço apenas entre palavras
          }
        }
        printf("\n");
    }

    return 0;
}
