#include <stdio.h>
int main(){

	int tamanho,i,j,k;
	scanf("%d",&tamanho);
	int matriz[tamanho][tamanho];

	for(k=0;k<tamanho;k++){
		for(i=k;i<tamanho-k;i++){			
			for(j=k;j<tamanho-k;j++){
				matriz[i][j]=k+1;
			}
		}
	}
	for(i =0;i<tamanho;i++){
		for(j=0;j<tamanho;j++){
			if(matriz[i][j]>=10){
				printf(" %d ",matriz[i][j]);
			}else{
				printf("  %d ",matriz[i][j]);
			}
		}
		printf("\n");
	}


	return 0;
}
