#include <stdio.h>
#include <stdlib.h>

#define vertex int

static int cnt;
int *visitados;
int *pre;
int nucleos = 0;

typedef struct Edge
{
    int v;
    int w;
} Edge;

struct grafo
{
    int V;
    int E;
    int **adj;
};

typedef struct grafo *Grafo;

static int **startMariz(int r, int c, int val)
{
    int **m = malloc(sizeof(int *) * r);

    for (vertex i = 0; i < r; i++)
    {
        m[i] = malloc(sizeof(int) * c);
    }

    for (vertex i = 0; i < r; i++)
    {
        for (vertex j = 0; j < c; j++)
        {
            m[i][j] = val;
        }
    }

    return m;
}

Grafo startGrafo(int V)
{
    Grafo G = malloc(sizeof *G);
    G->V = V;
    G->E = 0;
    G->adj = startMariz(V, V, 0);

    return G;
}

void GrafoInsert(Grafo G, Edge E)
{
    int v = E.v;
    int w = E.w;

    if (G->adj[v][w] == 0)
    {
        G->adj[v][w] = 1;
        G->adj[w][v] = 1;
        G->E++;
    }
}

static void Reach(Grafo G, int v)
{
    visitados[v] = 1;
    for (int w = 0; w < G->V; w++)
    {
        if (G->adj[v][w] == 1 && visitados[w] == 0)
            Reach(G, w);
    }
}

int GrafoReach(Grafo G, int s, int t)
{
    for (int v = 0; v < G->V; v++)
        visitados[v] = 0;

    Reach(G, s);

    if (visitados[t] == 0)
    {
        return 0;
    }

    return 1;
}

static void dfs(Grafo G, vertex v)
{
    pre[v] = cnt++;

    for (int a = 0; a < G->V; a++)
    {
        if (G->adj[v][a] != 0)
        {
            if (pre[a] == -1)
                dfs(G, a);
        }
    }
}

void GrafoDFS(Grafo G)
{
    cnt = 0;

    for (vertex v = 0; v < G->V; v++)
    {
        pre[v] = -1;
    }
    for (vertex v = 0; v < G->V; v++)
    {
        if (pre[v] == -1)
        {
            dfs(G, v);
            nucleos++;
        }
    }
}

int main()
{

    int V, scan = 1;
    vertex v, w;
    Edge linha;
    visitados = malloc(sizeof(int) * 10000);
    pre = malloc(sizeof(int) * 10000);

    scanf("%d", &V);

    Grafo matriz = startGrafo(V);

    while (scan > 0)
    {
        scan = scanf("%d %d", &v, &w);
        if (scan > 0)
        {
            linha.v = v;
            linha.w = w;

            GrafoInsert(matriz, linha);
        }
    }

    GrafoDFS(matriz);

    printf("%d\n", nucleos);

    free(visitados);
    free(pre);

    return 0;
}