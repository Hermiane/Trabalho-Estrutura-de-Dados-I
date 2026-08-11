#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
/* Estrutura do nó da lista encadeada (item do carrinho) */
typedef struct Item {
    int id_produto;
    int quantidade;
    float preco;
    struct Item *proximo;
} Item;

/* Cria e retorna um ponteiro para o início da lista (carrinho vazio) */
Item *criar_carrinho(void) {
    return NULL;
}

/* Insere um novo item no final da lista.
 * Recebe o ponteiro para o ponteiro da cabeça (permite alterar
 * a lista mesmo quando ela está vazia). */
void inserir_item(Item **cabeca, int id_produto, int quantidade, float preco) {
    Item *novo = (Item *) malloc(sizeof(Item));
    if (novo == NULL) {
        fprintf(stderr, "Erro: falha ao alocar memoria.\n");
        exit(EXIT_FAILURE);
    }
    novo->id_produto = id_produto;
    novo->quantidade = quantidade;
    novo->preco = preco;
    novo->proximo = NULL;
    if (*cabeca == NULL) {
        *cabeca = novo;
        return;
    }
    Item *atual = *cabeca;
    while (atual->proximo != NULL) {
        atual = atual->proximo;
    }
    atual->proximo = novo;
}

/* Calcula o valor total do carrinho (soma de quantidade * preco) */
float calcular_total(Item *cabeca) {
    float total = 0.0f;
    Item *atual = cabeca;
    while (atual != NULL) {
        total += atual->quantidade * atual->preco;
        atual = atual->proximo;
    }
    return total;
}

/* Exibe todos os itens do carrinho */
void imprimir_carrinho(Item *cabeca) {
    Item *atual = cabeca;
    int contador = 1;
    if (atual == NULL) {
        printf("Carrinho vazio.\n");
        return;
    }
    printf("----- Carrinho de Compras -----\n");
    while (atual != NULL) {
        printf("Item %d -> ID: %d | Qtd: %d | Preco: R$ %.2f | Subtotal: R$ %.2f\n",
               contador, atual->id_produto, atual->quantidade,
               atual->preco, atual->quantidade * atual->preco);
        atual = atual->proximo;
        contador++;
    }
    printf("--------------------------------\n");
}

/* Libera toda a memoria alocada para a lista */
void liberar_carrinho(Item *cabeca) {
    Item *atual = cabeca;
    Item *proximo;
    while (atual != NULL) {
        proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
}

int main(void) {
    setlocale(LC_ALL, "");
    
    Item *carrinho = criar_carrinho();
    int id_produto, quantidade;
    float preco;
    char opcao;

    do {
        printf("\nDigite o ID do produto: ");
        scanf("%d", &id_produto);

        printf("Digite a quantidade: ");
        scanf("%d", &quantidade);

        printf("Digite o preco unitario: R$ ");
        scanf("%f", &preco);

        inserir_item(&carrinho, id_produto, quantidade, preco);

        printf("\nItem adicionado com sucesso!\n");

        printf("Deseja adicionar outro item? (s/n): ");
        scanf(" %c", &opcao); /* o espaço antes de %c descarta o '\n' pendente no buffer */

    } while (opcao == 's' || opcao == 'S');

    printf("\n");
    imprimir_carrinho(carrinho);

    float total = calcular_total(carrinho);
    printf("\nValor total do carrinho: R$ %.2f\n", total);

    liberar_carrinho(carrinho);
    carrinho = NULL;

    return 0;
}