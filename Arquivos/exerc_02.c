//Renan Henrique Barreiro Souza     RA:11202130682
#include <stdio.h>
#include <stdlib.h>

void meucat(FILE* arq){
    char aux;
    while(fscanf(arq,"%c",&aux)!=EOF){
        printf("%c",aux);
    }
    printf("\n");
    return;
}

int main(int argc, char* argv[]){
    FILE* text;
    int i;
    if(argc<2){
        printf("nenhum arquivo adicionado!\n");
        return 1;
    }
    else{
        printf("Arquivo lido\n");
        for(i=1;i<argc;i++){
            text = fopen(argv[i],"r");
            if(text == NULL){
                printf("Problema ao ler o arquivo");
                return 1;
            }
            meucat(text);
            fclose(text);
        }
    }

    return 0;
}