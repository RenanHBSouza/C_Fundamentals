//Renan Henrique Barreiro Souza             RA: 11202130682
#include <stdio.h>
#include <stdlib.h>

typedef struct comb
{
   int* pre;
   int tam_atual;
   int tam_desejado;
   int valor; 
}* Dados;

void combinacoes_tam_def(int n, Dados l){
    int i;
    if(l->tam_atual==l->tam_desejado){
        for(i=0;i<l->tam_atual;i++){
            printf("%d ", l->pre[i]);
        }
        printf("\n");
        return;
    }
    else{
        l->tam_atual += 1;
        combinacoes_tam_def(n,l);
    }
}

void ler_vetor(int* v, int n){
    int i;
    for(i=0;i<n;i++){
        scanf("%d", &v[i]);
    }
    return;
}

int main(){
    int n, k;
    Dados l = malloc(sizeof(struct comb));
    printf("Defina um n e um k positivos: ");
    scanf("%d %d", &n, &k);
    l->pre = (int*)malloc(n*sizeof(int));
    l->tam_atual=1;
    l->tam_desejado = k;
    ler_vetor(l->pre,n);
    combinacoes_tam_def(n,l);
    free(l->pre);
    free(l);
    return 0;
}
