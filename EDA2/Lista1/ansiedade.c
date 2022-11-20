#include <stdio.h>
#include <stdlib.h>

int main(){
	//conjunto arbitrário de formularios com linhas 10
	//cada form possui sim ou nao
	//contar o numero de triagens com 2 sim para a triagem
	int num_triagem = 0;
	char resp[4];
	//processamento
	while(scanf(" %s",resp) != EOF){
		int cont_sim = 0;
		if(resp[0] == 's'){
			cont_sim = 1;
		}
		for(int i=0; i<9 ;i++){
			scanf(" %s",resp);
			if(resp[0] == 's'){
				cont_sim++;
			}
		}
		if(cont_sim >= 2){
			num_triagem++;
		}
	}
	//saida
	printf("%d\n",num_triagem);
	
	return 0;
	
}
