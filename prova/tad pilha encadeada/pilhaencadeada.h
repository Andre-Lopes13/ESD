/* tad pilha encadeada */
typedef struct bloco no;
typedef struct pilha TPilha;
TPilha *cria();
void insere(TPilha *P, int X);
void removeNo(TPilha *P);
void imprime(TPilha *P);

