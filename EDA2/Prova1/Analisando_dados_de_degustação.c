#include <stdio.h>
#include <stdlib.h>

typedef struct sequencia
{
  int i;  // tamanho
  char c; // caracter
  int p;  // posicao
  int ordem;
} sequencia;

#define key(a) (a.i)

#define less(a, b) (key(a) < key(b))

#define lesseq(a, b) (key(a) <= key(b))

#define exch(a, b)   \
  {                  \
    sequencia t = a; \
    a = b;           \
    b = t;           \
  }

#define cmpexch(a, b) \
  {                   \
    if (less(b, a))   \
      exch(a, b);     \
  }

void merge(sequencia *V, int l, int m, int r)
{
  sequencia R = malloc(sizeof(sequencia)(r - l + 1));
  int i = l, j = m + 1, k = 0;

  while (i <= m && j <= r)
  {
    if (lesseq(V[j], V[i]))
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

void mergesort(sequencia *V, int l, int r){
  if (l >= r)
    return;
  int meio = (l + r) / 2;
  mergesort(V, l, meio);
  mergesort(V, meio + 1, r);
  merge(V, l, meio, r);
}

int analisar(char *v, sequencia *seq){
  int i = 0, n = 0;
  char charLido, contador = 0;

  charLido = v[i];
  seq[n].p = i;

  while (v[i] != '\0'){
    while (v[i] == charLido){
      contador++;
      i++;
    }

    seq[n].c = v[i - 1];
    seq[n].i = contador;
    seq[n].p = i - contador;

    n++;
    contador = 0;

    charLido = v[i];
  }
  return n;
}

int main(){
  char s[100001];
  sequencia seq[100001];

  scanf("%s", s);

  int x = analisar(s, seq);

  mergesort(seq, 0, x - 1);

  for (int i = 0; i < x; i++){
    printf("%d %c %d\n", seq[i].i, seq[i].c, seq[i].p);
  }
  return 0;
}