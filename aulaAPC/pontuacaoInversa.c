#include <stdio.h>

int main(){

    int i=0,pontuacoes[301];
    while(i<301){
        scanf("%d",&pontuacoes[i]);
        if(pontuacoes[i]<0){
            i--;
            break;
        }else{
            i++;
        }
    }
    while (i>=0){
        printf("%d ",pontuacoes[i]);
        i--;
    }
    

    return 0;
}