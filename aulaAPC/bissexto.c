#include <stdio.h>
 int main(){
    int ano;
    scanf("%d",&ano);
    if((ano%400)==0){
        printf("Sim\n");
    }else if((ano%100)==0){
        printf("Naum\n");
    }else if((ano%4)==0){
        printf("Sim\n");
    }else{
        printf("Naum\n");
    }
    return 0;
 }