/* tad lse classificada sem repetição */
typedef struct bloco no;
typedef struct lista Lista;
Lista *Cria(int *flagErro);
void InsereOrdenadoSemRepeticao(Lista *L, int x, int *flagErro);
void Remove(Lista *L, int *x, int *flagErro);
void Destroi(Lista *L, int *flagErro);
void Imprime(Lista *L);
int Vazia(Lista *L);
int Tamanho(Lista *L);
int Cheia(Lista *L);
int BuscaBinaria(Lista *L, int x);
void InsereInicio(Lista *L, int x, int *flagErro);
void InsereFim(Lista *L, int x, int *flagErro);
void RemoveInicio(Lista *L, int *x, int *flagErro);
void RemoveFim(Lista *L, int *x, int *flagErro);