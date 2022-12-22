#include <stdio.h>

int soma(char x[], int tam)
{
    if (tam <= 0)
    {
        return 0;
    }
    else
    {
        return ((int)x[tam - 1] - 48) + soma(x, tam - 1);
    }
}

int main()
{
    char entrada[15];
    int tamanho;
    scanf("%s", entrada);
    tamanho = strlen(entrada);
    printf("%d\n", soma(entrada, tamanho));

}