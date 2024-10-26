#include <stdio.h>

int main(void) {
    FILE *fp = fopen("c:\\Dados\\frutas.txt", "r");
    if (fp == NULL) {
        printf("Erro ao abrir arquivo\n");
    }
    char ch;
    // ler caracter por caracter enquando for diferente de fim de aquivo (EOF)
    while ((ch = fgetc(fp)) != EOF) {
        putchar(ch);
    }
    fclose(fp); //fechar o arquivo
    return 0;
}
