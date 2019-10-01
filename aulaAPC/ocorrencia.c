#include <stdio.h>
#include <string.h>
int main(){
    char string[1000],letra,i=0,contador=0;
    scanf("%s",string);
    scanf("%c",&letra);
    int tamanhoString = strlen(string);
    printf("%d",tamanhoString);
    /*while (i<tamanhoString)
    {
        if(string[i]==letra)
        {
            contador++;
        }
        i++;
    }
    printf("%d",contador);
    */
    return 0;
}