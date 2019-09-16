#include <stdio.h>

int main(){
    int idade;
    float peso;
    scanf("%d",&idade);
    scanf("%f",&peso);
    if(peso >= 50 && (idade>=16 && idade <= 69)){
        printf("É doador\n");
    }else{
        printf("Não é doador\n");
    }
    return 0;
}