/*
* Nome: Daniel Monteiro Ribeiro 
* RA: 176231
*/


#include <stdio.h>

void preencher_sudoku (int M[3][3][3][3]) {
  for (int i = 0; i < 3; i++) {
    for (int k = 0; k < 3; k++) {
      for (int j = 0; j < 3; j++) {
        for (int l = 0; l < 3; l++) {
          scanf("%d", &M[i][j][k][l]);
        }
      }
    }
  }
}

// Checa se coluna, linha ou matriz 3x3 contêm os números de 1-9
int checar_numeros (int vetor[]) {
  // Usa um vetor como auxílio para marcar números como encontrados
  int numeros[10] = {0}, num;
  for (int i=0; i<9; i++) {
    num = vetor[i];
    // Se o númeor estiver fora do intervalo ou se for repetido, retorne 0
    if (num<1 || num>9 || numeros[num]) return 0;
    // Se não, marque como encontrado
    else numeros[num] = 1;
  }
  return 1; // Todos os números de 1-9 foram encontrados
}

int checar_sudoku(int sudoku[3][3][3][3]) {
  int linha[9], coluna[9], matriz3x3[9];
  int i, j, k, l, index;

  // Checa para as linhas
  for(i=0; i<3; i++) { 
    for(k=0; k<3; k++) { 
      index=0; 
      for(j=0; j<3; j++) { 
        for(l=0; l<3; l++) { 
          linha[index++] = sudoku[i][j][k][l];
        }
      }
      if (!checar_numeros(linha)) return 0; // Sudoku incorreto
    }
  }

  // Checa para as colunas
  for(j=0; j<3; j++) { 
    for(l=0; l<3; l++) { 
      index=0; 
      for(i=0; i<3; i++) { 
        for(k=0; k<3; k++) { 
          coluna[index++] = sudoku[i][j][k][l];
        }
      }
      if (!checar_numeros(coluna)) return 0; // Sudoku incorreto
    }
  }

  // Checa para cada matriz 3x3
  for(i=0; i<3; i++) { 
    for(j=0; j<3; j++) { 
      index=0; 
      for(k=0; k<3; k++) { 
        for(l=0; l<3; l++) { 
          matriz3x3[index++] = sudoku[i][j][k][l];
        }
      }
      if (!checar_numeros(matriz3x3)) return 0; // Sudoku incorreto
    }
  }

  return 1; // O jogo de sudoku está corretamente preenchido
}

int main(){
  int sudoku9x9[3][3][3][3], instancias;

  scanf("%d", &instancias);
  for(int i=1; i<=instancias; i++) {
    preencher_sudoku(sudoku9x9);
    printf("Instancia %d\n", i);
    if (checar_sudoku(sudoku9x9)) printf("SIM\n");
    else printf("NAO\n");
    printf("\n");
  }
}
