#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
void main()
{
    Lista l = criaLista(10, 1, 1);
    // menu
    int opcao, valor;
    do
    {
        printf("1 - Inserir\n");
        printf("2 - Buscar\n");
        printf("3 - Sair\n");
        scanf("%d", &opcao);
        switch (opcao)
        {
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
            break;
        default:
            printf("Opcao invalida\n");
        }
    } while (opcao != 3);
}