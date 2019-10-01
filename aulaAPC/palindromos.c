#include <stdio.h>
#include <string.h>

int main(){
    int i,j,tamanho,aux=1;
    scanf("%d",&tamanho);
    char string[tamanho+1];
    scanf("%s",string);

    i=tamanho-1;
    j=0;
    while(j<tamanho)
    {
        if(string[i]!=string[j])
        {
            aux=0;
            break;
        }
        i--;
        j++;
    }
    if(aux)
    {
        printf("eh palindromo\n");
    }else
    {
        printf("nao eh palindromo\n");
    }
    
    return 0;
}   