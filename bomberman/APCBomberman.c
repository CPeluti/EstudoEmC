/*Universidade de Brasilia
Instituto de Ciencias Exatas
Departamento de Ciencia da Computacao
Algoritmos e Programacao de Computadores –
2/2019
Aluno(a): Caio Otavio Peluti Alencar
Matricula: 190085312
Turma: A
Versao do compilador: gcc 7.4.0
Descricao: Bombermand em C para jogar em command line*/

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


/*struct para salvar o jogo*/
typedef struct{
	char nomeJogador[20];
	char tabuleiro[15][28];
	int tempo;
	int tempo_partida;
	int numeroDeInimigos;
	int posicaoBoneco[2];
	int posicaoBomba[2];
	int existe_bomba;
}partidaSalva;

/*struct do ranking*/
typedef struct{
	char nomeJogador[21];
	int tempo_partida;
}tipoRanking;

char nome[21];

#ifdef _WIN32
#define CLEAR "cls"
#else 
#define CLEAR "clear"
#endif

int DURACAO_PARTIDA=200;
/*matriz onde o jogo ocorrera*/
char tabuleiro[15][28];
/*tempo que falta para a bomba explodir*/
int tempo; 
/*tempo que falta para a partida acabar*/
int tempo_partida;
/* tempo em segundos do momento atual*/
long int tempo_atual;
/*tempo em segundos de quado foi iniciado a jogatina*/
long int tempo_start;
/*tempo em que a bomba foi iniciada*/
long int tempo_start_bomba;
/*Posicao do boneco*/
/*PosicaoBoneco[0] eh o eixo x & PosicaoBoneco[1] eh o eixo y*/
int posicaoBoneco[2]={13,1};
/*numero de inimigos restantes*/
int numeroDeInimigos=0;
/*existe bomba*/
int existe_bomba=0;
/*posicao da bomba*/
/*posicaoBomba[0] eh o eixo x & posicaoBomba[1] eh o eixo y*/
int posicaoBomba[2];

/*limpa a tela*/
void clear(){
	printf("\n");
	system(CLEAR);
}
/*funcao para printar o ranking*/
void printaRanking(){
	int i,m=1;
	tipoRanking* vet;
	/*aloca o vetor vet*/
	vet=(tipoRanking*)malloc(sizeof(tipoRanking)*m);
	FILE* fd;
	fd=fopen("ranking.txt","r");	
	/*se o arquivo nao existir*/
	if(fd==NULL){
		printf("Nenhum ranking encontrado!");
	}else{
		/*enquanto nao for o final do arquivo*/
		while(!feof(fd)){
			/*realoca o espaco de acordo com a necessidade*/
			vet=(tipoRanking*)realloc(vet,m*sizeof(tipoRanking));
			fscanf(fd,"%s %d",vet[m-1].nomeJogador,&vet[m-1].tempo_partida);
			m++;
		}
	}
	/*printa o ranking armazenado no vetor vet*/
	for(i=0;i<m-1;i++){
		printf("%d\t%s\t%d\n",(i+1),vet[i].nomeJogador,vet[i].tempo_partida);
	}
	printf("\npressione <ENTER> para sair");
	fclose(fd);
	free(vet);
}
/*funcao para criar e/ou salvar o ranking*/
void criaRanking(){
	int i,m=0;
	tipoRanking* vet;
	vet=(tipoRanking*)malloc(sizeof(tipoRanking)*m);
	FILE* fd;
	fd=fopen("ranking.txt","r");	
	
	tipoRanking aux,aux2,atual;
	atual.tempo_partida=tempo_partida;
	strcpy(atual.nomeJogador,nome);
	
	/*se o arquivo nao existir*/
	if(fd==NULL){
		fd=fopen("ranking.txt","w");
		fprintf(fd,"%s %d",atual.nomeJogador,atual.tempo_partida);
	}else{
		/*enquanto nao for o fim do arquivo*/
		while(!feof(fd)){
			/*realoca vet de acordo com a necessidade e o preenche com a linha correspondente do arquivo*/
			m++;
			vet=(tipoRanking*)realloc(vet,m*sizeof(tipoRanking));
			fscanf(fd,"%s %d",vet[m-1].nomeJogador,&vet[m-1].tempo_partida);
		}
		/*aloca mais um espaco em vet para que possa colocar a valor do ranking atual*/
		vet=(tipoRanking*)realloc(vet,(m+1)*sizeof(tipoRanking));

		/*acha a posicao que o valor atual se encaixa*/
		for(i=0;i<m;i++){
			if(vet[i].tempo_partida<tempo_partida){
				aux=vet[i];
				vet[i]=atual;
				break;
			}
		}
		/*se nao achou nenhuma posicao, entao o valor se encaixa no final*/
		if(i==m){
			m++;
			vet[i]=atual;
		}
		else{
			/*se achou a posicao, reordene o resto do vetor*/
			m++;
			for(i=i+1;i<m;i++){
				aux2=vet[i];
				vet[i]=aux;
				aux=aux2;
			}
		}
		fclose(fd);

		/*escreve no arquivo o novo ranking*/
		fd=fopen("ranking.txt","w");
		for(i=0;i<m;i++){	
			fprintf(fd,"\n%s %d",vet[i].nomeJogador,vet[i].tempo_partida);
		}
	}
	fclose(fd);
	free(vet);
}
/*funcao para salvar o jogo*/
void salvaJogo(){
	FILE* arquivo;
	partidaSalva save;
	int i;
	strcpy(save.nomeJogador,nome);
	for(i=0;i<15;i++){
		strcpy(save.tabuleiro[i],tabuleiro[i]);
	}
	/*preenche as informacoes necessarias para o jogo na struct save*/
	save.tempo_partida=tempo_partida;
	save.tempo=tempo-(tempo_atual-tempo_start_bomba);
	save.numeroDeInimigos=numeroDeInimigos;
	save.posicaoBoneco[0]=posicaoBoneco[0];
	save.posicaoBoneco[1]=posicaoBoneco[1];
	save.posicaoBomba[0]=posicaoBomba[0];
	save.posicaoBomba[1]=posicaoBomba[1];
	save.existe_bomba=existe_bomba;
	arquivo=fopen("save.bin","w+b");
	/*escreve a struct save no arquivo binario*/
	fwrite(&save,sizeof(partidaSalva),1,arquivo);
	fclose(arquivo);
}
/*atualiza o tempo do jogo*/
int atualizaTempo(){
	tempo_partida=DURACAO_PARTIDA-(tempo_atual-tempo_start);
	if(tempo_partida<=0){
		return 4;
	}else{
		return 404;
	}
}
/*atualiza o tempo da bomba*/
int atualizaTempoBomba(){
	
	if((tempo-(tempo_atual-tempo_start_bomba))<=0){
		return 4;
	}else{
		return 404;
	}
}
/*inicializa o tabuleiro*/
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
/*funcao para printar matriz*/
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
/*mostra o menu escolhido*/
int menu(int select){
	int inputmenu=0;
			
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
		/*menu inicial*/
		default:

			while(inputmenu!=1&&inputmenu!=2&&inputmenu!=3&&inputmenu!=4){
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
				scanf("%d",&inputmenu);
			}
			return inputmenu;
			break;
	}
	return 0;
}
/*cria a bomba*/
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
/*evento de quando a bomba explode*/
int explodeBomba(){
	int flag=404;
	if((tabuleiro[posicaoBomba[0]+1][posicaoBomba[1]]=='&')||(tabuleiro[posicaoBomba[0]-1][posicaoBomba[1]]=='&')||(tabuleiro[posicaoBomba[0]][posicaoBomba[1]+1]=='&')||(tabuleiro[posicaoBomba[0]][posicaoBomba[1]-1]=='&')||(posicaoBoneco[0]==posicaoBomba[0]&&posicaoBoneco[1]==posicaoBomba[1])){
		flag=2;
		tabuleiro[posicaoBoneco[0]][posicaoBoneco[1]]=' ';
	}if((tabuleiro[posicaoBomba[0]+1][posicaoBomba[1]+1]=='&')||(tabuleiro[posicaoBomba[0]-1][posicaoBomba[1]-1]=='&')||(tabuleiro[posicaoBomba[0]+1][posicaoBomba[1]-1]=='&')||(tabuleiro[posicaoBomba[0]-1][posicaoBomba[1]+1]=='&')){
		flag=2;
		tabuleiro[posicaoBoneco[0]][posicaoBoneco[1]]=' ';
	
	}if(tabuleiro[posicaoBomba[0]+1][posicaoBomba[1]]=='@'){
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
		tabuleiro[posicaoBomba[0]+1][posicaoBomba[1]]=' ';
	
	}if(tabuleiro[posicaoBomba[0]-1][posicaoBomba[1]]=='#'){
		tabuleiro[posicaoBomba[0]-1][posicaoBomba[1]]=' ';
	
	}if(tabuleiro[posicaoBomba[0]][posicaoBomba[1]+1]=='#'){
		tabuleiro[posicaoBomba[0]][posicaoBomba[1]+1]=' ';
	
	}if(tabuleiro[posicaoBomba[0]][posicaoBomba[1]-1]=='#'){
		tabuleiro[posicaoBomba[0]][posicaoBomba[1]-1]=' ';
	}
	tabuleiro[posicaoBomba[0]][posicaoBomba[1]]=' ';
	existe_bomba=0;
	return flag;	
}
/*eventos de quando um botao foi pressionado durante o jogo*/
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
			/*cheat para testar condição de vitória*/
			}else if(input=='P'||input=='p'){
				return 5;
			}else{
				return 1;
			}
}
/*preenche o tabuleiro com inimigos e obstaculos*/
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
/*eventos de fim de jogo*/
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
			criaRanking();
			return 1;
			break;

		default:
			return 0;
			break;
	}
}
/*rotina de quando o jogo inicia*/
void rotinaDeStart(){
	tempo_start=time(0);
	tempo_atual=time(0);
	srand(time(0));
	preencheMatriz();
}
/*funcao main do jogo*/
int main(){
	char inputMenu;
	/*loop para o primeiro menu*/
	while(1){
		int returnMenu=menu(0);
		/* opcao 4 */
		/* fim do programa */
		if(returnMenu==4){
			return 0;
		}
		/* opcao 1 */
		else if(returnMenu==1){
			printf("Digite seu nome: ");
			getchar();
			scanf("%20s%*[^\n]",nome);
			
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
		/* opcao 2 */		
		}else if(returnMenu==2){
			int i;
			partidaSalva save;
			FILE* arquivo;
			arquivo=fopen("save.bin","rb");
			if(arquivo==NULL){
				clear();
				printf("Nenhum jogo salvo foi encontrado\n");
				getchar();
				printf("pressione <ENTER> para retornar ao menu");
				getchar();
			}else{
				fread(&save, sizeof(partidaSalva),1,arquivo);
				strcpy(nome,save.nomeJogador);
				for(i=0;i<15;i++){
					strcpy(tabuleiro[i],save.tabuleiro[i]);
				}
				DURACAO_PARTIDA=save.tempo_partida;
				tempo=save.tempo;
				numeroDeInimigos=save.numeroDeInimigos;
				posicaoBoneco[0]=save.posicaoBoneco[0];
				posicaoBoneco[1]=save.posicaoBoneco[1];
				posicaoBomba[0]=save.posicaoBomba[0];
				posicaoBomba[1]=save.posicaoBomba[1];
				existe_bomba=save.existe_bomba;
				tempo_start_bomba=time(0);
				tempo_start=time(0);
				tempo_atual=time(0);
				srand(time(0));
				fclose(arquivo);
				break;
			}
		/* opcao 3 */
		}else if(returnMenu==3){
			clear();
			printaRanking();
			getchar();
			getchar();
		}
	}
	char input;
	int flag;

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
		return 0;
	}
	
