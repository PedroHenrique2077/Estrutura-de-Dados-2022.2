#include <stdio.h>

char inverte(char *x)
{
    if(x[0] == '\0')
    {
        return;
    }
    inverte(x+1);
    printf("%c", x[0]);
}


int main(void)
{
    char entrada[501];
    scanf("%s", entrada);
    inverte(entrada);
    return 0;
}