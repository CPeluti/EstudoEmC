#include <stdio.h>
int main(){
    float peso,altura;
    scanf("%f",&altura);
    peso = (72.7 * altura) - 58.0;
    printf("%.1f",peso);
    return 0;
}