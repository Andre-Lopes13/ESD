#include <stdio.h>
#include <stdlib.h>
#include "pilhaencadeada.h"
struct tipoitem
{
    int valor;
};
typedef struct celula_str
{
    TipoItem Item;
    struct celula_str *Prox;
} Celula;
struct tipopilha
{
    Celula *Fundo, Topo;
    int Tamanho;
};
TipoPilha *inicializaPilha()
{
    TipoPilha *pilha = (TipoPilha *)malloc(sizeof(TipoPilha));
    return pilha;
}
void fPVazia(TipoPilha *Pilha)
{
    Pilha->Topo = (Celula *)malloc(sizeof(Celula));
    Pilha->Fundo = Pilha->Topo;
    Pilha->Topo->Prox = NULL;
    Pilha->Tamanho = 0;
}
int vazia(TipoPilha *Pilha)
{
    return (Pilha->Topo == Pilha->Fundo);
}
void empilha(TipoItem *x, TipoPilha *Pilha)
{
    Celula *Aux;
    Aux = (Celula *)malloc(sizeof(Celula));
    Pilha->Topo->Item = *x;
    Aux->Prox = Pilha->Topo;
    Pilha->Topo = Aux;
    Pilha->Tamanho++;
}
void desempilha(TipoPilha *Pilha, TipoItem *Item)
{
    Celula *q;
    if (Vazia(Pilha))
    {
        printf("Erro: lista vazia \n");
        return;
    }
    q = Pilha->Topo;
    Pilha->Topo = q->Prox;
    *Item = q->Prox->Item;
    free(q);
    Pilha->Tamanho--;
}
int tamanho(TipoPilha *Pilha)
{
    return (Pilha->Tamanho);
}
void imprime(TipoPilha *pilha)
{
    Celula *Aux;
    Aux = pilha->Topo->Prox;
    printf("Imprime Pilha Encadeada: \n");
    while (Aux != NULL)
    {
        printf("%d\n", Aux->Item.valor);
        Aux = Aux->Prox;
    }
}
TipoItem *inicializaTipoItem(int n)
{
    TipoItem *item = (TipoItem *)malloc(sizeof(TipoItem));
    item->valor = n;
    return item;
}