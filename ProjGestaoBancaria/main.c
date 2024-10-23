#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

/*
 Alunos:
 Arthur Aparecido Marquesi Santana
 João Vitor Costa e Silva
 Marcelo Augusto Manara de Abreu
*/

//Número máximo de cadastros
#define MAXCADS 100

typedef struct {
    int codigoCliente;
    char nomeCliente[100];
    int numeroAgencia;
    char numeroConta[20];
    float saldoAtual;
    char usuario[30];
    char senha[80];
    char chavePix[100];
} Clientes;

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void checarEntradaInteira(int *variavel, char *mensagem) {
    bool valOk = false;
    while (!valOk) {
        printf("%s", mensagem);
        if (scanf("%d", variavel) != 1) {
            printf("Valor Inválido! Insira um número!\n\n");
            limparBuffer();
        } else {
            limparBuffer();
            valOk = true;
        }
    }
}

void limparFgets(char *string) {
    const size_t len = strlen(string);
    if (len > 0 && string[len - 1] == '\n') {
        string[len - 1] = '\0';
    }
}

void cadastrarCliente(Clientes cliente[], int *totalClientes, int *codigoClienteMain) {
    if (*totalClientes >= MAXCADS) {
        printf("O limite de clientes cadastrados foi atingido.\n");
        return;
    }
    printf("\n======CADASTRO NOVO CLIENTE======\n");
    printf("Digite seu nome: ");
    fgets(cliente[*totalClientes].nomeCliente, sizeof(cliente[*totalClientes].nomeCliente), stdin);
    limparFgets(cliente[*totalClientes].nomeCliente);
    checarEntradaInteira(&cliente[*totalClientes].numeroAgencia, "Digite o número da agência: ");
    printf("Digite o número da conta: ");
    fgets(cliente[*totalClientes].numeroConta, sizeof(cliente[*totalClientes].numeroConta), stdin);
    limparFgets(cliente[*totalClientes].numeroConta);
    printf("Escolha um nome de usuário (1-100 caracteres): ");
    fgets(cliente[*totalClientes].usuario, sizeof(cliente[*totalClientes].usuario), stdin);
    limparFgets(cliente[*totalClientes].usuario);
    printf("Escolha uma senha (1-80 caracteres): ");
    fgets(cliente[*totalClientes].senha, sizeof(cliente[*totalClientes].senha), stdin);
    limparFgets(cliente[*totalClientes].senha);
    cliente[*totalClientes].codigoCliente = *codigoClienteMain;
    cliente[*totalClientes].saldoAtual = 0;
    (*totalClientes)++;
    (*codigoClienteMain)++;
}

void editarCliente(Clientes cliente[], int totalClientes) {
    int codigoEditar;
    bool encontrado = false;
    printf("\n====== EDITAR DADOS DO CLIENTE ======\n");
    checarEntradaInteira(&codigoEditar, "Digite o código do cliente que deseja editar: ");
    for (int i = 0; i < totalClientes; i++) {
        if (cliente[i].codigoCliente == codigoEditar) {
            encontrado = true;
            printf("Dados atuais do cliente:\n");
            printf("Nome: %s\n", cliente[i].nomeCliente);
            printf("Agência: %d\n", cliente[i].numeroAgencia);
            printf("Número da Conta: %s\n", cliente[i].numeroConta);
            printf("Saldo Atual: R$%.2f\n", cliente[i].saldoAtual);
            printf("Usuário: %s\n", cliente[i].usuario);
            printf("Chave PIX: %s\n", cliente[i].chavePix);
            printf("\nDigite os novos dados do cliente\n");
            printf("Novo nome: ");
            fgets(cliente[i].nomeCliente, sizeof(cliente[i].nomeCliente), stdin);
            limparFgets(cliente[i].nomeCliente);
            checarEntradaInteira(&cliente[i].numeroAgencia, "Novo número da agência: ");
            printf("Novo número da conta: ");
            fgets(cliente[i].numeroConta, sizeof(cliente[i].numeroConta), stdin);
            limparFgets(cliente[i].numeroConta);
            printf("Novo saldo atual: ");
            scanf("%f", &cliente[i].saldoAtual);
            limparBuffer();
            printf("Novo usuário: ");
            fgets(cliente[i].usuario, sizeof(cliente[i].usuario), stdin);
            limparFgets(cliente[i].usuario);
            printf("Nova chave PIX: ");
            fgets(cliente[i].chavePix, sizeof(cliente[i].chavePix), stdin);
            limparFgets(cliente[i].chavePix);
            printf("\nDados atualizados com sucesso!\n");
            break;
        }
    }
    if (!encontrado) {
        printf("Cliente não encontrado.\n");
    }
}

void fazerLogin(Clientes cliente[], char nomeUsuario[], char senhaUsuario[], bool *token, int *codigoCliente, int totalClientes, bool *eAdmin) {
    for (int i = 0; i < totalClientes; i++) {
        if (strcmp(nomeUsuario, cliente[i].usuario) == 0 && strcmp(senhaUsuario, cliente[i].senha) == 0 && strcmp(nomeUsuario, "rafaelConceicao") != 0) {
            *token = true;
            *codigoCliente = cliente[i].codigoCliente;
            return;
        }
    }
    if (strcmp(nomeUsuario, "rafaelConceicao") == 0 && strcmp(senhaUsuario, "26081914") == 0) {
        *eAdmin = true;
        *codigoCliente = cliente[0].codigoCliente;  // Admin assume o código do primeiro cliente
        *token = true;  // Marca como autenticado para o admin
        return;
    }
    printf("Nome de usuário ou senha incorretos!\n");
}

void verificarChavePix(Clientes cliente[], char chavePix[], const int codigoUsuario, bool *pixExiste, int *codigoConta, int totalClientes) {
    for (int i = 0; i < totalClientes; i++) {
        if (strcmp(chavePix, cliente[i].chavePix) == 0 && i != codigoUsuario) {
            *codigoConta = cliente[i].codigoCliente;
            *pixExiste = true;
            return;
        }
    }
    *pixExiste = false;
}

void verificarCodConta(Clientes cliente[], char numConta[], const int codigoUsuario, bool *contaExiste, int *codConta, int totalClientes) {
    for (int i = 0; i < totalClientes; i++) {
        if (strcmp(cliente[i].numeroConta, numConta) == 0 && i != codigoUsuario) {
            *codConta = cliente[i].codigoCliente;
            *contaExiste = true;
            return;
        }
    }
    *contaExiste = false;
}

void exibirClientes(Clientes cliente[], int totalClientes, bool eAdmin, int codigoCliente) {
    if (!eAdmin) {
        printf("\nCliente: %s\n", cliente[codigoCliente].nomeCliente);
        printf("Código do Cliente: %d\n", cliente[codigoCliente].codigoCliente);
        printf("Agência: %d\n", cliente[codigoCliente].numeroAgencia);
        printf("Conta: %s\n", cliente[codigoCliente].numeroConta);
        printf("Saldo Atual: R$%.2f\n", cliente[codigoCliente].saldoAtual);
    } else {
        printf("\nLista de Clientes:\n");
        for (int i = 0; i < totalClientes; i++) {
            printf("Cliente: %s\n", cliente[i].nomeCliente);
            printf("Código do Cliente: %d\n", cliente[i].codigoCliente);
            printf("Agência: %d\n", cliente[i].numeroAgencia);
            printf("Conta: %s\n", cliente[i].numeroConta);
            printf("Saldo Atual: R$%.2f\n\n", cliente[i].saldoAtual);
        }
    }
}

int main(void) {
    bool sairMenu = false;
    int totalClientes = 1, codigoClienteMain = 1;
    Clientes cliente[MAXCADS];
    //ADMIN
    cliente[0].codigoCliente = 0;
    strcpy(cliente[0].nomeCliente, "Rafael Conceição");
    cliente[0].numeroAgencia = 0000;
    strcpy(cliente[0].numeroConta, "00000000-0");
    cliente[0].saldoAtual = 0;
    strcpy(cliente[0].usuario, "rafaelConceicao");
    strcpy(cliente[0].senha, "26081914");
    while (!sairMenu) {
        int optionLogin = 0;
        printf("\n==========MENU URUBUBANK==========\n"
               "1. Já tenho uma conta UrubuBank\n"
               "2. Ainda não tenho uma conta UrubuBank\n"
               "0. Sair\n");
        while (true) {
            checarEntradaInteira(&optionLogin, "Escolha uma opção: ");
            if (optionLogin < 0 || optionLogin > 2) {
                printf("Valor Inválido! Escolha uma opção entre 0 e 2.\n");
            } else {
                break;
            }
        }
        switch (optionLogin) {
            case 1: {
                bool tokenAcesso = false, eAdmin = false;
                char nomeUsuario[30], senhaUsuario[80];
                int codigoUsuario = 0;
                printf("Digite o seu nome de usuário: ");
                fgets(nomeUsuario, sizeof(nomeUsuario), stdin);
                limparFgets(nomeUsuario);
                printf("Digite a sua senha: ");
                fgets(senhaUsuario, sizeof(senhaUsuario), stdin);
                limparFgets(senhaUsuario);
                fazerLogin(cliente, nomeUsuario, senhaUsuario, &tokenAcesso, &codigoUsuario, totalClientes, &eAdmin);
                if (tokenAcesso) {
                    bool sairLoggedIn = false;
                    while (!sairLoggedIn) {
                        int optionLoggedIn = 0;
                        printf("\n==========MENU URUBUBANK==========\n"
                               "1. Saque\n"
                               "2. Depósito\n"
                               "3. Área Pix\n"
                               "4. Transferência Bancária\n"
                               "5. Consultar Saldo\n"
                               "6. Editar Cadastros (Apenas Administradores)\n"
                               "0. Sair\n");
                        while (true) {
                            checarEntradaInteira(&optionLoggedIn, "Escolha uma opção: ");
                            if ((optionLoggedIn < 0 || optionLoggedIn > 6)) {
                                printf("Valor Inválido! Escolha uma opção entre 0 e 6.\n");
                            } else {
                                break;
                            }
                        }
                        switch (optionLoggedIn) {
                            case 1: {
                                int saque;
                                checarEntradaInteira(&saque, "Quanto deseja sacar?: ");

                                if (saque > cliente[codigoUsuario].saldoAtual && !eAdmin) {
                                    printf("Saldo Insuficiente!\n");
                                } else {
                                    cliente[codigoUsuario].saldoAtual -= saque;
                                    printf("Seu saldo agora é de R$%.2f.\n", cliente[codigoUsuario].saldoAtual);
                                }
                            }
                            break;
                            case 2: {
                                int deposito;
                                checarEntradaInteira(&deposito, "Quanto deseja depositar?: ");
                                cliente[codigoUsuario].saldoAtual += deposito;
                                printf("Seu saldo agora é de R$%.2f.\n", cliente[codigoUsuario].saldoAtual);
                            }
                            break;
                            case 3: {
                                int optionPix;
                                printf("\n==============Área PIX==============\n"
                                       "1. Cadastrar Chave Pix\n"
                                       "2. Enviar Pix\n"
                                       "0. Sair\n");
                                while (true) {
                                    checarEntradaInteira(&optionPix, "Escolha uma opção: ");
                                    if (optionPix < 0 || optionPix > 2) {
                                        printf("Valor Inválido! Escolha uma opção entre 0 e 2.\n");
                                    } else {
                                        break;
                                    }
                                }
                                switch (optionPix) {
                                    case 1: {
                                        char cadChavePix[100];
                                        bool pixExiste;
                                        int codigoDestinatario;
                                        printf("Digite a chave PIX que deseja cadastrar: ");
                                        fgets(cadChavePix, sizeof(cadChavePix), stdin);
                                        limparFgets(cadChavePix);
                                        verificarChavePix(cliente, cadChavePix, codigoUsuario, &pixExiste, &codigoDestinatario, totalClientes);
                                        if (!pixExiste && !eAdmin) {
                                            strcpy(cliente[codigoUsuario].chavePix, cadChavePix);
                                            printf("Chave PIX cadastrada com sucesso!\n");
                                        } else {
                                            printf("Chave PIX indisponível!\n");
                                        }
                                    }
                                    break;
                                    case 2: {
                                        char cadChavePix[100];
                                        bool pixExiste;
                                        int codigoDestinatario;
                                        printf("Digite a chave PIX do destinatário: ");
                                        fgets(cadChavePix, sizeof(cadChavePix), stdin);
                                        limparFgets(cadChavePix);
                                        verificarChavePix(cliente, cadChavePix, codigoUsuario, &pixExiste, &codigoDestinatario, totalClientes);
                                        if (pixExiste) {
                                            int deposito;
                                            checarEntradaInteira(&deposito, "Quanto deseja enviar?: ");
                                            if (deposito > cliente[codigoUsuario].saldoAtual && !eAdmin) {
                                                printf("Saldo insuficiente.\n");
                                            } else {
                                                cliente[codigoUsuario].saldoAtual -= deposito;
                                                cliente[codigoDestinatario].saldoAtual += deposito;
                                                printf("PIX efetuado com sucesso!");
                                            }
                                        } else {
                                            printf("Chave PIX indisponível!\n");
                                        }
                                    }
                                    break;
                                    case 0:{
                                        char certeza[5];
                                        printf("Você tem certeza de que deseja sair? (S/N): ");
                                        fgets(certeza, sizeof(certeza), stdin);
                                        limparFgets(certeza);
                                        for (int i = 0; i < sizeof(certeza); i++) {
                                            certeza[i] = tolower(certeza[i]);
                                        }
                                        if (strcmp(certeza, "s") == 0 || strcmp(certeza, "sim") == 0) {
                                            printf("Saindo...\n");
                                            break;
                                        } else {
                                            printf("Retornando ao Menu Principal...\n");
                                        }
                                    }
                                        break;
                                    default:
                                        printf("Opção inválida!\n");
                                }
                            }
                            break;
                            case 4: {
                                char numConta[20];
                                bool contaExiste = false;
                                int deposito = 0, codConta = 0;
                                printf("Digite o número da conta para qual deseja fazer a transferência: ");
                                fgets(numConta, sizeof(numConta), stdin);
                                limparFgets(numConta);
                                checarEntradaInteira(&deposito, "Digite o valor que deseja enviar: ");
                                verificarCodConta(cliente, numConta, codigoUsuario, &contaExiste, &codConta, totalClientes);
                                if (contaExiste) {
                                    if (deposito > cliente[codigoUsuario].saldoAtual && !eAdmin) {
                                        printf("Saldo insuficiente.\n\n");
                                    } else {
                                        cliente[codigoUsuario].saldoAtual -= deposito;
                                        cliente[codConta].saldoAtual += deposito;
                                    }
                                } else {
                                    printf("O número de conta informado não existe.\n\n");
                                }
                            }
                            break;
                            case 5: {
                                exibirClientes(cliente, totalClientes, eAdmin, codigoUsuario);
                            }
                            break;
                            case 6: {
                                if (eAdmin) {
                                    editarCliente(cliente, totalClientes);
                                } else {
                                    printf("Apenas administradores podem acessar essa opção.\n");
                                }
                            }
                            break;
                            case 0: {
                                char certeza[5];
                                printf("Você tem certeza de que deseja sair? (S/N): ");
                                fgets(certeza, sizeof(certeza), stdin);
                                limparFgets(certeza);
                                for (int i = 0; i < sizeof(certeza); i++) {
                                    certeza[i] = tolower(certeza[i]);
                                }
                                if (strcmp(certeza, "s") == 0 || strcmp(certeza, "sim") == 0) {
                                    printf("Saindo...\n");
                                    sairLoggedIn = true;
                                } else {
                                    printf("Retornando ao Menu Principal...\n");
                                }
                            }
                            break;
                            default:
                                printf("Opção inválida!\n");
                        }
                    }
                }
            }
            break;
            case 2:
                cadastrarCliente(cliente, &totalClientes, &codigoClienteMain);
                break;
            case 0: {
                char certeza[5];
                printf("Você tem certeza de que deseja sair? (S/N): ");
                fgets(certeza, sizeof(certeza), stdin);
                limparFgets(certeza);
                for (int i = 0; i < sizeof(certeza); i++) {
                    certeza[i] = tolower(certeza[i]);
                }
                if (strcmp(certeza, "s") == 0 || strcmp(certeza, "sim") == 0) {
                    printf("Saindo...\n");
                    sairMenu = true;
                } else {
                    printf("Retornando ao Menu Principal...\n");
                }
            }
            break;
            default:
                printf("Valor Inválido. Escolha uma opção válida.\n");
        }
    }
    return 0;
}