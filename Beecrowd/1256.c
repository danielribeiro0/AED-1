// Tabelas Hash
/*
* Daniel Monteiro Ribeiro
* RA: 176231
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int value;
	struct node* next;
} key;

void freeHashtable(key **h, int size) {
  for (int i = 0; i < size; i++) {
    key *aux = h[i];
    while (aux) {
      key *temp = aux;
      aux = aux->next;
      free(temp);
    }
  }
  free(h);
}

void insertKey(key **h, int address, int value) {
	key *k = malloc(sizeof(key));
	k->value = value;
  k->next = NULL;

	if (h[address] == NULL) {
		h[address] = k;
	}
	else {
    key *aux = h[address];
    while (aux->next != NULL) {
        aux = aux->next;
    }
    aux->next = k;  // Insere no final para preservar a ordem
	}
}

void printHashtable(key **h, int size) {
	key *aux;
	for (int i = 0; i < size; i++) {
		printf("%d -> ", i);
		aux = h[i];
		while (aux != NULL) {
			printf("%d -> ", aux->value);
			aux = aux->next;
		}
		printf("\\");
		printf("\n");
	}
}

int main() {
	key **hashtable;
	int N, M, C, value, address;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d %d", &M, &C);

    if (i) printf("\n");

		hashtable = malloc(M * sizeof(*hashtable)); // Inicializa a hashtable (separa memória para o vetor)

		for (int j = 0; j < M; j++) {
			hashtable[j] = NULL;
		}

		for (int j = 0; j < C; j++) {
			scanf("%d", &value);
			address = value % M;
			insertKey(hashtable, address, value);
		}

		printHashtable(hashtable, M);
		freeHashtable(hashtable, M);
	}
}