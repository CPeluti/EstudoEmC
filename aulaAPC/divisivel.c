#include <stdio.h>

int main(){
    int numero;
    scanf("%d",&numero);
    if(numero % 5 ==0 && numero%2==0){printf("Eh divisivel por 2 e 5\n");}
    else if(numero % 5 ==0 && numero%2!=0){printf("Eh divisivel por 5 mas nao por 2\n");}
    else if(numero % 5 !=0 && numero%2==0){printf("Eh divisivel por 2 mas nao por 5\n");}
    else if(numero % 5 !=0 && numero%2!=0){printf("Nao eh divisivel nem por 2 e nem por 5\n");}
    
    return 0;
}