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
        insereListaNaoClassificadaSemRepeticao(l, valor);
        return;
    }
}
void imprimeLista(Lista l)
{
    for (int i = 0; i < l.qtOcupada; i++)
    {
        printf("%d ", l.info[i]);
    }
    printf("\n");
}
void exclusaoOpcoes(Lista *l, int valor)
{
    int opc;
    printf("1 - Excluir todos os valores iguais a %d \n", valor);
    printf("2 - Excluir primeira ocorrencia de %d \n", valor);
    printf("3 - Excluir aleatoriamente com busca binaria \n");
    scanf("%d", &opc);
    do
    {
        switch (opc)
        {
        case 1:
            excluiTodasOcorrencias(l, valor);
            break;
        case 2:
            excluiPrimeiraOcorrencia(l, valor);
            break;
        case 3:
            excluiPrimeiraOcorrenciaBinaria(l, valor);
            break;
        default:
            printf("Opcao invalida\n");
            break;
        }
    } while (opc <= 1 && opc >= 3);
}
void excluiPrimeiraOcorrencia(Lista *l, int valor)
{
    if (l->ehClassificado)
    {
        for (int i = 0; i < l->qtOcupada; i++)
        {
            if (l->info[i] == valor)
            {
                for (; i <= l->qtOcupada; i++)
                {
                    l->info[i] = l->info[i + 1];
                }
                l->qtOcupada--;
                break;
            }
        }
    }
    else
    {
        for (int i = 0; i < l->qtOcupada; i++)
        {
            if (l->info[i] == valor)
            {
                l->info[i] = l->info[l->qtOcupada];
                l->qtOcupada--;
                break;
            }
        }
    }
}
void excluiTodasOcorrencias(Lista *l, int valor)
{
    if (l->ehClassificado)
    {
        for (int i = 0; i < l->qtOcupada; i++)
        {
            if (l->info[i] == valor)
            {
                for (; i <= l->qtOcupada; i++)
                {
                    l->info[i] = l->info[i + 1];
                }
                l->qtOcupada--;
            }
        }
    }
    else
    {
        for (int i = 0; i < l->qtOcupada; i++)
        {
            if (l->info[i] == valor)
            {
                while (l->qtOcupada >= i && l->info[l->qtOcupada-1] == valor)
                {
                    l->qtOcupada--;
                }
                l->info[i] = l->info[l->qtOcupada];
                l->qtOcupada--;
            }
        }
    }
}
void excluiPrimeiraOcorrenciaBinaria(Lista *l, int valor)
{
    // busca binaria
    int i = 0;
    int j = l->qtOcupada - 1;
    int k;
    if (l->ehClassificado)
    {
        while (i <= j)
        {
            k = (i + j) / 2;
            if (l->info[k] == valor)
            {
                for (; k <= l->qtOcupada; k++)
                {
                    l->info[k] = l->info[k + 1];
                }
                l->qtOcupada--;
                break;
            }
            if (l->info[k] < valor)
            {
                i = k + 1;
            }
            else
            {
                j = k - 1;
            }
        }
    }
    else
    {
        while (i <= j)
        {
            k = (i + j) / 2;
            if (l->info[k] == valor)
            {
                l->info[k] = l->info[l->qtOcupada];
                l->qtOcupada--;
                break;
            }
            if (l->info[k] < valor)
            {
                i = k + 1;
            }
            else
            {
                j = k - 1;
            }
        }
    }
}