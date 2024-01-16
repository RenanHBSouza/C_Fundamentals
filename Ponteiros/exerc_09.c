//Renan Henrique Barreiro Souza         RA: 11202130682
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* revert(char* s){
    int tam = strlen(s), i;
    char* result = (char*)malloc(tam*sizeof(char));
    if(result == NULL){
        printf("Memoria insuficiente!\n");
        exit(1);
    }
    for(i=0;i<tam;i++){
        result[i] = s[(tam-1)-i];       //o ponteiro result recebe no indice i o valor apontado pelo ponteiro de posição (tam-1)-i
    }
    return result;
}

int main(){
    char* string, *invertido;
    string = (char*)malloc(100*sizeof(char));
    if(string == NULL){
        printf("Memoria insuficiente!\n");
        exit(1);
    }
    printf("Defina a palavra a ser invertida: ");
    scanf("%s", string);
    invertido = revert(string);
    printf("%s", invertido);
    free(string);
    free(invertido);

    return 0;
}