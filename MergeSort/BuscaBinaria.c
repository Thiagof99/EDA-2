#include <stdio.h>
#include <stdlib.h>

int buscaBinaria(int *vetor, int numero, int fim)
{
    int comeco = 0;

    while (comeco <= fim - 1)
    {

        int i = (comeco + fim - 1) / 2;

        if (vetor[i] == numero)
        {
            return i;
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

    return fim;
}
int main(void)
{
    int *vetor, numero, N, M;

    scanf("%d %d", &N, &M);

    vetor = malloc(sizeof(int)*N);

    for(int c=0; c<N; c++){
        scanf("%d", &vetor[c]);
    }

    for(int c=0; c<M; c++){
        scanf("%d", &numero);
        printf("%d\n", buscaBinaria(vetor, numero, N));
    }

    free(vetor);
    
    return 0;
}