//Renan Henrique Barreiro Souza     RA: 11202130682


#include <stdio.h>
#define MAX 100
#define TAM 5   //Definição de tamanho dos vetores pois na função do enunciado não tem int n


typedef struct {
    int conjunto[100];
    int tamanho;
} Conjunto;

Conjunto conjunto(int vet[]){
    int i, j, flag;
    Conjunto c;
    c.tamanho = 0;  //Conjunto começa de tamanho 0

    for(i=0; i<TAM; i++){
        flag = 0;
         for(j=0; j<c.tamanho; j++){
            if(vet[i]==c.conjunto[j]){      //Verifica se o valor do vetor ja foi colocado do conjunto
                flag = 1;       //Sinaliza na flag
            }
        }
        if (flag==0){       //Flag == 0 significa que o valor ainda não foi inserido no conjunto
            c.conjunto[c.tamanho] = vet[i];     //Acrescenta valor na posição atual e aumenta 1 de tamanho
            c.tamanho = c.tamanho + 1;
        }
    }
    return c;
}

char conjunto_pertence(int a, Conjunto A){
    int i;
    for(i=0; i<A.tamanho; i++){     
        if(A.conjunto[i] == a){     //Verifica posição por posição do conjunto se a lhe pertence
            return '1';     //Retorna 1 caso pertença
        }
    }
    return '0';     //Retorna 0 caso não pertença
}


Conjunto conjunto_uniao(Conjunto A, Conjunto B){
    Conjunto c;
    c.tamanho = 0;      //Conjunto união c começa de tamanho 0
    int i, j, flag;
    for(i=0; i<A.tamanho; i++){     //Coloca todos os valores do conjunto A na união c
        c.conjunto[i] = A.conjunto[i];
        c.tamanho = c.tamanho + 1;      //Aumenta 1 de tamanho de c a cada inserção
    }
    for(i=0; i<B.tamanho; i++){     //Varredura dos valores do conjunto B
        if(conjunto_pertence(B.conjunto[i], c) == '0'){     //Verifica se o valor de B ja pertence a c
            c.conjunto[c.tamanho] = B.conjunto[i];
            c.tamanho = c.tamanho + 1;
        }
    }
    return c;
}


void print_conjunto(Conjunto a){
    int i;
    for(i=0; i<a.tamanho; i++){
        printf("%d ", a.conjunto[i]);
    }
}

void ler_vetor(int vetor[]){
    int i;
    for(i=0; i<TAM; i++){
        scanf("%d", &vetor[i]);
    }
}



int main() {
    int vetA[MAX], vetB[MAX], busca, n = TAM;
    Conjunto conj1, conj2, conjU;
    printf("Defina seu conjunto A: ");
    ler_vetor(vetA);
    printf("Defina seu conjunto B: ");
    ler_vetor(vetB);
    printf("Defina o valor a ser buscado: ");
    scanf("%d", &busca);
    conj1 = conjunto(vetA);
    conj2 = conjunto(vetB);    
    print_conjunto(conj1);
    printf("\n%c", conjunto_pertence(busca, conj1));
    printf("\n");
    print_conjunto(conj2);
    printf("\n");
    conjU = conjunto_uniao(conj1, conj2);
    print_conjunto(conjU);
    return 0;
}