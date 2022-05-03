/* lista simples encadiada ordenada sem repetição */
#include <stdio.h>
#include <stdlib.h>
#include "lse.h"
typedef struct bloco
{
    elem info;
    struct bloco *prox;
} no;
struct fila
{
    no *inicio, *fim;
    int tam;
};
Fila *Cria(int *flagErro)
{
    Fila *F = (Fila *)malloc(sizeof(Fila));
    if (F == NULL)
    {
        *flagErro = 1; // ERRO_MEMORIA_INSUFICIENTE
        return F;
    }
    else
    {
        *flagErro = 0; // SUCESSO
        F->inicio = NULL;
        F->fim = NULL;
        F->total = 0;
        return F;
    }
}
void InsereOrdenadoSemRepeticao(Lista *L, int x, int *flagErro){
    int i;
    no *p, *q;
    if (L != NULL)
    {
        if (L->tam == 0)
        {
            InsereInicio(L, x, flagErro);
        }
        else
        {
            i = BuscaBinaria(L, x);
            if (i == -1)
            {
                InsereFim(L, x, flagErro);
            }
            else
            {
                p = L->inicio;
                for (int i = 0; i < i; i++)
                    p = p->prox;
                q = p->prox;
                p->prox = (no *)malloc(sizeof(no));
                p->prox->info = x;
                p->prox->prox = q;
                L->tam++;
                *flagErro = 0; // SUCESSO
            }
        }
    }
    else
        *flagErro = 1; // ERRO_PONTEIRO_NULO
}
void InsereInicio(Lista *L, int x, int *flagErro)
{
    no *p = (no *)malloc(sizeof(no));
    if (L != NULL)
    {
        p->info = x;
        p->prox = L->inicio;
        L->inicio = p;
        if (L->fim == NULL)
            L->fim = p;
        L->tam++;
        *flagErro = 0; // SUCESSO
    }
    else
        *flagErro = 1; // ERRO_PONTEIRO_NULO
}
void InsereFim(Lista *L, int x, int *flagErro)
{
    no *p = (no *)malloc(sizeof(no));
    if (L != NULL)
    {
        p->info = x;
        p->prox = NULL;
        if (L->inicio == NULL)
            L->inicio = p;
        else
            L->fim->prox = p;
        L->fim = p;
        L->tam++;
        *flagErro = 0; // SUCESSO
    }
    else
        *flagErro = 1; // ERRO_PONTEIRO_NULO
}
void RemoveInicio(Lista *L, int *x, int *flagErro)
{
    no *p;
    if (L != NULL)
    {
        if (L->inicio != NULL)
        {
            p = L->inicio;
            *x = p->info;
            L->inicio = p->prox;
            if (L->inicio == NULL)
                L->fim = NULL;
            free(p);
            L->tam--;
            *flagErro = 0; // SUCESSO
        }
        else
            *flagErro = 1; // ERRO_FILA_VAZIA
    }
    else
        *flagErro = 1; // ERRO_PONTEIRO_NULO
}
void RemoveFim(Lista *L, int *x, int *flagErro)
{
    no *p, *q;
    if (L != NULL)
    {
        if (L->inicio != NULL)
        {
            if (L->inicio == L->fim)
            {
                p = L->inicio;
                *x = p->info;
                L->inicio = NULL;
                L->fim = NULL;
                free(p);
                L->tam--;
                *flagErro = 0; // SUCESSO
            }
            else
            {
                p = L->inicio;
                while (p->prox != L->fim)
                    p = p->prox;
                q = L->fim;
                p->prox = NULL;
                L->fim = p;
                *x = q->info;
                free(q);
                L->tam--;
                *flagErro = 0; // SUCESSO
            }
        }
        else
            *flagErro = 1; // ERRO_FILA_VAZIA
    }
    else
        *flagErro = 1; // ERRO_PONTEIRO_NULO
}
void Remove(Lista *L, int *x, int *flagErro){
    int i;
    no *p, *q;
    if (L != NULL)
    {
        if (L->inicio != NULL)
        {
            i = BuscaBinaria(L, *x);
            if (i != -1)
            {
                p = L->inicio;
                for (int i = 0; i < i; i++)
                    p = p->prox;
                q = p->prox;
                p->prox = q->prox;
                if (L->fim == q)
                    L->fim = p;
                free(q);
                L->tam--;
                *flagErro = 0; // SUCESSO
            }
            else
                *flagErro = 1; // ERRO_ELEMENTO_NAO_ENCONTRADO
        }
        else
            *flagErro = 1; // ERRO_FILA_VAZIA
    }
    else
        *flagErro = 1; // ERRO_PONTEIRO_NULO
}
void Imprime(Lista *L, int *flagErro){
    no *p;
    if (L != NULL)
    {
        if (L->inicio != NULL)
        {
            p = L->inicio;
            while (p != NULL)
            {
                printf("%d ", p->info);
                p = p->prox;
            }
            printf("\n");
            *flagErro = 0; // SUCESSO
        }
        else
            *flagErro = 1; // ERRO_FILA_VAZIA
    }
    else
        *flagErro = 1; // ERRO_PONTEIRO_NULO
}
void Libera(Lista *L, int *flagErro){
    no *p, *q;
    if (L != NULL)
    {
        if (L->inicio != NULL)
        {
            p = L->inicio;
            while (p != NULL)
            {
                q = p->prox;
                free(p);
                p = q;
            }
            L->inicio = NULL;
            L->fim = NULL;
            L->tam = 0;
            *flagErro = 0; // SUCESSO
        }
        else
            *flagErro = 1; // ERRO_FILA_VAZIA
    }
    else
        *flagErro = 1; // ERRO_PONTEIRO_NULO
}
void BuscaBinaria(Lista *L, int x, int *flagErro){
    int i, j, k, m;
    no *p, *q;
    if (L != NULL)
    {
        if (L->inicio != NULL)
        {
            i = 0;
            j = L->tam - 1;
            while (i <= j)
            {
                k = (i + j) / 2;
                p = L->inicio;
                for (int i = 0; i < k; i++)
                    p = p->prox;
                m = p->info;
                if (m == x)
                {
                    *flagErro = 0; // SUCESSO
                    return k;
                }
                else if (m < x)
                    i = k + 1;
                else
                    j = k - 1;
            }
            *flagErro = 1; // ERRO_ELEMENTO_NAO_ENCONTRADO
        }
        else
            *flagErro = 1; // ERRO_FILA_VAZIA
    }
    else
        *flagErro = 1; // ERRO_PONTEIRO_NULO
}
int Tamanho(Lista *L, int *flagErro){
    if (L != NULL)
    {
        *flagErro = 0; // SUCESSO
        return L->tam;
    }
    else
        *flagErro = 1; // ERRO_PONTEIRO_NULO
}
int Vazia(Lista *L, int *flagErro){
    if (L != NULL)
    {
        if (L->inicio == NULL)
        {
            *flagErro = 0; // SUCESSO
            return 1;
        }
        else
        {
            *flagErro = 0; // SUCESSO
            return 0;
        }
    }
    else
        *flagErro = 1; // ERRO_PONTEIRO_NULO
}
int Cheia(Lista *L, int *flagErro){
    if (L != NULL)
    {
        if (L->tam == MAX)
        {
            *flagErro = 0; // SUCESSO
            return 1;
        }
        else
        {
            *flagErro = 0; // SUCESSO
            return 0;
        }
    }
    else
        *flagErro = 1; // ERRO_PONTEIRO_NULO
}

