#include <stdio.h>
#include <stdlib.h>
#include "ponto.h"
typedef struct circulo
{
    tPonto centro;
    float raio;
} tCirculo;
void criaCirculo(tCirculo *circulo, tPonto pto, float raio);
void exibeCirculo(tCirculo circulo);
float calculaArea(tCirculo *circulo);
float calculaPerimetroCirculo(tCirculo *circulo);
float calculaDistancia(tCirculo *circulo1, tCirculo *circulo2);
int comparaTamanhoCirculo(tCirculo *circulo1, tCirculo *circulo2);
void clonaCirculo(tCirculo *circulo1, tCirculo circulo2);