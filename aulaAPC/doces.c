#include <stdio.h>

int main(){
    int n,i=0,numeroMinimo,convidados=0;
    scanf("%d %d",&n,&numeroMinimo);
    int quantidade[n];
    while (i<n)
    {
        scanf("%d",&quantidade[i]);
        i++;
    }
    i=0;
    while (i<n){

        if((quantidade[i]>=numeroMinimo)){
            convidados+=quantidade[i]/numeroMinimo;
            i++;
        }else
        {
            i++;
        }
        

    }
    printf("%d\n",convidados);
    
    

    return 0;
}