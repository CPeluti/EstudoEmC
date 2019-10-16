#include <stdio.h>
int main(){


	int k=0,i,tamanho1,tamanho2,z=0;
	scanf("%d %d",&tamanho1,&tamanho2);
	int matriz1[tamanho1][tamanho1],matriz2[tamanho2][tamanho2],matrizR[tamanho1][tamanho2];

	for(i=0;i<tamanho1;i++){
		for(z=0;z<tamanho1;z++){
			scanf("%d",&matriz1[i][z]);
			matrizR[i][z]=0;
		}
	}
	for(i=0;i<tamanho2;i++){
		for(z=0;z<tamanho2;z++){
			scanf("%d",&matriz2[i][z]);
		}
	}

	for(i=0;i<tamanho1;i++){
		for(z=0;z<tamanho2;z++){
			for(k=0;k<tamanho1;k++){
				matrizR[i][z]+=matriz1[i][k]*matriz2[k][z];
			}
		}
	}
	
	for(i=0;i<tamanho1;i++){
		for(z=0;z<tamanho2;z++){	
			printf("%d ",matrizR[i][z]);
		}
		printf("\n");
	} 
	return 0;
}