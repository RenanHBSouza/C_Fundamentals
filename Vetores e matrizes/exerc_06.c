// Renan Henrique Barreiro Souza     RA: 11202130682

#include <stdio.h>
#define MAX 100

void ler_mat(int mat[][MAX], int n) {
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			scanf("%d", &mat[i][j]);
		}
	}
}

void esc_mat(int mat[][MAX], int n) {
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			printf("%d", mat[i][j]);
			printf(" ");
		}
		printf("\n");
	}
}

int simetrica(int a[][MAX], int n) {
	int i, j, flag = 0;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (a[i][j] != a[j][i]) {		//Caso a igualdade não seja verdareira em alguma commparação sinaliza na flag
				flag = 1;
			}
		}
	}
	return flag;
}

int main() {
	int n, resp;
	int A[MAX][MAX], T[MAX][MAX];
	do {
		printf("Defina o numero n: ");
		scanf("%d", &n);
	} while (n < 1 || n > 1000);


	printf("Escreva os valores da matriz A: ");
	ler_mat(A, n);
	esc_mat(A, n);
	resp = simetrica(A, n);
	if (resp != 1) {		//Se a flag não for sinalizada retorna como simetrica
		printf("Matriz e simetrica!");
	} else {
		printf("Matriz nao e simetrica.");
	}
	return 0;
}