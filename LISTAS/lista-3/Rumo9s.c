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

int somaSemRecursao(int n)
{
    int soma = 0;
    while(n > 0)
    {
        soma += n % 10;
        n = n / 10;
    }
    return soma;
}

int main(void)
{

    char entrada[1001];
    int tamanho;

    while (scanf("%s", entrada) && entrada[0] != '0')
    {       
        tamanho = strlen(entrada);
        int contador = 1;
        int recebo = multiplo(entrada, tamanho);

        if (recebo % 9 == 0)
        {
            while(recebo != 9)
            {
                recebo = somaSemRecursao(recebo);
                contador++;
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
}