#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main() {
	char numero[10];
	scanf("%s", numero);

	int i, tam, novoValor = 0;
	tam = strlen(numero); //verifica quantos dígitos tem no número
	
	//pega os dígitos da direita para a esquerda	
	for (i = tam-1; i >= 0; i--) {
		//printf("%c|", numero[i]);
		if (numero[i] == '1') {
			novoValor += pow(2,tam-1-i);
		}
	}
	printf("Decimal: %i", novoValor);
	
	return 0;
}