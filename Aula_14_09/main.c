#include <stdio.h>
#include "calculadora.h"

int main(void) {
    int x = 10, y = 5;
    printf("\nResultado da soma: %d", somar(x, y));
    printf("\nResultado da soma: %d", subtrair(x, y));
    printf("\nResultado da soma: %d", multiplicar(x, y));
    printf("\nResultado da soma: %d", dividir(x, y));
    return 0;
}
