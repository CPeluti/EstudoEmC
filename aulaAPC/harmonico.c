#include <stdio.h>
int main(){
    int harmonico1,harmonico2,razao;
    scanf("%d",&harmonico1);
    scanf("%d",&harmonico2);
    razao = harmonico2/harmonico1;
    if((harmonico2%harmonico1)!=0||harmonico2<harmonico1){
        printf("Naum eh harmonico\n");
    }else{
        printf("Eh o harmonico num %d\n",razao);
    }
    
    return 0;
}