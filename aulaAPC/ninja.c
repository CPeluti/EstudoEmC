#include <stdio.h>

int main(){

    int i;
    long int entrada,saida=0;
    int serie[3];
    serie[0]=2;
    serie[1]=7;
    serie[2]=3;
    
    scanf("%ld",&entrada);
    int vezes;
    vezes = entrada/3;
    if(entrada%3!=0){
        printf("SEM SOMA\n");
    }else{
        for(i=0;i<vezes;i++){
            saida+=serie[0]+serie[1]+serie[2];
            serie[0]=serie[0]*2;
            serie[1]=serie[1]*3;
            serie[2]=serie[2]*4;
        }
        printf("%ld\n",saida);
    }
    
    
    

        





    




    return 0;
}