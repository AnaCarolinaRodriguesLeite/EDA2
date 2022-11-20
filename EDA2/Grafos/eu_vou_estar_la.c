// // #include <stdio.h>
// // #include <stdlib.h>

// // #define true 1
// // #define false 0
// // #define vertex int  
// // typedef int bool;
// // typedef struct node *link;
// // typedef struct graph *Graph;

// // struct node {
// //     vertex w;
// //     bool visitado;
// //     link next;
// // };

// // struct graph {
// //     int V;
// //     int A;
// //     link *adj;
// // };

// // static link addNode(vertex w, link next){
// //     link a = malloc(sizeof(struct node));
// //     a->w = w;
// //     a->next = next;
// //     a->visitado = false;
// //     return a;
// // }

// // Graph initGraph(int V){
// //     Graph G = malloc(sizeof *G);
// //     G->V = V;
// //     G->A = 0;
// //     G->adj = malloc(V * sizeof(link));
// //     for(vertex v = 0; v < V; ++v){
// //         G->adj[v] = NULL;
// //     }
// //     return G;
// // }

// // void addEdge(Graph G, vertex v, vertex w){
// //     if(!G) return;
// //     if(v < 0 || v >= G->V) return;
// //     if(w < 0 || w >= G->V) return;

// //     for(link a = G->adj[v]; a != NULL; a = a->next){
// //         if(a->w == w) return;
// //     }
// //     G->adj[v] = addNode(w, G->adj[v]);
// //     G->A++;
// // }

// // void BFS(Graph G, vertex s) {
// //     G->adj[s]->visitado = true;
// //     for(link a = G->adj[s]; a != NULL; a = a->next){
// //         if(G->adj[a->w]->visitado == false){
// //             G->adj[a->w]->visitado = true;
// //         }
// //     }
// // }

// // int main(void) {
// //     int N, M, J, K, A, B, C;
// //     Graph G;

// //     scanf("%d %d %d", &N, &M, &J);

// //     G = initGraph(N);
    
// //     for(int i = 0; i < N; i++){
// //         scanf("%d", &K);
// //         for(int j = 0; j < K; j++){
// //             scanf("%d", &A);
// //             addEdge(G, i, A);
// //         }
// //     }

// //     for(int i = 0; i < M; i++){
// //         scanf("%d", &B);
// //         BFS(G, B);
// //     }

// //     for(int i = 0; i < J; i++){
// //         scanf("%d", &C);
// //         if(G->adj[C]->visitado == true){
// //             printf("Eu vou estar la\n");
// //         }
// //         else{
// //             printf("Nao vou estar la\n");
// //         }
// //     }

// //     return 0;
// // }

// #include <stdio.h>
// #include <stdlib.h>
// #include <stdint.h>

// // https://moj.naquadah.com.br/cgi-bin/contest.sh/bcr-EDA2-2021_1-grafos
// // https://moj.naquadah.com.br/contests/bcr-EDA2-2021_1-grafos/euvouestarla.html
// // https://moj.naquadah.com.br/contests/bcr-EDA2-2021_1-grafos/euvouestarla.pdf

// typedef int Vertex;

// #define __CONNECTED 1
// #define __UNCONNECTED 0
// #define MAX_VERTICES 2000

// // Em uma máquina de 64 bits
// typedef struct MatUndGraph
// {
//   int vertices;                               // número de vértices
//   int edges;                                  // número de arestas
//   uint8_t matrix[MAX_VERTICES][MAX_VERTICES]; // matrix de booleanos
// } MatUndGraph;

// void __MatUndGraph_matrix_destroy(MatUndGraph *g)
// {
//   free(g->matrix);
// }

// MatUndGraph *MatUndGraph_create(int max_vertices)
// {
//   MatUndGraph *g = (MatUndGraph *)calloc(1, sizeof(MatUndGraph));
//   g->vertices = max_vertices;
//   g->edges = 0;
//   return g;
// }

// void MatUndGraph_destroy(MatUndGraph *g)
// {
//   free(g);
// }

// void MatUndGraph_insert_edge(MatUndGraph *g, Vertex a, Vertex b)
// {
//   if (g->matrix[a][b] == __UNCONNECTED)
//     ++g->edges;

//   g->matrix[a][b] = __CONNECTED;
//   g->matrix[b][a] = __CONNECTED;
// }

// uint8_t MatUndGraph_has_edge(MatUndGraph *g, Vertex a, Vertex b)
// {
//   return g->matrix[a][b] == __CONNECTED;
// }

// void MatUndGraph_show(MatUndGraph *g)
// {
//   int i, j;
//   printf("%d vertices, %d edges\n", g->vertices, g->edges);
//   for (i = 0; i < g->vertices; i++)
//   {
//     printf("%2d:", i);
//     for (j = 0; j < g->vertices; j++)
//     {
//       if (g->matrix[i][j] == 1)
//         printf(" %2d", j);
//     }
//     printf("\n");
//   }
// }

// #define WAS_NOT_HERE 0
// #define WAS_HERE 1

// typedef struct JuliusPos
// {
//   Vertex v;
//   uint8_t was_here;
// } JuliusPos;

// void fill_graph(MatUndGraph *g, int N)
// {
//   int i, j, neighbours_in_line, neighbour;

//   for (i = 0; i < N; i++)
//   {
//     scanf("%d", &neighbours_in_line);

//     for (j = 0; j < neighbours_in_line; j++)
//     {
//       scanf("%d", &neighbour);
//       MatUndGraph_insert_edge(g, i, neighbour);
//     }
//   }
// }

// void read_places_julius_has_been(uint8_t julius_was_here[], int M)
// {
//   int i = 0, vertex;
//   for (i = 0; i < M; i++)
//   {
//     scanf("%d", &vertex);
//     julius_was_here[vertex] = WAS_HERE;
//   }
// }

// int is_neighbour_to_where_julius_has_been(uint8_t julius_was_here[], MatUndGraph *g, Vertex v)
// {
//   int neighbour_to_v = 0;
//   for (; neighbour_to_v < g->vertices; neighbour_to_v++)
//   {
//     if (g->matrix[v][neighbour_to_v] == __CONNECTED)
//       if (julius_was_here[neighbour_to_v] == WAS_HERE)
//         return 1;
//   }

//   return 0;
// }

// void predict_where_julius_will_be(uint8_t julius_was_here[], int J, MatUndGraph *g)
// {
//   int i = 0, vertex, will_be_here = 0, is_neighbour = 0;
//   for (; i < J; i++)
//   {
//     scanf("%d", &vertex);

//     will_be_here = julius_was_here[vertex] ||
//                    is_neighbour_to_where_julius_has_been(julius_was_here, g, vertex);

//     printf("%s vou estar la\n", will_be_here ? "Eu" : "Nao");
//   }
// }

// int main()
// {
//   int N, M, J;
//   uint8_t julius_was_here[MAX_VERTICES] =
//       {[0 ... MAX_VERTICES - 1] = WAS_NOT_HERE};

//   scanf("%d %d %d", &N, &M, &J);

//   MatUndGraph g;
//   g.vertices = N;

//   fill_graph(&g, N);
//   read_places_julius_has_been(julius_was_here, M);
//   predict_where_julius_will_be(julius_was_here, J, &g);

//   // MatUndGraph_destroy(g);
//   return 0;
// }

#include <stdlib.h>
#include <stdio.h>

typedef struct node *link;
typedef struct graph *Graph;
typedef struct Edge
{
  int v;
  int w;
} Edge;

struct node{
  int v;
  link next;
  };

struct graph{
  int v, e;
  link *adj;
};

link NEW(int v, link next){
  link x = malloc(sizeof(*x));
  if(x==NULL)printf("DEU RUIM\n");
  x->v = v;
  x->next = next->next;
  return x;
}

Graph GRAPHInit(int V){
  int v;
  Graph G = malloc(sizeof(*G));
  G->v = V;
  G->e = 0;
  G->adj = malloc(V * sizeof(link));
  for(v = 0; v < V; v++){
    G->adj[v]=NULL;
  }
  return G;
}

Graph GRAPHInsert(Graph G, Edge e){
  int v = e.v, w = e.w;
  G->adj[v] = NEW(w, G->adj[v]);
  G->adj[w] = NEW(v, G->adj[w]);
  G->e++;
}

Edge EDGE(int v, int w){
    Edge E;
    E.v = v;
    E.w = w;
    return E;
}

int GRAPHEdges(Edge a[], Graph G){
  int v, E = 0; link t;
  for(v = 0; v < G->v; v++){
    for( t = G->adj[v]; t != NULL; t = t->next){
      if(v < t->v){
        a[E++] = EDGE(v, t->v);
      }
    }
  }
  return E;
}

int main(void)
{
  int n, m, j;
  int v, w, *visitados, *visitara;
  Edge *E;

    Graph g = GRAPHInit(n);

  scanf("%d %d %d", &n, &m, &j);

  for (int i = 0; i < n; i++)
  {
    scanf("%d", &v);
    for (int j = 0; j < v; j++)
    {
      scanf("%d", &w);
      Edge e = EDGE(v, w);
      GRAPHInsert(g, e);
    }
  }
  GRAPHEdges(E, g);
  visitados = malloc(sizeof(int) * m);
  visitara = malloc(sizeof(int) * j);
  for(int i = 0; i < m; i++){
    scanf("%d", &visitados[i]);
  }

  for(int i = 0; i < j; i++){
    scanf("%d", &visitara[i]);
  }
  return 0;
}