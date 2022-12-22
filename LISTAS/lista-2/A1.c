#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    int n, doutorando;
    int somador = 0;
    scanf("%d", &n);

    int pessoas[10];

    for(int i = 0; i < n; i++){
        scanf("%d", &pessoas[i]);
        somador += pessoas[i];
    }

    scanf("%d", &doutorando);

    if(somador == doutorando){
        printf("Acertou\n");
    } else {
        printf("Errou\n");
    }



    
    return 0;
}