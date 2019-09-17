#include <stdio.h>
int main(){
    int potencia;
    scanf("%d",&potencia);
    if((potencia%2)==0 && (potencia/2)%2==1){
        printf("-1\n");
    }else if(potencia%2==0&& (potencia/2)%2!=1){
        printf("1\n");
    }else if(potencia%2==1){
        if((potencia-1)%2==0&& ((potencia-1)/2) %2==0){
            printf("i\n");
        }else if((potencia-1)%2==0 && ((potencia-1)/2)%2==1){
            printf("-i\n");
        }
    }
    return 0;
}
