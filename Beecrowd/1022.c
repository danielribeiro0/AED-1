#include <stdio.h>

struct Racional
{
  int numerador, denominador;
};

struct Racional adicionar(struct Racional a, struct Racional b)
{
  struct Racional resultado;
  resultado.numerador = a.numerador * b.denominador + b.numerador * a.denominador;
  resultado.denominador = a.denominador * b.denominador;
  return resultado;
}

struct Racional subtrair(struct Racional a, struct Racional b)
{
  struct Racional resultado;
  resultado.numerador = a.numerador * b.denominador - b.numerador * a.denominador;
  resultado.denominador = a.denominador * b.denominador;
  return resultado;
}

struct Racional multiplicar(struct Racional a, struct Racional b)
{
  struct Racional resultado;
  resultado.numerador = a.numerador * b.numerador;
  resultado.denominador = a.denominador * b.denominador;
  return resultado;
}

struct Racional dividir(struct Racional a, struct Racional b)
{
  struct Racional resultado;
  resultado.numerador = a.numerador * b.denominador;
  resultado.denominador = b.numerador * a.denominador;
  return resultado;
}

int maximoDivisorComum(int x, int y)
{
  return (y == 0) ? x : maximoDivisorComum(y, x % y);
}

struct Racional simplificar(struct Racional r)
{
  int mdc = (r.numerador < 0) ? maximoDivisorComum(-r.numerador, r.denominador) : maximoDivisorComum(r.numerador, r.denominador);
  r.numerador /= mdc;
  r.denominador /= mdc;
  return r;
}

int main()
{
  int casos;
  char operacao;
  struct Racional r1, r2, resposta;

  scanf("%d\n", &casos);

  for (int i = 0; i < casos; ++i)
  {
    scanf("%d / %d %c %d / %d\n", &r1.numerador, &r1.denominador, &operacao, &r2.numerador, &r2.denominador);

    switch (operacao)
    {
    case '+':
      resposta = adicionar(r1, r2);
      break;
    case '-':
      resposta = subtrair(r1, r2);
      break;
    case '*':
      resposta = multiplicar(r1, r2);
      break;
    case '/':
      resposta = dividir(r1, r2);
      break;
    }

    printf("%d/%d = ", resposta.numerador, resposta.denominador);
    resposta = simplificar(resposta);
    printf("%d/%d\n", resposta.numerador, resposta.denominador);
  }

  return 0;
}
