//Renan Henrique Barreiro Souza     RA: 11202130682
#include <stdio.h>
#include <stdlib.h>

int soma(int v[], int n){
    if((n-1)==0){
        return v[0];
    }
    else{
        return v[n-1]+ soma(v, (n-1));
    }
}

int* ler_vetor(int n){
    int* v;
    v = (int*)malloc(n*sizeof(int));
    for(int i=0;i<n;i++){
        scanf("%d", &v[i]);
    }
    return v;
}

int main(){
    int* v;
    int n;
    printf("defina n: ");
    scanf("%d", &n);
    v = ler_vetor(n);
    int somar = soma(v, n);
    printf("soma: %d", somar);
    free(v);
    return 0;
}
