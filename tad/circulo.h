#include <stdio.h>
#include <stdlib.h>
typedef struct circulo{
    float x;
    float y;
    float raio; 
}tCirculo;
tCirculo criaCirculo( float x, float y, float r);
void exibeCirculo(tCirculo *circulo);
void alteraCirculo(tCirculo *circulo, float x, float y, float r);
void acessaCirculo(tCirculo *circulo, float *x, float *y);
float calculaArea(tCirculo *circulo);
float calculaPerimetroCirculo(tCirculo *circulo);
float calculaDistancia(tCirculo *circulo1, tCirculo *circulo2);
int comparaCirculo(tCirculo *circulo1, tCirculo *circulo2);
void clonaCirculo(tCirculo *circulo1, tCirculo *circulo2);