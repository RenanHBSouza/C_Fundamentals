//Renan Henrique Barreiro Souza         RA: 11202130682
#include <stdio.h>
#include <stdlib.h>

int** matriz_le(int n, int m){
    int i, j;
    int** mat = (int**)malloc(n*sizeof(int*));      //Aloca n linhas da matriz de ponteiro
    if(mat==NULL){
        printf("memoria insuficiente!");
        exit(1);
    }
    for(i=0;i<n;i++){
        mat[i] = (int*)malloc(m*sizeof(int));       //Aloca m colunas para cada linha da matriz
        if(mat[i]==NULL){
            printf("memoria insuficiente!");
            exit(1);
        }
    }

    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            printf("defina mat[%d][%d]: ", i, j);
            scanf("%d", &mat[i][j]);
        }
    }
    return mat;
}

void matriz_print(int** M, int n, int m){
    int i, j;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            printf("%d ", M[i][j]);
        }
        printf("\n");
    }
    return;
}
int main(){
    int lin, col, i;
    printf("Insira o n de linhas: ");
    scanf("%d", &lin);
    printf("Insira o n de colunas: ");
    scanf("%d", &col);
    int** mat;
    mat = matriz_le(lin, col);
    matriz_print(mat, lin, col);
    
    for(i=0;i<lin;i++){     //Libera a memoria de cada linha
        free(mat[i]);
    }
    free(mat);      //Libera **mat
    return 0;
}