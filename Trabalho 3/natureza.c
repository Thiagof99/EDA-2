#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int grafo[5002][5002];
int visitados[5002];
int qt, C, R;

char animais[5002][31];

int buscaBinaria(char *palavra, int l, int r)
{
    int meio, tmp;

    meio = (l + r) / 2;

    if (l > r)
    {
        return -1;
    }

    tmp = strcmp(palavra, animais[meio]);

    if (tmp == 0)
    {
        return meio;
    }
    else if (tmp < 0)
    {
        return buscaBinaria(palavra, l, meio - 1);
    }

    return buscaBinaria(palavra, meio + 1, r);
}

/*int buscaBinaria(char *vetor, int numero, int fim)
{
    int comeco = 0;

    while (comeco <= fim - 1)
    {

        int i = (comeco + fim - 1) / 2;

        if (vetor[i].valor == numero)
        {
            return vetor[i].posicao;
        }

        if (vetor[i].valor < numero)
        {
            comeco = i + 1;
        }
        else
        {
            fim = i;
        }
    }

    return -1;
}*/

void sort(int tamanho)
{
    int i, j;
    char aux[32];
    for (i = 1; i < tamanho; i++)
    {
        for (j = 1; j < tamanho; j++)
        {
            if (strcmp(animais[j - 1], animais[j]) > 0)
            {
                strcpy(aux, animais[j - 1]);
                strcpy(animais[j - 1], animais[j]);
                strcpy(animais[j], aux);
            }
        }
    }
}

void buscar(int v, int c)
{
    qt++;
    visitados[v] = 1;
    for (int i = 0; i < c; i++)
    {
        if (grafo[v][i] && !visitados[i])
        {
            buscar(i, c);
        }
    }
}

int main(void)
{
    int idxPresa, idxPredador;
    char presa[31], predador[31];
    int *ht;
    ht = malloc(sizeof(int) * 5002);
    //grafo = malloc(sizeof(int) * 5002 * 5002);
    //visitados = malloc(sizeof(int) * 5002);

    do
    {
        scanf("%d %d", &C, &R);
        if (C != 0 || R != 0)
        {
            memset(animais, 0, sizeof(animais));
            for (int i = 0; i < C; i++)
            {
                scanf(" %s", animais[i]);
            }
            sort(C);
            memset(grafo, 0, sizeof(grafo));

            for (int i = 0; i < R; i++)
            {
                scanf(" %s %s", presa, predador);
                idxPresa = buscaBinaria(presa, 0, C);
                idxPredador = buscaBinaria(predador, 0, C);
                grafo[idxPresa][idxPredador] = 1;
                grafo[idxPredador][idxPresa] = 1;
            }

            int qtMax = 0;
            memset(visitados, 0, sizeof(visitados));

            for (int i = 0; i < C; i++)
            {
                qt = 0;
                if (!visitados[i])
                {
                    buscar(i, C);
                    if (qt > qtMax)
                    {
                        qtMax = qt;
                    }
                }
            }
            printf("%d\n", qtMax);
        }
    } while (C != 0 || R != 0);

    free(ht);
    //free(grafo);
    //free(visitados);

    return 0;
}