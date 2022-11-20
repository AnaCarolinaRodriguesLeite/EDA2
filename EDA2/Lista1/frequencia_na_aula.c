#include <stdio.h>

int freq[1000000];

int main() {
  int n, x, res = 0;
  
  scanf("%d", &n); //quantidade de número de resgistro que aprecem na lista
  
  for(int i = 0; i < n; ++i){
    
	scanf("%d", &x); //numero de registro que foi inserido
    
	if(freq[x] == 0){
      freq[x] = 1;
      res += 1;
    }
  }
  printf("%d\n", res);
  return 0;
}
