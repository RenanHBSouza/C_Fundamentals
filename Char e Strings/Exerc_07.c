//Renan Henrique Barreiro Souza     RA: 11202130682

#include <stdio.h>
#define MAX 100
#define TAM 2

typedef struct {
    int membros[MAX][MAX];
    int dimensao;
} Matriz;

Matriz matriz_le(int n){
    int i, j;
    Matriz mat;
    mat.dimensao = n;

    for(i=0; i<mat.dimensao; i++){
        for(j=0; j<mat.dimensao; j++){
            scanf("%d", &mat.membros[i][j]);
        }
    }
    return mat;
}

Matriz matriz_multiplica(Matriz A, Matriz B){
    Matriz AxB;
    AxB.dimensao = A.dimensao;
    int i, j, r, valor=0;

    for(i=0; i<AxB.dimensao; i++){
        for(j=0; j<AxB.dimensao; j++){
            for(r=0; r<AxB.dimensao; r++){
                valor = valor + A.membros[i][r]*B.membros[r][j];
            }
            AxB.membros[i][j] = valor;
            valor = 0;
        }
    }
    return AxB;
}

void print_matriz(Matriz mat){
    int i, j;
    for(i=0; i<mat.dimensao; i++){
        for(j=0; j<mat.dimensao; j++){
            printf("%d ", mat.membros[i][j]);
        }
        printf("\n");
    }
}

int main(){
    Matriz matA, matB, matC;
    printf("A: ");
    matA = matriz_le(TAM);
    printf("B: ");
    matB = matriz_le(TAM);
    print_matriz(matA);
    print_matriz(matB);
    matC = matriz_multiplica(matA, matB);
    print_matriz(matC);
    return 0;
}