#include <stdio.h>
#include <string.h>

#define MAX 100

// Estrutura que representa uma parada da rota
struct parada
{
    char bairro[50];
    int prazo_minutos;
};

typedef struct parada Parada;

//Estrutura da lista sequencial
struct lista
{
    Parada vet[MAX]; //Vetor onde as paradas são armazenadas
    int n;        //Quantidade de paradas cadastradas
};

typedef struct lista Lista;

//Função para remover uma parada pelo nome do bairro
void removerParada(Lista *l, char bairro[])
{
    int i, j;

    // Procura a parada na lista
    for (i = 0; i < l->n; i++)
    {
        // Compara o nome informado com o nome armazenado
        if (strcmp(l->vet[i].bairro, bairro) == 0)
        {
            // Desloca todos os elementos para a esquerda
            for (j = i; j < l->n - 1; j++)
            {
                l->vet[j] = l->vet[j + 1];
            }

            //Diminui a quantidade de elementos da lista
            l->n--;

            printf("Parada removida com sucesso.\n");
            return;
        }
    }

    //Caso o bairro não seja encontrado
    printf("Parada nao encontrada.\n");
}

//Função para imprimir a lista
void imprime(Lista *l)
{
    int i;

    printf("\nRota de entregas:\n");

    for (i = 0; i < l->n; i++)
    {
         printf("%d - Bairro: %s | Prazo: %d minutos\n",
               i + 1,
               l->vet[i].bairro,
               l->vet[i].prazo_minutos);
    }
}

int main()
{
    Lista rota;
    char bairro[50];

    //inicializa a quantidade de paradas
    rota.n = 4;

    //cadastra algumas paradas
    strcpy(rota.vet[0].bairro, "Centro");
    rota.vet[0].prazo_minutos = 20;

    strcpy(rota.vet[1].bairro, "Aeroporto");
    rota.vet[1].prazo_minutos = 30;

    strcpy(rota.vet[2].bairro, "Cidade Nova");
    rota.vet[2].prazo_minutos = 25;

    strcpy(rota.vet[3].bairro, "UFPA");
    rota.vet[3].prazo_minutos = 40;
    //mostra a rota antes da remoção
    imprime(&rota);

    //o usuário informa qual parada deseja remover
    printf("\nDigite o bairro que deseja remover: ");
    scanf(" %[^\n]", bairro);

    //remove a parada
    removerParada(&rota, bairro);

    //mostra a rota atualizada
    imprime(&rota);

    return 0;
}
