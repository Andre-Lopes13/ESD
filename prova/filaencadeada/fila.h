typedef char elem;
typedef struct fila Fila;
Fila *Cria(int *flagErro);
void Esvazia(Fila *F, int *flagErro);
void Destroi(Fila *F, int *flagErro);
int Vazia(Fila *F, int *flagErro);
void Insere(Fila *F, elem X, int *erro);
void Remove(Fila *F, elem *X, int *erro);
void Inicio(Fila *F, elem *X, int *erro);
int Vazia(Fila *F, int *flagErro);
int Cheia(Fila *F, int *flagErro) ;
int Tamanho(Fila *F, int *flagErro);