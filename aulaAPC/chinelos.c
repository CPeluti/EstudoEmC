#include <stdio.h>

int main(){

    int i=0,z=-1,j=0,numero,tamanho,aux;
    scanf("%d %d",&numero,&tamanho);
    int chinelos[numero];
    while (i<numero)
    {
        scanf("%d",&chinelos[i]);
        i++;
    }
    i=0;
    while (i<numero){
        j = i+1;
        while (j<numero){
            if(chinelos[i]>chinelos[j]){
                aux = chinelos[i];
                chinelos[i]=chinelos[j];
                chinelos[j]=aux;
            }
            j++;
        }
        i++;
        
    }
    i=0;
    while (i<numero)
    {
        if(chinelos[i]>=tamanho)
        {
            z=i;
            break;
        }
        i++;
    }
    printf("%d",z);
    


    return 0;
}