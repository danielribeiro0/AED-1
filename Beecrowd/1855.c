#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Função para atualizar as coordenadas com base na direção atual
void move(char current_dir, int *px, int *py) {
  switch (current_dir) {
  case '>':  // Move para a direita
    (*px)++;
    break;
  case '<':  // Move para a esquerda
    (*px)--;
    break;
  case 'v':  // Move para baixo
    (*py)++;
    break;
  case '^':  // Move para cima
    (*py)--;
    break;
  default:
    break;
  }
}

int main() {
  int x, y;              // Dimensões do mapa
  int px, py, t;         // Coordenadas do "ponteiro" (px, py) e contador de passos (t)
  bool valid;            // Variável que indica se o destino foi encontrado
  char mapa[100][100];   // Mapa bidimensional
  char current_dir;      // Direção atual do "ponteiro"

  // Leitura das dimensões do mapa
  scanf("%d", &x);
  scanf("%d", &y);

  // Leitura do mapa
  for (int i = 0; i < y; i++) {
    for (int j = 0; j < x; j++) {
      scanf(" %c", &mapa[i][j]);
    }
  }

  // Inicialização das variáveis
  current_dir = mapa[0][0];  // Define a direção inicial a partir da célula (0, 0)
  px = 0;                    // Posição inicial do ponteiro (coluna 0)
  py = 0;                    // Posição inicial do ponteiro (linha 0)
  t = 0;                     // Inicializa o contador de passos
  valid = false;             // Inicializa a condição de término (não encontrou '*')

  // Loop principal: verifica se o ponteiro está dentro do mapa e não excedeu o limite de passos
  while (px >= 0 && px < x && py >= 0 && py < y && t < x * y && !valid) {
    switch (mapa[py][px]) {
      case '>':  // Direção para a direita
        current_dir = mapa[py][px];  // Atualiza a direção atual
        move(current_dir, &px, &py); // Move o ponteiro na direção atual
        t++;                         // Incrementa o contador de passos
        break;
      case '<':  // Direção para a esquerda
        current_dir = mapa[py][px];
        move(current_dir, &px, &py);
        t++;
        break;
      case 'v':  // Direção para baixo
        current_dir = mapa[py][px];
        move(current_dir, &px, &py);
        t++;
        break;
      case '^':  // Direção para cima
        current_dir = mapa[py][px];
        move(current_dir, &px, &py);
        t++;
        break;
      case '.':  // Célula vazia, continua na mesma direção
        move(current_dir, &px, &py); // Move o ponteiro com base na direção atual
        t++;
        break;
      case '*':  // Encontrou o destino
        valid = true;               // Sinaliza que o destino foi encontrado
        break;
      default:
        break;
    }
  }

  // Verifica se encontrou o destino ou se houve falha
  if (valid)
    printf("*\n");  // Imprime '*' se encontrou o destino
  else
    printf("!\n");  // Imprime '!' se não encontrou o destino após x * y passos

  return 0;
}
