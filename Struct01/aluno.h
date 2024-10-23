#ifndef ALUNO_H
#define ALUNO_H

#define MAX 100
typedef struct Aluno {
    char nome[81];
    int matricula;
    char endereco[121];
    char telefone[21];
    double nota;
}aluno; //criei um 'alias' um apelido para o struct

typedef aluno *p_aluno;

extern p_aluno v[MAX];

/**
 * Inicializar o vetor de ponteiros com nulo
 */
void inicializa();

/**
 * ler dados alocando em uma nova posicao
 * @param i representa o indice do vetor
 */
void ler_dados(int i);

/**
 * Recebe a posicao que se deseja imprimir
 * @param i representa o indice do vetor
 */
void imprimir_unico(int i);

/**
 * Imprimir todas as posicoes com dados
 */
void imprimir_tudo();

void procurar_aluno(int matricula);

#endif //ALUNO_H
