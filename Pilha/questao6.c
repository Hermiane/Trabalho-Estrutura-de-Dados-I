#include <stdio.h>
#include <stdlib.h>

#define MAX 50

// Estrutura da pilha
struct pilha
{
    int n;             // quantidade de precos armazenados
    float vet[MAX];    // guarda os precos antigos
};

typedef struct pilha Pilha;

// Cria a pilha
Pilha *cria(void)
{
    Pilha *p;

    p = (Pilha *) malloc(sizeof(Pilha));

    if (p == NULL)
    {
        printf("Erro de memoria.\n");
        exit(1);
    }

    p->n = 0;

    return p;
}

// Verifica se a pilha esta vazia
int vazia(Pilha *p)
{
    return (p->n == 0);
}

// Guarda um preco antigo na pilha
void push(Pilha *p, float preco)
{
    if (p->n == MAX)
    {
        printf("Pilha cheia.\n");
        return;
    }

    p->vet[p->n] = preco;
    p->n++;
}

// Retira o ultimo preco armazenado
float pop(Pilha *p)
{
    float preco;

    if (vazia(p))
    {
        printf("Nao ha alteracoes para desfazer.\n");
        return -1;
    }

    preco = p->vet[p->n - 1];
    p->n--;

    return preco;
}

// Libera a memoria
void libera(Pilha *p)
{
    free(p);
}

int main(void)
{
    Pilha *historico;

    float preco_atual = 100.00;
    float novo_preco;
    float preco_restaurado;

    char opcao;

    historico = cria();

    printf("Preco atual do produto: R$ %.2f\n", preco_atual);

    // Salva o preco antigo antes da primeira alteracao
    push(historico, preco_atual);

    printf("\nDigite o novo preco: R$ ");
    scanf("%f", &novo_preco);

    preco_atual = novo_preco;

    printf("Preco alterado para: R$ %.2f\n", preco_atual);

    // Salva novamente o preco antes da segunda alteracao
    push(historico, preco_atual);

    printf("\nDigite outro preco: R$ ");
    scanf("%f", &novo_preco);

    preco_atual = novo_preco;

    printf("Preco alterado para: R$ %.2f\n", preco_atual);

    // Usuario escolhe se deseja desfazer
    printf("\nDeseja desfazer a ultima alteracao? (s/n): ");
    scanf(" %c", &opcao);

    if (opcao == 's' || opcao == 'S')
    {
        preco_restaurado = pop(historico);

        if (preco_restaurado != -1)
        {
            preco_atual = preco_restaurado;

            printf("Preco restaurado para: R$ %.2f\n", preco_atual);
        }
    }
    else
    {
        printf("Alteracao mantida.\n");
        printf("Preco atual: R$ %.2f\n", preco_atual);
    }

    libera(historico);

    return 0;
}

