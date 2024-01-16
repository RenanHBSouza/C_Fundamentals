#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void imprimirCaso(char* frase, char* busca, int pos){      //Função para imprimir a frase com a palavra buscada em destaque
    int i;
    for(i=0;i<pos-strlen(busca);i++){       //Imprime os caracteres pré-palavra encontrada       
        printf("%c", frase[i]);
    }
    printf("**");       //printa o destaque pré-palavra
    for(i;i<pos;i++){       //Printa a palavra encontrada
        printf("%c", frase[i]);
    }
    printf("**");       //Printa o destaque pós-palavra
    for(i;frase[i]!='\0';i++){      //Printa o restante da frase
        printf("%c", frase[i]);
    }
    return;
}

void meugrep(FILE* texto, char* busca, char* nomearq){
    int linha=1,i=0,j=0;
    char c;
    char* frase = malloc(100*sizeof(char));
    char* palavra = malloc(100*sizeof(char));
        while(fscanf(texto,"%c",&c)!=EOF){          //Faz a leitura de caractere até terminar o arquivo
        if(c=='\n'){        //Procura a quebra de linha para finalizar a frase
            frase[i] = '\0';
            for(i=0;frase[i]!='\0';i++){        //Pega palavra por palavra para comparar com a buscada
                if(frase[i]!=' '){
                    palavra[j] = frase[i];
                    j+=1;
                }
                else{
                    palavra[j] = '\0';
                    if(strcmp(palavra,busca)==0){       //Caso as palavras sejam iguais printa a frase
                        printf("\n%s:%d: ",nomearq,linha);
                        imprimirCaso(frase,busca,i);
                    }
                    j = 0;
                }
            }
            palavra[j] = '\0';      //Faz a mesma analise com a ultima palavra que não tem ' ' como ultimo caractere,  
            if(strcmp(palavra,busca)==0){
                printf("\n%s:%d: ",nomearq,linha);                
                imprimirCaso(frase,busca,i);
            }
            j = 0;
            linha+=1;
            i = 0;
        }
        else{       //Enquanto não chega na quebra de linha escreve os caracteres na frase
            frase[i] = c;
            i+=1;
        }
    }  
    frase[i] = '\0';        //Faz a mesma analise para a ultima linha que termina por encontrar EOF
    for(i=0;frase[i]!='\0';i++){
        if(frase[i]!=' '){
            palavra[j] = frase[i];
            j+=1;
        }
        else{
            palavra[j] = '\0';
            if(strcmp(palavra,busca)==0){
                printf("\n%s:%d: ",nomearq,linha);
                imprimirCaso(frase,busca,i);
            }
            j = 0;
        }
    }
    palavra[j] = '\0';
    if(strcmp(palavra,busca)==0){
        printf("\n%s:%d: ",nomearq,linha);
        imprimirCaso(frase,busca,i);
    }
    j = 0;
    linha+=1;
    i = 0;
    free(frase);
    free(palavra);
}
    


int main(int argc, char* argv[]){
    char* busca = malloc(100*sizeof(char));
    FILE* arq;
    int i=2;
    if(argc<3){     //Verifica se as entradas foram inseridas
        printf("Entradas insuficientes!");
        return 1;
    }
    busca = strcpy(busca, argv[1]);     //Pega a palavra entrada e armazena em busca
    while(i<argc){
        arq = fopen(argv[i],"r");
        if(arq == NULL){
            printf("Memoria insufiente!");
            return 1;
        }
        meugrep(arq,busca,argv[i]);
        fclose(arq);
        i+=1;
    }
    free(busca);
    return 0;
}