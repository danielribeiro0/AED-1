// Ponteiros em C

/*
 * Declaração:
 * tipo *nome;
 * 
 * São variáveis que armazenam um endereço de memória.
 * 
 * Devem SEMPRE apontar para o tipo usado em sua declaração.
 * O código a seguir resultará em um erro ou aviso (incompatible pointer type).
 * 
 * int *p;
 * float a = 1;
 * p = &a; 
 * 
 * Isso acontece porque os tamanhos e as representações na memória de uma 
 * variável inteira e uma flutuante são diferentes.
*/

#include <stdio.h>

int main() {
  //Variável 'a' que armazena o valor 1
  int a = 1;

  /* 'pa' armazena o endereço de 'a'. 
   * '*pa' é o valor armazenado em 'a'.*/
  int *pa = &a; 

  // Imprime os valores de 'a', 'pa' e '*pa'.
  printf("a: %d\nEndereco de a (pa): %p\nValor de a (*pa): %d\n", a, pa, *pa);
}