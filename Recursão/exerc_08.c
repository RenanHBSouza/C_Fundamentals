//Renan Henrique Barreiro Souza         RA: 11202130682
#include <stdio.h>
#include <stdlib.h>

typedef struct Comb
{
    int* pre;
    int tam_atual;
    int valor;
    int tam_esp;
} Dados;

void combinacoes(int n, Dados l){
    int i;
    if(l.tam_atual==l.tam_esp){
        for(i=0;i<l.tam_atual;i++){
            printf("%d",l.pre[i]);
        }
        printf("\n");
        return;
    }
    else{
        for(i=l.valor;i<=n;i++){
            l.pre[l.tam_atual]=i;
            l.tam_atual += 1;
            l.valor = i + 1;
            combinacoes(n,l);
            l.tam_atual -= 1;
        }
    }
}

int main(){
    int n;
    Dados l;
    printf("Defina um n positivo: ");
    scanf("%d", &n);
    l.pre = (int*)malloc(n*sizeof(int));
    l.tam_esp = 1;
    for(int i=1;i<=n;i++){
        l.valor = 1;
        l.tam_atual = 0;
        combinacoes(n,l);
        l.tam_esp += 1;
    }
    free(l.pre);
    return 0;
}