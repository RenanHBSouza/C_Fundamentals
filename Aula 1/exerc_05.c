//Renan Henrique Barreiro Souza		RA: 11202130682

#include <stdio.h>
#define MAX 1000

void le_vetor(int v[], int n){		//Função para escrever os valores em cada posição do vetor
	int i;
	for(i=0;i<n;i++){
		scanf("%d", &v[i]);		//& indica que está sendo inserido no endereço da variavel
	}
}

int maximo(int v[], int n){		//Função que encontra o valor maximo do vetor verificando posição por posição
	int i, result=v[0];
	for(i=0;i<n;i++){
		if(v[i]>result){
			result=v[i];
		}
	}
	return result;
}

int minimo(int v[], int n){		//Função que encontra o valor minimo do vetor verificando posição por posição
	int i, result=v[0];
	for(i=0;i<n;i++){
		if(v[i]<result){
			result=v[i];
		}
	}
	return result;
}	

double media(int v[], int n){
	int i;
	double result, div=0., soma=0.;		//Variaveis double para ser possivel fazer o calculo da media
	for (i=0;i<n;i++){
		soma += v[i];
		div += 1.;		//soma 1 no divisor
	}
	result = soma/div;		//Calculo em double para retornar o resultado real
	return result;
}

int main(){
	int n, max, min;
	double med;
	int vetor[MAX];
	
	printf("Defina n: ");
	scanf("%d", &n);
	printf("Digite os %d digitos do vetor: \n", n);
	le_vetor(vetor, n);
	max = maximo(vetor, n);
	min = minimo(vetor, n);
	med = media(vetor, n);
	
	printf("Valor maximo do vetor e %d\n", max);
	printf("Valor minimo do vetor e %d\n", min);
	printf("Media dos valores do vetor e %.2lf\n", med);
		
	return 0;
}