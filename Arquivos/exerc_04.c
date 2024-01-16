//Renan Henrique Barreiro Souza 		RA: 11202130682
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct img{
    int** matriz;
    int coluna;
    int linha;
}* Imagem;

void imprimir_mat(Imagem dado,FILE* saida){
    int i, j;
    fprintf(saida,"%s\n","P2");
    fprintf(saida,"%s\n","#Feito por Renan Souza");
    fprintf(saida,"%d %d\n",dado->coluna,dado->linha);
    fprintf(saida,"%d\n",255);
    for(i=0;i<dado->linha;i++){
        for(j=0;j<dado->coluna;j++){
            fprintf(saida,"%d ",dado->matriz[i][j]);
        }
        fprintf(saida,"%c",'\n');
    } 
    return;
}

Imagem mat_original(FILE* imagem){
    int cont = 0;
    Imagem val;
    val = malloc(sizeof(struct img));
    char aux;
    while(cont!=2){
        fscanf(imagem,"%c",&aux);
        if(aux=='\n'){
            cont+=1;
        }
    }
    fscanf(imagem,"%d",&val->coluna);
    fscanf(imagem,"%d",&val->linha);
    fscanf(imagem,"%d",&cont);
    val->coluna += 2;
    val->linha += 2;
    printf("%d %d\n",val->linha,val->coluna);
    val->matriz = calloc(val->linha, sizeof(int*));
    if(val==NULL){
        printf("Erro de memoria!");
        exit(1);
    }
    for(int i=0;i<val->linha;i++){
        val->matriz[i] = calloc(val->coluna,sizeof(int));
        if(val->matriz[i]==NULL){
            printf("Erro de memoria!");
            exit(1);
        }
    }
    for(int i=0;i<val->coluna;i++){
        val->matriz[0][i] = 255;
        val->matriz[val->linha-1][i] = 255;
    }

    for(int i=0;i<val->linha;i++){
        val->matriz[i][0] = 255;
        val->matriz[i][val->coluna-1] = 255;
    }

    for(int i=1;i<val->linha-1;i++){
        for(int j=1;j<val->coluna-1;j++){
            fscanf(imagem,"%d",&val->matriz[i][j]);
        }
    }
    return val;
}


void kernel_borrao(Imagem dado){
    double kernel[3][3] = {{1.0/9, 1.0/9, 1.0/9},
                        {1.0/9, 1.0/9, 1.0/9},
                        {1.0/9, 1.0/9, 1.0/9}};
    int i, j, m, n, val = 0;
    for(i=1;i<dado->linha-1;i++){
        for(j=1;j<dado->coluna-1;j++){
            for(m=-1;m<2;m++){
                for(n=-1;n<2;n++){
                    val += dado->matriz[i+m][j+n]*kernel[1+m][1+n];
                    //printf("%d*%lf = %d; ",dado->matriz[i+m][j+n],kernel[1+m][1+n],val);
                }
            }
            //printf("\n");
            if(val<0){
                val = 0;
            }
            if(val>255){
                val = 255;
            }
            dado->matriz[i][j] = val;
            val = 0;         
        }
    }
    return;
}

void kernel_borda(Imagem dado){
    int kernel[3][3] = {{0, 1, 0},
                        {1, -4, 1},
                        {0, 1, 0}};
    int i,j,m,n,val;

    for(i=1;i<dado->linha-1;i++){
        for(j=1;j<dado->coluna-1;j++){
            val=0;
            for(m=-1; m<=1;m++){
                for(n=-1;n<=1;n++){
                        val+=dado->matriz[i+m][j+n]*kernel[1+m][1+n];
                }
            }
            if (val < 0) {
                val = 0;
            } else if (val > 255) {
                val = 255;
            }
            dado->matriz[i][j] = val;
        }
    }
}

void destruir_imagem(Imagem dado){
    int i, j;
    for(i=0;i<dado->linha;i++){
        free(dado->matriz[i]);
    }
    free(dado->matriz);
    free(dado);
    return;
}

int main(int argc, char* argv[]){
    Imagem original;
    if(argc<3){
        printf("Falta de parâmetros!");
        return 1;
    }
    FILE* entrada = fopen(argv[2],"r");
    FILE* saida = fopen(argv[3],"w");
    if(entrada==NULL || saida==NULL){
        printf("Erro de leitura!");
        return 1;
    }
    original = mat_original(entrada);
    //printf("Sai");
    if(strcmp(argv[1],"borrao")==0){
        printf("%s\n", "borrao");
        kernel_borrao(original);
    }
    else if(strcmp(argv[1],"borda")==0){
        printf("%s\n", "borda");
        kernel_borda(original);
    }
    else{
        printf("Entrada invalida!");
    }
    imprimir_mat(original,saida);
    destruir_imagem(original);
    fclose(entrada);
    fclose(saida);

    return 0;
}