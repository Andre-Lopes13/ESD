#include <time.h>
typedef struct tempo
{
    int hora;
    int minuto;
    int segundo;
    time_t tempoProva;
    time_t punicao;
    time_t totalTempo;
} tm;
time_t ler_tempo(const char data[11]);
time_t soma_tempo(time_t t1, time_t t2);
time_t subtrai_tempo(struct tempo t1, struct tempo t2);
void escrever_data(char *buf, size_t len, time_t data);
