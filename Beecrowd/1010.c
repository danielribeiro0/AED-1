// Cálculo Simples

#include <stdio.h>
 
int main() {
    
    int code, n;
    double value, total = 0;
    
    for (int i = 0; i < 2; i++) {
        scanf("%d %d %lf", &code, &n, &value);
        total += n * value;
    }
    
    printf("VALOR A PAGAR: R$ %.2lf\n", total);
 
    return 0;
}