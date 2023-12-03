//Renan Henrique Barreiro Souza         RA: 11202130682
#include <stdio.h>
#include <stdlib.h>

int* aloc_vetor(int n){
    int i;
    int* v = (int*)malloc(n*sizeof(int));
    if(v==NULL){
        printf("Memoria insulficiente!");
        exit(1);
    }
    for(i=0;i<n;i++){
        scanf("%d", &v[i]);
    }
    return v;
}

void infos(int* vetor, int n){
    int i;
    for(i=0;i<n;i++){
        printf("entrada: %d, conteudo: %d, endereco: %llu\n", i, *(vetor+i), &vetor[i]);
    }
    return;
}

int main(){
    int n, *valores;
    printf("Defina n: ");
    scanf("%d", &n);
    valores = aloc_vetor(n);
    infos(valores, n);
    free(valores);
    return 0;
}