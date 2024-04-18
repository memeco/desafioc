#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No {
    char nome[50];
    struct No* proximo;
     No;  

// Função para criar um novo nó
No* criarNo(char* nome) {
    No* novoNo = (No*) malloc(sizeof(No));
    strcpy(novoNo->nome, nome);
    novoNo->proximo = NULL;
    return novoNo;
}

// Função para inserir um nome na lista em ordem alfabética
void inserirEmOrdem(No** inicio, char* nome) {
    No* novoNo = criarNo(nome);
    
    if (*inicio == NULL || strcmp(nome, (*inicio)->nome) < 0) {
        novoNo->proximo = *inicio;
        *inicio = novoNo;
        return;
    }
    
    No* atual = *inicio;
    while (atual->proximo != NULL && strcmp(nome, atual->proximo->nome) > 0) {
        atual = atual->proximo;
    }
    
    novoNo->proximo = atual->proximo;
    atual->proximo = novoNo;
}

// Função para exibir todos os nomes da lista
void exibirLista(No* inicio) {
    printf("Lista de nomes: ");

    while (inicio != NULL) {
        printf("%s -> ", inicio->nome);
        inicio = inicio->proximo;
    }
    printf("NULL\n");
}


int main() {
    No* inicio = NULL;
    char nome[50];
    char opcao;

    do {
        printf("\nMenu:\n");
        printf("1. Adicionar nome\n");
        printf("2. Exibir lista\n");
        printf("3. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%c", &opcao);

        switch (opcao) {
            case '1':
                printf("Digite o nome a ser adicionado: ");
                scanf("%s", nome);
                inserirEmOrdem(&inicio, nome);
                break;
            case '3':
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != '3');

}
