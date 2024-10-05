#include <stdio.h>

void trocar_valor(int *pa, int *pb);
void imprimir_vetor(int *pv, int t);
void ordenar_vetor(int v[], int t);

int main(void) {
    int v[] = {11, 2, 7, 1, 14, 9};
    imprimir_vetor(v, 6);
    ordenar_vetor(v, 6);
    imprimir_vetor(v, 6);
    return 0;
}

void trocar_valor(int *pa, int *pb) {
    int aux = *pa;
    *pa = *pb;
    *pb = aux;
}
void imprimir_vetor(int *pv, int t) {
    // percorrer usando ponteiro
    printf("[ ");
    for (int i=0; i<t; i++) {
        printf("%d ", *pv++);
    }
    printf("]\n");
}
void ordenar_vetor(int v[], int t) {
    for (int i=0; i<t; i++) {
        for (int j=i+1; j<t; j++) {
            if (v[i] > v[j]) {
                trocar_valor(&v[i], &v[j]);
            }
        }
    }
}