#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define N 100
#define T 100
int main(){
	//conta o numero de entrada estando num vetor de 100 posições
	//entra com strings com o numero em linhas da quantidade incerida em cima
	//conta a casa que o numero dentro da string
	//contar o total dos numeros achados antes
	int num[N],cont_num = 0, cont_string = 0, numero,n;
	char letra[T],b;
	
	scanf("%d",&numero);
	n = numero;
	
	while(n--){
		scanf(" %s",letra);
		num[cont_num] = 0;
		for(cont_string = 0; letra[cont_string] != '\0'; cont_string++){
			b = letra[cont_string];
			if(isdigit(b)){
				num[cont_num] += b - '0';
			}	
		}
		cont_num++;
	}
	for(int i= 0; i < numero; i++){
		printf("%d\n", num[i]);
	}
}
