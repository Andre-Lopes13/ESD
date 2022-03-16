/*Uma federação desportiva deseja manter atualizadas as informações sobre os recordes de
algumas modalidades de provas de natação. Para tanto, a federação possui um arquivo com os
atuais recordes do seguinte modo:
­ código da modalidade,
­ segundos do atual recorde na modalidade.
O desempenho dos nadadores que participaram do último campeonato será informado a seguir, do
seguinte modo:
­ código da modalidade, minutos, segundos.
Faça um programa que, baseado nestas informações, verifique se algum recorde foi batido. Neste
caso, o recorde anterior deverá ser substituído. Ao final, o programa deve exibir as informações
ordenadas por código da modalidade.*/
#include <stdio.h>
#define TAM 10
typedef struct{
    int minutos;
    int segundos;
} Tempo;
typedef struct
{
    int codigo;
    Tempo recorde;
} Recordes;
int verificaRecorde(Recordes *recordes, int codigo, Tempo novoTempo);
void ordenaRecorde(Recordes *recordes, int posicaoNovorecorde, Tempo novoTempo);
int verificaRecorde(Recordes *recordes, int codigo, Tempo novoTempo){
    int i;
    for(i = 10; i >= 0 ; i--){
        if(recordes[i].codigo == codigo){
            if(recordes[i].recorde.minutos > novoTempo.minutos ||
            (recordes[i].recorde.minutos == novoTempo.minutos && recordes[i].recorde.segundos > novoTempo.segundos)){
                ordenaRecorde(recordes, i, novoTempo);
                return 1;
            }
        }
    }
    return 0;
}
void ordenaRecorde(Recordes *recordes, int posicaoNovorecorde, Tempo novoTempo){
    // insertion sort
    int i, j;
    Recordes aux;
    for(i = posicaoNovorecorde; i > 0; i--){
        if(recordes[i].recorde.minutos < recordes[i-1].recorde.minutos ||
        (recordes[i].recorde.minutos == recordes[i-1].recorde.minutos && recordes[i].recorde.segundos < recordes[i-1].recorde.segundos)){
            aux = recordes[i];
            for(j = i; j < posicaoNovorecorde; j++){
                recordes[j] = recordes[j+1];
            }
            recordes[posicaoNovorecorde] = aux;
        }
    }
}