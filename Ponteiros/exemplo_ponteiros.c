#include <stdio.h>


int main() {
  int x=1, y=3;
  // Armazena o endereço de y em 'px' e 'py'
  int *px = &y, *py = &y; // 'px' e 'py' apontam para 'y'

  printf("\n");
  // Imprime 'x' e 'y'
  printf("x: %d\ny: %d\n", x, y);

  // 'y' recebe 'y + y' (ou seja, o dobro de 'y')
  *px = *px + *py;

  printf("\n");
  printf("x: %d\ny: %d\n", x, y);
  printf("*px: %d\n*py: %d\n", *px, *py);
  printf("px: %p\npy: %p\n", px, py);
  printf("&x: %p\n&y: %p\n", &x, &y);
}