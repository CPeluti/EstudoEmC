#include<stdio.h>
#include<string.h>


int main(){
    int i=0,j=0,aux=0;
    char string[101],substring[101];
    scanf("%s",string);
    scanf("%s",substring);
    int tamanhoString=strlen(string),tamanhoSubString=strlen(substring);
    while (i<tamanhoString-tamanhoSubString)
    {
        j=0;
        while (j<tamanhoSubString)
        {
            if(string[i+j]==substring[j]){

            }else
            {
               
                break;
            }
            
            j++;
        }
        if(j == tamanhoSubString) aux = 1;
        
        i++;
    }
    if(aux){
        printf("Achei substring.\n");
    }else{
        printf("Nao achei substring.\n");
    }


    return 0;
}