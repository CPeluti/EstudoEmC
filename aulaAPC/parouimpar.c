#include <stdio.h>

int main(){

	int numero;
	
	do{
		scanf("%d",&numero);
		int pares[numero];
		if((numero%2)==1){
			printf("O numero %d eh impar\n",numero);
			break;
		}else{
			for(int i=0;i<=numero;i++){
				if((i%2)==0){
					pares[i] = i;
				}else{}
			}
		
			int tamanhoPares = sizeof(pares)/sizeof(pares[0]);
			printf("Os numeros pares ate %d sao: ",numero);
			for(int i =0;i<=tamanhoPares;i++){
				if((i%2)==0){
				printf("%d ",pares[i]);
				}else{}
				
			}
		}
	
	}while((numero%2)!=0);
	



	return 0;
}
