//Renan Henrique Barreiro Souza     RA: 11202130682

#include <stdio.h>
#define MAX 1000

void quebra_linhas(char texto[]){
    int i,j=-1;     //i utilizado para controlar o fim do textok, j controla a ocorrencia de 80 caracteres para a quebra
    for(i=0; texto[i]!='\0'; i++){
        j = j + 1;
        if(j==80){
            if(texto[i]!=' '){      //Caso o caractere da posição 80 não seja ' ' ele retorna até encontrar o ' ' mais proximo
                while(texto[i]!=' '){
                    i = i - 1;
                }
            }
            texto[i] = '\n';        //substitui esse espaço por uma quebra de linha e zera o contador j
            j = 0;
        }
        else{
            if(texto[i] == '\n'){
                texto[i] = ' ';
            }
        }
    }

}


int main(){
    int i, j=0, flag=0;
    char texto[MAX], captura[MAX];  //Captura utilizada para pegar partes do texto até o \n e o texto agrupa todas essas partes
    printf("insira o texto:\n");
    while (flag<2)      //loop enquanto a flag não indica 2 '\n' seguidos
    {
        fgets(captura, MAX, stdin);
        for(i=0;captura[i]!='\0'; i++){     //laço para verificar cada um dos caracteres da captura atual
            texto[j+i] = captura[i];        //Acrescenta cada um desses caracteres na string texto
            if(captura[i]=='\n'){       //Acrescenta 1 na flag quando encontra uma quebra de linha --> alcançará 2 quando uma captura terminar e a outra começar com '\n'
                flag += 1;
            }
            else{       //Zera a contagem cada vez que aparece outro caractere
                flag = 0;
            }
        }
        j = j + i;      //é somado o valor de i da captura atual no j para ir sempre incrementando os textos
    }
    
    quebra_linhas(texto);
    printf("Texto formatado:\n");
    for(i=0; texto[i]!='\0'; i++){
        printf("%c", texto[i]);
    }

    return 0;
}