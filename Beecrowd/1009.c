// Salário com Bônus

#include <stdio.h>
 
int main() {
 
    char nome[50];
    double salary, sales, TOTAL;

    scanf("%s %lf %lf", &nome, &salary, &sales);
    
    TOTAL = salary + (0.15 * sales);
    
    printf("TOTAL = R$ %.2lf\n", TOTAL);
    
 
    return 0;
}