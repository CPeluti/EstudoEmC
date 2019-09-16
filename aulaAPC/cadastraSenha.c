#include <stdio.h>
int main(){
    int numero,numero2;
    char letra1,letra2,letra3,letra4;
    scanf("%d%c%c",&numero,&letra1,&letra2);
    printf("informe a senha:");
    scanf("%d%c%c",&numero2,&letra3,&letra4);
    if(numero==numero2 && letra1==letra3 && letra2==letra4){
        printf("Senha correta !\n");
    }else if(letra1!=letra3 && letra2 != letra4){
        printf("Letras incorretas !\n");
    }else if(letra2 != letra4){
        printf("Segunda letra incorreta !\n");
    }else if(letra1 !=letra3){
        printf("Primeira letra incorreta !\n");
    }else if(numero != numero2){
        printf("Número incorreto !\n");
    }else if(letra1 != letra3 && numero != numero2){
        printf("Número e primeira letra incorretas !\n");
    }else if(letra2 != letra4 && numero != numero2){
        printf("Número e segunda letra incorretas !\n");
    }else{
        printf("Senha toda errada !\n");
    }
    return 0;
}