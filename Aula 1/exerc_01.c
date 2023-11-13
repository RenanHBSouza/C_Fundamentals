//Renan Henrique Barreiro Souza         RA: 11202130682

#include<stdio.h>

void par(int n){		//Função para verificar quais numeros são pares em um intervalo [o,n]
    int i;
    for(i=0;i<=n;i++){
        if (i%2==0){		//Verificamos o resto da divisão por 2 de cada numero, caso dê 0 printa pois é par
            printf("%d\n",i);
        }
    }
}

int main() {
    int num;
    printf("Defina o valor de n do intervalo [o,n]: ");
    scanf("%d", &num);

    printf("Valores pares: \n");
    par(num);
    return 0;
}