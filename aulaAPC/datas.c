#include <stdio.h>

//1 = dia; 2=horas; 3=minutos; 4=segundos;
int converteTempoSegundos(int tempo,int tipo){
    int resultado;
    switch (tipo){
        case 1:
            resultado = tempo*24*60*60;
            return resultado;
            break;
        case 2:
            resultado = tempo*60*60;
            return resultado;
            break;
        case 3:
            resultado = tempo*60;
            return resultado;
            break;
        default:
            return tempo;
    }
}
int main(){
    int dia1,dia2,hora1,hora2,minuto1,minuto2,segundo1,segundo2,resultado;
    scanf("%d %d:%d:%d",&dia1,&hora1,&minuto1,&segundo1);
    scanf("%d %d:%d:%d",&dia2,&hora2,&minuto2,&segundo2);
    resultado=converteTempoSegundos(dia2,1)-converteTempoSegundos(dia1,1)+\
    converteTempoSegundos(hora2,2)-converteTempoSegundos(hora1,2)+\
    converteTempoSegundos(minuto2,3)-converteTempoSegundos(minuto1,3)+segundo2-segundo1;
    if(resultado<0){
        printf("datas invalidas\n");
    }else {
        printf("%d dia(s)\n",resultado/(24*60*60));
        resultado -=((resultado/(24*60*60))*24*60*60); 
        printf("%d hora(s)\n",resultado/(60*60));
        resultado -=((resultado/(60*60))*60*60);
        printf("%d minuto(s)\n",(resultado/60));
        resultado -= (resultado/60)*60;
        printf("%d minuto(s)\n",(resultado));

    }
    return 0;
}