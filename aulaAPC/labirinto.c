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
			if(temsaida==5){
				for(j=0;j<colunas;j++){
					if(!matriz[0][j]&&!matriz[1][j]){
						for(i=1;i<linhas;i++){
							if(!matriz[i+1][j]){
								i++;
								continue;
							}else if(!matriz[i][j+1]){
								j++;
								continue;
							}else if(!matriz[i][j-1]){
								j--;
								continue;
							}else{
								matriz[i][j]=1;
								aux=0;
								break;
							}
						}
					}
					
					else{
						temsaida=0;
						continue;
					}
					printf("%d %d\n",j,i);
					if(!aux){
						j=0;
						aux=1;
						continue;
					}

					
				}
				if(quersaida==2){
					if(i==linhas){
						temsaida=2;
						break;
					}
				}else if(quersaida==3){
					if(j==0){
						temsaida=3;
						break;
					}
				}else if(quersaida==4){
					if(j==colunas){
						temsaida=4;
						break;
					}
				}
			
				
			}

			break;
		case 'S':
			if(temsaida==5){
				for(j=0;j<colunas;j++){
					if(!matriz[0][j]&&!matriz[1][j]){
						for(i=linhas;i>0;i--){
							if(!matriz[i-1][j]){
								i--;
								continue;
							}else if(!matriz[i][j+1]){
								j++;
								continue;
							}else if(!matriz[i][j-1]){
								j--;
								continue;
							}else{
								matriz[i][j]=1;
								aux=0;
								break;
							}
						}
					}
					
					else{
						temsaida=0;
						continue;
					}
					printf("%d %d\n",j,i);
					if(!aux){
						j=0;
						aux=1;
						continue;
					}

					
				}
				if(quersaida==1){
					if(i==0){
						temsaida=1;
						break;
					}
				}else if(quersaida==3){
					if(j==0){
						temsaida=3;
						break;
					}
				}else if(quersaida==4){
					if(j==colunas){
						temsaida=4;
						break;
					}
				}
			
				
			}
			break;
		case 'O':
			break;
		case 'L':
			break;
	}	


	printf("%d",temsaida);

	return 0;
}

/**/
