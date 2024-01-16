//Renan Henrique Barreiro Souza             RA: 11202130682
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1000

typedef struct aluno{       //Estrutura tipo *Aluno
    int ra;
    char nome[MAX];
    char sexo;
    int idade;
}* Aluno;

char aluno_cmp(Aluno* a, Aluno* b){     //Função que recebe dois arrays de ponteiros para comparação
    int flag=0;     //flag que soma 1 cada vez que uma comparação tiver o resultado esperado
    if((*a)->ra==(*b)->ra){     //por ser uma array de ponteiros é utilizado (*a)->ra, basicamente significa o valor apontado pelo ponteiro que é apontado por outro ponteiro
        flag += 1;
    }
    if((*a)->sexo==(*b)->sexo){
        flag += 1;
    } 
    if((*a)->idade==(*b)->idade){
        flag += 1;
    }
    if(strcmp((*a)->nome, (*b)->nome)==0){
        flag += 1;
    }
    if(flag==4){        //Retona 1 caso todas as comparações sejam verdadeiras
        return '1';
    }
    return '0';
}

void infos(Aluno* alunos, int n){
    printf("Insira a idade: ");
    scanf("%d", &alunos[n]->idade);
    printf("Insira o ra: ");
    scanf("%d", &alunos[n]->ra);
    getchar();
    printf("Insira o sexo: ");
    scanf("%c", &alunos[n]->sexo);
    getchar();
    printf("Insira o nome: ");
    fgets(alunos[n]->nome, MAX, stdin);
    return;
}

int main(){
    Aluno* alunos = (Aluno*)malloc(2*sizeof(Aluno));
    if(alunos==NULL){
        printf("Memoria insuficiente!");
        exit(1);
    }
    for(int i=0; i<2;i++){
        alunos[i] = malloc(sizeof(struct aluno));
    }

    infos(alunos, 0);
    infos(alunos, 1);

    printf("Sao iguais? %c", aluno_cmp(&alunos[0], &alunos[1]));

    for(int i=0; i<2;i++){
        free(alunos[i]);
    }
    free(alunos);

    return 0;
}