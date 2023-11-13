//Renan Henrique Barreiro Souza         RA: 11202130682

#include<stdio.h>
#define MAX 1000

void lerVetor(double array[], int n){		//Função para inserir valores no vetor em cada posição
    int i;
    for(i=0; i<n; i++){
        scanf("%lf", &array[i]);
    }
}

void produto_hadamard(double u[], double v[], double resultado[], int k){		//Função para multiplicar cada posição dos vetores para gerar outro vetor
    int i;
    for (i=0; i<k; i++){
        resultado[i] = u[i]*v[i];
    }
}

void escVetor(double array[], int n){		//Função para printar vetor
    int i;
    for(i=0; i<n; i++){
        printf("%.2lf\n", array[i]);
    }    
}

int main(){
    int i;
    double u[MAX], v[MAX], result[MAX];		//Declara os 3 vetores	
    
    printf("Insira o indice dos vetores: ");		//Recebe o valor do indice dos vetores
    scanf("%d", &i);
	while(i<0 || i>100){
		printf("Valor invalido, insira novamente: ");
		scanf("%d", &i);
	}
  
    printf("digite os %d valores do vetor u:\n", i);
    lerVetor(u,i);
    printf("digite os %d valores do vetor v:\n", i);	//Bloco para chamar as funções criadas
    lerVetor(v,i);
    produto_hadamard(u, v, result, i);
    printf("Valores da multiplicacao: \n");
    escVetor(result, i);

    return 0;
}