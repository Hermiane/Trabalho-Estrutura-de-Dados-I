#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_NOME 50

/* Estrutura do nó da fila (turista) */
typedef struct Turista {
    char nome[TAM_NOME];
    int idade;
    struct Turista *proximo;
} Turista;

/* Estrutura de controle da fila: guarda inicio e fim
 * para evitar percorrer a lista inteira a cada operacao. */
typedef struct Fila {
    Turista *inicio;
    Turista *fim;
    int tamanho;
} Fila;

/* Inicializa uma fila vazia */
void criar_fila(Fila *fila) {
    fila->inicio = NULL;
    fila->fim = NULL;
    fila->tamanho = 0;
}

/* Insere um turista no FIM da fila (enfileirar) */
void enfileirar_turista(Fila *fila, const char *nome, int idade) {
    Turista *novo = (Turista *) malloc(sizeof(Turista));
    if (novo == NULL) {
        fprintf(stderr, "Erro: falha ao alocar memoria.\n");
        exit(EXIT_FAILURE);
    }

    strncpy(novo->nome, nome, TAM_NOME - 1);
    novo->nome[TAM_NOME - 1] = '\0'; /* garante terminacao da string */
    novo->idade = idade;
    novo->proximo = NULL;

    if (fila->fim == NULL) {
        /* fila vazia: o novo turista e' inicio e fim ao mesmo tempo */
        fila->inicio = novo;
        fila->fim = novo;
    } else {
        fila->fim->proximo = novo;
        fila->fim = novo;
    }

    fila->tamanho++;
    printf("Enfileirado: %s (%d anos)\n", novo->nome, novo->idade);
}

/* Remove e atende o turista do INICIO da fila.
 * Retorna 1 se atendeu alguem, 0 se a fila estava vazia. */
int atender_turista(Fila *fila) {
    if (fila->inicio == NULL) {
        printf("Fila vazia. Nenhum turista para atender.\n");
        return 0;
    }

    Turista *atendido = fila->inicio;

    printf("Atendendo: %s (%d anos) -> Embarque liberado!\n",
           atendido->nome, atendido->idade);

    fila->inicio = fila->inicio->proximo;

    /* se a fila ficou vazia, atualiza o 'fim' tambem */
    if (fila->inicio == NULL) {
        fila->fim = NULL;
    }

    free(atendido);
    fila->tamanho--;
    return 1;
}

/* Mostra o turista que esta na frente da fila, sem remover */
void proximo_da_fila(Fila *fila) {
    if (fila->inicio == NULL) {
        printf("Fila vazia.\n");
        return;
    }
    printf("Proximo da fila: %s (%d anos)\n", fila->inicio->nome, fila->inicio->idade);
}

/* Exibe todos os turistas atualmente na fila, em ordem */
void imprimir_fila(Fila *fila) {
    Turista *atual = fila->inicio;
    int pos = 1;

    if (atual == NULL) {
        printf("Fila vazia.\n");
        return;
    }

    printf("----- Fila da Montanha-Russa (%d pessoas) -----\n", fila->tamanho);
    while (atual != NULL) {
        printf("%d) %s - %d anos\n", pos, atual->nome, atual->idade);
        atual = atual->proximo;
        pos++;
    }
    printf("------------------------------------------------\n");
}

/* Libera toda a memoria da fila (caso ainda existam turistas) */
void liberar_fila(Fila *fila) {
    Turista *atual = fila->inicio;
    Turista *proximo;

    while (atual != NULL) {
        proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }

    fila->inicio = NULL;
    fila->fim = NULL;
    fila->tamanho = 0;
}

int main(void) {
    Fila fila;
    criar_fila(&fila);

    enfileirar_turista(&fila, "Ana Souza", 22);
    enfileirar_turista(&fila, "Bruno Lima", 15);
    enfileirar_turista(&fila, "Carla Mendes", 34);

    printf("\n");
    imprimir_fila(&fila);

    printf("\n");
    proximo_da_fila(&fila);

    printf("\n");
    atender_turista(&fila); /* atende Ana */
    atender_turista(&fila); /* atende Bruno */

    printf("\n");
    imprimir_fila(&fila);

    liberar_fila(&fila);

    return 0;
}