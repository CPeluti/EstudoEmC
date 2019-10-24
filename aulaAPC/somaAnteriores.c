#include <stdio.h>

int SomaPares(int n) {
	int i,resultado=0;
    if(n<0){
        return -1;
    }else{
        for(i=2;i<=n;i+=2){
                resultado+=i;
        }
        return resultado;
    }
}

int main()
{
	int n;
	
	scanf("%d", &n);

	if(SomaPares(n)>=0){
        printf("%d\n",SomaPares(n));
    }else{
        printf("Numero nao e positivo\n");
    }
	
	return 0;
}