#include <stdio.h>

int funcao(char *x)
{
    int contador = 1;
    if (x[0] == '\0')
    {
        return 0;
    }
    if (x[0] == x[0+2])
    {
         return contador + funcao(x+1);
    }
    else
    {
        funcao(x+1);
    }
}

int main(void)
{
    char entrada[201];
    scanf("%s", entrada);
    printf("%d\n", funcao(entrada));
}