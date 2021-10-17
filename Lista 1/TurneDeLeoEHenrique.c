#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
typedef struct no
{
    char cidade[27];
    struct no *proximo;
} No;

void inserirNaFila(No **fila, char city[27])
{
    No *aux, *novo = malloc(sizeof(No));

    for (int c = 0; c < strlen(city); c++)
    {
        novo->cidade[c] = city[c];
    }
    novo->proximo = NULL;
    if (fila == NULL)
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
}*/

int main(void)
{
    int scan = 1, quantidade = 0, qRiscadas = 0, tam, c, tOrdem = 0;
    char **cidades, ***riscadas, ***ordem, cidade[27];

    cidades = malloc(sizeof(char));

    while (scan > 0)
    {
        scan = scanf("%s", cidade);
        getchar();
        if (scan > 0)
        {
            cidades = realloc(cidades, (quantidade + 1) * sizeof(char));
            tam = strlen(cidade);
            cidades[quantidade] = malloc(sizeof(char) * (tam + 1));
            strcpy(cidades[quantidade], cidade);
            quantidade++;
        }
    }
    riscadas = malloc(quantidade * sizeof(char));
    ordem = malloc((quantidade + 1) * sizeof(char));
    for (c = 0; c < quantidade; c++)
    {
        if (c == 0)
        {
            ordem[tOrdem] = &cidades[c];
            tOrdem++;
        }
        else
        {
            printf("%s\n", *ordem[tOrdem - 1]);
            printf("%c\n", cidades[c][0] + 32);
            printf("%s\n", strchr(*ordem[tOrdem - 1], cidades[c][0] + 32));
            if (strchr(*ordem[tOrdem - 1], cidades[c][0] + 32) == NULL || strlen(strchr(*ordem[tOrdem - 1], cidades[c][0] + 32)) != 1)
            {
                ordem[tOrdem] = &cidades[c];
                tOrdem++;
            }
            else
            {
                riscadas[qRiscadas] = &cidades[c];
                qRiscadas++;
            }
        }
    }
    for (c = 0; c < tOrdem; c++)
    {
        printf("%s\n", *ordem[c]);
    }
    for (c = 0; c < qRiscadas; c++)
    {
        printf("%s\n", *riscadas[c]);
    }

    free(cidades);
    free(riscadas);
    free(ordem);

    return 0;
}
