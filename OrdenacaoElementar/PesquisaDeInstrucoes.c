#include <stdio.h>
#include <stdlib.h>

typedef struct comando
{
    int id;
    char nome[16];
} Comando;

void binarySearch(Comando *lista, int elemento, int maior)
{

    int inicio = 1, meio, fim = maior;

    while (inicio <= fim)
    {

        meio = (inicio + fim) / 2;

        if (lista[meio].id == elemento)
        {
            printf("%s\n", lista[meio].nome);
            return;
        }
        if (lista[meio].id < elemento)
            inicio = meio + 1;
        if (lista[meio].id > elemento)
            fim = meio - 1;
    }
    printf("undefined\n");
    return;
}

void insertionSort(Comando *vetor, int l, int r)
{
    Comando tmp;
    int i;

    for (i = r; i > l; i--)
    {
        if (vetor[i].id < vetor[i - 1].id)
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
        while (tmp.id < vetor[j - 1].id)
        {
            vetor[j] = vetor[j - 1];
            j--;
        }
        vetor[j] = tmp;
    }
}

int main(void)
{
    int quantidade, comando;

    scanf("%d", &quantidade);

    Comando *instrucoes = malloc(sizeof(Comando) * (quantidade + 1));

    for (int c = 0; c < quantidade; c++)
    {
        scanf("%d %s", &instrucoes[c].id, instrucoes[c].nome);
        getchar();
    }

    insertionSort(instrucoes, 0, quantidade);

    while(scanf("%d", &comando) != EOF){
        binarySearch(instrucoes, comando, quantidade);
    }
    free(instrucoes);

    return 0;
}