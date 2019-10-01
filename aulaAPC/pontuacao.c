#include <stdio.h>
int main(){
    int i=0,j=0,tamanho,auxNumero,auxPosicao,auxNumero1,auxPosicao1;
    scanf("%d",&tamanho);
    int numeros[tamanho];
    while (i<tamanho){
        scanf("%d",&numeros[i]);
        i++;
    }
    auxNumero1=numeros[0];
    auxNumero=numeros[0];
    auxPosicao1 = 0;
    auxPosicao = 0;
    while (j<tamanho){
        if(numeros[j]>auxNumero1){
            auxNumero1 = numeros[j];
            auxPosicao1=j;
        }else if(numeros[j]<auxNumero){
            auxNumero=numeros[j];
            auxPosicao=j;
        }
        j++;
    }
    
    i = 0;
    printf("%d %d\n",auxNumero,auxPosicao);
    printf("%d %d\n",auxNumero1,auxPosicao1);
    while(i<tamanho){
        printf("%d ",numeros[i]);
        i++;
    }


}