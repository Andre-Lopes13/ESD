#include <stdio.h>
#include <stdlib.h>
#include "pilhaencadeada.h"
typedef struct bloco
{
    int info;
    struct bloco *prox;
} no;
typedef struct pilha
{
    no *inicio;
} TPilha;
TPilha *cria()
{
    TPilha *p;
    p = (TPilha *)malloc(sizeof(TPilha));
    p->inicio = NULL;
    return p;
}
void insere(TPilha *p, int elemento)
{
    no *novo = (no *)malloc(sizeof(no));
    novo->info = elemento;
    novo->prox = NULL;
    if (p->inicio == NULL)
    {
        p->inicio = novo;
    }
    else
    {
        novo->prox = p->inicio;
        p->inicio = novo;
    }
}
void removeNo(TPilha *p)
{
    no *aux = p->inicio;
    p->inicio = aux->prox;
    free(aux);
}
void imprime(TPilha *p)
{
    no *aux = p->inicio;
    while (aux != NULL)
    {
        printf("%d ", aux->info);
        aux = aux->prox;
    }
    printf("\n");
}
