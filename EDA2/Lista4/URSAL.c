#include <stdio.h>
#include <stdlib.h>

typedef struct vote{
  int candidato;
  int quantidade;
} vote;

void swap(vote *a, vote *b){
  vote aux = *a;
  *a = *b;
  *b = aux;
}

int comparate(vote a, vote b){
  if (a.quantidade > b.quantidade){
    return 1;
  }
  else if (a.quantidade == b.quantidade){
    if (a.candidato > b.candidato){
      return 1;
    }
    else{
      return 0;
    }
  }
  return 0;
}

int separates(vote *v, int left, int right){
  int i = left - 1, j = right;
  vote c = v[right];
  while (1){
    while (comparate(v[++i], c));
    while (comparate(c, v[--j]))
      if (j == left)
        break;
    if (i >= j)
      break;
    swap(&v[i], &v[j]);
  }
  swap(&v[i], &v[right]);
  return i;
}

void quicksort(vote *v, int left, int right){
  if (right <= left) return;

  if (left < right){
    int j;
    
    int mid = (left + right) / 2;
    
    if (comparate(v[right], v[mid])){
      swap(&v[right], &v[mid]);
    }
    if (comparate(v[mid], v[left])){
      swap(&v[mid], &v[left]);
    }
    if (comparate(v[mid], v[left])){
      swap(&v[mid], &v[right]);
    }
    
    j = separates(v, left, right);
    
    quicksort(v, left, j - 1);
    quicksort(v, j + 1, right);
  }
}

int main(){
  //variaveis
  int s, f, e, n;
  int contInv = 0, contVal = 0, contPres = 0;
  //alocação da quantidade de votos
  vote *votos = calloc(100000, sizeof(vote));
  //entrada
  scanf("%d %d %d", &s, &f, &e);
  //processamento do numero dos votos em relação aos candidatos
  while (scanf("%d", &n) != EOF){
    if (n < 0){
      contInv++;
    }
    else{
      votos[n].candidato = n;
      votos[n].quantidade++;
      if (n < 100){
        contPres++;
      }
      contVal++;
    }
  }
  //a contagem de votos válidos totais e contagem de votos inválidos
  printf("%d %d\n", contVal, contInv);
  //quick
  quicksort(votos, 10, 99);
  quicksort(votos, 100, 999);
  quicksort(votos, 1000, 9999);
  quicksort(votos, 10000, 99999);
  
  //saida
  float porcentagem = (votos[10].quantidade * 1.0) / (contPres * 1.0);
  //o código do presidente eleito ou a frase Segundo Turno
  if (porcentagem > 0.5){
    printf("%d\n", votos[10].candidato);
  }
  else{
    printf("Segundo turno\n");
  }
  //a lista dos candidatos eleitos para , Senador, dep.Fed e dep.Est.
  //ordenadas pela quantidade de votos e se houver empate, tem preferência o candidato de maior número.
  printf("%d", votos[100].candidato);
  for (int i = 101; i < 100 + s; i++){
    printf(" %d", votos[i].candidato);
  }
  printf("\n");
  printf("%d", votos[1000].candidato);
  for (int i = 1001; i < 1000 + f; i++){
    printf(" %d", votos[i].candidato);
  }
  printf("\n");
  printf("%d", votos[10000].candidato);
  for (int i = 10001; i < 10000 + e; i++){
    printf(" %d", votos[i].candidato);
  }
  printf("\n");
}