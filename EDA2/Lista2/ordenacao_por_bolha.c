#include <stdio.h>
#include <stdlib.h>

void bubblesort(int *v,int tam){
	for(int i = 0; i < tam; i++){
		for(int j = 1; j < tam; j++){
			if( v[j] < v[j-1] ){
				int aux = v[j];
				v[j] = v[j-1];
				v[j-1] = aux;
			}
		}
	}
}

int main(){
  	int n,v[1000],i=0,tam;
  
  	while(scanf("%d",&n) != EOF){
  		v[i++] = n;
	}
	tam= i;
	
	bubblesort(v,tam);
	
	for(int i = 0;i < tam;i++)
    	printf("%d",v[i]);

  return 0;
}
