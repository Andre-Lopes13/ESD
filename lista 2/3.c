#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define T 6
void imprimeMatriz(int matriz[T][T]);
void preencheDiagonalInferiorAleatorio(int matriz[T][T]);
void main()
{
    int matriz[T][T];
    int i, j;
    srand(time(NULL));
    preencheDiagonalInferiorAleatorio(matriz);
    imprimeMatriz(matriz);
}
void imprimeMatriz(int matriz[T][T])
{
    int i, j;
    for (i = 0; i < T; i++)
    {
        for (j = 0; j < T; j++)
        {
            printf("%.2d ", matriz[i][j]);
        }
        printf("\n");
    }
}
void preencheDiagonalInferiorAleatorio(int matriz[T][T])
{
    int i, j;
    for (i = 0; i < T; i++)
    {
        for (j = 0; i >= j; j++)
        {
            if (i == j)
            {
                matriz[i][j] = 0;
            }
            else
            {
                matriz[i][j] = rand() % 100;
                matriz[j][i] = matriz[i][j];
            }
        }
    }
}
