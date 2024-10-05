#include <stdio.h>
void trocar_valor(int *pa, int *pb);

int main(void) {
    int x = 10;
    int y = 20;

    trocar_valor(&x, &y);

    printf("Valor de X: %d \n", x);
    printf("Valor de Y: %d \n", y);
    return 0;
}

void trocar_valor(int *pa, int *pb) {
    int aux = *pa;
    *pa = *pb;
    *pb = aux;
}