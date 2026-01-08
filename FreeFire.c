#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ITENS 10

struct Item {
    char nome[30];
    char tipo[20];
    int quantidade;
};

// Protótipos das funções
void inserirItem(struct Item inventario[], int *total);
void removerItem(struct Item inventario[], int *total);
void listarItens(struct Item inventario[], int total);
void buscarItem(struct Item inventario[], int total);

int main() {
    struct Item inventario[MAX_ITENS];
    int totalItens = 0;
    int opcao;

    do {
        printf("\n===== MOCHILA DO JOGADOR =====\n");
        printf("1 - Inserir item\n");
        printf("2 - Remover item\n");
        printf("3 - Listar itens\n");
        printf("4 - Buscar item\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
            case 1:
                inserirItem(inventario, &totalItens);
                listarItens(inventario, totalItens);
                break;

            case 2:
                removerItem(inventario, &totalItens);
                listarItens(inventario, totalItens);
                break;

            case 3:
                listarItens(inventario, totalItens);
                break;

            case 4:
                buscarItem(inventario, totalItens);
                break;

            case 0:
                printf("Saindo do inventario...\n");
                break;

            default:
                printf("Opcao invalida!\n");
        }

    } while (opcao != 0);

    return 0;
}

//Funções

void inserirItem(struct Item inventario[], int *total) {
    if (*total >= MAX_ITENS) {
        printf("Mochila cheia!\n");
        return;
    }

    printf("Nome do item: ");
    fgets(inventario[*total].nome, 30, stdin);
    inventario[*total].nome[strcspn(inventario[*total].nome, "\n")] = '\0';

    printf("Tipo do item: ");
    fgets(inventario[*total].tipo, 20, stdin);
    inventario[*total].tipo[strcspn(inventario[*total].tipo, "\n")] = '\0';

    printf("Quantidade: ");
    scanf("%d", &inventario[*total].quantidade);
    getchar();

    (*total)++;
    printf("Item inserido com sucesso!\n");
}

void removerItem(struct Item inventario[], int *total) {
    char nomeBusca[30];
    int encontrado = 0;

    printf("Digite o nome do item a remover: ");
    fgets(nomeBusca, 30, stdin);
    nomeBusca[strcspn(nomeBusca, "\n")] = '\0';

    for (int i = 0; i < *total; i++) {
        if (strcmp(inventario[i].nome, nomeBusca) == 0) {
            for (int j = i; j < *total - 1; j++) {
                inventario[j] = inventario[j + 1];
            }
            (*total)--;
            encontrado = 1;
            printf("Item removido!\n");
            break;
        }
    }

    if (!encontrado) {
        printf("Item nao encontrado.\n");
    }
}

void listarItens(struct Item inventario[], int total) {
    if (total == 0) {
        printf("Mochila vazia.\n");
        return;
    }

    printf("\n===== ITENS NA MOCHILA =====\n");
    for (int i = 0; i < total; i++) {
        printf("\nItem %d\n", i + 1);
        printf("Nome: %s\n", inventario[i].nome);
        printf("Tipo: %s\n", inventario[i].tipo);
        printf("Quantidade: %d\n", inventario[i].quantidade);
    }
}

void buscarItem(struct Item inventario[], int total) {
    char nomeBusca[30];
    int encontrado = 0;

    printf("Digite o nome do item a buscar: ");
    fgets(nomeBusca, 30, stdin);
    nomeBusca[strcspn(nomeBusca, "\n")] = '\0';

    for (int i = 0; i < total; i++) {
        if (strcmp(inventario[i].nome, nomeBusca) == 0) {
            printf("\nItem encontrado!\n");
            printf("Nome: %s\n", inventario[i].nome);
            printf("Tipo: %s\n", inventario[i].tipo);
            printf("Quantidade: %d\n", inventario[i].quantidade);
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Item nao encontrado.\n");
    }
}
