/* tad lse classificada sem repetição */
typedef struct lse {
    int info;
    struct lse *prox;
} LSE;
/* funções basicas */ 
LSE *cria_lse(void);
void libera_lse(LSE *l);	
int consulta_lse(LSE *l, int elem);