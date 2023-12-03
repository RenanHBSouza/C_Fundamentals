//Renan Henrique Barreiro Souza         RA: 11202130682
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void inverte(char word[], int ini, int fim){
    char temp;
    if(ini>=fim){
        return;
    }
    else{
        temp = word[ini];
        word[ini] = word[fim];
        word[fim] = temp;
        return inverte(word, ini+1, fim-1);
    }
}

int main(){
    char* word;
    word = (char*)malloc(100*sizeof(char));
    printf("Escreva a palavra: ");
    scanf("%s", word);
    inverte(word, 0, strlen(word)-1);
    printf("palavra invertida: %s", word);
    free(word);
    return 0;
}