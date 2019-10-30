#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
/*valor medio que a bomba levara para explodir (segundos)*/
#define MEDIA_TEMPO 7
/* erro da medida de tempo que a bomba levara para explodir (segundos)*/
#define ERRO_TEMPO 3
/* expressao que gera um numero aleatorio no intervalo [M - E, M + E]*/
#define RAND(M, E) (M + (rand()%(2*E + 1) – E))
/*matriz onde o jogo ocorrera*/
char tabuleiro[15][28];
/*tempo que falta para a bomba explodir*/
int tempo; 
/*tempo que falta para a partida acabar*/
int tempo_partida;
/* tempo em que o jogo foi iniciado*/
int tempo_start;

void clear(){
	printf("\n");
	system("@cls||clear");
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
void menu(){
	clear();
	printf("************************ BOMBERMAN ************************ \n");
	printf("\n");
	printf("\n");
	printf("\n");
	printaMatriz();
}
void preencheMatriz(seed){

}
void rotinaDeStart(){
	
	srand(time(0));
	tempo_partida=200;
}

int main(){
	inicializaTabuleiro();
	menu();
	/*loop do jogo*/
	printf("Tecle <enter> para começar o jogo\n");
	char inputMenu=getchar();
	if(inputMenu=='\n'){
		printf("teste");
	}
	return 0;
}