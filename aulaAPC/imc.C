#include <stdio.h>
#include <math.h>
int main(){

    float imc,altura;
    int peso;
    scanf("%d",&peso);
    scanf("%f",&altura);

    imc=peso/pow(altura,2);
    

    if(imc<=18.5 &&!(imc <=0)){
        printf("Abaixo do peso.\n");
    }else if(imc>18.5 && imc <=25){
        printf("Peso normal.\n");

    }else if(imc>25 && imc <=30){
        printf("Sobre peso.\n");
    }else if(imc >30 && imc <=35){
        printf("Obesidade grau 1.\n");
    }else if(imc > 35 && imc <=40){
        printf("Obesidade grau 2.\n");
    }else if(peso <=0 || altura <=0){
        printf("Resultado inválido.\n");
    }else if(imc > 40){
        printf("Obesidade grau 3.\n");
    }else{
        printf("Resultado inválido.\n");
    }
    
    return 0;
}