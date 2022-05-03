/*
NOME: Andre Lopes Nascimento dos Santos
TURMA: A noite
*/
#include "Produto.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Data.h"
#include <time.h>
typedef struct produto
{
    char *id;
    char *codBarras;
    data dataValidade;
    int diasDeValidade;
    float preco;
} Tproduto;
// funções auxiliares
Tdata retornaDataAtual(){
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    Tdata data;
    data.dia = tm.tm_mday;
    data.mes = tm.tm_mon + 1;
    data.ano = tm.tm_year + 1900;
    return data;
}
void exibe(Tproduto p)
{
    printf("%s\n", p.id);
    printf("Codigo de barras: %s\n", p.codBarras);
    printf("Data de validade: %s\n", p.dataValidade.data);
    printf("Dias de validade: %d\n", p.diasDeValidade);
    printf("Preco: %.2f\n", p.preco);
}

int estaNaValidade(Tproduto p)
{
    if (p.diasDeValidade > 0)
        return 1;
    else
        return 0;
}
int ehSemelhante(Tproduto p1, Tproduto p2)
{
    if (strcmp(p1.id, p2.id) == 0)
        return 1;
    else
        return 0;
}
void reajuste(Tproduto *p, float x)
{
    p->preco *= (1 + x / 100);
}
char *getCodigo(Tproduto p)
{
    return p.id;
}
char *getDataFabricacao(Tproduto p)
{
    return p.dataValidade.data;
}
int getDiasValidade(Tproduto p)
{
    return p.diasDeValidade;
}
float getPreco(Tproduto p)
{
    return p.preco;
}
void setCodigo(Tproduto *p, char *codigo)
{
    p->id = codigo;
}
void setDataFabricacao(Tproduto *p, data data)
{
    p->dataValidade.data = data;
}
void setDiasValidade(Tproduto *p, int dias)
{
    p->diasDeValidade = dias;
}
void setPreco(Tproduto *p, float preco)
{
    p->preco = preco;
}
int ehIgual(Tproduto p1, Tproduto p2)
{
    if (strcmp(p1.id, p2.id) == 0 && strcmp(p1.codBarras, p2.codBarras) == 0 && p1.diasDeValidade == p2.diasDeValidade && p1.preco == p2.preco)
        return 1;
    else
        return 0;
}
// funções de criação
void criaProduto(Tproduto *p, char *id, char *codBarras, char *dataFabricacao, int diasValidade, float preco)
{
    p->id = id;
    p->codBarras = codBarras;
    p->dataValidade.data = dataFabricacao;
    p->diasDeValidade = diasValidade;
    p->preco = preco;
}