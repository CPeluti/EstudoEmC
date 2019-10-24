#include <stdio.h>

#define LINHAS 3
#define COLUNAS 3

int matriz[LINHAS][COLUNAS];

/* Insira a funcao LeMatriz() aqui */
void LeMatriz(){
    int i,j;
    for(i=0;i<LINHAS;i++){
        for(j=0;j<COLUNAS;j++){
            scanf("%d",&matriz[i][j]);
        }
    }
}
/* Insira a funcao ImprimeMatriz() aqui */
void ImprimeMatriz(){
    int i,j;
    for(i=0;i<LINHAS;i++){
        for(j=0;j<COLUNAS;j++){
            if((matriz[i][j]<100 && matriz[i][j]>=10)||(matriz[i][j]>-100 && matriz[i][j]<=-10)){
                printf(" %d ",matriz[i][j]);
            }else if((matriz[i][j]>100|| matriz[i][j]<-100)){
                printf("%d ",matriz[i][j]);
            }else{
                printf("  %d ",matriz[i][j]);
            }
        }
        printf("\n");
    }
}
int main()
{
	LeMatriz();
	ImprimeMatriz();
	
	return 0;
}