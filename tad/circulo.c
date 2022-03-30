#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "circulo.h"
void criaCirculo(tCirculo *circulo, tPonto pto, float raio)
{
    ptoAtribui(&circulo->centro, pto.x, pto.y);
    circulo->raio = raio;
}
void exibeCirculo(tCirculo circulo)
{
    printf("Centro: (%.2f, %.2f)\n", circulo.centro.x, circulo.centro.y);
    printf("Raio: %.2f\n", circulo.raio);
}
float calculaArea(tCirculo *circulo)
{
    return M_PI * pow(circulo->raio, 2);
}
float calculaPerimetroCirculo(tCirculo *circulo)
{
    return 2 * M_PI * circulo->raio;
}
float calculaDistancia(tCirculo *circulo1, tCirculo *circulo2)
{
    return sqrt(pow(circulo1->centro.y - circulo2->centro.x, 2) + pow(circulo1->centro.y - circulo2->centro.x, 2));
}
int comparaTamanhoCirculo(tCirculo *circulo1, tCirculo *circulo2)
{
    if (circulo1->raio == circulo2->raio)
    {
        return 0;
    }
    else
    {
        if (circulo1->raio > circulo2->raio)
        {
            return 1;
        }
        else
        {
            return -1;
        }
    }
}
void clonaCirculo(tCirculo *circulo1, tCirculo circulo2)
{
    circulo1->centro.x = circulo2.centro.x;
    circulo1->centro.y = circulo2.centro.y;
    circulo1->raio = circulo2.raio;
}
