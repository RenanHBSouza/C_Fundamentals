//Renan Henrique Barreiro Souza         RA: 11202130682
#include <stdio.h>
#include <stdlib.h>

char* strcat(char* a, char* b){         //recebe dois ponteiros para retornar um ponteiro concatenado
    int i, n = 0, m = 0, t;
    for(i=0;a[i]!='\0';i++){        //Define os tamanhos de cada um dos vetores de caractere usando \0 como limitador
        n = n + 1;
    }
    for(i=0;b[i]!='\0';i++){
        m = m + 1;
    }
    char* result = (char*)malloc((n+m)*sizeof(char));       //Aloca memoria com a soma do tamanho dos dois ponteiros recebidos
    if(result==NULL){
        printf("memoria insuficiente!");
        exit(1);
    }

    for(i=0;i<n;i++){       
        result[i] = *(a+i);      //Coloca os valores do primeiro ponteiro no ponteiro result
    }
    t = i;
    for(i=0;i<m;i++){       //Coloca os valores do segundo ponteiro no ponteiro result
        result[t+i] = *(b+i);
    }
    return result;
}  

int main(){
    char* a, *b;
    a = (char*)calloc(100, sizeof(char));
    if(a == NULL){
        printf("Memoria insuficiente!\n");
        exit(1);
    }
    b = (char*)calloc(100, sizeof(char));
    if(b == NULL){
        printf("Memoria insuficiente!\n");
        exit(1);
    }
    printf("Insira a primeira palavra: ");
    scanf("%s", a);
    getchar();
    printf("Insira a segunda palavra: ");
    scanf("%s", b);
    char* concatenar;
    concatenar = strcat(a,b);       //envia os vetores para a função
    printf("%s", concatenar);
    free(a);
    free(b);
    free(concatenar);
    return 0;
}