#include <stdio.h>

void troca(char *x)
{
    if(x[0] == '\0')
    {
        return;
    }
    if(x[0] != 'x')
    {
        printf("%c", x[0]);
        troca(x+1);
    }
    if(x[0] == 'x')
    {
        printf("%c", 'y');
        troca(x+1);
    }
}

int main(void)
{
    char entrada[81];
    scanf("%s", entrada);
    troca(entrada);
    return 0;
}