#include <stdio.h>
// 1=sen(angulo); 2=cos(angulo);
float trigonometricas(int angulo,int tipo){
    switch (tipo){
    case 1:
        switch (angulo){
        case 30:
            return 0.5;
            break;
        case 45:
            return 0.70710678;
        case 60:
            return 0.86602540;
        default:
            return 0;
            break;
        }
    case 2:
        switch (angulo){
            case 30:
                return 0.86602540;
                break;
            case 45:
                return 0.70710678;
            case 60:
                return 0.5;
            default:
                return 0;
                break;
        }
    default:
        return 0;
        break;
    }
}

int main(){
    float velocidade,alcance;
    int angulo;
    scanf("%f %d",&velocidade,&angulo);
    alcance = (2*(velocidade*velocidade)*trigonometricas(angulo,1)*trigonometricas(angulo,2))/10;
    printf("%.4f\n",alcance);
    
    return 0;
}