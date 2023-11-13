//Renan Henrique Barreiro Souza     RA: 11202130682

#include <stdio.h>
#define MAX 100

void converte_Texto(char texto[]){
    int i=0;
    while(texto[i]!= '\n'){
        if (texto[i] >= 'A' && texto[i] <= 'Z'){
            printf("%c", texto[i] + 32);
        }
        else if (texto[i] >= 'a' && texto[i] <= 'z'){
            printf("%c", texto[i] - 32);
        }
        else {
            printf("%c", texto[i]);
        }
        i = i + 1;
    }
}


int main(){
    char vetor[MAX];
    printf("Escreva sua frase: ");
    fgets(vetor, MAX, stdin);
    converte_Texto(vetor);
    return 0;
}