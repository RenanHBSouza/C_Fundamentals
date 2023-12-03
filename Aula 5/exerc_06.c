//Renan Henrique Barreiro Souza         RA: 11202130682
#include <stdio.h>
#include <stdlib.h>

void Collatz(unsigned int a){
    printf("%d ", a);
    if (a==1){
        return;
    }
    else if(a%2==0){
        return Collatz(a/2);
    }
    else{
        return Collatz(a*3+1);
    }
}

int main(){
    unsigned int num;
    printf("Defina um valor: ");
    scanf("%d", &num);
    Collatz(num);

    return 0;
}