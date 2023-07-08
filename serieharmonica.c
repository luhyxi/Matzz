#include <stdio.h>

int main() {
    int divisor;
    float soma;
    float hn;

    printf("Insira o numero desejado:"); 
    scanf("%d", &divisor);
    
    for (hn = 1; hn <= divisor; hn ++){
        soma = soma + (1/hn);
    }
    
    
    printf("\n O Hn do numero desejado é %.3f", soma);
    return 0;
}
