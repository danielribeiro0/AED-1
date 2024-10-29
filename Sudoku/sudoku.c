#include <stdio.h>

void preencher_sudoku (int M[3][3][3][3]) {
  int i, j, k, l;
  for (i = 0; i < 3; i++) {
    for (k = 0; k < 3; k++) {
      for (j = 0; j < 3; j++) {
        for (l = 0; l < 3; l++) {
          scanf("%d", &M[i][j][k][l]);
        }
      }
    }
  }
}

void print_sudoku(int matriz[3][3][3][3]) {
  int i, j, k, l;
  for(i=0; i<3; i++) {
    for(k=0; k<3; k++) {
      for(j=0; j<3; j++) {
        for(l=0; l<3; l++) {
          printf("[%d] ", matriz[i][j][k][l]);
        }
        if(j<2) printf("| ");
      }
      printf("\n");
    }
    if(i<2) printf("---------------------------------------\n");
  }
}

void alterar_sudoku(int linha, int coluna, int slinha, int scoluna, int matriz[3][3][3][3]) {
  int n;
  printf("Digite o valor para alterar: ");
  scanf("%d", &n);
  matriz[linha][coluna][slinha][scoluna] = n;
}

int main() {
  int matriz[3][3][3][3];

  preencher_sudoku(matriz);
  print_sudoku(matriz);

  int linha, coluna, slinha, scoluna;

  int x;
  printf("Deseja alterar a matriz? 1(sim) -1(não)\n");
  scanf("%d", &x);
  while(x != -1) {
    printf("Passe a coordenada do item que deseja alterar (0, 1, 1, 2):");
    scanf("%d %d %d %d", &linha, &coluna, &slinha, &scoluna);
    alterar_sudoku(linha, coluna, slinha, scoluna, matriz);
    print_sudoku(matriz);
    printf("Deseja continuar alterarando a matriz? 1(sim) -1(não)\n");
    scanf("%d", &x);
  };
}