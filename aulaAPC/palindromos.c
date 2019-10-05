#include <stdio.h>
#include <string.h>

int main(){

int QuantidadeCarcteres, tamanhoString, i,aux=1;
char palindromo[101];

scanf("%d", &QuantidadeCarcteres);
scanf("%s", palindromo);

tamanhoString = strlen(palindromo) - 1;

i = 0;
while(tamanhoString > 0 && i < tamanhoString + 1){

    if(palindromo[i] != palindromo[tamanhoString]){

        aux=0;
        i = i + (tamanhoString + 1);
    }
    i++;
    tamanhoString--;

    /*if(palindromo[i] == palindromo[tamanhoString] && i != tamanhoString){
        i++;
        tamanhoString--;
    }

    if(palindromo[i] == palindromo[tamanhoString] && i == tamanhoString){
        printf("eh palindromo\n");
        i = i + (tamanhoString + 1);
    }*/
}
    if(aux){
        printf("eh palindromo");
    }else{
        printf("nao eh palindromo");
    }

return 0;
}
