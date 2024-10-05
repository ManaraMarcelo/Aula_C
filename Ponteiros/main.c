/**
 * Ponteiros sao variaveis que armazenam endereco de outras variaveis
*/

#include <stdio.h>

int main(void) {
    int v[] = {2, 4, 6, 8, 10};
    int *p = v; // &v[3] apontando para a indice 3 do vetor
    // se eu nao especificar ele sempre vai apontar para o indice 0
    printf("Valor do apontado por p: %d \n", *p);
    for (int i = 0; i < 5; i++) {
        printf("Valor: %d \n", *p++);
    }
    p = v;
    return 0;
}
