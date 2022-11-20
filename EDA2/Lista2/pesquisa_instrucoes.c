#include <stdio.h>
#include <stdlib.h>

typedef struct instrucao{
	int codigo;
	char palavra[16];
} instrucao;

void insertionsort(instrucao *v, int l, int h){
	int i = 0, j, min = l;
	instrucao aux;
	for(i = h; i > l; i--){
		if(v[i].codigo < v[i-1].codigo){
			aux = v[i];
			v[i]= v[i-1];
			v[i-1] = aux;
		}
	}
	for (int i = l + 2; i <= h; i++){
		int j = i;  aux = v[i];

		while(aux.codigo < v[j-1].codigo){
				v[j] = v[j - 1];
				j--;
		}
		v[j] = aux;
	}
}

int buscabinaria(instrucao *v, int esq,int dir, int codigo){
	int meio = (esq + dir) / 2;

	while (esq <= dir){
		if (v[meio].codigo < codigo)
			esq = meio + 1;
		else if (codigo < v[meio].codigo)
			dir = meio - 1;
		else
			return meio;
		meio = (dir + esq)/2;
	}
	return (v[meio].codigo == codigo) ? meio : -1;
}

int main(){
	// variaveis
	instrucao v[15000];
	int elem,codigo;
	// entrada
	scanf("%d", &elem);
	
	for (int i = 0; i < elem; i++)
		scanf("%d %s\n", &v[i].codigo, v[i].palavra);
		
	// insercao
	insertionsort(v, 0, elem-1);
	
	// busca
	int elemindex;
	while (scanf("%d", &codigo) == 1){
		int elemindex = buscabinaria(v, 0, elem - 1, codigo);
		if (elemindex == -1)
			printf("undefined\n");
		else
			printf("%s\n", v[elemindex].palavra);
	}
	return 0;
}
