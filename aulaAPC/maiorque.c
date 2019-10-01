#include <stdio.h>
int main(){
    int numeroDeEntradas;
    int i =0;
    int maior,menor,numero;
    scanf("%d",&numeroDeEntradas);
    while(i < numeroDeEntradas){
        scanf("%d",&numero);
        if(i ==0){
            maior = numero;
            menor = numero;
            i++;
        }else{
            if(numero > maior){
                maior = numero;
            }else if(numero < menor){
                menor= numero;
            }
            i++;
        }
    }
    printf("%d %d\n",menor, maior);





    return 0;
}