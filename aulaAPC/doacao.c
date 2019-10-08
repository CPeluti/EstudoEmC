#include <stdio.h>
int main(){

    int i,tamanho,n,aux=1;
    scanf("%d %d",&n,&tamanho);
    int doacao[n],will[n],calcados[n];

    i=0;
    while(i<n){
        scanf("%d",&calcados[i]);
        if(calcados[i]>=tamanho)
        {
             will[i]=calcados[i];
            doacao[i]=0;
            
        }else 
        {
           doacao[i]=calcados[i];
           will[i]=0;
        }
        i++;
    }
    i=0;
    printf("Will: ");
    while (i<n+1){
        if(i == n&&aux){
            printf("0");
        }
        if(will[i]&&i!=n){
            printf("%d ", will[i]);
            aux = 0;

        }
        i++;
    }
    printf("\nDoacao: ");
    i=0;
    aux=1;
    while (i<n+1)
    {
        if(i==n&&aux)
        {
            printf("0 ");
            aux=1;
        }
        if(doacao[i]&&i!=n)
        {
            printf("%d ",doacao[i]);
            aux=0;
        }
        
        i++;
    }
    


    return 0;
}