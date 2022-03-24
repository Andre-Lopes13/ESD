#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "circulo.h"
tCirculo criaCirculo( float x, float y, float raio){
    tCirculo circulo;
    circulo.x = x;
    circulo.y = y;
    circulo.raio = raio;
    return circulo;
}
void exibeCirculo(tCirculo *circulo){
    printf("Centro: (%f, %f)\n", circulo->x, circulo->y);
    printf("Raio: %f\n", circulo->raio);
}
void alteraCirculo(tCirculo *circulo, float x, float y, float raio){
    circulo->x = x;
    circulo->y = y;
    circulo->raio = raio;
}
void acessaCirculo(tCirculo *circulo, float *x, float *y){
    *x = circulo->x;
    *y = circulo->y;
}
float calculaArea(tCirculo *circulo){
    return M_PI * pow(circulo->raio, 2);
}
float calculaPerimetroCirculo(tCirculo *circulo){
    return 2 * M_PI * circulo->raio;
}
float calculaDistancia(tCirculo *circulo1, tCirculo *circulo2){
    return sqrt(pow(circulo1->x - circulo2->x, 2) + pow(circulo1->y - circulo2->y, 2));
}
int comparaCirculo(tCirculo *circulo1, tCirculo *circulo2){
    if(calculaDistancia(circulo1, circulo2) < 0.1){
        return 1;
    }else{
        return 0;
    }
}
void clonaCirculo(tCirculo *circulo1, tCirculo *circulo2){
    circulo2->x = circulo1->x;
    circulo2->y = circulo1->y;
    circulo2->raio = circulo1->raio;
}
