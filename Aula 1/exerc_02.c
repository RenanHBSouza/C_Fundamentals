//Renan Henrique Barreiro Souza         RA: 11202130682

#include<stdio.h>

void primo(int n){		//Função para verificar se um numero é primo
    int i, j, cont=0;
    if (n>=2)		//Verifica se o intervalo é maior que 2 para aplicar a rotina (evitar erro de divisão de 0)
    {
        for(i=1;i<=n;i++){		//Verifica cada valor presente no intervalo a partir de 1
            for(j=0;j<i;j++){		//Divide o valor atual analisado por todos os números até ele
                if(i%(j+1)==0){		//*j+1 para evitar o erro de divisão por 0, com isso utilizando de resto para saber qual é divisivel ou nao
                cont+=1;		//Conta 1 toda vez que o sobra 0 na divisão
                }
            }
        if(cont==2){		//Printa o valor quando o valor é divido só por 2 numeros (1 e ele mesmo)
        printf("%d\n", i);
        }
        cont = 0;    
        }
    }

    }

int main() {
    int num;
    printf("Defina o valor de n do intervalo [1,n]: ");
    scanf("%d", &num);
    printf("Valores primos: \n");
    primo(num);
    return 0;
}