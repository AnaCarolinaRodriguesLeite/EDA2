#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reprova(int alunos){
  int nota, notaRep;
  char nome[21], nomeRep[21];
  for (int i = 0; i < alunos; i++){
    scanf(" %s %d", nome, &nota);

    if (i == 0){
      notaRep = nota;
      strcpy(nomeRep, nome);
    }
    else if (nota < notaRep){
      notaRep = nota;
      strcpy(nomeRep, nome);
    }
    else if (nota == notaRep){
      if (strcmp(nome, nomeRep) > 0){
        notaRep = nota;
        strcpy(nomeRep, nome);
      }
    }
  }
  printf("%s\n", nomeRep);
}

int main(){
  int instancia = 1, alunos;

  while (scanf("%d", &alunos) == 1){
    printf("Instancia %d\n", instancia++);
    reprova(alunos);
    printf("\n");
  }
  return 0;
}
