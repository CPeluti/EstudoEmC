#include <stdio.h>

int maior_valor(int n1,int n2, int n3){
    int i,aux,vetor[]={n1,n2,n3};
    for(i=0;i<3;i++){
        if(vetor[i]>vetor[i+1]){
            aux=vetor[i];
            vetor[i]=vetor[i+1];
            vetor[i+1]=aux;
        }
    }
    return vetor[2];
}

int main()
{
	int n1,n2,n3;
	
	scanf("%d %d %d", &n1, &n2, &n3);
	printf("%d\n", maior_valor(n1,n2,n3));
	
	return 0;
}