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

int N, M;
casa *ht;
casa NULLItem = {0, 0, 0, 0, 0};

typedef struct no
{
    casa c;
    struct no *proximo;
} No;

void inserirNaFila(No **fila, casa c)
{
    No *aux, *novo = malloc(sizeof(No));
    novo->c = c;
    novo->proximo = NULL;
    if (!fila)
    {
        *fila = novo;
    }
    else
    {
        aux = *fila;
    }
    while (aux->proximo)
    {
        aux = aux->proximo;
    }
    aux->proximo = novo;
}

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

/*void expand()
{
    int i;
    casa *t = ht;
    M = (M * 2) + 1;
    ht = malloc(sizeof(casa) * M);

    for (i = 0; i < M / 2; i++)
    {
        htInsert(t[i]);
    }
    free(t);
}*/

void htInsert(casa c, No *no)
{
    int v = c.chave;
    int i = v % M;

    if (ht[i].chave == NULLItem.chave)
    {
        ht[i] = c;
        if (c.sondada == 0)
        {
            inserirNaFila(&no, c);
        }
        N++;
    }

    /*    if (N >= M)
    {
        expand();
    }*/
}

void inserirCasas(casa c, No *no)
{
    int i, j;
    casa tmp;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (i != 1 && j != 1)
            {
                tmp.coluna = c.coluna - 1 + j;
                tmp.linha = c.linha - 1 + i;
                tmp.chave = (tmp.linha * tmp.coluna) % M;
                htInsert(tmp, no);
            }
        }
    }
}

void dominar()
{
    printf("dominar L C");
}

void sondar(No *no)
{
    printf("quebra aqui\n");
    printf("%d\n", ht[no->c.chave].linha);
    ht[no->c.chave].sondada = 1;

    inserirCasas(no->c, no);
    printf("sondar %d %d\n", no->c.linha, no->c.coluna);
}

int main(void)
{
    No *casasSondar = (No *)malloc(sizeof(No));
    casa tmp;
    N = 0;
    htInit(100003);
    int L, C, P, T, R, lt, ct, EDAzinhos = 0;
    char resposta[10];

    scanf("%d %d %d %d", &L, &C, &P, &T);
    getchar();

    tmp.coluna = C;
    tmp.linha = L;
    tmp.chave = (L * C) % M;
    tmp.pontuacao = P;
    tmp.sondada = 1;

    htInsert(tmp, casasSondar);

    inserirCasas(tmp, casasSondar);

    sondar(casasSondar);

    scanf("%s %d %d %d", resposta, &lt, &ct, &R);
    getchar();

    casasSondar = casasSondar->proximo;

    printf("fimturno\n");
    fflush(stdout);

    for (int c = 1; c < T; c++)
    {
        dominar();
        EDAzinhos++;
        for (int j = 0; j < EDAzinhos; j++)
        {
            sondar(casasSondar);
            scanf("%s %d %d %d", resposta, &lt, &ct, &R);
            getchar();
            casasSondar = casasSondar->proximo;
        }
        printf("fimturno\n");
        fflush(stdout);
    }

    free(ht);
    return 0;
}