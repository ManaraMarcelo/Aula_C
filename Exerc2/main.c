#include <stdio.h>

int num = 0;
int i;

int main(void) {
    printf("Escolha um numero inteiro positivo: ");
    scanf("%d", &num);
    for(i = 1; i <= num; i++) {
        if (i % 2 == 0) {
            printf("\nContagem: %d", i);
        }
    }
    return 0;
}
