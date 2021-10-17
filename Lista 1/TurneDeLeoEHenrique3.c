#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no
{
    char cidade[27];
    struct no *proximo;
} No;

typedef struct lista
{
    int index;
    No *cabeca;

} Lista;

void inserir(Lista *lista, char cidade[27])
{
    No *no = (No *)malloc(sizeof(No));
    strcpy(no->cidade, cidade);
    no->proximo = lista->cabeca;
    lista->cabeca = no;
    lista->index++;
}
Lista *criarLista()
{
    Lista *lista = (Lista *)malloc(sizeof(Lista));
    lista->index = 0;
    lista->cabeca = NULL;
    return lista;
}

int main(void)
{
    Lista *lista = criarLista();

    return 0;
}