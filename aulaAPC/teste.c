
#include <stdio.h>
#include <stdlib.h>
#define CLEAR "clear"

void preencheMatriz(int linhas,int colunas,int numero,int matriz[linhas][colunas]){
	int i,j;
	for(i=0;i<linhas;i++){
		for(j=0;j<colunas;j++){
			matriz[i][j]=numero;	
		}
	}
}
void printMatriz(int linhas,int colunas,int matriz[linhas][colunas]){
	int i,j;
	system(CLEAR);
	for(i=0;i<linhas;i++){
		for(j=0;j<colunas;j++){
			printf("%d ",matriz[i][j]);
		}
		printf("\n");
	}
}

int main(){

	int matriz[3][3];
	preencheMatriz(3,3,9,matriz);
	printMatriz(3,3,matriz);



	return 0;
}