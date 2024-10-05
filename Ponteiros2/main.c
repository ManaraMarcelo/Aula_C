#include <stdio.h>

int stringLengh(char *p);
void deslocar_string(char *p);

int main(void) {
    char palavra[] = "Fatec Arthur de Azevedo";
    printf("Total de caracteres: %d \n", stringLengh(palavra));
    printf("Palavra Fatec: %c ", deslocar_string(palavra));
    return 0;
}

int stringLengh(char *p) {
    char *p_inicio = p;
    while (*p != '\0') p++;
    return p - p_inicio;
}
void deslocar_string(char *p) {
    char *p_i = p;
    while (*p != '\0'){
        putchar(*p++); //function para imprimir caracteres
    }
    p--; //desloquei para a casa anterior ao '\0'
    while (p >= p_i) {
        putchar(*p_i--);
    }
    p++;
}