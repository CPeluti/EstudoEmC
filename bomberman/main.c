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

typedef struct{
	char nomeJogador[20];
	char tabuleiro[15][28];
	int tempo;
	int tempo_partida;
	int numeroDeInimigos;
}partidaSalva;


char nome[20];

#ifdef _WIN32
#define CLEAR "cls"
#else 
#define CLEAR "clear"
#endif

/*matriz onde o jogo ocorrera*/
char tabuleiro[15][28];
/*tempo que falta para a bomba explodir*/
int tempo; 
/*tempo que falta para a partida acabar*/
int tempo_partida=DURACAO_PARTIDA;
/* tempo em segundos do momento atual*/
long int tempo_atual;
/*tempo em segundos de quado foi iniciado a jogatina*/
long int tempo_start;
/*tempo em que a bomba foi iniciada*/
long int tempo_start_bomba;
/*Posicao do boneco*/
/*PosicaoBoneco[0] é o eixo x & PosicaoBoneco[1] é o eixo y*/
int posicaoBoneco[2]={13,1};
/*numero de inimigos restantes*/
int numeroDeInimigos=0;
/*existe bomba*/
int existe_bomba=0;
/*posicao da bomba*/
int posicaoBomba[2];

void clear(){
	printf("\n");
	system(CLEAR);
}

void salvaJogo(){
	FILE* arquivo;
	partidaSalva save;
	int i;
	strcpy(save.nomeJogador,nome);
	for(i=0;i<15;i++){
		strcpy(save.tabuleiro[i],tabuleiro[i]);
	}
	save.tempo_partida=tempo_partida;
	save.tempo=tempo;
	save.numeroDeInimigos=numeroDeInimigos;
	arquivo=fopen("save.bin","a+b");
	fwrite(&save,sizeof(partidaSalva),1,arquivo);
	fclose(arquivo);
}

int atualizaTempo(){
	tempo_partida=DURACAO_PARTIDA-(tempo_atual-tempo_start);
	if(tempo_partida<=0){
		return 4;
	}else{
		return 404;
	}
}
int atualizaTempoBomba(){
	
	if((tempo-(tempo_atual-tempo_start_bomba))<=0){
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


int menu(int select){
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
			break;
		
		default:
			clear();
			printf("************************ BOMBERMAN ************************ \n");
			printf("\n");
			printf("\n");
			printf("\n");
			printf("1.\t JOGAR\n");
			printf("2.\t CONTINUAR JOGO\n");
			printf("3.\t RANKING\n");
			printf("4.\t SAIR\n");
			printf("\nOPCAO: ");
			char inputmenu;
			scanf("%c",&inputmenu);
			while(inputmenu!='1'&&inputmenu!='2'&&inputmenu!='3'&&inputmenu!='4'){
				inputmenu=getchar();
			}
			switch(inputmenu){
				case '1':
					return 1;
					break;
				case '2':
					return 2;
					break;
				case '3':
					return 3;
					break;
				case '4':
					return 4;
					break;
				default:
					return 0;
					break;
			}
			break;
	}
	return 0;

}

void criaBomba(){
	tabuleiro[posicaoBoneco[0]][posicaoBoneco[1]]='*';
	posicaoBomba[0]=posicaoBoneco[0];
	posicaoBomba[1]=posicaoBoneco[1];
	/*setta o tempo da bomba*/
	tempo=RAND(MEDIA_TEMPO,ERRO_TEMPO);
	/*salva o instante que a bomba foi colocada*/
	tempo_start_bomba=time(0);
	existe_bomba=1;

}
int explodeBomba(){
	int flag=404;
	if((tabuleiro[posicaoBomba[0]+1][posicaoBomba[1]]=='&')||(tabuleiro[posicaoBomba[0]-1][posicaoBomba[1]]=='&')||(tabuleiro[posicaoBomba[0]][posicaoBomba[1]+1]=='&')||(tabuleiro[posicaoBomba[0]][posicaoBomba[1]-1]=='&')||(posicaoBoneco[0]==posicaoBomba[0]&&posicaoBoneco[1]==posicaoBomba[1])){
		flag=2;
		tabuleiro[posicaoBoneco[0]][posicaoBoneco[1]]=' ';
	}
	if(tabuleiro[posicaoBomba[0]+1][posicaoBomba[1]]=='@'){
		numeroDeInimigos--;
		tabuleiro[posicaoBomba[0]+1][posicaoBomba[1]]=' ';

	}if(tabuleiro[posicaoBomba[0]-1][posicaoBomba[1]]=='@'){
		numeroDeInimigos--;
		tabuleiro[posicaoBomba[0]-1][posicaoBomba[1]]=' ';
	
	}if(tabuleiro[posicaoBomba[0]][posicaoBomba[1]+1]=='@'){
		numeroDeInimigos--;
		tabuleiro[posicaoBomba[0]][posicaoBomba[1]+1]=' ';
	
	}if(tabuleiro[posicaoBomba[0]][posicaoBomba[1]-1]=='@'){
		numeroDeInimigos--;
		tabuleiro[posicaoBomba[0]][posicaoBomba[1]-1]=' ';
	
	}if(tabuleiro[posicaoBomba[0]+1][posicaoBomba[1]]=='#'){
		numeroDeInimigos--;
		tabuleiro[posicaoBomba[0]+1][posicaoBomba[1]]=' ';
	
	}if(tabuleiro[posicaoBomba[0]-1][posicaoBomba[1]]=='#'){
		numeroDeInimigos--;
		tabuleiro[posicaoBomba[0]-1][posicaoBomba[1]]=' ';
	
	}if(tabuleiro[posicaoBomba[0]][posicaoBomba[1]+1]=='#'){
		numeroDeInimigos--;
		tabuleiro[posicaoBomba[0]][posicaoBomba[1]+1]=' ';
	
	}if(tabuleiro[posicaoBomba[0]][posicaoBomba[1]-1]=='#'){
		numeroDeInimigos--;
		tabuleiro[posicaoBomba[0]][posicaoBomba[1]-1]=' ';
	}
	tabuleiro[posicaoBomba[0]][posicaoBomba[1]]=' ';
	existe_bomba=0;
	return flag;	
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
				}else if(tabuleiro[posicaoBoneco[0]][posicaoBoneco[1]-1]=='@'){
					return 3;
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

				}else if(tabuleiro[posicaoBoneco[0]][posicaoBoneco[1]+1]=='@'){
					return 3;
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
				}else if(tabuleiro[posicaoBoneco[0]-1][posicaoBoneco[1]]=='@'){
					return 3;
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
				}else if(tabuleiro[posicaoBoneco[0]+1][posicaoBoneco[1]]=='@'){
					return 3;
				}else{
					return 1;
				}

			}else if(input=='E'||input=='e'){
				salvaJogo();
				return 0;

			}else if(input=='B'||input=='b'){
				if(!existe_bomba){
					criaBomba();
				}else{
					return 1;
				}
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
				if(numero < 5){
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
		clear();
			printaMatriz();
			printf("\nJogo finalizado com sucesso!\n");
			return 1;
			break;
		case 2:
			clear();
			printaMatriz();
			printf("\nQue pena, você se explodiu. Voce Perdeu!!\n");
			return 1;
			break;
		case 3:
			clear();
			printaMatriz();
			printf("\nQue pena, você foi morto por um inimigo. Voce Perdeu!!\n");
			return 1;
			break;
		case 4:
			clear();
			printaMatriz();
			printf("\nQue pena, Tempo esgotado. Voce Perdeu!!\n");
			return 1;
			break;
		case 5:
			clear();
			printaMatriz();
			printf("\nVitoria! todos os inimigos foram eliminados.\n");
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
	char inputMenu;
	while(1){
		int returnMenu=menu(0);
		if(returnMenu==4){
			return 0;
		}
		else if(returnMenu==1){
			printf("Digite seu nome: ");
			scanf("%s",nome);
			menu(1);
			inicializaTabuleiro();
			printf("Tecle <enter> para começar o jogo\n");
			while(1){
				inputMenu=getchar();
				if(inputMenu=='\n'){
					rotinaDeStart();
					break;
				}
			}		
			break;		
		}else if(returnMenu==2){
			int i;
			partidaSalva save;
			FILE* arquivo;
			arquivo=fopen("save.bin","rb");
			if(arquivo==NULL){
				printf("Nenhum jogo salvo foi encontrado\n");
				getchar();
			}else{
				fread(&save, sizeof(partidaSalva),1,arquivo);
				strcpy(nome,save.nomeJogador);
				for(i=0;i<15;i++){
					strcpy(tabuleiro[i],save.tabuleiro[i]);
				}
				tempo_partida=save.tempo_partida;
				tempo=save.tempo;
				numeroDeInimigos=save.numeroDeInimigos;
				tempo_start=time(0);
				tempo_atual=time(0);
				srand(time(0));
				break;
			}
		}
	}
	char input;
	int flag;

	if(inputMenu=='\n'){
		while(1){
			atualizaTempo();
			menu(2);
			printf("OPCAO: ");
			input=getchar();
			tempo_atual=time(0);
			if(existe_bomba){
				if(atualizaTempoBomba()==4){
					if(fimDeJogo(explodeBomba())){
						getchar();
						break;
					}
				}
			}
			flag=fimDeJogo(funcoesInput(input));
			if(fimDeJogo(atualizaTempo())){
				getchar();
				break;
			/*checa se precionou E*/
			}else if(flag){
				getchar();
				break;
			}else if(numeroDeInimigos==0){
				fimDeJogo(5);
				getchar();
				break;
			}
		}
		getchar();
		clear();
	}
	return 0;
}
