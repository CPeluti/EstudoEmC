#include <stdio.h>
int main(){
    char nome[99];
    double salariofixo,totalvendas;
    scanf("%s",nome);
    scanf("%lf",&salariofixo);
    scanf("%lf",&totalvendas);
    salariofixo=salariofixo+0.15*totalvendas;
    printf("TOTAL = R$ %.2lf\n",salariofixo);

    return 0;
}
    
    