#include <stdio.h>

int main(){

    int estrela, r, quariguazy = 0, m;

    scanf("%d", &m);

    for(r = 0; r < m; r++){
        scanf("%d", &estrela);
        quariguazy = quariguazy + estrela;
    }

    printf("%d\n", quariguazy);

    return 0;
}