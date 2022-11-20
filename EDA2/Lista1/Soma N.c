#include <stdio.h>

int main(){
    //variaveis
    int N, X, soma, cont;
    //entrada
    scanf("%d",&N);
    //processamento
    soma = 0;
    cont = 0;
    while(cont < N){
        scanf("%d",&X);
        cont++;
        soma = soma + X;
    }
    printf("%d",soma);
    return 0;
}