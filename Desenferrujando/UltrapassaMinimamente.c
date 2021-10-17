#include <stdio.h>
#include <stdlib.h>

int main()
{

    int *numeros, quantidade = 0, quantidadeU = 0, numero, soma = 0, limite, *ultrapassou, c;

    numeros = malloc(sizeof(int));
    ultrapassou = malloc(sizeof(int));
    do
    {
        scanf("%d", &numero);

        if (numero != 0)
        {
            quantidade++;
            numeros = realloc(numeros, quantidade * sizeof(int));
            numeros[quantidade - 1] = numero;
        }

    } while (numero != 0);

    scanf("%d", &limite);

    for (c = 0; c < quantidade; c++)
    {
        soma = soma + numeros[c];
        if (soma > limite)
        {
            quantidadeU++;
            ultrapassou = realloc(ultrapassou, quantidadeU * sizeof(int));
            ultrapassou[quantidadeU - 1] = numeros[c];
            soma = 0;
        }
    }

    for (c = quantidadeU - 1; c >= 0; c--)
    {
        printf("%d\n", ultrapassou[c]);
    }

    free(numeros);
    free(ultrapassou);
    return 0;
}