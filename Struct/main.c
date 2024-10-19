#include <stdio.h>

struct Aluno {
    int ra;
    char nome[51];
    char email[51];
};

void imprimir(struct Aluno aluno);
void ler(struct Aluno *aluno);

int main(void) {
    struct Aluno aluno; // crio mais uma variavel dentro do struct chamada aluno
    ler(&aluno);
    imprimir(aluno);
    return 0;
}

void imprimir(struct Aluno aluno){
    printf("\n===== ALUNO =====\n");
    printf("Dados do Aluno \n");
    printf("RA: %d \n", aluno.ra);
    printf("Nome: %s \n", aluno.nome);
    printf("Email: %s \n", aluno.email);
    printf("=========================\n");

}
void ler(struct Aluno *aluno) {
    printf(" Digite o ra do aluno : ");
    scanf("%d", &aluno->ra); // inserir o valor seguindo o caminho do ponteiro para RA
    fflush(stdin);
    printf("Digite o nome do aluno: ");
    scanf("%[^\n]", aluno->nome);
    fflush(stdin);
    printf("Digite o email do aluno: ");
    scanf("%[^\n]", aluno->email);
}