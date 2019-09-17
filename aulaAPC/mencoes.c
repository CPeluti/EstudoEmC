#include <stdio.h>
int main (){
    int faltas;
    float mediaNumerica;
    scanf("%f %d",&mediaNumerica ,&faltas);
    if(faltas>25){
        printf("SR\n");
    }
    else {
            if (mediaNumerica<=10 && mediaNumerica>=9){printf("SS\n");}
            else if ((9.0>mediaNumerica)&&(mediaNumerica>=7.0)){printf("MS\n");}
            else if ((7.0>mediaNumerica)&&(mediaNumerica>=5.0)){printf("MM\n");}
            else if ((5.0>mediaNumerica)&&(mediaNumerica>=3.0)){printf("MI\n");}
            else if ((3.0>mediaNumerica)&&(mediaNumerica>0)){printf("II\n");}
            else{printf("SR\n");}
    } 
    return 0;
}