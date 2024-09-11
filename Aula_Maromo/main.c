#include <stdio.h>

short int numone = 0;
unsigned int numtwo = 0;

int main(void) {
    printf("Insira o valor do primeiro numero inteiro: ");
    scanf("%hd", &numone);
    printf("\nInsira o valor do segundo numero inteiro: ");
    scanf("%u", &numtwo);

    printf("\nValor primeiro numero: %hd", numone);
    printf("\nSeu tamanho em bytes: %zu", sizeof(numone));
    printf("\nValor do segundo numero: %u", numtwo);
    printf("\nSeu tamanho em bytes: %zu", sizeof(numtwo));
    return 0;
}
