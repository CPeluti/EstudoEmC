#include <stdio.h>
int minutosHoras(int horas){
    int minutos;
    minutos = horas*60;
    return minutos;
}
int main(){
    int horario[21];
    int horarioEmMinutos[11];
    int horasNecessarias;
    int minutoNecessarios;
    int horasExtras;
    int minutoExtras;
    const int horas = 480;
    scanf("%d:%d %d:%d",&horario[1],&horario[2],&horario[3],&horario[4]);
    scanf("%d:%d %d:%d",&horario[5],&horario[6],&horario[7],&horario[8]);
    scanf("%d:%d %d:%d",&horario[9],&horario[10],&horario[11],&horario[12]);
    scanf("%d:%d %d:%d",&horario[13],&horario[14],&horario[15],&horario[16]);
    scanf("%d:%d %d:%d",&horario[17],&horario[18],&horario[19],&horario[20]);
    for(int i =1;i<=20;i+=2){
        horario[i]=minutosHoras(horario[i]);
    }
    for(int i=1;i<20;i+=2){
        horarioEmMinutos[i/2] = horario[i]+horario[i+1];
    }
    for(int i=1;i<10;i+=2){
        if((horarioEmMinutos[i+1]-horarioEmMinutos[i]) == horas){
            horasNecessarias +=0;
            minutoNecessarios+=0;
        }
        if((horarioEmMinutos[i+1]-horarioEmMinutos[i]) < horas){
            horasNecessarias+=(horas-(horarioEmMinutos[i+1]-horarioEmMinutos[i]))/60;
            minutoNecessarios+=(horasNecessarias-(horarioEmMinutos[i+1]-horarioEmMinutos[i]));

        }
        else{
            horasExtras+=((horarioEmMinutos[i+1]-horarioEmMinutos[i])-horas)/60;
            minutoExtras+=(horarioEmMinutos[i+1]-horarioEmMinutos[i])-horasExtras;
        }    
    }
    if(horasExtras<horasNecessarias){
        hora
    }
    
    
    return 0;
}