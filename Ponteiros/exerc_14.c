//Renan Henrique Barreiro Souza         RA: 11202130682

#include <stdio.h>
#include <stdlib.h>

void map(int* vet, int n, int func(int)){
    int i;
    for(i=0;i<n;i++){
        vet[i] = func(vet[i]);
    }
    return;
}

int inc(int a){
    return a += 1;
}

int inc2(int a){
    return a += 2;
}

void esc_vetor(int* v, int n){
    int i;
    for(i=0;i<n;i++){
        printf("Insira o valor [%d]: ", i);
        scanf("%d", &v[i]);
    }
    return;
}

void print_vetor(int* v, int n){
    int i;
    for(i=0;i<n;i++){
        printf("%d ", v[i]);
    }
    printf("\n");
    return;
}

int main(){
    int n, *val;
    printf("Insira n: ");
    scanf("%d", &n);
    val = (int*)malloc(n*sizeof(int));
    esc_vetor(val, n);
    print_vetor(val, n);
    map(val, n, inc);
    print_vetor(val, n);
    map(val, n, inc2);
    print_vetor(val, n);

    free(val);
 
    return 0;
}