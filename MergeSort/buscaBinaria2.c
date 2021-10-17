#include <stdio.h>
#include <stdlib.h>

typedef struct item
{
    int valor;
    int posicao;
}item;

void merge(item *vetor, int l, int m, int r)
{
    item *tmp = malloc(sizeof(item) * (r - l + 1));
    int i = l, j = m + 1, k = 0;

    while (i <= m && j <= r)
    {
        if (vetor[i].valor < vetor[j].valor)
        {
            tmp[k] = vetor[i];
            k++;
            i++;
        }
        else
        {
            tmp[k] = vetor[j];
            k++;
            j++;
        }
    }

    while (i <= m)
    {
        tmp[k] = vetor[i];
        k++;
        i++;
    }
    while (j <= r)
    {
        tmp[k] = vetor[j];
        k++;
        j++;
    }

    k = 0;
    for (i = l; i <= r; i++)
    {
        vetor[i] = tmp[k];
        k++;
    }
    free(tmp);
}

void mergesort(item *vetor, int l, int r)
{
    if (l >= r)
    {
        return;
    }
    int meio = (l + r) / 2;
    mergesort(vetor, l, meio);
    mergesort(vetor, meio + 1, r);
    merge(vetor, l, meio, r);
}

int buscaBinaria(item *vetor, int numero, int fim)
{
    int comeco = 0;

    while (comeco <= fim - 1)
    {

        int i = (comeco + fim - 1) / 2;

        if (vetor[i].valor == numero)
        {
            return vetor[i].posicao;
        }

        if (vetor[i].valor < numero)
        {
            comeco = i + 1;
        }
        else
        {
            fim = i;
        }
    }

    return -1;
}

int main(void)
{
    int tmpP = 0, tmpE, numero, N, M;
    item *vetor;

    scanf("%d %d", &N, &M);

    vetor = malloc(sizeof(item)*N);

    for(int c=0; c<N; c++){
        scanf("%d", &tmpE);
        vetor[c].valor = tmpE;
        vetor[c].posicao = tmpP;
        tmpP++;
    }

    mergesort(vetor, 0, N-1);

    for(int c=0; c<M; c++){
        scanf("%d", &numero);
        printf("%d\n", buscaBinaria(vetor, numero, N));
    }

    free(vetor);
    
    return 0;
}