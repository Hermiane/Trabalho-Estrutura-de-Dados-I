#include <stdio.h>
#include <locale.h>

#define NUM_PACOTES 8

/* Troca o conteudo de duas variaveis float (passadas por endereco) */
void trocar(float *a, float *b) {
    float temp = *a;
    *a = *b;
    *b = temp;
}

/* Ordena o vetor de precos usando Bubble Sort (ordem crescente) */
void bubble_sort(float precos[], int tamanho) {
    int troquei;

    for (int i = 0; i < tamanho - 1; i++) {
        troquei = 0; /* flag de otimizacao */

        /* a cada passada, o maior elemento "borbulha" ate o final,
         * por isso o limite direito diminui (tamanho - 1 - i) */
        for (int j = 0; j < tamanho - 1 - i; j++) {
            if (precos[j] > precos[j + 1]) {
                trocar(&precos[j], &precos[j + 1]);
                troquei = 1;
            }
        }

        /* se nao houve nenhuma troca nesta passada,
         * o vetor ja esta ordenado -> encerra mais cedo */
        if (troquei == 0) {
            break;
        }
    }
}

/* Exibe o vetor de precos formatado */
void imprimir_precos(float precos[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("Pacote %d: R$ %.2f\n", i + 1, precos[i]);
    }
}

int main(void) {

    setlocale(LC_ALL, ""); /* para permitir acentos no terminal*/

    float precos[NUM_PACOTES] = {1899.90f, 750.00f, 3200.50f, 499.99f,
                                  2150.00f, 890.75f, 1250.30f, 640.00f};

    printf("----- Precos Antes da Ordenação -----\n");
    imprimir_precos(precos, NUM_PACOTES);

    bubble_sort(precos, NUM_PACOTES);
    
    printf("\n   ----- Depois da Ordenação -----\n");
    printf("\n----- Preços dos Pacotes (mais barato -> mais caro) -----\n");
    imprimir_precos(precos, NUM_PACOTES);

    return 0;
}