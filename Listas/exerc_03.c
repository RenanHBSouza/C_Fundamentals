
//Renan Henrique Barreiro Souza         RA: 11202130682
#include <stdlib.h>
#include <stdio.h>

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

Lista remover(Lista l, int val){
    Lista tempAT, tempANT;
    if (l->dado == val){
        tempAT = l->prox;
        l = NULL;
        l = tempAT;
        return l;
    }
    else{
        tempANT = l;
        tempAT = l->prox;
        while(tempAT!=NULL){
            if(tempAT->dado == val){
                tempANT->prox = tempAT->prox;
                l = tempANT;
                return l;
            }
            else{
                tempANT = tempANT->prox;
                tempAT = tempAT->prox;
            }
        }
    return l;
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
    printf("\nInsira o valor a ser removido: ");
    scanf("%d", &x);
    result = remover(list, x);
    print_lista(result);
    destruir_lista(list);
    return 0;

}