#include "corredor.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

time_t criarCorredor(tCorredor *c, int num, char nome[30], int horas, int minutos, int segundos, time_t punicao)
{
    c->num = num;
    strcpy(c->nome, nome);
    c->tempos.hora = horas;
    c->tempos.minuto = minutos;
    c->tempos.segundo = segundos;
    c->tempos.tempoProva = mktime(&c->tempos);
    c->tempos.punicao = punicao;
    return mktime(&c->tempos);
}
void aplicaPunicao(struct corredor *c)
{
    c->tempoFinal = soma_tempo(c->tempoCorredor, c->punicao);
}
int maisRapido(struct corredor corredor, struct corredor corredor2)
{
    if (corredor.tempoFinal < corredor2.tempoFinal)
        return 1;
    else
        return 0;
}
void vencedorCorrida(tCorredor *corredor, int *vNumPunidos, int qtpunidos)
{
    // aplica punicoes
    int i, j, k;
    for (i = 0, j = sizeof(vNumPunidos / vNumPunidos[0]); i < 9 || j >= 0; i++)
    {
        for (k = j; k >= 0; k--)
        {
            if (corredor[i].numPunidos == vNumPunidos[k])
            {
                printf("\n %s  -  punido\n", corredor[i].nome);
                aplicaPunicao(&corredor[i]);
                j--;
            }
        }
    }
    // ordena
    for (i = 0; i < 9; i++)
    {
        for (j = i + 1; j < 9; j++)
        {
            if (maisRapido(corredor[i], corredor[j]))
            {
                struct corredor aux = corredor[i];
                corredor[i] = corredor[j];
                corredor[j] = aux;
            }
        }
    }
    // imprime
    for (i = 0; i < 9; i++)
    {
        printf("\n %d° - %s  -  %d segundos\n", i + 1, corredor[i].nome, corredor[i].tempoFinal);
    }
}