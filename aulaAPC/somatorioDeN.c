#include <stdio.h>
int main(){

    int i=0;
    int quantidadeDeNumeros,numero;
    double resultado=0;
    scanf("%d\n",&quantidadeDeNumeros);
    while(i<quantidadeDeNumeros){
        scanf("%d",&numero);
        resultado+=numero;
        i++;
    }printf("%.2lf\n",resultado);

    return 0;
}