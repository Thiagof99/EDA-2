#include <stdio.h>

void bubbleSort(int *vetor, int l, int r)
{
    int tmp;
    for (int i = l; i < r; i++)
    {
        for (int j = l + 1; j <= r; j++)
        {
            if(vetor[j] < vetor [j - 1]){
                tmp =  vetor[j - 1];
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

    bubbleSort(lista, 0, quantidade - 1);

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