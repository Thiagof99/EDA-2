#include <stdio.h>

void insertionSort(int *vetor, int l, int r)
{
    int i, tmp;

    for (i = r; i > l; i--)
    {
        if (vetor[i] < vetor[i - 1])
        {
            tmp = vetor[i - 1];
            vetor[i - 1] = vetor[i];
            vetor[i] = tmp;
        }
    }

    for (i = l + 2; i <= r; i++)
    {
        int j = i;
        tmp = vetor[j];
        while (tmp < vetor[j - 1])
        {
            vetor[j] = vetor[j - 1];
            j--;
        }
        vetor[j] = tmp;
    }
}

int main(void)
{

    int lista[50000], quantidade = 0;

    while (scanf("%d", &lista[quantidade]) != EOF)
    {
        quantidade++;
    }

    insertionSort(lista, 0, quantidade - 1);

    for (int c = 0; c < quantidade; c++)
    {
        printf("%d", lista[c]);
        if (c < quantidade - 1)
        {
            printf(" ");
        }
        else
        {
            printf("\n");
        }
    }

    return 0;
}