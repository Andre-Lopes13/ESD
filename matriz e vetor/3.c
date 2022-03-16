#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define T 6
void imprimeMatriz(int matriz[T][T]);
void preencheDiagonalInferiorAleatorio(int matriz[T][T]);
int calculaDistancias(int mat[][6], int vCid[], int n); 
void main()
{
    int matriz[T][T];
    int vCid[T]={0,1,2,3,4,5};
    int i, j;
    srand(time(NULL));
    preencheDiagonalInferiorAleatorio(matriz);
    imprimeMatriz(matriz);
    printf("\n");
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
int calculaDistancias(int mat[][6], int vCid[], int n)
{
    int soma;
    int indVet;
    int linha;
    int coluna;
    soma = 0;
    for (indVet = 0; indVet < n - 1; indVet++)
    {
        linha = vCid[indVet] - 1;
        coluna = vCid[indVet + 1] - 1;
        soma += mat[linha][coluna];
    }
    return soma;
}