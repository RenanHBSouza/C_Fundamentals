//Renan Henrique Barreiro Souza         RA: 11202130682
#include <stdio.h>
#include <stdlib.h>

typedef struct no* Lista;

struct no{
    int dado;
    Lista prox;
};

void destruir_lista(Lista l){
    Lista temp;
    do{
        temp = l->prox;
        free(l);
        l = temp;
    } while (l!=NULL);

}

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

void print_lista(Lista l){
    if(l!=NULL){
        printf("%d ", l->dado);
        print_lista(l->prox);
    }
    else{
        return;
    }

}


int main(){
    Lista list;
    int x=0;
    list = criar_lista();
    printf("Insira um valor para a lista (-1 para parar): ");
    scanf("%d", &x);
    while(x!=-1){
        list = adicionar_elemento(list,x);
        printf("Insira um valor para a lista (-1 para parar): ");
        scanf("%d", &x);
    }
    print_lista(list);
    destruir_lista(list);   
    return 0;
}