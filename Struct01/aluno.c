#include "aluno.h"
#include <stdio.h>
#include <stdlib.h>

void inicializa() {
    for (int i=0; i<MAX; i++) {
        v[i] = NULL;
    }
}

void ler_dados(int i) {
    if (v[i]==NULL) {
        printf("Posição ja preenchida\n");
        return;
    }
    v[i] = (p_aluno) malloc(sizeof(aluno));
    fflush(stdin);
    printf("Digite o Nome do aluno: \n");
    scanf("[^\n]", v[i]->nome);
    fflush(stdin);
    printf("Digite o RA do aluno: \n");
    scanf("%d", &v[i]->matricula);
    fflush(stdin);
    printf("Digite o Endereco do aluno: \n");
    scanf("[^\n]", v[i]->endereco);
    fflush(stdin);
    printf("Digite o Telefone do aluno: \n");
    scanf("[^\n]", v[i]->telefone);
    fflush(stdin);
    printf("Digite a Nota do aluno: \n");
    scanf("[^\n]", &v[i]->nota);
    fflush(stdin);
    printf("Cadastrado com sucesso!\n");
}

void imprimir_unico(int i) {

}

void imprimir_tudo() {

}