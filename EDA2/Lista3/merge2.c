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

void mergeSort(int *v, int l, int r){
  if (l >= r)
    return;

  int meio = (l + r) / 2;
  mergeSort(v, l, meio);
  mergeSort(v, meio + 1, r);
  merge(v, l, meio, r);
}

int main(){
  int cont = 1;
  int *v = malloc(sizeof(int) * cont);

  while(scanf("%d", v + cont - 1) == 1){
    cont++;
    v = realloc(v, sizeof(int) * cont);
  }

  mergeSort(v, 0, cont - 2);

  for (int i = 0; i < cont - 1; i++){
    printf("%d ", *(v + i));
  }

  free(v);
  return 0;
}
