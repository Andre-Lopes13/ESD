#include "fila.h"
#include <stdio.h>
#include <stdlib.h>
typedef struct bloco
{
    int info;
    struct bloco *prox;
} no;
typedef struct fila
{
    no *inicio;
    no *fim;
} Fila;
Fila *cria()
{
    Fila *f;
    f = (Fila *)malloc(sizeof(Fila));
    f->inicio = NULL;
    f->fim = NULL;
    return f;
}
void insere(Fila *f, int elemento)
{
    no *novo = (no *)malloc(sizeof(no));
    novo->info = elemento;
    novo->prox = NULL;
    printf("%d", novo->info);
    if (f->inicio == NULL)
    {
        f->inicio = novo;
        f->fim = novo;
    }
    else
    {
        f->fim->prox = novo;
        f->fim = novo;
    }
}
void removeNo(Fila *f)
{
    no *aux = f->inicio;
    f->inicio = aux->prox;
    free(aux);
}
void imprime(Fila *f)
{
    no *aux = f->inicio;
    while (aux != NULL)
    {
        printf("%d ", aux->info);
        aux = aux->prox;
    }
    printf("\n");
}