    #include <stdio.h>
    int num = 1;
    int cont; //realiza a contagem de quantos foram adicionados
    int soma; //armazena as somas até sair a media
    float media;

    int main(void) {
        while(num != 0) {
            printf("Insira um valor inteiro positivo: ");
            scanf("%d", &num);
            if(num == 0) {
                break;
            }
            cont ++;
            soma += num;
            printf("\nsoma: %d", soma);
            printf("\ncont: %d\n", cont);
        }
        media = soma / cont;
        printf("A media total é: %.2f", media);
        return 0;
    }
