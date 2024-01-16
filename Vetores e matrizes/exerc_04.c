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

void soma(int a[][MAX], int b[][MAX], int c[][MAX], int n, int m){
	int i, j;
	for (i=0; i<n; i++){
		for (j=0; j<m; j++){
		c[i][j] = a[i][j] + b[i][j];	//Utiliza de for encadeado para realizar cada soma
		}
	}  
}

int main(){
	int n, m;
	int A[MAX][MAX], B[MAX][MAX], C[MAX][MAX];
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
	printf("Escreva os valores da matriz B: ");
	ler_mat(B, n, m);
	printf("Matriz soma: \n");
	soma(A, B, C, n, m);
	esc_mat(C, n, m);

    return 0;
}