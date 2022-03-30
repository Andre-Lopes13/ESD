#include "ponto.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void ptoCria(tPonto *pto, float x, float y)
{

    ptoAtribui(pto, x, y);
    return;
}
void ptoExibe(tPonto *pto)
{
    printf("(%.2f,%2.f)", pto->x, pto->y);
    return;
}
int ptoGetX(tPonto pto)
{
    return pto.x;
}
int ptoGetY(tPonto pto)
{
    return pto.y;
}
void ptoSetX(tPonto *pto, float valor)
{
    pto->x = valor;
}
void ptoSetY(tPonto *pto, float valor)
{
    pto->y = valor;
}
void ptoAtribui(tPonto *pto, float x, float y)
{
    ptoSetX(pto, x);
    ptoSetY(pto, y);
}
int ptoDistanciaMeu(tPonto pt1, tPonto pt2)
{
    return sqrt(pow(pt1.x - pt2.x, 2) + pow(pt1.y - pt2.y, 2));
}