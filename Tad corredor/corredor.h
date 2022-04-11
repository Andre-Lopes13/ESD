#include "tempo.h"
#include <time.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct corredor
{
    int num;
    char nome[30];
    tm tempo;
    time_t punicao;
} tCorredor;
time_t criarCorredor(tCorredor *c, int num, char nome[30], int horas, int minutos, int segundos, time_t punicao);
void aplicaPunicao(tCorredor *corredor);
int maisRapido(tCorredor corredor, tCorredor corredor2);
void vencedorCorrida(tCorredor *corredor, int *vNumPunidos, int qtpunidos);