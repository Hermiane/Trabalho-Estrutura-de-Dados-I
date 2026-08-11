#include <stdio.h>
#include <locale.h>

#define TAM_VETOR 8

/* Troca o conteudo de duas posicoes de memoria (usado dentro do bubble sort) */
void trocar(float *a, float *b) {
    float temp = *a;
    *a = *b;
    *b = temp;
}

/* Ordena o vetor de precos em ordem crescente usando Bubble Sort */
void bubble_sort(float precos[], int tamanho) {
    int i, j;
    int trocou;

    for (i = 0; i < tamanho - 1; i++) {
        trocou = 0; /* flag de otimizacao: se nao houve troca, o vetor ja esta ordenado */

        /* a cada passagem, o maior elemento "borbulha" ate o final,
         * por isso o limite direito diminui (tamanho - 1 - i) */
        for (j = 0; j < tamanho - 1 - i; j++) {
            if (precos[j] > precos[j + 1]) {
                trocar(&precos[j], &precos[j + 1]);
                trocou = 1;
            }
        }

        /* se nenhuma troca ocorreu nesta passagem, o vetor ja esta ordenado
         * e as passagens seguintes seriam desnecessarias */
        if (trocou == 0) {
            break;
        }
    }
}

/* Exibe o vetor de precos formatado */
void imprimir_precos(float precos[], int tamanho) {
    int i;
    for (i = 0; i < tamanho; i++) {
        printf("Pacote %d: R$ %.2f\n", i + 1, precos[i]);
    }
}

int main(void) {
    
    setlocale(LC_ALL, "");
    float precos[TAM_VETOR] = {2350.90f, 899.00f, 4500.50f, 1200.00f,
                                 780.25f, 3999.99f, 550.00f, 2100.75f};

    printf("----- Precos antes da ordenacao -----\n");
    imprimir_precos(precos, TAM_VETOR);

    bubble_sort(precos, TAM_VETOR);

    printf("\n----- Precos ordenados (mais barato -> mais caro) -----\n");
    imprimir_precos(precos, TAM_VETOR);

    return 0;
}