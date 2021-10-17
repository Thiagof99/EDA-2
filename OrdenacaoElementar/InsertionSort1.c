#include <stdio.h>

void insertionSort(int *vetor, int l, int r)
{
    int tmp;
    for (int i = l + 1; i <= r; i++)
    {
        for (int j = i; j > l; j--)
        {
            if (vetor[j] < vetor[j - 1])
            {
                tmp = vetor[j - 1];
                vetor[j - 1] = vetor[j];
                vetor[j] = tmp;
            }
        }
    }
}

int main(void)
{

    int lista[1000], quantidade = 0;

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