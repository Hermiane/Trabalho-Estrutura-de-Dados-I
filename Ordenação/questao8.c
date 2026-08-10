#include <stdio.h>

#define TAM 10

// Função para ordenar o vetor utilizando o Insertion Sort
void insertionSort(int vet[], int n)
{
    int i, j, chave;

    // Percorre o vetor a partir do segundo elemento
    for (i = 1; i < n; i++)
    {
        chave = vet[i]; // Guarda o elemento atual
        j = i - 1;

        // Desloca os elementos maiores para a direita
        while (j >= 0 && vet[j] > chave)
        {
            vet[j + 1] = vet[j];
            j--;
        }

        // Coloca a chave na posição correta
        vet[j + 1] = chave;
    }
}

// Função para imprimir os horários
void imprime(int vet[], int n)
{
    int i;

    for (i = 0; i < n; i++)
    {
        printf("%d minutos\n", vet[i]);
    }
}

int main()
{
    // Horários já registrados pelo supermercado
    int horarios[TAM] =
    {
        480, 720, 600, 510, 840,
        750, 540, 660, 900, 570
    };

    printf("Horarios antes da ordenacao:\n");
    imprime(horarios, TAM);

    // Ordena os horários
    insertionSort(horarios, TAM);

    printf("\nHorarios em ordem cronologica crescente:\n");
    imprime(horarios, TAM);

    return 0;
}

