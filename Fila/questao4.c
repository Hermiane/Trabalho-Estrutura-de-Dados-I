#include <stdio.h>
#include <string.h>

#define MAX 100

//Estrutura que representa um pedido
struct pedido
{
    int numero_pedido;
    char nome_prato[50];
};

typedef struct pedido Pedido;

//Estrutura da fila circular
struct fila
{
    Pedido vet[MAX];
    int inicio;
    int fim;
    int n;
};

typedef struct fila Fila;

//Inicializa a fila
void inicializa(Fila *f)
{
    f->inicio = 0;
    f->fim = 0;
    f->n = 0;
}

//Verifica se a fila est? vazia
int vazia(Fila *f)
{
    return (f->n == 0);
}

// Verifica se a fila est? cheia
int cheia(Fila *f)
{
    return (f->n == MAX);
}

//Insere um pedido no final da fila
void enfileira(Fila *f, int numero, char prato[])
{
    //Verifica se a fila est? cheia
    if (cheia(f))
    {
        printf("Fila cheia.\n");
        return;
    }

    //Armazena o n?mero do pedido
    f->vet[f->fim].numero_pedido = numero;

    //Armazena o nome do prato
    strcpy(f->vet[f->fim].nome_prato, prato);

    //Avan?a o final da fila de forma circular
    f->fim = (f->fim + 1) % MAX;

    //Aumenta a quantidade de pedidos
    f->n++;
}

//Remove e exibe o pr?ximo pedido da fila
void desenfileira(Fila *f)
{
    Pedido p;

    //Verifica se a fila est? vazia
    if (vazia(f))
    {
        printf("Fila vazia.\n");
        return;
    }

    //Guarda o pedido que est? no in?cio da fila
    p = f->vet[f->inicio];

    //Mostra o pr?ximo prato que ser? preparado
    printf("\nProximo pedido a preparar:\n");
    printf("Numero do pedido: %d\n", p.numero_pedido);
    printf("Prato: %s\n", p.nome_prato);

    //Avan?a o in?cio da fila de forma circular
    f->inicio = (f->inicio + 1) % MAX;

    //Diminui a quantidade de pedidos
    f->n--;
}

//Imprime os pedidos que est?o na fila
void imprime(Fila *f)
{
    int i;
    int posicao;

    if (vazia(f))
    {
        printf("Fila vazia.\n");
        return;
    }

    printf("\nFila de pedidos:\n");

    for (i = 0; i < f->n; i++)
    {
        //Calcula a posi??o correta dentro da fila circular
        posicao = (f->inicio + i) % MAX;

        printf("Pedido %d - %s\n",
               f->vet[posicao].numero_pedido,
               f->vet[posicao].nome_prato);
    }
}

int main()
{
    Fila fila;

    //Inicializa a fila
    inicializa(&fila);

    //Adiciona alguns pedidos para teste
    enfileira(&fila, 101, "Lasanha");
    enfileira(&fila, 102, "Pizza");
    enfileira(&fila, 103, "Hamburguer");
    enfileira(&fila, 104, "Macarronada");

    //Mostra a fila
    imprime(&fila);

    //Retira e mostra o pr?ximo pedido
    desenfileira(&fila);

    //Mostra a fila atualizada
    imprime(&fila);

    return 0;
}
