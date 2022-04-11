#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define C 4
void preencheMatrizAleatorio(int Matriz[][C], int n);
void imprimeMatrizSemDiagonalPrincipalESecundaria(int matriz[][C], int n);
void main()
{
    int n, i, j;
    printf("Digite o tamanho da matriz: ");
    scanf("%d", &n);
    int matriz[n][C];
    preencheMatrizAleatorio(matriz, n);
    imprimeMatrizSemDiagonalPrincipalESecundaria(matriz, n);
}
void preencheMatrizAleatorio(int matriz[][C], int n)
{
    int i, j;
    srand(time(NULL));
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < C; j++)
        {
            matriz[i][j] = rand() % 10;
        }
    }
}
void imprimeMatrizSemDiagonalPrincipalESecundaria(int matriz[][C], int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < C; j++)
        {
            if (i == j || j == n - 1 - i)
            {
                printf("- ");
            }
            else
            {
                printf("%d ", matriz[i][j]);
            }
                }
        printf("\n");
    }
}