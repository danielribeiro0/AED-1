

#include <stdio.h>
 
int main() {
    
    int price;
    
    scanf("%d", &price);
    
    
    printf("%d\n", price);

    printf("%d nota(s) de R$ 100,00\n", price / 100);
    price = price % 100;
    
    printf("%d nota(s) de R$ 50,00\n", price / 50);
    price = price % 50;
    
    printf("%d nota(s) de R$ 20,00\n", price / 20);
    price = price % 20;
    
    printf("%d nota(s) de R$ 10,00\n", price / 10);
    price = price % 10;
    
    printf("%d nota(s) de R$ 5,00\n", price / 5);
    price = price % 5;
    
    printf("%d nota(s) de R$ 2,00\n", price / 2);
    price = price % 2;
    
    printf("%d nota(s) de R$ 1,00\n", price / 1);
    price = price % 1;
 
    return 0;
}