#include <stdio.h>
#include <string.h>

int main() {
    char str1[100], str2[100], resultado[200];

    // Leitura das duas strings
    printf("Digite a primeira string: ");
    fgets(str1, sizeof(str1), stdin);  // Usa fgets para ler strings com espaços
    str1[strcspn(str1, "\n")] = 0;     // Remove o caractere de nova linha

    printf("Digite a segunda string: ");
    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2, "\n")] = 0;

    // Concatenando as duas strings
    strcpy(resultado, str1);   // Copia str1 para resultado
    strcat(resultado, str2);   // Concatena str2 a resultado

    // Exibe a string concatenada
    printf("String resultante: %s\n", resultado);

    return 0;
}
