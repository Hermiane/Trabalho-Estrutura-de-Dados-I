#include <stdio.h>
#include <locale.h>

#define TAM_VETOR 15

/* Realiza busca linear no vetor, retornando o indice onde encontrou
 * o codigo_barras procurado, ou -1 se nao existir no vetor. */
int busca_linear(int codigos[], int tamanho, int codigo_procurado) {
    int i;

    for (i = 0; i < tamanho; i++) {
        if (codigos[i] == codigo_procurado) {
            return i; /* encontrou: retorna a posicao imediatamente */
        }
    }

    return -1; /* percorreu o vetor inteiro e nao achou */
}

/* Exibe todas as posicoes do galpao e seus respectivos codigos */
void imprimir_galpao(int codigos[], int tamanho) {
    int i;
    printf("----- Mapa do Galpao -----\n");
    for (i = 0; i < tamanho; i++) {
        printf("Posicao %2d: codigo %d\n", i, codigos[i]);
    }
    printf("---------------------------\n");
}

int main(void) {

    setlocale(LC_ALL, "");
    int codigos[TAM_VETOR] = {
        78341, 12903, 55672, 90218, 33456,
        67789, 10245, 88761, 45123, 29984,
        61230, 74501, 15678, 39902, 82345
    };

    imprimir_galpao(codigos, TAM_VETOR);

    int codigo_procurado;
    printf("\nDigite o codigo de barras a buscar: ");
    scanf("%d", &codigo_procurado);

    int posicao = busca_linear(codigos, TAM_VETOR, codigo_procurado);

    if (posicao != -1) {
        printf("Codigo %d encontrado na posicao %d.\n", codigo_procurado, posicao);
    } else {
        printf("Codigo %d nao encontrado no galpao.\n", codigo_procurado);
    }

    return 0;
}