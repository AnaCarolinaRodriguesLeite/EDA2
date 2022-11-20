#include<stdio.h>
#include<stdlib.h>
#include <string.h>

typedef struct Pilha {
    char caracteres[150];
    struct Pilha* prox;
} Pilha;

int empilha (Pilha *p, char x[150]){
    Pilha *aux = malloc(sizeof(Pilha));
    if (aux == NULL)return 0;
    else{
        strcpy(aux->caracteres, x);
        aux -> prox = p -> prox;
        p -> prox = aux;
        return 1;
    }
}

int desempilha (Pilha *p){
    Pilha *aux = p -> prox;
    if (p -> prox == NULL)  return 0;
    else{
        p -> prox = aux -> prox;// nova variavel com novo prox
        free(aux);
        return 1;
	}
}

int main(){
    //entrada
    Pilha *p;
   
    p = malloc(sizeof(Pilha));
    p->prox = NULL;
   
    char x[10] ,frase[150];
   
    Pilha *lixo = p->prox;
    //processamento e saida
    while(scanf("%s",x) != EOF){
        if(strcmp(x, "desfazer") == 0){
         if(p->prox == NULL)
            printf("NULL\n");
        else
            printf("%s\n", p->prox->caracteres);            
            desempilha(p);  
        }
        if(strcmp(x, "inserir") == 0){
         scanf(" %[^\n]",frase);
         empilha(p, frase); 
        }
    }
}
