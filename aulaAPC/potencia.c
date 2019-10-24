#include <stdio.h>

int pot(int x, int y){
    int resultado=1,i;
    for(i=0;i<y;i++){
        resultado=resultado*x;
    }
    return resultado;
}

int main()
{
	int x,y;

	scanf("%d %d", &x, &y);
	printf("%d\n", pot(x,y));

	return 0;
}