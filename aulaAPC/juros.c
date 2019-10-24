#include <stdio.h>

int main(){
    int i;
    double valor[13],redimento,conta=0,depositado=0;
    valor[12]=0;
    for(i=0;i<12;i++)
    {
        scanf("%lf",&valor[i]);
        depositado+=valor[i];
        conta+=valor[i];
        if(conta<10000){
            conta+=conta*0.0175;

        }else{
            conta+=conta*0.0225;

        }

    }
    redimento=conta-depositado;

    printf("%.2lf\n",redimento);
    return 0;
}