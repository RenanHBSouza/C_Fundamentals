//Renan Henrique Barreiro Souza     11202130682

#include <stdio.h>
#define MAX 1000

void ler_vetor(int vetor[], int n){
    int i;
    printf("Escreva o vetor de %d valores: ", n);
    for (i=0; i<n; i++){
        scanf("%d", &vetor[i]);
    }
}

void esc_vetor(int vetor[], int n){
    int i;
    for (i=0; i<n; i++){
        printf("%d", vetor[i]);
        printf(" ");
    }
}

void decrescente(int vetor[], int n){
    int i, j, maior, posval;
    for (i=0; i<n; i++){		//laço para verificar qual o valor de cada posição do vetor ordenado
        maior = vetor[i];
        for(j=i; j<n; j++){			//laço para comparar o valor da posição em analise com todas as outras restantes
            if (maior<vetor[j]){	
                maior = vetor[j];
                posval = j;					//Realiza a troca dos valores entre a posição em analise e a posição do valor encontrado
                vetor[posval] = vetor[i];
                vetor[i] = maior;
            }

        }
    }
}

int main(){
    int n, vetor[MAX];
    
    do
    {
        printf("Escreva o valor de n: ");
        scanf("%d", &n);
    } while (n<1 || n>100);

    ler_vetor(vetor, n);
    decrescente(vetor, n);
    esc_vetor(vetor, n);
    return 0;
}