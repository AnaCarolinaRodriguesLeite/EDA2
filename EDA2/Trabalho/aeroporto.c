// #include <stdio.h>
// #define TAM 101

// int main(){
//   int aeroportos, voos, X, Y, infos[TAM], n = 0, i, maior;

//   scanf("%i %i", &aeroportos, &voos);

//   while (aeroportos != 0 && voos != 0){
//     for (i = 0; i <= aeroportos; i++){
//       infos[i] = 0;
//     }

//     for (i = 0; i < voos; i++){
//       scanf("%i %i", &X, &Y);
//       infos[X]++;
//       infos[Y]++;
//     }

//     // encontra o maior
//     maior = 0;
//     for (i = 1; i <= aeroportos; i++){
//       if (infos[i] >= maior){
//         maior = infos[i];
//       }
//     }

//     n++;
//     printf("Teste %i\n", n);

//     for (i = 0; i <= aeroportos; i++){
//       if (infos[i] == maior){
//         printf("%i ", i);
//       }
//     }
//     printf("\n\n");
//     scanf("%i %i", &aeroportos, &voos);
//   }
//   return 0;
// }

#include <stdio.h>
#define MAX_AERO 100

int main(int argc, char *argv[]){
    int a, v, o, d;
    register int c, max, k = 1;

    while(scanf("%d%d", &a, &v) && a && v) {
        int ma[MAX_AERO] = {0};
        max = 0;

        for(c = 0; c < v; c++) {
            scanf("%d%d", &o, &d);
            ma[o]++;
            ma[d]++;

            if(max < ma[o] || max < ma[d]){
                if(ma[o] > ma[d]) max = ma[o];
                else max = ma[d];
            }
        }
        printf("Teste %d\n", k++);
        for(c = 1; c <= a; c++){
            if(ma[c] == max) printf("%d ",c);
        }
        printf("\n\n");
    }
    return 0;
}