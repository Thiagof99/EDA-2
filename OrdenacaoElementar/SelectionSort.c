#include <stdio.h>

void selectionSort(int *vetor, int l, int r)
{
    int menor, tmp;
    for (int i = l; i < r; i++)
    {
        menor = i;
        for (int j = i + 1; j <= r; j++)
        {
            if (vetor[j] < vetor[menor])
            {
                menor = j;
            }
        }
        tmp = vetor[i];
        vetor[i] = vetor[menor];
        vetor[menor] = tmp;
    }
}

int main(void)
{

    int lista[1000], quantidade = 0;

    while (scanf("%d", &lista[quantidade]) != EOF)
    {
        quantidade++;
    }

    selectionSort(lista, 0, quantidade - 1);

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