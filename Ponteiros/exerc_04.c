//Renan Henrique Barreiro Souza         RA: 11202130682
#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b){      //Recebe o endereço de duas variaveis para fazer operação com ponteiros
    int temp;       
    temp = *a;      //temp recebe o valor apontado por a
    *a = *b;        //o valor apontado por a recebe o valor apontado por b
    *b = temp;      //o valor apontado por b recebe o valor armazenado em temp
    return;
}

int main(){
    int a, b;
    printf("insira o valor de a: ");
    scanf("%d", &a);
    printf("insira o valor de b: ");
    scanf("%d", &b);   
    swap(&a, &b);       //Envia o endereço de cada uma das variaveis para a função
    printf("a: %d\n", a);
    printf("b: %d\n", b);
    return 0;
}