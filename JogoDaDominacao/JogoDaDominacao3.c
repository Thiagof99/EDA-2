#include <stdio.h>
#include <stdlib.h>

typedef struct edazinho
{
    long linha;
    long coluna;
} edazinho;

typedef struct casa
{
    long linha;
    long coluna;
    long pontuacao;
    int dominada;
} casa;

edazinho *jogador;
casa *casas;
long *casasSondar;
long M;

long chave(long linha, long coluna)
{
    long chave;
    if (linha >= 0 && coluna >= 0)
    {
        chave = (linha * 239 + coluna * 233) % M;
    }
    if (linha >= 0 && coluna < 0)
    {
        chave = (linha * 4093 - coluna * 4091) % M;
    }
    if (linha < 0 && coluna >= 0)
    {
        chave = (linha * (-65099) + coluna * 65089) % M;
    }
    if (linha < 0 && coluna < 0)
    {
        chave = (linha * (-999983) - coluna * 999979) % M;
    }
    return chave;
}

int sondar(int EDAzinhos)
{
    int sondadas = 0, pos = EDAzinhos - 1, iteracoes = 0;

    if (casasSondar[chave(jogador[pos].linha, jogador[pos].coluna + 1)] != 1)
    {
        printf("sondar %ld %ld\n", jogador[pos].linha, jogador[pos].coluna + 1);
        casasSondar[chave(jogador[pos].linha, jogador[pos].coluna + 1)] = 1;
        sondadas++;
    }

    int i = 0;
    while (sondadas < EDAzinhos && i < 3)
    {

        for (int j = 0; j < 3; j++)
        {
            if (casasSondar[chave(jogador[pos].linha - 1 + i, jogador[pos].coluna - 1 + j)] != 1)
            {
                printf("sondar %ld %ld\n", jogador[pos].linha - 1 + i, jogador[pos].coluna - 1 + j);
                casasSondar[chave(jogador[pos].linha - 1 + i, jogador[pos].coluna - 1 + j)] = 1;
                sondadas++;
            }
            if (sondadas >= EDAzinhos)
            {
                break;
            }
        }
        i++;
    }
    return sondadas;
}

int main(void)
{
    int EDAzinhos = 0, qtsondados, casaAtual = 0, tmp, expande = 5, dominacao = 0, maior, limite;
    long L, C, P, T, linha, coluna, pontos, right, tmpL, tmpC, tmpP;
    char resposta[10];

    scanf("%ld %ld %ld %ld", &L, &C, &P, &T);

    M = T * 11;
    jogador = malloc(sizeof(edazinho) * T);
    casas = malloc(sizeof(casa) * 5 * T);
    casasSondar = malloc(sizeof(long) * M);

    jogador[EDAzinhos].linha = L;
    jogador[EDAzinhos].coluna = C;
    casasSondar[chave(L, C)] = 1;
    C = C + 1;
    right = C + 1;

    printf("sondar %ld %ld\n", L, C);
    casasSondar[chave(L, C)] = 1;

    printf("fimturno\n");
    fflush(stdout);

    scanf(" %s %ld %ld %ld", resposta, &linha, &coluna, &pontos);

    for (long i = 1; i < T; i++)
    {
        if (expande > 0)
        {
            expande--;
            printf("dominar %ld %ld\n", linha, coluna);
            dominacao = 1;
            if (coluna >= right && linha == L)
            {
                right = coluna + 1;
            }
        }
        else
        {
            if (casas[tmp].pontuacao > 0 && linha != 0)
            {
                printf("dominar %ld %ld\n", linha, coluna);
                dominacao = 1;

                if (coluna >= right && linha == L)
                {
                    right = coluna + 1;
                }
            }
            else if (casas[tmp].pontuacao <= 0 && casasSondar[chave(L, right)] == 1)
            {
                linha = L;
                coluna = right;
                right++;
                printf("dominar %ld %ld\n", linha, coluna);
                dominacao = 1;
            }
        }
        qtsondados = sondar(EDAzinhos + 1);

        printf("fimturno\n");
        fflush(stdout);

        if (dominacao == 1)
        {
            scanf(" %s %ld", resposta, &pontos);
            EDAzinhos++;
            jogador[EDAzinhos].linha = linha;
            jogador[EDAzinhos].coluna = coluna;
            dominacao = 0;
        }

        maior = -100;

        for (int j = 0; j < qtsondados; j++)
        {
            scanf(" %s %ld %ld %ld", resposta, &tmpL, &tmpC, &tmpP);
            if (tmpP >= limite || expande > 0)
            {
                casas[casaAtual].linha = tmpL;
                casas[casaAtual].coluna = tmpC;
                casas[casaAtual].pontuacao = tmpP;
                casaAtual++;
            }
        }

        limite = 0;

        if(linha == 0){
            limite = -10;
        }

        linha = 0;

        for (int j = 0; j < casaAtual; j++)
        {
            /*   if (j == 0)
            {
                maior = casas[j].pontuacao;
            }*/
            if (casas[j].pontuacao > maior && casas[j].dominada != 1)
            {
                tmp = j;
                maior = casas[j].pontuacao;
                linha = casas[j].linha;
                coluna = casas[j].coluna;
            }
        }

        casas[tmp].dominada = 1;
    }

    free(jogador);
    free(casas);
    free(casasSondar);

    return 0;
}