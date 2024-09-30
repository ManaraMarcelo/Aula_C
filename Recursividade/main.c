

#include <stdio.h>

int fat(int n);
int fatr(int n);
int up(int n);
int somatoria(int n);
int fibo(int i);

int main(void) {
    /*int v;
    printf("\nDigite o valor do fatorial desejado: ");
    scanf("%d", &v);
    printf("\nO fatorial de %d e: %d\n", v, fatr(v));
    return 0;*/
    /*
    int n = 0;
    printf("\nDigite o valor desejado para a contagem: ");
    scanf("%d", &n);
    printf("\nContagem: %d\n", up(n));
    return 0;
    */
    /*
    int n;
    printf("\nInsira o valor final para a somatoria: ");
    scanf("%d", &n);
    printf("\n%d\n", somatoria(n));
    return 0;
    */
    int n;
    printf("Insira o x° numero para Fibonacci: ");
    scanf("%d", &n);
    printf("\n%d", fibo(n));
}

int up(int n) {
    if (n==0) return;
    up(n-1);
    printf("%d\n", n);
}

int fat(int n) {
    int f = 1;
    for(int i=1; i<=n; i++){
        f*= 1;
    }
    return f;
}

int fatr(int n) {
    if(n==1) return 1;
    return n * fatr(n-1);
}

int somatoria(int n) {
    if (n==1) return 1;
    return n+(n-1);
}

int fibo(int n) {
    if(n==1 || n==2) return 1;
    return fibo(n-1) + fibo(n-2);
}