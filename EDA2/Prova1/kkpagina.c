#include <stdio.h>
#include <stdlib.h>

#define key(A) (A)
#define lesseq(A,B) ((A) <= (B))
#define exch(A,B) { int t; t=A; A=B; B=t;}

int part (int *v, int esquerda, int direita){
    int a = v[direita], k = esquerda;
    for (int i = esquerda; i < direita; i++)
        if (lesseq(v[i], a)){
            exch(v[i], v[k]);
            k++;
        }
    exch(v[k], v[direita]);
    return k;
}

void quickS(int *v, int esquerda, int direita, int k){ //select
    if (esquerda >= direita) return;
    int posi = part(v, esquerda, direita);
    if (posi > k)
        quickS(v, esquerda, posi - 1, k);
    if (posi < k)
        quickS(v, posi + 1, direita, k);
}

void sort(int *v, int esquerda, int direita){
    if (direita <= esquerda) return;
    int posi = part(v, esquerda, direita);

    sort(v, esquerda, posi - 1);
    sort(v, posi + 1, direita);
}

int main(){
    //variaveis
    int n, p, x, i = 0, esquerda, direita;
    //entrada
    scanf("%d %d %d", &n, &p, &x);
    //alocando variaveis nas celulas
    int *v = malloc(n * sizeof(int));
    //entrada dos ids dos produtos
    while(i < n){
        int id;
        scanf("%d", &id);
        v[i] = id;
        i++;
    }
   //pagina e quantidade
    esquerda = x * p;
    if (esquerda > n) return 0; //se for maior ele nao faz nada
    //valor da quantidade em relação a pagina
    direita = esquerda + x - 1;
    if(direita >= n) direita = n-1;
    //sorting e separa
    quickS(v, 0, n-1, esquerda);
    quickS(v, esquerda, n-1, direita);
    sort  (v, esquerda, direita); //sort

    //saida
    for(int i = esquerda; i <=direita; i++)
        printf("%d\n", v[i]);

    return 0;
}







