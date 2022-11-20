#include <stdio.h>
#include <stdlib.h>
typedef long long int Item;

#define Key(A) (A)
#define less(A, B) (Key(A) < Key(B))
#define lesseq(A, B) (Key(A) <= Key(B))
#define exch(A, B) {Item t = A; A = B; B = t;}
#define cmpexch(A, B){if (less(B, A)) exch(A, B);}

int separates(Item *V, int l, int r){
  Item elem_direita = V[r];
  int elem_index = l;
  for (int i = l; i < r; i++)
    if (lesseq(V[i], elem_direita)){
      exch(V[i], V[elem_index]);
      elem_index++;
    }
  exch(V[elem_index], V[r]);
  return elem_index;
}

void quickSortM3(Item *V, int l, int r){
  int j;

  if (r <= l) return;
  
  cmpexch(V[(r + l) / 2], V[r]);
  cmpexch(V[l], V[(r + l) / 2]);
  cmpexch(V[r], V[(r + l) / 2]);

  j = separates(V, l, r);
  quickSortM3(V, l, j - 1);
  quickSortM3(V, j + 1, r);
}

int main(){
  //variaveis
  int tam_v_int;
  //entrada
  scanf("%d", &tam_v_int);
  //alocação do tamanho do vetor de inteiros
  Item *v_int = malloc(sizeof(Item) * (tam_v_int + 1));

  for (int i = 0; i < tam_v_int; i++)
    scanf("%lld", &v_int[i]);

  quickSortM3(v_int, 0, tam_v_int - 1);

  for (int i = 0; i < tam_v_int; i++)
    (i != tam_v_int - 1) ? printf("%lld ", v_int[i]) : printf("%lld\n", v_int[i]);

  return 0;
}