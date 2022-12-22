#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    int p1, p2, p3, soma;

    scanf("%d %d %d", &p1, &p2, &p3);
    scanf("%d", &soma);

    if(soma == p1+p2+p3){
        printf("Acertou\n");
    } else{
        printf("Errou\n");
    }
    
    return 0;
}