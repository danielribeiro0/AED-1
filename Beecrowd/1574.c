// Instruções do Robô
/*
* Daniel Monteiro Ribeiro
* RA: 176231
*/

#include <stdio.h>
#include <string.h>

int main () {
  int T; // Qnt testes
  int n; // Qnt instruções
  int log_passos[100]; // Guarda as instruções
  char passo[13]; // 11 caracteres + \n + \0
  int index_passo; // Index do passo em log_passos
  int p = 0; // Posição do robô
  
  scanf("%d", &T); // Lê quantidade de testes
  for (int i = 0; i < T; i++) {
    scanf("%d", &n); // Lê quantidade de instruções
    getchar(); // Limpa o buffer

    for (int j = 0; j < n; j++) {
      fgets(passo, sizeof(passo), stdin); // Lê a instrução
      passo[strcspn(passo, "\n")] = '\0'; // Remove o '\n'

      if (strcmp(passo, "LEFT") == 0)
        log_passos[j] = -1;
      else if (strcmp(passo, "RIGHT") == 0)
        log_passos[j] = 1;
      else {
        sscanf(passo, "SAME AS %d", &index_passo);
        log_passos[j] = log_passos[index_passo - 1];
      }

      p = p + log_passos[j];
    }
    
    printf("%d\n", p);
    p = 0;
  }

}