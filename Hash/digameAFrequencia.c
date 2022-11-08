#include <stdio.h>
#include <stdlib.h>

typedef struct letra
{
    int ascii;
    int quantidade;
    int lida;
} letra;

static int N, M;
static letra *ht;

void htInit()
{
    int i;
    N = 0, M = 256;
    ht = malloc(sizeof(letra) * M);
    for (i = 0; i < M; i++)
    {
        ht[i].ascii = 0;
        ht[i].quantidade = 0;
        ht[i].lida = 0;
    }
}

void htInsert(letra item)
{
    int v = item.ascii % M;

    if (ht[v].ascii == 0)
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
    char texto[1001];
    letra tmp;
    int menor, idx;

    while (scanf("%s", texto) != EOF)
    {
        htInit();
        int c = 0;
        N = 0;

        while (texto[c] != '\0')
        {
            tmp.ascii = (int)texto[c];
            tmp.quantidade = 1;
            tmp.lida = 0;

            htInsert(tmp);

            c++;
        }

        for (int j = 0; j < N; j++)
        {
            menor = 999999999;
            for (int i = 0; i < 256; i++)
            {
                if (ht[i].quantidade > 0 && ht[i].quantidade < menor && ht[i].lida == 0)
                {
                    menor = ht[i].quantidade;
                    idx = i;
                }
            }
            printf("%d %d\n", ht[idx].ascii, ht[idx].quantidade);
            ht[idx].lida = 1;
        }

        printf("\n");
        free(ht);
    }

    return 0;
}