/* tad pilha encadeada */
typedef struct tipoitem TipoItem;
typedef struct tipopilha TipoPilha;
TipoPilha *inicializaPilha();
void fPVazia(TipoPilha *Pilha);
int vazia(TipoPilha *Pilha);
void empilha(TipoItem *x, TipoPilha *Pilha);
void desempilha(TipoPilha *Pilha, TipoItem *
                                      Item);
int tamanho(TipoPilha *Pilha);
TipoItem *inicializaTipoItem(TipoChave n);
void imprime(TipoPilha *pilha);