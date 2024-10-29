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

int main() {
  int matriz[3][3][3][3];

  preencher_sudoku(matriz);
  print_sudoku(matriz);
}