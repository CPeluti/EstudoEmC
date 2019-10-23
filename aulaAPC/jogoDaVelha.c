#include <stdio.h>
#define LINHAS 3
#define COLUNAS 3
char matriz[3][3]={{'-','-','-'},{'-','-','-'},{'-','-','-'}}; /* matriz para armazenar os lances no tabuleiro */


/* Funcao que imprime o tabuleiro na tela */
int matrizPreenchida(){
	int i,j;
	for(i=0;i<LINHAS;i++){
		for(j=0;j<COLUNAS;j++){
			if(matriz[i][j]=='-'){
				return 0;
			}
		}
		
	}
	return 1;

}
void ImprimeJogo(){
	int i,j;
	printf("\n");
	for(i=0;i<LINHAS;i++){
		for(j=0;j<COLUNAS;j++){
			printf(" %c ",matriz[i][j]);
		}
		printf("\n");
	}
}

/* Funcao que armazena uma jogada no tabuleiro */
int AtualizaMatriz(int lin, int col, char tipo) {
	if(matriz[lin][col]=='-'){
		matriz[lin][col]=tipo;
		return 1;
	}else{
		return 0;
	}
}

/* Funcao que imprime as mensagens na tela */
int ImprimeStatus(int status) {
	if(status==0){
		printf("Posicao invalida\n");
		return 0;
	}else if(status==1){
		printf("Ganhou");
		return 1;
	}else if(status==2){
		printf("Empatou");
		return 2;
	}
	return 0;

}

/* Funcao que testa se a partida terminou */
int JogoTerminou() {

	if((matriz[0][0]=='O'&&matriz[0][1]=='O'&&matriz[0][2]=='O')||(matriz[0][0]=='X'&&matriz[0][1]=='X'&&matriz[0][2]=='X')){
		return 1; 
	}else if((matriz[0][0]=='O'&&matriz[1][1]=='O'&&matriz[2][2]=='O')||(matriz[0][0]=='X'&&matriz[1][1]=='X'&&matriz[2][2]=='X')){
		return 1; 
	}else if((matriz[0][0]=='O'&&matriz[1][0]=='O'&&matriz[2][0]=='O')||(matriz[0][0]=='X'&&matriz[1][0]=='X'&&matriz[2][0]=='X')){
		return 1; 
	}else if((matriz[0][2]=='O'&&matriz[1][2]=='O'&&matriz[2][2]=='O')||(matriz[0][2]=='X'&&matriz[1][2]=='X'&&matriz[2][2]=='X')){
		return 1; 
	}else if((matriz[0][2]=='O'&&matriz[1][1]=='O'&&matriz[2][0]=='O')||(matriz[0][2]=='X'&&matriz[1][1]=='X'&&matriz[2][0]=='X')){
		return 1; 
	}else if((matriz[2][0]=='O'&&matriz[2][1]=='O'&&matriz[2][2]=='O')||(matriz[2][0]=='X'&&matriz[2][1]=='X'&&matriz[2][2]=='X')){
		return 1; 
	}else if((matriz[1][1]=='O'&&matriz[0][1]=='O'&&matriz[2][1]=='O')||(matriz[1][1]=='X'&&matriz[0][1]=='X'&&matriz[2][1]=='X')){
		return 1; 
	}else if((matriz[1][1]=='O'&&matriz[1][0]=='O'&&matriz[1][2]=='O')||(matriz[1][1]=='X'&&matriz[1][0]=='X'&&matriz[1][2]=='X')){
		return 1; 
	}else if(matrizPreenchida()){
		return 2;
	}
	return 3;
}

int main()
{
	const char tipo[2] = {'X','O'};
	int lin, col, count = 0;

	while (1)
	{
		ImprimeJogo();
		if (ImprimeStatus(JogoTerminou()))
			break;
		scanf("%d %d", &lin, &col);
		if (!ImprimeStatus(AtualizaMatriz(lin, col, tipo[count])))
			count = (count + 1) % 2;
	}
	
	return 0;
}