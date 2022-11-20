#include <stdio.h>
#include <stdlib.h>

#define key(A) (A)
#define less(A,B) (key(A)<key(B))
#define exch(A,B) {int temp = A; A = B; B = temp;}
#define cmpexch(A,B){if(less(A,B))exch(A,B);}

void insertionSort(int *v, int l, int r){
  for(int i = r-1; i > l; i--){
    	cmpexch(v[i], v[i - 1]);
  	}
  	
  for(int i = l + 2; i < r ; i++){
    	int j = i;
    	int tmp = v[j];
    	while(less(tmp, v[j - 1])){
      		v[j] = v[j - 1];
      		j--;
    	}
    	v[j] = tmp;
  	}
} 


int main(){
  int v[50000], i = 0;
  
  while(scanf("%d", &v[i]) != EOF){
  	i++;
  }
  
  //sort
  insertionSort(v, 0, i);

  //output
  for(int j = 0; j < i ; j++)
    if(j != i-1){
        printf("%d ", v[j]);	
	}
	else{
	    printf(" %d", v[j]);	
	}
	printf("\n");

  return 0;
}


v[j] < v[j-1] && j > 0
