//Renan Henrique Barreiro Souza        RA: 11202130682
#include <stdio.h>
#include <stdlib.h>

int hanoi(int n, char ini, char mei, char fim, int* cont){
    *cont += 1;
    if(n==1){
        return *cont;
    }
    else{
        hanoi(n-1, ini, mei, fim, cont);
        hanoi(n-1, mei, fim, ini, cont);
    }
}

int main(){
    int n, move=0;

    printf("Determine o numero de discos: ");
    scanf("%d", &n);
    move = hanoi(n,'A','B','C',&move);
    printf("Numero de movimentos: %d", move);
    return 0;
}