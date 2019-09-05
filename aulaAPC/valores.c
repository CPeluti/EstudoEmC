#include <stdio.h>
int main(){
    int A,B;
    scanf("%d %d",&A,&B);
    if(A==B){
        printf("%d\n",A);
        printf("%d\n",B);
        printf("iguais\n");
    }else{
        if(A>B){
            printf("%d\n",A);
            printf("%d\n",B);
            printf("diferentes");
        }else{
            printf("%d\n",B);
            printf("%d\n",A);
            printf("diferentes\n");
        }
        
    }
    return 0;
}