#include <stdio.h>

int main(){

    int input, quantidade = 0, scan = 1;

    while(scan > 0){
        scan = scanf("%d", &input);
        if(scan > 0){
            quantidade++;
        }
    }

    printf("%d\n", quantidade);

    return 0;
}