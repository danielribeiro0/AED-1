// O Maior

#include <stdio.h>
 
int main() {
    
    int a, b, c, maior;
    
    scanf("%d %d %d", &a, &b, &c);
    
    maior = a;
    if (maior < b) maior = b;
    if (maior < c) maior = c;
    
    printf("%d eh o maior\n", maior);
 
    return 0;
}