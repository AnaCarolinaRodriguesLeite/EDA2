#include <stdio.h>
#include <stdlib.h>

void merge_desenvolvido(int *v, int l, int h, int r){
  int i = l, j = h + 1, pos = 0, *k;
  k = (int *)calloc((r - l + 1), sizeof(int));

  while (i <= h && j <= r){
    if (v[i] < v[j]) k[pos++] = v[i++];
    else k[pos++] = v[j++];
  }
  //pedaco do primeiro
  while (i <= h)
    k[pos++] = v[i++];
  //pedado do segundo
  while (j <= r)
    k[pos++] = v[j++];

  // Merge
  //vetor original
  pos = 0;
  for (int i = l; i <= r; ++i){
    v[i] = k[pos++]; // k[i-esq
  }
  free(k);
}

void mergesort(int *vetor, int esq, int dir){
  if (esq >= dir)
    return;

  int meio = (esq + dir) / 2;
  mergesort(vetor, esq, meio);
  mergesort(vetor, meio + 1, dir);
  merge_desenvolvido(vetor, esq, meio, dir);
}

int busca_binaria(int *v, int b, int y){
  int com = -1, fim = y;
  int k = -1;
  
  while (com < fim - 1){
    int i = (com + fim) / 2;

	if (*(v+i) < b) com = i;
	else if (*(v + i) == b){
      fim = i;
      k = 1;
    }
    else
      fim = i;
  }

  if (k == 1){
    return 1;
  }
  else{
    return -1;
  }
}

int main(){
	//variaveis
	int n,*v, valor_busca;
	//entrada
	scanf("%d", &n);
	//aloca��o da entrada  
	v = malloc(sizeof(int) * n);
	//enchedo o vetor
	for(int i = 0; i < n; i++){
	    scanf("%d ", v + i);
	}
	//merge
	mergesort(v, 0, n - 1);
	//chamando busca para buscar se o numero inserido existe no vetor
	int x;
	while (scanf("%d", &x) != EOF){
	    valor_busca = busca_binaria(v, x, n);
	    
		if (valor_busca == -1) printf("nao\n");
	    else printf("sim\n");
	}
	
	  return 0;
}
