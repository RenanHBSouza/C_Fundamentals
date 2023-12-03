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

void insert(Lista* l, int x){
    Lista novo;
    novo = malloc(sizeof(struct no));
    if(novo==NULL){
        printf("Memoria insuficiente!");
        exit(1);
    }
    novo->dado = x;
    novo->prox = *l;
    *l = novo;
    return;
}

void destruir_lista(Lista l){
    if(l!=NULL){
        destruir_lista(l->prox);
        free(l);
    }
}

void print_lista(Lista l){
    if(l!=NULL){
        printf("%d ", l->dado);
        print_lista(l->prox);
    }
}

Lista busca(Lista l, int val){
    Lista retorno = NULL;
    if(l!=NULL){
        if(val==l->dado){
            retorno = l;
            return retorno;
        }
        busca(l->prox,val);
    }
    else{
        return retorno;
    }
}

int main(){
    Lista list;
    int x;
    list = criar_lista();
    printf("Insira um valor para a lista (-1 para parar): ");
    scanf("%d", &x);
    while(x!=-1){
        insert(&list,x);
        printf("Insira um valor para a lista (-1 para parar): ");
        scanf("%d", &x);
    }
    print_lista(list);
    destruir_lista(list);   
    return 0;

}