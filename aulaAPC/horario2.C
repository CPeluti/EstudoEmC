#include <stdio.h>
#include<stdlib.h>
int main(){
    int hora1,hora2,minuto1,minuto2,tempo=0;
    scanf("%d:%d %d:%d",&hora1,&minuto1,&hora2,&minuto2);
    if (((hora2*60+minuto2)-(hora1*60+minuto1))>=480){
        tempo += ((hora2*60+minuto2)-(hora1*60+minuto1)) - 480;
    }else{
        tempo -= 480 -((hora2*60+minuto2)-(hora1*60+minuto1));
    }
    scanf("%d:%d %d:%d",&hora1,&minuto1,&hora2,&minuto2);
    if (((hora2*60+minuto2)-(hora1*60+minuto1))>=480){
        tempo += ((hora2*60+minuto2)-(hora1*60+minuto1)) - 480;
    }else{
        tempo -= 480 -((hora2*60+minuto2)-(hora1*60+minuto1));
    }
    scanf("%d:%d %d:%d",&hora1,&minuto1,&hora2,&minuto2);
    if (((hora2*60+minuto2)-(hora1*60+minuto1))>=480){
        tempo += ((hora2*60+minuto2)-(hora1*60+minuto1)) - 480;
    }else{
        tempo -= 480 -((hora2*60+minuto2)-(hora1*60+minuto1));
    }
    scanf("%d:%d %d:%d",&hora1,&minuto1,&hora2,&minuto2);
    if (((hora2*60+minuto2)-(hora1*60+minuto1))>=480){
        tempo += ((hora2*60+minuto2)-(hora1*60+minuto1)) - 480;
    }else{
        tempo -= 480 -((hora2*60+minuto2)-(hora1*60+minuto1));
    }
    scanf("%d:%d %d:%d",&hora1,&minuto1,&hora2,&minuto2);
    if (((hora2*60+minuto2)-(hora1*60+minuto1))>=480){
        tempo += ((hora2*60+minuto2)-(hora1*60+minuto1)) - 480;
    }else{
        tempo -= 480 -((hora2*60+minuto2)-(hora1*60+minuto1));
    }




    if(tempo<0){
        printf("Este funcionário não cumpriu as horas e falta %d horas e %d minutos\n",(-1*(tempo/60)),(-1*(tempo%60)));
    }if(tempo==0){
        printf("Este funcionário cumpriu somente as horas semanais\n");
    }if(tempo>0){
        printf("Este funcionário cumpriu as horas e acumulou %d horas e %d minutos\n",(tempo/60),(tempo%60));
    }else{}
    
    return 0;
}