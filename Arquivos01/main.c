#include <stdio.h>

int main(void) {
    FILE *fp = fopen("c:\\Dados\\frutas.txt", "r");
    if (fp == NULL) {
        printf("Erro ao abrir arquivo\n");
        return -1;
    }
    char ch;
    char str[100];
    char *p_letra = str;
    fflush(stdin);
    printf("Digite uma fruta: \n");
    scanf("%[^\n]", str);
    // Escrever a fruta no final do arquivo
    while(*p_letra != '\0') {
        fputc(*p_letra, fp);
        p_letra++;
    }
    fputc('\n', fp);
    fclose(fp); //fechar o arquivo
    return 0;
}
