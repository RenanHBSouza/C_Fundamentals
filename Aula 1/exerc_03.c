//Renan Henrique Barreiro Souza         RA: 11202130682

#include<stdio.h>

float convCelsius(float g){		//Converte de Fahrenheit para celsius
    float result;
    result = (g-32.0)*(5.0/9.0);		//Formula de conversão
    return result;
}

float convFahrenheit(float g){		//Converte de Celsius para Fahrenheit
    float result;
    result=(g*(9.0/5.0))+32.0;			//Formula de conversão
    return result;
}

int main(){
    char val;
    float grau, convert;

    printf("C - Celsius p/ Fahrenheit;   F - Fahrenheit p/ Celcius;\n");
    printf("Defina a conversao que deseja: ");
    scanf("%c",&val);
    printf("Qual a temperatura?\n");
    scanf("%f", &grau);

    switch (val)		//Verifica se o usuário escolheu opção 1 ou 2
    {
    case 'c':
        convert = convFahrenheit(grau);
        printf("%.2f graus celsius equivalem a %.2f graus Fahrenheit;\n", grau, convert);
        break;
      
    case 'C':
        convert = convFahrenheit(grau);
        printf("%.2f graus celsius equivalem a %.2f graus Fahrenheit;\n", grau, convert);
        break;
    
    case 'f':
        convert = convCelsius(grau);
        printf("%.2f graus Fahrenheit equivalem a %.2f graus celsius;\n", grau, convert);
        break;

    case 'F':
        convert = convCelsius(grau);
        printf("%.2f graus Fahrenheit equivalem a %.2f graus celsius;\n", grau, convert);
        break;      
    }
    return 0;
}