#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct
{
    int min;
    int seg;
} tTempo;
typedef struct
{
    int codModal;
    char nome[40];
    tTempo desempenho;
} tNadador;
typedef struct
{
    int codModal;
    tNadador recorde;
} tModalidade;

int preenche(tModalidade *recordes, int n);
void obtemNadador(tNadador *nadador);
int busca(tModalidade *recordes, int n, int codigo);
void ordenar(tModalidade *recordes, int n);
void exibir(tModalidade *recordes, int n);
void main()
{
    tModalidade vRecordes[5];
    tNadador nadador;
    int qt;
    int i;
    int pos;

    qt = preenche(vRecordes, 5); // ler os dados do arquivo jogando no vetor
    for (i = 0; i < 2; i++)
    {
        obtemNadador(&nadador); // nadador = ObtemNadador()
        pos = busca(vRecordes, qt, nadador.codModal); // pos = Busca(vRecordes, qt, nadador.desempenho.codModal)
        if (pos != -1)
        {
            if (nadador.desempenho.min < vRecordes[pos].recorde.desempenho.min ||
                (nadador.desempenho.min == vRecordes[pos].recorde.desempenho.min &&
                    nadador.desempenho.seg < vRecordes[pos].recorde.desempenho.seg))
            {
                vRecordes[pos].recorde = nadador;
                ordenar(vRecordes, qt);
            }
        }
    }
    ordenar(vRecordes, qt);
    exibir(vRecordes, qt);
    return 0;
}
void ordenar(tModalidade *recordes, int n){
    // insertion
    int i, j;
    tModalidade aux;
    for(i = 1; i < n; i++){
        aux = recordes[i];
        for ( j = i-1 ; j >= 0 && aux.codModal < recordes[i].codModal; j--)
        {
            recordes[j+1] = recordes[j];
        }
        recordes[j+1] = aux;
    }
}

int preenche(tModalidade *recordes, int n)
{
    int i;
    char controle;
    for ( i = 0; i < n && controle != 'N'; i++)
    {
        printf("\nDigite o codigo da modalidade: ");
        scanf("%d", &recordes[i].codModal);
        printf("\nDigite o tempo: ");
        printf("\nMinutos: ");
        scanf("%d", &recordes[i].recorde.desempenho.min);
        printf("\nSegundos: ");
        scanf("%d", &recordes[i].recorde.desempenho.seg);
        printf("\n \n nome do nadador : ");
        scanf("%s", recordes[i].recorde.nome);
        fflush(stdin);
        printf("deseja continuar? (S/N)");
        scanf("%c", &controle);
        fflush(stdin);
        controle = toupper(controle);
        system("cls");
    }
    printf("\n");
    printf(" fim da leitura , saindo ... ");
    system("cls");
    return i;
}
void obtemNadador(tNadador *nadador)
{
    printf(" \n Inserindo novo tempo de nadador \n");
    printf("\n nome : ");
    scanf("%s", nadador->nome);
    printf("\n modalidade : ");
    scanf("%d", &nadador->codModal);
    printf("\n minutos : ");
    scanf("%d", &nadador->desempenho.min);
    printf("\n segundos : ");
    scanf("%d", &nadador->desempenho.seg);
    system("cls");
}
int busca(tModalidade *recordes, int n, int codigo)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (recordes[i].codModal == codigo)
        {
            return i;
        }
    }
    return -1;
}
void exibir(tModalidade *recordes, int n){
    int i;
    printf("\n");
    printf("**************************RECORDES**************************");
    for (i = 0; i < n; i++)
    {
       printf(" \n Modalidade codigo : %d", recordes[i].codModal);
       printf(" \n Nome : %s", recordes[i].recorde.nome);
       printf(" \n Tempo : %.2d:%.2d", recordes[i].recorde.desempenho.min, recordes[i].recorde.desempenho.seg);
    }
}