#include <stdio.h>

int main(){
	//variaveis
	int num, cont=0;
	//entrada e processamento
	while(scanf("%d",&num) != EOF){
		cont++;
	}
	//saida
	printf("%d\r",cont);
	return 0;
}