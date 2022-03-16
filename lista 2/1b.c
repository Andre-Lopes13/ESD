#include <string.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
void preencheVetor(int *v , int n);
int produtoInterno(int *v1, int *v2, int n);
void imprimeVetor(int *v,int n);
int main(){
    int n, v1[100], v2[100];
    srand(time(NULL));
    printf("Digite o tamanho dos vetores: ");
    scanf("%d", &n);
    preencheVetor(v1, n);
    preencheVetor(v2, n);
    printf("Vetor 1: ");
    imprimeVetor(v1, n);
    printf("Vetor 2: ");
    imprimeVetor(v2, n);
    printf("O produto interno dos vetores eh: %d\n", produtoInterno(v1, v2, n));
    return 0;
}
void imprimeVetor(int *v, int n){
    int i;
    for(i = 0; i < n; i++){
        printf("%d ", v[i]);
    }
    printf("\n");
}
int produtoInterno(int *v1, int *v2, int n){
    int i, produto = 0;
    for(i = 0; i < n; i++){
        produto += v1[i] * v2[i];
    }
    return produto;
}
void preencheVetor(int *v , int n){
    int i;
    for(i = 0; i < n; i++){
        v[i] = rand() % 100;
    }
}