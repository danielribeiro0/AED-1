// |Area of a Circle
/*
* Daniel Monteiro Ribeiro
* RA: 176231
*/

#include <stdio.h>
 
int main() {
    double pi=3.14159, A, R;
    scanf("%lf", &R);
    A = pi*(R*R);
    printf("A=%.4lf\n", A);
 
    return 0;
}