#include <stdio.h>
#include <stdlib.h>

typedef struct casa
{
    int chave;
    int linha;
    int coluna;
    int pontuacao;
    int sondada;
} casa;

int N, M, s;
casa *ht;
casa NULLItem = {0, 0, 0, 0, 0};

void htInit(int max)
{
    int i;
    N = 0, M = max;
    ht = malloc(sizeof(casa) * M);
    for (i = 0; i < M; i++)
    {
        ht[i] = NULLItem;
    }
}

void htInsert(casa c, casa *sondar)
{
    int v = c.chave;
    int i = v % M;

    if (ht[i].chave == NULLItem.chave)
    {
        ht[i] = c;
        if (c.sondada == 0)
        {
            sondar[s] = c;
            s++;
        }
        N++;
    }
    /*    if (N >= M)
    {
        expand();
    }*/
}

void inserirCasas(casa c, casa *casas)
{
    int i, j;
    casa tmp;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("quebra aqui\n");
            if (i != 1 && j != 1)
            {
                tmp.coluna = c.coluna - 1 + j;
                tmp.linha = c.linha - 1 + i;
                tmp.chave = (tmp.linha * tmp.coluna) % M;
                htInsert(tmp, casas);
            }
            printf("%d\n", tmp.chave);
        }
    }
}

void sondar(casa c, casa *casas)
{
    ht[c.chave].sondada = 1;

    printf("sondar %d %d\n", c.linha, c.coluna);
}

void dominar(casa *casa, int c)
{
    inserirCasas(casa[c], casa);
    printf("dominar %d %d\n", casa[c].linha, casa[c].coluna);
}

int main(void)
{
    casa *casasSondar, *casasDominar;
    casa tmp;
    N = 0;
    htInit(100003);
    int L, C, P, T, R, lt, ct, cs = 0, cd = 0, EDAzinhos = 0;
    char resposta[10];

    s = 0;

    scanf("%d %d %d %d", &L, &C, &P, &T);
    getchar();

    casasSondar = malloc(sizeof(casa) * T * 5);
    casasDominar = malloc(sizeof(casa) * T);

    tmp.coluna = C;
    tmp.linha = L;
    tmp.chave = (L * C) % M;
    tmp.pontuacao = P;
    tmp.sondada = 1;

    htInsert(tmp, casasSondar);

    inserirCasas(tmp, casasSondar);

    sondar(casasSondar[cs], casasSondar);

    scanf("%s %d %d %d", resposta, &lt, &ct, &R);
    getchar();

    if (R >= 0)
    {
        tmp.coluna = ct;
        tmp.linha = lt;
        tmp.pontuacao = R;
        tmp.sondada = 1;
        tmp.chave = (tmp.linha * tmp.coluna) % M;
        casasDominar[cd] = tmp;
    }

    printf("fimturno\n");
    fflush(stdout);

    for (int c = 1; c < T; c++)
    {
        if (casasDominar[cd].sondada != 0)
        {
            dominar(casasDominar, cd);
            EDAzinhos++;
            cd++;
        }
        for (int j = 0; j < EDAzinhos; j++)
        {
            sondar(casasSondar[cs], casasSondar);
            scanf("%s %d %d %d", resposta, &lt, &ct, &R);
            getchar();
            if (R >= 0)
            {
                tmp.coluna = ct;
                tmp.linha = lt;
                tmp.pontuacao = R;
                tmp.sondada = 1;
                tmp.chave = (tmp.linha * tmp.coluna) % M;
                casasDominar[cd] = tmp;
            }

            cs++;
        }
        printf("fimturno\n");
        fflush(stdout);
    }

    free(ht);
    free(casasSondar);
    free(casasDominar);

    return 0;
}