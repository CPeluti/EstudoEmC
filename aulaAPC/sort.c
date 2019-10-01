#include <stdio.h>
int main(){
    int i,j,aux,n=10,numeros[10];
    i=0;
    while(i<n){
        scanf("%d",&numeros[i]);
        i++;
    }
    i=0;
    while (i<n){
        j = i+1;
        while (j<n){
            if(numeros[i]>numeros[j]){
                aux = numeros[i];
                numeros[i]=numeros[j];
                numeros[j]=aux;
            }
            j++;
        }
        i++;
        
    }
    i=0;
    while (i<n){
        printf("%d ",numeros[i]);
        i++;
    }
    
    
}