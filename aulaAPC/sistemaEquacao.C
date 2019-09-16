#include <stdio.h>
#include <math.h>
int main(){
    float real,resultado;
    
    scanf("%f",&real);

    if(real<0){
        resultado=real+2;
    }else if(real>=0 && real<=2){
        resultado=pow(real,3)+5*real+2;
    }else{ 
        resultado = real +5;
    }
    printf("%g",resultado);
    return 0;
}