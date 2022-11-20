#include <stdio.h>

void insertionsort(int *v, int n){
	int i ,j;
	for(i = 1; i < n; i++){
		int x = v[i];
		j = i -1;
		while(j >= 0 && v[j] > x){
			v[j+1] = v[j];
			j--;
		}
		v[j+1] = x;
	}
	
int main(){
  	int n,v[1000],i=0,tam;
  
  	while(scanf("%d",&n) != EOF){
  		v[i++] = n;
	}
	tam= i;
	
	insertionsort(v,tam-1);
	
	for(int i = 0;i < tam-1;i++)
    	printf("%d\n",v[i]);
    printf("%d\n", v[i]);

  return 0;
}
