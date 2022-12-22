#include <stdio.h>

int faz_conta_direito(int parcelas, char op){

    int armazena[1000];
    int soma = 0;

    for(int i=0; i<parcelas; i++){
        scanf("%d", &armazena[i]);
    }

    if(op =='+'){
        for(int j=0; j<parcelas; j++){
            soma += armazena[j];
        }
    }
    
    if(op =='-'){
        soma = armazena[0];
        for(int k=1; k<parcelas; k++){
            soma -= armazena[k];
        }
    }

    return(soma);
}