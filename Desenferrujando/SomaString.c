#include <stdio.h>

int contaAlgarismos(char palavra[101]){
    int soma = 0, c = 0;
    while(palavra[c] != '\0'){
        if((int)palavra[c]-48 < 10 && (int)palavra[c]-48 >= 0){
            soma = soma + ((int)palavra[c]-48);
        }
        c++;
    }
    return soma;
}
int main(){

    int quantidade;
    char palavra[101];
    
    scanf("%d", &quantidade);

    for(int c = 0; c<quantidade; c++){
        scanf(" %s", palavra);
        printf("%d\n", contaAlgarismos(palavra));
    }
    return 0;
}