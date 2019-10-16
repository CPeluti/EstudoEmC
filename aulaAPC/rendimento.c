#include <stdio.h>
int main(){

	int i,z,linhas,colunas;
	scanf("%d %d",&linhas,&colunas);
	int matriz1[linhas][colunas],matriz2[linhas][colunas],matrizR[linhas][colunas];
	for(i=0;i<linhas;i++){
		for(z=0;z<colunas;z++){
			scanf("%d",&matriz1[i][z]);
		}
	}
	for(i=0;i<linhas;i++){
		for(z=0;z<colunas;z++){
			scanf("%d",&matriz2[i][z]);
		}
	}
	for(i=0;i<linhas;i++){
		for(z=0;z<colunas;z++){
			matrizR[i][z]=matriz1[i][z]-matriz2[i][z];
		}
	}
	for(i=0;i<linhas;i++){
		for(z=0;z<colunas;z++){
			printf("%d ",matrizR[i][z]);
		}

