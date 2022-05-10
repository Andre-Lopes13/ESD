/* lista simples encadiada ordenada sem repetição */
#include <stdio.h>
#include <stdlib.h>
#include "lse.h"
typedef struct bloco
{
    int info;
    struct bloco *prox;
} no;
struct lista
{
    no *inicio;
}Tlista;
void inicializa(lista *f)
{
    f->inicio = NULL;
}
no busca(lista *f, int x)
{
    no *p;
    for (p = f->inicio; p != NULL; p = p->prox)
    {
        if (p->info == x)
        {
            return *p;
        }
    }
    return NULL;
}
void insere(lista *f, int x)
{
    // inserção lista ordenada sem repetição encadeada
    no *p, *q;
    p = (no *)malloc(sizeof(no));
    p->info = x;
    p->prox = NULL;
    if (f->inicio == NULL)
    {
        f->inicio = p;
    }
    else
    {
        q = f->inicio;
        while (q->prox != NULL && q->prox->info < x)
        {
            q = q->prox;
        }
        if (q->prox == NULL)
        {
            q->prox = p;
        }
        else
        {
            p->prox = q->prox;
            q->prox = p;
        }
}
}
void imprime(lista *f)
{
    no *p;
    for (p = f->inicio; p != NULL; p = p->prox)
    {
        printf("%d ", p->info);
    }
    printf("\n");
}
void remove(lista *f, int x)
{
    no *p, *q;  // ponteiro para o elemento a ser removido e para o anterior
    p = f->inicio;
    q = NULL;
    while (p != NULL && p->info != x)
    {
        q = p;
        p = p->prox;
    }
    if (p == NULL)
    {
        printf("Elemento nao encontrado\n");
    }
    else
    {
        if (q == NULL)
        {
            f->inicio = p->prox;
        }
        else
        {
            q->prox = p->prox;
        }
        free(p);
    }
}
