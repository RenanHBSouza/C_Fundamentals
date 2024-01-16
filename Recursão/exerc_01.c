//Renan Henrique Barreiro Souza         RA: 11202130682
#include <stdio.h>

void count_down(int n){
    if(n==0){
        printf("ACABOU!");
        return;
    }
    else{
        printf("%d\n", n);
        return count_down(n-1);
    }
}

int main(){
    int n;
    printf("Insira o valor inicial: ");
    scanf("%d", &n);
    count_down(n);
    return 0;
}