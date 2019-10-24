#include <stdio.h>

double peso_ideal(double alt, char sex){
    double resultado;
    if(sex=='F'){
        resultado = (62.1 * alt) - 44.7;
    }else{
        resultado = (72.7 * alt) - 58;
    }
    return resultado;
}

int main()
{
	int i,n;
	double alt;
	char sex;

	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%lf %c", &alt, &sex);
		printf("%.2lf\n", peso_ideal(alt, sex));
	}

	return 0;
}