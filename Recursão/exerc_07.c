//Renan Henrique Barreiro Souza         RA: 11202130682
#include <stdio.h>
#include <stdlib.h>

int Stifel(int n, int k){
    if(k==0 || k==n){
        return 1;
    }
    else{
        return Stifel(n-1, k-1) + Stifel(n-1,k);
    }
}

int main(){
    int n, k, val;
    printf("Defina n e k: ");
    scanf("%d %d", &n, &k);
    val = Stifel(n,k);
    printf("Resposta: %d", val);
    return 0;
}