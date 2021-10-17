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

void buscaBinaria(int *vetor, int numero, int fim)
{
    int comeco = 0;

    while (comeco <= fim - 1)
    {

        int i = (comeco + fim - 1) / 2;

        if (vetor[i] == numero)
        {
            printf("sim\n");
            return;
        }

        if (vetor[i] < numero)
        {
            comeco = i + 1;
        }
        else
        {
            fim = i;
        }
    }

    printf("nao\n");
}

int main(void){
    int *vetor, N, valor;

    scanf("%d", &N);

    vetor = malloc(sizeof(int)*N);

    for(int c=0; c<N; c++){
        scanf("%d", &vetor[c]);
    }

    mergesort(vetor, 0, N-1);

    while(scanf("%d", &valor) != EOF){
        buscaBinaria(vetor, valor, N);
    }

    return 0;
}