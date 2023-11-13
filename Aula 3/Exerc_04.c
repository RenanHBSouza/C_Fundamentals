//Renan Henrique Barreiro Souza     RA: 11202130682

#include <stdio.h>
#define MAX 100

int tamanho(char vetor[]){
    int i = 0;
    while(vetor[i]!='\0'){
        i = i + 1;
    }
    return i;
}

void ocorre(char texto[], char busca[], int tamanho){
    int i, j, k, flag = 0;
    for(i=0; texto[i]!='\n'; i++){
        if(texto[i] == busca[0]){
            j = i;
            k = 0;
            while(texto[j]==busca[k]){
                j = j + 1;
                k = k + 1;
            }
            if(k==tamanho && (texto[j]==' ' || texto[j]==',' || texto[j] == '.')){
                printf("SIM");
                flag = 1;
            }
        }
    }
    if (flag==0){
        printf("NAO");
    }
}

int main(){
    char palavra[MAX], frase[MAX];
    int tam;
    printf("Insira a frase: ");
    fgets(frase, MAX, stdin);
    printf("Insira a palavra buscada: ");
    scanf("%s", palavra);
    tam = tamanho(palavra);
    ocorre(frase, palavra, tam);
    return 0;
}