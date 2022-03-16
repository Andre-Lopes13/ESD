#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define C 100
void preencheMatrizAleatorio(int matriz[][C], int linhas, int colunas);
void geraTransposta (int mOrigem[][C], int mTransposta[][C], int linhas, int colunas);
void imprimeMatriz(int matriz[][C], int linhas, int colunas);
int main()
{
    int matriz[C][C], matrizTransposta[C][C], linhas, colunas;
    printf("Digite o tamanho da matriz: ");
    printf("\nLinhas: ");
    scanf("%d", &linhas);
    printf("Colunas: ");
    scanf("%d", &colunas);
    preencheMatrizAleatorio(matriz, linhas, colunas);
    geraTransposta(matriz, matrizTransposta, linhas, colunas);
    printf("\n Matriz original: \n");
    imprimeMatriz(matriz, linhas, colunas);
    printf("\n Matriz transposta: \n");
    imprimeMatriz(matrizTransposta, colunas, linhas);
    return 0;
}
void geraTransposta (int mOrigem[][C], int mTransposta[][C], int linhas, int colunas)
{
    int i, j;
    for (i = 0; i < linhas; i++)
    {
        for (j = 0; j < colunas; j++)
        {
            mTransposta[j][i] = mOrigem[i][j];
        }
    }
}
void imprimeMatriz(int matriz[][C], int linhas, int colunas)
{
    int i, j;
    for (i = 0; i < linhas; i++)
    {
        for (j = 0; j < colunas; j++)
        {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

void preencheMatrizAleatorio(int matriz[][C], int linhas, int colunas)
{
    int i, j;
    srand(time(NULL));
    for (i = 0; i < linhas; i++)
    {
        for (j = 0; j < colunas ; j++)
        {
            matriz[i][j] = rand() % 10;
        }
    }
}