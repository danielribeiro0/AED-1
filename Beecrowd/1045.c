#include <stdio.h>

void trocar(double *x, double *y)
{
  double aux = *x;
  *x = *y;
  *y = aux;
}

int main()
{
  double lado1, lado2, lado3;

  scanf("%lf %lf %lf", &lado1, &lado2, &lado3);

  if (lado2 > lado1)
    trocar(&lado1, &lado2);
  if (lado3 > lado2)
  {
    trocar(&lado2, &lado3);
    if (lado2 > lado1)
      trocar(&lado1, &lado2);
  }

  if (lado1 >= lado2 + lado3)
  {
    printf("NAO FORMA TRIANGULO\n");
  }
  else
  {
    if (lado1 * lado1 == lado2 * lado2 + lado3 * lado3)
      printf("TRIANGULO RETANGULO\n");
    else if (lado1 * lado1 > lado2 * lado2 + lado3 * lado3)
      printf("TRIANGULO OBTUSANGULO\n");
    else
      printf("TRIANGULO ACUTANGULO\n");

    if (lado1 == lado2 && lado2 == lado3)
      printf("TRIANGULO EQUILATERO\n");
    else if (lado1 == lado2 || lado1 == lado3 || lado2 == lado3)
      printf("TRIANGULO ISOSCELES\n");
  }

  return 0;
}
