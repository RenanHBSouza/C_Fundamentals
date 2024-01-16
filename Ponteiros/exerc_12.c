//Renan Henrique Barreiro Souza         RA:11202130682
#include <stdio.h>
#include <stdlib.h>

typedef struct vet{
    void** data;
    int capacity;
    int nelements;
}* VectorInt;

VectorInt vectorint(){
    VectorInt p = malloc(sizeof(struct vet));    //Aloca memoria para a um ponteiro da estrutura
    if(p==NULL){
        printf("Memoria insuficiente!");
        exit(1);
    }
    p->capacity = 1;
    p->nelements = 0;
    (*p).data = (void**)malloc(sizeof(void*));      //Aloca memoria para o ponteiro data
    if(p->data==NULL){
        printf("Memoria insuficiente!");
        exit(1);
    }
    return p;
}

void vectorint_insert(VectorInt v, void* a){
    if (v->capacity==v->nelements){     //Verifica se a capacidade do vetor dinamico é igual o numero de elementos ja inseridos
        v->data = realloc(v->data, (2*v->capacity)*sizeof(void*));    //Realoca o dobro de capacidade de data
        if(v->data == NULL){
            printf("Memoria insuficiente!\n");
            exit(1);
        }
        v->data[v->nelements] = a;      //Insere o elemento no indice nelements
        v->capacity *= 2;
    }
    else{
        v->data[v->nelements] = a;      //Caso contrario apenas insere
    }
    v->nelements += 1;
    return;
}

void vectorint_remove(VectorInt v, void* a){
    int i, j;
    for(i=0;i<v->nelements;i++){
        if(v->data[i]==a){      //Caso encontre a, traz um elemento para traz todos os valores de data
            for(j=i;j<v->nelements-1;j++){
                v->data[j] = v->data[j+1];
            }
            v->nelements -= 1;      //Remove 1 do nelements
        }
    }
    if(v->nelements<v->capacity/2 && v->capacity>1){        //Verifica se o nelements é menor que metade da capacidade
        v->data = realloc(v->data, (v->capacity/2)*sizeof(void*));    //Caso sim realoca data com metade da capacidade
        if(v->data == NULL){
            printf("Memoria insuficiente!\n");
            exit(1);
        }
        v->capacity /= 2;
    }
    return;
}

void* vectorint_at(VectorInt v, int i){       //Procura o i-esimo valor em data
    if(i>=0 && i<v->nelements){
        return v->data[i];
    }
    else{
        printf("Indice incorreto!");
        exit(1);
    }

}

char vectorint_pert(VectorInt v, void* a){       //Procura o elemento a em data e retorna s ou n
    int i, j;
    for(i=0;i<v->nelements;i++){
        if(v->data[i]==a){
            return 's';
        }
    }
    return 'n';
}

int vectorint_elements(VectorInt v){    //Retorna o numero de elementos do vetor dinamico
    return v->nelements;
}

void vectorint_memory(VectorInt v){
    if(v!=NULL){
        free(v->data);
        free(v);
    }
    return;
}

int main(){
    int i, num, n;
    int* val;
    VectorInt dado;
    dado = vectorint();
    printf("Defina quantos valores quer inserir: ");
    scanf("%d", &n);
    for(i=0;i<n;i++){
        printf("valor %d: ", i);
        scanf("%d", &num);
        vectorint_insert(dado, (void*)num);
    }
    printf("capacidade do vetor: %d\n", dado->capacity);
    printf("n de elementos do vetor: %d\n", vectorint_elements(dado));

    printf("Insira posição que deseja buscar: ");
    scanf("%d", &n);
    val = (int*)vectorint_at(dado, n);
    printf("na posição %d: %d\n", n, val);

    printf("Defina quantos valores quer remover: ");
    scanf("%d", &n);
    for(i=0;i<n;i++){
        printf("Insira um valor: ");
        scanf("%d", &num);
        vectorint_remove(dado, (void*)num);
    }

    printf("capacidade do vetor: %d\n", dado->capacity);
    printf("n de elementos do vetor: %d\n", vectorint_elements(dado));

    printf("Insira posição que deseja buscar: ");
    scanf("%d", &n);
    val = (int*)vectorint_at(dado, n);
    printf("na posição %d: %d\n", n, val);

    printf("Insira um valor que deseja verificar se pertence ao vetor: ");
    scanf("%d", &num);
    printf("%d pertence ao vetor? %c", num, vectorint_pert(dado, (void*)num));

    vectorint_memory(dado);
    return 0;
}