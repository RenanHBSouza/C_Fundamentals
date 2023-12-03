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

Lista concatenar(Lista l1, Lista l2) {
    if (l1 == NULL) {
        return l2;
    }
    Lista atual = l1;
    while (atual->prox != NULL) {
        atual = atual->prox;
    }
    atual->prox = l2;
    return l1;
}




int main(){
    Lista l1, l2;
    l1 = criar_lista();
    l2 = criar_lista();
    int x;
    printf("Insira um valor para a lista 1(-1 para parar): ");
    scanf("%d", &x);
    while(x!=-1){
        l1 = adicionar_elemento(l1,x);
        printf("Insira um valor para a lista 1(-1 para parar): ");
        scanf("%d", &x);
    }
    imprime_elemento(l1);
    printf("Insira um valor para a lista 2(-1 para parar): ");
    scanf("%d", &x);
    while(x!=-1){
        l2 = adicionar_elemento(l2,x);
        printf("Insira um valor para a lista 2(-1 para parar): ");
        scanf("%d", &x);
    }
    imprime_elemento(l2);

    l1 = concatenar(l1,l2);    
    imprime_elemento(l1);
	finalizar_lista(l1);
    return 0;
}