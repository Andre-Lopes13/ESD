#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tempo.h"
#define SEGUNDOS_EM_UM_DIA 86400

time_t ler_tempo(const char data[11])
{
    struct tm tm = {0};
    sscanf(data, "%d/%d/%d", &tm.tm_mday, &tm.tm_mon, &tm.tm_year);
    tm.tm_mon--;
    tm.tm_year -= 1900;
    return mktime(&tm);
}
time_t soma_tempo(time_t t1, time_t t2)
{
    return t1 + t2;
}
time_t subtrai_tempo(struct tempo t1, struct tempo t2)
{
    return t1.tempo - t2.tempo / SEGUNDOS_EM_UM_DIA;
}
void escrever_data(char *buf, size_t len, time_t data)
{
    struct tm *tm = localtime(&data);
    buf[0] = '\0';
    sprintf(buf, "%02d/%02d/%04d",
            tm->tm_mday,
            tm->tm_mon + 1,
            tm->tm_year + 1900);
}