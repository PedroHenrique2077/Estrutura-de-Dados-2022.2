# include <stdio.h>
# include <string.h>

// char  inverter_string ( char vetor[]){
//     char vetor_invertido[ 1000 ], *p;
//     int x, tam = 0 ;

//     tam = strlen (vetor);
//     p = vetor + tam - 2 ;

//     for (x = 0 ; x < tam; x++){
//         vetor_invertido[x] = *p;
//         p--;
//     }

//     printf ("\n%s\n", vetor_invertido);

// }

#define TAMANHO 32

int main()
{
    char saida[1000];
    int c;
    int x = 0;

    printf("Digite os dígitos hexadecimais (l/c), 0 até o final: ");
    while(x < TAMANHO)
    {
        scanf("%2x",&c);
        if(c == 0){
            break;
        }
        saida[x] = (char)c;
        x++;
    }
    printf("%s\n", saida);

    return 0;
}