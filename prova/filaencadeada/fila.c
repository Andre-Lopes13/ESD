#include "fila.h"
#include <stdio.h>
#include <stdlib.h>
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
void Esvazia(Fila *F, int *flagErro)
{
    no *ndel, *nextno;
    if (F != NULL)
    {
        nextno = F->inicio;
        while (nextno != NULL)
        {
            ndel = nextno;
            nextno = nextno->prox;
            free(ndel);
        }
        F->inicio = NULL;
        F->fim = NULL;
        F->total = 0;
        *flagErro = 0; // SUCESSO
    }
    else
        *flagErro = 1; // ERRO_PONTEIRO_NULO
}
void Destroi(Fila *F, int *flagErro)
{
    if (F != NULL)
    {
        Esvazia(F, flagErro);
        free(F); // SUCESSO
        *flagErro = 0;
    }
    else
        *flagErro = 1; // ERRO_PONTEIRO_NULO
}
void Insere(Fila *F, elem X, int *erro)
{
    no *p = (no *)malloc(sizeof(no));
    if (F == NULL)
        *erro = 1;
    else
    {
        if (p == NULL)
            *erro = 1;
        else
        {
            *erro = 0;
            F->total++;
            p->info = X;
            p->prox = NULL;
            if (F->inicio == NULL) // Se é o primeiro, inicio aponta para o nó
                F->inicio = p;
            else
                F->fim->prox = p; // senão ajusta o campo prox do último nó
            F->fim = p;           // fim aponta para o nó
        }
    }
}
void Remove(Fila *F, elem *X, int *erro)
{
    no *p;
    if (!Vazia(F, erro))
    {
        if (*erro == 0)
        {
            *erro = 0; // desnecessário, pois a função Vazia já retorna um valor para erro
            F->total--;
            p = F->inicio;
            *X = p->info;
            F->inicio = F->inicio->prox;
            if (F->inicio == NULL) // Se ficou vazia ajusta fim
                F->fim = NULL;
            free(p);
        }
    }
    else
        *erro = 1;
}
void Inicio(Fila *F, elem *X, int *erro)
{
    if (!Vazia(F, erro))
    {
        if (*erro == 0)
        {
            *erro = 0;
            ; // desnecessário, pois a função Vazia já retorna um valor para erro
            *X = F->inicio->info;
        }
        else
            *erro = 1;
    }
}
int Vazia(Fila *F, int *flagErro)
{
    if (F != NULL)
    {
        *flagErro = 0; // SUCESSO
        if (F->total == 0)
            return 1;
        else
            return 0;
    }
    else
    {
        *flagErro = 1; // ERRO_PONTEIRO_NULO
        return 1;
    }
}
int Cheia(Fila *F, int *flagErro)
{
    if (F != NULL)
    {
        *flagErro = 0; // SUCESSO
        return 0;
    }
    else
    {
        *flagErro = 1; // ERRO_PONTEIRO_NULO
        return 0;
    }
}
int Tamanho(Fila *F, int *flagErro)
{
    if (F != NULL)
    {
        *flagErro = 0; // SUCESSO
        return F->total;
    }
    else
    {
        *flagErro = 1; // ERRO_PONTEIRO_NULO
        return -1;
    }
}