#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "corredor.h"
void main(){
    int vNumPunidos[2] = {999, 333}
    tCorredor corred[9];
        corred[0].tempos.criarCorredor(&corred[0],222,"Buba" , (2, 30, 15), 0);
        corred[1].tempos.criarCorredor(&corred[1],999,"Nana" , (1, 31, 20), 420);
        corred[2].tempos.criarCorredor(&corred[2],666,"Lulu" , (1, 20, 40), 1200);
        corred[3].tempos.criarCorredor(&corred[3],777,"Vivi" , (2, 10, 12), 0);
        corred[4].tempos.criarCorredor(&corred[4],555,"Bola" , (2, 30, 15), 0);
        corred[5].tempos.criarCorredor(&corred[5],444,"Nino" , (1, 45, 20), 0);
        corred[6].tempos.criarCorredor(&corred[6],333,"Lala" , (1, 10, 40), 1800);
        corred[7].tempos.criarCorredor(&corred[7],888,"Joca" , (2, 10, 12), 5);
        corred[8].tempos.criarCorredor(&corred[8],111,"Bebe" , (1, 35, 15), 0);
        vencedorCorrida(corred, vNumPunidos, 2);
}