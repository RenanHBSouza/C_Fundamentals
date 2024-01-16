//Renan Henrique Barreiro Souza     RA: 11202130682

#include <stdio.h>
#define MAX 100

typedef struct {
    int dia;
    int mes;
    int ano;
} data;

typedef struct {
    char nome[MAX];
    char ra[MAX];
    data nascimento;
} Aluno;

Aluno cadastro(){
    Aluno random;
    printf("Nome do aluno: ");
    fgets(random.nome, MAX, stdin);
    printf("Data de nacimento: ");
    scanf("%d %d %d", &random.nascimento.dia, &random.nascimento.mes, &random.nascimento.ano);
    getchar();
    printf("RA: ");
    scanf("%s", random.ra);

    return random;
}

void busca(Aluno valores[], char nome_busca[MAX], int n, int tam){
    int i, j, k, l;
    for(i=0;i<n;i++){
        for(j=0;valores[i].nome[j]!='\0';j++){
            if(valores[i].nome[j]==nome_busca[0]){
                k = j;
                l = 0;
                while(valores[i].nome[k]==nome_busca[l]){
                    k += 1;
                    l += 1;
                }
                if(l==tam && (valores[i].nome[k]==' ' || valores[i].nome[k]=='\n' || valores[i].nome[k]=='.')){
                    printf("\nNome: %s", valores[i].nome);
                    printf("RA: %s", valores[i].ra);
                    printf("\nData de nascimento: %d/%d/%d", valores[i].nascimento.dia, valores[i].nascimento.mes, valores[i].nascimento.ano);
                }
            }
        }
    }
}

void data_aniversario(Aluno alunos[], int n, data dataInicio, data dataFim) {
    printf("Alunos com data de nascimento entre %02d/%02d/%d e %02d/%02d/%d:\n", dataInicio.dia, dataInicio.mes, dataInicio.ano, dataFim.dia, dataFim.mes, dataFim.ano);
    for (int i = 0; i < n; i++) {
        if (alunos[i].nascimento.ano > dataInicio.ano && alunos[i].nascimento.ano < dataFim.ano) {
            if (alunos[i].nascimento.ano == dataInicio.ano && alunos[i].nascimento.mes >= dataInicio.mes && alunos[i].nascimento.dia >= dataInicio.dia) {
                if (alunos[i].nascimento.ano == dataFim.ano && alunos[i].nascimento.mes <= dataFim.mes && alunos[i].nascimento.dia <= dataFim.dia) {
                    printf("Nome: %s\n", alunos[i].nome);
                    printf("Data de Nascimento: %02d/%02d/%d\n", alunos[i].nascimento.dia, alunos[i].nascimento.mes, alunos[i].nascimento.ano);
                    printf("RA: %d\n", alunos[i].ra);
                } else if (alunos[i].nascimento.ano < dataFim.ano) {
                    printf("Nome: %s\n", alunos[i].nome);
                    printf("Data de Nascimento: %02d/%02d/%d\n", alunos[i].nascimento.dia, alunos[i].nascimento.mes, alunos[i].nascimento.ano);
                    printf("RA: %d\n", alunos[i].ra);
                }
            } else if (alunos[i].nascimento.ano > dataInicio.ano) {
                if (alunos[i].nascimento.ano == dataFim.ano && alunos[i].nascimento.mes <= dataFim.mes && alunos[i].nascimento.dia <= dataFim.dia) {
                    printf("Nome: %s\n", alunos[i].nome);
                    printf("Data de Nascimento: %02d/%02d/%d\n", alunos[i].nascimento.dia, alunos[i].nascimento.mes, alunos[i].nascimento.ano);
                    printf("RA: %d\n", alunos[i].ra);
                } else if (alunos[i].nascimento.ano < dataFim.ano) {
                    printf("Nome: %s\n", alunos[i].nome);
                    printf("Data de Nascimento: %02d/%02d/%d\n", alunos[i].nascimento.dia, alunos[i].nascimento.mes, alunos[i].nascimento.ano);
                    printf("RA: %d\n", alunos[i].ra);
                }
            }
        }
    }
}

int tamanho(char vetor[]){
    int i=0;
    while(vetor[i]!='\0'){
        i++;
    }
    return i;
}

int main(){
    Aluno alunos[MAX];
    data inicio, fim;
    char palavra[MAX];
    int menu, n=0, tam;
    printf("1- Cadastrar;   2- Buscar por nome;     3- Filtrar por data    -1 - Finalizar;\n");
    scanf("%d", &menu);
    while(menu!=-1){
        if(menu==1){
            getchar();
            alunos[n] = cadastro();
            printf("%s", alunos[n].nome);
            printf("%d/%d/%d", alunos[n].nascimento.dia, alunos[n].nascimento.mes, alunos[n].nascimento.ano);
            printf("\n%s", alunos[n].ra);
            n = n+1;
        }
        else if(menu==2){
            getchar();
            printf("Insira o nome buscado: ");
            scanf("%s", palavra);
            tam = tamanho(palavra);
            busca(alunos, palavra, n, tam);
        }
        else if(menu==3){
            printf("Intervalo inicial: ");
            scanf("%d %d %d", &inicio.dia, &inicio.mes, &inicio.ano);
            printf("Intervalo final: ");
            scanf("%d %d %d", &fim.dia, &fim.mes, &fim.ano);
            data_aniversario(alunos, n, inicio, fim);
        }
        else if(menu==-1){
            printf("Sessão finalizada!");
        }
        else{
            printf("Valor incorreto!");
        }

    printf("\n1- Cadastrar;   2- Buscar por nome;   3- Filtrar por data   -1 - Finalizar;\n");
    scanf("%d", &menu);
    }

    return 0;
}