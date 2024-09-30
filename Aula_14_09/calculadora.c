#include "calculadora.h"
#include <stdio.h>

int somar(int a, int b) {
    return a + b;
}

int subtrair(int a, int b) {
    return a - b;
}

int multiplicar(int a, int b) {
    return a * b;
}

int dividir(int a, int b) {
    if(b) { //se b tiver valor ele faz o código
        return a / b;
    }//se não automático
    printf("Erro na segunda variável");
    return -1; //deixo -1 como erro
}