#include <stdio.h>
#include <string.h>

int multiplo(char x[], int tam)
{
    if (tam <= 0)
    {
        return 0;
    }
    else
    {
        return ((int)x[tam - 1] - 48) + multiplo(x, tam - 1);
    }
}

int main()
{

    char entrada[1001];
    int tamanho;

    while (scanf("%s", entrada))
    {
        if(entrada[0] == '0')
        {
            return;
        }
        
        tamanho = strlen(entrada);
        int contador = 0;
        int recebo = multiplo(entrada, tamanho);

        if (recebo % 9 == 0)
        {
            while (recebo > 0)
            {
                contador++;
                recebo = recebo / 10;
            }
            printf("%s is a multiple of 9 and has 9-degree %d.\n", entrada, contador);
        }
        else
        {
            printf("%s is not a multiple of 9.\n", entrada);
        }

        entrada[1001];
        tamanho = 0;
        recebo = 0;
    }

    return 0;
}