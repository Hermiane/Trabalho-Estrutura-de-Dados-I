#include <stdio.h>

#define NUM_POSICOES 15

/* Busca linear: percorre o vetor do inicio ao fim procurando o codigo_barras.
 * Retorna o indice onde o codigo foi encontrado, ou -1 se nao existir. */
int busca_linear(int vetor[], int tamanho, int codigo_procurado) {
    for (int i = 0; i < tamanho; i++) {
        if (vetor[i] == codigo_procurado) {
            return i; /* encontrou: retorna o indice imediatamente */
        }
    }
    return -1; /* percorreu tudo e nao achou */
}

int main(void) {
    /* vetor nao ordenado, representando as 15 posicoes do galpao */
    int codigos_barras[NUM_POSICOES] = {
        78341, 12905, 55210, 90312, 43120,
        67810, 21453, 88732, 30298, 15674,
        99001, 40567, 62890, 71345, 25908
    };

    int codigo_digitado;

    printf("----- Posicoes do galpao -----\n");
    for (int i = 0; i < NUM_POSICOES; i++) {
        printf("Posicao %2d -> Codigo: %d\n", i, codigos_barras[i]);
    }

    printf("\nDigite o codigo de barras a ser localizado: ");
    scanf("%d", &codigo_digitado);

    int indice = busca_linear(codigos_barras, NUM_POSICOES, codigo_digitado);

    if (indice != -1) {
        printf("\nCodigo %d encontrado na posicao %d do galpao.\n", codigo_digitado, indice);
    } else {
        printf("\nCodigo %d nao encontrado no galpao.\n", codigo_digitado);
    }

    return 0;
}