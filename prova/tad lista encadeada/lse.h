/* tad lse classificada sem repetição */
typedef struct bloco no;
typedef struct lista Lista;
Lista *Cria();
void Insere(Lista *L, int x);
void exclui(Lista *L, int x);
void imprime(Lista *L);
no buscaBinaria(Lista l, int valor);
void insereListaClassificadaComRepeticao(Lista *l, int valor);
// classificada sem repetição
void insereListaClassificadaSemRepeticao(Lista *l, int valor);
// nao classificada com repetição
void insereListaNaoClassificadaComRepeticao(Lista *l, int valor);
// nao classificada sem repetição
void insereListaNaoClassificadaSemRepeticao(Lista *l, int valor);
void excluiPrimeiraOcorrencia(Lista *l, int valor);
// exclui valor da lista todas as ocorrências
void excluiTodasOcorrencias(Lista *l, int valor);
// exclui primeira ocorrencia busca binária;
void excluiPrimeiraOcorrenciaBinaria(Lista *l, int valor);
