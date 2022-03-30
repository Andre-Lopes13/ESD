#include <stdio.h>
#include <stdlib.h>
#include "circulo.h"
void main()
{
    tPonto ponto1;
    tCirculo circulo;
    ponto1.x = 3;
    ponto1.y = 4;
    criaCirculo(&circulo, ponto1, 10.0);
    exibeCirculo(circulo);
    exibeCirculo(circulo);
    printf("Area: %.2f\n", calculaArea(&circulo));
    printf("Perimetro: %.2f\n", calculaPerimetroCirculo(&circulo));
    printf("Distancia: %.2f\n", calculaDistancia(&circulo, &circulo));
    if (!comparaTamanhoCirculo(&circulo, &circulo))
    {
        printf("Circulos iguais\n");
    }
    else
    {
        printf("Circulos diferentes\n");
    }
    tCirculo circulo2;
    clonaCirculo(&circulo, circulo2);
    exibeCirculo(circulo2);
}