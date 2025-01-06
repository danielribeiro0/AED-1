// Onde Está o Mármore?
/*
* Daniel Monteiro Ribeiro
* RA: 176231
*/

#include <stdio.h>
#include <stdlib.h>

// Função de comparação para qsort
int cmp(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

// Busca binária para encontrar a posição do mármore
int busca_binaria(int arr[], int n, int x) {
    int esquerda = 0, direita = n - 1, meio;

    while (esquerda <= direita) {
        meio = (esquerda + direita) / 2;
        if (arr[meio] == x) {
            // Encontrar a primeira ocorrência do mármore
            while (meio > 0 && arr[meio - 1] == x) {
                meio--;
            }
            return meio + 1; // Retorna a posição 1-based
        } else if (arr[meio] < x) {
            esquerda = meio + 1;
        } else {
            direita = meio - 1;
        }
    }
    return 0; // Não encontrado
}

int main() {
    int N, Q, i, t = 1;

    while (scanf("%d %d", &N, &Q) == 2 && N > 0 && Q > 0) {
        printf("CASE# %d:\n", t++);

        int *marmores = (int *)malloc(N * sizeof(int));
        for (i = 0; i < N; i++) {
            scanf("%d", &marmores[i]);
        }

        // Ordena os mármores
        qsort(marmores, N, sizeof(int), cmp);

        for (i = 0; i < Q; i++) {
            int consulta, posicao;
            scanf("%d", &consulta);

            // Busca binária para encontrar o mármore
            posicao = busca_binaria(marmores, N, consulta);
            if (posicao > 0) {
                printf("%d found at %d\n", consulta, posicao);
            } else {
                printf("%d not found\n", consulta);
            }
        }

        free(marmores);
    }

    return 0;
}