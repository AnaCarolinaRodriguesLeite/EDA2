#include <stdio.h>
#include <stdlib.h>

void merge(int *v, int l, int h, int r)
{
  int i = l, j = h + 1, pos = 0, *k;
  k = (int *)calloc((r - l + 1), sizeof(int));

  while (i <= h && j <= r)
  {
    if (v[i] < v[j])
      k[pos++] = v[i++];
    else
      k[pos++] = v[j++];
  }

  while (i <= h)
    k[pos++] = v[i++];

  while (j <= r)
    k[pos++] = v[j++];

  // Merge
  pos = 0;
  for (int i = l; i <= r; ++i)
  {
    v[i] = k[pos++]; // k[i-esq]
  }
  free(k);
};

void merge2(int *v, int l, int r, int *v2, int l1, int r1)
{
  int i = l, j = l + 1, pos = 0, *k;
  k = (int *)calloc((r1 - l + 1), sizeof(int));

  while (i <= r && j <= r1)
  {
    if (v[i] < v[j])
      k[pos++] = v[i++];
    else
      k[pos++] = v[j++];
  }

  while (i <= r)
    k[pos++] = v[i++];

  while (j <= r1)
    k[pos++] = v[j++];

  // Merge
  pos = 0;
  for (int i = l; i <= r1; ++i)
  {
    v[i] = k[pos++]; // k[i-esq]
  }
  free(k);
};

int main(){
	// variaveis
	int v[8 * 100000], n, tam = 0, v1 = 0, i = 0;
	
	// i < 8
	for (i=0; i < 8; i++){
	    scanf("%d\n", &n);
	
		for (int j = 0; j < n; j++){
		    scanf("%d\n", &v[j + v1]);
		}
		
		  // ordenacao
		  tam += n;
		  
		  merge(v, 0, tam - n - 1, tam - 1);
		  
		  v1 += n;
	}
	for (; i < tam - 1; i++)
	    printf("%d ", v[i]);
	  printf("%d\n", v[i]);
  
  return 0;

}


//void intercala(int *v, int l, int h, int r){
//  int *aux = malloc(sizeof(int) * (r - l + 1));
//  int a = l, b = h + 1, c = 0;
//
//  while (a <= h && b <= r){
//    if (*(v + a) <= *(v + b)){
//      *(aux + c++) = *(v + a++);
//    }
//    else{
//      *(aux + c++) = *(v + b++);
//    }
//  }
//
//  while (a <= h){
//    *(aux + c++) = *(v + a++);
//  }
//
//  while (b <= r){
//    *(aux + c++) = *(v + b++);
//  }
//
//  for (int i = l, j = 0; i <= r; i++, j++){
//    *(v + i) = *(aux + j);
//  }
//
//  free(aux);
//}
