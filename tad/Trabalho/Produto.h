#include "Data.h"
typedef struct produto Tproduto;
/* Interface desejada:
 Exibir
 estaNaValidade : retorna 1 se na data atual está na validade ou 0 caso contrário
 ehSemelhante: recebe outro Produto e retorna True se tem mesma identificação
 reajuste: recebe um valor percentual(x) e atualiza o preço em x%
 get para cada atributo
 set para cada atributo
 Saber se dois produtos são iguais: mesmos atributos */
void exibe(Tproduto p);
int estaNaValidade(Tproduto p);
int ehSemelhante(Tproduto p1, Tproduto p2);
void reajuste(Tproduto *p, float x);
char *getCodigo(Tproduto p);
char *getDataFabricacao(Tproduto p);
int getDiasValidade(Tproduto p);
float getPreco(Tproduto p);
void setCodigo(Tproduto *p, char *codigo);
void setDataFabricacao(Tproduto *p, char *data);
void setDiasValidade(Tproduto *p, int dias);
void setPreco(Tproduto *p, float preco);
int ehIgual(Tproduto p1, Tproduto p2);