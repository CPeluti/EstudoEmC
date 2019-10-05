#include <stdio.h>
#include <string.h>

int main()
{
    int num_letras, i;/*retirei as variaveis length e a*/
    scanf("%d", &num_letras);/*num_letras é o tamanho da string*/
    char palavra[num_letras+1];/*mudei a ordem de declaração e coloquei num_letras+1 como tamanho(tanto de letras + \0)*/
    

    scanf("%s", palavra);
    
    i=0;
    while (i<num_letras){
        if(palavra[i]==palavra[(num_letras-1)-i]){/* aqui eu usei o proprio i pra pegar o final e ir decrementando, ja que conforme o i aumento, a posição (num_letras-1)-i diminui*/
            i++;
        }
        else
            i=num_letras+1;/*isso aqui tira do loop e serve pra não entrar no if*/
    }

    if (i==num_letras) /*tirei o if(i==1), ja que não me parece ser necessario*/
        printf("eh palindromo");
    else
        printf("nao eh palindromo");
    return 0;
}