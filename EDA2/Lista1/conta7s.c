#include <stdio.h>
 
unsigned long int conta7s(unsigned long int n)
{
    if(n < 1){
        return 0;
    }
    if (n % 10 == 7){
        return (1 + (conta7s(n / 10)));
    }
    else{
    
        return (conta7s(n / 10));
    }
}
 
int main()
{
    unsigned long int n;
    //printf("Digite um inteiro positivo: ");
    scanf("%ld", &n);
 
    printf("%d\n", conta7s(n));
}