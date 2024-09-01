#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max 2                   // Define o número máximo de clientes
#define tamanho_nome 100       // Define o tamanho máximo do nome do cliente
#define tamanho_cpf 12         // Define o tamanho máximo do CPF do cliente

#define senha_Gerente "1234"   // Senha para autenticação de gerente
#define senha_Cliente "0000"   // Senha para autenticação de cliente


// Estrutura para armazenar informações do cliente
typedef struct {
    char nome[tamanho_nome];    // Nome do cliente
    char senha[tamanho_cpf];    // CPF do cliente (usado como senha)
    float saldo;                // Saldo do cliente
} Cliente;


// Função para autenticação do usuário
int autenticacao_usuario() {
    char senha[tamanho_nome];   // Armazena a senha fornecida pelo usuário
    printf("\nDIGITE A SUA SENHA: ");
    scanf("%s", senha);


    // Verifica se a senha fornecida corresponde à senha do gerente
    if (strcmp(senha, senha_Gerente) == 0) {
        return 1; // Senha de Gerente
    } else if (strcmp(senha, senha_Cliente) == 0) {
        return 2; // Senha de Cliente
    } else {
        printf("SENHA INCORRETA. ACESSO NEGADO!\n");
        return 0; // Senha incorreta
    }
}


// Função para inserir clientes e seus CPFs
void InserirClientes_E_CPFS(Cliente *cliente) {
    printf("\n----------------------------------------------\n");
    printf("DIGITE O NOME DO CLIENTE: ");
    getchar(); // Limpa o buffer do teclado
    fgets(cliente->nome, tamanho_nome, stdin);
    cliente->nome[strcspn(cliente->nome, "\n")] = '\0'; // Remove o caractere de nova linha

    printf("DIGITE O CPF DO CLIENTE: ");
    fgets(cliente->senha, tamanho_cpf, stdin);
    cliente->senha[strcspn(cliente->senha, "\n")] = '\0'; // Remove o caractere de nova linha

    cliente->saldo = 0.0; // Inicializa o saldo do cliente com 0
    printf("CLIENTE CADASTRADO COM SUCESSO!\n");
}

// Função para listar os clientes cadastrados
void ListarClientes(Cliente clientes[], int num_clientes) {
    printf("\n----------------------------------------------\n");
    printf("\nCLIENTES CADASTRADOS\n");
    for (int i = 0; i < num_clientes; i++) {
        // Imprime as informações de cada cliente
        printf("CLIENTE %d: %s - CPF: %s - SALDO: R$ %.2f\n", i + 1, clientes[i].nome, clientes[i].senha, clientes[i].saldo);
    }
}


// Função para alterar o saldo de um cliente
void AlterarSaldoCliente(Cliente clientes[], int num_clientes) {
    char cpf[tamanho_cpf];
    int encontrado = 0; // Flag para indicar se o cliente foi encontrado
    printf("\n----------------------------------------------\n");
    printf("ALTERAR SALDO DO CLIENTE\n");
    printf("DIGITE O CPF DO CLIENTE: ");
    scanf("%s", cpf);

    for (int i = 0; i < num_clientes; i++) {
        if (strcmp(clientes[i].senha, cpf) == 0) {
            // Cliente encontrado
            printf("CLIENTE ENCONTRADO: %s\n", clientes[i].nome);
            printf("SALDO ATUAL: R$ %.2f\n", clientes[i].saldo);
            printf("DIGITE O NOVO SALDO: R$ ");
            scanf("%f", &clientes[i].saldo); // Atualiza o saldo
            printf("SALDO ALTERADO COM SUCESSO!\n");
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("CLIENTE NÃO ENCONTRADO!\n");
    }
}

// Função para alterar o nome de um cliente
void AlterarNomeCliente(Cliente clientes[], int num_clientes) {
    char nome_atual[tamanho_nome];
    char novo_nome[tamanho_nome];
    int encontrado = 0; // Flag para indicar se o cliente foi encontrado

    printf("\n----------------------------------------------\n");
    printf("ALTERAR NOME DO CLIENTE\n");
    printf("DIGITE O NOME ATUAL DO CLIENTE: ");
    getchar(); // Limpa o buffer do teclado
    fgets(nome_atual, tamanho_nome, stdin);
    nome_atual[strcspn(nome_atual, "\n")] = '\0'; // Remove o caractere de nova linha

    for (int i = 0; i < num_clientes; i++) {
        if (strcmp(clientes[i].nome, nome_atual) == 0) {
            // Cliente encontrado
            printf("CLIENTE ENCONTRADO: %s\n", clientes[i].nome);
            printf("DIGITE O NOVO NOME: ");
            fgets(novo_nome, tamanho_nome, stdin);
            novo_nome[strcspn(novo_nome, "\n")] = '\0'; // Remove o caractere de nova linha
            strcpy(clientes[i].nome, novo_nome); // Atualiza o nome do cliente
            printf("NOME ALTERADO COM SUCESSO!\n");
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("CLIENTE NÃO ENCONTRADO!\n");
    }
}

// Função para alterar o CPF de um cliente
void AlterarCPFCliente(Cliente clientes[], int num_clientes) {
    char cpf_atual[tamanho_cpf];
    char novo_cpf[tamanho_cpf];
    int encontrado = 0; // Flag para indicar se o cliente foi encontrado

    printf("\n----------------------------------------------\n");
    printf("ALTERAR CPF DO CLIENTE\n");
    printf("DIGITE O CPF ATUAL DO CLIENTE: ");
    scanf("%s", cpf_atual);

    for (int i = 0; i < num_clientes; i++) {
        if (strcmp(clientes[i].senha, cpf_atual) == 0) {
            // Cliente encontrado
            printf("CLIENTE ENCONTRADO: %s\n", clientes[i].nome);
            printf("DIGITE O NOVO CPF: ");
            scanf("%s", novo_cpf); // Atualiza o CPF
            strcpy(clientes[i].senha, novo_cpf);
            printf("CPF ALTERADO COM SUCESSO!\n");
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("CLIENTE NÃO ENCONTRADO!\n");
    }
}

// Função que exibe o menu do gerente
void MenuGerente(Cliente clientes[], int *num_clientes) {
    int opcao;

    do {
        printf("\n----------------------------------------------\n");
        printf("\nMENU GERENTE\n");
        printf("1. CADASTRAR CLIENTE\n");
        printf("2. LISTAR CLIENTES\n");
        printf("3. ALTERAR O SALDO DO CLIENTE\n");
        printf("4. ALTERAR O CPF DO CLIENTE\n");
        printf("5. ALTERAR O NOME DO CLIENTE\n");
        printf("6. TROCAR USUÁRIO\n");
        printf("7. SAIR\n");
        printf("ESCOLHA UMA OPCAO: ");
        scanf("%d", &opcao);
        system("CLS"); // Limpa a tela (comando específico do Windows)

        switch (opcao) {
            case 1:
                if (*num_clientes < max) {
                    InserirClientes_E_CPFS(&clientes[*num_clientes]);
                    (*num_clientes)++;
                } else {
                    printf("Número máximo de clientes alcançado!\n");
                }
                break;

            case 2:
                ListarClientes(clientes, *num_clientes);
                break;

            case 3:
                AlterarSaldoCliente(clientes, *num_clientes);
                break;

            case 4:
                AlterarCPFCliente(clientes, *num_clientes);
                break;

            case 5:
                AlterarNomeCliente(clientes, *num_clientes);
                break;

            case 6:
                return; // Volta para o início, permitindo alterar o tipo de usuário
                break;

            case 7:
                printf("SAINDO...\n");
                break;

            default:
                printf("OPCAO INVALIDA!\n");
                break;
        }
    } while (opcao != 7);
}

// Função que exibe o menu do cliente
void MenuCliente(Cliente clientes[], int indice_cliente) {
    int opcao;
    do {
        printf("\n----------------------------------------------\n");
        printf("\nMENU CLIENTE\n");
        printf("1. VERIFICAR SALDO\n");
        printf("2. REALIZAR SAQUE\n");
        printf("3. REALIZAR DEPOSITO\n");
        printf("4. TRANSFERENCIA DE VALORES\n");
        printf("5. TROCAR USUÁRIO\n");
        printf("6. SAIR\n");
        printf("ESCOLHA UMA OPCAO: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("SALDO: R$ %.2f\n", clientes[indice_cliente].saldo);
                break;

            case 2:
                RealizarSaque(clientes, indice_cliente);
                break;

            case 3:
                RealizarDep(clientes, indice_cliente);
                break;

            case 4:
                // Lógica para transferência (ainda não implementada)
                printf("TRANSFERENCIA REALIZADA COM SUCESSO!\n");
                break;

            case 5:
                return; // Volta para o início, permitindo alterar o tipo de usuário
                break;

            case 6:
                printf("SAINDO...\n");
                break;

            default:
                printf("OPCAO INVALIDA!\n");
                break;
        }
    } while (opcao != 6);
}

// Função para realizar o saque
void RealizarSaque(Cliente clientes[], int indice_cliente) {
    float valor_saque;

    printf("\n----------------------------------------------\n");
    printf("REALIZAR SAQUE\n");
    printf("SALDO ATUAL: R$ %.2f\n", clientes[indice_cliente].saldo);
    printf("DIGITE O VALOR DO SAQUE: R$ ");
    scanf("%f", &valor_saque);

    if (valor_saque <= 0) {
        printf("VALOR INVÁLIDO! O VALOR DO SAQUE DEVE SER MAIOR QUE ZERO.\n");
        return;
    }

    if (valor_saque > clientes[indice_cliente].saldo) {
        printf("SALDO INSUFICIENTE PARA REALIZAR O SAQUE!\n");
    } else {
        clientes[indice_cliente].saldo -= valor_saque; // Atualiza o saldo após o saque
        printf("SAQUE REALIZADO COM SUCESSO! NOVO SALDO: R$ %.2f\n", clientes[indice_cliente].saldo);
    }
}

// Função para realizar o depósito
void RealizarDep(Cliente clientes[], int indice_cliente) {
    float valor_Deposito;

    printf("\n----------------------------------------------\n");
    printf("REALIZAR DEPOSITO\n");
    printf("SALDO ATUAL: R$ %.2f\n", clientes[indice_cliente].saldo);
    printf("DIGITE O VALOR DO DEPOSITO: R$ ");
    scanf("%f", &valor_Deposito);

    if (valor_Deposito <= 0) {
        printf("VALOR INVÁLIDO! O VALOR DO DEPOSITO DEVE SER MAIOR QUE ZERO.\n");
        return;
    }

    clientes[indice_cliente].saldo += valor_Deposito; // Atualiza o saldo após o depósito
    printf("DEPOSITO REALIZADO COM SUCESSO! NOVO SALDO: R$ %.2f\n", clientes[indice_cliente].saldo);
}



// Função principal
int main() {
    Cliente clientes[max];     // Array de clientes
    int num_clientes = 0;      // Contador de clientes cadastrados
    int tipo_usuario;          // Tipo de usuário (Gerente ou Cliente)
    int indice_cliente = -1;   // Índice do cliente autenticado  - USADA PARA ARMAZENAR UM INDICE. IDENTIFICA QUEMÉ O USUARIO LOGADO

    do {
        printf("-------SEJA BEM-VINDO AO ADS BANK-------\n");
        printf("\n----------------------------------------------\n");

        // Autenticação de usuário
        tipo_usuario = autenticacao_usuario();
        if (tipo_usuario == 0) {
            continue; // Se a autenticação falhar, reinicia o loop
        }

        // Exibe o menu conforme o tipo de usuário (Gerente ou Cliente)
        if (tipo_usuario == 1) {
            MenuGerente(clientes, &num_clientes);
        } else if (tipo_usuario == 2) {
            char cpf_cliente[tamanho_cpf];
            printf("DIGITE O SEU CPF: ");
            scanf("%s", cpf_cliente);

            // Encontrar o índice do cliente
            for (int i = 0; i < num_clientes; i++) {
                if (strcmp(clientes[i].senha, cpf_cliente) == 0) {
                    indice_cliente = i;
                    break;
                }
            }

            if (indice_cliente != -1) {
                MenuCliente(clientes, indice_cliente);
            } else {
                printf("CLIENTE NÃO ENCONTRADO!\n");
            }
        }
    } while (1); // Continua pedindo autenticação até o usuário decidir sair

    return 0;
}
