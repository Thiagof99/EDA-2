#include <stdio.h>
#include <stdlib.h>

#define vertex int

static int Joao, maiorConexao, cont, achou, JoaoConexao, cnt;
int *visitados, *pre, nucleos = 0;

typedef struct Edge
{
    int v;
    int w;
} Edge;

Edge EDGE(int v, int w)
{
    Edge tmp;

    tmp.v = v;
    tmp.w = w;

    return tmp;
}

struct grafo
{
    int V;
    int E;
    int **adj;
};

typedef struct grafo *Grafo;

static int **startMatriz(int r, int c, int val)
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
    G->adj = startMatriz(V, V, 0);

    return G;
}

void GrafoInsert(Grafo G, Edge E)
{
    int v = E.v;
    int w = E.w;

    if (G->adj[v][w] == 0)
    {
        G->E++;
    }

    G->adj[v][w] = 1;
    G->adj[w][v] = 1;
}

void dfsR(Grafo G, Edge e)
{
    int t, w = e.w;
    pre[w] = cnt++;
    Edge are;
    for (t = 0; t < G->V; t++)
        if (G->adj[w][t] != 0)
            if (pre[t] == -1)
            {
                are = EDGE(w, t);
                dfsR(G, are);
                cont++;
                if (Joao == t)
                {
                    achou = 1;
                }
            }
}

int GrafoSearch(Grafo G)
{
    int v;
    int conexoes = 0;
    int maiorQt = 0;
    int posicao;
    cnt = 0;
    Edge e;

    for (v = 0; v < G->V; v++)
    {
        pre[v] = -1;
    }

    for (v = 0; v < G->V; v++)
        if (pre[v] == -1)
        {
            e = EDGE(v, v);
            cont = 0;
            dfsR(G, e);
            conexoes++;
            if (achou == 1)
                JoaoConexao = conexoes;
            if (cont >= maiorQt)
            {
                if (cont == maiorQt)
                {
                    if (achou == 1)
                    {
                        maiorQt = cont;
                        maiorConexao = conexoes;
                        posicao = v;
                    }
                }
                else
                {
                    maiorQt = cont;
                    maiorConexao = conexoes;
                    posicao = v;
                }
            }
            achou = 0;
        }
    if (maiorConexao == JoaoConexao)
    {
        if (maiorQt >= 1)
            printf("Bora pra estrada\n");
        else
            printf("Fique em casa\n");
    }
    else if (conexoes == 1 || posicao == Joao)
        printf("Bora pra estrada\n");
    else
        printf("Vamos para %d\n", posicao);
}

int main(void)
{
    int V, v, w, J, scan = 1;
    Edge edg;
    Grafo graph;
    visitados = malloc(sizeof(int) * 10000);
    pre = malloc(sizeof(int) * 10000);

    scanf("%d%d", &V, &J);

    Joao = J;
    maiorConexao = 0;
    achou = 0;
    JoaoConexao = 0;

    graph = startGrafo(V);

    while (scan > 0)
    {
        scan = scanf("%d%d", &v, &w);
        if (scan > 0)
        {
            edg = EDGE(v, w);
            GrafoInsert(graph, edg);
        }
    }

    GrafoSearch(graph);

    free(visitados);
    free(pre);

    return 0;
}