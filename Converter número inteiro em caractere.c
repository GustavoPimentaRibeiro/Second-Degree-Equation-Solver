#include <stdio.h>
#include <stdlib.h>

main(){
	
	int num;
	char numero[20];
	
	gets(numero);
	printf("\n\n %s", numero);
	
	// Transformação do número em string para número em inteiro
	num = numero[0] - 48;

	printf("\n\n %d", num);
	
	// Transformação do número em inteiro para número em string
	numero[0] = num + 48;
	
	printf("\n\n %c", numero[0]);
	
}
