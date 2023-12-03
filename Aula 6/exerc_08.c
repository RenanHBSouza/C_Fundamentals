//Renan Henrique Barreiro Souza         RA: 11202130682
#include <stdio.h>
#include <stdlib.h>

typedef struct no* Lista;
struct no{
    int dado;
    Lista prox;
};

Lista criar_lista(){
    return NULL;
}

Lista adicionar_elemento(Lista l, int x){
    Lista novo;
    novo = malloc(sizeof(struct no));
    if(novo==NULL){
        printf("Memoria insuficiente!");
        exit(1);
    }
    novo->dado = x;
    novo->prox = l;
    return novo;
}

void imprime_elemento(Lista l){
    if(l != NULL){
        printf("%d ", l->dado);
        imprime_elemento(l->prox);
    }
    else{
        printf("\n");
    }
    return;
}

void finalizar_lista(Lista l){
    if(l != NULL){
        finalizar_lista(l->prox);
        free(l);
    }
    return;
}

Lista inverterRecursivo(Lista atual, Lista anterior) {
    if (atual == NULL) {
        return anterior; // Retorna o novo início da lista
    }

    Lista proximo = atual->prox;
    atual->prox = anterior;

    // Chama recursivamente para o próximo nó
    return inverterRecursivo(proximo, atual);
}




int main(){
    Lista l1, invert;
    l1 = criar_lista();
    invert = (Lista)malloc(sizeof(struct no));
    int x;
    printf("Insira um valor para a lista 1(-1 para parar): ");
    scanf("%d", &x);
    while(x!=-1){
        l1 = adicionar_elemento(l1,x);
        printf("Insira um valor para a lista 1(-1 para parar): ");
        scanf("%d", &x);
    }
    imprime_elemento(l1);

    invert = inverterRecursivo(l1,NULL);  
    imprime_elemento(invert);
    finalizar_lista(invert);
    return 0;
}