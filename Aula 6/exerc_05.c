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
    return;
}

void print_lista(Lista l){
    if(l!=NULL){
        printf("%d ", l->dado);
        print_lista(l->prox);
    }
    return;
}

Lista remover(Lista l, int flag, int val){
    if(flag==0){
        if(l->dado == val){
            l = l->prox;
        }
        flag = 1;
    }
   if(l->prox != NULL){
        remover(l->prox,1,val);
        if(l->prox->dado == val){
            l->prox = l->prox->prox;
        }
   }
   return l;
}

int main(){
    Lista list;
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
    list = remover(list,0,x);
    print_lista(list);
    destruir_lista(list); 
    return 0;
}