#include <stdio.h>

int main(){

	char entrada,saida;
	int flag=0,i,j,linhas,colunas,posEntrada,temSaida=0,aux=0;
	scanf("%c %c %d %d",&entrada,&saida,&linhas,&colunas);
	int matriz[linhas][colunas];
	for(i=0;i<linhas;i++){
		for(j=0;j<colunas;j++){
			scanf("%d",&matriz[i][j]);
		}
	}
	switch (entrada)
	{
	case 'N':
		while(flag==0){
			for(j=0;j<colunas;j++){
				if(!matriz[0][j]&&!matriz[1][j]){
					posEntrada=j;/*Achou a posição de entrada*/
					flag=0;
					break;
				}else{
					temSaida=0;
					flag=1;
					
				}
			}
			i=0;
			j=posEntrada;
			while(aux==0&&flag==0){
				if(matriz[i+1][j]==0){
					matriz[i][j]=2;
					i++;
				}else if(matriz[i][j+1]==0){
					matriz[i][j]=2;
					j++;
				}else if(matriz[i][j-1]==0){
					matriz[i][j]=2;
					j--;
				}else if(matriz[i-1][j]==0&&(i-1>0)){
					matriz[i][j]=2;
					i--;
				}else{
					matriz[i][j]=1;
					for(i=0;i<linhas;i++){
						for(j=0;j<colunas;j++){
							if(matriz[i][j]==2){
								matriz[i][j]=0;
							}
						}
					}
					break;
				/*trabalha com a saida*/
				/*se quer saida sul*/
				}if(saida=='S'){
					if(i==linhas-1&&matriz[i][j]==0){
						temSaida=2;
						aux=1;
						flag=1;
						break;
					}else if(i==linhas-1&&matriz[i][j]!=0){
						temSaida=0;
						aux=1;
						flag=1;
						break;
					}
				/*se quer saida oeste*/
				}else if(saida=='O'){
					if(j==0&&matriz[i][j]==0){
						temSaida=3;
						aux=1;
						flag=1;
						break;
					}else if(j==0&&matriz[i][j]!=0){
						temSaida=0;
						aux=1;
						flag=1;
						break;
					}
				/*se quer saida leste*/
				}else if(saida=='L'){
					if(j==colunas-1&&matriz[i][j]==0){
						temSaida=4;
						aux=1;
						flag=1;
						break;
					}else if(j==colunas-1&&matriz[i][j]!=0){
						temSaida=0;
						aux=1;
						flag=1;
						break;
					}
				}
			}
		}

		break;
	case 'S':
		while(flag==0){
			for(j=0;j<colunas;j++){
				if(!matriz[linhas-1][j]&&!matriz[linhas-2][j]){
					posEntrada=j;/*Achou a posição de entrada*/
					flag=0;
					break;
				}else{
					temSaida=0;
					flag=1;
					
				}
			}
			i=linhas-1;
			j=posEntrada;
			while(aux==0&&flag==0){
				if(matriz[i-1][j]==0){
					matriz[i][j]=2;
					i--;
				}else if(matriz[i][j+1]==0){
					matriz[i][j]=2;
					j++;
				}else if(matriz[i][j-1]==0){
					matriz[i][j]=2;
					j--;
				}else if(matriz[i+1][j]==0&&(i+1<linhas)){
					matriz[i][j]=2;
					i++;
				}else{
					matriz[i][j]=1;
					for(i=0;i<linhas;i++){
						for(j=0;j<colunas;j++){
							if(matriz[i][j]==2){
								matriz[i][j]=0;
							}
						}
					}
					break;
				/*trabalha com a saida*/
				/*se quer saida norte*/
				}if(saida=='N'){
					if(i==0&&matriz[i][j]==0){
						temSaida=1;
						aux=1;
						flag=1;
						break;
					}else if(i==0&&matriz[i][j]!=0){
						temSaida=0;
						aux=1;
						flag=1;
						break;
					}
				/*se quer saida oeste*/
				}else if(saida=='O'){
					if(j==0&&matriz[i][j]==0){
						temSaida=3;
						aux=1;
						flag=1;
						break;
					}else if(j==0&&matriz[i][j]!=0){
						temSaida=0;
						aux=1;
						flag=1;
						break;
					}
				/*se quer saida leste*/
				}else if(saida=='L'){
					if(j==colunas-1&&matriz[i][j]==0){
						temSaida=4;
						aux=1;
						flag=1;
						break;
					}else if(j==colunas-1&&matriz[i][j]!=0){
						temSaida=0;
						aux=1;
						flag=1;
						break;
					}
				}
			}
		}
		break;
	case 'O':
		while(flag==0){
			for(i=0;i<linhas;i++){
				if(!matriz[i][0]&&!matriz[i][1]){
					posEntrada=i;/*Achou a posição de entrada*/
					flag=0;
					break;
				}else{
					temSaida=0;
					flag=1;
					
				}
			}
			j=0;
			i=posEntrada;
			while(aux==0&&flag==0){
				if(matriz[i][j+1]==0){
					matriz[i][j]=2;
					j++;
				}else if(matriz[i+1][j]==0){
					matriz[i][j]=2;
					i++;
				}else if(matriz[i-1][j]==0){
					matriz[i][j]=2;
					i--;
				}else if(matriz[i][j-1]==0&&(j-1>0)){
					matriz[i][j]=2;
					j--;
				}else{
					matriz[i][j]=1;
					for(i=0;i<linhas;i++){
						for(j=0;j<colunas;j++){
							if(matriz[i][j]==2){
								matriz[i][j]=0;
							}
						}
					}
					break;
				/*trabalha com a saida*/
				/*se quer saida norte*/
				}if(saida=='N'){
					if(i==0&&matriz[i][j]==0){
						temSaida=1;
						aux=1;
						flag=1;
						break;
					}else if(i==0&&matriz[i][j]!=0){
						temSaida=0;
						aux=1;
						flag=1;
						break;
					}
				/*se quer saida sul*/
				}else if(saida=='S'){
					if(i==linhas&&matriz[i][j]==0){
						temSaida=2;
						aux=1;
						flag=1;
						break;
					}else if(i==linhas&&matriz[i][j]!=0){
						temSaida=0;
						aux=1;
						flag=1;
						break;
					}
				/*se quer saida leste*/
				}else if(saida=='L'){
					if(j==colunas-1&&matriz[i][j]==0){
						temSaida=4;
						aux=1;
						flag=1;
						break;
					}else if(j==colunas-1&&matriz[i][j]!=0){
						temSaida=0;
						aux=1;
						flag=1;
						break;
					}
				}
			}
		}
		break;
	case 'L':
		while(flag==0){
			for(i=0;i<linhas;i++){
				if(!matriz[i][colunas-1]&&!matriz[i][colunas-2]){
					posEntrada=i;/*Achou a posição de entrada*/
					flag=0;
					break;
				}else{
					temSaida=0;
					flag=1;
					
				}
			}
			j=colunas-1;
			i=posEntrada;
			while(aux==0&&flag==0){
				if(matriz[i][j-1]==0){
					matriz[i][j]=2;
					j--;
				}else if(matriz[i+1][j]==0){
					matriz[i][j]=2;
					i++;
				}else if(matriz[i-1][j]==0){
					matriz[i][j]=2;
					i--;
				}else if(matriz[i][j+1]==0&&(j+1<colunas)){
					matriz[i][j]=2;
					j++;
				}else{
					matriz[i][j]=1;
					for(i=0;i<linhas;i++){
						for(j=0;j<colunas;j++){
							if(matriz[i][j]==2){
								matriz[i][j]=0;
							}
						}
					}
					break;
				/*trabalha com a saida*/
				/*se quer saida norte*/
				}if(saida=='N'){
					if(i==0&&matriz[i][j]==0){
						temSaida=1;
						aux=1;
						flag=1;
						break;
					}else if(i==0&&matriz[i][j]!=0){
						temSaida=0;
						aux=1;
						flag=1;
						break;
					}
				/*se quer saida sul*/
				}else if(saida=='S'){
					if(i==linhas&&matriz[i][j]==0){
						temSaida=2;
						aux=1;
						flag=1;
						break;
					}else if(i==linhas&&matriz[i][j]!=0){
						temSaida=0;
						aux=1;
						flag=1;
						break;
					}
				/*se quer saida leste*/
				}else if(saida=='O'){
					if(j==0&&matriz[i][j]==0){
						temSaida=3;
						aux=1;
						flag=1;
						break;
					}else if(j==0&&matriz[i][j]!=0){
						temSaida=0;
						aux=1;
						flag=1;
						break;
					}
				}
			}
		}
		break;	
	default:
		break;
	}
	if(temSaida==0){
		printf("Nao existe saida %c - %c.\n",entrada,saida);
	}else if(temSaida>=1)
	{
		printf("Existe saida %c - %c.\n",entrada,saida);
	}
	
	return 0;
}

/*
N S 4 6
1 1 1 1 0 1
1 1 1 1 0 1
1 0 0 0 0 1
1 0 1 1 1 1
*/