//Renan Henrique Barreiro Souza			RA: 11202130682
#include <stdio.h>
#include <stdlib.h>
int wordcount(FILE* text){
	int n;
	char* aux = malloc(1000*sizeof(char));
	while(fscanf(text, "%s", &aux)!= EOF){
		n += 1;
	}
	return n;
}

int main(int argc, char* argv[]){
	int val;
	FILE* text;
	if(argc<2){
		printf("Arquivo não encontrado!\n");
		return 1;
	}
	else{
		text = fopen(argv[1],"r");
		if(text==NULL){
			printf("memoria insuficiente\n");
			return 1;
		}
		printf("arquivo lido!\n");
	}	
	val = wordcount(text);
	printf("numero de palavras eh: %d", val);
	fclose(text);
	return 0;
}