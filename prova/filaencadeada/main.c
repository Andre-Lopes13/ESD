/* teste main fila */
#include <stdio.h>
#include <stdlib.h>
#include "fila.h"
int main()
{
    Fila *f = cria();
    // menu hashing
    int opcao;
    int flagErro = 0;
    do
    {
        printf("\n\nMenu:\n");
        printf("1 - Inserir elemento na fila\n");
        printf("2 - Remover elemento da fila\n");
        printf("3 - Imprime Fila\n");
        printf("0 - Sair\n");
        printf("\nDigite a opcao: ");
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            printf("\nDigite o elemento a ser inserido: ");
            int elem;
            scanf("%d", &elem);
            insere(f, elem);
            break;
        case 2:
            removeNo(f);
            printf("\n Elemento removido\n");
            break;
        case 3:
            imprime(f);
            break;
        case 0:
            printf("\n Saindo do programa\n");
            break;
        default:
            printf("\n Opcao invalida\n");
            break;
        }
    } while (opcao != 0);
}