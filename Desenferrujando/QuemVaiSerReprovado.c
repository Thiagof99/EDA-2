#include <stdio.h>
#include <string.h>

typedef struct aluno
{
    char nome[21];
    int nota;
} aluno;

int main()
{

    int instancia = 1, participantes, scan = 1;
    aluno reprovado, participante;

    while (scan > 0)
    {
        scan = scanf("%d", &participantes);

        if (scan > 0)
        {
            scanf(" %s %d", reprovado.nome, &reprovado.nota);

            for (int c = 0; c < participantes - 1; c++)
            {
                scanf(" %s %d", participante.nome, &participante.nota);
                if (participante.nota < reprovado.nota)
                {
                    memmove(reprovado.nome, participante.nome, 21);
                    reprovado.nota = participante.nota;
                }
                else if (participante.nota == reprovado.nota)
                {
                    if (strcmp(participante.nome, reprovado.nome) > 0)
                    {
                        memmove(reprovado.nome, participante.nome, 21);
                        reprovado.nota = participante.nota;
                    }
                }
            }
            printf("Instancia %d\n%s\n", instancia, reprovado.nome);
            instancia++;
        }
    }

    return 0;
}