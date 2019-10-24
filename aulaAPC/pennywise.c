#include <stdio.h>
int main(){

	int tamanho,i,j,numero[4],z,k,aux;
	scanf("%d",&tamanho);
	int matriz[tamanho][tamanho];
	for(i=0;i<tamanho;i++){
		for(j=0;j<tamanho;j++){			
			numero[0]=i++;
			numero[1]=j++;
			numero[2]=tamanho-i;
			numero[3]=tamanho-j;
			for(z=0;z<4;z++){
				for(k=0;k<4;k++){
					if(numero[z]<numero[k]){
						aux=numero[z];
						numero[z]=numero[k];
						numero[k]=aux;
					}

				}
			}
			matriz[i][j]=numero[0];

		}

	}
	for(i =0;i<tamanho;i++){
		for(j=0;j<tamanho;j++){
			printf("%d ",matriz[i][j]);
		}
		printf("\n");
	}


	return 0;
}