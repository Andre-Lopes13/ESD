#include "circulo.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
void main(){
    tCirculo circulo1 = criaCirculo(1, 1, 1);
    tCirculo circulo2 = criaCirculo(2, 2, 2);
    exibeCirculo(&circulo1);
    exibeCirculo(&circulo2);
    alteraCirculo(&circulo1, 7, 8, 9);
    alteraCirculo(&circulo2, 10, 11, 12);
    exibeCirculo(&circulo1);
    exibeCirculo(&circulo2);
    printf("%f\n", calculaArea(&circulo1));
    printf("%f\n", calculaPerimetroCirculo(&circulo1));
    printf("%f\n", calculaDistancia(&circulo1, &circulo2));
    comparaCirculo(&circulo1, &circulo2)>0?printf("Circulos iguais\n"):printf("Circulos diferentes\n");
    clonaCirculo(&circulo1, &circulo2);
    exibeCirculo(&circulo2);
}