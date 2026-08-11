#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define TAM_CODIGO 30

/* Estrutura do no da pilha (caixa) */
typedef struct Caixa {
    char codigo_rastreio[TAM_CODIGO];
    struct Caixa *proximo;
} Caixa;

/* Estrutura de controle da pilha: guarda apenas o topo */
typedef struct Pilha {
    Caixa *topo;
    int tamanho;
} Pilha;

/* Inicializa uma pilha vazia */
void criar_pilha(Pilha *pilha) {
    pilha->topo = NULL;
    pilha->tamanho = 0;
}

/* Insere uma caixa no TOPO da pilha (empilhar) */
void empilhar_caixa(Pilha *pilha, const char *codigo_rastreio) {
    Caixa *nova = (Caixa *) malloc(sizeof(Caixa));
    if (nova == NULL) {
        fprintf(stderr, "Erro: falha ao alocar memória.\n");
        exit(EXIT_FAILURE);
    }

    strncpy(nova->codigo_rastreio, codigo_rastreio, TAM_CODIGO - 1);
    nova->codigo_rastreio[TAM_CODIGO - 1] = '\0';

    /* a nova caixa aponta para quem era o topo ate agora */
    nova->proximo = pilha->topo;
    /* e passa a ser ela mesma o novo topo */
    pilha->topo = nova;

    pilha->tamanho++;
    printf("Empilhada: caixa [%s]\n", nova->codigo_rastreio);
}

/* Remove e retira a caixa do TOPO da pilha (desempilhar).
 * Retorna 1 se retirou alguma caixa, 0 se a pilha estava vazia. */
int desempilhar_caixa(Pilha *pilha) {
    if (pilha->topo == NULL) {
        printf("Pilha vazia. Nenhuma caixa para retirar.\n");
        return 0;
    }

    Caixa *retirada = pilha->topo;

    printf("Retirada: caixa [%s] -> removida do palete\n", retirada->codigo_rastreio);

    pilha->topo = pilha->topo->proximo;

    free(retirada);
    pilha->tamanho--;
    return 1;
}

/* Mostra a caixa do topo, sem remover */
void topo_da_pilha(Pilha *pilha) {
    if (pilha->topo == NULL) {
        printf("Pilha vazia.\n");
        return;
    }
    printf("Topo da pilha: [%s]\n", pilha->topo->codigo_rastreio);
}

/* Exibe todas as caixas empilhadas, do topo para a base */
void imprimir_pilha(Pilha *pilha) {
    Caixa *atual = pilha->topo;
    int pos = 1;

    if (atual == NULL) {
        printf("Pilha vazia.\n");
        return;
    }

    printf("----- Pilha do Palete (%d caixas) - Topo -> Base -----\n", pilha->tamanho);
    while (atual != NULL) {
        printf("%d) [%s]\n", pos, atual->codigo_rastreio);
        atual = atual->proximo;
        pos++;
    }
    printf("--------------------------------------------------------\n");
}

/* Libera toda a memoria da pilha (caso ainda existam caixas) */
void liberar_pilha(Pilha *pilha) {
    Caixa *atual = pilha->topo;
    Caixa *proximo;

    while (atual != NULL) {
        proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }

    pilha->topo = NULL;
    pilha->tamanho = 0;
}

int main(void) {

    setlocale(LC_ALL, ""); /* para permitir acentos no terminal*/
    Pilha palete;
    criar_pilha(&palete);

    empilhar_caixa(&palete, "BR-0001-XA");
    empilhar_caixa(&palete, "BR-0002-XA");
    empilhar_caixa(&palete, "BR-0003-XA");

    printf("\n");
    imprimir_pilha(&palete);

    printf("\n");
    topo_da_pilha(&palete);

    printf("\n");
    desempilhar_caixa(&palete); /* retira BR-0003-XA (ultima empilhada) */

    printf("\n");
    imprimir_pilha(&palete);

    liberar_pilha(&palete);

    return 0;
}