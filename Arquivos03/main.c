#include <stdio.h>

typedef struct aluno {
    int rm;
    char nome[51];
}Aluno;

int main(void) {
    Aluno aluno;
    fflush(stdin);
    printf("Digite o nome do aluno: ");
    scanf("%[^\n]", aluno.nome); // strings nao precisam de &
    printf("Digite o rm do aluno: ");
    scanf("%d", &aluno.rm);

    FILE *fp = fopen("c:\\Dados\\aluno.txt", "a"); //modos append para insercao
    if (fp == NULL) {
        printf("Erro ao abrir arquivo\n");
        return -1;
    }
    // Escrever os dados do aluno no arquivo
    fprintf(fp, "RM: %d, Nome: %s\n", aluno.rm, aluno.nome);
    fclose(fp); //fechar o arquivo
    return 0;
}
