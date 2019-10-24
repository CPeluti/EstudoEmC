#include <stdio.h>
int main(){

    int numeroDeProdutos;
    double preco,total=0;

    do
    {
        scanf("%d ",&numeroDeProdutos);
        scanf("%lf",&preco);
        total+=numeroDeProdutos*preco;
    } while (numeroDeProdutos!=0);
    

    printf("%.2lf\n",total);

    return 0;
}