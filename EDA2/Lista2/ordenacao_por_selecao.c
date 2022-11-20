#include <stdio.h>
#include <stdlib.h>

//void selectionsort(int *v,int l,int r){
//	for(int l = 0; l < i -1; i++){
//		int min = i;
//		for(int j = i; j <= r; j++){
//			if(v[j] < v[min]){
//				min = j;
//			}
//		}
//		int aux = v[min];
//		v[min] = v[i];
//		v[i] = aux;
//	}
//}

void selectionsortr(long int *v,int l, int r){
	if(l == r) return;
	
	int min = l;
	for(int j = l+1; j < r; j++){
		if(v[min] > v[j]){
			min = j;
		}
	}
	int aux = v[min];
	v[min] = v[l];
	v[l] = aux;
	
	selectionsortr(v,l+1,r);
}

int main(){
  	long int v[1001];
	int i=0,k;
  
  	while(scanf("%ld",&v[i]) == 1){
  		i++;
	}
	
	selectionsortr(v,0,i);
	k = (i-1);
	
	for(int j = 0; j < i; j++)
    	if(j != k){
        	printf("%ld ", v[j]);	
		}
		else{
	    	printf("%ld", v[j]);	
		}
	printf("\n");

  return 0;
}
