/*
NOME: Andre Lopes Nascimento dos Santos
TURMA: A noite
*/
struct lista {
    int info;
    struct lista *prox;
}Tlista;
lista uniao(lista l1, lista l2) {
    lista l3 = NULL;
    lista aux = l1;
    while (aux != NULL) {
        l3 = insere(l3, aux->info);
        aux = aux->prox;
    }
    aux = l2;
    while (aux != NULL) {
        l3 = insere(l3, aux->info);
        aux = aux->prox;
    }
    return l3;
}