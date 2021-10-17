#include <stdio.h>
#include <stdlib.h>

void merge(int *vetor, int l, int m, int r)
{
    int *tmp = malloc(sizeof(int) * (r - l + 1));
    int i = l, j = m + 1, k = 0;

    while (i <= m && j <= r)
    {
        if (vetor[i] < vetor[j])
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

void mergesort(int *vetor, int l, int r)
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

int main(void)
{
    int *vetor, quantidade;

    scanf("%d", &quantidade);

    vetor = malloc(sizeof(int) * quantidade);

    for (int c = 0; c < quantidade; c++)
    {
        scanf("%d", &vetor[c]);
    }

    mergesort(vetor, 0, quantidade - 1);

    for (int c = 0; c < quantidade; c++)
    {
        if (c == 0)
        {
            printf("%d", vetor[c]);
        }
        else
        {
            printf(" %d", vetor[c]);
        }
    }

    printf("\n");

    free(vetor);

    return 0;
}