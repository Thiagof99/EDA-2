#include <stdio.h>
#include <string.h>

int main()
{

    int linhas, linhaCursor, colunaCursor, i, j, scan = 1;
    char upDown, texto[1000][1001];

    scanf("%d", &linhas);

    for (i = 0; i < linhas; i++)
    {
        scanf(" %1001[^\n]", texto[i]);
    }

    scanf("%d %d", &linhaCursor, &colunaCursor);

    while (scan > 0)
    {
        scan = scanf(" %c", &upDown);

        if (scan > 0)
        {
            if (upDown == 'j')
            {
                if (linhaCursor < linhas)
                {
                    linhaCursor++;
                }
                if (strlen(texto[linhaCursor - 1]) >= colunaCursor)
                {
                    printf("%d %d %c\n", linhaCursor, colunaCursor, texto[linhaCursor - 1][colunaCursor - 1]);
                }
                else
                {
                    printf("%d %ld %c\n", linhaCursor, strlen(texto[linhaCursor - 1]), texto[linhaCursor - 1][strlen(texto[linhaCursor - 1]) - 1]);
                }
            }
            else
            {
                if (linhaCursor > 1)
                {
                    linhaCursor--;
                }
                if (strlen(texto[linhaCursor - 1]) >= colunaCursor)
                {
                    printf("%d %d %c\n", linhaCursor, colunaCursor, texto[linhaCursor - 1][colunaCursor - 1]);
                }
                else
                {
                    printf("%d %ld %c\n", linhaCursor, strlen(texto[linhaCursor - 1]), texto[linhaCursor - 1][strlen(texto[linhaCursor - 1]) - 1]);
                }
            }
        }
    }

    return 0;
}