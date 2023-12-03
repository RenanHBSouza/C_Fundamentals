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
    Lista list, result;
    int x;
    list = criar_lista();
    printf("Insira um valor para a lista (-1 para parar): ");
    scanf("%d", &x);
    while(x!=-1){
        list = adicionar_elemento(list,x);
        printf("Insira um valor para a lista (-1 para parar): ");
        scanf("%d", &x);
    }
    print_lista(list);
    printf("\nInsira o valor a ser buscado: ");
    scanf("%d", &x);
    result = busca(list, x);
    if(result==NULL){
        printf("Valor não encontrado.");
    }
    else{
        printf("Valor encontrado no endereço %llu", result);
    }
    destruir_lista(list);   
    return 0;

}