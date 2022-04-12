/* tad basico de operações de lista simples */
typedef struct lista
{
    int *info;
    int qtOcupada;
    int capacidade;
    int ehClassificado;
    int ehComRepeticao;
} Lista;
// funcao cria lista vazia
Lista criaLista(int capacidade, int ehClassificado, int ehComRepeticao);
// funcao buscar valor na lista
int buscaValor(Lista l, int valor);
// imprime valores da lista
void imprimeLista(Lista l);
// funcao insere valor na lista de 4 formas
void insereLista(Lista *l, int valor);
// classificada com repetição
void insereListaClassificadaComRepeticao(Lista *l, int valor);
// classificada sem repetição
void insereListaClassificadaSemRepeticao(Lista *l, int valor);
// nao classificada com repetição
void insereListaNaoClassificadaComRepeticao(Lista *l, int valor);
// nao classificada sem repetição
void insereListaNaoClassificadaSemRepeticao(Lista *l, int valor);