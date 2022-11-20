#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
  char key[16];
} hash;

int main(int argc, char const *argv[]){
  int num_cases, num_op, soma = 0, indice = 0;
  hash *v = malloc(sizeof(hash));
  hash *v2 = malloc(102 * sizeof(hash));
  scanf("%d", &num_cases);
  for (int i = 0; i < num_cases; i++){
    scanf(("%d"), &num_op);
    for (int j = 0; j < num_op; j++){
      scanf("%s", v->key);
      if (v->key[0] == 'A'){
        for (int k = 0; k < strlen(v->key); k++){
          soma += ((k + 1) * (v->key[k + 4]));
        }
        indice = (soma * 19) % 101;
        printf("%d\n", indice);
        if (strlen(v2[indice].key) == 0){
          for (int l = 4; l < strlen(v->key); l++){
            v2[indice].key[l - 4] = v->key[l];
          }
          v2[indice].key[strlen(v2[indice].key) + 1] = '\n';
          printf("%s\n", v2[indice].key);
        }
        else{
          int m = 1;
          while (strlen(v2[indice].key) != 0)
          {
            indice += (indice + (m * m) + (23 * m)) % 101;
            m++;
            if (m == 20){
              break;
            }
          }
          printf("%d\n", indice);
          for (int l = 4; l < strlen(v->key); l++){
            v2[indice].key[l - 4] = v->key[l];
          }
          v2[indice].key[strlen(v2[indice].key) + 1] = '\n';
          printf("%s\n", v2[indice].key);
        }
      }
      else if (v->key[0] == 'D'){
      }
    }
  }

  return 0;
}