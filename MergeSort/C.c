#include <stdio.h>

int main(void)
{

    int numero;

    do
    {
        scanf("%d", &numero);
        if (numero != 42)
        {
            printf("%d\n", numero);
        }
    } while (numero != 42);

    return 0;
}