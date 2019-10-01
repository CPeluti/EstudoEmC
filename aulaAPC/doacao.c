#include <stdio.h>
int main(){

    int i,tamanho,n;
    scanf("%d %d",&n,&tamanho);
    int doacao[n],will[n],calcados[n];
    doacao[0]=0;will[0]=0;

    i=0;
    while(i<n){
        scanf("%d",&calcados[i]);
        if(calcados[i]<tamanho){
            doacao[i]=calcados[i];
            will[i]=0;
        }else{
            will[i]=calcados[i];
            doacao[i]=0;
        }
        i++;
    }
    i=0;
    printf("Will: ");
    while (i<n)
    {
        
        if(doacao[0]==0&&i==0){
            printf("0");
            break;
        }else if(doacao[i]==0){
        }else
        {
            printf("%d ",will[i]);
        }
    }
    printf("\nDoacao: ");
    i=0;
    while (i<n)
    {
        if(doacao[i]==0&&i==0){
            printf("0");
            break;
        }else if(doacao[i]==0){
        }else
        {
            printf("%d ",doacao[i]);
        }
        
        i++;
    }
    


    return 0;
}