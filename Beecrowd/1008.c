// Salário

#include <stdio.h>
 
int main() {
    
    int N, hours;
    double hour_price, salary;

    scanf("%d %d %lf", &N, &hours, &hour_price);
    
    salary = hour_price * hours;
    
    printf("NUMBER = %d\n", N);
    printf("SALARY = U$ %.2lf\n", salary);
 
    return 0;
}