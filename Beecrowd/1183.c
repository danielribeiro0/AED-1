#include <stdio.h>

int main() {
  char operacao;
  int contador;
  double soma, matriz[12][12];

  scanf("%c\n", &operacao);
  soma = 0.0;
  contador = 0;
  for (int i = 0; i < 12; ++i) {
    for (int j = 0; j < 12; ++j) {
      scanf("%lf", &matriz[i][j]);

      if (j > i) {
        soma += matriz[i][j];
        ++contador;
      }
    }
  }

  printf("%.1lf\n", operacao == 'S' ? soma : soma / contador);

  return 0;
}
