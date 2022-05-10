/* teste main */ 
#include <stdio.h>
#include <stdlib.h>
#include "pilhaencadeada.h"
int main()
{
    TPilha *p = cria();
    // menu hashing
    int opcao;
    do
    {
        printf("\n\nMenu:\n");
        printf("1 - Inserir elemento na pilha\n");
        printf("2 - Remover elemento da pilha\n");
        printf("3 - Imprime Pilha\n");
        printf("0 - Sair\n");
        printf("\nDigite a opcao: ");
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            printf("\nDigite o elemento a ser inserido: ");
            int elem;
            scanf("%d", &elem);
            insere(p, elem);
            break;
        case 2:
            removeNo(p);
            printf("\n Elemento removido\n");
            break;
        case 3:
            imprime(p);
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