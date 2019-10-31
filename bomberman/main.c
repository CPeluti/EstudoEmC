#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
/*valor medio que a bomba levara para explodir (segundos)*/
#define MEDIA_TEMPO 7
/* erro da medida de tempo que a bomba levara para explodir (segundos)*/
#define ERRO_TEMPO 3
/* expressao que gera um numero aleatorio no intervalo [M - E, M + E]*/
#define RAND(M,E) (M+(rand()%(2*E+1)-E))

#define DURACAO_PARTIDA 200

/*matriz onde o jogo ocorrera*/
char tabuleiro[15][28];
/*tempo que falta para a bomba explodir*/
int tempo; 
/*tempo que falta para a partida acabar*/
int tempo_partida=DURACAO_PARTIDA;

long int tempo_atual;

long int tempo_start;

/*Posição do boneco*/
/*PosicaoBoneco[0] é o eixo x & PosicaoBoneco[1] é o eixo y*/
int posicaoBoneco[2]={13,1};

int numeroDeInimigos=0;

void clear(){
	printf("\n");
	system("@cls||clear");
}


int atualizaTempo(){
	tempo_partida=DURACAO_PARTIDA-(tempo_atual-tempo_start);
	if(tempo_partida<=0){
		return 4;
	}else{
		return 404;
	}
}


void inicializaTabuleiro(){
	/*string das linhas*/
	char string[28]="| + + + + + + + + + + + + |";
	char string2[28]="|                         |";
	int i,j;
	for(j=1;j<26;j++){
		tabuleiro[0][0]=' ';
		tabuleiro[0][28]=' ';
		tabuleiro[0][j]='_';
		tabuleiro[14][j]='_';
		tabuleiro[14][0]='|';
		tabuleiro[14][26]='|';
	}
	for(i=2;i<13;i+=2){
		strcpy(tabuleiro[i],string);
	}

	for(i=1;i<14;i+=2){
		strcpy(tabuleiro[i],string2);
	}
}


void printaMatriz(){

	int i,j;
	
	for(i=0;i<15;i++){
		for(j=0;j<28;j++){
			printf("%c",tabuleiro[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}


void menu(int select){
	switch(select){
		case 1:
			clear();
			printf("************************ BOMBERMAN ************************ \n");
			printf("\n");
			printf("\n");
			printf("\n");
			printaMatriz();
			break;
		case 2:
			clear();
			
			printf("TEMPO: %d\n\n",tempo_partida);
			printf("A = ESQUERDA	 	D = DIREITA 	 	S = CIMA\nX = BAIXO 		B = BOMBA 		E = ENCERRAR\n");
			printaMatriz();
			printf("%d",tempo);
			break;
		default:
		break;
	}
}


int funcoesInput(int input){
	if(input=='A'||input=='a'){
				if((posicaoBoneco[1]-1)==0){
					return 1;
				}else if(tabuleiro[posicaoBoneco[0]][posicaoBoneco[1]-1]==' '){
					if(tabuleiro[posicaoBoneco[0]][posicaoBoneco[1]]=='*'){
						tabuleiro[posicaoBoneco[0]][posicaoBoneco[1]]='*';
						posicaoBoneco[1]-=1;
						tabuleiro[posicaoBoneco[0]][posicaoBoneco[1]]='&';
						return 1;
					}else{
						tabuleiro[posicaoBoneco[0]][posicaoBoneco[1]]=' ';
						posicaoBoneco[1]-=1;
						tabuleiro[posicaoBoneco[0]][posicaoBoneco[1]]='&';
						return 1;
					}	
				}else{
					return 1;
				}

			}else if(input=='D'||input=='d'){
				if((posicaoBoneco[1]+1)==28){
					return 1;
				}else if(tabuleiro[posicaoBoneco[0]][posicaoBoneco[1]+1]==' '){
					if(tabuleiro[posicaoBoneco[0]][posicaoBoneco[1]]=='*'){
						tabuleiro[posicaoBoneco[0]][posicaoBoneco[1]]='*';
						posicaoBoneco[1]+=1;
						tabuleiro[posicaoBoneco[0]][posicaoBoneco[1]]='&';
						return 1;
					}else{
						tabuleiro[posicaoBoneco[0]][posicaoBoneco[1]]=' ';
						posicaoBoneco[1]+=1;
						tabuleiro[posicaoBoneco[0]][posicaoBoneco[1]]='&';
						return 1;
					}
				}else{
					return 1;
				}

			}else if(input=='S'||input=='s'){
				if((posicaoBoneco[0]-1)==0){
					return 1;
				}else if(tabuleiro[posicaoBoneco[0]-1][posicaoBoneco[1]]==' '){
					if(tabuleiro[posicaoBoneco[0]][posicaoBoneco[1]]=='*'){
						tabuleiro[posicaoBoneco[0]][posicaoBoneco[1]]='*';
						posicaoBoneco[0]-=1;
						tabuleiro[posicaoBoneco[0]][posicaoBoneco[1]]='&';
						return 1;
					}else{
						tabuleiro[posicaoBoneco[0]][posicaoBoneco[1]]=' ';
						posicaoBoneco[0]-=1;
						tabuleiro[posicaoBoneco[0]][posicaoBoneco[1]]='&';
						return 1;
					}
				}else{
					return 1;
				}
			}else if(input=='X'||input=='x'){
				if((posicaoBoneco[0]+1)==0){
					return 1;
				}else if(tabuleiro[posicaoBoneco[0]+1][posicaoBoneco[1]]==' '){
					if(tabuleiro[posicaoBoneco[0]][posicaoBoneco[1]]=='*'){
						tabuleiro[posicaoBoneco[0]][posicaoBoneco[1]]='*';
						posicaoBoneco[0]+=1;
						tabuleiro[posicaoBoneco[0]][posicaoBoneco[1]]='&';
						return 1;
					}else{
						tabuleiro[posicaoBoneco[0]][posicaoBoneco[1]]=' ';
						posicaoBoneco[0]+=1;
						tabuleiro[posicaoBoneco[0]][posicaoBoneco[1]]='&';
						return 1;
					}
				}else{
					return 1;
				}

			}else if(input=='E'||input=='e'){
				return 0;

			}else if(input=='B'||input=='b'){

				return 1;
			}else{
				return 1;
			}
}


void preencheMatriz(){
	int i,j,numero;
	
	for(i=1;i<14;i++){
		for(j=1;j<27;j++){
			if(tabuleiro[i][j]==' '&&(i!=13||j!=1)){
				numero = RAND(10,10);
				if(numero < 10){
					tabuleiro[i][j]='#';
				}else if(numero<11&&numero>=10){
					tabuleiro[i][j]='@';
					numeroDeInimigos++;
				}else{
					continue;
				}
			}
		}
	}
	tabuleiro[posicaoBoneco[0]][posicaoBoneco[1]]='&';
}


int fimDeJogo(int type){
	switch(type){
		case 0:
			printf("Jogo finalizado com sucesso!\n");
			return 1;
			break;
		case 2:
			printf("Que pena, você se explodiu. Você Perdeu!!\n");
			return 1;
			break;
		
		case 4:
			printf("Que pena, Tempo esgotado. Você Perdeu!!\n");
			return 1;
			break;

		default:
			return 0;
			break;
	}
}


void rotinaDeStart(){

	tempo_start=time(0);
	tempo_atual=time(0);
	srand(time(0));
	preencheMatriz();
	
}


int main(){
	inicializaTabuleiro();
	menu(1);
	
	printf("Tecle <enter> para começar o jogo\n");

	char inputMenu=getchar();
	char input;
	int flag;

	if(inputMenu=='\n'){
		rotinaDeStart();
		while(1){
			atualizaTempo();
			menu(2);
			input=getchar();
			tempo_atual=time(0);
			flag=fimDeJogo(funcoesInput(input));
			if(fimDeJogo(atualizaTempo())){
				break;
			}else if(flag){
				break;
			}
			
		}
	}
	return 0;
}