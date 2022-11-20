#include <stdio.h>
#include <stdlib.h>

#define less(A, B) ((A) < (B))
#define lesseq(A, B) ((A) <= (B))
#define exch(A, B) {int t; t = A; A = B; B = t;}
#define cmpexch(A, B) { if (less(B, A)) exch(A, B);}

void merge(int *V, int l, int m, int r){
  int *R = malloc(sizeof(int) * (r - l + 1));
  int i = l, j = m + 1, k = 0;

  while (i <= m && j <= r){
    if (lesseq(V[i], V[j]))
      R[k++] = V[i++];
    else
      R[k++] = V[j++];
  }

  while (i <= m)
    R[k++] = V[i++];
  while (j <= r)
    R[k++] = V[j++];

  k = 0;
  for (i = l; i <= r; i++)
    V[i] = R[k++];
  free(R);
}

void mergesort(int *V, int l, int r){
  if (l >= r)
    return;
  int meio = (l + r) / 2;
  mergesort(V, l, meio);
  mergesort(V, meio + 1, r);
  merge(V, l, meio, r);
}

int encontrou(int num, int *v, int l, int r){
  for (int i = l; i <= r; i++)
    if (v[i] == num)
      return 1;
  return 0;
}

int busca_binaria(int *v, int l, int r, int num){
  if (l > r)
    return -1;
  
  int meio = (l + r) / 2;
  
  if (less(v[meio], num))
    return encontrou(num, v, meio + 1, r);
  
  else if (lesseq(v[meio], num))
    return meio;
  
  else
    return encontrou(num, v, l, meio - 1);
}

int main(){
  //variavies
  int N, i = 0, k = 0, aux, a[100000], b[100000], c[100000];

  //indide tem que partir do 0
  for (int m = 0; m < 100000; m++){
    a[m] = -1;
    b[m] = -1;
  }
  //entrada 
  //numero da quantidade de vezes que o vetor vai ter
  scanf("%d", &N);
  //numeros dentro do vetor
  while (i < N){
    scanf("%d", &aux);
    a[i] = aux;
    i++;
  }

  mergesort(a, 0, i - 1);

  //eliminando numeros repetidos
  for (int j = 0; j < i; j++){
    if (j == 0 || a[j] != a[j - 1]){
      b[k] = a[j];
      k++;
    }
  }
  //fim do vetor se não for par
  if (k % 2 != 0){
    b[k] = 1000000000;
    k++;
  }

  //soma dos dois conjuntos de numeros
  i = 0;
  for (int j = 0; j < k; j += 2){
    c[i] = b[j] + b[j + 1];
    i++;
  }
  //busca dos numeros resultantes da soma que são iguais aos numeros do vetor, se for igual ele conta, se não ocntinua
  for (int j = 0; j < i; j++){
    aux = c[j];
    if (busca_binaria(b, 0, k - 1, aux) == 0){
      b[k] = aux;
      k++;
    }
    else{
      continue;
    }
  }
  //ordena os numeros resultantes da soma que foram para dentro do vetor
  mergesort(b, 0, k - 1);
  //imprime os indices de numeros de 4 a 4
  for (int j = 0; j < k; j += 4){
    printf("%d\n", b[j]);
  }
  //quantidade de elementos que tem dentro do vetor inteiro depois dos numeros somados inseridos
  printf("Elementos: %d\n", k);
}