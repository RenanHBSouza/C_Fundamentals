//Renan Henrique Barreiro Souza         RA:11202130682

#include <stdio.h>
#define MAX 100

void procura_Char(char texto[], char caractere){
    int i=0;
    while (texto[i]!= caractere && texto[i]!='\n'){
        printf("%c", texto[i]);
        i = i+1;
    }
}


int main(){
    char frase[MAX], caracter;
    printf("Escreva o caractere procurado: ");
    scanf("%c", &caracter);
    printf("Digite Seu texto: ");
    getchar();
    fgets(frase, MAX, stdin);
    procura_Char(frase, caracter);
    
    return 0;
}