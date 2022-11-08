#include <stdio.h>
#include <stdlib.h>

typedef struct nota
{
    int valor;
    int quantidade;
} nota;

static int N, M;
static nota *ht;

void htInit()
{
    int i;
    N = 0, M = 1001;
    ht = malloc(sizeof(nota) * M);
    for (i = 0; i < M; i++)
    {
        ht[i].valor = 0;
        ht[i].quantidade = 0;
    }
}

void htInsert(nota item)
{
    int v = item.valor % M;

    if (ht[v].valor == 0)
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
    int alunos, nt, maior = 0, maiorNota;
    nota tmp;

    htInit();

    scanf("%d", &alunos);

    for (int c = 0; c < alunos; c++)
    {
        scanf("%d", &nt);

        tmp.valor = nt;
        tmp.quantidade = 1;

        htInsert(tmp);
    }

    for (int c = 0; c <= 1000; c++)
    {
        if (ht[c].quantidade >= maior)
        {
            maior = ht[c].quantidade;
            maiorNota = c;
        }
    }

    printf("%d\n", ht[maiorNota].valor);

    free(ht);
    return 0;
}