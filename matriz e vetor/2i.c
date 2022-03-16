#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int verificaSeMatrizESimetrica(int m[100][100], int linhas, int colunas);
void preencheMatrizAleatorio(int m[100][100], int linhas, int colunas);
void main()
{
    int linhas = 4,colunas = 4;
    /*printf("Digite o tamanho da matriz: ");
    scanf("%d", &linhas);
    scanf("%d", &colunas);*/
    int m[100][100] = {{0, 1, 2, 3},
                        {1, 0, 1, 2},
                        {2, 1, 0, 1},
                        {3, 2, 1, 0}};
    //preencheMatrizAleatorio(m, 4, 4);
    if (verificaSeMatrizESimetrica(m, 4, 4))
    {
        printf("A matriz e simetrica");
    }
    else
    {
        printf("A matriz nao e simetrica");
    }
}
void preencheMatrizAleatorio(int m[100][100], int linhas, int colunas)
{
    int i, j;
    srand(time(NULL));
    for (i = 0; i < linhas; i++)
    {
        for (j = 0; j < colunas; j++)
        {
            m[i][j] = rand() % 10;
        }
    }
}
int verificaSeMatrizESimetrica(int m[100][100], int linhas, int colunas)
{
    int i, j;
    for (i = 0; i < linhas; i++)
    {
        for (j = i + 1; j < colunas; j++)
        {
            if (m[i][j] != m[j][i])
            {
                return 0;
            }
        }
    }
    return 1;
}