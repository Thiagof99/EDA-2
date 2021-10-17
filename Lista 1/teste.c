#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no
{
    char cidade[27];
    struct no *proximo;
} No;

void inserirNaFila(No **fila, char city[27])
{
    No *aux, *novo = malloc(sizeof(No));
    strcpy(novo->cidade, city);
    novo->proximo = NULL;
    if (!fila)
    {
        *fila = novo;
    }
    else
    {
        aux = *fila;
    }
    while (aux->proximo)
    {
        aux = aux->proximo;
    }
    aux->proximo = novo;
}
void ordenar(No *cidades, char cidade[27], int primeira)
{
    No *ordem = malloc(sizeof(No)), *riscadas = malloc(sizeof(No));
    cidades = cidades->proximo;
    if (!cidades->proximo)
    {
        printf("%s\n", cidades->cidade);
        return;
    }
    else
    {
        while (cidades)
        {
            if (primeira == 0)
            {
                inserirNaFila(&ordem, cidades->cidade);
                ordem = ordem->proximo;
                printf("%s\n", ordem->cidade);
                cidades = cidades->proximo;
                primeira++;
            }
            else
            {
                while (!ordem && cidades)
                {
                    if (cidades->cidade[0] + 32 == cidade[strlen(cidade) - 1])
                    {
                        inserirNaFila(&ordem, cidade);
                        ordem = ordem->proximo;
                        printf("%s\n", ordem->cidade);
                    }
                    else
                    {
                        inserirNaFila(&riscadas, cidades->cidade);
                    }
                    cidades = cidades->proximo;
                }
                if (cidades->cidade[0] + 32 != ordem->cidade[strlen(ordem->cidade) - 1])
                {
                    inserirNaFila(&ordem, cidades->cidade);
                    ordem = ordem->proximo;
                    printf("%s\n", ordem->cidade);
                }
                else
                {
                    inserirNaFila(&riscadas, cidades->cidade);
                }
                cidades = cidades->proximo;
            }
        }
        if (riscadas->proximo)
        {
            ordenar(riscadas, ordem->cidade, 1);
        }
        return;
    }
}
int main(void)
{
    No *cidades;
    int scan = 1;
    char cidade[27];

    while (scan > 0)
    {
        scan = scanf("%s", cidade);
        if (scan > 0)
        {
            getchar();
            inserirNaFila(&cidades, cidade);
        }
    }

    ordenar(cidades, cidade, 0);

    free(cidades);

    return 0;
}