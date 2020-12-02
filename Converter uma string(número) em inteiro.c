#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/* 
Converte o número em formato de caracter em número inteiro fazendo a conta de:
	número em inteiro = (posição do vetor de caracter - 48)
Depois disso é analisado posição a posição e multiplicado por 10 elevado á posição atual para separar de unidade, dezena, centena ... que é feito com a conta:
	número inteiro = posição atual do vetor de caractere * 10 elevado á posição do vetor de forma contrária
Somando todas as ordens de um número é possível chegar ao resultado que é retornado ao término da função
*/
int convert_int_char(char *numeros, long long int num){
	int i;

	for(i = 0; i < strlen(numeros); i ++){
		
		num = num + (numeros[i] - 48) * pow(10, strlen(numeros) - 1 - i);
		
	}
	
	return num;
	
}

main(){
	
	char numeros[] = {"12349"};
	long long int num = 0;
	
	printf("\n Numero convertido: %lld", convert_int_char(numeros, num));
	
}
