#include <stdio.h>
#include <stdlib.h>

typedef struct pato
{
    int cor;
    int quantidade;
} pato;

static int N, M;
static pato *ht;

void htInit()
{
    int i;
    N = 0, M = 9439;
    ht = malloc(sizeof(pato) * M);
    for (i = 0; i < M; i++)
    {
        ht[i].cor = 0;
        ht[i].quantidade = 0;
    }
}

void htInsert(pato item)
{
    int v = item.cor % M;

    if (ht[v].cor == 0)
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
    int N, cor;
    pato tmp, maior;

    scanf("%d", &N);

    while (N != 0)
    {
        htInit();
        maior.cor = 0;
        maior.quantidade = 0;

        for (int c = 0; c < N; c++)
        {
            scanf("%d", &cor);

            tmp.cor = cor;
            tmp.quantidade = 1;
            htInsert(tmp);

            if (ht[tmp.cor % M].quantidade > maior.quantidade)
            {
                maior = ht[tmp.cor % M];
            }
        }

        printf("%d\n", maior.cor);
        free(ht);

        scanf("%d", &N);
    }

    return 0;
}