#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *registros, alunos, presenca, presentes = 0, i;

    scanf("%d", &alunos);

    registros = calloc(1000001, sizeof(int));

    for (i = 0; i < alunos; i++)
    {
        scanf("%d", &presenca);

        if (registros[presenca] == 0)
        {
            presentes++;
        }

        registros[presenca] = 1;
    }

    printf("%d\n", presentes);

    free(registros);

    return 0;
}