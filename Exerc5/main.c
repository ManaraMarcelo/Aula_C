#include <stdio.h>
int num = 1;

int main(void) {
    while (num>0) {
        printf("Insira numeros inteiros: ");
        scanf("%d", &num);
        if(num<0) {
            printf("Num negativo: %d", num);
            break;
        }
    }
    return 0;
}
