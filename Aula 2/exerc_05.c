//Renan Henrique Barreiro Souza     RA: 11202130682

#include <stdio.h>
#define MAX 100

void ler_mat(int mat[][MAX], int n, int m){
    int i, j;
    for (i=0; i<n; i++){
        for(j=0; j<m; j++){
            scanf("%d", &mat[i][j]);
        }
    }
}

void esc_mat(int mat[][MAX], int n, int m){
    int i, j;
    for (i=0; i<n; i++){
        for(j=0; j<m; j++){
            printf("%d", mat[i][j]);
            printf(" ");
        }
        printf("\n");
    }
}

void transposta(int a[][MAX], int b[][MAX], int n, int m){
	int i, j;
	for (i=0; i<n; i++){
		for (j=0; j<m; j++){
			b[j][i] = a[i][j];	//Inverte os valores de indice para calculo da trasnposta
		}
	}  
}

int main(){
	int n, m;
	int A[MAX][MAX], T[MAX][MAX];
	do {
		printf("Defina o numero de linhas: ");
		scanf("%d", &n);   
	}
	while (n<1 || n>1000);
	do {
		printf("Defina o numero de colunas: ");
		scanf("%d", &m);  
	}
	while (n<1 || n>1000);

	printf("Escreva os valores da matriz A: ");
	ler_mat(A, n, m);
	esc_mat(A, n, m);
	printf("Matriz transposta: \n");
	transposta(A, T, n, m);
	esc_mat(T, m, n);

    return 0;
}