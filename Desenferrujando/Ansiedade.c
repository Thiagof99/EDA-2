#include <stdio.h>

int main()
{

    char resposta[3];

    int scan = 1, quantidade = 0, ficha = 0, triagem = 0;

    while (scan == 1)
    {

        scan = scanf("%s", resposta);

        if (resposta[0] == 's')
        {
            quantidade++;
        }

        ficha++;
        if (ficha == 10 || scan == 0)
        {
            ficha = 0;
            if (quantidade >= 2)
            {
                triagem++;
            }
            quantidade = 0;
        }
    }

    printf("%d\n", triagem);

    return 0;
}