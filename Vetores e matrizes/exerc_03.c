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

void ordena(int valores[], int n){
    int i, j, menor, posval;
    for (i=0; i<n; i++){		//laço para verificar qual o valor de cada posição do vetor ordenado
        menor = valores[i];
        for(j=i; j<n; j++){			//laço para comparar o valor da posição em analise com todas as outras restantes
            if (menor>valores[j]){
                menor = valores[j];
                posval = j;					//Realiza a troca dos valores entre a posição em analise e a posição do valor encontrado
                valores[posval] = valores[i];
                valores[i] = menor;
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
    ordena(vetor, n);
    esc_vetor(vetor, n);
	
    return 0;
}