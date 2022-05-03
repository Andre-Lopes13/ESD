#include "Produto.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Data.h"
#include <time.h>
void main(){
    // menu -
    // 1 - cria produto
    // 2 - exibe produto
    // 3 - verifica se esta na validade
    // 4 - verifica se eh semelhante
    // 5 - reajuste
    // 6 - get codigo
    // 7 - get data fabricacao
    // 8 - get dias validade
    // 9 - get preco
    // 10 - set codigo
    // 11 - set data fabricacao
    // 12 - set dias validade
    // 13 - set preco
    // 14 - sair
    int opcao;
    Tproduto p;
    char codigo[10];
    char dataFabricacao[10];
    int diasValidade;
    float preco;
    do
    {
        // opcoes do menu
        printf("1 - cria produto\n");
        printf("2 - exibe produto\n");
        printf("3 - verifica se esta na validade\n");
        printf("4 - verifica se eh semelhante\n");
        printf("5 - reajuste\n");
        printf("6 - insere codigo\n");
        printf("7 - insere data fabricacao\n");
        printf("8 - insere dias validade\n");
        printf("9 - insere preco\n");
        printf("10 - traz codigo\n");
        printf("11 - traz data fabricacao\n");
        printf("12 - traz dias validade\n");
        printf("13 - traz preco\n");

        switch (opcao)
        {
        case -1:
            printf("Saindo \n");
                break;
        case 1:
            criaProduto(&p);
            break;
        case 2:
            exibeProduto(p);
            break;
        case 3:   
            if (estaNaValidade(p))
                printf("Produto esta na validade\n");
            else
                printf("Produto nao esta na validade\n");
            break;
        case 4:
            if (ehSemelhante(p, p))
                printf("Produtos sao semelhantes\n");
            else
                printf("Produtos nao sao semelhantes\n");
            break;
        case 5:
            reajuste(&p, 10);
            break;
        case 6: 
            strcpy(codigo, getCodigo(p));
            printf("Codigo: %s\n", codigo);
            break;
        case 7:
            strcpy(dataFabricacao, getDataFabricacao(p));
            printf("Data de fabricacao: %s\n", dataFabricacao);
            break;
        case 8:
            diasValidade = getDiasValidade(p);
            printf("Dias de validade: %d\n", diasValidade);
            break;
        case 9:
            preco = getPreco(p);
            printf("Preco: %.2f\n", preco);
            break;
        case 10:
            setCodigo(&p, codigo);
            break;
        case 11:
            setDataFabricacao(&p, dataFabricacao);
            break;
        case 12:
            setDiasValidade(&p, diasValidade);
            break;
        case 13:
            setPreco(&p, preco);
            break;
        default:
            printf("Opcao invalida\n");
            break;
        }
    } while (opcao != -1);
    

}