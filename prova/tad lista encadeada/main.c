#include <stdio.h>
#include <stdlib.h>
#include "lse.h"
void main()
{
    lista l;
    // menu cria lista;
    inicializa(&l);
    // menu
    int opcao, valor;
    do
    {
        printf("1 - Inserir\n");
        printf("2 - Buscar\n");
        printf("3 - imprimir lista\n");
        printf("4 - excluir\n");
        printf("-1 - Sair\n");
        scanf("%d", &opcao);
        switch (opcao)
        {
        case -1:
            break;
        case 1:
            printf("Valor: ");
            scanf("%d", &valor);
            insereLista(&l, valor);
            break;
        case 2:
            printf("Valor: ");
            scanf("%d", &valor);
            int pos = buscaValor(l, valor);
            if (pos == -1)
                printf("Valor nao encontrado\n");
            else
                printf("Valor encontrado na posicao %d\n", pos);
            break;
        case 3:
            imprimeLista(l);
            break;
        case 4:
            printf("Valor: ");
            scanf("%d", &valor);
            exclusaoOpcoes(&l, valor);
            break;
        default:
            printf("Opcao invalida\n");
        }
    } while (opcao != -1);
}