#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Converte a sub-string passada por parâmetro para inteiro
int convert_int_char(char *function, long long int number, int cont){
	int i;

	for(i = 0; i < cont; i ++){
		
		number = number + (function[i] - 48) * pow(10, cont - 1 - i);
		
	}
	
	return number;
	
}

// Checa se a string contém somente números
int check_char(char word){
	char numbers[] = {"0123456789"};
	char variables[] = {"x"};
	char exponentials[] = {"²"};
	int i;
	
	for(i = 0; i < strlen(numbers); i ++){
		
		if (word == numbers[i]){
		
			return 1; // achou um número qualquer
		
		}else if(word == variables[0]){
			
			return 2; // achou uma variável x
			
		}else if(word == exponentials[0]){
			
			return 3; // achou um exponencial, apenas ignore-o
			
		}
		
	}
	
	return 0;
}

void function_analiser(char *function, long long int number, int *a, int *b, int *c){
	
	int i,control = 1, sinal = 1, cont = 0;
	
	/* 
	cont = auxilia na contagem dos números antes das variáveis
	control = é uma variável de controle para saber qual variável está sofrendo a alteração {1 - a; 2 - b; 3 - c}
	*/
	char aux[10]; // auxiliar para controlar os números em formato de string e ajudar na conversão
	
	for(i = 0; i < strlen(function); i ++){
		
		if(i == 0){
			
			if (function[0] == 'x'){
			
				*a  = 1;
			
			}else if(function[0] == '-' && function[1] == 'x'){
			
				*a = -1;
				i ++;
				
			}else if(function[0] == '-' && function[1] != 'x'){
				
				sinal = -1;
				
			}else{
				
				if (check_char(function[i]) == 1){
				
					aux[cont] = function[i];
					cont ++;
					sinal = 1;
				
				}
			
			}
			
		}else{
			
			if (function[i] == '+'){
				
				if(function[i+1] == 'x'){
					
					if(control == 1){
						
						*a = 1;
						cont = 0;
						i ++;
						continue;
						
					}else if(control == 2){
						
						*b = 1;
						cont = 0;
						i ++;
						continue;
						
					}
					
				}else{
					
					sinal = 1;
					control ++;
					cont = 0;
					continue;
					
				}
				
				
			}else if (function[i] == '-'){
				
				if(function[i+1] == 'x'){
					
					if(control == 1){
						
						*a = -1;
						cont = 0;
						continue;
						
					}else if(control == 2){
						
						*b = -1;
						cont = 0;
						continue;
						
					}
					
				}else{
					
					sinal = -1;
					control ++;
					cont = 0;
					continue;
						
				}
				
				
			}
			
			if (check_char(function[i]) == 1){
				
				aux[cont] = function[i];
				cont ++;
				
			}else if(check_char(function[i]) == 2){
				
				if(control == 1){
					
					*a = convert_int_char(aux, number, cont) * sinal;
					cont = 0;
					
				}else if(control == 2){
					
					*b = convert_int_char(aux, number, cont) * sinal;
					
				}
				
			}else if(check_char(function[i]) == 3){
				
				continue;
				
			}else{
				
				printf("\n\n Formato de funcao invalido!");
				break;
				
			}
			
		}
		
	}
	
	*c = convert_int_char(aux, number, cont) * sinal;
	
}

main(){
	
	char function[] = {"2x²+6x+15"};
	long long int number = 0;
	int a = 0, b = 0, c = 0;
	
	function_analiser(function, number, &a, &b, &c);
	printf("\n A= %d\n B= %d\n C= %d", a, b, c);
	
}
