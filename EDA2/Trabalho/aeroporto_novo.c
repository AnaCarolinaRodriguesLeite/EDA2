#include <stdio.h>
#include <stdlib.h>
#define size 101

// A é aeroportos
// V é voos
int main(){
  // variaveis
  // X e Y são informações do voo
  // tamanho de A sendo 1 a A
  int A, V, X, Y, infos[size], n = 0, i, maior;

  // entrada
  scanf("%d %d", &A, &V);

  // quando o não temos aeroportos,
  // não se tem informações de voos
  while (A != 0 && V != 0){
    for (i = 0; i <= A; i++){
      infos[i] = 0;
    }
    // quando o valor de V é menor que i,
    // siginifica que esse voo(V) não tem informações
    // indo de X para o aeroporto Y
    // então adiciona informações
    for (i = 0; i < V; i++){
      scanf("%d %d", &X, &Y);
      infos[X]++;
      infos[Y]++;
    }

    // quando já se tem os voos e os aeroportos,
    // se o valor das informações forem maiores que maior,
    // significa que ele agora é o maior em relação aos outros
    maior = 0;
    for (i = 1; i <= A; i++){
      if (infos[i] >= maior){
        maior = infos[i];
      }
    }

    // printa o numero do teste
    n++;
    printf("Teste %d\n", n);

    // printa o valor do maior
    for (i = 0; i <= A; i++){
      if (infos[i] == maior){
        printf("%d ", i);
      }
    }
    printf("\n\n");
    scanf("%d %d", &A, &V);
  }
  return 0;
}
