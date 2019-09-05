#include <stdio.h>
int main(){
    int codigo1,codigo2,pecas1,pecas2;
    double preco1,preco2,valorTotal;
    scanf("%d %d %lf",&codigo1,&pecas1,&preco1);
    scanf("%d %d %lf",&codigo2,&pecas2,&preco2);
    valorTotal=preco1*pecas1+preco2*pecas2;
    printf("VALOR A PAGAR: R$ %.2lf\n",valorTotal);
    return 0;
}