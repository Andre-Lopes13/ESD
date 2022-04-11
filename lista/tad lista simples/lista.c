#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
Lista criaLista(int capacidade, int ehClassificado, int ehComRepeticao)
{
    Lista l;
    l.capacidade = capacidade;
    l.ehClassificado = ehClassificado;
    l.ehComRepeticao = ehComRepeticao;
    l.qtOcupada = 0;
    l.info = (int *)malloc(capacidade * sizeof(int));
    return l;
}
int buscaValor(Lista l, int valor)
{
    int i;
    for (i = 0; i < l.qtOcupada; i++)
    {
        if (l.info[i] == valor)
            return i;
    }
    return -1;
}
void insereListaClassificadaComRepeticao(Lista *l, int valor)
{
    int i, j;
    for (i = 0; i < l->qtOcupada; i++)
    {
        if (valor < l->info[i])
        {
            break;
        }
    }
    for (j = l->qtOcupada; j > i; j--)
    {
        l->info[j] = l->info[j - 1];
    }
    l->info[i] = valor;
    l->qtOcupada++;
}
void insereListaClassificadaSemRepeticao(Lista *l, int valor)
{
    int i, j;
    if (buscaValor(*l, valor) != -1)
    {
        printf("Valor ja existe na lista\n");
        return;
    }
    for (i = 0; i < l->qtOcupada; i++)
    {
        if (valor < l->info[i])
        {
            break;
        }
    }
    for (int j = l->qtOcupada; j > i; j--)
    {
        l->info[j] = l->info[j - 1];
    }
    l->info[i] = valor;
    l->qtOcupada++;
}
void insereListaNaoClassificadaComRepeticao(Lista *l, int valor)
{
    l->info[l->qtOcupada] = valor;
    l->qtOcupada++;
}
void insereListaNaoClassificadaSemRepeticao(Lista *l, int valor)
{
    int i;
    if (buscaValor(*l, valor) != -1)
    {
        printf("Valor ja existe na lista\n");
        return;
    }
    l->info[l->qtOcupada] = valor;
    l->qtOcupada++;
}
void insereLista(Lista *l, int valor)
{
    if (l->qtOcupada == l->capacidade)
    {
        printf("Lista cheia\n");
        return;
    }
    if (l->ehComRepeticao && l->ehClassificado)
    {
        insereListaClassificadaComRepeticao(l, valor);
        return;
    }
    if (l->ehClassificado && !l->ehComRepeticao)
    {
        insereListaClassificadaSemRepeticao(l, valor);
        return;
    }
    if (!l->ehClassificado && l->ehComRepeticao)
    {
        insereListaNaoClassificadaComRepeticao(l, valor);
        return;
    }
    if (!l->ehClassificado && !l->ehComRepeticao)
    {
        void insereListaNaoClassificadaSemRepeticao(l, valor);
        return;
    }
}
