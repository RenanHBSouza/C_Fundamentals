//Renan Henrique Barreiro Souza         RA: 11202130682
#include <stdio.h>
#include <stdlib.h>

int* cartesiano(int* v1, int n1, int* v2, int n2){
    int tam = n1*n2, i, j, k=0;

    int *result = (int*)malloc(tam*sizeof(int));      //Aloca o tamanho para a multiplicação dos vetores
    if(result==NULL){
        printf("Memoria insulficiente!");
        exit(1);
    }

    for(i=0;i<n1;i++){
        for(j=0;j<n2;j++){
            result[k] = v1[i]*v2[j];        //laço que guarda em cada posição do ponteiro a multiplicação cartesiana dos vetores de entrada
            k += 1;
        }
    }
    return result;
}

int* ler_vetor(int n){
    int i, *vet;
    vet = (int*)malloc(n*sizeof(int));
    if(vet==NULL){
        printf("memoria insuficiente!");
        exit(1);
    }
    for(i=0;i<n;i++){
        scanf("%d", &vet[i]);
    }
    return vet;
}

void esc_vetor(int* vet, int n, int m){
    int tam = n*m, i;
    for(i=0;i<tam;i++){
        printf("%d ", vet[i]);
    }
    return;
}

int main(){
    int tam1, tam2;
    int* v1;
    int* v2;
    printf("Defina o tamanho de v1: ");
    scanf("%d", &tam1);
    v1 = ler_vetor(tam1);
    printf("Defina o tamanho de v2: ");
    scanf("%d", &tam2); 
    v2 = ler_vetor(tam2);

    int* vresp = cartesiano(v1, tam1, v2, tam2);
    printf("Saída: ");
    esc_vetor(vresp, tam1, tam2);

    free(v1);
    free(v2);   
    free(vresp);

    return 0;
}