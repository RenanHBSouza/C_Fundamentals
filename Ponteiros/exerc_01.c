//Renan Henrique Barreiro Souza         RA: 11202130682
#include <stdio.h>
#include <stdlib.h>

int* esc_vetor(int n){
    int i, *vetor;
    vetor = (int*)malloc(n*sizeof(int));
    if (vetor==NULL){
        printf("Não há memoria disponivel!");
        exit(1);
    }
    for(i=0;i<n;i++){
        scanf("%d", &vetor[i]);
    }
    return vetor;
}

double calc_media(int* vetor, int n){
    int i;
    double result=0;
    for(i=0;i<n;i++){
        result = result + (vetor[i]/(double)n);
    }
    return result;
}

int main(){
    int n, *valores;
    double media;
    printf("Defina n: ");
    scanf("%d", &n);
    valores = esc_vetor(n);
    media = calc_media(valores, n);   
    printf("Media final: %.2lf", media);
    free(valores);
    return 0;
}