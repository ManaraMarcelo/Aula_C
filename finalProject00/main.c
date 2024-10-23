#include <stdio.h>   // Biblioteca padrão de entrada e saída (printf, scanf, etc.)
#include <stdlib.h>  // Biblioteca para funções utilitárias como alocação de memória e exit()
#include <string.h>  // Biblioteca para manipulação de strings (função strcpy, etc.)

#define MAX_PRODUTOS 100  // Define o número máximo de produtos no estoque

// Estrutura para representar um produto
typedef struct {
    int id;               // ID único do produto
    char nome[50];        // Nome do produto
    float preco;          // Preço do produto
    int quantidade;       // Quantidade do produto no estoque
} Produto;  // 'Produto' é um nome alternativo para a struct que guarda as informações de um produto

// Protótipos das funções que serão utilizadas no programa
void adicionar_produto(Produto *produtos, int *total_produtos);   // Função para adicionar produto
void atualizar_produto(Produto *produtos, int total_produtos);     // Função para atualizar produto
void listar_estoque(Produto *produtos, int total_produtos);        // Função para listar produtos no estoque
void salvar_estoque(Produto *produtos, int total_produtos);        // Função para salvar estoque em arquivo
void carregar_estoque(Produto *produtos, int *total_produtos);     // Função para carregar estoque de arquivo

int main() {
    Produto produtos[MAX_PRODUTOS];  // Array que vai armazenar os produtos
    int total_produtos = 0;          // Contador de quantos produtos estão cadastrados
    int opcao;                       // Variável para armazenar a escolha do usuário no menu

    carregar_estoque(produtos, &total_produtos);  // Carrega o estoque salvo do arquivo, se existir

    do {
        // Exibe o menu de opções para o usuário
        printf("\nMenu:\n");
        printf("1. Adicionar Produto\n");
        printf("2. Atualizar Produto\n");
        printf("3. Listar Estoque\n");
        printf("4. Salvar Estoque e Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);  // Lê a opção do usuário

        // Switch para realizar a ação escolhida
        switch(opcao) {
            case 1:
                adicionar_produto(produtos, &total_produtos);  // Chama função para adicionar produto
                break;
            case 2:
                atualizar_produto(produtos, total_produtos);   // Chama função para atualizar um produto existente
                break;
            case 3:
                listar_estoque(produtos, total_produtos);      // Chama função para listar os produtos
                break;
            case 4:
                salvar_estoque(produtos, total_produtos);      // Salva o estoque em um arquivo e sai
                printf("Estoque salvo com sucesso!\n");
                break;
            default:
                printf("Opção inválida!\n");  // Se a opção for inválida, exibe uma mensagem de erro
        }
    } while (opcao != 4);  // Repete o menu até que o usuário escolha a opção de sair

    return 0;  // Termina o programa
}

// Função para adicionar um novo produto ao estoque
void adicionar_produto(Produto *produtos, int *total_produtos) {
    if (*total_produtos < MAX_PRODUTOS) {  // Verifica se ainda há espaço no estoque
        Produto novo_produto;  // Cria uma variável para armazenar o novo produto
        // Coleta as informações do novo produto
        printf("ID do produto: ");
        scanf("%d", &novo_produto.id);
        printf("Nome do produto: ");
        scanf(" %[^\n]s", novo_produto.nome);  // Lê o nome do produto (com espaços)
        printf("Preço do produto: ");
        scanf("%f", &novo_produto.preco);
        printf("Quantidade no estoque: ");
        scanf("%d", &novo_produto.quantidade);

        // Adiciona o novo produto ao array de produtos
        produtos[*total_produtos] = novo_produto;
        (*total_produtos)++;  // Incrementa o total de produtos cadastrados
    } else {
        printf("Estoque cheio!\n");  // Se o estoque estiver cheio, exibe mensagem de erro
    }
}

// Função para atualizar as informações de um produto existente no estoque
void atualizar_produto(Produto *produtos, int total_produtos) {
    int id, encontrado = 0;  // Variáveis para armazenar o ID procurado e se o produto foi encontrado
    printf("Digite o ID do produto a ser atualizado: ");
    scanf("%d", &id);  // Lê o ID do produto que o usuário quer atualizar

    // Percorre o array de produtos para procurar o produto com o ID fornecido
    for (int i = 0; i < total_produtos; i++) {
        if (produtos[i].id == id) {  // Se encontrar o produto
            printf("Novo preço: ");
            scanf("%f", &produtos[i].preco);  // Atualiza o preço
            printf("Nova quantidade: ");
            scanf("%d", &produtos[i].quantidade);  // Atualiza a quantidade
            encontrado = 1;  // Marca que o produto foi encontrado
            break;  // Sai do loop pois já encontrou o produto
        }
    }

    if (!encontrado) {  // Se o produto não foi encontrado, exibe mensagem de erro
        printf("Produto não encontrado!\n");
    }
}

// Função para listar todos os produtos no estoque
void listar_estoque(Produto *produtos, int total_produtos) {
    // Itera sobre todos os produtos e exibe suas informações
    for (int i = 0; i < total_produtos; i++) {
        printf("ID: %d\n", produtos[i].id);
        printf("Nome: %s\n", produtos[i].nome);
        printf("Preço: %.2f\n", produtos[i].preco);
        printf("Quantidade: %d\n\n", produtos[i].quantidade);
    }
}

// Função para salvar o estoque em um arquivo
void salvar_estoque(Produto *produtos, int total_produtos) {
    FILE *arquivo = fopen("estoque.txt", "w");  // Abre o arquivo para escrita

    if (arquivo != NULL) {  // Verifica se o arquivo foi aberto corretamente
        // Grava os dados de cada produto no arquivo
        for (int i = 0; i < total_produtos; i++) {
            fprintf(arquivo, "%d %s %.2f %d\n", produtos[i].id, produtos[i].nome, produtos[i].preco, produtos[i].quantidade);
        }
        fclose(arquivo);  // Fecha o arquivo após a gravação
    } else {
        printf("Erro ao abrir o arquivo!\n");  // Se não conseguir abrir o arquivo, exibe erro
    }
}

// Função para carregar o estoque de um arquivo
void carregar_estoque(Produto *produtos, int *total_produtos) {
    FILE *arquivo = fopen("estoque.txt", "r");  // Abre o arquivo para leitura

    if (arquivo != NULL) {  // Verifica se o arquivo foi aberto corretamente
        // Lê os dados do arquivo e armazena no array de produtos
        while (fscanf(arquivo, "%d %49s %f %d", &produtos[*total_produtos].id, produtos[*total_produtos].nome, &produtos[*total_produtos].preco, &produtos[*total_produtos].quantidade) != EOF) {
            (*total_produtos)++;  // Incrementa o número total de produtos carregados
        }
        fclose(arquivo);  // Fecha o arquivo após a leitura
    } else {
        printf("Nenhum arquivo de estoque encontrado, iniciando um novo estoque.\n");  // Se não encontrar o arquivo, começa um novo estoque vazio
    }
}
