// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// static int cnt, pre[5001], aux=0, maior=0;

// typedef struct Animal{
//     char nome[31];
//     int n;
// } Animal;

// typedef struct{
//     int v;
//     int w;
// } Edge;

// Edge EDGE(int v, int w){
//     Edge EDGE;
//     EDGE.v = v;
//     EDGE.w = w;
//     return EDGE;
// };

// typedef struct graph *Graph;

// struct graph {
//     int V;
//     int E;
//     int **adj;
//     int **tc;
// };


// int **MATRIXInit(int w, int h, int value) {
// 	int **arr = malloc(sizeof(*arr) * w);
// 	for (int i = 0; i < w; i++)
// 		arr[i] = malloc(sizeof(int) * h);
// 	return arr;
// }

// Graph GRAPHinit(int v){
//     Graph G = malloc(sizeof(*G));
//     G->V = v; G->E= 0;
//     G->adj=MATRIXInit(v,v,0);
//     return G;
// }

// void GRAPHInsertE(Graph G, Edge e){
//     int v = e.v; int w=e.w;
//     if(G->adj[v][w] == 0) G->E++;
//     G->adj[v][w]=1;
//     G->adj[w][v]=1; // Nao dirigido
// }


// int GRAPHEdges(Edge a[], Graph G){
//     int v,w,E=0;
//     for(v=0; v<G->V;v++){
//         for(w=v+1; w<G->V;w++){
//             if (G->adj[v][w] == 1)
//             a[E++]=EDGE(v,w);
//         }
//     }
//     return E;
// }


// void GRAPHFt(Graph G) {
// 	int s, i, t;
// 	G->tc = MATRIXInit(G->V, G->V, 0);
// 	for (s = 0; s < G->V; s++){
// 		for (t = 0; t < G->V; t++){
// 			G->tc[s][t] = G->adj[s][t];
// 		}
// 	}
// 	for (s = 0; s < G->V; s++) {
// 		G->tc[s][s] = 1;
// 	}
// 	for (i = 0; i < G->V; i++){
// 		for (s = 0; s < G->V; s++){
// 			if (G->tc[s][i] == 1){
// 				for (t = 0; t < G->V; t++){
// 					if (G->tc[i][t] == 1)
// 						G->tc[s][t] = 1;
// 				}
// 			}
// 		}
// 	}
// }


// void GRAPHshow( Graph G) {
//    for (int v = 0; v < G->V; ++v) {
//       printf( "%2d:", v);
//       for (int w = 0; w < G->V; ++w)
//          if (G->adj[v][w] == 1)
//             printf( " %2d", w);
//       printf( "\n");
//    }
// }

// void dfsR(Graph G, Edge e) {
// 	int w = e.w;
// 	pre[w] = cnt++;
// 	for(int i = 0; i < G->V; i++) {
// 		if (G->adj[w][i] != 0){
//             if (pre[i] == -1) dfsR(G, EDGE(w, i));
//         }
// 	}
//     aux++;
// }

// int GRAPHSearch(Graph G) {
// 	int conexos = 0;
// 	cnt = 0;
// 	for (int i = 0; i < G->V; i++) pre[i] = -1;
// 	for (int i = 0; i < G->V; i++) {
// 		if (pre[i] == -1) {
//             aux=0;
// 			dfsR(G, EDGE(i, i));
//             if(aux>maior) maior=aux;
// 			conexos++;
// 		}
// 	}
// 	return conexos;
// }

// int find(Animal *a, char *animal, int tam){
//     for(int i=0; i<tam; i++){
//         if(strcmp(a[i].nome, animal)==0){
//             return a[i].n;
//         }
//     }
//     return -1;
// }

// int main(){

//     int c, r;
//     char animal[31], predador[31];

//     scanf("%d %d", &c, &r);
//     while (c!=0 || r!=0){
//        Graph G = GRAPHinit(c);
//         Animal *a = malloc(c*sizeof(Animal));
//         for(int i=0; i<c; i++){
//             scanf(" %[^\n]", a[i].nome);
//             a[i].n=i;
//         }

//         for(int i=0; i<r; i++){
//             scanf("%s %s", animal, predador);
//             int v1 = find(a, animal, c);
//             int v2 = find(a, predador, c);
//             GRAPHInsertE(G, EDGE(v1,v2));
//         }
//         GRAPHSearch(G);
//         printf("%d\n", maior); 
//         maior=0;
//         scanf("%d %d", &c, &r);
//     }

//     return 0;
// }


#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define MAX 7993

typedef char Item;


void merge(Item v[5000][31], Item aux[5000][31], int lo, int mid, int hi) {
  int k = 0, i = lo, j = mid+1;
    
  while (i <= mid && j <= hi) {
    // if (less(v[i], v[j])) // less(v[i], v[j])
    if (strncmp(v[i], v[j], 30) < 0)
      strncmp(aux[k++], v[i++], 30);
      // aux[k++] = v[i++];
    else
      strncmp(aux[k++], v[j++], 30);
      // aux[k++] = v[j++];
  }

  while (i <= mid) {
    strncmp(aux[k++], v[i++], 30);
    // aux[k++] = v[i++];
  }

  while (j <= hi) {
    strncmp(aux[k++], v[j++], 30);
    // aux[k++] = v[j++];
  }

  // copiar para o vetor original
  k = 0;
  for (i = lo; i <= hi; ++i)
    strncmp(v[i], aux[k++], 30);
    // v[i] = aux[k++];
}


void mergesort(Item v[5000][31], Item aux[5000][31], int lo, int hi) {
  if (lo >= hi) return;

  int mid = (lo+hi)/2;

  mergesort(v, aux, lo, mid);
  mergesort(v, aux, mid+1, hi);
  merge(v, aux, lo, mid, hi);
}



typedef struct edge
{
    int v;
    int w;
} Edge;

struct graph
{
    int V;
    int E;
    char adj[MAX][MAX];
};

typedef struct graph *Graph;
static struct graph g;

Edge EDGE(int v, int w)
{
    Edge e;
    e.v = v;
    e.w = w;
    return e;
}

Graph GRAPH(int v, int *validas, int n)
{
    int t, w;
    g.V = v;
    g.E = 0;
    for(int i = 0; i < n; i++){
        t = validas[i];
        for(int j = 0; j < n; j++){
            w = validas[j];
            g.adj[t][w] = 0;
        }
    }
    return &g;
}

void GRAPH_insert(Graph G, Edge e)
{
    int v = e.v, w = e.w;
    if (G->adj[v][w] == 0)
        G->E++;
    G->adj[v][w] = 1;
    G->adj[w][v] = 1;
}

void dfsR(Graph G, Edge e, int *pre, int *count, int *validas, int n)
{
    int t, w = e.w, v;
    pre[w] = (*count)++;
    for (t = 0; t < n; t++)
    {
        v = validas[t];
        if (G->adj[w][v] != 0)
        {
            if (pre[v] == -1)
            {
                dfsR(G, EDGE(w, v), pre, count, validas, n);
            }
        }
    }
}

int GRAPH_maior_nucleos(Graph G, int *validas, int n, int *pre)
{
    int count = 0, t, quantidade = 0, v;
    int maior = 0;

    for(int i = 0; i < MAX; i++)
        pre[i] = -1;

    for (int i = 0; i < n; i++)
    {
        v = validas[i];
        if (pre[v] == -1)
        {
            t = count;
            dfsR(G, EDGE(v, v), pre, &count, validas, n);
            quantidade = count - t;
            if (quantidade > maior)
            {
                maior = quantidade;
            }
        }
    }
    return maior;
}

int hash(char *key)
{
    int a = 31415, b = 27183, h = 0;
    for (; *key != '\0'; key++)
    {
        a = (a * b) % (MAX - 1);
        h = (a * (unsigned)h + *key) % MAX;
    }
    return h;
}

int cmp_criatura(const void* c1, const void * c2) {
  // const char* cri1 = *(const char** ) c1;
  // const char* cri2 = *(const char** ) c2;
  const char* cri1;
  const char* cri2;
  strcmp(cri1,  *(const char** ) c1);
  strcmp(cri2,  *(const char** ) c2);

  return strncmp(cri1, cri2, 30);
}

int main()
{
    int C, R;
    char criatura[31], criatura2[31];
    static int validas[5000], n = 0, pre[MAX];
    char criaturas[5000][31], aux[5000][31];
    Graph G;
    Edge e;

    while (scanf("%d %d", &C, &R) == 2 && !(C == 0 && R == 0))
    {
        G = GRAPH(C, validas, n);
        n = 0;
        for (int i = 0; i < C; i++)
        {
            scanf("%s", criatura);
            strncpy(criaturas[n], criatura, 30);
            validas[n++] = hash(criatura);
        }
        
        mergesort(criaturas, aux, 0, n-1);
        // qsort(criaturas, n, sizeof(char*), cmp_criatura);

        for (int i = 0; i < R; i++)
        {
            scanf("%s %s", criatura, criatura2);
            GRAPH_insert(G, EDGE(hash(criatura), hash(criatura2)));
        }
        int maior = GRAPH_maior_nucleos(G, validas, n, pre);
        printf("%d\n", maior);
    }
    return 0;
}