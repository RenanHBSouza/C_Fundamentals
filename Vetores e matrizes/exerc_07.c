 // Renan Henrique Barreiro Souza     RA: 11202130682

#include <stdio.h>
#define MAX 100

void ler_mat(int mat[][MAX], int n, int m) {
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			scanf("%d", &mat[i][j]);
		}
	}
}

void esc_mat(int mat[][MAX], int n, int m) {
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			printf("%d", mat[i][j]);
			printf(" ");
		}
		printf("\n");
	}
}

void troca(int a[][MAX], int m, int i, int j) {
	int k, armazen;
	for (k = 0; k < m; k++) {		//Faz a verifação por coluna, trocando de posição os valores das linhas i-1 e j-1
		armazen = a[i-1][k];		//Usa a variavel 'armazen' para não perder o valor da posição que será alterada primeiro
		a[i-1][k] = a[j-1][k];
		a[j-1][k] = armazen;
	}
}

int main() {
	int n, m, i, j;
	int A[MAX][MAX], T[MAX][MAX];
	do {
		printf("Defina o numero de linhas: ");
		scanf("%d", &n);
	} while (n < 1 || n > 1000);
  
	do {
		printf("Defina o numero de colunas: ");
		scanf("%d", &m);
	} while (m < 1 || m > 1000);
  
	do {
		printf("Defina o valor de i: ");
		scanf("%d", &i);
	} while (i < 1 || i > n);

	do {
		printf("Defina o numero de j: ");
		scanf("%d", &j);
	} while (j < 1 || j > n);  

	printf("Escreva os valores da matriz A: ");
	ler_mat(A, n, m);
	esc_mat(A, n, m);
	printf("Matriz A' com linhas %d e %d trocadas: \n", i, j);

	troca(A, m, i, j);
	esc_mat(A, n, m);  

	return 0;
}