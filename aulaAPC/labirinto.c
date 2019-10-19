#include <stdio.h>
int main(){

	char entrada,saida;
	int i,j,aux=1,linhas,colunas,quersaida,temsaida=5;/*não tem saida =0,saida norte =1,saida sul =2,saida oeste =3, saida leste =4,naosabe=5*/
	scanf("%c %c %d %d",&entrada,&saida,&linhas,&colunas);
	int matriz[linhas][colunas];
	for(i = 0;i<linhas;i++){
		for(j=0;j<colunas;j++){
			scanf("%d",&matriz[i][j]);
		}
	}
	switch(saida){
		case 'N':
			quersaida=1;
			break;
		case 'S':
			quersaida=2;
			break;
		case 'O':
			quersaida=3;
			break;
		case 'L':
			quersaida=4;
			break;
	}
	switch(entrada){

		case 'N':
			
			break;
		case 'S':

			break;
		case 'O':

			break;
		case 'L':

			break;

	}	
	if(temsaida==1){
		printf("Existe saida %C - N.",entrada);
	}else if(temsaida==2){
		printf("Existe saida %C - S.\n",entrada);
	}else if(temsaida==3){
		printf("Existe saida %C - O.\n",entrada);
	}else if(temsaida==4){
		printf("Existe saida %C - L.\n",entrada);
	}else if(temsaida==0){
		printf("Nao existe saida %C - %C.\n",entrada,saida);
	}



	return 0;
}

/**/
