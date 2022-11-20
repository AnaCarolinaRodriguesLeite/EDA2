#include <stdio.h>

void insertionsort(int *v, int l, int h){
  for (int i = l+1; i < h; i++) {
    	for (int j = i; j > l; j--) {
    		if(v[j] < v[j-1]){
    			int aux = v[j];
      			v[j] = v[j-1];
      			v[j-1] = aux;
			}
    	}
  	}
}

int main(){
  	int v[1000],i = 0,k;
  
  	while(scanf("%d",&v[i]) == 1){
  		i++;
	}
	
	insertionsort(v, 0, i);
	k = i-1;
	
	for(int j = 0; j < i; j++)
    	if(j != k){
        	printf("%d ", v[j]);	
		}
		else{
	    	printf(" %d", v[j]);	
		}
	printf("\n");

  return 0;
}

