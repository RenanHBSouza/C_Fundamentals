//Renan Henrique Barreiro Souza         RA: 11202130682
#include <stdio.h>
#include <stdlib.h>

void swap(int** a, int** b) {       //Ponteiro recebe o endereço de outro ponteiro (ponteiro aponta aponteiro)
    int* temp;
    temp = *a;      //temp recebe o endereço apontado por *a (porque ele aponta **a)
    *a = *b;
    *b = temp;
}

int main() {
    int i, n, m;
    printf("defina n elementos de a: ");
    scanf("%d", &n);
    int* a = (int*)malloc(n*sizeof(int));
    for(i=0;i<n;i++){
        scanf("%d", &a[i]);
    }
    
    printf("Defina m elmentos de b: ");
    scanf("%d", &m);
    int* b = (int*)malloc(m*sizeof(int));
    for(i=0;i<m;i++){
        scanf("%d", &b[i]);
    }

    swap(&a, &b);

    printf("Vetor a: ");
    for(i=0;i<m;i++) {
        printf("%d ", a[i]);
    }
    printf("\nVetor b: ");
    for(i=0;i<n;i++) {
        printf("%d ", b[i]);
    }
    free(a);
    free(b);
    return 0;
}