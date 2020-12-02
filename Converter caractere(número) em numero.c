#include <stdio.h>
#include <stdlib.h>

/* 
Converte o número em formato de caracter em número inteiro fazendo a conta de:
número inteiro = (posição do vetor de caracter - 48)	
*/
int convert_int_char(char *numeros, int num, int pos){

	num = numeros[pos] - 48;
	
	return num;
	
}

main(){
	
	char numeros[] = {"12349"};
	int num = 0, pos = 3;
	// pos é uma variável que indica a posição do vetor numeros que deseja converter para inteiro
	
	printf("\n Numero convertido: %d", convert_int_char(numeros, num, pos));
	
}
