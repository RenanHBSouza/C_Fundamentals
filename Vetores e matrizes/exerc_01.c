//Renan Henrique Barreiro Souza         RA:11202130682

#include <stdio.h>
#define MAX 1000

void ler_vetor(int vetor[], int n){
    int i;
    for (i=0; i<n; i++){
        scanf("%d", &vetor[i]);
    }
}

void esc_vetor(int vetor[], int n){
    int i;
    for (i=0; i<n; i++){
        printf("%d\n", vetor[i]);
    }
}

int busca(int valores[], int n, int chave) {
    int i;
    for (i=0; i<n; i++){
        if(chave==valores[i]){		//Automaticamente ao encontrar o valor buscado retorna a posição
            return i;
        }
    }
	return -1;		//Caso 'chave' não seja encontrado retorna o valor -1
}

int main(){
    int resp, n, chave;
    printf("Escreva o numero de valores do vetor: ");
    scanf("%d", &n);
    int valores[MAX];
    printf("Escreva os %d valores do vetor: \n", n);
    ler_vetor(valores, n);
    printf("Digite o valor a ser procurado: ");
    scanf("%d", &chave);
    resp = busca(valores, n, chave);
    printf("O valor se encontra na posicao %d!", resp);

    return 0;
}