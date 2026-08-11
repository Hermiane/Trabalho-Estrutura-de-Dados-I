#include <stdio.h>
#include <string.h>
#include <locale.h>

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

    setlocale(LC_ALL, ""); /* para permitir acentos no terminal*/

    /* vetor nao ordenado, representando as 15 posicoes do galpao */
    int codigos_barras[NUM_POSICOES] = {
        78341, 12905, 55210, 90312, 43120,
        67810, 21453, 88732, 30298, 15674,
        99001, 40567, 62890, 71345, 25908
    };

    int codigo_digitado;

    printf("----- Posições do galpão -----\n");
    for (int i = 0; i < NUM_POSICOES; i++) {
        printf("Posição %2d -> Código: %d\n", i, codigos_barras[i]);
    }

    printf("\nDigite o código de barras a ser localizado: ");
    scanf("%d", &codigo_digitado);

    int indice = busca_linear(codigos_barras, NUM_POSICOES, codigo_digitado);

    if (indice != -1) {
        printf("\nCódigo %d encontrado na posição %d do galpão.\n", codigo_digitado, indice);
    } else {
        printf("\nCódigo %d não encontrado no galpão.\n", codigo_digitado);
    }

    return 0;
}