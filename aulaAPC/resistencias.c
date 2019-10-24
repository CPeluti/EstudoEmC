#include<stdio.h>
int main(){
    int i;
    double resistencia[6],resultado=0,paralelo=0,maior=0,media=0,diferenca;

    for(i=0;i<6;i++){

        scanf("%lf",&resistencia[i]);
    }

    for(i=0;i<6;i++){
        if(resistencia[i]>maior){
            maior = resistencia[i];
        }
        media+=resistencia[i];
        resultado+=resistencia[i];

    }
    paralelo=1/resultado;
    media = media/6;
    diferenca=maior-media;

    printf("%.4lf %.4lf %.4lf\n",resultado,paralelo,diferenca);
    return 0;
}