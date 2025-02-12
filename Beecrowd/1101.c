#include <stdio.h>

int main()
{
  int num1, num2;

  while (scanf("%d %d", &num1, &num2) != EOF)
  {
    if (num1 <= 0 || num2 <= 0)
    {
      break;
    }

    if (num1 > num2)
    {
      int temp = num1;
      num1 = num2;
      num2 = temp;
    }

    int soma = 0;
    for (int i = num1; i <= num2; ++i)
    {
      printf("%d ", i);
      soma += i;
    }
    printf("Sum=%d\n", soma);
  }

  return 0;
}
