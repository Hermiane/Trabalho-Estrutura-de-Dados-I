#include <stdio.h>

#define TAM 1000

// Função que realiza a busca binária
int buscaBinaria(int vet[], int n, int id)
{
    int inicio = 0;
    int fim = n - 1;
    int meio;

    // Continua a busca enquanto houver posições para analisar
    while (inicio <= fim)
    {
        // Calcula a posição central do vetor
        meio = (inicio + fim) / 2;

        // Verifica se o ID foi encontrado
        if (vet[meio] == id)
        {
            return meio;
        }

        // Se o ID procurado for maior, busca na metade direita
        if (id > vet[meio])
        {
            inicio = meio + 1;
        }
        else
        {
            // Caso seja menor, busca na metade esquerda
            fim = meio - 1;
        }
    }

    // Retorna -1 caso o ID não esteja na base
    return -1;
}

int main()
{
    int clientes[TAM];
    int id;
    int posicao;
    int i;

    //Simula os 1000 IDs já cadastrados em ordem crescente,
    //mas não são consecutivos.

    clientes[0] = 1;

    for (i = 1; i < TAM; i++)
    {
        clientes[i] = clientes[i - 1] + 2;
    }

    // Usuário informa o ID que deseja consultar
    printf("Digite o ID do cliente que deseja consultar: ");
    scanf("%d", &id);

    // Realiza a busca binária
    posicao = buscaBinaria(clientes, TAM, id);

    // Mostra o resultado da consulta
    if (posicao != -1)
    {
        printf("Cliente com ID %d esta ativo na base de dados.\n", id);
    }
    else
    {
        printf("Cliente com ID %d nao esta ativo na base de dados.\n", id);
    }

    return 0;
}
