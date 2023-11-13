//Renan Henrique Barreiro Souza     RA: 11202130682

#include <stdio.h>
#define MAX 100

int sequencia_Zeros(char string[]){
    int i, maior, agrupador[MAX], indice = 0, contador = 0;
    for(i=0; string[i]!='\0';i++){      //For para procurar os '0s' até o fim da string
        if(string[i] == '0'){       //Ao encontrar o 0 ele inicia um contador que para qnd acha algum caractere diferente
            while(string[i] == '0'){
                i = i + 1;
                contador = contador + 1;
            }
            agrupador[indice] = contador;
            contador = 0;
            indice = indice + 1;
        }
    }
    maior = agrupador[0];
    for(i=0; i<indice; i++){        //laço para encontrar o maior dos valores salvos entre as contagens de 0
        if (agrupador[i]>maior){
            maior = agrupador[i];
        }
    }
    return maior;
}

int main(){
    char frase[MAX];
    int resultado;
    printf("Escreva a sequencia de valores: ");
    scanf("%s", frase);
    resultado = sequencia_Zeros(frase);
    printf("%d", resultado);

    return 0;
}