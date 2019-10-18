#include <stdio.h>
int main(){
    double resultado,valorDolar;
    int quantidadeDeDolar,lotes;
    scanf("%lf",&valorDolar);
    scanf("%d",&quantidadeDeDolar);
    scanf("%d",&lotes);
    resultado = (valorDolar*quantidadeDeDolar)*1.025;
    for(int i =1;i<=lotes;i++){
        printf("Lote: %d - Total da venda: R$ %.2lf\n",i,resultado);

    }
    
    return 0;
}