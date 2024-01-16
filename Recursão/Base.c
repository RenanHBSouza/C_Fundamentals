//Renan Henrique Barreiro Souza         RA: 11202130682
#include <stdio.h>

void gerar_combinacoes(int n, int *prefixo, int tamanho_prefixo, int atual, int tamanho_desejado) {
    if (tamanho_prefixo == tamanho_desejado) {
        // Base case: quando atingir o tamanho desejado, imprime a combinação atual
        for (int i = 0; i < tamanho_prefixo; i++) {
            printf("%d", prefixo[i]);
        }
        printf("\n");
        return;
    }
    
    for (int i = atual; i <= n; i++) {
        // Chamada recursiva para incluir o próximo número no prefixo
        prefixo[tamanho_prefixo] = i;
        gerar_combinacoes(n, prefixo, tamanho_prefixo + 1, i + 1, tamanho_desejado);
    }
}

int main() {
    // Obtém a entrada do usuário
    int n;
    printf("Digite um número positivo: ");
    scanf("%d", &n);

    // Aloca espaço para o array prefixo
    int prefixo[n];

    // Chama a função principal para cada tamanho de combinação
    for (int tamanho = 1; tamanho <= n; tamanho++) {
        gerar_combinacoes(n, prefixo, 0, 1, tamanho);
    }

    return 0;
}