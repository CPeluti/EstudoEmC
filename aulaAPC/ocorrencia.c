#include <stdio.h>
#include <string.h>
int main(){
    char string[1000],letra;
    int i=0,contador=0;
    scanf("%[^\n]",string);
    getchar();
    scanf("%c",&letra);
    if (letra >= 'A' && letra <= 'Z') {
            letra = letra + 32;
        }
    while(string[i]!='\0'){
        if (string[i] >= 'A' && string[i] <= 'Z') {
            string[i] = string[i] + 32;
        }
        i++;
    }
    int tamanhoString = strlen(string)-1;
    i=0;
    while(i<=tamanhoString){
        if(string[i]==letra){
            contador++;
        }
        i++;
    }
    printf("%d\n",contador);
    
    return 0;
}