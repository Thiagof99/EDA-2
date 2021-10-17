#include <stdio.h>
#include <stdlib.h>

void merge(int *V, int l, int m, int r)
{
    int *R = malloc(sizeof(int) * (r - l + 1));
    int i = l, j = m + 1, k = 0;

    while (i <= m && j <= r)
    {
        if (V[i] < V[j])
            R[k++] = V[i++];
        else
            R[k++] = V[j++];
    }

    while (i <= m)
        R[k++] = V[i++];
    while (j <= r)
        R[k++] = V[j++];

    k = 0;
    for (i = l; i <= r; i++)
        V[i] = R[k++];
    free(R);
}

int main(void)
{

    int *vetor, elementos = 0, novosElementos, elemento = 0, novoElemento;

    vetor = malloc(sizeof(int));

    for (int i = 0; i < 8; i++)
    {
        scanf("%d", &novosElementos);
        if (novosElementos != 0)
        {
            elementos = elementos + novosElementos;
            vetor = realloc(vetor, sizeof(int) * elementos);
            for (int j = 0; j < novosElementos; j++)
            {
                scanf("%d", &vetor[elemento]);
                elemento++;
            }
            merge(vetor, 0, (elementos - novosElementos) - 1, elementos - 1);
        }
    }

    for (int c = 0; c < elementos; c++)
    {
        printf("%d ", vetor[c]);
    }

    printf("\n");

    free(vetor);

    return 0;
}