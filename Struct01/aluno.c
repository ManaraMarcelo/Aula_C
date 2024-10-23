#include "aluno.h"
#include <stdio.h>
#include <stdlib.h>

void inicializa() {
    //varrer o vetor e colocar null em todas as posicoes
    for (int i = 0; i < MAX; i++) {
        v[i] = NULL;
    }
}
void ler_dados(int i) {
    if(v[i]!=NULL) {
        printf("Posicao ja preenhida\n");
        return;
    }
    v[i] =(p_aluno) malloc(sizeof(aluno));
    v[i] = (p_aluno) malloc(sizeof(struct Aluno));
    fflush(stdin);
    printf("Digite o nome do aluno: \n");
    scanf("%[^\n]", v[i]->nome);
    fflush(stdin);
    printf("Digite o ra do aluno: \n");
    scanf("%d", &v[i]->matricula);
    fflush(stdin);
    printf("Digite o endereco do aluno: \n");
    scanf("%[^\n]", v[i]->endereco);
    fflush(stdin);
    printf("Digite o telefone do aluno: \n");
    scanf("%[^\n]", v[i]->telefone);
    fflush(stdin);
    printf("Digite a nota do aluno: \n");
    scanf("%lf", &v[i]->nota);
    printf("Cadastrado com sucesso \n");
}
void imprimir_unico(int i) {
    if(v[i]!=NULL) {
        printf("Dado do Aluno de RA: %d \n", v[i]->matricula);
        printf("Nome do Aluno: %s \n", v[i]->nome);
        printf("Endereco do Aluno: %s \n", v[i]->endereco);
        printf("Telefone do Aluno: %s \n", v[i]->telefone);
        printf("Nota do Aluno: %.2lf \n", v[i]->nota);
    }
}
void imprimir_tudo() {
    for (int i = 0; i < MAX; i++) {
        imprimir_unico(i);
    }
}

void procurar_aluno(int matricula) {
    for (int i=0; i<MAX; ++i) {
        if (matricula == v[i]->matricula) {
            printf("Aluno encontrado: \n");
            imprimir_unico(i);
            return;
        }
    }
    printf("Aluno não encontrado \n");
}