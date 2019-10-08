#include <stdio.h>

int main(){
    int i,n,lesmas[scanf("%d",&n)],maisRapido;
    for(i=0;i<n;i++){
        scanf("%d",&lesmas[i]);
        if(lesmas[i]>maisRapido){
            maisRapido = lesmas[i];
        }

    }
    if(maisRapido<10){
        printf("1\n");
    }else if(maisRapido>=10 && maisRapido<20){
        printf("2\n");
    }else{
        printf("3\n");
    }


    return 0;
}