#include <stdio.h>
#include <string.h>

int contador(char numero[14]){
    int ocorrencias = 0, primeira;

    if(strchr(numero, '7') != NULL){
        ocorrencias++;
        ocorrencias = ocorrencias + contador(memmove(strchr(numero, '7'), strchr(numero, '7')+1, strlen(strchr(numero, '7'))));
    }
    return ocorrencias;
}

int main(){

    char numero[14];
    int ocorrencias;

    scanf("%s", numero);

    ocorrencias = contador(numero);

    printf("%d\n", ocorrencias);

    return 0;
}

