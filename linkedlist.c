#include <stdio.h>
#include <stdlib.h>

struct item
{
    int value;
    struct item *next;
};

void InicializarLista(struct item **l)
{
    // atribuir 0 para a lista
    *l = NULL;
};

void InserirNaLista(struct item **l, int v)
{
    if (*l == 0)
    {
        *l = malloc(sizeof(struct item));
        (*l)->value = v;
        (*l)->next = 0;
    } else {
        /*
        struct item *aux = malloc(sizeof(struct item));
        aux->value = v;
        aux->next = *l;
        *l = aux;
        */
        InserirNaLista(&((*l)->next), v);
    };
};

int PopList(struct item *p)
{
    int popValue;
    while ((p->next)->next != 0){
        p = p->next;
    }
    
    popValue = (p->next)->value;
    free(p->next);
    p->next = 0;
    
    return popValue;
}

void DestruirLista(struct item *l)
{
    free(l);
};

void ListaImprimir(struct item *p)
{
    while (p != 0)
    {
        // Imprimir dados
        printf("Valor = %d\n", p->value);
        printf("Proximo = %p\n", p->next);
        // Avançar para o próximo nó
        p = p->next;
    };
};

int main()
{
    struct item *lista;
    InicializarLista(&lista);
    printf("endereço da lista = %p\n", lista);

    InserirNaLista(&lista, 1);
    InserirNaLista(&lista, 2);
    InserirNaLista(&lista, 3);
    InserirNaLista(&lista, 4);
    InserirNaLista(&lista, 5);

    ListaImprimir(lista);

    int ValorPopado = PopList(lista);
    printf("\n\nValor popado = %d\n", ValorPopado);

    printf("\n\n");

    ListaImprimir(lista);

    DestruirLista(lista);

    return 0;
}