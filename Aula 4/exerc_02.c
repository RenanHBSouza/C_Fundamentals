//Renan Henrique Barreiro Souza         RA: 11202130682
#include <stdio.h>
#include <stdlib.h>

char* ler_vetor(int n){
    int i;
    char* vetor = (char*)malloc(n*sizeof(char));
    if(vetor==NULL){
        printf("Memoria insuficiente!");
        exit(1);
    }
    for(i=0;i<n;i++){
        getchar();
        scanf("%c", &vetor[i]);
    }
    return vetor;
}

void infos(char* vetor, int n){
    int i;
    for(i=0;i<n;i++){
        printf("entrada: %d, conteudo: %c, endereco: %llu\n", i, vetor[i], &vetor[i]);
    }
    return;
}

int main(){
    int n;
    char* valores;
    printf("Insira n: ");
    scanf("%d", &n);
    valores = ler_vetor(n);
    infos(valores, n);
    free(valores);
    return 0;
}