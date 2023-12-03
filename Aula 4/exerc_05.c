//Renan Henrique Barreiro Souza         RA: 11202130682
#include <stdio.h>
#include <stdlib.h>

void inc(int* x){       //Recebe um endereço e incrimenta 1 no valor apontado pelo ponteiro
    *x = *x+1;
    return;
}

int main(){
    int a;
    printf("Insira o valor de a: ");
    scanf("%d", &a);
    inc(&a);
    printf("%d", a);
    return 0;
}