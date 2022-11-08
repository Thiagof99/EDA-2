#include <stdio.h>
#include <stdlib.h>

typedef struct voto
{
    int candidato;
    int quantidade;
    int lida;
} voto;

static int N, M;
static voto *ht;

void htInit()
{
    int i;
    N = 0, M = 100000;
    ht = malloc(sizeof(voto) * M);
    for (i = 0; i < M; i++)
    {
        ht[i].candidato = 0;
        ht[i].quantidade = 0;
        ht[i].lida = 0;
    }
}

void htInsert(voto item)
{
    int v = item.candidato % M;

    if (ht[v].candidato == 0)
    {
        ht[v] = item;
        N++;
    }
    else
    {
        ht[v].quantidade++;
    }
}

int main(void)
{
    int vt, validos = 0, invalidos = 0, S, F, E, maior = 0, eleito, empate = 0;
    voto tmp;
    htInit();

    scanf("%d %d %d", &S, &F, &E);

    while (scanf("%d", &vt) != EOF)
    {
        if (vt > 0)
        {
            tmp.candidato = vt;
            tmp.quantidade = 1;
            tmp.lida = 0;

            htInsert(tmp);
            validos++;
        }
        else
        {
            invalidos++;
        }
    }

    printf("%d %d\n", validos, invalidos);

    for (int c = 0; c < 100; c++)
    {
        empate = empate + ht[c].quantidade;
        if (ht[c].quantidade > maior)
        {
            maior = ht[c].quantidade;
            eleito = c;
        }
    }

    if (ht[eleito].quantidade > empate / 2)
    {
        printf("%d\n", ht[eleito].candidato);
    }
    else
    {
        printf("Segundo turno\n");
    }

    for (int i = 0; i < S; i++)
    {
        maior = 0;
        for (int j = 100; j < 1000; j++)
        {
            if (ht[j].quantidade >= maior && ht[j].lida == 0)
            {
                eleito = j;
                maior = ht[j].quantidade;
            }
        }
        if (i > 0)
        {
            printf(" ");
        }

        printf("%d", ht[eleito].candidato);
        ht[eleito].lida = 1;
    }

    printf("\n");

    for (int i = 0; i < F; i++)
    {
        maior = 0;
        for (int j = 1000; j < 10000; j++)
        {
            if (ht[j].quantidade >= maior && ht[j].lida == 0)
            {
                eleito = j;
                maior = ht[j].quantidade;
            }
        }
        if (i > 0)
        {
            printf(" ");
        }

        printf("%d", ht[eleito].candidato);
        ht[eleito].lida = 1;
    }

    printf("\n");

    for (int i = 0; i < E; i++)
    {
        maior = 0;
        for (int j = 10000; j < 100000; j++)
        {
            if (ht[j].quantidade >= maior && ht[j].lida == 0)
            {
                eleito = j;
                maior = ht[j].quantidade;
            }
        }
        if (i > 0)
        {
            printf(" ");
        }

        printf("%d", ht[eleito].candidato);
        ht[eleito].lida = 1;
    }

    printf("\n");

    free(ht);
    return 0;
}